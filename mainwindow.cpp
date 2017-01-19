 #include <QtGui>
 #include <QtDebug>
 #include <QRegExp>
 #include <QTextCodec>
 #include <QTime>
 #include <QString>
 #include <QTextCodec> 
 #include <QMessageBox>
 #include <qfiledialog.h>


 #include "mainwindow.h"
 #include <threadcomport.h>
 #include "ui_main_window_form.h"
 #include <md5.h>
/*
==============
<CONSTRUCTORS>
==============
*/
 MainWindow::MainWindow()
 {
	QString prefix = "";
#ifdef Q_WS_WIN 
    const QString portname = "COM";
	int minnum = 1;
	int maxnum = 20;
	prefix = "\\\\.\\";
#else
	const QString portname = "/dev/ttyS";
	int minnum = 0;
	int maxnum = 19;
#endif

	setupUi(this);
	port =  NULL;
	timerout = NULL;
    receiveTimer = NULL;
    sendTimer = NULL;
	timeoutTime = NULL;
	counter_in = 0;
	counter_out = 0;

    //QTextCodec *codec = QTextCodec::codecForLocale();
    //QTextCodec::setCodecForTr(codec);
    //QTextCodec::setCodecForCStrings(codec);
	createMainMenu();
	setWindowIcon(QIcon(":/images/plats.ico"));
	
	labelReceive = new QLabel("                  ");
	labelReceive->setIndent(10);
	labelTransmit = new QLabel("                  ");
	labelTransmit->setIndent(10);
    statusBar()->addWidget(labelReceive);
    statusBar()->addWidget(labelTransmit);

	for (minnum; minnum <= maxnum; minnum++)
    {
        if (minnum>=10)
            comboBox_port->addItem(prefix+portname+QString("%1").arg(minnum));//for windows xp and vista port prefix
        else
			comboBox_port->addItem(portname+QString("%1").arg(minnum));	
    }
	comboBox_baudrate->addItem("BAUD110",BAUD110);
	comboBox_baudrate->addItem("BAUD300",BAUD300);
	comboBox_baudrate->addItem("BAUD600",BAUD600);
	comboBox_baudrate->addItem("BAUD1200",BAUD1200);
	comboBox_baudrate->addItem("BAUD2400",BAUD2400);
	comboBox_baudrate->addItem("BAUD4800",BAUD4800);
	comboBox_baudrate->addItem("BAUD9600",BAUD9600);
	comboBox_baudrate->addItem("BAUD19200",BAUD19200);
	comboBox_baudrate->addItem("BAUD38400",BAUD38400);
	comboBox_baudrate->addItem("BAUD57600",BAUD57600);
	comboBox_baudrate->addItem("BAUD115200",BAUD115200);

	comboBox_parity->addItem("PAR_NONE",PAR_NONE);
	comboBox_parity->addItem("PAR_ODD",PAR_ODD);
	comboBox_parity->addItem("PAR_EVEN",PAR_EVEN);
	comboBox_parity->addItem("PAR_SPACE",PAR_SPACE);

	comboBox_flcntrl->addItem("FLOW_OFF",FLOW_OFF);
	comboBox_flcntrl->addItem("FLOW_HARDWARE",FLOW_HARDWARE);
	comboBox_flcntrl->addItem("FLOW_XONXOFF",FLOW_XONXOFF);

	PortSettings settings;
	readSettings(&settings);

	mainComThread = new QMainComThread(comboBox_port->currentText(),&settings);
	mainComThread->start();
	while (!port)
	{
		port = mainComThread->getPort();
		qApp->processEvents();
	}

	bt_stopsend->setEnabled(false);
	bt_closeport->setEnabled(false);
	progressBar->setValue(0);
	timerout = new QTimer(this);
    receiveTimer = new QTimer(this);
    sendTimer = new QTimer(this);
    update_init();






	SetCurComboBState();
		//connecting
	connect(bt_openport,SIGNAL(clicked()),this, SLOT(openPort()));
	connect(bt_closeport,SIGNAL(clicked()),this, SLOT(closePort()));
	connect(comboBox_baudrate,SIGNAL(currentIndexChanged(int)),this,SLOT(enabledPortBt()));
	connect(comboBox_parity,SIGNAL(currentIndexChanged(int)),this,SLOT(enabledPortBt()));
	connect(comboBox_flcntrl,SIGNAL(currentIndexChanged(int)),this,SLOT(enabledPortBt()));
	connect(bt_apply,SIGNAL(clicked(bool)),this,SLOT(applyPortOptions()));
	connect(bt_cancel,SIGNAL(clicked(bool)),this,SLOT(SetCurComboBState()));
	connect(bt_send,SIGNAL(clicked(bool)), this, SLOT(btsendClick()));
	connect(bt_stopsend,SIGNAL(clicked(bool)), this, SLOT(btstopsendClick()));
    connect(timerout, SIGNAL(timeout()), this, SLOT(transmitMsg()));
    connect(receiveTimer, SIGNAL(timeout()), this, SLOT(pressUartData()));
	connect(bt_clear, SIGNAL(clicked(bool)), textBr_inp, SLOT(clear()));
	connect(bt_clear, SIGNAL(clicked(bool)), textBr_mess, SLOT(clear()));
	connect(port,SIGNAL(newDataInPortSignal(QTime,const unsigned char *, const int)),this, SLOT(receiveMsg(QTime,const unsigned char *, const int)));
    connect(spinBox_Period, SIGNAL(valueChanged(int)), this, SLOT(intervalChange(int)));
}



 void MainWindow::update_init()
 {
     //add by lekee
     updateFileList->setEditable(true);
     readFileList->setEditable(true);
     frimwareVersion->setEditable(true);
     if(comboBox_updateWay->currentText() == "本地升级")
     {
        comboBox_updateMode->setDisabled(true);
     }

     shortAddr->addItem(tr("0x0000"));
     shortAddr->addItem(tr("0xFFFF"));

     usart.r_count = 0;
     usart.s_count = 0;


 }


/*
==============
<DESTRUCTORS>
==============
*/
MainWindow::~MainWindow()
{
	delete timerout;
	timerout = NULL;

	delete mainComThread;
	mainComThread = NULL;
}
/*
==============
<METHODS>
==============
*/
void MainWindow::closeEvent(QCloseEvent *event)
{
	writeSettings();
    event->accept();
}

void MainWindow::getdataout(QByteArray *data)
{
	data->clear();
    //QString str = (textEd_out->toPlainText()).toAscii();
    QString str = (textEd_out->toPlainText()).toLatin1();
	if (rbt_ASCIIout->isChecked())//ASCII
	{
		str = textEd_out->toPlainText();
        *data = str.toLatin1();
	}
	if (rbt_Decout->isChecked())//Dec
	{
		QRegExp rx("(\\d+)");
		int pos = 0;
		while ((pos = rx.indexIn(str, pos)) != -1)
		{
			data->append((rx.cap(1)).toInt());
			pos += rx.matchedLength();
		}
	}
	if (rbt_BINout->isChecked())//BIN
	{
		QRegExp rx("([01]+)");
		int pos = 0;
		while ((pos = rx.indexIn(str, pos)) != -1)
		{
			bool ok;
			data->append((rx.cap(1)).toInt(&ok, 2));
			pos += rx.matchedLength();
		}
	}
	if (rbt_HEXout->isChecked())//HEX
	{
		QRegExp rx("([0-9a-fA-F]+)");
		int pos = 0;
		while ((pos = rx.indexIn(str, pos)) != -1)
		{
			bool ok;
			data->append((rx.cap(1)).toInt(&ok, 16));
			pos += rx.matchedLength();
		}
	}
}

void MainWindow::readSettings(PortSettings *portsettings)
{
#ifdef Q_WS_WIN 
	QSettings settings("QT_comport.ini" ,QSettings::IniFormat);
#else
	QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Gorin", "QT_comport");
#endif
	settings.beginGroup("window");
    QPoint pos = settings.value("pos", QPoint(200, 200)).toPoint();
    QSize size = settings.value("size", QSize(700, 400)).toSize();
	settings.endGroup();

    resize(size);
    move(pos);

	settings.beginGroup("port");
	int portparam;
	portparam = comboBox_port->findText( (settings.value("name")).toString(),
		Qt::MatchExactly | Qt::MatchFixedString);
	if (-1 == portparam)
		portparam = 0;
	comboBox_port->setCurrentIndex(portparam);
	portsettings->BaudRate = (BaudRateType)settings.value("baudrate",BAUD9600).toInt();
	portsettings->Parity = (ParityType)settings.value("parity",PAR_NONE).toInt();
	portsettings->FlowControl = (FlowType)settings.value("flowcontrol",FLOW_OFF).toInt();
	portsettings->DataBits = (DataBitsType)settings.value("databits",DATA_8).toInt();
	portsettings->StopBits = (StopBitsType)settings.value("flowcontrol",STOP_1).toInt();
	bDTR = settings.value("DTR",false).toBool();
	bRTS = settings.value("RTS",false).toBool();
    portsettings->Timeout_Millisec = 500;
    portsettings->Timeout_Sec = 0;
	settings.endGroup();

	settings.beginGroup("parameters");
	spinBox_Period->setValue(settings.value("periodvalue",0).toInt());
	TypeDataInOut type = (TypeDataInOut)(settings.value("typedataout",0).toInt());
	switch (type)
	{
	case DEC_:
		rbt_Decout->setChecked(true);
		break;
	case ASCII_:
		rbt_ASCIIout->setChecked(true);
		break;
	case BIN_:
		rbt_BINout->setChecked(true);
		break;
	case HEX_:
		rbt_HEXout->setChecked(true);
		break;
	}
	type = (TypeDataInOut)(settings.value("typedatain",0).toInt());
	switch (type)
	{
	case DEC_:
		rbt_Decin->setChecked(true);
		break;
	case ASCII_:
		rbt_ASCIIin->setChecked(true);
		break;
	case BIN_:
		rbt_BINin->setChecked(true);
		break;
	case HEX_:
		rbt_HEXin->setChecked(true);
		break;
	}
	textEd_out->setPlainText(settings.value("dataout","").toString());
	calcTimeoutAct->setChecked(settings.value("calctimeout",false).toBool());
	settings.endGroup();
}

void MainWindow::writeSettings()
{
#ifdef Q_WS_WIN 
	QSettings settings("QT_comport.ini" ,QSettings::IniFormat);
#else
	QSettings settings(QSettings::IniFormat, QSettings::UserScope, "Gorin", "QT_comport");
#endif
	settings.beginGroup("window");
	settings.setValue("pos", pos());
    settings.setValue("size", size());
	settings.endGroup();

	settings.beginGroup("port");
	settings.setValue("name", port->portName());
	settings.setValue("baudrate", (int)port->baudRate());
	settings.setValue("parity", (int)port->parity());
	settings.setValue("flowcontrol", (int)port->flowControl());
	settings.setValue("databits", (int)port->dataBits());
	settings.setValue("stopbits", (int)port->stopBits());
	settings.setValue("DTR",bDTR);
	settings.setValue("RTS",bRTS);
	settings.endGroup();

	settings.beginGroup("parameters");
	settings.setValue("periodvalue",spinBox_Period->value());
	TypeDataInOut type;
	if (rbt_Decout->isChecked())
		type = DEC_;
	if (rbt_ASCIIout->isChecked())
		type = ASCII_;
	if (rbt_BINout->isChecked())
		type = BIN_;
	if (rbt_HEXout->isChecked())
		type = HEX_;
	settings.setValue("typedataout",type);
	if (rbt_Decin->isChecked())
		type = DEC_;
	if (rbt_ASCIIin->isChecked())
		type = ASCII_;
	if (rbt_BINin->isChecked())
		type = BIN_;
	if (rbt_HEXin->isChecked())
		type = HEX_;
	settings.setValue("typedatain",type);
	settings.setValue("dataout",textEd_out->toPlainText());
	settings.setValue("calctimeout", calcTimeoutAct->isChecked());
	settings.endGroup();
}
/*
==============
<SLOTS>
==============
*/
void MainWindow::about()
{
	QMessageBox::about(this, "About "+windowTitle(),
			"<B>"+windowTitle()+"</B><BR>"
			"author: Egor Golubkin (Gorin)<br>"
            "<a href='mailto:Gorin_mind@rambler.ru'>Gorin_mind@rambler.ru</a>"
			"<br><br>"
			"<small>based on qextserialport</small>");
}

void MainWindow::applyPortOptions()
{
	int portparam = (comboBox_baudrate->itemData(comboBox_baudrate->currentIndex())).toInt();
	port->setBaudRate((BaudRateType)portparam);
	portparam = (comboBox_flcntrl->itemData(comboBox_flcntrl->currentIndex())).toInt();
	port->setFlowControl((FlowType)portparam);
	portparam = (comboBox_parity->itemData(comboBox_parity->currentIndex())).toInt();
	port->setParity((ParityType)portparam);
	bt_apply->setEnabled(false);
	bt_cancel->setEnabled(false);
}

void MainWindow::btsendClick()
{

    transmitMsg();
}

void MainWindow::btstopsendClick()
{
	timerout->stop();
	bt_send->setEnabled(true);
	bt_stopsend->setEnabled(false);
}

void MainWindow::createMainMenu()
{
	//File actions
	exitAct = new QAction(tr("E&xit"), this);
	exitAct->setShortcut(tr("Alt+F4"));
	exitAct->setStatusTip(tr("Exit the application"));
	connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
	//Help actions
	aboutAct = new QAction(tr("&About"), this);
	aboutAct->setShortcut(tr("CTRL+A"));
	aboutAct->setStatusTip(tr("About application"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
	//calcTimeoutAct
	calcTimeoutAct = new QAction (tr("&Calc Timeout"), this);
	calcTimeoutAct->setCheckable(true);
//	connect(calcTimeoutAct, SIGNAL(toggled(bool)), this, SLOT(setTimeoutTimer(bool)));
	
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(exitAct);

	editMenu = menuBar()->addMenu(tr("&Edit"));
	editMenu->addAction(calcTimeoutAct);

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
}

void MainWindow::closePort()
{
	if (! port) return;
	port->close();
	textBr_mess->append("Port close");
	bt_closeport->setEnabled(false);
	bt_openport->setEnabled(true);
}

void MainWindow::enabledPortBt()
{
	bt_apply->setEnabled(true);
	bt_cancel->setEnabled(true);
}

void MainWindow::intervalChange(int value)
{
	timerout->setInterval(value);
}

void MainWindow::openPort()
{
	if (! port) return;
	if (port->isOpen())
		port->close();
	port->setPortName(comboBox_port->currentText());
//	setTimeoutTimer(false);
	port->open(QIODevice::ReadWrite);
	if (port->isOpen())
		textBr_mess->append("Port open");
	else
		textBr_mess->append("Port not open");
	port->setDtr(bDTR);
	port->setRts(bRTS);
	bt_closeport->setEnabled(true);
	bt_openport->setEnabled(false);
	counter_in = 0;
	counter_out = 0;
}

void MainWindow::receiveMsg(const QTime timesl, const unsigned char *data, const int size)
{
    int i;
//    textBr_mess->append(QString("read %1").arg(size));
//    QDateTime datTime = QDateTime::currentDateTime();//获取系统现在的时间
//    textBr_inp->append(datTime.toString("yyyy/MM/dd hh:mm:ss")+
//                       QString(" %1 mS").arg(timesl.msec())+
//                       QString("receive: %1 byte").arg(size)
//                       );
//    textBr_inp->append(transformInpData(data, size));
//    textBr_inp->insertPlainText(transformInpData(data, size));


    for(i = 0; i < size;i++)
    {
        usart.receive[usart.r_count] = data[i];
        usart.r_count++;
    }
    receiveTimer->start(50);
}



void MainWindow::pressUartData()
{
    uint8 *ptr;
    uint16 size;
    uint16 length;
    uint16 crc_calculate;

    ptr = usart.receive;
    size = usart.r_count;
    receiveTimer->stop();

    textBr_inp->insertPlainText(transformInpData(ptr , size));
    counter_in+=size;
    labelReceive->setText(QString("receive %1").arg(counter_in));


    //search head of the packet
    while(size)
    {
        if(ptr[0] == 0x5A || ptr[0] == 0x5F)
        {
            length = ptr[1]*256+ptr[2];
            if(length>(size-5))
            {
                ptr++;
                size--;
            }
            else
            {
                //计算CRC
                crc_calculate = Crc16Bit((const char *)ptr,length+3);
                if(crc_calculate == (ptr[length+3]*256+ptr[length+4]))
                {

                    //process
                    pressCmdData(ptr,length+5);
                    if(size<length+5)
                    {
                        size=0;
                        ptr = NULL;
                    }
                    else
                    {
                        size -= (length+5);
                        ptr += (length+5);
                    }
                }
                else
                {
                    ptr++;
                    size--;
                }
            }
        }
        else
        {
            ptr++;
            size--;
        }
    }
    usart.r_count = 0;
}

void MainWindow::pressCmdData(uint8 *data , uint16 size)
{
    QByteArray buff;
    QByteArray ptr;
    QString str;
    UC_PAR uc_par;
    //UR_PAR ur_par;

    buff.clear();
    for(int i = 0; i < size;i++)
    {
        buff.append(data[i]);
    }
    str = buff.toHex();
    for(int i =0; i*3<str.length();i++)
    {
        str.insert(i*3+2, " ");
    }

    DisplayWithTime(QString("uart receive %1 byte").arg(buff.length()));
    textBr_mess->append(str.toUpper());


    if(data[0] == 0x5A)
    {
        uc_par.head = data[0];
        uc_par.len = data[1]*256+data[2];
        uc_par.cmd = data[3];
        uc_par.data = &data[4];
        uc_par.crc = data[size-2]*256+data[size-1];

        switch(uc_par.cmd)
        {

            case u_getDevNetInf:  //查询/设置网络参数
                textBr_mess->append("查询网络参数:");
            break;
            case u_getDevInf:            //请求设备详细信息
                textBr_mess->append("请求设备详细信息:");
            break;
            case u_senFirInf:            //发送固件信息包
                textBr_mess->append("发送固件信息包:");
            break;
            case u_senPacket:            //发送固件数据包
                textBr_mess->append("发送固件数据包:");
            break;
            case u_getBootloader:        //请求回传bootloader
                textBr_mess->append("请求回传bootloader:");
            break;
            case u_getFirmware:          //请求回传firmware
                textBr_mess->append("请求回传firmware:");
            break;
            case u_recDevNetInf:    //返回网络参数
                textBr_mess->append("返回网络参数:");
                textBr_mess->append("panID: "+uint16ToHex(uc_par.data[0]*256+uc_par.data[1]));
                textBr_mess->append("shorID: "+uint16ToHex(uc_par.data[2]*256+uc_par.data[3]));
                textBr_mess->append("power: "+uint8ToHex(uc_par.data[4]));
                textBr_mess->append("channel: "+uint8ToHex(uc_par.data[5]));
                textBr_mess->append("MAC: "+strToHex(&uc_par.data[6],8));
            break;
            case u_recDevInf:            //返回设备详细信息
                textBr_mess->append("返回设备详细信息:");
                textBr_mess->append("deviceType: "+uint8ToHex(uc_par.data[0]));
                textBr_mess->append("MAC: "+strToHex(&uc_par.data[1],8));
                textBr_mess->append("panID: "+uint16ToHex(uc_par.data[9]*256+uc_par.data[10]));
                textBr_mess->append("nodeType: "+uint8ToHex(uc_par.data[11]));
                textBr_mess->append("shorID: "+uint16ToHex(uc_par.data[12]*256+uc_par.data[13]));
                textBr_mess->append("Firmware version: "+uint8ToHex(uc_par.data[14]));
                textBr_mess->append("MD5: "+strToHex(&uc_par.data[15],16));

            break;
            case u_recUpdSta:            //返回固件升级状态
                textBr_mess->append("返回固件升级状态:");
                switch(uc_par.data[0])
                {
                    case 0:
                        textBr_mess->append("返回固件升级状态0：进入固件升级状态");
                    break;
                    case 1:
                        textBr_mess->append("返回固件升级状态1：MD5固件校验出错，重新请求升级");
                    break;
                    case 2:
                        textBr_mess->append("返回固件升级状态2：升级成功");
                    break;
                    case 3:
                        textBr_mess->append("返回固件升级状态3：升级超时");
                    break;
                    case 4:
                        textBr_mess->append("返回固件升级状态4：flash写失败");
                    break;
                    default:break;

                }
            break;
            case u_recPacSta:             //返回固件数据包接收状态
                if(uc_par.data[0] == 0)
                {
                    textBr_mess->append(QString("返回固件数据包接收状态：数据包1%接收成功").arg(uc_par.data[1]*256+uc_par.data[2]));
                }
                else
                {
                    textBr_mess->append(QString("返回固件数据包接收状态：请求重新发送数据包1%").arg(uc_par.data[1]*256+uc_par.data[2]));
                }
            break;
            default:
                textBr_mess->append("数据分析错误");
            break;

        }
    }
    else if(data[0] == 0x5F)
    {


    }

}
QString MainWindow::uint8ToHex(uint8 data)
{
    QByteArray buff;
    buff[0] = data;
    return buff.toHex();
}

QString MainWindow::uint16ToHex(uint16 data)
{
    QByteArray buff;
    buff[0] = (data>>8)&0xFF;
    buff[1] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MainWindow::uint32ToHex(uint32 data)
{
    QByteArray buff;
    buff[0] = (data>>24)&0xFF;
    buff[1] = (data>>16)&0xFF;
    buff[2] = (data>>8)&0xFF;
    buff[3] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MainWindow::strToHex(uint8 *data , uint16 len)
{
    QByteArray buff;
    for(int i = 0 ; i<len;i++)
    {
        buff[i] = data[i];
    }
    return buff.toHex();
}


void MainWindow::DisplayWithTime(const QString &text)
{
    QDateTime datTime = QDateTime::currentDateTime();
    QTime qTime = QTime::currentTime();
    textBr_mess->append(datTime.toString("yyyy/MM/dd hh:mm:ss")+
                        QString(" %1 mS       ").arg(qTime.msec())+
                        text
                        );
}

void MainWindow::DisplayWithNoTime(const QString &text)
{
    textBr_mess->append( text);
}


void MainWindow::SetCurComboBState()
{
	if (!port) return;
	comboBox_port->setCurrentIndex(comboBox_port->findText(port->portName()));
	int portparam = comboBox_baudrate->findData( port->baudRate());
	comboBox_baudrate->setCurrentIndex(portparam);
	portparam = comboBox_parity->findData( port->parity());
	comboBox_parity->setCurrentIndex(portparam);
	portparam = comboBox_flcntrl->findData(port->flowControl());
	comboBox_flcntrl->setCurrentIndex(portparam);
		
	bt_apply->setEnabled(false);
	bt_cancel->setEnabled(false);
}


QString MainWindow::transformInpData(const unsigned char *data, const int size)
{
	const QString tab = "  ";
	QString res;
	if (rbt_Decin->isChecked())
	{
        for (int i = 0;i < size;i++)
            res = res+QString("%1").arg((int)data[i])+tab;

	}
	if (rbt_ASCIIin->isChecked())
	{
		static char datatr[4*4096];
		int j = 0;
		int i = 0;
        for (;i < size;i++)
            if (data[i] != 0)
                datatr[i+j] = data[i];
			else
			{
				datatr[i+0] = '\"';
				datatr[i+1] = '\\';
				datatr[i+2] = '0';
				datatr[i+3] = '\"';
				j+=4;
			}
		datatr[i+j] = '\0';
		res=QMainWindow::tr(datatr);
	}
	if (rbt_BINin->isChecked())
	{
        for (int i = 0;i < size;i++)
            res = res+QString("%1").arg((int)data[i],0,2)+tab;
	}
	if (rbt_HEXin->isChecked())
	{
        for (int i = 0;i < size;i++)
            res = res+QString("%1").arg((int)data[i],0,16)+tab;
	}
	return res;
}

unsigned short int MainWindow::Crc16Bit(const char *ptr, unsigned short int len)
{
    unsigned short int i,j;
    const char *src = ptr;
    unsigned short int CRC16 = 0xFFFF;

    for (j = len; j != 0; j--)
    {
        CRC16 =CRC16 ^ (0x00ff&(*src++));
        for (i = 8; i != 0; i--)
        {
            if ((CRC16 & 0x0001) != 0)
            {
                CRC16 >>= 1;
                CRC16 ^= 0xA001;
            }
            else
            {
                CRC16 >>= 1;
            }
        }
    }

    return (CRC16);
}

void MainWindow::transmitMsg()
{
    int count;
    QByteArray data;
    //unsigned short int crc_calculate;
    //int percent = 0;

    if(true)
    {
        getdataout(&data);
        count = port->write(data, data.length());
        textBr_mess->append(QString("uart transmited %1").arg(count));

    }
    else
    {
//        if(file_send_count < file_send.length())
//        {
//            data = file_send.mid(file_send_count , 1000);
//            file_send_count+=1000;
//            send_frames_count = file_send_count/1000;

//            data.insert(0,"A5LLSSMM");
//            data.insert(data.length(),"CC");
//            //frames head
//            data[0] = 0xAA;
//            data[1] = 0x55;
//            //lenght
//            data[2] = (data.length()-4)/256;
//            data[3] = (data.length()-4)%256;
//            //frames count
//            data[4] = send_frames_count/256;
//            data[5] = send_frames_count%256;
//            //frames max
//            data[6] = send_frames_max/256;
//            data[7] = send_frames_max%256;

//            crc_calculate = Crc16Bit(data , data.length()-2);
//            data[data.length()-2] = (crc_calculate>>8)&0xff;
//            data[data.length()-1] = crc_calculate&0xff;


//            count = port->write(data, data.length());
//            percent = send_frames_count*100/send_frames_max;
//            textBr_mess->append(QString("transmit %1 ").arg(data.length()));
//            textBr_mess->append(QString("frames max: %1").arg(send_frames_max));
//            textBr_mess->append(QString("frames count: %1").arg(send_frames_count));
//            progressBar->setValue(percent);
//            timerout->start(100);
//        }
//        else
//        {
//            data = md5_Array;
//            send_frames_count = send_frames_max;

//            data.insert(0,"A5LLSSMM");
//            data.insert(data.length(),"CC");
//            //frames head
//            data[0] = 0xAA;
//            data[1] = 0x55;
//            //lenght
//            data[2] = (data.length()-4)/256;
//            data[3] = (data.length()-4)%256;
//            //frames count
//            data[4] = send_frames_count/256;
//            data[5] = send_frames_count%256;
//            //frames max
//            data[6] = send_frames_max/256;
//            data[7] = send_frames_max%256;

//            crc_calculate = Crc16Bit(data , data.length()-2);
//            data[data.length()-2] = (crc_calculate>>8)&0xff;
//            data[data.length()-1] = crc_calculate&0xff;


//            count = port->write(data, data.length());
//            percent = send_frames_count*100/send_frames_max;
//            textBr_mess->append(QString("transmit %1 ").arg(data.length()));
//            textBr_mess->append(QString("frames max: %1").arg(send_frames_max));
//            textBr_mess->append(QString("frames count: %1").arg(send_frames_count));
//            progressBar->setValue(percent);
//            timerout->stop();
//            file_send_count = 0;
//        }
    }

    if (count == -1) count = 0;
    counter_out += count;
    labelTransmit->setText(QString("transmit %1").arg(counter_out));
}
 
char MainWindow::u_sendMessage(unsigned char cmd,QByteArray *data)
{
    unsigned short crc_calculate;
    char status;
    QByteArray send_buff;
    send_buff.clear();
    send_buff = *data;
    send_buff.insert(0,0x5A);
    send_buff.insert(1,(data->length()+1)/256);
    send_buff.insert(2,(data->length()+1)%256);
    send_buff.insert(3,cmd);
    crc_calculate = Crc16Bit(send_buff,send_buff.length());
    send_buff[send_buff.length()] = crc_calculate/256;
    send_buff[send_buff.length()] = crc_calculate%256;
    status = port->write(send_buff, send_buff.length());
    return status;
}


char MainWindow::r_sendMessage(unsigned short dest_addr,
                               unsigned char sequence,
                               unsigned char device_type,
                               unsigned char cmd,
                               QByteArray *data)
{
    unsigned short crc_calculate;
    char status;
    QByteArray send_buff;
    send_buff.clear();
    send_buff = *data;
    send_buff.insert(0,0x5F);
    send_buff.insert(1,(data->length()+8)/256);
    send_buff.insert(2,(data->length()+8)%256);
    send_buff.insert(3,dest_addr/256);
    send_buff.insert(4,dest_addr%256);
    send_buff.insert(5,"");
    send_buff.insert(6,"");
    send_buff.insert(7,"");
    send_buff.insert(8,sequence);
    send_buff.insert(9,device_type);
    send_buff.insert(10,cmd);
    crc_calculate = Crc16Bit(send_buff,send_buff.length());
    send_buff[send_buff.length()] = crc_calculate/256;
    send_buff[send_buff.length()] = crc_calculate%256;
    status = port->write(send_buff, send_buff.length());
    return status;
}



void MainWindow::on_bt_openFile_clicked()
{
    QStringList fileNameList;
    QString fileName0;
    QString str;

    //creat a dialog
    QFileDialog* fd = new QFileDialog(this);
    fd->resize(240,320);
    fd->setNameFilter("Allfile(*.*);;hexfile(*.hex);;binfile(*.bin)");
    fd->setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs);
    fd->setViewMode(QFileDialog::Detail);
    if ( fd->exec() == QDialog::Accepted )
    {
        //creat a file and wirte the firmware
//        QFile fd_creat("readfile.bin");
//        fd_creat.open(QIODevice::WriteOnly);
//        fd_creat.write(file_send);
//        fd_creat.close();

        fileNameList = fd->selectedFiles();
        //read the file name
        fileName0 = fileNameList[0];
        //close the dialog
        fd->close();
        QFile file(fileName0);
        if(!file.open(QIODevice::ReadOnly))
        {
           textBr_mess->append("file opne error");
        }
        else
        {

            fir.local_w.buff.clear();
            fir.local_w.buff = file.readAll();
            file.close();

            fir.local_w.send_cout = 0;
            fir.local_w.total_packet = fir.local_w.buff.length()/1000;
            if(fir.local_w.buff.length()%1000)
            {
                fir.local_w.total_packet++;
            }
            fir.local_w.send_max = fir.local_w.total_packet;


            MD5 md5;
            md5.update(fir.local_w.buff,fir.local_w.buff.length());
            str = QString::fromStdString(md5.toString());
            fir.local_w.md5.clear();
            fir.local_w.md5.append(str);


            updateFileList->insertItem(0,fileName0);
            updateFileList->setCurrentText(fileName0);
            textBr_mess->append(fileName0);
            textBr_mess->append(QString("file size: %1").arg(fir.local_w.buff.length()));
            textBr_mess->append(QString("packet max: %1").arg(fir.local_w.send_max));
            textBr_mess->append(QString("packet count: %1").arg(fir.local_w.send_cout));
            textBr_mess->append("MD5:"+str);
        }
    }
    else
    {
        fd->close();
    }
}

void MainWindow::on_comboBox_updateWay_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "本地升级")
    {
        textBr_mess->append("升级方式："+arg1);
        comboBox_updateMode->setDisabled(true);
    }
    else if(arg1 == "OTA升级")
    {
        textBr_mess->append("升级方式："+arg1);
        comboBox_updateMode->setDisabled(false);
    }
    else
    {
        textBr_mess->append("升级方式： ERROR");
        comboBox_updateMode->setDisabled(true);
    }
}

void MainWindow::usartAck()
{
    unsigned short crc_calculate;
    QByteArray send_buff;
    send_buff.clear();
    send_buff[0] = 0x5A;
    send_buff[1] = 0;
    send_buff[2] = 0;
    crc_calculate = Crc16Bit(send_buff,send_buff.length());
    send_buff[send_buff.length()] = crc_calculate/256;
    send_buff[send_buff.length()] = crc_calculate%256;
    port->write(send_buff, send_buff.length());
}

void MainWindow::on_File_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_bt_getDeviceInf_clicked()
{
    QByteArray buff;
    buff.clear();
    u_sendMessage(u_getDevNetInf,&buff);
}

void MainWindow::on_bt_sendFirInf_clicked()
{
    QByteArray buff;
    buff.clear();
    u_sendMessage(u_senFirInf,&buff);
}

void MainWindow::on_bt_sendPacket_clicked()
{

}

void MainWindow::on_bt_autoUpdate_clicked()
{

}

void MainWindow::on_bt_stopAutoUpdate_clicked()
{

}

void MainWindow::on_bt_readBoot_clicked()
{

}

void MainWindow::on_bt_readFirmware_clicked()
{

}

void MainWindow::on_bt_stopRead_clicked()
{

}

void MainWindow::on_bt_storeFile_clicked()
{

}
