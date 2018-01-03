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
#include <equation.h>

#include "mainwindow.h"
#include <threadcomport.h>
#include "ui_main_window_form.h"
#include "mangeid.h"
#include <QPainter>
#include <QGraphicsItem>
#include <QWidget>
#include "mygraphicsitem.h"
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
    LOC_init();
    COO_init();
    ENE_init();
    INJ_init();
    SOS_init();
    BLE_init();
    BLE_DisplayInit();
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
     rf_send.rssi = 100;
     rf_send.device = dev_gatway;



     /**************file stroe file*********************/



     QDir dir;
     QString path;
     path = QDir::currentPath();

     dir.cd(path);
     dir.mkdir("history");
     path +="/history";
     dir.cd(path);

     history_par.Network_path = "Network";
     history_par.Uart_path = "Uart";
     history_par.Update_path = "Update";
     history_par.cool_path = "cool";
     history_par.custom_path = "custom";
     history_par.energy_path = "energy";
     history_par.injection_path = "injection";
     history_par.sos_path = "sos";
     history_par.location_path = "location";
     history_par.ble_path = "ble";

     dir.mkdir(history_par.Network_path);
     dir.mkdir(history_par.Uart_path);
     dir.mkdir(history_par.Update_path);
     dir.mkdir(history_par.cool_path);
     dir.mkdir(history_par.custom_path);
     dir.mkdir(history_par.energy_path);
     dir.mkdir(history_par.injection_path);
     dir.mkdir(history_par.sos_path);
     dir.mkdir(history_par.location_path);
     dir.mkdir(history_par.ble_path);

     path+="/";
     history_par.Network_path   = path+history_par.Network_path;
     history_par.Uart_path      = path+history_par.Uart_path;
     history_par.Update_path    = path+history_par.Update_path;
     history_par.cool_path      = path+history_par.cool_path;
     history_par.custom_path    = path+history_par.custom_path;
     history_par.energy_path    = path+history_par.energy_path;
     history_par.injection_path = path+history_par.injection_path;
     history_par.sos_path = path+history_par.sos_path;
     history_par.location_path  = path+history_par.location_path;
     history_par.ble_path  = path+history_par.ble_path;

     history_par.Network_buff.clear();
     history_par.Uart_buff.clear();
     history_par.Update_buff.clear();
     history_par.cool_buff.clear();
     history_par.custom_buff.clear();
     history_par.energy_buff.clear();
     history_par.injection_buff.clear();
     history_par.sos_buff.clear();
     history_par.location_buff.clear();
     history_par.ble_buff.clear();

//     history_par.Network_file = new QFile(history_par.Network_path+"/current.txt");
//     history_par.Network_file->open(QIODevice::ReadWrite);
//     history_par.Network_file->write("konying history log\r\n");
//     history_par.Network_file->close();

//     history_par.Uart_file = new QFile(history_par.Uart_path+"/current.txt");
//     history_par.Uart_file->open(QIODevice::ReadWrite);
//     history_par.Uart_file->write("konying history log\r\n");
//     history_par.Uart_file->close();

//     history_par.Update_file = new QFile(history_par.Update_path+"/current.txt");
//     history_par.Update_file->open(QIODevice::ReadWrite);
//     history_par.Update_file->write("konying history log\r\n");
//     history_par.Update_file->close();


//     history_par.cool_file = new QFile(history_par.cool_path+"/current.txt");
//     history_par.cool_file->open(QIODevice::ReadWrite);
//     history_par.cool_file->write("konying history log\r\n");
//     history_par.cool_file->close();

//     history_par.custom_file = new QFile(history_par.custom_path+"/current.txt");
//     history_par.custom_file->open(QIODevice::ReadWrite);
//     history_par.custom_file->write("konying history log\r\n");
//     history_par.custom_file->close();

//     history_par.energy_file = new QFile(history_par.energy_path+"/current.txt");
//     history_par.energy_file->open(QIODevice::ReadWrite);
//     history_par.energy_file->write("konying history log\r\n");
//     history_par.energy_file->close();

//     history_par.injection_file = new QFile(history_par.injection_path+"/current.txt");
//     history_par.injection_file->open(QIODevice::ReadWrite);
//     history_par.injection_file->write("konying history log\r\n");
//     history_par.injection_file->close();

//     history_par.location_file = new QFile(history_par.location_path+"/current.txt");
//     history_par.location_file->open(QIODevice::ReadWrite);
//     history_par.location_file->write("konying history log\r\n");
//     history_par.location_file->close();


     history_par.time_count = 0;
     history_par.timer = new QTimer(this);
     connect(history_par.timer,SIGNAL(timeout()),this,SLOT(storeHistoryLog()));
     history_par.timer->start(1000);
     /**************file stroe file*********************/

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
//    textBr_inp->append(datTime.toString("yyyy-MM-dd hh:mm:ss")+
//                       QString(" %1 mS").arg(timesl.msec())+
//                       QString("receive: %1 byte").arg(size)
//                       );
//    textBr_inp->append(transformInpData(data, size));
//    textBr_inp->insertPlainText(transformInpData(data, size));

    if(comunication_protocal->currentText() == "Uart")
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
    LOCATION_FRAME location_frame;
    BLE_LOCATION_FRAME ble_location_frame;
    COOL_FRAME cool_frame;


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
        if(comunication_protocal->currentText() == "Server")
        {
            DisplayWithTime(QString("tcp/ip Server receive %1 byte").arg(buff.length()));
        }
        else if(comunication_protocal->currentText() == "Client")
        {
            DisplayWithTime(QString("tcp/ip Client receive %1 byte").arg(buff.length()));
        }
        else if(comunication_protocal->currentText() == "Uart")
        {
            DisplayWithTime(QString("uart receive %1 byte").arg(buff.length()));
        }


        textBr_mess->append(str.toUpper()+"\r\n");
        history_par.Update_buff += str;
    }

    iot_frame.head = data[0]*256+data[1];
    iot_frame.gateway_id = data[2]*256+data[3];
    iot_frame.device_id = data[4]*256+data[5];
    iot_frame.cmd = data[6];
    iot_frame.length = data[7];
    iot_frame.data = &data[8];
    iot_frame.checkSum = data[size-1];
    iot_frame.rssi = data[size-2];

    str = "gateway_id:";
    str0 = "0x" + uint16ToHex(iot_frame.gateway_id).toUpper();
    str += str0;

    if(shortAddr->findItems(str0 , Qt::MatchExactly).isEmpty())
    {
        shortAddr->insertItem(0,tr(""));
        shortAddr->item(0)->setText(str0);
        total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));
    }
    NET_setBindSocket(iot_frame.gateway_id);
    id_access.updateBindID(iot_frame.gateway_id,iot_frame.gateway_id);//更新绑定ID


    str += "/ device_id:";
    str0 = "0x" + uint16ToHex(iot_frame.device_id).toUpper();
    str += str0;

    if(shortAddr->findItems(str0 , Qt::MatchExactly).isEmpty())
    {
        //判断ID列表是否存在，如不存在立即添加
        shortAddr->insertItem(0,tr(""));
        shortAddr->item(0)->setText(str0);
        total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));
    }
    NET_setBindSocket(iot_frame.device_id);//更新更定IP
    id_access.updateBindID(iot_frame.gateway_id,iot_frame.device_id);//更新绑定ID





    str += QString("/ rssi:%1dBm").arg(iot_frame.rssi ,0,10);


    if(iot_frame.cmd == cmd_heartBeat)
    {
        str +=QString("/ heartbeat time:%1").arg(iot_frame.data[0]*256+iot_frame.data[1]);
        str +=QString("/ bandwith:%1").arg(iot_frame.data[4]*256+iot_frame.data[5]);

        IOT_cmdHeartBeat(&iot_frame);
        NET_DisplayWithTime(str);
    }
    else if(iot_frame.cmd == cmd_idRequest)
    {
        if(networkAutoIdStatus->isChecked()==true)
        {
            //send = id_access.accessId(iot_frame.data);
            send = id_access.accessId(iot_frame.data,
                                      textEdit_MAX_ID->toPlainText().toUShort(),
                                      textEdit_MIN_ID->toPlainText().toUShort());
            NET_DisplayWithTime("自动分配");
        }
        else if(networkManuIdStatus->isChecked()==true)
        {
            send = id_access.checkId(iot_frame.data);
            NET_DisplayWithTime("固定分配");
        }
        if(send.device_id == 0xFFFF)return;

        str0 = "0x" + uint16ToHex(send.device_id).toUpper();
        if(shortAddr->findItems(str0 , Qt::MatchExactly).isEmpty())
        {
            shortAddr->insertItem(0,tr(""));
            shortAddr->item(0)->setText(str0);
            total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));
        }

        NET_setBindSocket(send.device_id);
        IOT_cmdAsscessId(iot_frame.gateway_id,iot_frame.device_id,&send);
        id_access.getIdInf(send.device_id);
        NET_DisplayWithTime(id_access.getIdInf(send.device_id));
    }
    else if(iot_frame.cmd == cmd_app)
    {
        if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x1E)
        {
            //include rssi
            //BLE&Outdoor location
            ble_location_frame.head[0] = iot_frame.data[0];
            ble_location_frame.head[1] = iot_frame.data[1];
            ble_location_frame.device_type = iot_frame.data[2];
            ble_location_frame.sequence = iot_frame.data[3];
            memcpy(ble_location_frame.devie_id,&iot_frame.data[4],8);
            memcpy(ble_location_frame.ant_ble_id,&iot_frame.data[12],8);
            ble_location_frame.ant_125k_id = iot_frame.data[20]*256+iot_frame.data[21];
            ble_location_frame.rssi = iot_frame.data[22];
            ble_location_frame.sensor_x = iot_frame.data[23];
            ble_location_frame.sensor_y = iot_frame.data[24];
            ble_location_frame.sensor_z = iot_frame.data[25];
            ble_location_frame.battery = iot_frame.data[26];
            ble_location_frame.alarm = iot_frame.data[27];
            ble_location_frame.checksum = iot_frame.data[28];


            if(checkSum((char *)(&iot_frame.data[0]),0x1C)!= ble_location_frame.checksum)
            {
                return ;
            }

            if(locationStopDisplay->isChecked() == true)return;
            if(locationDisplayMac->isChecked() == true)
            {
                str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

            }

            //if(iot_frame.device_id != loc_par.filtId[0] && loc_par.filtId[0] != 0xFFFF)
            if( iot_frame.device_id != loc_par.filtId[0]&&
                iot_frame.device_id != loc_par.filtId[1]&&
                iot_frame.device_id != loc_par.filtId[2]&&
                iot_frame.device_id != loc_par.filtId[3]&&
                iot_frame.device_id != loc_par.filtId[4])
            {
                if(loc_par.filtId[0]!=0xFFFF||
                    loc_par.filtId[1]!=0xFFFF||
                    loc_par.filtId[2]!=0xFFFF||
                    loc_par.filtId[3]!=0xFFFF||
                    loc_par.filtId[4]!=0xFFFF)
                {
                    return;
                }
            }



            if(ble_location_frame.device_type == location_device_125k)str += QString("/ mode_125K");
            else if(ble_location_frame.device_type == location_device_868)str += QString("/ mode_868");
            else if(ble_location_frame.device_type == location_device_ble)str += QString("/ mode_ble");
            str += QString("/ seq:%1").arg(ble_location_frame.sequence);
            str += "/ device_id:"+strToHex(ble_location_frame.devie_id,8).toUpper();
            str += "/ ant_id:"+strToHex(ble_location_frame.ant_ble_id,8).toUpper();
            str += "/ 125k_id:0x"+uint16ToHex(ble_location_frame.ant_125k_id);
            str += QString("/ BLE_rssi:%1").arg(ble_location_frame.rssi,0,10);
            str += "/ x:"+uint8ToHex(ble_location_frame.sensor_x);
            str += " y:"+uint8ToHex(ble_location_frame.sensor_y);
            str += " z:"+uint8ToHex(ble_location_frame.sensor_z);
            str += QString("/ voltage:%1.%2").arg(ble_location_frame.battery/10,0,10).arg(ble_location_frame.battery%10,0,10);

            if(checkDrop(ble_location_frame.alarm))str += " 跌落报警;";
            if(checkAlarm(ble_location_frame.alarm))str += " 紧急报警;";
            if(checkLocation(ble_location_frame.alarm))str += " 室外报警;";
            if(checkLowBattery(ble_location_frame.alarm))str += " 低电报警;";
            if(checkTamper(ble_location_frame.alarm))str += " 防拆报警;";
            if(loc_par.filtStr.length()!=0)
            {

                if(str.contains(loc_par.filtStr) == false)
                return;
            }
            LOC_DisplayWithTime(str);
        }
        if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x0A)
        {
            //include rssi
            location_frame.head[0] = iot_frame.data[0];
            location_frame.head[1] = iot_frame.data[1];
            location_frame.devie_id = iot_frame.data[2]*256+iot_frame.data[3];
            location_frame.ant_id = iot_frame.data[4]*256+iot_frame.data[5];
            location_frame.rssi = iot_frame.data[6];
            location_frame.alarm = iot_frame.data[7];
            location_frame.checksum = iot_frame.data[8];


            if(checkSum((char *)(&iot_frame.data[2]),6)!= iot_frame.data[8])
            {
                return ;
            }

            if(locationStopDisplay->isChecked() == true)return;
            if(locationDisplayMac->isChecked() == true)
            {
                str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

            }

            //if(iot_frame.device_id != loc_par.filtId[0] && loc_par.filtId[0] != 0xFFFF)
            if( iot_frame.device_id != loc_par.filtId[0]&&
                iot_frame.device_id != loc_par.filtId[1]&&
                iot_frame.device_id != loc_par.filtId[2]&&
                iot_frame.device_id != loc_par.filtId[3]&&
                iot_frame.device_id != loc_par.filtId[4])
            {
                if(loc_par.filtId[0]!=0xFFFF||
                    loc_par.filtId[1]!=0xFFFF||
                    loc_par.filtId[2]!=0xFFFF||
                    loc_par.filtId[3]!=0xFFFF||
                    loc_par.filtId[4]!=0xFFFF)
                {
                    return;
                }
            }





            str += QString("/ devie_id:%1").arg(location_frame.devie_id)+"=0x"+uint16ToHex(location_frame.devie_id).toUpper();
            str += QString("/ ant_id:%1").arg(location_frame.ant_id)+"=0x"+uint16ToHex(location_frame.ant_id).toUpper();
            str += QString("/ rssi:%1").arg(location_frame.rssi,0,10);
            str += "/ alarm:0x"+uint8ToHex(location_frame.alarm).toUpper();
            if(checkDrop(location_frame.alarm))str += " 跌落报警;";
            if(checkAlarm(location_frame.alarm))str += " 紧急报警;";
            if(checkLocation(location_frame.alarm))str += " 室外报警;";
            if(checkLowBattery(location_frame.alarm))str += " 低电报警;";
            if(checkTamper(location_frame.alarm))str += " 防拆报警;";
            if(loc_par.filtStr.length()!=0)
            {

                if(str.contains(loc_par.filtStr) == false)
                return;
            }
            LOC_DisplayWithTime(str);
        }
        else if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x09)//no rssi
        {
            //新腕带程序
            location_frame.head[0] = iot_frame.data[0];
            location_frame.head[1] = iot_frame.data[1];
            location_frame.devie_id = iot_frame.data[2]*256+iot_frame.data[3];
            location_frame.ant_id = iot_frame.data[4]*256+iot_frame.data[5];
            location_frame.rssi = iot_frame.data[6];
            location_frame.alarm = iot_frame.data[7];
            location_frame.checksum = iot_frame.data[8];


            if(checkSum((char *)(&iot_frame.data[2]),6)!= iot_frame.data[8])
            {
                return ;
            }

            if(locationStopDisplay->isChecked() == true)return;
            if(locationDisplayMac->isChecked() == true)
            {
                str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

            }

            //if(iot_frame.device_id != loc_par.filtId[0] && loc_par.filtId[0] != 0xFFFF)
            if( iot_frame.device_id != loc_par.filtId[0]&&
                iot_frame.device_id != loc_par.filtId[1]&&
                iot_frame.device_id != loc_par.filtId[2]&&
                iot_frame.device_id != loc_par.filtId[3]&&
                iot_frame.device_id != loc_par.filtId[4])
            {
                return;
            }
            else if(loc_par.filtId[0]!=0xFFFF&&
                    loc_par.filtId[1]!=0xFFFF&&
                    loc_par.filtId[2]!=0xFFFF&&
                    loc_par.filtId[3]!=0xFFFF&&
                    loc_par.filtId[4]!=0xFFFF)
            {
                return;
            }





            str += QString("/ devie_id:%1").arg(location_frame.devie_id)+"=0x"+uint16ToHex(location_frame.devie_id).toUpper();
            str += QString("/ ant_id:%1").arg(location_frame.ant_id)+"=0x"+uint16ToHex(location_frame.ant_id).toUpper();
            str += QString("/ rssi:%1").arg(location_frame.rssi,0,10);
            str += "/ alarm:0x"+uint8ToHex(location_frame.alarm).toUpper();
            if(checkDrop(location_frame.alarm))str += " 跌落报警;";
            if(checkAlarm(location_frame.alarm))str += " 紧急报警;";
            if(checkLocation(location_frame.alarm))str += " 室外报警;";
            if(checkLowBattery(location_frame.alarm))str += " 低电报警;";
            if(checkTamper(location_frame.alarm))str += " 防拆报警;";
            if(loc_par.filtStr.length()!=0)
            {

                if(str.contains(loc_par.filtStr) == false)
                return;
            }
            LOC_DisplayWithTime(str);
        }
        else if(iot_frame.data[0]==0xFA && iot_frame.data[1]==0xCA)
        {


            cool_frame.head[0] = iot_frame.data[0];
            cool_frame.head[1] = iot_frame.data[1];
            cool_frame.sensorId = iot_frame.data[2]*256+iot_frame.data[3];
            cool_frame.deviceType = iot_frame.data[4];
            cool_frame.len = iot_frame.data[5];
            cool_frame.cmd = iot_frame.data[6];
            cool_frame.data = &iot_frame.data[7];
            cool_frame.checksum = iot_frame.data[6+cool_frame.len];

            if(checkSum((char *)(iot_frame.data),cool_frame.len+6)!= cool_frame.checksum)
            {
                return ;
            }



            if(cool_frame.deviceType == coolDevTempreture)
            {
                //if(cool_frame.cmd != 0xFE)COO_ackSuccess(iot_frame.gateway_id,iot_frame.device_id,cool_frame.cmd);
                if(coolStopDisplay->isChecked() == true)return;
                if(coolDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }

                if(iot_frame.device_id != coo_par.filtId && coo_par.filtId != 0xFFFF)
                {
                    return;
                }



                str += QString("/ sensor_id:%1").arg(cool_frame.sensorId);
                str += "=0x"+uint16ToHex(cool_frame.sensorId).toUpper();
                str +="/ 温度传感器";
                double double_num;
                switch(cool_frame.cmd)
                {
                    case coolCmdUnkown:
                    str +="/ coolCmdUnkown";
                    break;


                    case coolCmdGetDisNum:
                    str +="/ coolCmdGetDisNum：";
                    str +=QString("%1").arg(cool_frame.data[0]*256+cool_frame.data[1]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;




                    case coolCmdSetDisNum:
                    str +="/ coolCmdSetDisNum：";
                    str +=QString("%1").arg(cool_frame.data[0]*256+cool_frame.data[1]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;




                    case coolCmdAlarm:
                    str +="/ coolCmdAlarm:";
                    if(cool_frame.data[0] == 0)str += "00 超过上限温度";
                    else if(cool_frame.data[0] == 1)str += "01 低于下限温度";

                    if(cool_frame.data[1] == 0)str += "/ +";
                    else if(cool_frame.data[1] == 1)str += "/ -";
                    double_num = cool_frame.data[2]*256+
                                cool_frame.data[3]+
                                (double )cool_frame.data[4]/100;
                    str += QString("%1'C").arg(double_num);
                    double_num = cool_frame.data[5]+
                                (double )cool_frame.data[6]/100;
                    str += QString("/ %1%H").arg(double_num);

                    //str += QString("%1.").arg(cool_frame.data[2]*256+cool_frame.data[3]);
                    //str += QString("%1'C").arg(cool_frame.data[4],2,10);
                    //str += QString("/ %1.%2%H").arg(cool_frame.data[5]).arg(cool_frame.data[6]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[7]).toUpper();
                    break;




                    case coolCmdDisarm:
                    str +="/ coolCmdDisarm";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;




                    case coolCmdSetRepTime:
                    str +="/ coolCmdSetRepTime:";
                    uint detect_time;
                    detect_time = (cool_frame.data[0]<<24)+
                                  (cool_frame.data[1]<<16)+
                                  (cool_frame.data[2]<<8)+
                                  (cool_frame.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(detect_time)+uint32ToHex(detect_time).toUpper()+"mS";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[4]).toUpper();
                    break;


                    case coolCmdTemVer:
                    str +="/ coolCmdTemVer";
                    if(cool_frame.data[0] == 0)str +="/ +";
                    else if(cool_frame.data[0] == 1)str +="/ -";
                    double_num = (double)cool_frame.data[1]/10;
                    str += QString("%1'C").arg(double_num);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;



                    case coolCmdHumVer:
                    str +="/ coolCmdHumVer";
                    if(cool_frame.data[0] == 0)str +="/ +";
                    else if(cool_frame.data[0] == 1)str +="/ -";
                    double_num = (double)cool_frame.data[1]/10;
                    str += QString("%1%H").arg(double_num);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;



                    case coolCmdGetSenVal:
                    str +="/ coolCmdGetSenVal";
                    if(cool_frame.data[0] == 0)str += "/ +";
                    else if(cool_frame.data[0] == 1)str += "/ -";
                    double_num = cool_frame.data[1]*256+
                                cool_frame.data[2]+
                                (double )cool_frame.data[3]/100;
                    str += QString("%1'C").arg(double_num);
                    double_num = cool_frame.data[4]+
                                (double )cool_frame.data[5]/100;
                    str += QString("/ %1%H").arg(double_num);

                    //str += QString("%1.").arg(cool_frame.data[1]*256+cool_frame.data[2]);
                    //str += QString("%1'C").arg(cool_frame.data[3],2,10);
                    //str += QString("/ %1.%2%H").arg(cool_frame.data[4]).arg(cool_frame.data[5],2,10);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[6]).toUpper();
                    break;




                    case coolCmdSetAlaVal:
                    str +="/ coolCmdSetAlaVal";
                    if(cool_frame.data[0] == 0)str += "/ 上限温度：+";
                    else if(cool_frame.data[0] == 1)str += "/ 上限温度：-";
                    double_num = cool_frame.data[1]*256+
                                cool_frame.data[2]+
                                (double )cool_frame.data[3]/100;
                    str += QString("%1'C").arg(double_num);

                    //str += QString("%1.").arg(cool_frame.data[1]*256+cool_frame.data[2]);
                    //str += QString("%1'C").arg(cool_frame.data[3],2,10);

                    if(cool_frame.data[4] == 0)str += "/ 下限温度：+";
                    else if(cool_frame.data[4] == 1)str += "/ 下限温度：-";
                    double_num = cool_frame.data[5]*256+
                                cool_frame.data[6]+
                                (double )cool_frame.data[7]/100;
                    str += QString("%1'C").arg(double_num);

                    //str += QString("%1.").arg(cool_frame.data[5]*256+cool_frame.data[6]);
                    //str += QString("%1'C").arg(cool_frame.data[7],2,10);
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[6]).toUpper();
                    break;



                    case coolCmdSenError:
                    str +="/ coolCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;
                    case coolCmdStatus:
                    str +="/ coolCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[1]).toUpper();
                    break;
                    default:
                    str +="/ ERROR";
                    break;
                }
                if(coo_par.filtStr.length()!=0)
                {

                    if(str.contains(coo_par.filtStr) == false)
                    return;
                }
                COO_DisplayWithTime(str);

            }
            else if(cool_frame.deviceType == coolDevSiren)
            {

            }
            else if(cool_frame.deviceType == coolDevSosPanic)
            {

            }
            else if(cool_frame.deviceType == coolDevUnkown)
            {

            }
            else if(cool_frame.deviceType == coolDevEnergy)
            {
                if(energyStopDisplay->isChecked() == true)return;
                if(energyDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }

                if(iot_frame.device_id != ene_par.filtId && ene_par.filtId != 0xFFFF)
                {
                    return;
                }



                str += QString("/ sensor_id:%1").arg(cool_frame.sensorId);
                str += "=0x"+uint16ToHex(cool_frame.sensorId).toUpper();
                str +="/ 插座";

                uint detect_u32;
                switch(cool_frame.cmd)
                {
                    case energyCmdSetRepTime:
                    str +="/ energyCmdSetRepTime:";
                    detect_u32 = (cool_frame.data[0]<<24)+
                                  (cool_frame.data[1]<<16)+
                                  (cool_frame.data[2]<<8)+
                                  (cool_frame.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(detect_u32)+uint32ToHex(detect_u32).toUpper()+"mS";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[4]).toUpper();
                    break;


                    case energyCmdGetMeasurement:
                    str +="/ energyCmdGetMeasurement";


                    if(cool_frame.len<0x12)
                    {
                        //220V
                        str +="/ 220V";


                        detect_u32 =  (cool_frame.data[0]<<24)+
                                      (cool_frame.data[1]<<16)+
                                      (cool_frame.data[2]<<8)+
                                      (cool_frame.data[3]<<0);
                        str +=QString("/ 电压：%1V").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame.data[4]<<24)+
                                      (cool_frame.data[5]<<16)+
                                      (cool_frame.data[6]<<8)+
                                      (cool_frame.data[7]<<0);
                        str +=QString("/ 电流：%1A").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame.data[8]<<24)+
                                      (cool_frame.data[9]<<16)+
                                      (cool_frame.data[10]<<8)+
                                      (cool_frame.data[11]<<0);
                        str +=QString("/ 功率：%1W").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame.data[12]<<24)+
                                      (cool_frame.data[13]<<16)+
                                      (cool_frame.data[14]<<8)+
                                      (cool_frame.data[15]<<0);
                        str +=QString("/ 电量：%1KW/H").arg((double)detect_u32/10000);
                    }
                    else
                    {
                        //380V
                        str +="/ 380V";

                        //A
                        detect_u32 =  (cool_frame.data[0]<<8)+
                                      (cool_frame.data[1]<<0);
                        str +=QString("/ A电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[2]<<8)+
                                      (cool_frame.data[3]<<0);
                        str +=QString("/ A电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[4]<<8)+
                                      (cool_frame.data[5]<<0);
                        str +=QString("/ A功率：%1W").arg((double)detect_u32);

                        detect_u32 = (cool_frame.data[6]<<24)+
                                      (cool_frame.data[7]<<16)+
                                      (cool_frame.data[8]<<8)+
                                      (cool_frame.data[9]<<0);
                        str +=QString("/ A电量：%1KWH").arg((double)detect_u32/800);

                        //B
                        detect_u32 =  (cool_frame.data[10]<<8)+
                                      (cool_frame.data[11]<<0);
                        str +=QString("/ B电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[12]<<8)+
                                      (cool_frame.data[13]<<0);
                        str +=QString("/ B电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[14]<<8)+
                                      (cool_frame.data[15]<<0);
                        str +=QString("/ B功率：%1W").arg((double)detect_u32);

                        detect_u32 = (cool_frame.data[16]<<24)+
                                      (cool_frame.data[17]<<16)+
                                      (cool_frame.data[18]<<8)+
                                      (cool_frame.data[19]<<0);
                        str +=QString("/ B电量：%1KWH").arg((double)detect_u32/800);

                        //C
                        detect_u32 =  (cool_frame.data[20]<<8)+
                                      (cool_frame.data[21]<<0);
                        str +=QString("/ C电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[22]<<8)+
                                      (cool_frame.data[23]<<0);
                        str +=QString("/ C电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame.data[24]<<8)+
                                      (cool_frame.data[25]<<0);
                        str +=QString("/ C功率：%1W").arg((double)detect_u32);

                        detect_u32 = (cool_frame.data[26]<<24)+
                                      (cool_frame.data[27]<<16)+
                                      (cool_frame.data[28]<<8)+
                                      (cool_frame.data[29]<<0);
                        str +=QString("/ C电量：%1KWH").arg((double)detect_u32/800);


                        detect_u32 = (cool_frame.data[30]<<24)+
                                      (cool_frame.data[31]<<16)+
                                      (cool_frame.data[32]<<8)+
                                      (cool_frame.data[33]<<0);
                        str +=QString("/ 总电量：%1KWH").arg((double)detect_u32/800);

                    }



                    break;



                    case energyCmdSenError:
                    str +="/ energyCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;
                    case energyCmdStatus:
                    str +="/ energyCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[1]).toUpper();
                    break;
                    default:
                    str +="/ ERROR";
                    break;
                }
                if(ene_par.filtStr.length()!=0)
                {

                    if(str.contains(ene_par.filtStr) == false)
                    return;
                }
                ENE_DisplayWithTime(str);
            }
            else if(cool_frame.deviceType == coolDevInjection)
            {
                if(cool_frame.cmd != 0xFE)INJ_ackSuccess(iot_frame.gateway_id,iot_frame.device_id,cool_frame.cmd);
                if(injectionStopDisplay->isChecked() == true)return;
                if(injectionDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }
                if(iot_frame.device_id != inj_par.filtId && inj_par.filtId != 0xFFFF)
                {
                    return;
                }


                str += QString("/ sensor_id:%1").arg(cool_frame.sensorId);
                str += "=0x"+uint16ToHex(cool_frame.sensorId).toUpper();
                str +="/ 移动输液";

                switch(cool_frame.cmd)
                {
                    case injectionCmdUnkown:
                    str +="/ injectionCmdUnkown";
                    str +="/ 未知命令";
                    break;

                    case injectionCmdPowerOn:
                    str +="/ injectionCmdPowerOn";
                    str +="/ 设备开机";
                    break;

                    case injectionCmdRepStatus:
                    str +="/ injectionCmdRepStatus";

                    str +=QString("/ %1滴/min ").arg(cool_frame.data[0]);

                    if(cool_frame.data[1] == 0)str +="/ 喇叭关闭";
                    else if(cool_frame.data[1] == 1)str +="/ 喇叭打开";
                    else str +="/ 喇叭状态未知";

                    str +=QString("/ 显示编号为：%1").arg(cool_frame.data[2]*256+cool_frame.data[3]);

                    if(cool_frame.data[4] == 0) str +=QString("/ 无告警：%1").arg(cool_frame.data[4]);
                    else if(cool_frame.data[4] == 1) str +=QString("/ 低限告警：%1").arg(cool_frame.data[4]);
                    else if(cool_frame.data[4] == 2) str +=QString("/ 高限告警：%1").arg(cool_frame.data[4]);
                    else if(cool_frame.data[4] == 3) str +=QString("/ 设备节流：%1").arg(cool_frame.data[4]);
                    else if(cool_frame.data[4] == 4) str +=QString("/ 输液暂停：%1").arg(cool_frame.data[4]);
                    else if(cool_frame.data[4] == 5) str +=QString("/ 输液完成：%1").arg(cool_frame.data[4]);
                    else str +=QString("/ 未知状态：%1").arg(cool_frame.data[4]);


                    str +=QString("/ 总滴数量：%1").arg(cool_frame.data[5]*256+cool_frame.data[6]);

                    str +=QString("/ 上限：%1 下限：%2").arg(cool_frame.data[7]).arg(cool_frame.data[8]);
\
                    str +=QString("/ 电量：%1%").arg(cool_frame.data[9]);
                    break;



                    case injectionCmdDevReset:
                    str +="/ injectionCmdDevReset";
                    str +="/ 设备复位";
                    break;
                    case injectionCmdDevCutoff:
                    str +="/ injectionCmdDevCutoff";
                    str +="/ 设备卡断";
                    break;
                    case injectionCmdPowerOff:
                    str +="/ injectionCmdPowerOff";
                    str +="/ 设备关机";
                    break;
                    case injectionCmdDevError:
                    str +="/ injectionCmdDevError";
                    str +="/ 设备异常";
                    break;
                    case injectionCmdDevStart:
                    str +="/ injectionCmdDevStart";
                    str +="/ 开始输液";
                    break;
                    case injectionCmdDevStop:
                    str +="/ injectionCmdDevStop";
                    str +="/ 暂停输液";
                    break;
                    case injectionCmdDevFinish:
                    str +="/ injectionCmdDevFinish";
                    str +="/ 完成输液";
                    break;
                    case injectionCmdSetTotalDi:
                    str +="/ injectionCmdSetTotalDi";
                    str +="/ 设置总滴量";
                    break;
                    case injectionCmdSetStopTimeout:
                    str +="/ injectionCmdSetStopTimeout";
                    str +="/ 设定停止超时时间";
                    break;
                    case injectionCmdGetDeviceParameter:
                    str +="/ injectionCmdGetDeviceParameter";
                    str +="/ 获取设备信息";

                    break;
                    case injectionCmdStatus:
                    str +="/ coolCmdStatus";

                    if(cool_frame.data[0] == injectionCmdGetDeviceParameter)
                    {
                        str +="/ injectionCmdGetDeviceParameter";

                        if(cool_frame.data[1]==0x00)str +="/ 关机状态";
                        else if(cool_frame.data[1]==0x01)str +="/ 开机状态";
                        else if(cool_frame.data[1]==0x02)str +="/ 正在输液";
                        else if(cool_frame.data[1]==0x03)str +="/ 输液暂停";
                        else if(cool_frame.data[1]==0x04)str +="/ 输液完成";


                        str +=QString("/ normal:%1滴/S max:%2滴/S min:%3滴/S").arg(cool_frame.data[2]).arg(cool_frame.data[3]).arg(cool_frame.data[4]);


                        if(cool_frame.data[5]==0x00)str +="/ 喇叭关闭";
                        else if(cool_frame.data[5]==0x01)str +="/ 喇叭打开";

                        str +=QString("/ 显示编号%1").arg(cool_frame.data[6]*256+cool_frame.data[7]);


                        uint injection_report_time;
                        injection_report_time = (cool_frame.data[8]<<24)+
                                                (cool_frame.data[9]<<16)+
                                                (cool_frame.data[10]<<8)+
                                                (cool_frame.data[11]<<0);
                        str +=QString("/ 上报时间%1").arg(injection_report_time);


                        if(cool_frame.data[12] == 0) str +=QString("/ 无告警：%1").arg(cool_frame.data[12]);
                        else if(cool_frame.data[12] == 1) str +=QString("/ 低限告警：%1").arg(cool_frame.data[12]);
                        else if(cool_frame.data[12] == 2) str +=QString("/ 高限告警：%1").arg(cool_frame.data[12]);
                        else str +=QString("/ 未知状态：%1").arg(cool_frame.data[12]);

                        str +=QString("/ 当前滴速%1").arg(cool_frame.data[13]);
                        str +=QString("/ 电机状态%1").arg(cool_frame.data[14]);
                        str +=QString("/ 输液状态%1").arg(cool_frame.data[15]);
                        str +=QString("/ 累积滴量%1").arg(cool_frame.data[16]*256+cool_frame.data[17]);
                        str +=QString("/ 总滴量%1").arg(cool_frame.data[18]*256+cool_frame.data[19]);
                        str +=QString("/ 检测时长%1").arg(cool_frame.data[20]*256+cool_frame.data[21]);


                    }
                    else
                    {
                        str +="/ status code:0x" + uint8ToHex(cool_frame.data[0]).toUpper();
                    }



                    break;
                    default:
                    str +="/ ERROR";
                    break;
                }
                if(inj_par.filtStr.length()!=0)
                {

                    if(str.contains(inj_par.filtStr) == false)
                    return;
                }

                INJ_DisplayWithTime(str);

            }
            else if(cool_frame.deviceType == coolDevSosNoLocationPanic)
            {
                if(sosStopDisplay->isChecked() == true)return;
                if(sosDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }

                if(iot_frame.device_id != sos_par.filtId && sos_par.filtId != 0xFFFF)
                {
                    return;
                }



                str += QString("/ sensor_id:%1").arg(cool_frame.sensorId);
                str += "=0x"+uint16ToHex(cool_frame.sensorId).toUpper();
                str +="/ SOS按键(不带定位)";

                uint32_t sos_report_time = 0;
                switch(cool_frame.cmd)
                {
                    case sosCmdSetRepTime:
                    str +="/ sosCmdSetRepTime:";
                    sos_report_time = (cool_frame.data[0]<<24)+
                                  (cool_frame.data[1]<<16)+
                                  (cool_frame.data[2]<<8)+
                                  (cool_frame.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(sos_report_time)+uint32ToHex(sos_report_time).toUpper()+"mS";

                    break;


                    case sosCmdReportStatus:
                    str +="/ sosCmdReportStatus";

                    str +=QString("/ voltage:%1.").arg(cool_frame.data[0]/10)+QString("%1V").arg(cool_frame.data[0]%10);

                    if(cool_frame.data[1]&BV(0))str +="/ 按键报警";
                    if(cool_frame.data[1]&BV(1))str +="/ 不要拆报警";

                    sos_report_time = (cool_frame.data[2]<<24)+
                                  (cool_frame.data[3]<<16)+
                                  (cool_frame.data[4]<<8)+
                                  (cool_frame.data[5]<<0);
                    str +=QString("/ ReportTime:%1mS").arg(sos_report_time);


                    break;

                    case sosCmdSenError:
                    str +="/ sosCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;
                    case sosCmdStatus:
                    str +="/ sosCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[1]).toUpper();
                    break;
                    default:
                    str +="/ ERROR";
                    break;
                }
                if(sos_par.filtStr.length()!=0)
                {

                    if(str.contains(sos_par.filtStr) == false)
                    return;
                }
                SOS_DisplayWithTime(str);
            }

        }

    }
    else if(iot_frame.cmd == cmd_network)
    {
        app_frame.rf.sequence = iot_frame.data[0];
        app_frame.rf.deviceType = iot_frame.data[1];
        app_frame.rf.cmd = iot_frame.data[2];
        app_frame.rf.data = &iot_frame.data[3];

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
        case dev_sosPanicLocation:
            str += "sosPanicLocation";
            break;
        case dev_plug:
            str += "plug";
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
        case dev_tag:
            str += "money_tag";
            break;
        case dev_125kTag:
            str += "dev_125kTag";
            break;
        case dev_rfidReader:
            str += "rfid_reader";
            break;
        case dev_sosPanic:
            str += "sosPanic";
            break;
        case dev_bleTag:
            str += "dev_bleTag";
            break;
        case dev_bleAnt:
            str += "bleAnt";
            break;
        case dev_repeater:
            str += "repeater";
            break;
        case dev_normal:
            str += "normal";
            break;
        case dev_lowPower:
            str += "lowPower";
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
                str+="/ 返回网络参数:\r\n";

                textEdit_panID->setText( "0x"+uint16ToHex(app_frame.rf.data[0]*256+app_frame.rf.data[1]).toUpper());
                textEdit_shortID->setText( "0x"+uint16ToHex(app_frame.rf.data[2]*256+app_frame.rf.data[3]).toUpper());
                textEdit_power->setText( "0x"+uint8ToHex(app_frame.rf.data[4]).toUpper());
                textEdit_channel->setText(  "0x"+uint8ToHex(app_frame.rf.data[5]).toUpper());




                str+=("panID:    "+textEdit_panID->toPlainText()+"\r\n");
                str+=("shorID:   "+textEdit_shortID->toPlainText()+"\r\n");
                str+=("power:    "+textEdit_power->toPlainText()+"\r\n");
                str+=("channel:  "+textEdit_channel->toPlainText()+"\r\n");
                str+=("MAC:      "+strToHex(&app_frame.rf.data[6],8).toUpper());

                NET_DisplayWithTime(str);






            break;
            case r_recDevInf:            //返回设备详细信息
                DisplayWithTime(str+"/ 返回设备详细信息:");
                if(networkManuIdStatus->isChecked()==true)
                {
                    str0 = id_access.manuId(&app_frame.rf.data[0],iot_frame.gateway_id,iot_frame.device_id,app_frame.rf.data[8]*256+app_frame.rf.data[9]);
                    NET_DisplayWithTime("存储固定ID");
                    NET_DisplayWithTime(str0);
                }
                textBr_mess->append("MAC:         "+strToHex(&app_frame.rf.data[0],8).toUpper());
                textBr_mess->append("panID:       "+uint16ToHex(app_frame.rf.data[8]*256+app_frame.rf.data[9]).toUpper());
                //textBr_mess->append("nodeType:    "+uint8ToHex(app_frame.rf.data[10]).toUpper());
                str = "nodeType:    "+uint8ToHex(app_frame.rf.data[10]).toUpper();
                if(app_frame.rf.data[10] == 0)str+= "/ EMBER_UNKNOWN_DEVICE";
                else if(app_frame.rf.data[10] == 1)str+= "/ EMBER_STAR_COORDINATOR";
                else if(app_frame.rf.data[10] == 2)str+= "/ EMBER_STAR_RANGE_EXTENDER ";
                else if(app_frame.rf.data[10] == 3)str+= "/ EMBER_STAR_END_DEVICE";
                else if(app_frame.rf.data[10] == 4)str+= "/ EMBER_STAR_SLEEPY_END_DEVICE";
                else if(app_frame.rf.data[10] == 5)str+= "/ EMBER_DIRECT_DEVICE";
                else if(app_frame.rf.data[10] == 6)str+= "/ EMBER_MAC_MODE_DEVICE";
                textBr_mess->append(str);
                textBr_mess->append("Fir version: "+uint8ToHex(app_frame.rf.data[11]).toUpper());
                textBr_mess->append("MD5:         "+strToHex(&app_frame.rf.data[12],16).toUpper());
                if((comboBox_updateMode->currentText() == "OTA单独升级")||
                   (comboBox_updateMode->currentText() == "OTA批量升级"))
                {
                    rcmdSendFirInf(iot_frame.gateway_id,iot_frame.device_id);
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
                            //发送第0包数据，开始升级
                            rcmdSendsendPacket(iot_frame.gateway_id,iot_frame.device_id,0);
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

                        rcmdSendsendPacket(iot_frame.gateway_id,iot_frame.device_id,packet_num+1);
                    }
                }
                else
                {
                    str+=QString("请求重新发送数据包%1").arg(packet_num);
                    DisplayWithTime(str);
                    if((comboBox_updateMode->currentText() == "OTA单独升级")||
                       (comboBox_updateMode->currentText() == "OTA批量升级"))
                    {
                        rcmdSendsendPacket(iot_frame.gateway_id,iot_frame.device_id,packet_num);
                    }
                }

            break;
            case r_systemReset:             //返回固件数据包接收状态

                str+="/ 设备复位";
                NET_DisplayWithTime(str);
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

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    textBr_mess->append(str);
    str += "\r\n";
    history_par.Update_buff += QByteArray::fromStdString(str.toStdString());

}

void MainWindow::DisplayWithNoTime(const QString &text)
{
    textBr_mess->append( text);
    QString str;
    str = text +"\r\n";
    history_par.Update_buff += QByteArray::fromStdString(str.toStdString());
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
        textBr_mess->append(str.toUpper()+"\r\n");
        history_par.Update_buff += str;
    }
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
    //buff[26]=rf_send.rssi;//rssi
    buff[7]=buff.length()-8;
    buff.append(checkSum(buff,buff.length()));


    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(buff);
    }
    else if(comunication_protocal->currentText() == "Server")
    {
        //NET_getBindSocket(id->device_id);
        NET_send(buff);
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_send(buff);
    }
}


void  MainWindow::IOT_cmdHeartBeat(IOT_FRAME *ptr)
{
    QByteArray buff;
    buff.clear();
    buff[0]=(ptr->head>>8)&0xFF;
    buff[1]=ptr->head&0xFF;
    buff[2]=(ptr->gateway_id>>8)&0xFF;
    buff[3]=ptr->gateway_id&0xFF;
    buff[4]=(ptr->device_id>>8)&0xFF;
    buff[5]=ptr->device_id&0xFF;
    buff[6]=ptr->cmd;
    buff[7]=ptr->length;//length
    buff[8]=ptr->data[0];
    buff[9]=ptr->data[1];
    buff[10]=ptr->data[2];
    buff[11]=ptr->data[3];
    buff[12]=ptr->data[4];
    buff[13]=ptr->data[5];
    buff[14]=ptr->rssi;//rssi
    buff[15]=ptr->checkSum;


    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(buff);
    }
    else if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(ptr->device_id);
        NET_send(buff);
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_send(buff);
    }
}


void  MainWindow::IOT_cmdHeartBeat(ushort gateway_id,
                                   ushort device_id,
                                   ushort time,
                                   ushort bandwith,
                                   uchar rssi
                                   )
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
    buff[12]=(bandwith>>8)&0xFF;
    buff[13]=bandwith&0xFF;
    buff[14]=rssi;//rssi
    buff[7]=buff.length()-8;
    buff.append(checkSum(buff,buff.length()));


    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(buff);
    }
    else if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(buff);
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_send(buff);
    }
}




void MainWindow::IOT_cmdNetwork(ushort gateway_id,ushort device_id,QByteArray data)
{

    QByteArray send_buff;

    if(rf_send.sequence==255)rf_send.sequence=0;
    else rf_send.sequence++;


    if(shortAddr->currentRow()<0)
    {
        DisplayWithTime("please select addr ");
        return ;
    }


    //ID_SEND send = id_access.getIdSendInf(rf_send.device_id);

    send_buff.clear();
    send_buff = data;
    send_buff.insert(0,0x98);
    send_buff.insert(1,0x89);
    send_buff.insert(2,gateway_id/256);
    send_buff.insert(3,gateway_id%256);
    send_buff.insert(4,device_id/256);
    send_buff.insert(5,device_id%256);
    send_buff.insert(6,cmd_network);
    send_buff.insert(7,0xFF);
    send_buff.insert(8,rf_send.sequence);
    send_buff.insert(9,rf_send.device);
    //send_buff.append(rf_send.rssi);
    send_buff[7] = send_buff.length()-8;
    send_buff.append(checkSum(send_buff,send_buff.length()));



    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(send_buff);
    }
    else if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(send_buff);
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_send(send_buff);
    }
}


void MainWindow::IOT_cmdApp(ushort gateway_id,ushort device_id,QByteArray data)
{

    QByteArray send_buff;

    if(rf_send.sequence==255)rf_send.sequence=0;
    else rf_send.sequence++;


    if(shortAddr->currentRow()<0)
    {
        DisplayWithTime("please select addr ");
        return ;
    }


    //ID_SEND send = id_access.getIdSendInf(rf_send.device_id);

    send_buff.clear();
    send_buff = data;
    send_buff.insert(0,0x98);
    send_buff.insert(1,0x89);
    send_buff.insert(2,gateway_id/256);
    send_buff.insert(3,gateway_id%256);
    send_buff.insert(4,device_id/256);
    send_buff.insert(5,device_id%256);
    send_buff.insert(6,cmd_app);
    send_buff.insert(7,0xFF);
    //send_buff.append(rf_send.rssi);
    send_buff[7] = send_buff.length()-8;
    send_buff.append(checkSum(send_buff,send_buff.length()));



    if(comunication_protocal->currentText() == "Uart")
    {
        UART_send(send_buff);
    }
    else if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(send_buff);
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_send(send_buff);
    }
}

//*****************************************
//IOT end
//*****************************************





//*****************************************
//rcmd start
//*****************************************


void MainWindow::rcmdSetHeartbeatTime(ushort gateway_id,ushort device_id)
{

    QString str;
    ushort time;

    str = textEdit_heartbeat_time->toPlainText();
    time = str.toUShort();


    QByteArray buff;
    buff.clear();
    buff[0] = r_setHeartbeat;
    buff[1] = (time>>8)&0xFF;
    buff[2] = (time>>0)&0xFF;
    IOT_cmdNetwork(gateway_id,device_id,buff);
    LOC_DisplayWithTime(QString("set heartbeat time：%1 S").arg(time));
}



void MainWindow::rcmdSetNetPar(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    QString str;

    ushort panId;
    ushort shortId;
    uchar power;
    uchar channel;


    if(device_id!=0xFFFF)
    {
        str = textEdit_panID->toPlainText();
        if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
        {
            panId = str.toUShort(Q_NULLPTR,16);
        }
        else
        {
            panId = str.toUShort(Q_NULLPTR,10);
        }

        str = textEdit_shortID->toPlainText();
        if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
        {
            shortId = str.toUShort(Q_NULLPTR,16);
        }
        else
        {
            shortId = str.toUShort(Q_NULLPTR,10);
        }

        str = textEdit_power->toPlainText();
        if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
        {
            power = str.toUShort(Q_NULLPTR,16);
        }
        else
        {
            power = str.toUShort(Q_NULLPTR,10);
        }

        str = textEdit_channel->toPlainText();
        if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
        {
            channel = str.toUShort(Q_NULLPTR,16);
        }
        else
        {
            channel = str.toUShort(Q_NULLPTR,10);
        }



        buff.clear();
        buff[0] = r_getDevNetInf;
        buff[1] = panId/256;
        buff[2] = panId%256;
        buff[3] = shortId/256;
        buff[4] = shortId%256;
        buff[5] = power;
        buff[6] = channel;


        IOT_cmdNetwork(gateway_id,device_id,buff);
        str = "send rcmdSetNetPar cmd to device 0x"+uint16ToHex(device_id).toUpper();
    }
    else
    {
        str = "error: device id is 0xFFFF";
    }
    NET_DisplayWithTime(str);
}

void MainWindow::rcmdRequestNetPar(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    QString str;
    buff.clear();
    buff[0] = r_getDevNetInf;
    IOT_cmdNetwork(gateway_id,device_id,buff);
    str = "send rcmdRequestNetPar cmd to device 0x"+uint16ToHex(device_id).toUpper();
    NET_DisplayWithTime(str);
}

void MainWindow::rcmdSystemReset(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    QString str;
    buff.clear();
    buff[0] = r_systemReset;
    IOT_cmdNetwork(gateway_id,device_id,buff);
    str = "send rcmdSystemReset cmd to device 0x"+uint16ToHex(device_id).toUpper();
    NET_DisplayWithTime(str);
}

void MainWindow::rcmdGetDeviceInf(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = r_getDevInf;
    IOT_cmdNetwork(gateway_id,device_id,buff);
    DisplayWithTime("get device information");
}

void MainWindow::rcmdSendFirInf(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    unsigned short i = 0;
    if(fir.ota_w.buff.isEmpty() == true)
    {
        DisplayWithTime("please open the file xxx.bin");
        return;
    }
    buff.clear();
    buff[i++] = r_senFirInf;
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


    IOT_cmdNetwork(gateway_id,device_id,buff);

    DisplayWithTime("send firmware information");
}

void MainWindow::rcmdSendsendPacket(ushort gateway_id,ushort device_id,ushort packet)
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
    buff[i++] = r_senPacket;
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
    IOT_cmdNetwork(gateway_id,device_id,buff);
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
        ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
        rcmdGetDeviceInf(send.gateway_id,rf_send.device_id);
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
        ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
        rcmdSendFirInf(send.gateway_id,rf_send.device_id);
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
        ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
        rcmdSendsendPacket(send.gateway_id,rf_send.device_id,fir.ota_w.send_cout);
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
        ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
        rcmdGetDeviceInf(send.gateway_id,rf_send.device_id);
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


                //fir.ota_w.device_type = cb_deviceType->currentIndex();
                if(cb_deviceType->currentText() == "网关")fir.ota_w.device_type = 0x00;
                else if(cb_deviceType->currentText() == "成人腕带")fir.ota_w.device_type = 0x01;
                else if(cb_deviceType->currentText() == "精神病腕带")fir.ota_w.device_type = 0x02;
                else if(cb_deviceType->currentText() == "婴儿腕带")fir.ota_w.device_type = 0x03;
                else if(cb_deviceType->currentText() == "SOS按键(带定位)")fir.ota_w.device_type = 0x04;
                else if(cb_deviceType->currentText() == "插座")fir.ota_w.device_type = 0x05;
                else if(cb_deviceType->currentText() == "温度传感器")fir.ota_w.device_type = 0x06;
                else if(cb_deviceType->currentText() == "湿度传感器")fir.ota_w.device_type = 0x07;
                else if(cb_deviceType->currentText() == "多功能传感器")fir.ota_w.device_type = 0x08;
                else if(cb_deviceType->currentText() == "资产标签")fir.ota_w.device_type = 0x09;
                else if(cb_deviceType->currentText() == "四通道读头")fir.ota_w.device_type = 0x0A;
                else if(cb_deviceType->currentText() == "125k资产标签")fir.ota_w.device_type = 0x0B;
                else if(cb_deviceType->currentText() == "SOS按键(不带定位)")fir.ota_w.device_type = 0x0C;
                else if(cb_deviceType->currentText()  == "蓝牙透传863模块")fir.ota_w.device_type = 0x0D;
                else if(cb_deviceType->currentText()  == "手术室863模块")fir.ota_w.device_type = 0x0E;
                else if(cb_deviceType->currentText() == "蓝牙资产标签")fir.ota_w.device_type = 0xA0;
                else if(cb_deviceType->currentText() == "蓝牙定位天线")fir.ota_w.device_type = 0xB0;
                else if(cb_deviceType->currentText() == "中继器")fir.ota_w.device_type = 0xFC;
                else if(cb_deviceType->currentText() == "普通节点")fir.ota_w.device_type = 0xFD;
                else if(cb_deviceType->currentText() == "低功耗节点")fir.ota_w.device_type = 0xFE;
                else if(cb_deviceType->currentText() == "未知节点")fir.ota_w.device_type = 0xFF;

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
    if(comunication_protocal->currentText() == "Server")
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
    else if(comunication_protocal->currentText() == "Client")
    {

    }
    else if(comunication_protocal->currentText() == "Uart")
    {

    }

    DisplayWithTime(QString("Dest addr:")+str);


    total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));
}

void MainWindow::on_frimwareVersion_3_currentTextChanged(const QString &arg1)
{
    DisplayWithTime(arg1);
}

void MainWindow::on_cb_deviceType_currentTextChanged(const QString &arg1)
{
    DisplayWithTime(arg1);
    //fir.ota_w.device_type = cb_deviceType->currentIndex();
    if(cb_deviceType->currentText() == "网关")fir.ota_w.device_type = 0x00;
    else if(cb_deviceType->currentText() == "成人腕带")fir.ota_w.device_type = 0x01;
    else if(cb_deviceType->currentText() == "精神病腕带")fir.ota_w.device_type = 0x02;
    else if(cb_deviceType->currentText() == "婴儿腕带")fir.ota_w.device_type = 0x03;
    else if(cb_deviceType->currentText() == "SOS按键(带定位)")fir.ota_w.device_type = 0x04;
    else if(cb_deviceType->currentText() == "插座")fir.ota_w.device_type = 0x05;
    else if(cb_deviceType->currentText() == "温度传感器")fir.ota_w.device_type = 0x06;
    else if(cb_deviceType->currentText() == "湿度传感器")fir.ota_w.device_type = 0x07;
    else if(cb_deviceType->currentText() == "多功能传感器")fir.ota_w.device_type = 0x08;
    else if(cb_deviceType->currentText() == "资产标签")fir.ota_w.device_type = 0x09;
    else if(cb_deviceType->currentText() == "四通道读头")fir.ota_w.device_type = 0x0A;
    else if(cb_deviceType->currentText() == "125k资产标签")fir.ota_w.device_type = 0x0B;
    else if(cb_deviceType->currentText() == "SOS按键(不带定位)")fir.ota_w.device_type = 0x0C;
    else if(cb_deviceType->currentText()  == "蓝牙透传863模块")fir.ota_w.device_type = 0x0D;
    else if(cb_deviceType->currentText()  == "手术室863模块")fir.ota_w.device_type = 0x0E;
    else if(cb_deviceType->currentText() == "蓝牙资产标签")fir.ota_w.device_type = 0xA0;
    else if(cb_deviceType->currentText() == "蓝牙定位天线")fir.ota_w.device_type = 0xB0;
    else if(cb_deviceType->currentText() == "中继器")fir.ota_w.device_type = 0xFC;
    else if(cb_deviceType->currentText() == "普通节点")fir.ota_w.device_type = 0xFD;
    else if(cb_deviceType->currentText() == "低功耗节点")fir.ota_w.device_type = 0xFE;
    else if(cb_deviceType->currentText() == "未知节点")fir.ota_w.device_type = 0xFF;

}

void MainWindow::on_cb_deviceType_currentIndexChanged(int index)
{
    //rf_send.device = index;
    //fir.ota_w.device_type = index;
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
    ushort add_id;

    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        add_id = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        add_id = str.toUShort(Q_NULLPTR,10);
    }


    str = "0x"+ uint16ToHex(add_id).toUpper();

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
    total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));
}

void MainWindow::on_pb_deleteAddr_clicked()
{
//    ushort i = shortAddr->currentRow();
//    QString str = te_addrEdit->toPlainText();
//    DisplayWithTime("change addr:" +shortAddr->item(i)->text()+" to "+str);
//    shortAddr->item(i)->setText(str);
    shortAddr->clear();
    total_id_display->setText(QString("select:%1 total:%2").arg(shortAddr->currentRow()).arg(shortAddr->count()));

}





/**********************network start*****************************************/
/**********************network start*****************************************/

void MainWindow::NET_Init()

{
    ulong i;
    QString str = NET_get_localmachine_ip();
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
    comunication_protocal->setCurrentText("Servezr");

    net_par.clientSocket = new QTcpSocket(this);

//    uchar aa = 0xFF;
//    ushort bb = 0xFFFF;
//    short cc = 0xFFFF;
//    NET_DisplayWithNoTime(QString("%1  %2  %3").arg(aa,0,10).arg(bb,0,10).arg(cc,0,10));
    networkAutoIdStatus->setChecked(false);
    networkManuIdStatus->setChecked(true);
}



QString MainWindow::NET_get_localmachine_ip()
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

void MainWindow::NET_revData()

{

   ushort i,j;
   QByteArray display;
   QByteArray datas;

   if(comunication_protocal->currentText() == "Server")
   {
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




           for(i = 0; i < datas.length();i++)
           {
               transport.receive[transport.r_count] = datas[i];
               transport.r_count++;
           }
           //receiveTimer->start(20);
           pressUartData();

       }
   }
   else if(comunication_protocal->currentText() == "Client")
   {
       datas.clear();
       datas = net_par.clientSocket->readAll();
       if(datas.length() == 0)return;

       //接收字符串数据。
       display = datas.toHex().toUpper();
       for(i=0;i<display.length();i+=3)
       {
            display.insert( i+2, " ");
       }
       infReceive->setPlainText(display);




       for(i = 0; i < datas.length();i++)
       {
           transport.receive[transport.r_count] = datas[i];
           transport.r_count++;
       }
       //receiveTimer->start(20);
       pressUartData();

   }
}

void MainWindow::NET_send(QByteArray src)
{

    if(comunication_protocal->currentText() == "Server")
    {
        if(net_par.Server ==NULL)
        {
            infDisplay->append("no server operation");
            return ;
        }

        if(net_par.currentSocket ==NULL )
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
            net_par.currentSocket->write(src);
            NET_DisplayWithTime("send message to IP:"+net_par.currentSocket->peerAddress().toString());
        }

    }
    else if(comunication_protocal->currentText() == "Client")
    {
        if(net_par.clientSocket->isValid())
        {
            net_par.clientSocket->write(src);
            NET_DisplayWithTime("send message to IP:"+net_par.clientSocket->peerAddress().toString());
        }
    }
    else
    {
        return;
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
        textBr_mess->append(str.toUpper()+"\r\n");
        history_par.Update_buff += str;

    }
}


void MainWindow::on_bt_netSend_clicked()
{
    NET_getBindSocket(rf_send.device_id);
    NET_send(infEdit->toPlainText().toLatin1());

}


void MainWindow::NET_newListen()
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

void MainWindow::NET_clientToServer()
{
    ushort port;
    QString str = textEdit_Port->toPlainText();
    port = str.toUShort();
    net_par.clientSocket->abort();
    net_par.clientSocket->connectToHost(textEdit_IP->toPlainText(),port);
    connect(net_par.clientSocket,SIGNAL(readyRead()),this,SLOT(NET_revData()));
    //connect(net_par.clientSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(NET_displayError(QAbstractSocket::SocketError)));
}



void MainWindow::NET_acceptConnection()
{
    ushort i;
    QString str;

    for(i=0;i<SOCKET_MAX;i++)
    {
        if(net_par.Socket[i] == NULL)
        {
            net_par.Socket[i] = new QTcpSocket(this);
            //net_par.currentSocket = net_par.Socket[i];
            //当tcpSocket在接受客户端连接时出现错误时，NET_displayError(QAbstractSocket::SocketError)进行错误提醒并关闭tcpSocket。
            connect(net_par.Socket[i],SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(NET_displayError(QAbstractSocket::SocketError)));

            //当有客户来访时将tcpSocket接受tcpServer建立的socket
            net_par.Socket[i] = net_par.Server->nextPendingConnection();
            connect(net_par.Socket[i],SIGNAL(readyRead()),this,SLOT(NET_revData()));
            str = "new client connection";
            str +=" / peerName:"+net_par.Socket[i]->peerName();
            str +=" / peerAddress:"+net_par.Socket[i]->peerAddress().toString();
            str +=QString(" / peerPort:%1").arg(net_par.Socket[i]->peerPort());
            NET_DisplayWithTime(str);


            break;
        }
    }
}



void MainWindow::NET_displayError(QAbstractSocket::SocketError)
{
    ushort i;
    qDebug()<<net_par.Socket[0]->errorString();
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

    if(comunication_protocal->currentText() == "Server")
    {
        net_par.Server = new QTcpServer(this);

        NET_newListen();
        //newConnection()用于当有客户端访问时发出信号，NET_acceptConnection()信号处理函数
        connect(net_par.Server,SIGNAL(newConnection()),this,SLOT(NET_acceptConnection()));
    }
    else if(comunication_protocal->currentText() == "Client")
    {
        NET_clientToServer();
    }
    else
    {

    }
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
    if(net_par.Server != NULL)net_par.Server->close();
    net_par.clientSocket->abort();

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
    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    infDisplay->append(str);
    str += "\r\n";
    history_par.Network_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::NET_DisplayWithNoTime(const QString &text)
{
    infDisplay->append( text);
    QString str;
    str += "\r\n";
    history_par.Network_buff += QByteArray::fromStdString(str.toStdString());
}


void MainWindow::NET_setBindSocket(ushort id)
{
     if(comunication_protocal->currentText() == "Server")
     net_par.bind_socket[id] = net_par.currentSocket;
}

void MainWindow::NET_getBindSocket(ushort id)
{
    if(comunication_protocal->currentText() == "Server")
    {
        if(id = 0xFFFF)
        {
            net_par.currentSocket = NULL;
        }
        else
        {
            net_par.currentSocket = net_par.bind_socket[id];
        }
    }
    else
    {
        net_par.currentSocket = NULL;
    }
}


void MainWindow::on_networkResetIdTable_clicked()
{

    NET_DisplayWithTime(id_access.resetAllId());
}


void MainWindow::on_bt_clearId_clicked()
{
    QString str;
    ushort id;

    str = textEdit_ID->toPlainText();
    id = str.toUShort();
    str = id_access.clearId(id);

    NET_DisplayWithTime(str);
}

void MainWindow::on_export_idList_2_clicked()
{

}

void MainWindow::on_export_idList_3_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    rcmdSystemReset(send.gateway_id,rf_send.device_id);
}

void MainWindow::on_pushButton_requestNetPar_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    rcmdRequestNetPar(send.gateway_id,rf_send.device_id);
}

void MainWindow::on_pushButton_setNetPar_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    rcmdSetNetPar(send.gateway_id,rf_send.device_id);
}





/*******************Client start******************/



/*******************Client end******************/


/*******************network end******************/
/*******************network end******************/
/*******************network end******************/
/*******************network end******************/


/****************location start****************/


void MainWindow::LOC_init()
{
    loc_par.filtStr.clear();
    localtionFiltId->setPlainText("");
    localtionFiltId_1->setPlainText("");
    localtionFiltId_2->setPlainText("");
    localtionFiltId_3->setPlainText("");
    localtionFiltId_4->setPlainText("");
}


void MainWindow::LOC_DisplayWithTime(const QString &text)
{
    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    location_display->append(str);
    str += "\r\n";
    history_par.location_buff += QByteArray::fromStdString(str.toStdString());

}

void MainWindow::LOC_DisplayWithNoTime(const QString &text)
{
    location_display->append( text);
    QString str;
    str = text + "\r\n";
    history_par.location_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::on_localtionFiltId_textChanged()
{
    QString str = localtionFiltId->toPlainText();
    if(str.length() == 0)
    {
        loc_par.filtId[0] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        loc_par.filtId[0] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        loc_par.filtId[0] = str.toUShort(Q_NULLPTR,10);
    }
    LOC_DisplayWithTime("filt id_0:0x"+uint16ToHex(loc_par.filtId[0]).toUpper());
}

void MainWindow::on_localtionFiltId_1_textChanged()
{
    QString str = localtionFiltId_1->toPlainText();
    if(str.length() == 0)
    {
        loc_par.filtId[1] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        loc_par.filtId[1] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        loc_par.filtId[1] = str.toUShort(Q_NULLPTR,10);
    }
    LOC_DisplayWithTime("filt id_1:0x"+uint16ToHex(loc_par.filtId[1]).toUpper());
}

void MainWindow::on_localtionFiltId_2_textChanged()
{
    QString str = localtionFiltId_2->toPlainText();
    if(str.length() == 0)
    {
        loc_par.filtId[2] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        loc_par.filtId[2] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        loc_par.filtId[2] = str.toUShort(Q_NULLPTR,10);
    }
    LOC_DisplayWithTime("filt id_2:0x"+uint16ToHex(loc_par.filtId[2]).toUpper());
}

void MainWindow::on_localtionFiltId_3_textChanged()
{
    QString str = localtionFiltId_3->toPlainText();
    if(str.length() == 0)
    {
        loc_par.filtId[3] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        loc_par.filtId[3] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        loc_par.filtId[3] = str.toUShort(Q_NULLPTR,10);
    }
    LOC_DisplayWithTime("filt id_3:0x"+uint16ToHex(loc_par.filtId[3]).toUpper());
}

void MainWindow::on_localtionFiltId_4_textChanged()
{
    QString str = localtionFiltId_4->toPlainText();
    if(str.length() == 0)
    {
        loc_par.filtId[4] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        loc_par.filtId[4] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        loc_par.filtId[4] = str.toUShort(Q_NULLPTR,10);
    }
    LOC_DisplayWithTime("filt id_4:0x"+uint16ToHex(loc_par.filtId[4]).toUpper());
}
void MainWindow::on_localtionFiltStr_textChanged()
{
    loc_par.filtStr = QByteArray::fromStdString(localtionFiltStr->toPlainText().toStdString());
    LOC_DisplayWithTime("filt string:"+loc_par.filtStr);
}


void MainWindow::on_locationStopDisplay_clicked(bool checked)
{

}

void MainWindow::on_localtionFiltId_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_localtionFiltStr_windowIconTextChanged(const QString &iconText)
{

}



void MainWindow::on_localtionIdSelection_windowIconTextChanged(const QString &iconText)
{

}

void MainWindow::on_localtionIdSelection_4_windowIconTextChanged(const QString &iconText)
{

}




void MainWindow::on_bt_setHeartBeatTime_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    rcmdSetHeartbeatTime(send.gateway_id,rf_send.device_id);
}


void MainWindow::on_bt_setHeartBeatTime_3_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    LOC_Set125KRssi(send.gateway_id,rf_send.device_id);
}


void MainWindow::LOC_Set125KRssi(ushort gateway_id,ushort device_id)
{

    QString str;
    ushort ant125kId;
    uchar ant125kRssi;

    str = location125KIDtextEdit->toPlainText();
    ant125kId = str.toUShort();
    str = location125KRssitextEdit->toPlainText();
    ant125kRssi = str.toUShort();

    if(ant125kRssi>0x3F){
        LOC_DisplayWithTime("error: ant 125K RSSI 0x00~0x3F");
    }
    else{
        QByteArray buff;
        buff.clear();
        buff[0] = 0xA5;
        buff[1] = 0x5A;
        buff[2] = (ant125kId>>8)&0xFF;
        buff[3] = (ant125kId>>0)&0xFF;
        buff[4] = ant125kRssi;
        buff.append(checkSum(buff,buff.length()));

        IOT_cmdApp(gateway_id,device_id,buff);
        str = "ANT 125K ID = 0x"+uint16ToHex(ant125kId).toUpper();
        str += "  /RSSI = 0x"+uint8ToHex(ant125kRssi).toUpper();
        LOC_DisplayWithTime(str);
    }
}


/***********************location end****************/



/****************cool start****************/


void MainWindow::COO_init()
{
    coo_par.filtStr.clear();
    coolFiltId->setPlainText("0xFFFF");
}


void MainWindow::COO_DisplayWithTime(const QString &text)
{

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    cool_display->append(str);
    str += "\r\n";
    history_par.cool_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::COO_DisplayWithNoTime(const QString &text)
{
    cool_display->append( text);
    QString str;
    str = text + "\r\n";
    history_par.cool_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::on_coolFiltId_textChanged()
{
    QString str = coolFiltId->toPlainText();
    if(str.length() == 0)
    {
        coo_par.filtId = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        coo_par.filtId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        coo_par.filtId = str.toUShort(Q_NULLPTR,10);
    }
    COO_DisplayWithTime("filt id:0x"+uint16ToHex(coo_par.filtId).toUpper());
}

void MainWindow::on_coolFiltStr_textChanged()
{
    coo_par.filtStr = QByteArray::fromStdString(coolFiltStr->toPlainText().toStdString());
    COO_DisplayWithTime(QString("filt string:")+coo_par.filtStr);
}



void MainWindow::on_coolGetSn_clicked()
{

    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_getSnNumber(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("获取冷链显示编号");
}



void MainWindow::on_coolSetRepTime_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_setReportTime(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("设置采样时间");
}

void MainWindow::on_coolSetSn_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_setSnNumber(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("设置冷链显示编号");
}

void MainWindow::on_coolTemVerification_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_tempretureVerfication(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("温度校准");
}

void MainWindow::on_coolHumVerification_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_HumVerfication(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("湿度校准");
}

void MainWindow::on_coolDisarm_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_clearTemAlarm(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("解除报警");
}

void MainWindow::on_coolGetTempreture_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_getSensorValue(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("获取温湿度");
}

void MainWindow::on_coolTemAlarm_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    COO_tempretureAlarmHL(send.gateway_id , rf_send.device_id);
    COO_DisplayWithTime("设置报警参数");
}

void MainWindow::on_coolTemAlarmH_Edit_destroyed()
{

}

void MainWindow::COO_getSnNumber(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdGetDisNum;
    buff[7] = 00;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::COO_setSnNumber(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort display_id;
    display_id = coolSetSn_Edit->toPlainText().toUShort(Q_NULLPTR,10);



    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdSetDisNum;
    buff[7] = display_id/256;
    buff[8] = display_id%256;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::COO_getSensorValue(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdGetSenVal;
    buff[7] = 00;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::COO_clearTemAlarm(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdDisarm;
    buff[7] = 00;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}



void MainWindow::COO_tempretureVerfication(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    short num;
    QString str = coolTemVerification_Edit->toPlainText();


    num = str.toShort();





    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdTemVer;
    if(num<0)
    {
        buff[7] = 1;
        buff[8] = -num;
    }
    else
    {
        buff[7] = 0;
        buff[8] = num;
    }

    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::COO_HumVerfication(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    short num;
    QString str = coolHumVerification_Edit->toPlainText();


    num = str.toShort();





    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdHumVer;
    if(num<0)
    {
        buff[7] = 1;
        buff[8] = -num;
    }
    else
    {
        buff[7] = 0;
        buff[8] = num;
    }

    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::COO_tempretureAlarmHL(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    float tem_h,tem_l;
    long tem;
    QString str;
    str = coolTemAlarmH_Edit->toPlainText();
    tem_h = str.toFloat();
    str = coolTemAlarmL_Edit->toPlainText();
    tem_l = str.toFloat();





    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdSetAlaVal;
    if(tem_h<0)
    {
        tem = (-tem_h)*100;
        buff[7] = 1;
        buff[8] = (tem/100)>>8;
        buff[9] = (tem/100)>>0;
        buff[10] =(tem%100)>>0;
    }
    else
    {
        tem = tem_h*100;
        buff[7] = 0;
        buff[8] = (tem/100)>>8;
        buff[9] = (tem/100)>>0;
        buff[10] =(tem%100)>>0;
    }
    if(tem_l<0)
    {
        tem = -tem_l;
        buff[11] = 1;
        buff[12] = (tem/100)>>8;
        buff[13] = (tem/100)>>0;
        buff[14] = (tem%100)>>0;
    }
    else
    {
        tem = (-tem_h)*100;
        buff[11] = 0;
        buff[12] = (tem/100)>>8;
        buff[13] = (tem/100)>>0;
        buff[14] = (tem%100)>>0;
    }
    buff[5] = buff.length()-6;
    buff[15] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::COO_setReportTime(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uint time;
    time = coolSetRepTime_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x05;//len
    buff[6] = coolCmdSetRepTime;
    buff[7] = 0xFF&(time>>24);
    buff[8] = 0xFF&(time>>16);
    buff[9] = 0xFF&(time>>8);
    buff[10] = 0xFF&(time>>0);
    buff[11] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::COO_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    COO_DisplayWithTime("server ack success");
}

void MainWindow::COO_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevTempreture;
    buff[5] = 0x03;//len
    buff[6] = coolCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    COO_DisplayWithTime("server ack error");
}






/***********************cool end****************/


/****************eneryg start****************/


void MainWindow::ENE_init()
{
    ene_par.filtStr.clear();
    energyFiltId->setPlainText("0xFFFF");

}


void MainWindow::ENE_DisplayWithTime(const QString &text)
{

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    energy_display->append(str);
    str += "\r\n";
    history_par.energy_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::ENE_DisplayWithNoTime(const QString &text)
{
    energy_display->append( text);
    QString str;
    str = text+ "\r\n";
    history_par.energy_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::on_energyFiltId_textChanged()
{
    QString str = energyFiltId->toPlainText();
    if(str.length() == 0)
    {
        ene_par.filtId = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ene_par.filtId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ene_par.filtId = str.toUShort(Q_NULLPTR,10);
    }
    ENE_DisplayWithTime("filt id:0x"+uint16ToHex(ene_par.filtId).toUpper());
}

void MainWindow::on_energyFiltStr_textChanged()
{
    ene_par.filtStr = QByteArray::fromStdString(energyFiltStr->toPlainText().toStdString());
    ENE_DisplayWithTime(QString("filt string:")+ene_par.filtStr);
}

void MainWindow::on_energyGetMeasurement_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    ENE_getMeasurementValue(send.gateway_id , rf_send.device_id);
    ENE_DisplayWithTime("获取电量参数");
}

void MainWindow::on_energySetRepTime_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    ENE_setReportTime(send.gateway_id , rf_send.device_id);
    ENE_DisplayWithTime("设置上传时间");
}




void MainWindow::ENE_getMeasurementValue(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevEnergy;
    buff[5] = 0x03;//len
    buff[6] = energyCmdGetMeasurement;
    buff[7] = 00;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}



void MainWindow::ENE_setReportTime(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uint time;
    time = energySetRepTime_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevEnergy;
    buff[5] = 0x05;//len
    buff[6] = energyCmdSetRepTime;
    buff[7] = 0xFF&(time>>24);
    buff[8] = 0xFF&(time>>16);
    buff[9] = 0xFF&(time>>8);
    buff[10] = 0xFF&(time>>0);
    buff[11] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::ENE_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevEnergy;
    buff[5] = 0x03;//len
    buff[6] = energyCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    COO_DisplayWithTime("server ack success");
}

void MainWindow::ENE_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevEnergy;
    buff[5] = 0x03;//len
    buff[6] = energyCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    COO_DisplayWithTime("server ack error");
}





/***********************eneryg end****************/


void MainWindow::on_bt_clear_clicked()
{
    textBr_inp->clear();
    textBr_mess->clear();
    infDisplay->clear();
    infEdit->clear();
    infReceive->clear();
    location_display->clear();
    cool_display->clear();
    energy_display->clear();
    injection_display->clear();
    sos_display->clear();
    BLE_display->clear();
}

void MainWindow::on_comunication_protocal_currentTextChanged(const QString &arg1)
{
    transport.r_count = 0;
    transport.s_count = 0;
    if(arg1=="Server")
    {
        bt_listen->setText("监听");
        bt_stopListen->setText("停止监听");
    }
    else if(arg1=="Client")
    {
        bt_listen->setText("连接");
        bt_stopListen->setText("断开连接");
    }
    else if(arg1=="Uart")
    {

    }
    else
    {

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















/**********store history file**************/
void MainWindow::on_StoreDir_clicked()
{
    history_par.timer->start(60000);
    history_par.time_count = 0;

    QDateTime datTime = QDateTime::currentDateTime();
    //QByteArray buff;
    QString str;
    str = "/"+datTime.toString("yyyy-MM-dd_hh-mm-ss")+".txt";



    history_par.Network_file = new QFile(history_par.Network_path+str);
    history_par.Network_file->open(QIODevice::ReadWrite);
    history_par.Network_file->write(history_par.Network_buff);
    history_par.Network_file->close();
    history_par.Network_buff.clear();



    history_par.Uart_file = new QFile(history_par.Uart_path+str);
    history_par.Uart_file->open(QIODevice::ReadWrite);
    history_par.Uart_file->write(history_par.Uart_buff);
    history_par.Uart_file->close();
    history_par.Uart_buff.clear();


    history_par.Update_file = new QFile(history_par.Update_path+str);
    history_par.Update_file->open(QIODevice::ReadWrite);
    history_par.Update_file->write(history_par.Update_buff);
    history_par.Update_file->close();
    history_par.Update_buff.clear();


    history_par.location_file = new QFile(history_par.location_path+str);
    history_par.location_file->open(QIODevice::ReadWrite);
    history_par.location_file->write(history_par.location_buff);
    history_par.location_file->close();
    history_par.location_buff.clear();

    history_par.cool_file = new QFile(history_par.cool_path+str);
    history_par.cool_file->open(QIODevice::ReadWrite);
    history_par.cool_file->write(history_par.cool_buff);
    history_par.cool_file->close();
    history_par.cool_buff.clear();

    history_par.energy_file = new QFile(history_par.energy_path+str);
    history_par.energy_file->open(QIODevice::ReadWrite);
    history_par.energy_file->write(history_par.energy_buff);
    history_par.energy_file->close();
    history_par.energy_buff.clear();

    history_par.injection_file = new QFile(history_par.injection_path+str);
    history_par.injection_file->open(QIODevice::ReadWrite);
    history_par.injection_file->write(history_par.injection_buff);
    history_par.injection_file->close();
    history_par.injection_buff.clear();

    history_par.custom_file = new QFile(history_par.custom_path+str);
    history_par.custom_file->open(QIODevice::ReadWrite);
    history_par.custom_file->write(history_par.custom_buff);
    history_par.custom_file->close();
    history_par.custom_buff.clear();

    history_par.ble_file = new QFile(history_par.ble_path+str);
    history_par.ble_file->open(QIODevice::ReadWrite);
    history_par.ble_file->write(history_par.ble_buff);
    history_par.ble_file->close();
    history_par.ble_buff.clear();



    textBr_inp->clear();
    textBr_mess->clear();
    infDisplay->clear();
    infEdit->clear();
    infReceive->clear();
    location_display->clear();
    cool_display->clear();
    energy_display->clear();
    BLE_display->clear();
}

void MainWindow::storeHistoryLog()
{
    history_par.timer->start(60000);
    history_par.time_count++;
    if(history_par.time_count>10)
    {
        QDateTime datTime = QDateTime::currentDateTime();
        //QByteArray buff;
        QString str;
        str = "/"+datTime.toString("yyyy-MM-dd_hh-mm-ss")+".txt";



        history_par.Network_file = new QFile(history_par.Network_path+str);
        history_par.Network_file->open(QIODevice::ReadWrite);
        history_par.Network_file->write(history_par.Network_buff);
        history_par.Network_file->close();
        history_par.Network_buff.clear();



//        history_par.Uart_file = new QFile(history_par.Uart_path+str);
//        history_par.Uart_file->open(QIODevice::ReadWrite);
//        history_par.Uart_file->write(history_par.Uart_buff);
//        history_par.Uart_file->close();
//        history_par.Uart_buff.clear();


        history_par.Update_file = new QFile(history_par.Update_path+str);
        history_par.Update_file->open(QIODevice::ReadWrite);
        history_par.Update_file->write(history_par.Update_buff);
        history_par.Update_file->close();
        history_par.Update_buff.clear();


        history_par.location_file = new QFile(history_par.location_path+str);
        history_par.location_file->open(QIODevice::ReadWrite);
        history_par.location_file->write(history_par.location_buff);
        history_par.location_file->close();
        history_par.location_buff.clear();

        history_par.cool_file = new QFile(history_par.cool_path+str);
        history_par.cool_file->open(QIODevice::ReadWrite);
        history_par.cool_file->write(history_par.cool_buff);
        history_par.cool_file->close();
        history_par.cool_buff.clear();

        history_par.energy_file = new QFile(history_par.energy_path+str);
        history_par.energy_file->open(QIODevice::ReadWrite);
        history_par.energy_file->write(history_par.energy_buff);
        history_par.energy_file->close();
        history_par.energy_buff.clear();

//        history_par.injection_file = new QFile(history_par.injection_path+str);
//        history_par.injection_file->open(QIODevice::ReadWrite);
//        history_par.injection_file->write(history_par.injection_buff);
//        history_par.injection_file->close();
//        history_par.injection_buff.clear();

//        history_par.custom_file = new QFile(history_par.custom_path+str);
//        history_par.custom_file->open(QIODevice::ReadWrite);
//        history_par.custom_file->write(history_par.custom_buff);
//        history_par.custom_file->close();
//        history_par.custom_buff.clear();


        history_par.ble_file = new QFile(history_par.ble_path+str);
        history_par.ble_file->open(QIODevice::ReadWrite);
        history_par.ble_file->write(history_par.ble_buff);
        history_par.ble_file->close();
        history_par.ble_buff.clear();


        textBr_inp->clear();
        textBr_mess->clear();
        infDisplay->clear();
        infEdit->clear();
        infReceive->clear();
        location_display->clear();
        cool_display->clear();
        energy_display->clear();
        BLE_display->clear();

        history_par.time_count = 0;

    }

}

/**********store history file**************/

void MainWindow::on_shortAddr_currentRowChanged(int currentRow)
{

}

void MainWindow::on_shortAddr_itemChanged(QListWidgetItem *item)
{

}

void MainWindow::on_shortAddr_activated(const QModelIndex &index)
{

}

void MainWindow::on_shortAddr_itemActivated(QListWidgetItem *item)
{

}





/****************injection start****************/


void MainWindow::INJ_init()
{
    inj_par.filtStr.clear();
    injectionFiltId->setPlainText("0xFFFF");
}


void MainWindow::INJ_DisplayWithTime(const QString &text)
{

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    injection_display->append(str);
    str += "\r\n";
    history_par.injection_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::INJ_DisplayWithNoTime(const QString &text)
{
    injection_display->append( text);
    QString str;
    str = text + "\r\n";
    history_par.injection_buff += QByteArray::fromStdString(str.toStdString());
}


void MainWindow::on_injectionFiltId_textChanged()
{
    QString str = injectionFiltId->toPlainText();
    if(str.length() == 0)
    {
        inj_par.filtId = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        inj_par.filtId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        inj_par.filtId = str.toUShort(Q_NULLPTR,10);
    }
    INJ_DisplayWithTime("filt id:0x"+uint16ToHex(inj_par.filtId).toUpper());
}

void MainWindow::on_injectionFiltStr_textChanged()
{
    inj_par.filtStr = QByteArray::fromStdString(injectionFiltStr->toPlainText().toStdString());
    INJ_DisplayWithTime(QString("filt string:")+inj_par.filtStr);
}


void MainWindow::on_injectionTemAlarm_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_tempretureAlarmHL(send.gateway_id , rf_send.device_id);
    INJ_DisplayWithTime("设置滴速");
}

void MainWindow::on_injectionSetSn_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_setSnNumber(send.gateway_id , rf_send.device_id);
    INJ_DisplayWithTime("设置显示编号");
}

void MainWindow::on_injectionSetRepTime_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_setReportTime(send.gateway_id , rf_send.device_id);
    INJ_DisplayWithTime("设置回传时间");
}

void MainWindow::on_injectionSetSpeaker_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionSetSpeaker_Bt->text());
    INJ_setSpeaker(send.gateway_id , rf_send.device_id);

}

void MainWindow::on_injectionGetSn_clicked()
{

}



void MainWindow::on_injectionStart_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionStart_Bt->text());
    INJ_startInjection(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionStop_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionStop_Bt->text());
    INJ_stopInjection(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionFinish_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionFinish_Bt->text());
    INJ_finishInjection(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionSetTotalDi_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionSetTotalDi_Bt->text());
    INJ_setTotalDi(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionSetStopTimeOut_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionSetStopTimeOut_Bt->text());
    INJ_setStopTimeout(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionGetDeviceParameters_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionGetDeviceParameters_Bt->text());
    INJ_getDeviceParameters(send.gateway_id , rf_send.device_id);
}


void MainWindow::on_injectionDiInit_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionDiInit_Bt->text());
    INJ_DiInit(send.gateway_id , rf_send.device_id);
}




void MainWindow::on_injectionSetDi_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionSetDi_Bt->text());
    INJ_SetDi(send.gateway_id , rf_send.device_id);
}

void MainWindow::on_injectionSetName_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    INJ_DisplayWithTime(injectionSetName_Bt->text());
    INJ_SetName(send.gateway_id , rf_send.device_id);
}


void MainWindow::INJ_setSnNumber(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort display_id;
    display_id = injectionSetSn_Edit->toPlainText().toUShort(Q_NULLPTR,10);



    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetDisNum;
    buff[7] = display_id/256;
    buff[8] = display_id%256;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}



void MainWindow::INJ_setSpeaker(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x02;//len
    buff[6] = injectionCmdSetSpeaker;

    if(injectionSetSpeaker_Bt->text()=="打开喇叭")
    {
        buff[7] = 0x01;
        injectionSetSpeaker_Bt->setText("关闭喇叭");
    }
    else
    {
        buff[7] = 0x00;
        injectionSetSpeaker_Bt->setText("打开喇叭");
    }

    buff[8] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}




void MainWindow::INJ_tempretureAlarmHL(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uchar tem_h,tem_m,tem_l;
    QString str;
    str = injectionTemAlarmH_Edit->toPlainText();
    tem_h = str.toUShort()%256;
    str = injectionTemAlarmM_Edit->toPlainText();
    tem_m = str.toUShort()%256;
    str = injectionTemAlarmL_Edit->toPlainText();
    tem_l = str.toUShort()%256;


    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x04;//len
    buff[6] = injectionCmdSetSpeed;
    buff[7] = tem_m;
    buff[8] = tem_l;
    buff[9] = tem_h;
    buff[10] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::INJ_setReportTime(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uint time;
    time = injectionSetRepTime_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x05;//len
    buff[6] = injectionCmdSetRepTime;
    buff[7] = 0xFF&(time>>24);
    buff[8] = 0xFF&(time>>16);
    buff[9] = 0xFF&(time>>8);
    buff[10] = 0xFF&(time>>0);
    buff[11] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::INJ_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    INJ_DisplayWithTime("server ack success");
}

void MainWindow::INJ_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    INJ_DisplayWithTime("server ack error");
}


void MainWindow::INJ_startInjection(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x02;//len
    buff[6] = injectionCmdDevStart;
    buff[7] = 0x01;
    buff[8] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}
void MainWindow::INJ_stopInjection(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x02;//len
    buff[6] = injectionCmdDevStop;
    buff[7] = 0x01;
    buff[8] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}
void MainWindow::INJ_finishInjection(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x02;//len
    buff[6] = injectionCmdDevFinish;
    buff[7] = 0x01;
    buff[8] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}
void MainWindow::INJ_setTotalDi(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort dididi;
    dididi = injectionSetTotalDi_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetTotalDi;
    buff[7] = 0xFF&(dididi>>8);
    buff[8] = 0xFF&(dididi>>0);
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}
void MainWindow::INJ_setStopTimeout(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort time;
    time = injectionSetStopTimeOut_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetStopTimeout;

    buff[7] = 0xFF&(time>>8);
    buff[8] = 0xFF&(time>>0);
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}
void MainWindow::INJ_getDeviceParameters(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uchar parameters_list;
    QString str;
    str = injectionDeviceParameters_list->currentText();
    str.remove(2,str.length());
    parameters_list = str.toUInt(Q_NULLPTR,10);
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x02;//len
    buff[6] = injectionCmdGetDeviceParameter;
    buff[7] = 0xFF&parameters_list;
    buff[8] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::INJ_DiInit(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort dididi;
    dididi = injectionDiInit_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdDiInit;

    buff[7] = 0xFF&(dididi>>8);
    buff[8] = 0xFF&(dididi>>0);
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::INJ_SetDi(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort dididi;
    dididi = injectionSetDi_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetDi;

    buff[7] = 0xFF&(dididi>>8);
    buff[8] = 0xFF&(dididi>>0);
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::INJ_SetName(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    ushort dididi;
    dididi = injectionSetName_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetName;

    buff[7] = 0xFF&(dididi>>8);
    buff[8] = 0xFF&(dididi>>0);
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

/***********************injection end****************/

/****************sos start****************/


void MainWindow::SOS_init()
{
    sos_par.filtStr.clear();
    sosFiltId->setPlainText("0xFFFF");

}


void MainWindow::SOS_DisplayWithTime(const QString &text)
{

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    sos_display->append(str);
    str += "\r\n";
    history_par.sos_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::SOS_DisplayWithNoTime(const QString &text)
{
    sos_display->append( text);
    QString str;
    str = text+ "\r\n";
    history_par.sos_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::on_sosFiltId_textChanged()
{
    QString str = sosFiltId->toPlainText();
    if(str.length() == 0)
    {
        sos_par.filtId = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        sos_par.filtId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        sos_par.filtId = str.toUShort(Q_NULLPTR,10);
    }
    SOS_DisplayWithTime("filt id:0x"+uint16ToHex(sos_par.filtId).toUpper());
}

void MainWindow::on_sosFiltStr_textChanged()
{
    sos_par.filtStr = QByteArray::fromStdString(sosFiltStr->toPlainText().toStdString());
    SOS_DisplayWithTime(QString("filt string:")+sos_par.filtStr);
}


void MainWindow::on_sosSetRepTime_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    SOS_setReportTime(send.gateway_id , rf_send.device_id);
    SOS_DisplayWithTime("设置上传时间");
}





void MainWindow::SOS_setReportTime(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    uint time;
    time = sosSetRepTime_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevSosNoLocationPanic;
    buff[5] = 0x05;//len
    buff[6] = sosCmdSetRepTime;
    buff[7] = 0xFF&(time>>24);
    buff[8] = 0xFF&(time>>16);
    buff[9] = 0xFF&(time>>8);
    buff[10] = 0xFF&(time>>0);
    buff[11] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::SOS_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevSosNoLocationPanic;
    buff[5] = 0x03;//len
    buff[6] = sosCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    SOS_DisplayWithTime("server ack success");
}

void MainWindow::SOS_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevSosNoLocationPanic;
    buff[5] = 0x03;//len
    buff[6] = sosCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    SOS_DisplayWithTime("server ack error");
}





/***********************sos end****************/

/***********************BLE start****************/








void MainWindow::BLE_init()
{
    ble_par.filtStr.clear();
    BLE_FiltId->setPlainText("");
    BLE_FiltId_1->setPlainText("");
    BLE_FiltId_2->setPlainText("");
    BLE_FiltId_3->setPlainText("");
    BLE_FiltId_4->setPlainText("");
}


void MainWindow::BLE_DisplayWithTime(const QString &text)
{
    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    BLE_display->append(str);
    str += "\r\n";
    history_par.ble_buff += QByteArray::fromStdString(str.toStdString());

}

void MainWindow::BLE_DisplayWithNoTime(const QString &text)
{
    BLE_display->append( text);
    QString str;
    str = text + "\r\n";
    history_par.ble_buff += QByteArray::fromStdString(str.toStdString());
}


void MainWindow::on_BLE_FiltId_textChanged()
{
    QString str = BLE_FiltId->toPlainText();
    if(str.length() == 0)
    {
        ble_par.filtId[0] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ble_par.filtId[0] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ble_par.filtId[0] = str.toUShort(Q_NULLPTR,10);
    }
    BLE_DisplayWithTime("filt id_0:0x"+uint16ToHex(ble_par.filtId[0]).toUpper());
}

void MainWindow::on_BLE_FiltId_1_textChanged()
{
    QString str = BLE_FiltId_1->toPlainText();
    if(str.length() == 0)
    {
        ble_par.filtId[1] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ble_par.filtId[1] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ble_par.filtId[1] = str.toUShort(Q_NULLPTR,10);
    }
    BLE_DisplayWithTime("filt id_1:0x"+uint16ToHex(ble_par.filtId[1]).toUpper());
}

void MainWindow::on_BLE_FiltId_2_textChanged()
{
    QString str = BLE_FiltId_2->toPlainText();
    if(str.length() == 0)
    {
        ble_par.filtId[2] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ble_par.filtId[2] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ble_par.filtId[2] = str.toUShort(Q_NULLPTR,10);
    }
    BLE_DisplayWithTime("filt id_2:0x"+uint16ToHex(ble_par.filtId[2]).toUpper());
}

void MainWindow::on_BLE_FiltId_3_textChanged()
{
    QString str = BLE_FiltId_3->toPlainText();
    if(str.length() == 0)
    {
        ble_par.filtId[3] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ble_par.filtId[3] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ble_par.filtId[3] = str.toUShort(Q_NULLPTR,10);
    }
    BLE_DisplayWithTime("filt id_3:0x"+uint16ToHex(ble_par.filtId[3]).toUpper());
}

void MainWindow::on_BLE_FiltId_4_textChanged()
{
    QString str = BLE_FiltId_4->toPlainText();
    if(str.length() == 0)
    {
        ble_par.filtId[4] = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ble_par.filtId[4] = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ble_par.filtId[4] = str.toUShort(Q_NULLPTR,10);
    }
    BLE_DisplayWithTime("filt id_4:0x"+uint16ToHex(ble_par.filtId[4]).toUpper());
}

void MainWindow::on_BLE_FiltStr_textChanged()
{
    ble_par.filtStr = QByteArray::fromStdString(BLE_FiltStr->toPlainText().toStdString());
    BLE_DisplayWithTime("filt string:"+ble_par.filtStr);
}

void MainWindow::on_BLE__set125KRssi_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    BLE_Set125KRssi(send.gateway_id,rf_send.device_id);
}


void MainWindow::BLE_Set125KRssi(ushort gateway_id,ushort device_id)
{

    QString str;
    ushort ant125kId;
    uchar ant125kRssi;

    str = BLE_125KIDtextEdit->toPlainText();
    ant125kId = str.toUShort();
    str = BLE_125KRssitextEdit->toPlainText();
    ant125kRssi = str.toUShort();

    if(ant125kRssi>0x3F){
        BLE_DisplayWithTime("error: ant 125K RSSI 0x00~0x3F");
    }
    else{
        QByteArray buff;
        buff.clear();
        buff[0] = 0xA5;
        buff[1] = 0x5A;
        buff[2] = (ant125kId>>8)&0xFF;
        buff[3] = (ant125kId>>0)&0xFF;
        buff[4] = ant125kRssi;
        buff.append(checkSum(buff,buff.length()));

        IOT_cmdApp(gateway_id,device_id,buff);
        str = "ANT 125K ID = 0x"+uint16ToHex(ant125kId).toUpper();
        str += "  /RSSI = 0x"+uint8ToHex(ant125kRssi).toUpper();
        BLE_DisplayWithTime(str);
    }
}

void MainWindow::BLE_DisplayInit(void)
{

    uchar i,j;
    display_par.xy_max = 100;
    display_par.xy_unit = 10;
    for(i=0;i<DEVICE_DISPLAY_MAX;i++){

        display_par.ant[i].id = 0xFFFF;
        display_par.ant[i].x = 0x00;
        display_par.ant[i].y = 0x00;
        display_par.ant[i].radius = 0x00;
        display_par.ant[i].rssi_offset = 0x00;
        display_par.ant[i].color = Qt::white;
        display_par.ant[i].displayInfFlag = false;
        memset(display_par.ant[i].mac,0x00,8);

        display_par.device[i].id = 0xFFFF;
        display_par.device[i].x = 0x00;
        display_par.device[i].y = 0x00;
        display_par.device[i].radius = 0x00;
        display_par.device[i].rssi_offset = 0x00;
        display_par.device[i].color = Qt::white;
        display_par.device[i].displayInfFlag = false;
        memset(display_par.device[i].mac,0x00,8);

    }


    display_par.ant[0].id = 0x0001;
    display_par.ant[0].x = 0;
    display_par.ant[0].y = 0;
    display_par.ant[0].radius = 0;
    display_par.ant[0].rssi_offset = 0;
    display_par.ant[0].color = Qt::darkGreen;
    display_par.ant[0].displayInfFlag = false;
    memset(display_par.ant[0].mac,0x00,8);

    display_par.ant[1].id = 0x0002;
    display_par.ant[1].x = 50;
    display_par.ant[1].y = 0;
    display_par.ant[1].radius = 0;
    display_par.ant[1].rssi_offset = 0;
    display_par.ant[1].color = Qt::darkGreen;
    display_par.ant[1].displayInfFlag = false;
    memset(display_par.ant[1].mac,0x00,8);

    display_par.ant[2].id = 0x0003;
    display_par.ant[2].x = 50;
    display_par.ant[2].y = 50;
    display_par.ant[2].radius = 0;
    display_par.ant[2].rssi_offset = 0;
    display_par.ant[2].color = Qt::darkGreen;
    display_par.ant[2].displayInfFlag = false;
    memset(display_par.ant[2].mac,0x00,8);


    BLE_virtualAntIdEdit->setText("1");
    BLE_virtualDeviceIdEdit->setText("10");
    BLE_virtualSeqEdit->setText("1");
    BLE_virtualRssiEdit->setText("-20");

    for(i = 0;i<ALGORITHM_DEVICE_MAX;i++){

        ble_algorithm_par.ble_algorithm[i].receive_count = 0;
        ble_algorithm_par.ble_algorithm[i].device_id = 0xFFFF;
        ble_algorithm_par.ble_algorithm[i].sequence = 0;
        ble_algorithm_par.ble_algorithm[i].update_flag = false;
        for(j = 0;j<ALGORITHM_ANT_MAX;j++){
            ble_algorithm_par.ble_algorithm[i].ant_id[j] = 0xFFFF;
            ble_algorithm_par.ble_algorithm[i].rssi[j] = -100;
        }

    }


    ble_algorithm_par.timer = new QTimer(this);
    connect(ble_algorithm_par.timer,SIGNAL(timeout()),this,SLOT(BLE_locationCalculator()));

    // 场景
    QGraphicsScene *scene = new QGraphicsScene;




    BLE_DisplayDrawXY(display_par.xy_unit,display_par.xy_max,scene);


    // 视图
    // 视图关联场景
    graphicsView_BLE->setScene(scene);
    // 显示视图
    graphicsView_BLE->show();




    BLE_displayUpdate();


}

/***********************BLE end****************/



void MainWindow::BLE_displayUpdate()
{
    //BLE_DisplayInit();
    int x_point,y_point;
    ushort e_radius;
    graphicsView_BLE->scene()->clear();
    // 场景
    QGraphicsScene *scene = new QGraphicsScene;

    BLE_DisplayDrawXY(display_par.xy_unit,display_par.xy_max,scene);



    QPixmap pix(9,9);
    pix.fill(Qt::darkGreen);


    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
        if(display_par.ant[i].id!=0xFFFF){
            x_point = x_convert(display_par.ant[i].x);
            y_point = y_convert(display_par.ant[i].y);
            pix.fill(display_par.ant[i].color);
            scene->addPixmap(pix)->setPos(x_point-4,y_point-4);
            if(display_par.ant[i].radius)
            {
                // 圆形
                e_radius = x_convert(display_par.ant[i].radius);
                QGraphicsEllipseItem *e_item = new QGraphicsEllipseItem(x_point-e_radius, y_point-e_radius, e_radius*2, e_radius*2);
                scene->addItem(e_item);
            }


            scene->addText("ID :0x"+uint16ToHex(display_par.ant[i].id).toUpper()+
                           QString("(%1m,%2m)").arg(display_par.ant[i].x).arg(display_par.ant[i].y)
                           )->setPos(x_point+4,y_point);
            if(display_par.ant[i].displayInfFlag == true){
                scene->addText("MAC:"+strToHex(display_par.ant[i].mac,8).toUpper())->setPos(x_point+4,y_point+10);
                scene->addText(QString("OFS:%1").arg(display_par.ant[i].rssi_offset))->setPos(x_point+4,y_point+20);
                scene->addText(QString("RAD:%1").arg(display_par.ant[i].radius))->setPos(x_point+4,y_point+30);
            }
        }
    }

    pix.fill(Qt::darkBlue);
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
        if(display_par.device[i].id!=0xFFFF){
            x_point = x_convert(display_par.device[i].x);
            y_point = y_convert(display_par.device[i].y);
            pix.fill(display_par.device[i].color);
            scene->addPixmap(pix)->setPos(x_point-4,y_point-4);
            if(display_par.device[i].radius)
            {
                // 圆形
                e_radius = x_convert(display_par.device[i].radius);
                QGraphicsEllipseItem *e_item = new QGraphicsEllipseItem(x_point-e_radius, y_point-e_radius, e_radius*2, e_radius*2);
                scene->addItem(e_item);
            }


            scene->addText("ID :0x"+uint16ToHex(display_par.device[i].id).toUpper()+
                           QString("(%1m,%2m)").arg(display_par.device[i].x).arg(display_par.device[i].y)
                           )->setPos(x_point+4,y_point);
            if(display_par.device[i].displayInfFlag == true){
                scene->addText("MAC:"+strToHex(display_par.device[i].mac,8).toUpper())->setPos(x_point+4,y_point+10);
                scene->addText(QString("OFS:%1").arg(display_par.device[i].rssi_offset))->setPos(x_point+4,y_point+20);
                scene->addText(QString("RAD:%1").arg(display_par.device[i].radius))->setPos(x_point+4,y_point+30);
            }
        }
    }
    // 视图

    // 视图关联场景
    graphicsView_BLE->setScene(scene);
    // 显示视图
    graphicsView_BLE->show();

}



void MainWindow::BLE_DisplayDrawXY(uint xy_unit,uint xy_max,QGraphicsScene *scene)
{

    int num  = xy_max/xy_unit;

    for(int i=0;i<=num;i++){
        scene->addLine(0,y_convert(xy_unit)*i,x_convert(xy_max),y_convert(xy_unit)*i);
        scene->addText(QString("%1m").arg(i*xy_unit))->setPos(x_convert(0)-30,y_convert(xy_unit)*i-10);
    }
    if(xy_max%xy_unit){
        scene->addLine(0,y_convert(xy_max),x_convert(xy_max),y_convert(xy_max));
        scene->addText(QString("%1m").arg(xy_max))->setPos(x_convert(0)-30,y_convert(xy_max)-10);
    }

    for(int i=0;i<=num;i++){
        scene->addLine(x_convert(xy_unit)*i,0,x_convert(xy_unit)*i,y_convert(xy_max));
        scene->addText(QString("%1m").arg(i*xy_unit))->setPos(x_convert(xy_unit)*i-10,y_convert(0));
    }
    if(xy_max%xy_unit){
        scene->addLine(x_convert(xy_max),0,x_convert(xy_max),y_convert(xy_max));
        scene->addText(QString("%1m").arg(xy_max))->setPos(x_convert(xy_max)-10,y_convert(0));
    }
}







void MainWindow::on_BLE_addAnt_clicked()
{


    QString str;
    uchar i;
    int x_point;
    int y_point;

    str = BLE_xPointEdit->toPlainText();
    x_point = str.toInt();
    str = BLE_yPointEdit->toPlainText();
    y_point = str.toInt();



    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].x = x_point;
           display_par.ant[i].y = y_point;
           display_par.ant[i].color = Qt::darkGreen;
           goto on_BLE_addAnt_clicked_0;
       }
    }

    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == 0xFFFF){
           display_par.ant[i].id = rf_send.device_id;
           display_par.ant[i].x = x_point;
           display_par.ant[i].y = y_point;
           display_par.ant[i].color = Qt::darkGreen;
           goto on_BLE_addAnt_clicked_0;
       }
    }


on_BLE_addAnt_clicked_0:

    BLE_displayUpdate();



}

void MainWindow::on_BLE_deleteAnt_clicked()
{
    uchar i;

    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].id = 0xFFFF;
           display_par.ant[i].x = 0x00;
           display_par.ant[i].y = 0x00;
           display_par.ant[i].radius = 0x00;
           display_par.ant[i].rssi_offset = 0x00;
           display_par.ant[i].color = Qt::white;
           display_par.ant[i].displayInfFlag = false;
           memset(display_par.ant[i].mac,0x00,8);
           BLE_displayUpdate();
       }
    }
}






void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    BLE_roundMeter->setText(QString("半径%1米圆形").arg(value));

    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].radius = value;  
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id == rf_send.device_id){
           display_par.device[i].radius= value;
       }
    }
    BLE_displayUpdate();
}

void MainWindow::on_BLE_showDeviceInf_clicked()
{
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].displayInfFlag = true;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id == rf_send.device_id){
           display_par.device[i].displayInfFlag = true;
       }
    }
    BLE_displayUpdate();
}

void MainWindow::on_BLE_hideDeviceInf_clicked()
{
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].displayInfFlag = false;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id == rf_send.device_id){
           display_par.device[i].displayInfFlag = false;

       }
    }
    BLE_displayUpdate();
}

void MainWindow::on_BLE_showAllDeviceInf_clicked()
{
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id != 0xFFFF){
           display_par.ant[i].displayInfFlag = true;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id != 0xFFFF){
           display_par.device[i].displayInfFlag = true;
       }
    }
    BLE_displayUpdate();

}

void MainWindow::on_BLE_hideAllDeviceInf_clicked()
{
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id != 0xFFFF){
           display_par.ant[i].displayInfFlag = false;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id != 0xFFFF){
           display_par.device[i].displayInfFlag = false;
       }
    }
    BLE_displayUpdate();

}

void MainWindow::on_BLE_rssiCalculatorSlider_valueChanged(int value)
{
    BLE_rssiCalculatorLabel->setText(QString("天线校准%1dBm").arg(value-50));
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].rssi_offset = value-50;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id == rf_send.device_id){
           display_par.device[i].rssi_offset= value-50;
       }
    }
    BLE_displayUpdate();
}

void MainWindow::BLE_storeData(ushort device_id,ushort ant_id,uchar sequence,char rssi){
    for(uchar i=0;i<ALGORITHM_DEVICE_MAX;i++)
    {
        if(ble_algorithm_par.ble_algorithm[i].device_id == device_id){
            if(ble_algorithm_par.ble_algorithm[i].sequence == sequence){
                for(uchar j = 0;j<ble_algorithm_par.ble_algorithm[i].receive_count;j++){
                    if(ble_algorithm_par.ble_algorithm[i].ant_id[j] == ant_id){
                        ble_algorithm_par.ble_algorithm[i].rssi[j] = rssi;
                        ble_algorithm_par.ble_algorithm[i].update_flag = true;
                        BLE_locationCalculator();
                        return;
                    }
                }

                if(ble_algorithm_par.ble_algorithm[i].receive_count>=ALGORITHM_ANT_MAX){
                    ble_algorithm_par.ble_algorithm[i].receive_count = 0;
                }
                ble_algorithm_par.ble_algorithm[i].rssi[ble_algorithm_par.ble_algorithm[i].receive_count] = rssi;
                ble_algorithm_par.ble_algorithm[i].ant_id[ble_algorithm_par.ble_algorithm[i].receive_count] = ant_id;
                ble_algorithm_par.ble_algorithm[i].receive_count++;
                ble_algorithm_par.ble_algorithm[i].update_flag = true;
                return ;
            }
            else if(ble_algorithm_par.ble_algorithm[i].sequence < sequence ||
                   ble_algorithm_par.ble_algorithm[i].sequence > (sequence+3)){
                //有新的数据接收到，计算定位数据
                if(ble_algorithm_par.ble_algorithm[i].update_flag == true){
                    //还没有来得及计算位置，就有新的数据
                    BLE_locationCalculator();
                }
                //store new data
                ble_algorithm_par.ble_algorithm[i].rssi[0] = rssi;
                ble_algorithm_par.ble_algorithm[i].ant_id[0] = ant_id;
                ble_algorithm_par.ble_algorithm[i].receive_count=1;
                ble_algorithm_par.ble_algorithm[i].sequence = sequence;
                ble_algorithm_par.ble_algorithm[i].update_flag = true;

                return;
            }
            else{
                return;
            }
        }
    }
    for(uchar i=0;i<ALGORITHM_DEVICE_MAX;i++)
    {
        if(ble_algorithm_par.ble_algorithm[i].device_id == 0xFFFF){
            //store new data
            ble_algorithm_par.ble_algorithm[i].device_id = device_id;
            ble_algorithm_par.ble_algorithm[i].rssi[0] = rssi;
            ble_algorithm_par.ble_algorithm[i].ant_id[0] = ant_id;
            ble_algorithm_par.ble_algorithm[i].receive_count=1;
            ble_algorithm_par.ble_algorithm[i].sequence = sequence;
            ble_algorithm_par.ble_algorithm[i].update_flag = true;

            return;
        }
    }
}


void MainWindow::BLE_locationCalculator(void){
    bool update_flag = false;
    uchar i ,j,m,n;
    double a1, b1, c1, d1, e1, f1, M1;
    double a2, b2, c2, d2, e2, f2, M2;
    double a3, b3, c3, d3, e3, f3, M3;
    uchar xA,yA,xB,yB,xC,yC;
    short x,y,x_point,y_point;
    double distance_AB[2],distance_AC[2],distance_BC[2],distance_last;
    double distance_A,distance_B,distance_C;
    double rssi_AB,rssi_AC,rssi_BC;
    ushort ant_idA,ant_idB,ant_idC;
    double ant_rssiA,ant_rssiB,ant_rssiC;
    short ant_offsetA,ant_offsetB,ant_offsetC;
    Eigen::Matrix<double, 6, 1> equation1,equation2,equation3;



    for(i=0;i<ALGORITHM_DEVICE_MAX;i++){
        if(ble_algorithm_par.ble_algorithm[i].update_flag == true &&
           ble_algorithm_par.ble_algorithm[i].receive_count >= 3){
            update_flag = true;
            ble_algorithm_par.ble_algorithm[i].update_flag = false;


            //location algorithm
//            for(j = 0;j<DEVICE_DISPLAY_MAX;j++){
//                //clear last location data
//                if(display_par.device[j].id==i){
//                    display_par.device[j].id = 0xFFFF;
//                    display_par.device[j].x = 0x00;
//                    display_par.device[j].y = 0x00;
//                    display_par.device[j].radius = 0x00;
//                    display_par.device[j].rssi_offset = 0x00;
//                    display_par.device[j].color = Qt::white;
//                    display_par.device[j].displayInfFlag = false;
//                    memset(display_par.device[j].mac,0x00,8);
//                }
//            }

            for(m = 0;m< ble_algorithm_par.ble_algorithm[i].receive_count-2;m++){
                for(n = m;n< ble_algorithm_par.ble_algorithm[i].receive_count-2;n++){
                    //选择三个天线的数据进行定位
                    ant_idA = ble_algorithm_par.ble_algorithm[i].ant_id[m];
                    ant_idB = ble_algorithm_par.ble_algorithm[i].ant_id[m+1];
                    ant_idC = ble_algorithm_par.ble_algorithm[i].ant_id[n+2];
                    ant_rssiA = ble_algorithm_par.ble_algorithm[i].rssi[m];
                    ant_rssiB = ble_algorithm_par.ble_algorithm[i].rssi[m+1];
                    ant_rssiC = ble_algorithm_par.ble_algorithm[i].rssi[n+2];

                    for(j = 0 ; j <DEVICE_DISPLAY_MAX;j++){
                        //seek ant0 information
                        if(display_par.ant[j].id==ant_idA){
                            xA = display_par.ant[j].x;
                            yA = display_par.ant[j].y;
                            ant_offsetA = display_par.ant[j].rssi_offset;
                            break;
                        }
                    }

                    for(j = 0 ; j <DEVICE_DISPLAY_MAX;j++){
                        //seek ant1 information
                        if(display_par.ant[j].id==ant_idB){
                            xB = display_par.ant[j].x;
                            yB = display_par.ant[j].y;
                            ant_offsetB = display_par.ant[j].rssi_offset;
                            break;
                        }
                    }

                    for(j = 0 ; j <DEVICE_DISPLAY_MAX;j++){
                        //seek ant2 information
                        if(display_par.ant[j].id==ant_idC){
                            xC = display_par.ant[j].x;
                            yC = display_par.ant[j].y;
                            ant_offsetC = display_par.ant[j].rssi_offset;
                            break;
                        }
                    }
                    //all information is ready
                    ant_rssiA = -ant_rssiA+ant_offsetA;
                    ant_rssiB = -ant_rssiB+ant_offsetB;
                    ant_rssiC = -ant_rssiC+ant_offsetC;




                    if(ant_rssiA>ant_rssiB){
                        rssi_AB = ant_rssiA/ant_rssiB;
                    }
                    else {
                        rssi_AB = ant_rssiB/ant_rssiA;
                    }

                    if(ant_rssiA>ant_rssiC){
                        rssi_AC = ant_rssiA/ant_rssiC;
                    }
                    else {
                        rssi_AC = ant_rssiC/ant_rssiA;
                    }

                    if(ant_rssiB>ant_rssiC){
                        rssi_BC = ant_rssiB/ant_rssiC;
                    }
                    else {
                        rssi_BC = ant_rssiC/ant_rssiB;
                    }


                    distance_last = 1000;
                    x_point=1000;
                    y_point=1000;
                    for(x=-100;x<200;x++){
                        for(y=-100;y<200;y++){

                            if((x==xA&&y==yA)||(x==xB&&y==yB)||(x==xC&&y==yC)){
                                continue;
                            }
                            distance_A = sqrt((x - xA)*(x - xA)+(y - yA)*(y - yA));
                            distance_B = sqrt((x - xB)*(x - xB)+(y - yB)*(y - yB));
                            distance_C = sqrt((x - xC)*(x - xC)+(y - yC)*(y - yC));

                            if(ant_rssiA>ant_rssiB){
                                distance_AB[0] = distance_A / distance_B;
                            }
                            else {
                                distance_AB[0] = distance_B / distance_A;
                            }

                            if(ant_rssiA>ant_rssiC){
                                distance_AC[0] = distance_A / distance_C;
                            }
                            else {
                                distance_AC[0] = distance_C / distance_A;
                            }

                            if(ant_rssiB>ant_rssiC){
                                distance_BC[0] = distance_B / distance_C;
                            }
                            else {
                                distance_BC[0] = distance_C / distance_B;
                            }



//                            if(distance_AB[0]<rssi_AB){
//                                distance_AB[1] = rssi_AB - distance_AB[0];
//                            }
//                            else {
//                                distance_AB[1] = distance_AB[0] - rssi_AB;
//                            }

//                            if(distance_AC[0]<rssi_AC){
//                                distance_AC[1] = rssi_AC - distance_AC[0];
//                            }
//                            else {
//                                distance_AC[1] = distance_AC[0] - rssi_AC;
//                            }

//                            if(distance_BC[0]<rssi_BC){
//                                distance_BC[1] = rssi_BC - distance_BC[0];
//                            }
//                            else {
//                                distance_BC[1] = distance_BC[0] - rssi_BC;
//                            }



//                            if(distance_last > (distance_AB[1]+distance_AC[1]+distance_BC[1])){
//                                distance_last = distance_AB[1]+distance_AC[1]+distance_BC[1];
//                                x_point = x;
//                                y_point = y;
//                            }


                            distance_AB[1] = rssi_AB/distance_AB[0];
                            distance_AC[1] = rssi_AC/distance_AC[0];
                            distance_BC[1] = rssi_BC/distance_BC[0];

                            if(distance_AB[1]>1){
                                distance_AB[1] = distance_AB[1] - 1;
                            }
                            else {
                                distance_AB[1] = 1 - distance_AB[1];
                            }

                            if(distance_AC[1]>1){
                                distance_AC[1] = distance_AC[1] - 1;
                            }
                            else {
                                distance_AC[1] = 1 - distance_AC[1];
                            }

                            if(distance_BC[1]>1){
                                distance_BC[1] = distance_BC[1] - 1;
                            }
                            else {
                                distance_BC[1] = 1 - distance_BC[1];
                            }



                            if(distance_AB[1]<0.1 && distance_AC[1]<0.1 && distance_BC[1]<0.1)
                            {

                                if(distance_last > (distance_AB[1]+distance_AC[1]+distance_BC[1]))
                                {
                                    distance_last = distance_AB[1]+distance_AC[1]+distance_BC[1];
                                    x_point = x;
                                    y_point = y;
                                }
                            }
                        }
                    }



//                    M1 = ant_rssiA*ant_rssiA/ant_rssiB/ant_rssiB;
//                    M2 = ant_rssiA*ant_rssiA/ant_rssiC/ant_rssiC;
//                    M3 = ant_rssiB*ant_rssiB/ant_rssiC/ant_rssiC;




//                    a1 = 1-M1;
//                    b1 = 0;
//                    c1 = 1-M1;
//                    d1 = -2*xA+2*M1*xB;
//                    e1 = -2*yA+2*M1*yB;
//                    f1 = xA*xA+yA*yA-M1*xB*xB-M1*yB*yB;

//                    a2 = 1-M2;
//                    b2 = 0;
//                    c2 = 1-M2;
//                    d2 = -2*xA+2*M2*xC;
//                    e2 = -2*yA+2*M2*yC;
//                    f2 = xA*xA+yA*yA-M2*xC*xC-M2*yC*yC;


//                    a3 = 1-M3;
//                    b3 = 0;
//                    c3 = 1-M3;
//                    d3 = -2*xB+2*M3*xC;
//                    e3 = -2*yB+2*M3*yC;
//                    f3 = xB*xB+yB*yB-M3*xC*xC-M3*yC*yC;

//                    //a*x^2+b*x*y+c*y^2+d*x+e*y+f=0
//                    //a1*x^2+b1*x*y+c1*y^2+d1*x+e1*y+f1=0
//                    //a2*x^2+b2*x*y+c2*y^2+d2*x+e2*y+f2=0
//                    //a3*x^2+b3*x*y+c3*y^2+d3*x+e3*y+f3=0

//                    if(((a3*d1-a1*d3)*(a2*e1-a1*e2)-(a2*d1-a1*d2)*(a3*e1-a1*e3)!=0)&&
//                       ((a3*e1-a1*e3)*(a2*d1-a1*d2)-(a2*e1-a1*e2)*(a3*d1-a1*d3)!=0)){

//                        y = ((a2*d1-a1*d2)*(a3*f1-a1*f3)-(a3*d1-a1*d3)*(a2*f1-a1*f2))/
//                            ((a3*d1-a1*d3)*(a2*e1-a1*e2)-(a2*d1-a1*d2)*(a3*e1-a1*e3));
//                        x = ((a2*d1-a1*e2)*(a3*f1-a1*f3)-(a3*e1-a1*e3)*(a2*f1-a1*f2))/
//                            ((a3*e1-a1*e3)*(a2*d1-a1*d2)-(a2*e1-a1*e2)*(a3*d1-a1*d3));
//                    }

//                    if(a1 == 0 && a2 == 0 && a3 == 0){
//                        //d1*x+e1*y+f1=0
//                        //d2*x+e2*y+f2=0
//                        //d3*x+e3*y+f3=0
//                        //1&2
//                        if((d1*e2-d2*e1)!=0 && (d2*e1-d1*e2)!=0){
//                            x = (f2*e1-f1*e2)/(d1*e2-d2*e1);
//                            y = (f2*d1-f1*d2)/(d2*e1-d1*e2);
//                        }
//                        //1&3
//                        else if((d1*e3-d3*e1)!=0 && (d3*e1-d1*e3)!=0){
//                            x = (f3*e1-f1*e3)/(d1*e3-d3*e1);
//                            y = (f3*d1-f1*d3)/(d3*e1-d1*e3);
//                        }
//                        //2&3
//                        else if((d2*e3-d3*e2)!=0 && (d3*e2-d2*e3)!=0){
//                            x = (f3*e2-f2*e3)/(d2*e3-d3*e2);
//                            y = (f3*d2-f2*d3)/(d3*e2-d2*e3);
//                        }
//                        else {
//                            //no answer
//                            LOC_DisplayWithTime("没有办法计算出答案");
//                        }
//                    }
//                    else if(a1 == 0 && a2 == 0 && a3 != 0){
//                        //d1*x+e1*y+f1=0
//                        //d2*x+e2*y+f2=0
//                        //a3*x^2+b3*x*y+c3*y^2+d3*x+e3*y+f3=0

//                        if((d1*e2-d2*e1)!=0 && (d2*e1-d1*e2)!=0){
//                            x = (f2*e1-f1*e2)/(d1*e2-d2*e1);
//                            y = (f2*d1-f1*d2)/(d2*e1-d1*e2);
//                        }
//                        else
//                        {

//                        }
//                    }
//                    else if(a1 == 0 && a2 != 0 && a3 == 0){
//                        //d1*x+e1*y+f1=0
//                        //a2*x^2+b2*x*y+c2*y^2+d2*x+e2*y+f2=0
//                        //d3*x+e3*y+f3=0
//                        if((d1*e3-d3*e1)!=0 && (d3*e1-d1*e3)!=0){
//                            x = (f3*e1-f1*e3)/(d1*e3-d3*e1);
//                            y = (f3*d1-f1*d3)/(d3*e1-d1*e3);
//                        }
//                    }
//                    else if(a1 == 0 && a2 != 0 && a3 != 0){
//                        //d1*x+e1*y+f1=0
//                        //a2*x^2+b2*x*y+c2*y^2+d2*x+e2*y+f2=0
//                        //a3*x^2+b3*x*y+c3*y^2+d3*x+e3*y+f3=0
//                    }
//                    else if(a1 != 0 && a2 == 0 && a3 == 0){
//                        //a1*x^2+b1*x*y+c1*y^2+d1*x+e1*y+f1=0
//                        //d2*x+e2*y+f2=0
//                        //d3*x+e3*y+f3=0
//                        if((d2*e3-d3*e2)!=0 && (d3*e2-d2*e3)!=0){
//                            x = (f3*e2-f2*e3)/(d2*e3-d3*e2);
//                            y = (f3*d2-f2*d3)/(d3*e2-d2*e3);
//                        }
//                    }
//                    else if(a1 != 0 && a2 == 0 && a3 != 0){
//                        //a1*x^2+b1*x*y+c1*y^2+d1*x+e1*y+f1=0
//                        //d2*x+e2*y+f2=0
//                        //a3*x^2+b3*x*y+c3*y^2+d3*x+e3*y+f3=0
//                    }
//                    else if(a1 != 0 && a2 != 0 && a3 == 0){
//                        //a1*x^2+b1*x*y+c1*y^2+d1*x+e1*y+f1=0
//                        //a2*x^2+b2*x*y+c2*y^2+d2*x+e2*y+f2=0
//                        //d3*x+e3*y+f3=0
//                    }
//                    else if(a1 != 0 && a2 != 0 && a3 != 0){
//                        //a1*x^2+b1*x*y+c1*y^2+d1*x+e1*y+f1=0
//                        //a2*x^2+b2*x*y+c2*y^2+d2*x+e2*y+f2=0
//                        //a3*x^2+b3*x*y+c3*y^2+d3*x+e3*y+f3=0
//                    }


                    if((x_point>-1000)&&
                       (y_point>-1000)&&
                       (x_point<1000)&&
                       (y_point<1000)
                            ){
                        for(j = 0;j<DEVICE_DISPLAY_MAX;j++){
                            //clear last location data
                            if(display_par.device[j].id == ble_algorithm_par.ble_algorithm[i].device_id){
                                display_par.device[j].id = ble_algorithm_par.ble_algorithm[i].device_id;
                                display_par.device[j].x = x_point;
                                display_par.device[j].y = y_point;
                                display_par.device[j].radius = 0x00;
                                display_par.device[j].rssi_offset = 0x00;
                                display_par.device[j].color = Qt::darkBlue;
                                display_par.device[j].displayInfFlag = false;
                                memset(display_par.device[j].mac,0x00,8);
                                goto BLE_locationCalculator_display;
                            }
                        }
                        for(j = 0;j<DEVICE_DISPLAY_MAX;j++){
                            //clear last location data
                            if(display_par.device[j].id == 0xFFFF){
                                display_par.device[j].id = ble_algorithm_par.ble_algorithm[i].device_id;
                                display_par.device[j].x = x_point;
                                display_par.device[j].y = y_point;
                                display_par.device[j].radius = 0x00;
                                display_par.device[j].rssi_offset = 0x00;
                                display_par.device[j].color = Qt::darkBlue;
                                display_par.device[j].displayInfFlag = false;
                                memset(display_par.device[j].mac,0x00,8);
                                goto BLE_locationCalculator_display;
                            }
                        }
                    }
                }
            }
        }
    }

 BLE_locationCalculator_display:
    if(update_flag == true){
        BLE_displayUpdate();
    }
}



//***************************************************


void MainWindow::on_BLE_virtualSetBt_clicked()
{
    //ushort i = shortAddr->currentRow();
    QString str;

    ushort virtual_ant_id,virtual_device_id;
    char rssi;
    uchar sequence;

    str = BLE_virtualAntIdEdit->toPlainText();
    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        virtual_ant_id = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        virtual_ant_id = str.toUShort(Q_NULLPTR,10);
    }

    str = BLE_virtualDeviceIdEdit->toPlainText();
    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        virtual_device_id = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        virtual_device_id = str.toUShort(Q_NULLPTR,10);
    }

    str = BLE_virtualSeqEdit->toPlainText();
    sequence = str.toUShort(Q_NULLPTR,10);

    str = BLE_virtualRssiEdit->toPlainText();
    rssi = str.toShort(Q_NULLPTR,10);



    BLE_storeData(virtual_device_id,virtual_ant_id,sequence,rssi);


}
















