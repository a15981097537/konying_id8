 #include <QtGui>
 #include <QtDebug>
 #include <QRegExp>
 #include <QTextCodec>
 #include <QTime>
 #include <QTimer>
 #include <QString>
 #include <QTextCodec> 
 #include <QMessageBox>
 #include <qfiledialog.h>


 #include "mainwindow.h"
 #include <threadcomport.h>
 #include "ui_main_window_form.h"
 #include "mangeid.h"


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

    for (minnum = 0; minnum <= maxnum; minnum++)
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
    user_init();
    NET_Init();



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
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(ucmdAutoUpdate()));
    connect(port,SIGNAL(newDataInPortSignal(QTime,const unsigned char *, const int)),this, SLOT(receiveMsg(QTime,const unsigned char *, const int)));
    connect(spinBox_Period, SIGNAL(valueChanged(int)), this, SLOT(intervalChange(int)));
}



 void MainWindow::user_init()
 {
     //add by lekee
     updateFileList->setEditable(true);
     readFileList->setEditable(true);
     frimwareVersion->setEditable(true);
     packetbyte->setEditable(true);


     comboBox_updateMode->setCurrentText("OTA手动升级") ;
     bt_getDeviceInf->setDisabled(false);
     bt_sendFirInf->setDisabled(false);
     bt_sendPacket->setDisabled(false);
     bt_autoUpdate->setDisabled(true);
     bt_stopAutoUpdate->setDisabled(true);
     bt_readBoot->setDisabled(true);
     bt_readFirmware->setDisabled(true);
     bt_stopRead->setDisabled(true);
     pushButton_nc0->setDisabled(true);
     packetbyte->setCurrentText("88");



     fir.auto_step = update_step_finish;

     shortAddr->addItem(tr("0x0000"));
     shortAddr->addItem(tr("0xFFFF"));
//     shortAddr->addItem(tr("+++addr+++"));
     //DisplayWithTime(QString("%1").arg(shortAddr->currentRow()));
     shortAddr->setCurrentRow(0);


     transport.r_count = 0;
     transport.s_count = 0;


     rf_send.sequence = 0;
     rf_send.rssi = 0xFF;
     rf_send.device = dev_gatway;


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

    if(comunication_protocal->currentText() == "uart")
    {
        for(i = 0; i < size;i++)
        {
            transport.receive[transport.r_count] = data[i];
            transport.r_count++;
        }
        receiveTimer->start(20);
        textBr_inp->insertPlainText(transformInpData(data , size));
    }
}



void MainWindow::pressUartData()
{
    uchar *ptr;
    ushort size;
    ushort length;
    uchar check_sum;





    ptr = transport.receive;
    size = transport.r_count;
    receiveTimer->stop();


    counter_in+=size;
    labelReceive->setText(QString("receive %1").arg(counter_in));


    //search head of the packet
    while(size)
    {
        if((ptr[0] == 0x98) && (ptr[1] == 0x89))
        {
            length = ptr[7]+9;

            if(length>size)
            {
                ptr++;
                size--;
            }
            else
            {
                check_sum=checkSum((char *)ptr,length-1);
                if(ptr[length-1]==check_sum)
                {
                    pressCmdData(ptr,length);
                    size -= length;
                    ptr += length;
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
    transport.r_count = 0;
}


void MainWindow::pressCmdData(uchar *data , ushort size)
{
    QByteArray buff;
    IOT_FRAME iot_frame;
    APP_FRAME app_frame;
    QString str,str0;
    ushort packet_num;
    ushort packet_length;
    ID_SEND send;
    int i;



    buff.clear();
    for(i = 0; i < size;i++)
    {
        buff.append(data[i]);
    }

    if(rb_displayRawHex->isChecked()==true)
    {
        QString str = buff.toHex();
        for(i =0; i*3<str.length();i++)
        {
            str.insert(i*3+2, " ");
        }
        if(comunication_protocal->currentText() == "Network")
        {
            DisplayWithTime(QString("tcp/ip receive %1 byte").arg(buff.length()));
        }
        else
        {
            DisplayWithTime(QString("uart receive %1 byte").arg(buff.length()));
        }


        textBr_mess->append(str.toUpper());
    }

    iot_frame.head = data[0]*256+data[1];
    iot_frame.gateway_id = data[2]*256+data[3];
    iot_frame.device_id = data[4]*256+data[5];
    iot_frame.cmd = data[6];
    iot_frame.length = data[7];
    iot_frame.data = &data[8];
    iot_frame.checkSum = data[9];


    str = "message from node";
    str0 = "0x" + uint16ToHex(iot_frame.device_id).toUpper();
    str += str0;


    if(shortAddr->findItems(str0 , Qt::MatchExactly).isEmpty())
    {
        shortAddr->insertItem(0,tr(""));
        shortAddr->item(0)->setText(str0);
    }

    NET_setBindSocket(iot_frame.gateway_id);
    NET_setBindSocket(iot_frame.device_id);

    if(iot_frame.cmd == cmd_idRequest)
    {
         send = id_access.accessId(iot_frame.data);
         str0 = "0x" + uint16ToHex(send.device_id).toUpper();
         if(shortAddr->findItems(str0 , Qt::MatchExactly).isEmpty())
         {
             shortAddr->insertItem(0,tr(""));
             shortAddr->item(0)->setText(str0);
         }

         NET_setBindSocket(send.device_id);
         IOT_cmdAsscessId(iot_frame.gateway_id,iot_frame.device_id,&send);
         id_access.getIdInf(send.device_id);
         NET_DisplayWithTime(id_access.getIdInf(send.device_id));
    }
    else if(iot_frame.cmd == cmd_network)
    {
        app_frame.rf.sequence = iot_frame.data[0];
        app_frame.rf.deviceType = iot_frame.data[1];
        app_frame.rf.cmd = iot_frame.data[2];
        app_frame.rf.data = &iot_frame.data[3];
        app_frame.rssi = data[size-2];

        str += QString("/ rssi:%1dBm").arg(app_frame.rssi);
        str += QString("/ sequence:%1").arg(app_frame.rf.sequence);
        str += "/ device type:";
        switch(app_frame.rf.deviceType)
        {
        case dev_gatway:
            str += "gatway";
            break;
        case dev_adultSpireLamella:
            str += "adultSpireLamella";
            break;
        case dev_childSpireLamella:
            str += "childSpireLamella";
            break;
        case dev_patientSpireLamella:
            str += "gatway";
            break;
        case dev_sosPanic:
            str += "tempreture";
            break;
        case dev_plug:
            str += "tempreture";
            break;
        case dev_tempreture:
            str += "tempreture";
            break;
        case dev_humidity:
            str += "humidity";
            break;
        case dev_multileSensor:
            str += "multileSensor";
            break;
        default:
            str += "unkown device";
            break;

        }

        switch(app_frame.rf.cmd)
        {

            case r_getDevNetInf:  //查询/设置网络参数
                DisplayWithTime(str+"/ 查询网络参数:");
            break;
            case r_getDevInf:            //请求设备详细信息
                DisplayWithTime(str+"/ 请求设备详细信息:");
            break;
            case r_senFirInf:            //发送固件信息包
                DisplayWithTime(str+"/ 接收固件信息包:");
                if(comboBox_updateMode->currentText() == "OTA固件读取")
                {
                    fir.ota_r.mode = app_frame.rf.data[0];
                    fir.ota_r.device_type = app_frame.rf.data[1];
                    fir.ota_r.total_packet = (app_frame.rf.data[2]<<8)+app_frame.rf.data[3];
                    fir.ota_r.packet_byte = app_frame.rf.data[4];
                    fir.ota_r.total_byte  = app_frame.rf.data[5]<<24;
                    fir.ota_r.total_byte += app_frame.rf.data[6]<<16;
                    fir.ota_r.total_byte += app_frame.rf.data[7]<<8;
                    fir.ota_r.total_byte += app_frame.rf.data[8];
                    fir.ota_r.version = app_frame.rf.data[9];
                    for(i=0;i<16;i++)
                    {
                        fir.ota_r.md5[i] = app_frame.rf.data[10+i];
                    }
                    fir.ota_r.buff.clear();
                    DisplayWithNoTime(QString("file size: %1").arg(fir.ota_r.total_byte));
                    DisplayWithNoTime(QString("packet byte: %1").arg(fir.ota_r.packet_byte));
                    DisplayWithNoTime(QString("packet total: %1").arg(fir.ota_r.total_packet));
                    DisplayWithNoTime(QString("packet count: %1").arg(fir.ota_r.send_cout));
                    DisplayWithNoTime("MD5:"+fir.ota_r.md5.toHex().toUpper());
                }
            break;
            case r_senPacket:            //发送固件数据包
                str +="/ 接收固件数据包:";
                if(comboBox_updateMode->currentText() == "OTA固件读取")
                {
                    fir.ota_r.send_cout = (app_frame.rf.data[0]<<8)+app_frame.rf.data[1];
                    packet_length = (app_frame.rf.data[2]<<8)+app_frame.rf.data[3];
                    for(i=0;i<packet_length;i++)
                    {
                        fir.ota_r.buff.append(app_frame.rf.data[4+i]);
                    }
                    str += QString("count:%1  length:%2").arg(fir.ota_r.send_cout).arg(packet_length);
                }
                DisplayWithTime(str);
            break;
            case r_getDevCap:            //查询设备所具备的功能
                DisplayWithTime(str+"/ 查询设备所具备的功能:");
            break;
            case r_getDevCapDat:         //查询设备功能数据
                DisplayWithTime(str+"/ 查询设备功能数据:");
            break;
            case r_setDevCapDat:         //设置设备功能
                DisplayWithTime(str+"/ 设置设备功能:");
            break;
            case r_setGetRepDat:         //查询/设置设备自动回传功能数据参数
                DisplayWithTime(str+"/ 查询/设置设备自动回传功能数据参数:");
            break;
            case r_getBootloader:        //请求回传bootloader
                DisplayWithTime(str+"/ 请求回传bootloader:");
            break;
            case r_getFirmware:          //请求回传firmware
                DisplayWithTime(str+"/ 请求回传firmware:");
            break;
            case r_recDevNetInf:    //返回网络参数
                DisplayWithTime(str+"/ 返回网络参数:");
                textBr_mess->append("panID:    "+uint16ToHex(app_frame.rf.data[0]*256+app_frame.rf.data[1]).toUpper());
                textBr_mess->append("shorID:   "+uint16ToHex(app_frame.rf.data[2]*256+app_frame.rf.data[3]).toUpper());
                textBr_mess->append("power:    "+uint8ToHex(app_frame.rf.data[4]).toUpper());
                textBr_mess->append("channel:  "+uint8ToHex(app_frame.rf.data[5]).toUpper());
                textBr_mess->append("MAC:      "+strToHex(&app_frame.rf.data[6],8).toUpper());
            break;
            case r_recDevInf:            //返回设备详细信息
                DisplayWithTime(str+"/ 返回设备详细信息:");
                textBr_mess->append("MAC:         "+strToHex(&app_frame.rf.data[0],8).toUpper());
                textBr_mess->append("panID:       "+uint16ToHex(app_frame.rf.data[8]*256+app_frame.rf.data[9]).toUpper());
                textBr_mess->append("nodeType:    "+uint8ToHex(app_frame.rf.data[10]).toUpper());
                textBr_mess->append("Fir version: "+uint8ToHex(app_frame.rf.data[11]).toUpper());
                textBr_mess->append("MD5:         "+strToHex(&app_frame.rf.data[12],16).toUpper());
                if((comboBox_updateMode->currentText() == "OTA单独升级")||
                   (comboBox_updateMode->currentText() == "OTA批量升级"))
                {
                    rcmdSendFirInf();
                }
            break;
            case r_recUpdSta:            //返回固件升级状态
                str+= "/ 返回固件升级状态";
                switch(app_frame.rf.data[0])
                {
                    case 0:
                        str+="0：进入固件升级状态";
                        DisplayWithTime(str);
                        if(comboBox_updateMode->currentText() == "OTA单独升级")
                        {
                            rcmdSendsendPacket(fir.ota_w.send_cout);
                        }
                    break;
                    case 1:
                        str+="1：MD5固件校验出错，重新请求升级";
                        DisplayWithTime(str);
                    break;
                    case 2:
                        str+="2：升级成功";
                        DisplayWithTime(str);
                    break;
                    case 3:
                        str+="3：升级超时";
                        DisplayWithTime(str);
                    break;
                    case 4:
                        str+="4：flash写失败";
                        DisplayWithTime(str);
                    break;
                    case 5:
                        str+="5：flash擦除失败";
                        DisplayWithTime(str);
                    break;
                    default:break;
                }

            break;
            case r_recPacSta:             //返回固件数据包接收状态

                str+="/ 返回固件数据包接收状态:";
                packet_num = app_frame.rf.data[1]*256+app_frame.rf.data[2];
                if(app_frame.rf.data[0] == 0)
                {

                    str+=QString("数据包%1接收成功").arg(packet_num);
                    DisplayWithTime(str);
                    if((comboBox_updateMode->currentText() == "OTA单独升级")||
                       (comboBox_updateMode->currentText() == "OTA批量升级"))
                    {
                        fir.ota_w.send_cout = packet_num+1;
                        rcmdSendsendPacket(fir.ota_w.send_cout);
                    }
                }
                else
                {
                    str+=QString("请求重新发送数据包%1").arg(packet_num);
                    DisplayWithTime(str);
                    if((comboBox_updateMode->currentText() == "OTA单独升级")||
                       (comboBox_updateMode->currentText() == "OTA批量升级"))
                    {
                        fir.ota_w.send_cout = packet_num;
                        rcmdSendsendPacket(fir.ota_w.send_cout);
                    }
                }

            break;
            default:
                DisplayWithTime(str+"/ 数据分析错误");
            break;

        }


    }



}
QString MainWindow::uint8ToHex(uchar data)
{
    QByteArray buff;
    buff[0] = data;
    return buff.toHex();
}

QString MainWindow::uint16ToHex(ushort data)
{
    QByteArray buff;
    buff[0] = (data>>8)&0xFF;
    buff[1] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MainWindow::uint32ToHex(uint data)
{
    QByteArray buff;
    buff[0] = (data>>24)&0xFF;
    buff[1] = (data>>16)&0xFF;
    buff[2] = (data>>8)&0xFF;
    buff[3] = (data>>0)&0xFF;
    return buff.toHex();
}

QString MainWindow::strToHex(uchar *data , ushort len)
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
    if(false)
    {
        textBr_mess->append(datTime.toString("yyyy/MM/dd hh:mm:ss")+
                            QString(" %1 mS     ").arg(qTime.msec())+
                            text
                            );
    }
    else
    {
        textBr_mess->append(datTime.toString("yyyy/MM/dd hh:mm:ss    ")+text);
    }


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
            //res = res+QString("%1").arg((int)data[i],0,16)+tab;
            res = res+uint8ToHex(data[i])+" ";
            res = res.toUpper();
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
//---------------------------------------------------------------------------

//和校验
uchar MainWindow::checkSum(const char* puchData, ushort len)
{
    uchar crc8 = 0;
    while (len--)
    {
        crc8 = crc8 + (*puchData++);
    }
    return crc8;
}

//---------------------------------------------------------------------------


//*****************************************
//usart transimit layer
//*****************************************
void MainWindow::transmitMsg()
{
    int count;
    QByteArray data;
    //unsigned short int crc_calculate;
    //int percent = 0;

    getdataout(&data);
    count = port->write(data, data.length());
    //textBr_mess->append(QString("uart transmited %1").arg(count));

    if (count == -1) count = 0;
    counter_out += count;
    labelTransmit->setText(QString("transmit %1").arg(counter_out));
}

void MainWindow::UART_send(QByteArray src)
{

    port->write(src, src.length());

    QString str;
    str = src.toHex();
    for(ushort i =0; i*3<str.length();i++)
    {
        str.insert(i*3+2, " ");
    }
    textEd_out->append(str.toUpper());


    if(rb_displayRawHex->isChecked()==true)
    {
        DisplayWithTime(QString("usart send %1 byte").arg(src.length()));
        textBr_mess->append(str.toUpper());
    }
}

char MainWindow::r_sendMessage(unsigned char cmd,QByteArray *data)
{

    QByteArray send_buff;

    if(rf_send.sequence==255)rf_send.sequence=0;
    else rf_send.sequence++;


    send_buff.clear();
    send_buff = *data;
    send_buff.insert(0,rf_send.sequence);
    send_buff.insert(1,rf_send.device);
    send_buff.insert(2,cmd);
    send_buff.append(rf_send.rssi);

    return IOT_sendMessage(cmd_network,&send_buff);
}




//*****************************************
//usart transimit layer end
//*****************************************



//*****************************************
//IOT start
//*****************************************



void  MainWindow::IOT_cmdAsscessId(ushort gateway_id,ushort device_id,ID_SEND *id)
{
    ushort i;
    QByteArray buff;
    buff.clear();
    buff[0]=0x98;
    buff[1]=0x89;
    buff[2]=(gateway_id>>8)&0xFF;
    buff[3]=gateway_id&0xFF;
    buff[4]=(device_id>>8)&0xFF;
    buff[5]=device_id&0xFF;
    buff[6]=cmd_idRequest;
    buff[7]=0;//length
    for(i=0;i<8;i++)
    {
        buff[8+i]=id->mac[i];
    }
    buff[16]=(id->gateway_id>>8)&0xFF;
    buff[17]=id->gateway_id&0xFF;
    buff[18]=(id->panid>>8)&0xFF;
    buff[19]=id->panid&0xFF;
    buff[20]=(id->device_id>>8)&0xFF;
    buff[21]=id->device_id&0xFF;
    buff[22]=id->un[0];
    buff[23]=id->un[1];
    buff[24]=id->un[2];
    buff[25]=id->un[3];
    buff[26]=rf_send.rssi;//rssi
    buff[27] = checkSum(buff,buff.length());
    buff[7]=buff.length()-9;

    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(buff);
    }
    else if(comunication_protocal->currentText() == "Network")
    {
        NET_getBindSocket(id->device_id);
        NET_send(buff);
    }
}



void  MainWindow::IOT_cmdHeartBeat(ushort gateway_id,ushort device_id,ushort time)
{
    QByteArray buff;
    buff.clear();
    buff[0]=0x98;
    buff[1]=0x89;
    buff[2]=(gateway_id>>8)&0xFF;
    buff[3]=gateway_id&0xFF;
    buff[4]=(device_id>>8)&0xFF;
    buff[5]=device_id&0xFF;
    buff[6]=cmd_heartBeat;
    buff[7]=0;//length
    buff[8]=(time>>8)&0xFF;
    buff[9]=time&0xFF;
    buff[10]=(gateway_id>>8)&0xFF;
    buff[11]=gateway_id&0xFF;
    buff[12]=0;
    buff[13]=0;
    buff[14]=rf_send.rssi;//rssi
    buff[15] = checkSum(buff,buff.length());
    buff[7]=buff.length()-9;

    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(buff);
    }
    else if(comunication_protocal->currentText() == "Network")
    {
        NET_getBindSocket(device_id);
        NET_send(buff);
    }
}




char MainWindow::IOT_sendMessage(uchar cmd,QByteArray *data)
{
    ID_SEND send;
    char status = 0;
    QByteArray send_buff;

    if(rf_send.sequence==255)rf_send.sequence=0;
    else rf_send.sequence++;


    if(shortAddr->currentRow()<0)
    {
        DisplayWithTime("please select addr ");
        return 0;
    }


    send = id_access.getIdSendInf(rf_send.device_id);

    send_buff.clear();
    send_buff = *data;
    send_buff.insert(0,0x98);
    send_buff.insert(1,0x89);
    send_buff.insert(2,send.gateway_id/256);
    send_buff.insert(3,send.gateway_id%256);
    send_buff.insert(4,send.device_id/256);
    send_buff.insert(5,send.device_id%256);
    send_buff.insert(6,cmd);
    send_buff.append(checkSum(send_buff,send_buff.length()));
    send_buff.insert(7,send_buff.length()-8);



    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(send_buff);
    }
    else if(comunication_protocal->currentText() == "Network")
    {
        NET_getBindSocket(send.device_id);
        NET_send(send_buff);
    }

    return status;
}
//*****************************************
//IOT end
//*****************************************





//*****************************************
//rcmd start
//*****************************************




void MainWindow::rcmdGetDeviceInf()
{
    QByteArray buff;
    buff.clear();
    r_sendMessage(r_getDevInf,&buff);
    DisplayWithTime("get device information");
}

void MainWindow::rcmdSendFirInf()
{
    QByteArray buff;
    unsigned short i = 0;
    if(fir.ota_w.buff.isEmpty() == true)
    {
        DisplayWithTime("please open the file xxx.bin");
        return;
    }
    buff.clear();
    buff[i++] = fir.ota_w.mode;
    buff[i++] = fir.ota_w.device_type;
    buff[i++] = (fir.ota_w.total_packet>>8)&0xFF;
    buff[i++] = (fir.ota_w.total_packet>>0)&0xFF;
    buff[i++] = fir.ota_w.packet_byte;
    buff[i++] = (fir.ota_w.total_byte>>24)&0xFF;
    buff[i++] = (fir.ota_w.total_byte>>16)&0xFF;
    buff[i++] = (fir.ota_w.total_byte>>8)&0xFF;
    buff[i++] = (fir.ota_w.total_byte>>0)&0xFF;
    buff[i++] = fir.ota_w.version;
    for(int j = 0;j<16 ; j++)
    {
        buff[i++] = fir.ota_w.md5[j];
    }
    r_sendMessage(r_senFirInf,&buff);
    DisplayWithTime("send firmware information");
}

void MainWindow::rcmdSendsendPacket(ushort packet)
{
    QByteArray buff;
    ushort i = 0;
    uint ptr;
    uchar  byte_count;

    if(fir.ota_w.buff.isEmpty() == true)
    {
        DisplayWithTime("please open the file xxx.bin");
        return;
    }
    else if(packet>=fir.ota_w.total_packet)
    {
        DisplayWithTime("固件发送完成");
        progressBar->setValue(100);
        return;
    }



    buff.clear();
    buff[i++] = (packet>>8)&0xFF;
    buff[i++] = (packet>>0)&0xFF;
    buff[i++] = fir.ota_w.mode;
    ptr = packet*fir.ota_w.packet_byte;
    if(packet<(fir.ota_w.total_packet-1))
    {
        byte_count = fir.ota_w.packet_byte;
    }
    else
    {
        byte_count = fir.ota_w.total_byte%fir.ota_w.packet_byte;
        if(byte_count == 0)byte_count = fir.ota_w.packet_byte;
    }

    buff[i++] = byte_count;


    for(uint j = 0;j<byte_count ; j++)
    {
        buff[i++] = fir.ota_w.buff[ptr+j];
    }
    r_sendMessage(r_senPacket,&buff);

    DisplayWithTime(QString("send_packet:%1  packet byte:%2").arg(packet).arg(byte_count));
    progressBar->setValue(packet*100/fir.ota_w.total_packet);
}


//*****************************************
//rcmd end
//*****************************************




//*****************************************
//控件事件
//*****************************************


void MainWindow::on_File_clicked()
{

}

void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::on_bt_getDeviceInf_clicked()
{

    if(comboBox_updateMode->currentText() == "OTA手动升级")
    {
        rcmdGetDeviceInf();
    }
    else
    {
        DisplayWithTime("error:the update mode is " + comboBox_updateMode->currentText());
    }

}

void MainWindow::on_bt_sendFirInf_clicked()
{

    if(comboBox_updateMode->currentText() == "OTA手动升级")
    {
        rcmdSendFirInf();
    }
    else
    {
        DisplayWithTime("error:the update mode is " + comboBox_updateMode->currentText());
    }

}

void MainWindow::on_bt_sendPacket_clicked()
{
    if(comboBox_updateMode->currentText() == "OTA手动升级")
    {
        rcmdSendsendPacket(fir.ota_w.send_cout);
        fir.ota_w.send_cout++;
    }
    else
    {
        DisplayWithTime("error:the update mode is " + comboBox_updateMode->currentText());
    }

}

void MainWindow::on_bt_autoUpdate_clicked()
{

    if(comboBox_updateMode->currentText() == "OTA单独升级")
    {
        fir.ota_w.send_cout=0;
        rcmdGetDeviceInf();
    }
    else
    {
        DisplayWithTime("error:the update mode is " + comboBox_updateMode->currentText());
    }
}

void MainWindow::on_bt_stopAutoUpdate_clicked()
{

    fir.auto_step = update_step_finish;
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
    user_MD5 md5;
    QString str = "update mode error";
    if(comboBox_updateMode->currentText() == "OTA固件读取")
    {
        md5.CalcFileMD5(fir.ota_w.buff, fir.ota_w.buff.length());
        if(memcmp(fir.ota_w.md5 , md5.buffer,16) == 0)
        {
            QFile fd_creat(readFileList->currentText());
            fd_creat.open(QIODevice::WriteOnly);
            fd_creat.write(fir.ota_r.buff);
            fd_creat.close();
            str = "固件保存到："+readFileList->currentText();
        }
        else
        {
            str = "md5 error";
        }
    }
    DisplayWithTime(str);

}

void MainWindow::on_comboBox_updateMode_currentTextChanged(const QString &arg1)
{
    if(arg1 == "OTA手动升级")
    {
        packetbyte->setCurrentText("88");
        bt_getDeviceInf->setDisabled(false);
        bt_sendFirInf->setDisabled(false);
        bt_sendPacket->setDisabled(false);
        bt_autoUpdate->setDisabled(true);
        bt_stopAutoUpdate->setDisabled(true);
        bt_readBoot->setDisabled(true);
        bt_readFirmware->setDisabled(true);
        bt_stopRead->setDisabled(true);
    }
    else if(arg1 == "OTA单独升级")
    {
        packetbyte->setCurrentText("88");
        bt_getDeviceInf->setDisabled(true);
        bt_sendFirInf->setDisabled(true);
        bt_sendPacket->setDisabled(true);
        bt_autoUpdate->setDisabled(false);
        bt_stopAutoUpdate->setDisabled(false);
        bt_readBoot->setDisabled(true);
        bt_readFirmware->setDisabled(true);
        bt_stopRead->setDisabled(true);
    }
    else if(arg1 == "OTA批量升级")
    {
        packetbyte->setCurrentText("88");
        bt_getDeviceInf->setDisabled(true);
        bt_sendFirInf->setDisabled(true);
        bt_sendPacket->setDisabled(true);
        bt_autoUpdate->setDisabled(false);
        bt_stopAutoUpdate->setDisabled(false);
        bt_readBoot->setDisabled(true);
        bt_readFirmware->setDisabled(true);
        bt_stopRead->setDisabled(true);
    }
    else if(arg1 == "OTA固件读取")
    {
        packetbyte->setCurrentText("88");
        bt_getDeviceInf->setDisabled(true);
        bt_sendFirInf->setDisabled(true);
        bt_sendPacket->setDisabled(true);
        bt_autoUpdate->setDisabled(true);
        bt_stopAutoUpdate->setDisabled(true);
        bt_readBoot->setDisabled(false);
        bt_readFirmware->setDisabled(false);
        bt_stopRead->setDisabled(false);
    }
    else
    {

        bt_getDeviceInf->setDisabled(true);
        bt_sendFirInf->setDisabled(true);
        bt_sendPacket->setDisabled(true);
        bt_autoUpdate->setDisabled(true);
        bt_stopAutoUpdate->setDisabled(true);
        bt_readBoot->setDisabled(true);
        bt_readFirmware->setDisabled(true);
        bt_stopRead->setDisabled(true);
    }
    DisplayWithTime(comboBox_updateMode->currentText());
}



void MainWindow::on_bt_openFile_clicked()
{
    QStringList fileNameList;
    QString fileName0;
    QString str;
    user_MD5 md5;


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
            if((comboBox_updateMode->currentText() == "OTA手动升级")||
               (comboBox_updateMode->currentText() == "OTA单独升级")||
               (comboBox_updateMode->currentText() == "OTA批量升级"))
            {

                fir.ota_w.buff.clear();
                fir.ota_w.buff = file.readAll();
                file.close();

                str = packetbyte->currentText();
                if(str.toUShort(0,10)>91)fir.ota_w.packet_byte = 91;
                else fir.ota_w.packet_byte = str.toUShort(0,10);

                fir.ota_w.version = frimwareVersion->currentText().toUShort(0,10);


                fir.ota_w.device_type = cb_deviceType->currentIndex();

                if(comboBox_updateMode->currentText() == "OTA批量升级")
                {
                    shortAddr->setCurrentRow(1);
                    fir.ota_w.mode = 0x01;
                }
                else
                {
                    fir.ota_w.mode = 0x00;
                }


                fir.ota_w.send_cout = 0;
                fir.ota_w.total_byte = fir.ota_w.buff.length();
                fir.ota_w.total_packet = fir.ota_w.total_byte/fir.ota_w.packet_byte;
                if(fir.ota_w.total_byte%fir.ota_w.packet_byte != 0)
                {
                    fir.ota_w.total_packet++;
                }




                md5.CalcFileMD5(fir.ota_w.buff, fir.ota_w.buff.length());
                fir.ota_w.md5.clear();
                const byte* ptr = md5.buffer;
                for(uchar i=0;i<16;i++)
                {
                    fir.ota_w.md5[i] = ptr[i];
                }



                updateFileList->insertItem(0,fileName0);
                updateFileList->setCurrentText(fileName0);
                textBr_mess->append(fileName0);
                textBr_mess->append(QString("file size: %1").arg(fir.ota_w.buff.length()));
                textBr_mess->append(QString("packet byte: %1").arg(fir.ota_w.packet_byte));
                textBr_mess->append(QString("packet total: %1").arg(fir.ota_w.total_packet));
                textBr_mess->append(QString("packet count: %1").arg(fir.ota_w.send_cout));
                textBr_mess->append(QString("firmware version: %1").arg(fir.ota_w.version));
                textBr_mess->append("MD5:"+fir.ota_w.md5.toHex().toUpper());
            }
        }
    }
    else
    {
        fd->close();
    }
}
void MainWindow::on_comboBox_updateWay_currentIndexChanged(const QString &arg1)
{
    DisplayWithTime(arg1);
}

void MainWindow::on_shortAddr_itemSelectionChanged()
{
    QString str = shortAddr->currentItem()->text();
    rf_send.device_id = str.toUShort(0,16);
    if(comunication_protocal->currentText() == "Network")
    {
        if(net_par.bind_socket[rf_send.device_id]!=NULL)
        {
            str+=" / bind IP" + net_par.bind_socket[rf_send.device_id]->peerAddress().toString();
            str+=" / bind port"+QString("%1").arg(net_par.bind_socket[rf_send.device_id]->peerPort());
        }
        else
        {
            if(rf_send.device_id == 0xFFFF)str+=" / brocast message to all gateway and all node";
            else str+=" / no gateway bind";
        }
    }

    DisplayWithTime(QString("Dest addr:")+str);
}

void MainWindow::on_frimwareVersion_3_currentTextChanged(const QString &arg1)
{
    DisplayWithTime(arg1);
}

void MainWindow::on_cb_deviceType_currentTextChanged(const QString &arg1)
{
    DisplayWithTime(arg1);
}

void MainWindow::on_cb_deviceType_currentIndexChanged(int index)
{
    //rf_send.device = index;
    fir.ota_w.device_type = index;
}

void MainWindow::on_shortAddr_doubleClicked(const QModelIndex &index)
{
    ushort i = index.row();
    te_addrEdit->setText(shortAddr->item(i)->text());
}

void MainWindow::on_pb_addAddr_clicked()
{
    //ushort i = shortAddr->currentRow();
    QString str = te_addrEdit->toPlainText();

    if(shortAddr->findItems(str , Qt::MatchExactly).isEmpty())
    {
        shortAddr->insertItem(0,tr(""));
        shortAddr->item(0)->setText(str);
        DisplayWithTime("add addr:" + str);
    }
    else
    {
        DisplayWithTime("error：已经存在" + str);
    }

}

void MainWindow::on_pb_deleteAddr_clicked()
{
    ushort i = shortAddr->currentRow();
    QString str = te_addrEdit->toPlainText();
    DisplayWithTime("change addr:" +shortAddr->item(i)->text()+" to "+str);
    shortAddr->item(i)->setText(str);
}





/**********************network start*****************************************/
/**********************network start*****************************************/

void MainWindow::NET_Init()

{
    ulong i;
    QString str = get_localmachine_ip();
    textEdit_IP->setPlainText(str);
    textEdit_Port->setPlainText("7777");
    textEdit_ID->setPlainText("0");
    textEdit_ID2->setPlainText("0");
    bt_stopListen->setDisabled(true);

    for(i=0;i<SOCKET_MAX;i++)
    {
        net_par.Socket[i]=NULL;
    }
    net_par.Server=NULL;

    for(i=0;i<65536;i++)
    {
        net_par.bind_socket[i] = NULL;
    }
}



QString MainWindow::get_localmachine_ip()
{
    QString ipAddress;
    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    // use the first non-localhost IPv4 address
    for (int i = 0; i < ipAddressesList.size(); ++i) {
        if (ipAddressesList.at(i) != QHostAddress::LocalHost &&
            ipAddressesList.at(i).toIPv4Address()) {
            ipAddress = ipAddressesList.at(i).toString();
            break;
        }
    }
    // if we did not find one, use IPv4 localhost
    if (ipAddress.isEmpty())
        ipAddress = QHostAddress(QHostAddress::LocalHost).toString();
    return ipAddress;
}

void MainWindow::revData()

{

   ushort i,j;
   QByteArray display;
   QByteArray datas;

   for(j = 0 ; j < SOCKET_MAX ; j ++)
   {

       if(net_par.Socket[j] == NULL)continue;
       datas.clear();
       datas = net_par.Socket[j]->readAll();
       if(datas.length() == 0)continue;

       net_par.currentSocket = net_par.Socket[j];
       //接收字符串数据。
       display = datas.toHex().toUpper();
       for(i=0;i<display.length();i+=3)
       {
            display.insert( i+2, " ");
       }
       infReceive->setPlainText(display);



       if(comunication_protocal->currentText() == "Network")
       {
           for(i = 0; i < datas.length();i++)
           {
               transport.receive[transport.r_count] = datas[i];
               transport.r_count++;
           }
           //receiveTimer->start(20);
           pressUartData();
       }
   }
}

void MainWindow::NET_send(QByteArray src)
{

    if(net_par.Server ==NULL )
    {
        infDisplay->append("no server operation");
        return ;
    }

    if(net_par.currentSocket ==NULL )
    {
        if(rf_send.device_id == 0xFFFF)
        {
            for(ushort i=0;i<SOCKET_MAX;i++)
            {
                if(net_par.Socket[i]!=NULL)
                {
                    net_par.Socket[i]->write(src);
                    NET_DisplayWithTime("send message to IP:"+net_par.Socket[i]->peerAddress().toString());
                }
            }
        }
        else
        {
            infDisplay->append("no client connect to the ID");
            return ;
        }
    }
    else
    {
        net_par.currentSocket->write(src);
        NET_DisplayWithTime("send message to IP:"+net_par.currentSocket->peerAddress().toString());
    }



    QString str;
    str = src.toHex().toUpper();
    for(ushort i =0; i*3<str.length();i++)
    {
        str.insert(i*3+2, " ");
    }
    infEdit->setPlainText(str);



    if(rb_displayRawHex->isChecked()==true)
    {
        DisplayWithTime(QString("tcp/ip send %1 byte").arg(src.length()));
        textBr_mess->append(str.toUpper());
    }
}


void MainWindow::on_bt_netSend_clicked()
{
    NET_getBindSocket(rf_send.device_id);
    NET_send(infEdit->toPlainText().toLatin1());

}


void MainWindow::newListen()
{
    ushort port;
    QString str = textEdit_Port->toPlainText();
    port = str.toUShort();

    str = textEdit_IP->toPlainText();
    QHostAddress ip;
    ip.setAddress(str);


   //监听是否有客户端来访，且对任何来访者监听，端口为6666
   if(!net_par.Server->listen(ip,port))
   {

      qDebug()<<net_par.Server->errorString();

      close();

      return;

   }
}



void MainWindow::acceptConnection()
{
    ushort i;
    QString str;

    for(i=0;i<SOCKET_MAX;i++)
    {
        if(net_par.Socket[i] == NULL)
        {
            net_par.Socket[i] = new QTcpSocket(this);
            //net_par.currentSocket = net_par.Socket[i];
            //当tcpSocket在接受客户端连接时出现错误时，displayError(QAbstractSocket::SocketError)进行错误提醒并关闭tcpSocket。
            connect(net_par.Socket[i],SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

            //当有客户来访时将tcpSocket接受tcpServer建立的socket
            net_par.Socket[i] = net_par.Server->nextPendingConnection();
            connect(net_par.Socket[i],SIGNAL(readyRead()),this,SLOT(revData()));
            str = "new client connection";
            str +=" / peerName:"+net_par.Socket[i]->peerName();
            str +=" / peerAddress:"+net_par.Socket[i]->peerAddress().toString();
            str +=QString(" / peerPort:%1").arg(net_par.Socket[i]->peerPort());
            NET_DisplayWithTime(str);


            break;
        }
    }
}



void MainWindow::displayError(QAbstractSocket::SocketError)
{
    ushort i;
    //qDebug()<<net_par.Socket[0]->errorString();
    for(i=0;i<SOCKET_MAX;i++)
    {
        if(net_par.Socket[i]->errorString()!=NULL)
        net_par.Socket[i]->close();
        net_par.Socket[i] = NULL;
    }
}



void MainWindow::on_bt_listen_clicked()
{
    bt_listen->setDisabled(true);
    bt_stopListen->setDisabled(false);
    net_par.Server = new QTcpServer(this);




    newListen();
    //newConnection()用于当有客户端访问时发出信号，acceptConnection()信号处理函数
    connect(net_par.Server,SIGNAL(newConnection()),this,SLOT(acceptConnection()));




}

void MainWindow::on_bt_stopListen_clicked()
{
    for(ushort i = 0;i<SOCKET_MAX;i++)
    {
        if(net_par.Socket[i]!=NULL)
        {
            net_par.Socket[i]->close();
        }
    }

    net_par.Server->close();
    bt_listen->setDisabled(false);
}

void MainWindow::on_bt_searchId_clicked()
{
    QString str;
    ushort id;

    str = textEdit_ID->toPlainText();
    id = str.toUShort();
    str = id_access.getIdInf(id);

    NET_DisplayWithTime(str);

}
void MainWindow::on_export_idList_clicked()
{
    NET_DisplayWithTime("Export id information to file(id_information.txt)");
    NET_DisplayWithTime("starting......");
    id_access.ExportIdInformation();
    NET_DisplayWithTime("finish");
}

void MainWindow::NET_DisplayWithTime(const QString &text)
{
    QDateTime datTime = QDateTime::currentDateTime();
    infDisplay->append(datTime.toString("yyyy/MM/dd hh:mm:ss // ")+text);
}

void MainWindow::NET_DisplayWithNoTime(const QString &text)
{
    infDisplay->append( text);
}


void MainWindow::NET_setBindSocket(ushort id)
{
     if(comunication_protocal->currentText() == "Network")
     net_par.bind_socket[id] = net_par.currentSocket;
}

void MainWindow::NET_getBindSocket(ushort id)
{
    if(comunication_protocal->currentText() == "Network")
    net_par.currentSocket = net_par.bind_socket[id];
}








/*******************network end******************/


void MainWindow::on_bt_clear_clicked()
{
    textBr_inp->clear();
    textBr_mess->clear();
    infDisplay->clear();
    infEdit->clear();
    infReceive->clear();
}

void MainWindow::on_comunication_protocal_currentTextChanged(const QString &arg1)
{
    if(arg1=="Network" || arg1=="Uart")
    {
        transport.r_count = 0;
        transport.s_count = 0;
    }
}

void MainWindow::on_bt_search_net_clicked()
{
    QString str;
    ushort id;

    str = textEdit_ID2->toPlainText();
    id = str.toUShort();

    if(net_par.bind_socket[id] == NULL)
    {
        str = QString("ID %1 bind to NULL:").arg(id);
    }
    else
    {
       str = QString("ID %1 bind to IP:").arg(id);
       str += net_par.bind_socket[id]->peerAddress().toString();
    }
    NET_DisplayWithTime(str);
}
