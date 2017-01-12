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
	timeoutTime = NULL;
    file_send = NULL;
    file_send_count = 0;
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
	connect(bt_clear, SIGNAL(clicked(bool)), textBr_inp, SLOT(clear()));
	connect(bt_clear, SIGNAL(clicked(bool)), textBr_mess, SLOT(clear()));
	connect(port,SIGNAL(newDataInPortSignal(QTime,const unsigned char *, const int)),this, SLOT(receiveMsg(QTime,const unsigned char *, const int)));
    connect(spinBox_Period, SIGNAL(valueChanged(int)), this, SLOT(intervalChange(int)));
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
//	if (spinBox_Period->value() <= 0)
//        transmitMsg();
//	else
//	{
//		timerout->start(spinBox_Period->value());
//		bt_send->setEnabled(false);
//		bt_stopsend->setEnabled(true);
//	}

    if(File->isChecked() == true)
    {
        progressBar->setValue(0);
        file_send_count = 0;
        timerout->stop();
    }
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
	connect(calcTimeoutAct, SIGNAL(toggled(bool)), this, SLOT(setTimeoutTimer(bool)));
	
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
	setTimeoutTimer(false);
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
	textBr_mess->append(QString("read %1").arg(size));

	QTime timedb;
	timedb = timesl ;
	qDebug()<<"mainwindow "<<"inputtime= "<<"\t"<<timedb.second()<<" "<<timedb.msec();
	qDebug()<<"mainwindow "<<"time= "<<"\t\t\t"<<timedb.currentTime().second()<<" "<<timedb.currentTime().msec()<<"-------------------------";

	if (calcTimeoutAct->isChecked())
	{
		if (timeoutTime)
			textBr_inp->append(QString("timeout %1 ms").arg(timeoutTime->msecsTo(timesl)));
		else timeoutTime = new QTime();
		*timeoutTime = timesl;
	}
	textBr_inp->append(transformInpData(data, size));
	counter_in+=size;
	labelReceive->setText(QString("receive %1").arg(counter_in));
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

void MainWindow::setTimeoutTimer(bool state)
{
	if (state);
	else
	{
		delete timeoutTime;
		timeoutTime = NULL;
	}
}

QString MainWindow::transformInpData(const unsigned char *data, int size)
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
    unsigned short int crc_calculate;
    int percent = 0;

    if(File->isChecked() == false)
    {
        getdataout(&data);
        count = port->write(data, data.length());
        textBr_mess->append(QString("transmited %1").arg(count));

    }
    else
    {
        if(file_send_count < file_send.length())
        {
            data = file_send.mid(file_send_count , 1000);
            file_send_count+=1000;
            send_frames_count = file_send_count/1000;

            data.insert(0,"A5LLSSMM");
            data.insert(data.length(),"CC");
            //frames head
            data[0] = 0xAA;
            data[1] = 0x55;
            //lenght
            data[2] = (data.length()-4)/256;
            data[3] = (data.length()-4)%256;
            //frames count
            data[4] = send_frames_count/256;
            data[5] = send_frames_count%256;
            //frames max
            data[6] = send_frames_max/256;
            data[7] = send_frames_max%256;

            crc_calculate = Crc16Bit(data , data.length()-2);
            data[data.length()-2] = (crc_calculate>>8)&0xff;
            data[data.length()-1] = crc_calculate&0xff;


            count = port->write(data, data.length());
            percent = send_frames_count*100/send_frames_max;
            textBr_mess->append(QString("transmit %1 ").arg(data.length()));
            textBr_mess->append(QString("frames max: %1").arg(send_frames_max));
            textBr_mess->append(QString("frames count: %1").arg(send_frames_count));
            progressBar->setValue(percent);
            timerout->start(100);
        }
        else
        {
            data = md5_Array;
            send_frames_count = send_frames_max;

            data.insert(0,"A5LLSSMM");
            data.insert(data.length(),"CC");
            //frames head
            data[0] = 0xAA;
            data[1] = 0x55;
            //lenght
            data[2] = (data.length()-4)/256;
            data[3] = (data.length()-4)%256;
            //frames count
            data[4] = send_frames_count/256;
            data[5] = send_frames_count%256;
            //frames max
            data[6] = send_frames_max/256;
            data[7] = send_frames_max%256;

            crc_calculate = Crc16Bit(data , data.length()-2);
            data[data.length()-2] = (crc_calculate>>8)&0xff;
            data[data.length()-1] = crc_calculate&0xff;


            count = port->write(data, data.length());
            percent = send_frames_count*100/send_frames_max;
            textBr_mess->append(QString("transmit %1 ").arg(data.length()));
            textBr_mess->append(QString("frames max: %1").arg(send_frames_max));
            textBr_mess->append(QString("frames count: %1").arg(send_frames_count));
            progressBar->setValue(percent);
            timerout->stop();
            file_send_count = 0;
        }
    }

    if (count == -1) count = 0;
    counter_out += count;
    labelTransmit->setText(QString("transmit %1").arg(counter_out));
}
 


void MainWindow::on_File_clicked()
{
    if(File->isChecked() == true)
    {
        QStringList fileNameList;
        QString fileName0;
        QString str;
        QFileDialog* fd = new QFileDialog(this);//创建对话框
        fd->resize(240,320);    //设置显示的大小
        fd->setNameFilter("Allfile(*.*);;hexfile(*.hex);;binfile(*.bin)");//设置文件过滤器
        fd->setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs);
        fd->setViewMode(QFileDialog::Detail);  //设置浏览模式，有 列表（list） 模式和 详细信息（detail）两种方式
        if ( fd->exec() == QDialog::Accepted )   //如果成功的执行
        {
            fileNameList = fd->selectedFiles();      //返回文件列表的名称
            fileName0 = fileNameList[0];            //取第一个文件名
            fd->close();
            QFile file(fileName0);
            if(!file.open(QIODevice::ReadOnly))
            {
               textBr_mess->append("file opne error");
            }
            else
            {

                file_send.clear();
                file_send = file.readAll();
                file.close();

                QFile fd_creat("readfile.bin");
                fd_creat.open(QIODevice::WriteOnly);
                fd_creat.write(file_send);
                fd_creat.close();

                file_send_count = 0;
                send_frames_max = file_send.length()/1000;
                if(file_send.length()%1000)
                {
                    send_frames_max +=2;
                }
                else
                {
                    send_frames_max +=1;
                }
                send_frames_count = 0;

                textEd_out->clear();

                textEd_out->setPlainText(file_send.toHex());


                MD5 md5;
                md5.update(file_send,file_send.length());
                md5_Array.clear();
                md5_Array = QByteArray::fromStdString(md5.toString());
                md5_Array.insert(0,"MD5:");

                textBr_mess->append(fileName0);
                textBr_mess->append(QString("file size: %1").arg(file_send.length()));
                textBr_mess->append(QString("frames max: %1").arg(send_frames_max));
                textBr_mess->append(QString("frames count: %1").arg(send_frames_count));
                textBr_mess->append(md5_Array);
            }
        }
        else
        {
            fd->close();
        }

    }
}
