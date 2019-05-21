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

	setupUi(this);
	timerout = NULL;
    receiveTimer = NULL;
    sendTimer = NULL;
	timeoutTime = NULL;
	counter_in = 0;
	counter_out = 0;

	setWindowIcon(QIcon(":/images/plats.ico"));


	progressBar->setValue(0);
	timerout = new QTimer(this);
    receiveTimer = new QTimer(this);
    sendTimer = new QTimer(this);
    user_init();
    NET_Init();
    LOC_init();
    COO_init();
    TEMTH_init();
    ENE_init();
    INJ_init();
    SOS_init();
    BLE_init();
    BLE_DisplayInit();

		//connecting

    connect(timerout, SIGNAL(timeout()), this, SLOT(transmitMsg()));
    connect(receiveTimer, SIGNAL(timeout()), this, SLOT(pressUartData()));
    connect(sendTimer,SIGNAL(timeout()),this,SLOT(ucmdAutoUpdate()));
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

     sys_par.battery = 0;
     sys_par.cal_now_x = 0;
     sys_par.cal_now_y = 0;
     sys_par.cal_now_z = 0;
     sys_par.device_receive_rssi = -120;
     sys_par.device_tx_power = -120;
     sys_par.tamper_0 = 0;
     sys_par.tamper_1 = 0;
     sys_par.shake = 1;

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
     history_par.temTh_path = "tempreture_humidity";
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
     dir.mkdir(history_par.temTh_path);
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
     history_par.temTh_path      = path+history_par.temTh_path;
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
     history_par.temTh_buff.clear();
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

}
/*
==============
<METHODS>
==============
*/
void MainWindow::closeEvent(QCloseEvent *event)
{

    event->accept();
}


/*
==============
<SLOTS>
==============
*/



void MainWindow::pressUartData(QTcpSocket *socket)
{
    uchar *ptr;
    ushort size;
    ushort length;
    uchar check_sum;





    ptr = transport.receive;
    size = transport.r_count;
    receiveTimer->stop();


    counter_in+=size;


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
                    pressCmdData(ptr,length,socket);
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


void MainWindow::pressCmdData(uchar *data , ushort size,QTcpSocket *socket)
{
    QByteArray buff;
    IOT_FRAME iot_frame;
    APP_FRAME app_frame;
    LOCATION_FRAME location_frame;
    LOCATION_8_FRAME loc_8_frame;
    BLE_LOCATION_FRAME ble_location_frame;
    COOL_FRAME_A55A cool_frame;
    COOL_FRAME_FACA cool_frame_faca;
    TEST_FRAME test_frame;
    A125K_FRAME a125k_frame;
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
    iot_frame.rssi = (char)data[size-2];

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





    str += QString("/ rssi:%1dBm").arg(iot_frame.rssi);


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
        if(iot_frame.data[0]==0xDB && iot_frame.data[1]==0xBD && checkBox_productTest->isChecked()==true){

            test_frame.head[0] = iot_frame.data[0];
            test_frame.head[1] = iot_frame.data[1];
            test_frame.cmd = iot_frame.data[2];
            test_frame.mac[0] = iot_frame.data[3];
            test_frame.mac[1] = iot_frame.data[4];
            test_frame.mac[2] = iot_frame.data[5];
            test_frame.mac[3] = iot_frame.data[6];
            test_frame.mac[4] = iot_frame.data[7];
            test_frame.mac[5] = iot_frame.data[8];
            test_frame.mac[6] = iot_frame.data[9];
            test_frame.mac[7] = iot_frame.data[10];
            test_frame.data = &iot_frame.data[11];

            ushort lenght = iot_frame.length - 1;

            if(checkSum((char *)(&iot_frame.data[2]),lenght-3)!= iot_frame.data[lenght-1])
            {
                LOC_DisplayWithTime("product test checkSum error");
                return;
            }

            str += "/ MAC:"+strToHex(test_frame.mac,8).toUpper();
            switch(test_frame.cmd){
                case test_tamper   :
                str += "/ cmd 0x01 按键测试状态:";
                if(test_frame.data[0]==0x00){
                    sys_par.tamper_0 = 1;
                    str+="拆卸解除";
                }
                else if(test_frame.data[0]==0x01){
                    sys_par.tamper_1 = 1;
                    str+="拆卸告警";
                }
                else str+="状态未知";
                break;
                case test_shake    :
                str += "/ cmd 0x02 震动测试状态:";
                sys_par.shake = test_frame.data[0];
                if(sys_par.shake==0x00)str+="振动检测成功";
                else if(sys_par.shake==0x01)str+="未检测到振动";
                else str+="状态未知";
                break;
                case test_txPower  :
                str += "/ cmd 0x03 rssi:";
                sys_par.device_tx_power = (char)test_frame.data[0] ;
                sys_par.gateway_receive_rssi = iot_frame.rssi;
                str += QString("/ 设备发射功率：%1dBm").arg(sys_par.device_tx_power ,0,10);
                str += QString("/ 网关接收灵敏度：%1dBm").arg(sys_par.gateway_receive_rssi);
                rcmdRssiAckTest(iot_frame.gateway_id,iot_frame.device_id,20);
                break;
                case test_reportPar:
                str += "/ cmd 0x04 测试报告:\r\n";
                sys_par.cal_previous_x = test_frame.data[0]*256+test_frame.data[1];
                sys_par.cal_previous_y = test_frame.data[2]*256+test_frame.data[3];
                sys_par.cal_previous_z = test_frame.data[4]*256+test_frame.data[5];
                sys_par.cal_now_x      = test_frame.data[6]*256+test_frame.data[7];
                sys_par.cal_now_y      = test_frame.data[8]*256+test_frame.data[9];
                sys_par.cal_now_z      = test_frame.data[10]*256+test_frame.data[11];
                str += "/ 校验前x轴:0x"+uint16ToHex(sys_par.cal_previous_x ).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_previous_x);
                str += "/ 校验前y轴:0x"+uint16ToHex(sys_par.cal_previous_y ).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_previous_y);
                str += "/ 校验前z轴:0x"+uint16ToHex(sys_par.cal_previous_z ).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_previous_z);
                str += "\r\n/ 校验后x轴:0x"+uint16ToHex(sys_par.cal_now_x).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_now_x);
                str += "/ 校验后y轴:0x"+uint16ToHex(sys_par.cal_now_y).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_now_y);
                str += "/ 校验后z轴:0x"+uint16ToHex(sys_par.cal_now_z).toUpper();
                str += QString("=%1kHZ").arg((double)38400/sys_par.cal_now_z);

                sys_par.device_receive_rssi = (char)test_frame.data[12];
                str += QString("\r\n/ 接收灵敏度:%1dBm").arg(sys_par.device_receive_rssi);
                sys_par.battery = test_frame.data[13];
                str += QString("/ 电压:%1V").arg((double)sys_par.battery/10);

                str += "\r\n************************test report**********************";
                sys_par.test_status = true;
                if(sys_par.battery<32 && sys_par.battery>34){
                    sys_par.test_status = false;
                    str += "\r\nvoltage error";
                }
                if(sys_par.device_receive_rssi<5){
                    sys_par.test_status = false;
                    str += "\r\ndevice receive rssi error";
                }

                if(sys_par.gateway_receive_rssi<5){
                    sys_par.test_status = false;
                    str += "\r\ngateway_receive rssi error";
                }

                if(sys_par.device_tx_power<20){
                    sys_par.test_status = false;
                    str += "\r\ntx power error";
                }

                if(( sys_par.cal_now_x>0x0140 || sys_par.cal_now_x<0x0127)||
                    (sys_par.cal_now_y>0x0140 || sys_par.cal_now_y<0x0127)||
                    (sys_par.cal_now_z>0x0140 || sys_par.cal_now_z<0x0127)
                        ){//120K~130k正常
                    sys_par.test_status = false;
                    str += "\r\n125k cal error";
                }

                if(sys_par.tamper_0==0 || sys_par.tamper_1==0){
                    sys_par.test_status = false;
                    str += "\r\ntamper error";
                }

                if(sys_par.shake == 1){
                    sys_par.test_status = false;
                    str += "\r\nshake error";
                }
                if(sys_par.test_status == false)str += "\r\ntest error !!!!!!!!!!!!!!!!!!!test error";
                else str += "\r\ntest OK !!!!!!!!!!!!!!!!!!!test OK";
                sys_par.battery = 0;
                sys_par.cal_now_x = 0;
                sys_par.cal_now_y = 0;
                sys_par.cal_now_z = 0;
                sys_par.device_receive_rssi = -120;
                sys_par.device_tx_power = -120;
                sys_par.tamper_0 = 0;
                sys_par.tamper_1 = 0;
                sys_par.shake = 1;



                str += "\r\n************************test report**********************";
                str += "\r\n请在10S钟内按下低功耗电流测试键";
                break;
                default:break;
            }
            LOC_DisplayWithTime(str);
        }
        else if(iot_frame.data[0]==0xDB && iot_frame.data[1]==0xBD && checkBox_125KTest->isChecked()==true){

            a125k_frame.head[0] = iot_frame.data[0];
            a125k_frame.head[1] = iot_frame.data[1];
            a125k_frame.device_id = iot_frame.data[2]*256+iot_frame.data[3];
            a125k_frame.nc0 = iot_frame.data[4];
            a125k_frame.reset_inf = iot_frame.data[5]*256+iot_frame.data[6];
            a125k_frame.nc1 = iot_frame.data[7];
            a125k_frame.ant0_previous = iot_frame.data[8]*256+iot_frame.data[9];
            a125k_frame.ant1_previous = iot_frame.data[10]*256+iot_frame.data[11];
            a125k_frame.ant2_previous = iot_frame.data[12]*256+iot_frame.data[13];
            a125k_frame.nc2 = iot_frame.data[14];
            a125k_frame.ant0_current = iot_frame.data[15]*256+iot_frame.data[16];
            a125k_frame.ant1_current = iot_frame.data[17]*256+iot_frame.data[18];
            a125k_frame.ant2_current = iot_frame.data[19]*256+iot_frame.data[20];
            a125k_frame.nc3 = iot_frame.data[21];
            a125k_frame.voltage = iot_frame.data[22]*256+iot_frame.data[23];
            a125k_frame.nc4 = iot_frame.data[24];
            a125k_frame.checksum = iot_frame.data[25];

            if(checkSum((char *)(&iot_frame.data[2]),23)!= a125k_frame.checksum)
            {
                LOC_DisplayWithTime("125k checkSum error");
                return;
            }

            str += "/ device_id 0x"+ uint16ToHex(a125k_frame.device_id);
            str += "/ reset inf 0x"+ uint16ToHex(a125k_frame.reset_inf);
            str += "\r\n/ ant0_previous 0x"+ uint16ToHex(a125k_frame.ant0_previous);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant0_previous,7);
            str += "/ ant1_previous 0x"+ uint16ToHex(a125k_frame.ant1_previous);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant1_previous,7);
            str += "/ ant2_previous 0x"+ uint16ToHex(a125k_frame.ant2_previous);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant2_previous,7);

            str += "\r\n/ ant0_current  0x"+ uint16ToHex(a125k_frame.ant0_current);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant0_current,7);
            str += "/ ant1_current  0x"+ uint16ToHex(a125k_frame.ant1_current);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant1_current,7);
            str += "/ ant2_current  0x"+ uint16ToHex(a125k_frame.ant2_current);
            str += QString(" = %1 KHZ").arg(38400/(double)a125k_frame.ant2_current,7);
            str += QString("\r\n/ voltage:%1V").arg((double)a125k_frame.voltage/1000);


            LOC_DisplayWithTime(str);
        }
        else if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x1E)
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
            ble_location_frame.rssi = (char)iot_frame.data[22];
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
            str += QString("/ BLE_rssi:%1").arg(ble_location_frame.rssi);
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
        else if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x0A)
        {
            //include rssi
            location_frame.head[0] = iot_frame.data[0];
            location_frame.head[1] = iot_frame.data[1];
            location_frame.devie_id = iot_frame.data[2]*256+iot_frame.data[3];
            location_frame.ant_id = iot_frame.data[4]*256+iot_frame.data[5];
            location_frame.rssi = (char)iot_frame.data[6];
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
            str += QString("/ rssi:%1").arg(location_frame.rssi);
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


           for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                //clear last location data
                if(display_par.device[j].id == location_frame.devie_id){
                    display_par.device[j].id = 0xFFFF;
                    display_par.device[j].x = 0;
                    display_par.device[j].y = 0;
                    display_par.device[j].radius = 0x00;
                    display_par.device[j].rssi_offset = 0x00;
                    display_par.device[j].color = Qt::white;
                    display_par.device[j].displayInfFlag = false;
                    memset(display_par.device[j].mac,0x00,8);
                }
            }
            for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                //clear last location data
                if(display_par.device[j].id == 0xFFFF){
                    display_par.device[j].id = location_frame.devie_id;
                    display_par.device[j].x = location_frame.ant_id/256;
                    display_par.device[j].y = location_frame.ant_id%256;
                    display_par.device[j].radius = 0x00;
                    display_par.device[j].rssi_offset = 0x00;
                    display_par.device[j].color = Qt::darkBlue;
                    display_par.device[j].displayInfFlag = false;
                    memset(display_par.device[j].mac,0x00,8);
                    break;
                }
            }

            BLE_displayUpdate();
        }
        else if(iot_frame.data[0]==0xA5 && iot_frame.data[1]==0x5A && iot_frame.length==0x09)//no rssi
        {
            //新腕带程序
            location_frame.head[0] = iot_frame.data[0];
            location_frame.head[1] = iot_frame.data[1];
            location_frame.devie_id = iot_frame.data[2]*256+iot_frame.data[3];
            location_frame.ant_id = iot_frame.data[4]*256+iot_frame.data[5];
            location_frame.rssi = (char)iot_frame.data[6];
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
            str += QString("/ rssi:%1").arg(location_frame.rssi);
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
        else if(iot_frame.data[0]==0xA6 && iot_frame.data[1]==0x6A)
        {
            //include rssi
            //BLE&Outdoor location
            loc_8_frame.head[0] = iot_frame.data[0];
            loc_8_frame.head[1] = iot_frame.data[1];
            memcpy(loc_8_frame.mac,&iot_frame.data[2],8);
            loc_8_frame.device_type = iot_frame.data[10];
            loc_8_frame.len = iot_frame.data[11];
            loc_8_frame.cmd = iot_frame.data[12];
            loc_8_frame.data = &iot_frame.data[13];
            loc_8_frame.checksum = iot_frame.data[12+loc_8_frame.len];



            if(checkSum((char *)(&iot_frame.data[0]),12+loc_8_frame.len)!= loc_8_frame.checksum)
            {
                return ;
            }

            if(locationStopDisplay->isChecked() == true)return;


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


            str += "/ device_MAC:"+strToHex(loc_8_frame.mac,8).toUpper();

            str += "/ device type:";
            switch(loc_8_frame.device_type)
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
                str += "patientSpireLamella";
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
            case dev_863DriectModule:
                str += "863DriectModule";
                break;
            case dev_863ORModule:
                str += "863ORModule";
                break;
            case dev_863PDA:
                str += "863PDA";
                break;
            case dev_863DesktopRW:
                str += "863DesktopRW";
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

            str += "/ cmd:";
            switch(loc_8_frame.cmd){
            case locCmd_125KData:
                str += "125KData";
                ushort Data125K_ant_id  ;
                short Data125K_ant_rssi ;
                uchar Data125K_alarm    ;
                uchar Data125K_voltage  ;

                Data125K_ant_id = loc_8_frame.data[0]*256+loc_8_frame.data[1];
                Data125K_ant_rssi = loc_8_frame.data[2];
                Data125K_alarm = loc_8_frame.data[3];
                Data125K_voltage = loc_8_frame.data[4];

                str += QString("/ ant_id:%1").arg(Data125K_ant_id)+"=0x"+uint16ToHex(Data125K_ant_id).toUpper();
                str += QString("/ 125K_rssi:%1").arg(Data125K_ant_rssi);
                str += "/ alarm:0x"+uint8ToHex(Data125K_alarm).toUpper();
                if(checkDrop(Data125K_alarm))str += " 跌落报警;";
                if(checkAlarm(Data125K_alarm))str += " 紧急报警;";
                if(checkLocation(Data125K_alarm))str += " 室外报警;";
                if(checkLowBattery(Data125K_alarm))str += " 低电报警;";
                if(checkTamper(Data125K_alarm))str += " 防拆报警;";
                str += QString("/ voltage:%1.%2").arg(Data125K_voltage/10,0,10).arg(Data125K_voltage%10,0,10);

                if(loc_par.filtStr.length()!=0)
                {

                    if(str.contains(loc_par.filtStr) == false)
                    return;
                }
                break;
            case locCmd_outDoorData:
                str += "outDoorData";
                short outDoorData_x         ;
                short outDoorData_y         ;
                uchar outDoorData_alarm     ;
                uchar outDoorData_voltage   ;

                outDoorData_x         = loc_8_frame.data[0]*256+loc_8_frame.data[1];
                outDoorData_y         = loc_8_frame.data[2]*256+loc_8_frame.data[3];
                outDoorData_alarm     = loc_8_frame.data[4];
                outDoorData_voltage   = loc_8_frame.data[5];


                str += QString("/ x:%1  y:%2").arg(outDoorData_x).arg(outDoorData_y);
                str += "/ alarm:0x"+uint8ToHex(outDoorData_alarm).toUpper();
                if(checkDrop(outDoorData_alarm))str += " 跌落报警;";
                if(checkAlarm(outDoorData_alarm))str += " 紧急报警;";
                if(checkLocation(outDoorData_alarm))str += " 室外报警;";
                if(checkLowBattery(outDoorData_alarm))str += " 低电报警;";
                if(checkTamper(outDoorData_alarm))str += " 防拆报警;";
                str += QString("/ voltage:%1.%2").arg(outDoorData_voltage/10,0,10).arg(outDoorData_voltage%10,0,10);

                if(loc_par.filtStr.length()!=0)
                {

                    if(str.contains(loc_par.filtStr) == false)
                    return;
                }

                for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                    //clear last location data
                    //if(display_par.device[j].id == location_frame.devie_id){
                    if(memcmp(display_par.device[j].mac,loc_8_frame.mac,8) == 0){
                        display_par.device[j].id = 0xFFFF;
                        display_par.device[j].x = 0;
                        display_par.device[j].y = 0;
                        display_par.device[j].radius = 0x00;
                        display_par.device[j].rssi_offset = 0x00;
                        display_par.device[j].color = Qt::white;
                        display_par.device[j].displayInfFlag = false;
                        memset(display_par.device[j].mac,0x00,8);
                    }
                }
                for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                    //clear last location data
                    if(display_par.device[j].id == 0xFFFF){
                        display_par.device[j].id = iot_frame.device_id;
                        display_par.device[j].x = outDoorData_x;
                        display_par.device[j].y = outDoorData_y;
                        display_par.device[j].radius = 0x00;
                        display_par.device[j].rssi_offset = 0x00;
                        display_par.device[j].color = Qt::darkBlue;
                        display_par.device[j].displayInfFlag = false;
                        memcpy(display_par.device[j].mac,loc_8_frame.mac,8);
                        break;
                    }
                }

                BLE_displayUpdate();

                break;
            case locCmd_rssiCaculation:
                str += "locCmd_rssiCaculation";
                break;
            case locCmd_bleData:
                uchar locCmd_bleData_alarm     ;
                uchar locCmd_bleData_voltage   ;
                short locCmd_bleData_txPowr;
                short locCmd_bleData_recRssi;
                str += "locCmd_bleData";
                str += "/ ant_mac:"+strToHex(&loc_8_frame.data[0],8).toUpper();
                str += QString("/ seq:%1").arg(loc_8_frame.data[8],3);
                locCmd_bleData_voltage = loc_8_frame.data[9];
                str += QString("/ bat:%1.%2V").arg(locCmd_bleData_voltage/10).arg(locCmd_bleData_voltage%10);
                str += QString("/ x:%1 y:%2 z:%3").arg(loc_8_frame.data[10]).arg(loc_8_frame.data[11]).arg(loc_8_frame.data[12]);
                locCmd_bleData_alarm = loc_8_frame.data[13];
                
                locCmd_bleData_txPowr = (char)loc_8_frame.data[14];
                locCmd_bleData_recRssi = (char)loc_8_frame.data[15];
                
                str += QString("/ txPower:%1dBm").arg(locCmd_bleData_txPowr,2);
                str += QString("/ recRssi:%1dBm").arg(locCmd_bleData_recRssi,4);
                
                str += "/ alarm:0x"+uint8ToHex(locCmd_bleData_alarm).toUpper();
                if(checkDrop(locCmd_bleData_alarm))str += " 跌落报警;";
                if(checkAlarm(locCmd_bleData_alarm))str += " 紧急报警;";
                if(checkLocation(locCmd_bleData_alarm))str += " 室外报警;";
                if(checkLowBattery(locCmd_bleData_alarm))str += " 低电报警;";
                if(checkTamper(locCmd_bleData_alarm))str += " 防拆报警;";
                
                




                break;
            case locCmd_heartRateData:
                str += "locCmd_heartRateData";
                str += QString("/ max:%1").arg((short)(loc_8_frame.data[0]*256+loc_8_frame.data[1]));
                str += QString("/ avr:%1").arg((short)(loc_8_frame.data[2]*256+loc_8_frame.data[3]));
                str += QString("/ min:%1").arg((short)(loc_8_frame.data[4]*256+loc_8_frame.data[5]));
                str += QString("/ time report:%1S").arg(loc_8_frame.data[6]*256+loc_8_frame.data[7]);
                uint time_utc;
                time_utc =  (loc_8_frame.data[8]<<24)+
                            (loc_8_frame.data[9]<<16)+
                            (loc_8_frame.data[10]<<8)+
                            (loc_8_frame.data[11]<<0);
                str += QString("/ UTC:%1").arg(time_utc);

                str += "/ "+ (QDateTime::fromTime_t(time_utc)).toString();
                break;
            case locCmd_setReportTime:
                str += "locCmd_setReportTime";
                ushort report_time;
                report_time= loc_8_frame.data[0]*256+loc_8_frame.data[1];
                str += QString("/ time:%1 S").arg(report_time);
                break;
            case locCmd_setRssiOffset:
                str += "locCmd_setRssiOffset";
                char rssi_offset;
                rssi_offset= loc_8_frame.data[0];
                str += QString("/ rssi offset:%1").arg((short)rssi_offset);
                break;
            default :
                str += "unknow cmd";
                break;
            }
            if(loc_par.filtStr.length()!=0)
            {

                if(str.contains(loc_par.filtStr) == false)
                return;
            }
            LOC_DisplayWithTime(str);
        }
        else if(iot_frame.data[0]==0xFA && iot_frame.data[1]==0xCA)
        {


            cool_frame_faca.head[0] = iot_frame.data[0];
            cool_frame_faca.head[1] = iot_frame.data[1];
            cool_frame_faca.sensorId = iot_frame.data[2]*256+iot_frame.data[3];
            cool_frame_faca.deviceType = iot_frame.data[4];
            cool_frame_faca.len = iot_frame.data[5];
            cool_frame_faca.cmd = iot_frame.data[6];
            cool_frame_faca.data = &iot_frame.data[7];
            cool_frame_faca.checksum = iot_frame.data[6+cool_frame_faca.len];

            if(checkSum((char *)(iot_frame.data),cool_frame_faca.len+6)!= cool_frame_faca.checksum)
            {
                return ;
            }



            if(cool_frame_faca.deviceType == coolDevCoolChain)
            {
                //if(cool_frame_faca.cmd != 0xFE)COO_ackSuccess(iot_frame.gateway_id,iot_frame.device_id,cool_frame_faca.cmd);
                if(coolStopDisplay->isChecked() == true)return;
                if(coolDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }

                if(iot_frame.device_id != coo_par.filtId && coo_par.filtId != 0xFFFF)
                {
                    return;
                }



                str += QString("/ sensor_id:%1").arg(cool_frame_faca.sensorId);
                str += "=0x"+uint16ToHex(cool_frame_faca.sensorId).toUpper();
                str +="/ 冷链";
                double double_num;
                switch(cool_frame_faca.cmd)
                {
                    case coolCmdUnkown:
                    str +="/ coolCmdUnkown";
                    break;


                    case coolCmdGetDisNum:
                    str +="/ coolCmdGetDisNum：";
                    str +=QString("%1").arg(cool_frame_faca.data[0]*256+cool_frame_faca.data[1]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;




                    case coolCmdSetDisNum:
                    str +="/ coolCmdSetDisNum：";
                    str +=QString("%1").arg(cool_frame_faca.data[0]*256+cool_frame_faca.data[1]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;




                    case coolCmdAlarm:
                    str +="/ coolCmdAlarm:";
                    if(cool_frame_faca.data[0] == 0)str += "00 超过上限温度";
                    else if(cool_frame_faca.data[0] == 1)str += "01 低于下限温度";

                    if(cool_frame_faca.data[1] == 0)str += "/ +";
                    else if(cool_frame_faca.data[1] == 1)str += "/ -";
                    double_num = cool_frame_faca.data[2]*256+
                                cool_frame_faca.data[3]+
                                (double )cool_frame_faca.data[4]/100;
                    str += QString("%1'C").arg(double_num);
                    double_num = cool_frame_faca.data[5]+
                                (double )cool_frame_faca.data[6]/100;
                    str += QString("/ %1%H").arg(double_num);

                    //str += QString("%1.").arg(cool_frame_faca.data[2]*256+cool_frame_faca.data[3]);
                    //str += QString("%1'C").arg(cool_frame_faca.data[4],2,10);
                    //str += QString("/ %1.%2%H").arg(cool_frame_faca.data[5]).arg(cool_frame_faca.data[6]);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[7]).toUpper();
                    break;




                    case coolCmdDisarm:
                    str +="/ coolCmdDisarm";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;




                    case coolCmdSetRepTime:
                    str +="/ coolCmdSetRepTime:";
                    uint detect_time;
                    detect_time = (cool_frame_faca.data[0]<<24)+
                                  (cool_frame_faca.data[1]<<16)+
                                  (cool_frame_faca.data[2]<<8)+
                                  (cool_frame_faca.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(detect_time)+uint32ToHex(detect_time).toUpper()+"mS";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[4]).toUpper();
                    break;


                    case coolCmdTemVer:
                    str +="/ coolCmdTemVer";
                    if(cool_frame_faca.data[0] == 0)str +="/ +";
                    else if(cool_frame_faca.data[0] == 1)str +="/ -";
                    double_num = (double)cool_frame_faca.data[1]/10;
                    str += QString("%1'C").arg(double_num);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;



                    case coolCmdHumVer:
                    str +="/ coolCmdHumVer";
                    if(cool_frame_faca.data[0] == 0)str +="/ +";
                    else if(cool_frame_faca.data[0] == 1)str +="/ -";
                    double_num = (double)cool_frame_faca.data[1]/10;
                    str += QString("%1%H").arg(double_num);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;



                    case coolCmdGetSenVal:
                    str +="/ coolCmdGetSenVal";
                    if(cool_frame_faca.data[0] == 0)str += "/ +";
                    else if(cool_frame_faca.data[0] == 1)str += "/ -";
                    double_num = cool_frame_faca.data[1]*256+
                                cool_frame_faca.data[2]+
                                (double )cool_frame_faca.data[3]/100;
                    str += QString("%1'C").arg(double_num);
                    double_num = cool_frame_faca.data[4]+
                                (double )cool_frame_faca.data[5]/100;
                    str += QString("/ %1%H").arg(double_num);

                    //str += QString("%1.").arg(cool_frame_faca.data[1]*256+cool_frame_faca.data[2]);
                    //str += QString("%1'C").arg(cool_frame_faca.data[3],2,10);
                    //str += QString("/ %1.%2%H").arg(cool_frame_faca.data[4]).arg(cool_frame_faca.data[5],2,10);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[6]).toUpper();
                    break;




                    case coolCmdSetAlaVal:
                    str +="/ coolCmdSetAlaVal";
                    if(cool_frame_faca.data[0] == 0)str += "/ 上限温度：+";
                    else if(cool_frame_faca.data[0] == 1)str += "/ 上限温度：-";
                    double_num = cool_frame_faca.data[1]*256+
                                cool_frame_faca.data[2]+
                                (double )cool_frame_faca.data[3]/100;
                    str += QString("%1'C").arg(double_num);

                    //str += QString("%1.").arg(cool_frame_faca.data[1]*256+cool_frame_faca.data[2]);
                    //str += QString("%1'C").arg(cool_frame_faca.data[3],2,10);

                    if(cool_frame_faca.data[4] == 0)str += "/ 下限温度：+";
                    else if(cool_frame_faca.data[4] == 1)str += "/ 下限温度：-";
                    double_num = cool_frame_faca.data[5]*256+
                                cool_frame_faca.data[6]+
                                (double )cool_frame_faca.data[7]/100;
                    str += QString("%1'C").arg(double_num);

                    //str += QString("%1.").arg(cool_frame_faca.data[5]*256+cool_frame_faca.data[6]);
                    //str += QString("%1'C").arg(cool_frame_faca.data[7],2,10);
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[6]).toUpper();
                    break;



                    case coolCmdSenError:
                    str +="/ coolCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;
                    case coolCmdStatus:
                    str +="/ coolCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[1]).toUpper();
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
            else if(cool_frame_faca.deviceType == coolDevSiren)
            {

            }
            else if(cool_frame_faca.deviceType == coolDevSosPanic)
            {

            }
            else if(cool_frame_faca.deviceType == coolDevUnkown)
            {

            }
            else if(cool_frame_faca.deviceType == coolDevEnergy)
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



                str += QString("/ sensor_id:%1").arg(cool_frame_faca.sensorId);
                str += "=0x"+uint16ToHex(cool_frame_faca.sensorId).toUpper();
                str +="/ 插座";

                uint detect_u32;
                switch(cool_frame_faca.cmd)
                {
                    case energyCmdSetRepTime:
                    str +="/ energyCmdSetRepTime:";
                    detect_u32 = (cool_frame_faca.data[0]<<24)+
                                  (cool_frame_faca.data[1]<<16)+
                                  (cool_frame_faca.data[2]<<8)+
                                  (cool_frame_faca.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(detect_u32)+uint32ToHex(detect_u32).toUpper()+"mS";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[4]).toUpper();
                    break;


                    case energyCmdGetMeasurement:
                    str +="/ energyCmdGetMeasurement";


                    if(cool_frame_faca.len<0x12)
                    {
                        //220V
                        str +="/ 220V";


                        detect_u32 =  (cool_frame_faca.data[0]<<24)+
                                      (cool_frame_faca.data[1]<<16)+
                                      (cool_frame_faca.data[2]<<8)+
                                      (cool_frame_faca.data[3]<<0);
                        str +=QString("/ 电压：%1V").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame_faca.data[4]<<24)+
                                      (cool_frame_faca.data[5]<<16)+
                                      (cool_frame_faca.data[6]<<8)+
                                      (cool_frame_faca.data[7]<<0);
                        str +=QString("/ 电流：%1A").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame_faca.data[8]<<24)+
                                      (cool_frame_faca.data[9]<<16)+
                                      (cool_frame_faca.data[10]<<8)+
                                      (cool_frame_faca.data[11]<<0);
                        str +=QString("/ 功率：%1W").arg((double)detect_u32/10000);

                        detect_u32 =  (cool_frame_faca.data[12]<<24)+
                                      (cool_frame_faca.data[13]<<16)+
                                      (cool_frame_faca.data[14]<<8)+
                                      (cool_frame_faca.data[15]<<0);
                        str +=QString("/ 电量：%1KW/H").arg((double)detect_u32/10000);
                    }
                    else
                    {
                        //380V
                        str +="/ 380V";

                        //A
                        detect_u32 =  (cool_frame_faca.data[0]<<8)+
                                      (cool_frame_faca.data[1]<<0);
                        str +=QString("/ A电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[2]<<8)+
                                      (cool_frame_faca.data[3]<<0);
                        str +=QString("/ A电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[4]<<8)+
                                      (cool_frame_faca.data[5]<<0);
                        str +=QString("/ A功率：%1W").arg((double)detect_u32);

                        detect_u32 =  (cool_frame_faca.data[6]<<24)+
                                      (cool_frame_faca.data[7]<<16)+
                                      (cool_frame_faca.data[8]<<8)+
                                      (cool_frame_faca.data[9]<<0);
                        str +=QString("/ A电量：%1KWH").arg((double)detect_u32/800);

                        //B
                        detect_u32 =  (cool_frame_faca.data[10]<<8)+
                                      (cool_frame_faca.data[11]<<0);
                        str +=QString("/ B电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[12]<<8)+
                                      (cool_frame_faca.data[13]<<0);
                        str +=QString("/ B电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[14]<<8)+
                                      (cool_frame_faca.data[15]<<0);
                        str +=QString("/ B功率：%1W").arg((double)detect_u32);

                        detect_u32 =  (cool_frame_faca.data[16]<<24)+
                                      (cool_frame_faca.data[17]<<16)+
                                      (cool_frame_faca.data[18]<<8)+
                                      (cool_frame_faca.data[19]<<0);
                        str +=QString("/ B电量：%1KWH").arg((double)detect_u32/800);

                        //C
                        detect_u32 =  (cool_frame_faca.data[20]<<8)+
                                      (cool_frame_faca.data[21]<<0);
                        str +=QString("/ C电压：%1V").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[22]<<8)+
                                      (cool_frame_faca.data[23]<<0);
                        str +=QString("/ C电流：%1A").arg((double)detect_u32/100);

                        detect_u32 =  (cool_frame_faca.data[24]<<8)+
                                      (cool_frame_faca.data[25]<<0);
                        str +=QString("/ C功率：%1W").arg((double)detect_u32);

                        detect_u32 =  (cool_frame_faca.data[26]<<24)+
                                      (cool_frame_faca.data[27]<<16)+
                                      (cool_frame_faca.data[28]<<8)+
                                      (cool_frame_faca.data[29]<<0);
                        str +=QString("/ C电量：%1KWH").arg((double)detect_u32/800);


                        detect_u32 =  (cool_frame_faca.data[30]<<24)+
                                      (cool_frame_faca.data[31]<<16)+
                                      (cool_frame_faca.data[32]<<8)+
                                      (cool_frame_faca.data[33]<<0);
                        str +=QString("/ 总电量：%1KWH").arg((double)detect_u32/800);

                    }



                    break;



                    case energyCmdSenError:
                    str +="/ energyCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;
                    case energyCmdStatus:
                    str +="/ energyCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[1]).toUpper();
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
            else if(cool_frame_faca.deviceType == coolDevInjection)
            {
                if(cool_frame_faca.cmd != 0xFE)INJ_ackSuccess(iot_frame.gateway_id,iot_frame.device_id,cool_frame_faca.cmd);
                if(injectionStopDisplay->isChecked() == true)return;
                if(injectionDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }
                if(iot_frame.device_id != inj_par.filtId && inj_par.filtId != 0xFFFF)
                {
                    return;
                }


                str += QString("/ sensor_id:%1").arg(cool_frame_faca.sensorId);
                str += "=0x"+uint16ToHex(cool_frame_faca.sensorId).toUpper();
                str +="/ 移动输液";

                switch(cool_frame_faca.cmd)
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

                    str +=QString("/ %1滴/min ").arg(cool_frame_faca.data[0]);

                    if(cool_frame_faca.data[1] == 0)str +="/ 喇叭关闭";
                    else if(cool_frame_faca.data[1] == 1)str +="/ 喇叭打开";
                    else str +="/ 喇叭状态未知";

                    str +=QString("/ 显示编号为：%1").arg(cool_frame_faca.data[2]*256+cool_frame_faca.data[3]);

                    if(cool_frame_faca.data[4] == 0) str +=QString("/ 无告警：%1").arg(cool_frame_faca.data[4]);
                    else if(cool_frame_faca.data[4] == 1) str +=QString("/ 低限告警：%1").arg(cool_frame_faca.data[4]);
                    else if(cool_frame_faca.data[4] == 2) str +=QString("/ 高限告警：%1").arg(cool_frame_faca.data[4]);
                    else if(cool_frame_faca.data[4] == 3) str +=QString("/ 设备节流：%1").arg(cool_frame_faca.data[4]);
                    else if(cool_frame_faca.data[4] == 4) str +=QString("/ 输液暂停：%1").arg(cool_frame_faca.data[4]);
                    else if(cool_frame_faca.data[4] == 5) str +=QString("/ 输液完成：%1").arg(cool_frame_faca.data[4]);
                    else str +=QString("/ 未知状态：%1").arg(cool_frame_faca.data[4]);


                    str +=QString("/ 总滴数量：%1").arg(cool_frame_faca.data[5]*256+cool_frame_faca.data[6]);

                    str +=QString("/ 上限：%1 下限：%2").arg(cool_frame_faca.data[7]).arg(cool_frame_faca.data[8]);
\
                    str +=QString("/ 电量：%1%").arg(cool_frame_faca.data[9]);
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

                    if(cool_frame_faca.data[0] == injectionCmdGetDeviceParameter)
                    {
                        str +="/ injectionCmdGetDeviceParameter";

                        if(cool_frame_faca.data[1]==0x00)str +="/ 关机状态";
                        else if(cool_frame_faca.data[1]==0x01)str +="/ 开机状态";
                        else if(cool_frame_faca.data[1]==0x02)str +="/ 正在输液";
                        else if(cool_frame_faca.data[1]==0x03)str +="/ 输液暂停";
                        else if(cool_frame_faca.data[1]==0x04)str +="/ 输液完成";


                        str +=QString("/ normal:%1滴/S max:%2滴/S min:%3滴/S").arg(cool_frame_faca.data[2]).arg(cool_frame_faca.data[3]).arg(cool_frame_faca.data[4]);


                        if(cool_frame_faca.data[5]==0x00)str +="/ 喇叭关闭";
                        else if(cool_frame_faca.data[5]==0x01)str +="/ 喇叭打开";

                        str +=QString("/ 显示编号%1").arg(cool_frame_faca.data[6]*256+cool_frame_faca.data[7]);


                        uint injection_report_time;
                        injection_report_time = (cool_frame_faca.data[8]<<24)+
                                                (cool_frame_faca.data[9]<<16)+
                                                (cool_frame_faca.data[10]<<8)+
                                                (cool_frame_faca.data[11]<<0);
                        str +=QString("/ 上报时间%1").arg(injection_report_time);


                        if(cool_frame_faca.data[12] == 0) str +=QString("/ 无告警：%1").arg(cool_frame_faca.data[12]);
                        else if(cool_frame_faca.data[12] == 1) str +=QString("/ 低限告警：%1").arg(cool_frame_faca.data[12]);
                        else if(cool_frame_faca.data[12] == 2) str +=QString("/ 高限告警：%1").arg(cool_frame_faca.data[12]);
                        else str +=QString("/ 未知状态：%1").arg(cool_frame_faca.data[12]);

                        str +=QString("/ 当前滴速%1").arg(cool_frame_faca.data[13]);
                        str +=QString("/ 电机状态%1").arg(cool_frame_faca.data[14]);
                        str +=QString("/ 输液状态%1").arg(cool_frame_faca.data[15]);
                        str +=QString("/ 累积滴量%1").arg(cool_frame_faca.data[16]*256+cool_frame_faca.data[17]);
                        str +=QString("/ 总滴量%1").arg(cool_frame_faca.data[18]*256+cool_frame_faca.data[19]);
                        str +=QString("/ 检测时长%1").arg(cool_frame_faca.data[20]*256+cool_frame_faca.data[21]);


                    }
                    else
                    {
                        str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[0]).toUpper();
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
            else if(cool_frame_faca.deviceType == coolDevSosNoLocationPanic)
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



                str += QString("/ sensor_id:%1").arg(cool_frame_faca.sensorId);
                str += "=0x"+uint16ToHex(cool_frame_faca.sensorId).toUpper();
                str +="/ SOS按键(不带定位)";

                uint32_t sos_report_time = 0;
                switch(cool_frame_faca.cmd)
                {
                    case sosCmdSetRepTime:
                    str +="/ sosCmdSetRepTime:";
                    sos_report_time = (cool_frame_faca.data[0]<<24)+
                                  (cool_frame_faca.data[1]<<16)+
                                  (cool_frame_faca.data[2]<<8)+
                                  (cool_frame_faca.data[3]<<0);
                    str +=QString("%1mS = 0x").arg(sos_report_time)+uint32ToHex(sos_report_time).toUpper()+"mS";

                    break;


                    case sosCmdReportStatus:
                    str +="/ sosCmdReportStatus";

                    str +=QString("/ voltage:%1.").arg(cool_frame_faca.data[0]/10)+QString("%1V").arg(cool_frame_faca.data[0]%10);

                    if(cool_frame_faca.data[1]&BV(0))str +="/ 按键报警";
                    if(cool_frame_faca.data[1]&BV(1))str +="/ 不要拆报警";

                    sos_report_time = (cool_frame_faca.data[2]<<24)+
                                  (cool_frame_faca.data[3]<<16)+
                                  (cool_frame_faca.data[4]<<8)+
                                  (cool_frame_faca.data[5]<<0);
                    str +=QString("/ ReportTime:%1mS").arg(sos_report_time);


                    break;

                    case sosCmdSenError:
                    str +="/ sosCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[2]).toUpper();
                    break;
                    case sosCmdStatus:
                    str +="/ sosCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame_faca.data[1]).toUpper();
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
        else if(iot_frame.data[0]==0xAA && iot_frame.data[1]==0x55)
        {


            cool_frame.head[0] = iot_frame.data[0];
            cool_frame.head[1] = iot_frame.data[1];
            cool_frame.sensorMac[0] = iot_frame.data[2];
            cool_frame.sensorMac[1] = iot_frame.data[3];
            cool_frame.sensorMac[2] = iot_frame.data[4];
            cool_frame.sensorMac[3] = iot_frame.data[5];
            cool_frame.sensorMac[4] = iot_frame.data[6];
            cool_frame.sensorMac[5] = iot_frame.data[7];
            cool_frame.sensorMac[6] = iot_frame.data[8];
            cool_frame.sensorMac[7] = iot_frame.data[9];

            cool_frame.deviceType = iot_frame.data[10];
            cool_frame.len = iot_frame.data[11];
            cool_frame.cmd = iot_frame.data[12];
            cool_frame.data = &iot_frame.data[13];
            cool_frame.checksum = iot_frame.data[12+cool_frame.len];

            if(checkSum((char *)(iot_frame.data),cool_frame.len+12)!= cool_frame.checksum)
            {
                return ;
            }



            if(cool_frame.deviceType == coolDevCoolChain)
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



                str += "/ sensorMac:"+ strToHex(cool_frame.sensorMac,8);
                str +="/ 冷链";
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
            else if(cool_frame.deviceType == coolDevTemTh)
            {
                //if(cool_frame.cmd != 0xFE)COO_ackSuccess(iot_frame.gateway_id,iot_frame.device_id,cool_frame.cmd);
                if(TemTHStopDisplay->isChecked() == true)return;
                if(TemTHDisplayMac->isChecked() == true)
                {
                    str += "/ device_MAC:"+id_access.getIdMac(iot_frame.device_id);

                }

                if(iot_frame.device_id != temth_par.filtId && temth_par.filtId != 0xFFFF)
                {
                    return;
                }



                str += "/ sensorMac:"+ strToHex(cool_frame.sensorMac,8).toUpper();
                str +="/ 温湿度传感器";
                double double_num;
                switch(cool_frame.cmd)
                {
                    case TemThCmdSetRepTime:
                    str +="/ TemThCmdSetRepTime:";
                    uint detect_time;
                    detect_time =
                                  (cool_frame.data[0]<<8)+
                                  (cool_frame.data[1]<<0);
                    str +=QString("%1mS = 0x").arg(detect_time)+uint32ToHex(detect_time).toUpper()+"mS";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[3]).toUpper();
                    break;


                    case TemThCmdGetSenVal:
                    str +="/ TemThCmdGetSenVal";

                    //tempreture
                    if(cool_frame.data[0] == 0)str += "/ -";
                    else if(cool_frame.data[0] == 1)str += "/ +";
                    double_num = cool_frame.data[1]*256+cool_frame.data[2]+(double )cool_frame.data[3]/100;
                    str += QString("%1'C").arg(double_num);

                    //humidity
                    double_num = cool_frame.data[4]+(double )cool_frame.data[5]/100;
                    str += QString("/ %1%RH").arg(double_num);

                    //voltage
                    double_num = (double )cool_frame.data[6]/10;
                    str += QString("/ %1V").arg(double_num);

                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[7]).toUpper();

                    break;

                    case TemThCmdSystemTime:
                    str +="/ TemThCmdSystemTime：request system time";
                    TEMTH_setSystemTime(iot_frame.gateway_id,iot_frame.device_id,cool_frame.sensorMac);
                    break;



                    case TemThCmdSenError:
                    str +="/ coolCmdSenError";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[2]).toUpper();
                    break;
                    case TemThCmdStatus:
                    str +="/ coolCmdStatus";
                    str +="/ status code:0x" + uint8ToHex(cool_frame.data[1]).toUpper();
                    break;
                    default:
                    str +="/ ERROR";
                    break;
                }
                if(temth_par.filtStr.length()!=0)
                {

                    if(str.contains(temth_par.filtStr) == false)
                    return;
                }
                TEMTH_DisplayWithTime(str);

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



                str += "/ sensorMac:"+ strToHex(cool_frame.sensorMac,8);
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


                str += "/ sensorMac:"+ strToHex(cool_frame.sensorMac,8);
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



                str += "/ sensorMac:"+ strToHex(cool_frame.sensorMac,8);
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
            str += "patientSpireLamella";
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
        case dev_863DriectModule:
            str += "863DriectModule";
            break;
        case dev_863ORModule:
            str += "863ORModule";
            break;
        case dev_863PDA:
            str += "863PDA";
            break;
        case dev_863DesktopRW:
            str += "863DesktopRW";
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
    else if(iot_frame.cmd == cmd_bleData){

    }
}


void MainWindow::processJsonData(QByteArray datas){
    QJsonParseError jsonError;
    QJsonValue value;
    QJsonObject object;
    QString str;
    QJsonArray array;
    QJsonDocument document = QJsonDocument::fromJson(datas, &jsonError);  // 转化为 JSON 文档
    if (!document.isNull() && (jsonError.error == QJsonParseError::NoError)) {  // 解析未发生错误
        if (document.isObject()) {  // JSON 文档为对象
            object = document.object();  // 转化为对象
            if(object.contains("cmd")){//命令
                value = object.value("cmd");
                str = value.toString();
                if(str == "device_par"){//设备参数
                    if(object.contains("operation")) {
                        value = object.value("operation");
                        if(value.isString() && value.toString()=="w_req") {//写请求
                            if (object.contains("par")) {
                                value = object.value("par");
                                if (value.isArray()) {//数组
                                    array = value.toArray();
                                    int nSize = array.size();
                                    for (int i = 0; i < nSize; ++i) {//遍历数组
                                        value = array.at(i);
                                        if (value.isObject()) {//
                                            DEVICE_DISPLAY_PAR *dev_par = NULL;
                                            ushort dev_id;
                                            object = value.toObject();
                                            if (object.contains("dev")) {
                                                value = object.value("dev");
                                                if (value.isString()==false || value.toString() != "ant") {
                                                    return;
                                                }
                                            }
                                            else return;


                                            //get id
                                            if (object.contains("id")) {
                                                value = object.value("id");
                                                if (value.isDouble()) {
                                                    dev_id = value.toVariant().toByteArray().toUShort();
                                                }
                                                else return;
                                            }
                                            else return;

                                            for(int j=0;j<DEVICE_DISPLAY_MAX;j++){
                                                if(display_par.ant[j].id == dev_id){
                                                    dev_par = &display_par.ant[j];
                                                    break;
                                                }
                                            }

                                            if(dev_par == NULL){
                                                for(int j=0;j<DEVICE_DISPLAY_MAX;j++){
                                                    if(display_par.ant[j].id == 0xFFFF){
                                                        dev_par = &display_par.ant[j];
                                                        break;
                                                    }
                                                }
                                            }
                                            if(dev_par != NULL){
                                                dev_par->id = dev_id;
                                            }
                                            else return;

                                            if (object.contains("x_point")) {
                                                value = object.value("x_point");
                                                if (value.isDouble()) {
                                                    dev_par->x = value.toVariant().toByteArray().toShort();
                                                }
                                            }

                                            if (object.contains("y_point")) {
                                                value = object.value("y_point");
                                                if (value.isDouble()) {
                                                    dev_par->y = value.toVariant().toByteArray().toShort();
                                                }
                                            }

                                            if (object.contains("offset")) {
                                                value = object.value("offset");
                                                if (value.isDouble()) {
                                                    dev_par->rssi_offset = value.toVariant().toByteArray().toShort();
                                                }
                                            }

                                            if (object.contains("mac")) {
                                                value = object.value("mac");
                                                if (value.isString()&&value.toString().length() == 16) {
                                                    str = value.toString();
                                                    dev_par->mac[0] = hexToUint8(str,0);
                                                    dev_par->mac[1] = hexToUint8(str,2);
                                                    dev_par->mac[2] = hexToUint8(str,4);
                                                    dev_par->mac[3] = hexToUint8(str,6);
                                                    dev_par->mac[4] = hexToUint8(str,8);
                                                    dev_par->mac[5] = hexToUint8(str,10);
                                                    dev_par->mac[6] = hexToUint8(str,12);
                                                    dev_par->mac[7] = hexToUint8(str,14);
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        else if(value.isString() && value.toString()=="w_res"){

                        }
                        else if(value.isString() && value.toString()=="r_req"){
                            //read request ,it will return the device par
                        }
                        else if(value.isString() && value.toString()=="r_res"){

                        }
                    }
                }
                else if(str == "algorithm_par"){//设备参数
                    if(object.contains("operation")) {
                        value = object.value("operation");
                        if(value.isString() && value.toString()=="w_req") {//写请求

                        }
                        else if(value.isString() && value.toString()=="w_res"){

                        }
                        else if(value.isString() && value.toString()=="r_req"){

                        }
                        else if(value.isString() && value.toString()=="r_res"){
                            if(object.contains("translate")){
                                value = object.value("translate");
                                if(value.isBool()){
                                    ble_algorithm.par.translate = value.toBool();
                                }
                            }
                            if(object.contains("translate center")){
                                value = object.value("translate center");
                                if(value.isBool()){
                                    ble_algorithm.par.translate_center = value.toBool();
                                }
                            }
                            if(object.contains("filter")){
                                value = object.value("filter");
                                if(value.isBool()){
                                    ble_algorithm.par.filter = value.toBool();
                                }
                            }
                            if(object.contains("limit xy")){
                                value = object.value("limit xy");
                                if(value.isBool()){
                                    ble_algorithm.par.limit_xy = value.toBool();
                                }
                            }
                            if(object.contains("limit r")){
                                value = object.value("limit r");
                                if(value.isBool()){
                                    ble_algorithm.par.limit_r = value.toBool();
                                }
                            }
                            if (object.contains("compare")) {
                                value = object.value("compare");
                                if (value.isDouble()) {
                                    ble_algorithm.par.compare = value.toDouble();
                                }
                            }
                        }
                    }
                }
            }
        }
        else if(document.isArray()){
            array = document.array();
            int nSize = array.size();
            for (int i = 0; i < nSize; ++i) {//遍历数组
                value = array.at(i);
                if(value.isObject()){
                    object = value.toObject();
                    if(object.contains("AntData")){
                        value = object.value("AntData");
                        if(value.isArray()){
                            QJsonArray antArray = value.toArray();
                            int antSize = antArray.size();
                            for(int j=0;j<antSize;j++){
                                value = antArray.at(j);
                                if(value.isObject()){
                                    DEVICE_DISPLAY_PAR *dev_par = NULL;
                                    ushort dev_id;
                                    object = value.toObject();
                                    //get id
                                    if (object.contains("HardID")) {
                                        value = object.value("HardID");
                                        if (value.isDouble()) {
                                            dev_id = value.toVariant().toByteArray().toUShort();
                                        }
                                        else return;
                                    }
                                    else return;

                                    for(int j=0;j<DEVICE_DISPLAY_MAX;j++){
                                        if(display_par.ant[j].id == dev_id){
                                            dev_par = &display_par.ant[j];
                                            break;
                                        }
                                    }

                                    if(dev_par == NULL){
                                        for(int j=0;j<DEVICE_DISPLAY_MAX;j++){
                                            if(display_par.ant[j].id == 0xFFFF){
                                                dev_par = &display_par.ant[j];
                                                break;
                                            }
                                        }
                                    }
                                    if(dev_par != NULL){
                                        dev_par->id = dev_id;
                                    }
                                    else return;

                                    if (object.contains("X")) {
                                        value = object.value("X");
                                        if (value.isDouble()) {
                                            dev_par->x = value.toVariant().toByteArray().toShort();
                                        }
                                    }

                                    if (object.contains("Y")) {
                                        value = object.value("Y");
                                        if (value.isDouble()) {
                                            dev_par->y = value.toVariant().toByteArray().toShort();
                                        }
                                    }

                                    if (object.contains("AntID")) {
                                        value = object.value("AntID");
                                        if (value.isDouble()) {
                                            //dev_par->AntID = value.toVariant().toByteArray().toUShort();
                                        }
                                    }
                                    if (object.contains("AntName")) {
                                        value = object.value("AntName");
                                        if (value.isString()) {
                                            //dev_par->AntName = value.toString();
                                        }
                                    }
                                    if (object.contains("Kind")) {
                                        value = object.value("Kind");
                                        if (value.isDouble()) {
                                            //dev_par->Kind = value.toVariant().toByteArray().toUShort();
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else if(value.isString()){
                    if(value.toString() == "GetAnt"){
                        IOT_sendAntInformation(net_par.locationSocket);
                    }
                }
            }
        }
    }
    else {
        NET_DisplayWithNoTime(jsonError.errorString());

        LOCATION_FRAME location_frame;
        if((uchar)datas[0]==0xA5 && (uchar)datas[1]==0x5A && datas.length()==0x09)//no rssi
        {
            //新腕带程序
            location_frame.head[0] = (uchar)datas[0];
            location_frame.head[1] = (uchar)datas[1];
            location_frame.devie_id = (uchar)datas[2]*256+(uchar)datas[3];
            location_frame.ant_id = (uchar)datas[4]*256+(uchar)datas[5];
            location_frame.rssi = (char)datas[6];
            location_frame.alarm = (uchar)datas[7];
            location_frame.checksum = (uchar)datas[8];


            QByteArray buff = datas;
            buff.remove(0,2);
            if(checkSum(buff,6)!= location_frame.checksum)
            {
                return ;
            }

            if(locationStopDisplay->isChecked() == true)return;
            if(locationDisplayMac->isChecked() == true)
            {
                str += "/ device_MAC:"+id_access.getIdMac(location_frame.devie_id);

            }

            if( location_frame.devie_id != loc_par.filtId[0]&&
                location_frame.devie_id != loc_par.filtId[1]&&
                location_frame.devie_id != loc_par.filtId[2]&&
                location_frame.devie_id != loc_par.filtId[3]&&
                location_frame.devie_id != loc_par.filtId[4])
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
            str += QString("/ rssi:%1").arg(location_frame.rssi);
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


            for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                //clear last location data
                if(display_par.device[j].id == location_frame.devie_id){
                    display_par.device[j].id = 0xFFFF;
                    display_par.device[j].x = 0;
                    display_par.device[j].y = 0;
                    display_par.device[j].radius = 0x00;
                    display_par.device[j].rssi_offset = 0x00;
                    display_par.device[j].color = Qt::white;
                    display_par.device[j].displayInfFlag = false;
                    memset(display_par.device[j].mac,0x00,8);
                }
            }
            for(int j = 0;j<DEVICE_DISPLAY_MAX;j++){
                //clear last location data
                if(display_par.device[j].id == 0xFFFF){
                    display_par.device[j].id = location_frame.devie_id;
                    display_par.device[j].x = location_frame.ant_id/256;
                    display_par.device[j].y = location_frame.ant_id%256;
                    display_par.device[j].radius = 0x00;
                    display_par.device[j].rssi_offset = 0x00;
                    display_par.device[j].color = Qt::darkBlue;
                    display_par.device[j].displayInfFlag = false;
                    memset(display_par.device[j].mac,0x00,8);
                    break;
                }
            }

            BLE_displayUpdate();
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

ushort MainWindow::hexToUint8(QString str,uint start){
    str.remove(0,start);
    str.remove(2,str.length());
    return str.toUShort(Q_NULLPTR,16);
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
//和校验
uchar MainWindow::checkSum(QByteArray puchData, ushort len)
{
    uchar crc8 = 0;
    ushort i=0;
    while (len--)
    {
        crc8 = crc8 + puchData[i++];
    }
    return crc8;
}

//---------------------------------------------------------------------------




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


    if(comunication_protocal->currentText() == "Server")
    {
        //NET_getBindSocket(id->device_id);
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


    if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(ptr->device_id);
        NET_send(buff);
    }
}


void  MainWindow::IOT_cmdHeartBeat(ushort gateway_id,
                                   ushort device_id,
                                   ushort time,
                                   ushort bandwith,
                                   short rssi
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


    if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(buff);
    }

}




QByteArray MainWindow::IOT_cmdNetwork(ushort gateway_id,ushort device_id,QByteArray data)
{

    QByteArray send_buff;

    if(rf_send.sequence==255)rf_send.sequence=0;
    else rf_send.sequence++;


    if(shortAddr->currentRow()<0)
    {
        DisplayWithTime("please select addr ");
        send_buff.clear();
        return send_buff;
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



    if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(send_buff);
    }
    return send_buff;
}


QByteArray MainWindow::IOT_cmdApp(ushort gateway_id,ushort device_id,QByteArray data)
{

    QByteArray send_buff;



    if(shortAddr->currentRow()<0)
    {
        DisplayWithTime("please select addr ");
        send_buff.clear();
        return send_buff;
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



    if(comunication_protocal->currentText() == "Server")
    {
        NET_getBindSocket(device_id);
        NET_send(send_buff);
    }
    return send_buff;
}



void MainWindow::NET_TCPIP_SocketSend(QByteArray src,QTcpSocket *socket)
{
    QString str;
    if(socket == NULL){
        NET_DisplayWithTime("error:socket == NULL");
        return;
    }
    if(socket->state()==QAbstractSocket::ConnectedState)
    {
        socket->write(src);
        str = "Socket send message to IP:"+socket->peerAddress().toString();
        str += QString("PORT:%1").arg(socket->peerPort());
        str +=QString("  %1 byte").arg(src.length());
        NET_DisplayWithTime(str);


        str = src.toHex().toUpper();
        for(ushort i =0; i*3<str.length();i++)
        {
            str.insert(i*3+2, " ");
        }
        NET_DisplayWithTime(src);
        NET_DisplayWithTime(str.toUpper());

    }
}

void MainWindow::IOT_sendIdInformation(ushort id,QTcpSocket *socket){
 /***************************************************************************/

    QJsonObject device;// 构建 Json 对象
    QJsonArray par;// 构建 Json 数组 - Version
    QJsonObject json;// 构建 Json 对象
    QJsonDocument document;// 构建 Json 文档


    if(id !=0xFFFF){
        for(ushort i = 0;i<DEVICE_DISPLAY_MAX;i++){
            if(display_par.ant[i].id == id){
                device.insert("dev", "ant");
                device.insert("x_point", display_par.ant[i].x);
                device.insert("y_point", display_par.ant[i].y);
                device.insert("id", display_par.ant[i].id);
                device.insert("mac", strToHex( display_par.ant[i].mac,8).toUpper());
                device.insert("offset",display_par.ant[i].rssi_offset);
                par.append(device);
                goto BLE_sendIdInformation_document;
            }
        }
        for(ushort i = 0;i<DEVICE_DISPLAY_MAX;i++){
            if(display_par.device[i].id == id){
                device.insert("dev", "ant");
                device.insert("x_point", display_par.device[i].x);
                device.insert("y_point", display_par.device[i].y);
                device.insert("id", display_par.device[i].id);
                device.insert("mac", strToHex( display_par.device[i].mac,8).toUpper());
                device.insert("offset",display_par.device[i].rssi_offset);
                par.append(device);
                goto BLE_sendIdInformation_document;
            }
        }
    }

BLE_sendIdInformation_document:


    json.insert("cmd","device_par");
    json.insert("operation","w_req");
    json.insert("par",QJsonValue(par));


    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    //NET_DisplayWithNoTime(byteArray);
    NET_TCPIP_SocketSend(byteArray,socket);

}


void MainWindow::IOT_sendAntInformation(QTcpSocket *socket){
 /***************************************************************************/
    QJsonArray antArray;// 构建 Json 数组 - Version
    QJsonArray dataArray;// 构建 Json 数组 - Version
    QJsonObject antObject;// 构建 Json 对象
    QJsonObject dataObject;// 构建 Json 数组 - Version
    QJsonDocument document;// 构建 Json 文档





    for(ushort i = 0;i<DEVICE_DISPLAY_MAX;i++){
        if(display_par.ant[i].id != 0xFFFF){
            dataObject.empty();
            display_par.ant[i].id  = id_access.getIdMac(display_par.ant[i].mac);
            dataObject.insert("mac",strToHex(display_par.ant[i].mac,8));
            dataObject.insert("AntID", 99);
            dataObject.insert("AntName", 001);
            dataObject.insert("Kind", 3);
            dataObject.insert("X", display_par.ant[i].x);
            dataObject.insert("Y", display_par.ant[i].y);
            dataObject.insert("HardID",QString("%1").arg(display_par.ant[i].id));
            dataObject.insert("offset",display_par.ant[i].rssi_offset);
            dataArray.append(dataObject);
        }
    }


    antObject.insert("MapID",20);
    antObject.insert("MapName","map1");
    antObject.insert("ImageWidth",1609);
    antObject.insert("ImageHeight",861);
    antObject.insert("ActualWidth",16000);
    antObject.insert("ActualHeight",8600);
    antObject.insert("AntData",dataArray);


    antArray.append(antObject);


    document.setArray(antArray);
    QByteArray byteArray = document.toJson(QJsonDocument::Indented);
    NET_TCPIP_SocketSend(byteArray,socket);

}

void MainWindow::IOT_sendAlgorithm(QTcpSocket *socket){
 /***************************************************************************/
    QJsonObject json;
    QJsonDocument document;
    QByteArray byteArray;

    if(BLE_attenuationcheckBox->isChecked())ble_algorithm.par.translate = true;
    else ble_algorithm.par.translate = false;
    if(BLE_attenuationWithoutCentercheckBox->isChecked())ble_algorithm.par.translate_center = true;
    else ble_algorithm.par.translate_center = false;
    if(BLE_FiltercheckBox->isChecked())ble_algorithm.par.filter = true;
    else ble_algorithm.par.filter = false;
    if(BLE_xyPointCheckBox->isChecked())ble_algorithm.par.limit_xy = true;
    else ble_algorithm.par.limit_xy = false;
    if(BLE_radiusCheckBox->isChecked())ble_algorithm.par.limit_r = true;
    else ble_algorithm.par.limit_r = false;


    json.insert("cmd","algorithm_par");
    json.insert("operation","w_req");
    json.insert("translate",ble_algorithm.par.translate);
    json.insert("translate center",ble_algorithm.par.translate_center);
    json.insert("filter",ble_algorithm.par.filter);
    json.insert("limit xy",ble_algorithm.par.limit_xy);
    json.insert("limit r",ble_algorithm.par.limit_r);
    json.insert("compare",ble_algorithm.par.ratio);

    document.setObject(json);
    byteArray = document.toJson(QJsonDocument::Compact);
    //NET_DisplayWithNoTime(byteArray);
    NET_TCPIP_SocketSend(byteArray,socket);
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

    str = textEdit_heartbeat_time->text();
    time = str.toUShort();


    QByteArray buff;
    buff.clear();
    buff[0] = r_setHeartbeat;
    buff[1] = (time>>8)&0xFF;
    buff[2] = (time>>0)&0xFF;
    IOT_cmdNetwork(gateway_id,device_id,buff);
    LOC_DisplayWithTime(QString("set heartbeat time：%1 S").arg(time));
}


void MainWindow::rcmdRssiAckTest(ushort gateway_id,ushort device_id,short dBm)
{
    QByteArray buff;
    buff.clear();
//    buff[0] = 0xDB;
//    buff[1] = 0xBD;
    buff[0] = test_txPower;
    buff[1] = 0xFF;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = 0xFF;
    buff[5] = 0xFF;
    buff[6] = 0xFF;
    buff[7] = 0xFF;
    buff[8] = 0xFF;
    buff[9] = (char)dBm;
    buff[10] = 0;
    buff[10] = checkSum(buff,10);
    buff.insert(0,0xDB);
    buff.insert(1,0xBD);
    IOT_cmdApp(gateway_id,device_id,buff);
    LOC_DisplayWithTime(QString("send gateway tx power = %1dBm to device").arg(dBm));
}



void MainWindow::rcmdSetNetPar(ushort gateway_id,ushort device_id)
{
    QByteArray buff;
    QString str;

    ushort panId;
    ushort shortId;
    char power;
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
            power = str.toShort(Q_NULLPTR,10);
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
                else if(cb_deviceType->currentText()  == "PDA863模块")fir.ota_w.device_type = 0x0F;
                else if(cb_deviceType->currentText()  == "桌面读卡器863模块")fir.ota_w.device_type = 0x10;
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
    else if(cb_deviceType->currentText() == "蓝牙透传863模块")fir.ota_w.device_type = 0x0D;
    else if(cb_deviceType->currentText() == "手术室863模块")fir.ota_w.device_type = 0x0E;
    else if(cb_deviceType->currentText() == "PDA863模块")fir.ota_w.device_type = 0x0F;
    else if(cb_deviceType->currentText() == "桌面读卡器863模块")fir.ota_w.device_type = 0x10;
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
    localtionFiltId_4->setText(shortAddr->item(i)->text());
    BLE_FiltId_4->setText(shortAddr->item(i)->text());
    sosFiltId->setText(shortAddr->item(i)->text());
    injectionFiltId->setText(shortAddr->item(i)->text());
    energyFiltId->setText(shortAddr->item(i)->text());
    TemTHFiltId->setText(shortAddr->item(i)->text());
    coolFiltId->setText(shortAddr->item(i)->text());
    localtionFiltId_4->setText(shortAddr->item(i)->text());
    localtionFiltId_4->setText(shortAddr->item(i)->text());
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
    textEdit_IP->setText(str);
    textEdit_Port->setText("6002");
    textEdit_IP_location->setText(str);
    textEdit_Port_location->setText("5999");


    textEdit_ID->setPlainText("0");
    textEdit_ID2->setText("0");
    bt_stopListen->setDisabled(true);
    bt_stopListen_location->setDisabled(true);

    for(i=0;i<SOCKET_MAX;i++)
    {
        net_par.Socket[i]=NULL;
    }
    net_par.Server=NULL;
    net_par.locationServer = NULL;

    for(i=0;i<65536;i++)
    {
        net_par.bind_socket[i] = NULL;
    }
    comunication_protocal->setCurrentText("Server");

    net_par.Server = new QTcpServer(this);
    connect(net_par.Server,SIGNAL(newConnection()),this,SLOT(NET_acceptConnection()));

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
           infReceive->setText(display);




           for(i = 0; i < datas.length();i++)
           {
               transport.receive[transport.r_count] = datas[i];
               transport.r_count++;
           }
           //receiveTimer->start(20);
           pressUartData(net_par.Socket[j]);

       }
   }

}


void MainWindow::NET_revDataLocation()

{

   ushort i;
   QByteArray display;
   QByteArray datas;


   datas.clear();
   datas = net_par.locationSocket->readAll();
   if(datas.length() == 0)return;



   QString str = "location receive data from";
   str += "  IP:" + net_par.locationSocket->peerAddress().toString();
   str += QString("  PORT:%1").arg(net_par.locationSocket->peerPort());
   str += "\r\n"+datas;

   //接收字符串数据。
   display = datas.toHex().toUpper();
   for(i=0;i<display.length();i+=3){
       display.insert( i+2, " ");
   }

   NET_DisplayWithTime(str);
   NET_DisplayWithNoTime(display);

   processJsonData(datas);

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

        if(net_par.currentSocket == NULL )
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
    infEdit->setText(str);



    if(rb_displayRawHex->isChecked()==true)
    {
        DisplayWithTime(QString("tcp/ip send %1 byte").arg(src.length()));
        textBr_mess->append(str.toUpper()+"\r\n");
        history_par.Update_buff += str;

    }
}


void MainWindow::on_bt_netSend_clicked()
{


    QString str = lineEdit_manuel->text();
    QByteArray byte;
    for(int i =0;i<str.length();i+=3){
        byte.append((uchar)hexToUint8(str,i));
    }


    if((uchar)byte[0] == 0x98 && (uchar)byte[1] == 0x89){

        byte.append(checkSum(byte,byte.length()));
        ushort device_id = (uchar)byte[4]*256+(uchar)byte[5];
        NET_getBindSocket(device_id);
        NET_send(byte);
    }
    else {

        ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
        byte.append(checkSum(byte,byte.length()));

        if(((uchar)byte[0] == 0xA5 && (uchar)byte[1] == 0x5A)||
           ((uchar)byte[0] == 0xA6 && (uchar)byte[1] == 0x6A)||
           ((uchar)byte[0] == 0xAA && (uchar)byte[1] == 0x55)||
           ((uchar)byte[0] == 0xFA && (uchar)byte[1] == 0xCA)
                )
        {
            byte = IOT_cmdApp(send.gateway_id,send.device_id,byte);
        }
        else {
            byte = IOT_cmdNetwork(send.gateway_id,send.device_id,byte);
        }
    }






    str.clear();
    str = byte.toHex().toUpper();
    for(ushort i =0; i*3<str.length();i++)
    {
        str.insert(i*3+2, " ");
    }
    infEdit->setText(str);
}


bool MainWindow::NET_newListen()
{
    ushort port;
    QString str = textEdit_Port->text();
    port = str.toUShort();

    str = textEdit_IP->text();

   QHostAddress ip;
   ip.setAddress(str);


   for(ushort i = 0;i<SOCKET_MAX;i++)
   {
       if(net_par.Socket[i]!=NULL){
           if(net_par.Socket[i]->ConnectedState == QAbstractSocket::ConnectedState){
               net_par.Socket[i]->close();
           }
           net_par.Socket[i] = NULL;
       }
   }
   for(int i=0;i<=65535;i++){
       net_par.bind_socket[i] = NULL;
   }
   if(net_par.Server->isListening())net_par.Server->close();



   //监听是否有客户端来访，且对任何来访者监听，端口为
   if(net_par.Server->listen(ip,port)){
       str = "Server listening";
       str += "  IP:" + net_par.Server->serverAddress().toString();
       str += QString("  PORT:%1").arg(net_par.Server->serverPort());
       NET_DisplayWithTime(str);
       return true;
   }
   else{
       NET_DisplayWithTime(net_par.Server->errorString());
       return false;
   }
}
void MainWindow::NET_newListenLocation()
{
    ushort port;
    QString str = textEdit_Port_location->text();
    port = str.toUShort();

    str = textEdit_IP_location->text();
    QHostAddress ip;
    ip.setAddress(str);


   //监听是否有客户端来访，且对任何来访者监听，端口为6666
   if(!net_par.locationServer->listen(ip,port))
   {

      qDebug()<<net_par.locationServer->errorString();

      close();

      return;

   }
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

void MainWindow::NET_acceptConnectionLocation()
{
    ushort i;
    QString str;


    if(net_par.locationSocket!=NULL)net_par.locationSocket->close();

    //当有客户来访时将tcpSocket接受tcpServer建立的socket
    net_par.locationSocket = net_par.locationServer->nextPendingConnection();
    connect(net_par.locationSocket,SIGNAL(readyRead()),this,SLOT(NET_revDataLocation()));
    //当tcpSocket在接受客户端连接时出现错误时，NET_displayError(QAbstractSocket::SocketError)进行错误提醒并关闭tcpSocket。
    connect(net_par.locationSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(NET_displayError(QAbstractSocket::SocketError)));

    str = "new client connection";
    str +=" / peerName:"+net_par.locationSocket->peerName();
    str +=" / peerAddress:"+net_par.locationSocket->peerAddress().toString();
    str +=QString(" / peerPort:%1").arg(net_par.locationSocket->peerPort());
    NET_DisplayWithTime(str);

}


void MainWindow::NET_displayError(QAbstractSocket::SocketError)
{
    ushort i;
    for(i=0;i<SOCKET_MAX;i++)
    {
        if(net_par.Socket[i]!=NULL){
            net_par.Socket[i]->close();
            net_par.Socket[i] = NULL;
        }
    }
}



void MainWindow::on_bt_listen_clicked()
{


    bt_listen->setDisabled(true);
    bt_stopListen->setDisabled(false);

    if(comunication_protocal->currentText() == "Server")
    {
        if(NET_newListen()==true){
            bt_listen->setDisabled(true);
            bt_stopListen->setDisabled(false);
        }
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
    for(int i=0;i<=65535;i++){
        net_par.bind_socket[i] = NULL;
    }
    if(net_par.Server != NULL)net_par.Server->close();

    bt_listen->setDisabled(false);



}

void MainWindow::on_bt_listen_location_clicked()
{
    bt_listen_location->setDisabled(true);
    bt_stopListen_location->setDisabled(false);

    if(net_par.locationSocket != NULL)net_par.locationSocket->close();
    if(net_par.locationServer != NULL)net_par.locationServer->close();

    net_par.locationServer = new QTcpServer(this);
    NET_newListenLocation();
    //newConnection()用于当有客户端访问时发出信号，NET_acceptConnection()信号处理函数
    connect(net_par.locationServer,SIGNAL(newConnection()),this,SLOT(NET_acceptConnectionLocation()));

}

void MainWindow::on_bt_stopListen_location_clicked()
{

    if(net_par.locationSocket != NULL)net_par.locationSocket->close();
    if(net_par.locationServer != NULL)net_par.locationServer->close();
    net_par.locationSocket = NULL;
    net_par.locationServer = NULL;

    bt_listen_location->setDisabled(false);
}

void MainWindow::on_bt_searchId_clicked()
{
    QString str;
    ushort id;

    str = textEdit_ID->toPlainText();
    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        id = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        id = str.toUShort(Q_NULLPTR,10);
    }

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

void MainWindow::on_bt_setDevRssi_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    LOC_SetDevRssiOffset(send.gateway_id,send.device_id,send.mac);
}


void MainWindow::on_pushButton_setHeartRateTime_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    LOC_SetDevHeartRateTime(send.gateway_id,rf_send.device_id,send.mac);
}

void MainWindow::on_checkBox_productTest_stateChanged(int arg1)
{
    if(checkBox_productTest->isChecked()==true){
        checkBox_125KTest->setChecked(false);

    }
}




void MainWindow::on_checkBox_125KTest_stateChanged(int arg1)
{
    if(checkBox_125KTest->isChecked()==true){
        checkBox_productTest->setChecked(false);
    }
}



void MainWindow::LOC_Set125KRssi(ushort gateway_id,ushort device_id)
{

    QString str;
    ushort ant125kId;
    uchar ant125kRssi;

    str = location125KIDtextEdit->toPlainText();
    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ant125kId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ant125kId = str.toUShort(Q_NULLPTR,10);
    }
    str = location125KRssitextEdit->toPlainText();
    if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        ant125kRssi = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        ant125kRssi = str.toUShort(Q_NULLPTR,10);
    }







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

void MainWindow::LOC_SetDevRssiOffset(ushort gateway_id,ushort device_id,uchar *mac)
{

    QString str;
    char ant125kRssi;


    locationDevIDtextEdit->setText(strToHex(mac,8).toUpper());
    str = locationDevRssitextEdit->text();

    ant125kRssi = (char)str.toShort(Q_NULLPTR,10);


    QByteArray buff;
    buff.clear();
    buff[0] = 0xA6;
    buff[1] = 0x6A;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = rf_send.device_type;
    buff[11] = 2;
    buff[12] = locCmd_setRssiOffset;
    buff[13] = ant125kRssi;
    buff.append(checkSum(buff,buff.length()));

    IOT_cmdApp(gateway_id,device_id,buff);
    str = "locCmd_setRssiOffset/ device id = 0x"+uint16ToHex(device_id).toUpper();
    str += "/ MAC:"+locationDevIDtextEdit->text();
    str += QString("/ RSSI offset = %1").arg((short)ant125kRssi);
    LOC_DisplayWithTime(str);
}

void MainWindow::LOC_SetDevHeartRateTime(ushort gateway_id,ushort device_id,uchar *mac)
{

    QString str;
    uint time_utc;
    ushort time_seconds;
    QDateTime qtime;
    time_utc = (uint)(qtime.currentDateTimeUtc().toMSecsSinceEpoch()/1000);

    str = textEdit_heartRate_time->text();

    time_seconds = str.toUShort(Q_NULLPTR,10);


    QByteArray buff;
    buff.clear();
    buff[0] = 0xA6;
    buff[1] = 0x6A;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = rf_send.device_type;
    buff[11] = 7;
    buff[12] = locCmd_setReportTime;
    buff[13] = (time_seconds>>8)&0xFF;
    buff[14] = (time_seconds>>0)&0xFF;
    //UTC TIME
    buff[15] = (uchar)(time_utc>>24)&0xFF;
    buff[16] = (uchar)(time_utc>>16)&0xFF;
    buff[17] = (uchar)(time_utc>>8 )&0xFF;
    buff[18] = (uchar)(time_utc>>0 )&0xFF;
    buff.append(checkSum(buff,buff.length()));

    IOT_cmdApp(gateway_id,device_id,buff);
    str = "locCmd_setReportTime/ device id = 0x"+uint16ToHex(device_id).toUpper();
    str += "/ MAC:"+strToHex(mac,8).toUpper();
    str += QString("/ time report = %1S").arg(time_seconds);
    str += "/ UTC:" + QString("%1").arg(time_utc);
    //str += "/ "+ (QDateTime::fromTime_t(1533801743)).toString();
    LOC_DisplayWithTime(str);
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
    if(coolAA55checkBox->isChecked()){
        COO_tempretureVerfication(send.gateway_id , rf_send.device_id,send.mac);
        COO_DisplayWithTime("AA55温度校准");
    }
    else{
        COO_tempretureVerfication(send.gateway_id , rf_send.device_id);
        COO_DisplayWithTime("温度校准");
    }

}

void MainWindow::on_coolHumVerification_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    if(coolAA55checkBox->isChecked()){
        COO_HumVerfication(send.gateway_id , rf_send.device_id,send.mac);
        COO_DisplayWithTime("AA55湿度校准");
    }
    else{
        COO_HumVerfication(send.gateway_id , rf_send.device_id);
        COO_DisplayWithTime("湿度校准");
    }


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
    buff[4] = coolDevCoolChain;
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
    buff[4] = coolDevCoolChain;
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
    buff[4] = coolDevCoolChain;
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
    buff[4] = coolDevCoolChain;
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
    buff[4] = coolDevCoolChain;
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

void MainWindow::COO_tempretureVerfication(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    short num;
    QString str = coolTemVerification_Edit->toPlainText();


    num = str.toShort();

    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevCoolChain;
    buff[11] = 0x03;//len
    buff[12] = coolCmdTemVer;
    if(num<0)
    {
        buff[13] = 1;
        buff[14] = -num;
    }
    else
    {
        buff[13] = 0;
        buff[14] = num;
    }

    buff[15] = checkSum(buff,buff.length());

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
    buff[4] = coolDevCoolChain;
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

void MainWindow::COO_HumVerfication(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    short num;
    QString str = coolHumVerification_Edit->toPlainText();


    num = str.toShort();

    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevCoolChain;
    buff[11] = 0x03;//len
    buff[12] = coolCmdHumVer;
    if(num<0)
    {
        buff[13] = 1;
        buff[14] = -num;
    }
    else
    {
        buff[13] = 0;
        buff[14] = num;
    }

    buff[15] = checkSum(buff,buff.length());

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
    buff[4] = coolDevCoolChain;
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
        tem = (-tem_l)*100;
        buff[11] = 1;
        buff[12] = (tem/100)>>8;
        buff[13] = (tem/100)>>0;
        buff[14] = (tem%100)>>0;
    }
    else
    {
        tem = (tem_l)*100;
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
    buff[4] = coolDevCoolChain;
    buff[5] = 0x05;//len
    buff[6] = coolCmdSetRepTime;
    buff[7] = 0xFF&(time>>24);
    buff[8] = 0xFF&(time>>16);
    buff[9] = 0xFF&(time>>8);
    buff[10] = 0xFF&(time>>0);
    buff[11] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::COO_setReportTime(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    uint time;
    time = coolSetRepTime_Edit->toPlainText().toUInt(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevTemTh;
    buff[11] = 0x05;//len
    buff[12] = coolCmdSetRepTime;
    buff[13] = 0xFF&(time>>24);
    buff[14] = 0xFF&(time>>16);
    buff[15] = 0xFF&(time>>8);
    buff[16] = 0xFF&(time>>0);
    buff[17] = checkSum(buff,buff.length());

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
    buff[4] = coolDevCoolChain;
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
    buff[4] = coolDevCoolChain;
    buff[5] = 0x03;//len
    buff[6] = coolCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    COO_DisplayWithTime("server ack error");
}






/***********************cool end****************/



/****************TemTH start****************/


void MainWindow::TEMTH_init()
{
    temth_par.filtStr.clear();
    TemTHFiltId->setPlainText("0xFFFF");

}


void MainWindow::TEMTH_DisplayWithTime(const QString &text)
{

    QString str;
    QDateTime datTime = QDateTime::currentDateTime();
    str = datTime.toString("yyyy-MM-dd hh:mm:ss/ ")+text;
    TemTH_display->append(str);
    str += "\r\n";
    history_par.temTh_buff += QByteArray::fromStdString(str.toStdString());
}

void MainWindow::TEMTH_DisplayWithNoTime(const QString &text)
{
    TemTH_display->append( text);
    QString str;
    str = text + "\r\n";
    history_par.temTh_buff += QByteArray::fromStdString(str.toStdString());
}
void MainWindow::on_TemTHFiltId_textChanged()
{
    QString str = TemTHFiltId->toPlainText();
    if(str.length() == 0)
    {
        temth_par.filtId = 0xFFFF;
    }
    else if(str[0]=='0' && (str[1]=='x' || str[1]=='X'))
    {
        temth_par.filtId = str.toUShort(Q_NULLPTR,16);
    }
    else
    {
        temth_par.filtId = str.toUShort(Q_NULLPTR,10);
    }
    TEMTH_DisplayWithTime("filt id:0x"+uint16ToHex(temth_par.filtId).toUpper());
}

void MainWindow::on_TemTHFiltStr_textChanged()
{
    temth_par.filtStr = QByteArray::fromStdString(TemTHFiltStr->toPlainText().toStdString());
    TEMTH_DisplayWithTime(QString("filt string:")+temth_par.filtStr);
}




void MainWindow::on_TemTHSetRepTime_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    TEMTH_setReportTime(send.gateway_id , rf_send.device_id,send.mac);
    TEMTH_DisplayWithTime("设置采样时间");
}

void MainWindow::on_TemTHTemVerification_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    TEMTH_tempretureVerfication(send.gateway_id , rf_send.device_id,send.mac);
    TEMTH_DisplayWithTime("温度校验");
}

void MainWindow::on_TemTHHumVerification_Bt_clicked()
{
    ID_SEND send = id_access.getIdSendInf(rf_send.device_id);
    TEMTH_HumVerfication(send.gateway_id , rf_send.device_id,send.mac);
    TEMTH_DisplayWithTime("湿度校验");
}



void MainWindow::TEMTH_setReportTime(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    ushort time;
    time = TemTHSetRepTime_Edit_2->text().toUShort(Q_NULLPTR,10);

    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevTemTh;
    buff[11] = 0x04;//len
    buff[12] = TemThCmdSetRepTime;
    buff[13] = 0xFF&(time>>8);
    buff[14] = 0xFF&(time>>0);
    buff[15] = 0;
    buff[16] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::TEMTH_tempretureVerfication(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    short num;
    QString str = TemTHTemVerification_Edit->toPlainText();


    num = str.toShort();

    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevTemTh;
    buff[11] = 0x03;//len
    buff[12] = TemThCmdTemVer;
    if(num<0)
    {
        buff[13] = 1;
        buff[14] = -num;
    }
    else
    {
        buff[13] = 0;
        buff[14] = num;
    }

    buff[15] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}

void MainWindow::TEMTH_HumVerfication(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    short num;
    QString str = TemTHHumVerification_Edit->toPlainText();


    num = str.toShort();

    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevTemTh;
    buff[11] = 0x03;//len
    buff[12] = TemThCmdHumVer;
    if(num<0)
    {
        buff[13] = 1;
        buff[14] = -num;
    }
    else
    {
        buff[13] = 0;
        buff[14] = num;
    }

    buff[15] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}



void MainWindow::TEMTH_setSystemTime(ushort gateway_id,ushort device_id,uchar *mac)
{
    QByteArray buff;
    uint time;
    QDateTime datTime = QDateTime::currentDateTime();
    TEMTH_DisplayWithTime(QString("set system time UTC: %1").arg(datTime.toUTC().toTime_t()));
    time = datTime.toUTC().toTime_t();
    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = mac[0];
    buff[3] = mac[1];
    buff[4] = mac[2];
    buff[5] = mac[3];
    buff[6] = mac[4];
    buff[7] = mac[5];
    buff[8] = mac[6];
    buff[9] = mac[7];
    buff[10] = coolDevTemTh;
    buff[11] = 0x06;//len
    buff[12] = TemThCmdSystemTime;
    buff[13] = 0xFF&(time>>24);
    buff[14] = 0xFF&(time>>16);
    buff[15] = 0xFF&(time>>8);
    buff[16] = 0xFF&(time>>0);
    buff[17] = 0;
    buff[18] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);
}


void MainWindow::TEMTH_ackSuccess(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevCoolChain;
    buff[5] = 0x03;//len
    buff[6] = coolCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 00;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    TEMTH_DisplayWithTime("server ack success");
}

void MainWindow::TEMTH_ackError(ushort gateway_id,ushort device_id,uchar ack_cmd)
{
    QByteArray buff;
    buff.clear();
    buff[0] = 0xAA;
    buff[1] = 0x55;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevCoolChain;
    buff[5] = 0x03;//len
    buff[6] = coolCmdStatus;
    buff[7] = ack_cmd;
    buff[8] = 01;
    buff[9] = checkSum(buff,buff.length());

    IOT_cmdApp(gateway_id,device_id,buff);

    TEMTH_DisplayWithTime("server ack error");
}






/***********************TemTH end****************/


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

    TEMTH_DisplayWithTime("server ack success");
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

    TEMTH_DisplayWithTime("server ack error");
}





/***********************eneryg end****************/


void MainWindow::on_bt_clear_clicked()
{
    on_StoreDir_clicked();
//    textBr_mess->clear();
//    infDisplay->clear();
//    infEdit->clear();
//    infReceive->clear();
//    location_display->clear();
//    cool_display->clear();
//    energy_display->clear();
//    injection_display->clear();
//    sos_display->clear();
//    BLE_display->clear();
    for(uchar j = 0;j<DEVICE_DISPLAY_MAX;j++){
        //clear last location data

        display_par.device[j].id = 0xFFFF;
        display_par.device[j].x = 0x00;
        display_par.device[j].y = 0x00;
        display_par.device[j].radius = 0x00;
        display_par.device[j].rssi_offset = 0x00;
        display_par.device[j].color = Qt::white;
        display_par.device[j].displayInfFlag = false;
        memset(display_par.device[j].mac,0x00,8);

    }
    BLE_displayUpdate();
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

    str = textEdit_ID2->text();
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


    history_par.temTh_file = new QFile(history_par.temTh_path+str);
    history_par.temTh_file->open(QIODevice::ReadWrite);
    history_par.temTh_file->write(history_par.temTh_buff);
    history_par.temTh_file->close();
    history_par.temTh_buff.clear();

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
    TemTH_display->clear();

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

        history_par.injection_file = new QFile(history_par.injection_path+str);
        history_par.injection_file->open(QIODevice::ReadWrite);
        history_par.injection_file->write(history_par.injection_buff);
        history_par.injection_file->close();
        history_par.injection_buff.clear();

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
    QString str = injectionSetName_Edit->toPlainText();
    INJ_DisplayWithNoTime(str);

    buff.clear();
    buff[0] = 0xFA;
    buff[1] = 0xCA;
    buff[2] = 0xFF;
    buff[3] = 0xFF;
    buff[4] = coolDevInjection;
    buff[5] = 0x03;//len
    buff[6] = injectionCmdSetName;
    buff.append(str);

//    buff[9] = checkSum(buff,buff.length());
    buff.append(checkSum(buff,buff.length()));

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

    BLE_idInfoReadFromFile();
    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
        display_par.device[i].id = 0xFFFF;
        display_par.device[i].x = 0x00;
        display_par.device[i].y = 0x00;
        display_par.device[i].radius = 0x00;
        display_par.device[i].rssi_offset = 0x00;
        display_par.device[i].color = Qt::white;
        display_par.device[i].displayInfFlag = false;
        memset(display_par.device[i].mac,0xFF,8);
    }


    BLE_virtualRatio->setText("0.5");

    for(i = 0;i<ALGORITHM_DEVICE_MAX;i++){

        ble_algorithm.ble_algorithm[i].receive_count = 0;
        ble_algorithm.ble_algorithm[i].device_id = 0xFFFF;
        ble_algorithm.ble_algorithm[i].sequence = 0;
        ble_algorithm.ble_algorithm[i].update_flag = false;
        for(j = 0;j<ALGORITHM_ANT_MAX;j++){
            ble_algorithm.ble_algorithm[i].ant_id[j] = 0xFFFF;
            ble_algorithm.ble_algorithm[i].rssi[j] = -100;
        }

    }


    ble_algorithm.timer = new QTimer(this);
    connect(ble_algorithm.timer,SIGNAL(timeout()),this,SLOT(BLE_locationCalculator(0xFFFF)));
    ble_algorithm.timer->start(1000);
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
        if((display_par.ant[i].mac[0] != 0xFF)||
           (display_par.ant[i].mac[1] != 0xFF)||
           (display_par.ant[i].mac[2] != 0xFF)||
           (display_par.ant[i].mac[3] != 0xFF)||
           (display_par.ant[i].mac[4] != 0xFF)||
           (display_par.ant[i].mac[5] != 0xFF)||
           (display_par.ant[i].mac[6] != 0xFF)||
           (display_par.ant[i].mac[7] != 0xFF)){
//        if(display_par.ant[i].id!=0xFFFF){
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
        if((display_par.device[i].mac[0] != 0xFF)||
           (display_par.device[i].mac[1] != 0xFF)||
           (display_par.device[i].mac[2] != 0xFF)||
           (display_par.device[i].mac[3] != 0xFF)||
           (display_par.device[i].mac[4] != 0xFF)||
           (display_par.device[i].mac[5] != 0xFF)||
           (display_par.device[i].mac[6] != 0xFF)||
           (display_par.device[i].mac[7] != 0xFF)){
//        if(display_par.device[i].id!=0xFFFF){
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
    uchar mac[8];

    str = BLE_xPointEdit->toPlainText();
    x_point = str.toInt();
    str = BLE_yPointEdit->toPlainText();
    y_point = str.toInt();


    str = lineEditAddAntMac->text();
    if(str.length()==16){
        mac[0] = hexToUint8(str,0);
        mac[1] = hexToUint8(str,2);
        mac[2] = hexToUint8(str,4);
        mac[3] = hexToUint8(str,6);
        mac[4] = hexToUint8(str,8);
        mac[5] = hexToUint8(str,10);
        mac[6] = hexToUint8(str,12);
        mac[7] = hexToUint8(str,14);
    }
    else {
        return;
    }

    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(memcmp(display_par.ant[i].mac,mac,8)==0){
           display_par.ant[i].id  = id_access.getIdMac(display_par.ant[i].mac);
           display_par.ant[i].x = x_point;
           display_par.ant[i].y = y_point;
           display_par.ant[i].color = Qt::darkGreen;
           goto on_BLE_addAnt_clicked_0;
       }
    }

    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if((display_par.ant[i].mac[0] == 0xFF)&&
          (display_par.ant[i].mac[1] == 0xFF)&&
          (display_par.ant[i].mac[2] == 0xFF)&&
          (display_par.ant[i].mac[3] == 0xFF)&&
          (display_par.ant[i].mac[4] == 0xFF)&&
          (display_par.ant[i].mac[5] == 0xFF)&&
          (display_par.ant[i].mac[6] == 0xFF)&&
          (display_par.ant[i].mac[7] == 0xFF)
               ){
           memcpy(display_par.ant[i].mac,mac,8);
           display_par.ant[i].id  = id_access.getIdMac(display_par.ant[i].mac);
           display_par.ant[i].x = x_point;
           display_par.ant[i].y = y_point;
           display_par.ant[i].color = Qt::darkGreen;
           goto on_BLE_addAnt_clicked_0;
       }
    }


on_BLE_addAnt_clicked_0:

    BLE_displayUpdate();
    BLE_idInfoWriteInFile();


}

void MainWindow::on_BLE_deleteAnt_clicked()
{
    uchar i;
    QString str;
    uchar mac[8];
    str = lineEditAddAntMac->text();
    if(str.length()==16){
        mac[0] = hexToUint8(str,0);
        mac[1] = hexToUint8(str,2);
        mac[2] = hexToUint8(str,4);
        mac[3] = hexToUint8(str,6);
        mac[4] = hexToUint8(str,8);
        mac[5] = hexToUint8(str,10);
        mac[6] = hexToUint8(str,12);
        mac[7] = hexToUint8(str,14);
    }
    else {
        return;
    }



    for(i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(memcmp(display_par.ant[i].mac,mac,8)==0){
//       if(display_par.ant[i].id == device_id){
           display_par.ant[i].id = 0xFFFF;
           display_par.ant[i].x = 0x00;
           display_par.ant[i].y = 0x00;
           display_par.ant[i].radius = 0x00;
           display_par.ant[i].rssi_offset = 0x00;
           display_par.ant[i].color = Qt::white;
           display_par.ant[i].displayInfFlag = false;
           memset(display_par.ant[i].mac,0xFF,8);
           BLE_displayUpdate();
       }
    }
    BLE_idInfoWriteInFile();
}






void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    BLE_roundMeter->setText(QString("半径%1米圆形").arg(value));

    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.ant[i].id == rf_send.device_id){
           display_par.ant[i].radius = value;  
           IOT_sendIdInformation(rf_send.device_id,net_par.locationSocket);
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
       if(display_par.device[i].id == rf_send.device_id){
           display_par.device[i].radius= value;
           IOT_sendIdInformation(rf_send.device_id,net_par.locationSocket);
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
        if((display_par.ant[i].mac[0] != 0xFF)||
           (display_par.ant[i].mac[1] != 0xFF)||
           (display_par.ant[i].mac[2] != 0xFF)||
           (display_par.ant[i].mac[3] != 0xFF)||
           (display_par.ant[i].mac[4] != 0xFF)||
           (display_par.ant[i].mac[5] != 0xFF)||
           (display_par.ant[i].mac[6] != 0xFF)||
           (display_par.ant[i].mac[7] != 0xFF)){
//       if(display_par.ant[i].id != 0xFFFF){
           display_par.ant[i].displayInfFlag = true;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
        if((display_par.device[i].mac[0] != 0xFF)||
           (display_par.device[i].mac[1] != 0xFF)||
           (display_par.device[i].mac[2] != 0xFF)||
           (display_par.device[i].mac[3] != 0xFF)||
           (display_par.device[i].mac[4] != 0xFF)||
           (display_par.device[i].mac[5] != 0xFF)||
           (display_par.device[i].mac[6] != 0xFF)||
           (display_par.device[i].mac[7] != 0xFF)){
//       if(display_par.device[i].id != 0xFFFF){
           display_par.device[i].displayInfFlag = true;
       }
    }
    BLE_displayUpdate();

}

void MainWindow::on_BLE_hideAllDeviceInf_clicked()
{
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
        if((display_par.ant[i].mac[0] != 0xFF)||
           (display_par.ant[i].mac[1] != 0xFF)||
           (display_par.ant[i].mac[2] != 0xFF)||
           (display_par.ant[i].mac[3] != 0xFF)||
           (display_par.ant[i].mac[4] != 0xFF)||
           (display_par.ant[i].mac[5] != 0xFF)||
           (display_par.ant[i].mac[6] != 0xFF)||
           (display_par.ant[i].mac[7] != 0xFF)){
//       if(display_par.ant[i].id != 0xFFFF){
           display_par.ant[i].displayInfFlag = false;
       }
    }
    for(uchar i=0;i<DEVICE_DISPLAY_MAX;i++){
        if((display_par.device[i].mac[0] != 0xFF)||
           (display_par.device[i].mac[1] != 0xFF)||
           (display_par.device[i].mac[2] != 0xFF)||
           (display_par.device[i].mac[3] != 0xFF)||
           (display_par.device[i].mac[4] != 0xFF)||
           (display_par.device[i].mac[5] != 0xFF)||
           (display_par.device[i].mac[6] != 0xFF)||
           (display_par.device[i].mac[7] != 0xFF)){
//       if(display_par.device[i].id != 0xFFFF){
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

void MainWindow::BLE_storeData(ushort device_id,ushort ant_id,uchar sequence,short rssi){
    for(uchar j = 0 ; j <DEVICE_DISPLAY_MAX;j++){
        //seek ant0 information
        if(display_par.ant[j].id==ant_id){
            break;
        }
        else{
            if(j+1==DEVICE_DISPLAY_MAX)return;
        }
    }
    for(uchar i=0;i<ALGORITHM_DEVICE_MAX;i++)
    {
        if(ble_algorithm.ble_algorithm[i].device_id == device_id){
            if(ble_algorithm.ble_algorithm[i].sequence == sequence){
                for(uchar j = 0;j<ble_algorithm.ble_algorithm[i].receive_count;j++){
                    if(ble_algorithm.ble_algorithm[i].ant_id[j] == ant_id){
                        ble_algorithm.ble_algorithm[i].rssi[j] = rssi;
                        ble_algorithm.ble_algorithm[i].update_flag = true;
                        //BLE_locationCalculator(ble_algorithm.ble_algorithm[i].device_id);
                        return;
                    }
                }

                if(ble_algorithm.ble_algorithm[i].receive_count>=ALGORITHM_ANT_MAX){
                    ble_algorithm.ble_algorithm[i].receive_count = 0;
                }
                ble_algorithm.ble_algorithm[i].rssi[ble_algorithm.ble_algorithm[i].receive_count] = rssi;
                ble_algorithm.ble_algorithm[i].ant_id[ble_algorithm.ble_algorithm[i].receive_count] = ant_id;
                ble_algorithm.ble_algorithm[i].receive_count++;
                ble_algorithm.ble_algorithm[i].update_flag = true;
                return ;
            }
            else if(ble_algorithm.ble_algorithm[i].sequence < sequence ||
                   ble_algorithm.ble_algorithm[i].sequence > (sequence+3)){
                //有新的数据接收到，计算定位数据
                if(ble_algorithm.ble_algorithm[i].update_flag == true){
                    //还没有来得及计算位置，就有新的数据
                    BLE_locationCalculator(ble_algorithm.ble_algorithm[i].device_id);
                }
                //store new data
                ble_algorithm.ble_algorithm[i].rssi[0] = rssi;
                ble_algorithm.ble_algorithm[i].ant_id[0] = ant_id;
                ble_algorithm.ble_algorithm[i].receive_count=1;
                ble_algorithm.ble_algorithm[i].sequence = sequence;
                ble_algorithm.ble_algorithm[i].update_flag = true;

                return;
            }
            else{
                return;
            }
        }
    }
    for(uchar i=0;i<ALGORITHM_DEVICE_MAX;i++)
    {
        if(ble_algorithm.ble_algorithm[i].device_id == 0xFFFF){
            //store new data
            ble_algorithm.ble_algorithm[i].device_id = device_id;
            ble_algorithm.ble_algorithm[i].rssi[0] = rssi;
            ble_algorithm.ble_algorithm[i].ant_id[0] = ant_id;
            ble_algorithm.ble_algorithm[i].receive_count=1;
            ble_algorithm.ble_algorithm[i].sequence = sequence;
            ble_algorithm.ble_algorithm[i].update_flag = true;

            return;
        }
    }
}


void MainWindow::BLE_locationCalculator(ushort id){
    bool update_flag = false;
    uchar i,j,m,ant_first,ant_second,ant_third;
    short xA=0,yA=0,xB=0,yB=0,xC=0,yC=0,x_min,y_min,x_max,y_max;
    short x,y,x_point,y_point,x_point_previous,y_point_previous;
    long double distance_AB[2],distance_AC[2],distance_BC[2],distance_last0,distance_last1;
    long double distance_A,distance_B,distance_C,distance_A_last,distance_B_last,distance_C_last;
    long double rssi_AB,rssi_AC,rssi_BC;
    ushort ant_idA,ant_idB,ant_idC;
    long double ant_rssiA,ant_rssiB,ant_rssiC;
    short ant_offsetA=0,ant_offsetB=0,ant_offsetC=0;
    long double len_AB,len_BC,len_AC,len_A,len_B,len_C;
    QString str;




   //ble_algorithm.timer->start(1000);
    ble_algorithm.timer->stop();
    str.clear();
    if(BLE_displayLog->isChecked()){
        str+="\r\n*********************algorithm start*************************";
    }

    for(i=0;i<ALGORITHM_DEVICE_MAX;i++){
        if((ble_algorithm.ble_algorithm[i].device_id != id)&&
           (id != 0xFFFF)){
            continue;
        }

        if((ble_algorithm.ble_algorithm[i].update_flag == true) &&
           (ble_algorithm.ble_algorithm[i].receive_count >= 3)){
            update_flag = true;
            ble_algorithm.ble_algorithm[i].update_flag = false;

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
            //location algorithm

            ant_first = 0;
            ant_second = 0;
            ant_third = 0;
            ant_rssiA = -1000;
            ant_rssiB = -1000;
            ant_rssiC = -1000;

            for(m = 0;m< ble_algorithm.ble_algorithm[i].receive_count;m++){
                //选择rssi第一大的天线
                if(ant_rssiA<ble_algorithm.ble_algorithm[i].rssi[m]){
                    ant_first = m;
                    ant_rssiA = ble_algorithm.ble_algorithm[i].rssi[m];
                }
            }

            for(m = 0;m< ble_algorithm.ble_algorithm[i].receive_count;m++){
                //选择rssi第二大的天线
                if(m==ant_first)continue;
                if(ant_rssiB<ble_algorithm.ble_algorithm[i].rssi[m]){
                    ant_second = m;
                    ant_rssiB = ble_algorithm.ble_algorithm[i].rssi[m];
                }
            }

            for(m = 0;m< ble_algorithm.ble_algorithm[i].receive_count;m++){
                //选择rssi第三大的天线
                if(m==ant_first || m==ant_second)continue;
                if(ant_rssiC<ble_algorithm.ble_algorithm[i].rssi[m]){
                    ant_third = m;
                    ant_rssiC = ble_algorithm.ble_algorithm[i].rssi[m];
                }
            }

            if(ant_rssiA==-1000||ant_rssiB==-1000||ant_rssiC==-1000){
                BLE_DisplayWithTime("*********************ant_rssiA==-1000||ant_rssiB==-1000||ant_rssiC==-1000 error*************************");
                return;
            }

            //选择三个天线的数据进行定位
            ant_idA = ble_algorithm.ble_algorithm[i].ant_id[ant_first];
            ant_idB = ble_algorithm.ble_algorithm[i].ant_id[ant_second];
            ant_idC = ble_algorithm.ble_algorithm[i].ant_id[ant_third];
//            ant_rssiA = ble_algorithm.ble_algorithm[i].rssi[ant_first];
//            ant_rssiB = ble_algorithm.ble_algorithm[i].rssi[ant_second];
//            ant_rssiC = ble_algorithm.ble_algorithm[i].rssi[ant_third];

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

            x_point=1000;
            y_point=1000;
            x_point_previous = 1000;
            y_point_previous = 1000;
            for(j = 0 ; j <DEVICE_DISPLAY_MAX;j++){
                //seek ant2 information
                if(display_par.device[j].id==ble_algorithm.ble_algorithm[i].device_id){
                    x_point_previous = display_par.device[j].x;
                    y_point_previous = display_par.device[j].y;
                    break;
                }
            }


            ant_rssiA = -(ant_rssiA+ant_offsetA)+20;

            ant_rssiB = -(ant_rssiB+ant_offsetB)+20;

            ant_rssiC = -(ant_rssiC+ant_offsetC)+20;

            len_A = ant_rssiA;
            len_B = ant_rssiB;
            len_C = ant_rssiC;

            //if((ant_rssiA - ant_rssiC)>5)
            {
                if(BLE_attenuationcheckBox->isChecked()){
                    //接收灵敏度转换距离
                    len_A = pow(10, (len_A -91.2)/20)*1000;
                    len_B = pow(10, (len_B -91.2)/20)*1000;
                    len_C = pow(10, (len_C -91.2)/20)*1000;
                    if(BLE_attenuationWithoutCentercheckBox->isChecked()&&((ant_rssiC-ant_rssiA)<10)&&(ant_rssiA>50)){
                        len_A = ant_rssiA;
                        len_B = ant_rssiB;
                        len_C = ant_rssiC;
                    }
                }
            }






            len_AB = sqrt((xA - xB)*(xA - xB)+(yA - yB)*(yA - yB));
            len_AC = sqrt((xA - xC)*(xA - xC)+(yA - yC)*(yA - yC));
            len_BC = sqrt((xB - xC)*(xB - xC)+(yB - yC)*(yB - yC));



            if(len_A<=0)len_A = 1;
            if(len_B<=0)len_B = 1;
            if(len_C<=0)len_C = 1;


            if(len_A>len_B){
                rssi_AB = len_A/len_B;
            }
            else {
                rssi_AB = len_B/len_A;
            }

            if(len_A>len_C){
                rssi_AC = len_A/len_C;
            }
            else {
                rssi_AC = len_C/len_A;
            }

            if(len_B>len_C){
                rssi_BC = len_B/len_C;
            }
            else {
                rssi_BC = len_C/len_B;
            }



            distance_last0 = 1000;
            distance_last1 = 1000;


            //find max and min x
            if(xA>xB){
                x_min = xB;
                x_max = xA;
            }
            else {
                x_min = xA;
                x_max = xB;
            }

            if(xC>x_max)x_max = xC;
            else if(xC<x_min)x_min = xC;
            //find max and min y
            if(yA>yB){
                y_min = yB;
                y_max = yA;
            }
            else {
                y_min = yA;
                y_max = yB;
            }

            if(yC>y_max)y_max = yC;
            else if(yC<y_min)y_min = yC;


            for(x=-100;x<200;x++){
                if(BLE_xyPointCheckBox->isChecked()){
                    if((x<x_min)||(x>x_max))continue;
                }
                for(y=-100;y<200;y++){
                    if(BLE_xyPointCheckBox->isChecked()){
                        if((y<y_min)||(y>y_max))continue;
                    }

//                    if(((x==xA)&&(y==yA))||((x==xB)&&(y==yB))||((x==xC)&&(y==yC))){
//                        continue;
//                    }
                    distance_A = sqrt((x - xA)*(x - xA)+(y - yA)*(y - yA));
                    distance_B = sqrt((x - xB)*(x - xB)+(y - yB)*(y - yB));
                    distance_C = sqrt((x - xC)*(x - xC)+(y - yC)*(y - yC));

                    if(BLE_radiusCheckBox->isChecked()){
                        if((distance_A>len_AB)&&(distance_A>len_AC))continue;;
                        if((distance_B>len_AB)&&(distance_B>len_BC))continue;;
                        if((distance_C>len_AC)&&(distance_C>len_BC))continue;;
                    }


                    if(distance_A<=0)distance_A =0.000001;
                    if(distance_B<=0)distance_B =0.000001;
                    if(distance_C<=0)distance_C =0.000001;



                    if(len_A>len_B){
                        distance_AB[0] = distance_A / distance_B;
                    }
                    else {
                        distance_AB[0] = distance_B / distance_A;
                    }

                    if(len_A>len_C){
                        distance_AC[0] = distance_A / distance_C;
                    }
                    else {
                        distance_AC[0] = distance_C / distance_A;
                    }

                    if(len_B>len_C){
                        distance_BC[0] = distance_B / distance_C;
                    }
                    else {
                        distance_BC[0] = distance_C / distance_B;
                    }

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


//                    distance_AB[1] = fabs(rssi_AB-distance_AB[0]);
//                    distance_AC[1] = fabs(rssi_AC-distance_AC[0]);
//                    distance_BC[1] = fabs(rssi_BC-distance_BC[0]);

                    if((distance_AB[1]<ble_algorithm.par.ratio) && (distance_AC[1]<ble_algorithm.par.ratio) && (distance_BC[1]<ble_algorithm.par.ratio)){
                        if(((len_AB+len_AC+len_BC))>(distance_A+distance_B+distance_C)){
                            if(distance_last0 > (distance_AB[1]+distance_AC[1]+distance_BC[1])){
                                distance_last0 = (distance_AB[1]+distance_AC[1]+distance_BC[1]);
                                x_point = x;
                                y_point = y;

                                distance_A_last = distance_A;
                                distance_B_last = distance_B;
                                distance_C_last = distance_C;
                            }
                        }
                    }
                }
            }



            if((x_point!=1000)&&(y_point!=1000)){

                //**************filter***************************/
                if(BLE_FiltercheckBox->isChecked()){
                    if((x_point_previous!=1000)&&(y_point_previous!=1000)){
                        distance_last0 = sqrt((x_point - x_point_previous)*(x_point - x_point_previous)+(y_point - y_point_previous)*(y_point - y_point_previous));

//                        str += QString("\r\nx_point_previous:%1  y_point_previous:%2 ").arg(x_point_previous).arg(y_point_previous);
//                        str += QString("\r\nx_point:         %1  y_point:         %2   len:%3").arg(x_point).arg(y_point).arg((double)distance_last);

//                        if(distance_last>1.5){
//                            x_point = x_point_previous+(x_point-x_point_previous)/5;
//                            y_point = y_point_previous+(y_point-y_point_previous)/5;
//                        }


                        if(distance_last0>30){
                            x_point = x_point_previous+(x_point-x_point_previous)/8;
                            y_point = y_point_previous+(y_point-y_point_previous)/8;
                        }
                        else if(distance_last0>20){
                            x_point = x_point_previous+(x_point-x_point_previous)/7;
                            y_point = y_point_previous+(y_point-y_point_previous)/7;
                        }
                        else if(distance_last0>10){
                            x_point = x_point_previous+(x_point-x_point_previous)/5;
                            y_point = y_point_previous+(y_point-y_point_previous)/5;
                        }
                        else if(distance_last0>5){
                            x_point = x_point_previous+(x_point-x_point_previous)/3;
                            y_point = y_point_previous+(y_point-y_point_previous)/3;
                        }
                        else if(distance_last0>2){
                            x_point = x_point_previous+(x_point-x_point_previous)/2;
                            y_point = y_point_previous+(y_point-y_point_previous)/2;
                        }


//                        str += QString("\r\nx_point:         %1  y_point:         %2").arg(x_point).arg(y_point);
                    }
                }


                //**************filter***************************/

                for(j = 0;j<DEVICE_DISPLAY_MAX;j++){
                    //clear last location data
                    if(display_par.device[j].id == ble_algorithm.ble_algorithm[i].device_id){
                        display_par.device[j].id = 0xFFFF;
                        display_par.device[j].x = 0;
                        display_par.device[j].y = 0;
                        display_par.device[j].radius = 0x00;
                        display_par.device[j].rssi_offset = 0x00;
                        display_par.device[j].color = Qt::white;
                        display_par.device[j].displayInfFlag = false;
                        memset(display_par.device[j].mac,0x00,8);
                    }
                }
                for(j = 0;j<DEVICE_DISPLAY_MAX;j++){
                    //clear last location data
                    if(display_par.device[j].id == 0xFFFF){
                        display_par.device[j].id = ble_algorithm.ble_algorithm[i].device_id;
                        display_par.device[j].x = x_point;
                        display_par.device[j].y = y_point;
                        display_par.device[j].radius = 0x00;
                        display_par.device[j].rssi_offset = 0x00;
                        display_par.device[j].color = Qt::darkBlue;
                        display_par.device[j].displayInfFlag = false;
                        memset(display_par.device[j].mac,0x00,8);
                        break;
                    }
                }
            }


            if(BLE_displayLog->isChecked())
            {

                str+="\r\n/ device_id:0x"+uint16ToHex(ble_algorithm.ble_algorithm[i].device_id).toUpper();
                str+="/ ant_idA:0x"+uint16ToHex(ant_idA).toUpper();
                str+="/ ant_idB:0x"+uint16ToHex(ant_idB).toUpper();
                str+="/ ant_idC:0x"+uint16ToHex(ant_idC).toUpper();
                str+=QString("/ len_A:%1 len_B:%2 len_C:%3").arg((double)len_A).arg((double)len_B).arg((double)len_B);
                str+= QString("/ distance_A:%1  distance_B:%2  distance_C:%3").arg((double)distance_A_last).arg((double)distance_B_last).arg((double)distance_C_last);
                str+=QString("/ x_point:%1  y_point:%2").arg(x_point).arg(y_point);
            }
            break;
        }
    }


    if(update_flag == true){
        BLE_displayUpdate();
    }
    if(BLE_displayLog->isChecked()){

        str+="\r\n*********************algorithm end*************************";
        BLE_DisplayWithTime(str);
    }

}


//***************************************************


void MainWindow::on_BLE_virtualRatio_textChanged()
{
    ble_algorithm.par.ratio = BLE_virtualRatio->toPlainText().toDouble();
}



//**************************ant_id information***************************





bool MainWindow::BLE_idInfoWriteInFile()
{
    ulong i;
    uchar *ptr;
    QByteArray buff;
    buff.clear();



    ptr = (uchar *)&display_par;

    for(i=0;i<sizeof(display_par);i++)
    {
        buff.append(*ptr++);
    }


    QString path = QDir::currentPath();
    path+="/ant_information.bin";
    QFile file(path);
    file.open(QIODevice::ReadWrite);
    file.write(buff);
    file.close();

    return true;
}



bool MainWindow::BLE_idInfoReadFromFile()
{
    ulong i;
    QByteArray buff;
    uchar *ptr;
    buff.clear();
    QString path = QDir::currentPath();
    path+="/ant_information.bin";
    QFile file(path);


    if(!file.open(QIODevice::ReadOnly))
    {
       //creat a file and wirte the firmware
       ptr = (uchar *)&display_par;
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
           memset(display_par.ant[i].mac,0xFF,8);

           display_par.device[i].id = 0xFFFF;
           display_par.device[i].x = 0x00;
           display_par.device[i].y = 0x00;
           display_par.device[i].radius = 0x00;
           display_par.device[i].rssi_offset = 0x00;
           display_par.device[i].color = Qt::white;
           display_par.device[i].displayInfFlag = false;
           memset(display_par.device[i].mac,0xFF,8);

       }

       for(i=0;i<sizeof(display_par);i++)
       {
           buff.append(*ptr++);
       }




       QFile fd_creat(path);
       fd_creat.open(QIODevice::ReadWrite);
       fd_creat.write(buff);
       fd_creat.close();
    }
    else
    {
        buff = file.readAll();
        file.close();
        memcpy((uchar *)&display_par,buff.data(),buff.length());
    }
    return true;
}




void MainWindow::on_BLE_setAlgorithmPar_clicked()
{
    IOT_sendAlgorithm(net_par.locationSocket);
}

void MainWindow::on_BLE_sendAntList_clicked()
{
    IOT_sendAntInformation(net_par.locationSocket);
}

void MainWindow::on_textEdit_MIN_ID_textChanged()
{
//    ushort min_id = textEdit_MIN_ID->toPlainText().toUShort();
//    if(min_id<50000)textEdit_MIN_ID->setPlainText("50000");
}

void MainWindow::on_textEdit_MAX_ID_textChanged()
{
//    ushort max_id = textEdit_MAX_ID->toPlainText().toUShort();
//    if(max_id<50000)textEdit_MAX_ID->setPlainText("51000");
}











void MainWindow::on_cb_deviceTypeLocation_currentTextChanged(const QString &arg1)
{
    if(arg1 == "网关")rf_send.device_type = 0x00;
    else if(arg1 == "成人腕带")rf_send.device_type = 0x01;
    else if(arg1 == "精神病腕带")rf_send.device_type = 0x02;
    else if(arg1 == "婴儿腕带")rf_send.device_type = 0x03;
    else if(arg1 == "SOS按键(带定位)")rf_send.device_type = 0x04;
    else if(arg1 == "插座")rf_send.device_type = 0x05;
    else if(arg1 == "温度传感器")rf_send.device_type = 0x06;
    else if(arg1 == "湿度传感器")rf_send.device_type = 0x07;
    else if(arg1 == "多功能传感器")rf_send.device_type = 0x08;
    else if(arg1 == "资产标签")rf_send.device_type = 0x09;
    else if(arg1 == "四通道读头")rf_send.device_type = 0x0A;
    else if(arg1 == "125k资产标签")rf_send.device_type = 0x0B;
    else if(arg1 == "SOS按键(不带定位)")rf_send.device_type = 0x0C;
    else if(arg1  == "蓝牙透传863模块")rf_send.device_type = 0x0D;
    else if(arg1  == "手术室863模块")rf_send.device_type = 0x0E;
    else if(arg1  == "PDA863模块")rf_send.device_type = 0x0F;
    else if(arg1  == "桌面读卡器863模块")rf_send.device_type = 0x10;
    else if(arg1 == "蓝牙资产标签")rf_send.device_type = 0xA0;
    else if(arg1 == "蓝牙定位天线")rf_send.device_type = 0xB0;
    else if(arg1 == "中继器")rf_send.device_type = 0xFC;
    else if(arg1 == "普通节点")rf_send.device_type = 0xFD;
    else if(arg1 == "低功耗节点")rf_send.device_type = 0xFE;
    else if(arg1 == "未知节点")rf_send.device_type = 0xFF;
}


