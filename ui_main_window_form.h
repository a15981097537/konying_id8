/********************************************************************************
** Form generated from reading UI file 'main_window_form.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_FORM_H
#define UI_MAIN_WINDOW_FORM_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionFirmware_update;
    QAction *actionUart_tool;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_12;
    QComboBox *comunication_protocal;
    QTextEdit *te_addrEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_addAddr;
    QPushButton *pb_deleteAddr;
    QListWidget *shortAddr;
    QPushButton *bt_clear;
    QTabWidget *function;
    QWidget *Network;
    QVBoxLayout *verticalLayout_25;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout_20;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_17;
    QTextEdit *textEdit_IP;
    QPushButton *bt_listen;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_18;
    QTextEdit *textEdit_Port;
    QPushButton *bt_stopListen;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_22;
    QTextEdit *textEdit_ID2;
    QPushButton *bt_search_net;
    QSpacerItem *horizontalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_19;
    QTextEdit *textEdit_ID;
    QPushButton *bt_searchId;
    QPushButton *export_idList;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *horizontalSpacer_11;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_5;
    QTextBrowser *infDisplay;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_23;
    QHBoxLayout *horizontalLayout_19;
    QVBoxLayout *verticalLayout_21;
    QLabel *label_20;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_22;
    QHBoxLayout *horizontalLayout_20;
    QTextEdit *infEdit;
    QPushButton *bt_netSend;
    QTextBrowser *infReceive;
    QWidget *Uart;
    QVBoxLayout *verticalLayout_24;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_17;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *comboBox_port;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_6;
    QComboBox *comboBox_flcntrl;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_3;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_5;
    QComboBox *comboBox_parity;
    QVBoxLayout *verticalLayout_16;
    QVBoxLayout *verticalLayout_15;
    QPushButton *bt_apply;
    QPushButton *bt_cancel;
    QVBoxLayout *verticalLayout_4;
    QPushButton *bt_openport;
    QPushButton *bt_closeport;
    QSpacerItem *horizontalSpacer_7;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QSpinBox *spinBox_Period;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *bt_send;
    QPushButton *bt_stopsend;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QRadioButton *rbt_Decout;
    QRadioButton *rbt_ASCIIout;
    QRadioButton *rbt_BINout;
    QRadioButton *rbt_HEXout;
    QTextEdit *textEd_out;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_1;
    QRadioButton *rbt_Decin;
    QRadioButton *rbt_ASCIIin;
    QRadioButton *rbt_BINin;
    QRadioButton *rbt_HEXin;
    QTextBrowser *textBr_inp;
    QWidget *Firmware_update;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QComboBox *comboBox_updateMode;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_11;
    QComboBox *packetbyte;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_10;
    QComboBox *frimwareVersion;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_13;
    QComboBox *cb_deviceType;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_12;
    QPushButton *bt_getDeviceInf;
    QPushButton *bt_sendFirInf;
    QVBoxLayout *verticalLayout_13;
    QPushButton *bt_sendPacket;
    QPushButton *pushButton_nc0;
    QVBoxLayout *verticalLayout_10;
    QPushButton *bt_autoUpdate;
    QPushButton *bt_stopAutoUpdate;
    QVBoxLayout *verticalLayout_11;
    QPushButton *bt_readBoot;
    QPushButton *bt_readFirmware;
    QVBoxLayout *verticalLayout_14;
    QPushButton *bt_stopRead;
    QRadioButton *rb_displayRawHex;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *updateFileList;
    QPushButton *bt_openFile;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *readFileList;
    QPushButton *bt_storeFile;
    QProgressBar *progressBar;
    QTextBrowser *textBr_mess;
    QWidget *location;
    QVBoxLayout *verticalLayout_28;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_18;
    QVBoxLayout *verticalLayout_26;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_9;
    QTextEdit *localtionFiltId;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QTextEdit *localtionFiltStr;
    QRadioButton *locationStopDisplay;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_12;
    QTextBrowser *location_display;
    QWidget *cool;
    QVBoxLayout *verticalLayout_29;
    QGroupBox *groupBox_8;
    QHBoxLayout *horizontalLayout_21;
    QVBoxLayout *verticalLayout_27;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_14;
    QTextEdit *coolFiltId;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_23;
    QTextEdit *coolFiltStr;
    QRadioButton *coolStopDisplay;
    QVBoxLayout *verticalLayout_32;
    QPushButton *coolGetSn;
    QPushButton *coolGetTempreture;
    QPushButton *coolDisarm;
    QVBoxLayout *verticalLayout_31;
    QHBoxLayout *horizontalLayout_27;
    QTextEdit *coolSetSn_Edit;
    QPushButton *coolSetSn_Bt;
    QHBoxLayout *horizontalLayout_30;
    QTextEdit *coolTemVerification_Edit;
    QPushButton *coolTemVerification_Bt;
    QHBoxLayout *horizontalLayout_29;
    QTextEdit *coolHumVerification_Edit;
    QPushButton *coolHumVerification_Bt;
    QVBoxLayout *verticalLayout_30;
    QHBoxLayout *horizontalLayout_31;
    QTextEdit *coolTemAlarmH_Edit;
    QTextEdit *coolTemAlarmL_Edit;
    QPushButton *coolTemAlarm_Bt;
    QHBoxLayout *horizontalLayout_28;
    QTextEdit *coolSetRepTime_Edit;
    QPushButton *coolSetRepTime_Bt;
    QSpacerItem *horizontalSpacer_17;
    QSpacerItem *horizontalSpacer_18;
    QSpacerItem *horizontalSpacer_19;
    QSpacerItem *horizontalSpacer_16;
    QTextBrowser *cool_display;
    QWidget *energy;
    QWidget *injection;
    QWidget *custom;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1112, 689);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionFirmware_update = new QAction(MainWindow);
        actionFirmware_update->setObjectName(QStringLiteral("actionFirmware_update"));
        actionUart_tool = new QAction(MainWindow);
        actionUart_tool->setObjectName(QStringLiteral("actionUart_tool"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        horizontalLayout_12 = new QHBoxLayout(centralwidget);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(150, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_12);

        comunication_protocal = new QComboBox(groupBox);
        comunication_protocal->setObjectName(QStringLiteral("comunication_protocal"));
        comunication_protocal->setMinimumSize(QSize(0, 0));

        verticalLayout_19->addWidget(comunication_protocal);


        verticalLayout_3->addLayout(verticalLayout_19);

        te_addrEdit = new QTextEdit(groupBox);
        te_addrEdit->setObjectName(QStringLiteral("te_addrEdit"));
        te_addrEdit->setMaximumSize(QSize(16777215, 25));

        verticalLayout_3->addWidget(te_addrEdit);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        pb_addAddr = new QPushButton(groupBox);
        pb_addAddr->setObjectName(QStringLiteral("pb_addAddr"));

        horizontalLayout_6->addWidget(pb_addAddr);

        pb_deleteAddr = new QPushButton(groupBox);
        pb_deleteAddr->setObjectName(QStringLiteral("pb_deleteAddr"));

        horizontalLayout_6->addWidget(pb_deleteAddr);


        verticalLayout_3->addLayout(horizontalLayout_6);

        shortAddr = new QListWidget(groupBox);
        shortAddr->setObjectName(QStringLiteral("shortAddr"));

        verticalLayout_3->addWidget(shortAddr);

        bt_clear = new QPushButton(groupBox);
        bt_clear->setObjectName(QStringLiteral("bt_clear"));

        verticalLayout_3->addWidget(bt_clear);


        horizontalLayout_12->addWidget(groupBox);

        function = new QTabWidget(centralwidget);
        function->setObjectName(QStringLiteral("function"));
        Network = new QWidget();
        Network->setObjectName(QStringLiteral("Network"));
        verticalLayout_25 = new QVBoxLayout(Network);
        verticalLayout_25->setObjectName(QStringLiteral("verticalLayout_25"));
        groupBox_4 = new QGroupBox(Network);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_8 = new QHBoxLayout(groupBox_4);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        label_17 = new QLabel(groupBox_4);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setMaximumSize(QSize(30, 25));

        horizontalLayout_16->addWidget(label_17);

        textEdit_IP = new QTextEdit(groupBox_4);
        textEdit_IP->setObjectName(QStringLiteral("textEdit_IP"));
        textEdit_IP->setMaximumSize(QSize(100, 25));

        horizontalLayout_16->addWidget(textEdit_IP);

        bt_listen = new QPushButton(groupBox_4);
        bt_listen->setObjectName(QStringLiteral("bt_listen"));

        horizontalLayout_16->addWidget(bt_listen);


        verticalLayout_20->addLayout(horizontalLayout_16);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QStringLiteral("horizontalLayout_17"));
        label_18 = new QLabel(groupBox_4);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setMaximumSize(QSize(30, 25));

        horizontalLayout_17->addWidget(label_18);

        textEdit_Port = new QTextEdit(groupBox_4);
        textEdit_Port->setObjectName(QStringLiteral("textEdit_Port"));
        textEdit_Port->setMaximumSize(QSize(100, 25));

        horizontalLayout_17->addWidget(textEdit_Port);

        bt_stopListen = new QPushButton(groupBox_4);
        bt_stopListen->setObjectName(QStringLiteral("bt_stopListen"));

        horizontalLayout_17->addWidget(bt_stopListen);


        verticalLayout_20->addLayout(horizontalLayout_17);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setMaximumSize(QSize(30, 25));

        horizontalLayout_11->addWidget(label_22);

        textEdit_ID2 = new QTextEdit(groupBox_4);
        textEdit_ID2->setObjectName(QStringLiteral("textEdit_ID2"));
        textEdit_ID2->setMaximumSize(QSize(100, 25));

        horizontalLayout_11->addWidget(textEdit_ID2);

        bt_search_net = new QPushButton(groupBox_4);
        bt_search_net->setObjectName(QStringLiteral("bt_search_net"));

        horizontalLayout_11->addWidget(bt_search_net);


        verticalLayout_20->addLayout(horizontalLayout_11);


        horizontalLayout_8->addLayout(verticalLayout_20);

        horizontalSpacer_4 = new QSpacerItem(49, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_4);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_19 = new QLabel(groupBox_4);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMaximumSize(QSize(30, 25));

        horizontalLayout_9->addWidget(label_19);

        textEdit_ID = new QTextEdit(groupBox_4);
        textEdit_ID->setObjectName(QStringLiteral("textEdit_ID"));
        textEdit_ID->setMaximumSize(QSize(100, 25));

        horizontalLayout_9->addWidget(textEdit_ID);


        verticalLayout_8->addLayout(horizontalLayout_9);

        bt_searchId = new QPushButton(groupBox_4);
        bt_searchId->setObjectName(QStringLiteral("bt_searchId"));
        bt_searchId->setMaximumSize(QSize(16777215, 25));

        verticalLayout_8->addWidget(bt_searchId);

        export_idList = new QPushButton(groupBox_4);
        export_idList->setObjectName(QStringLiteral("export_idList"));

        verticalLayout_8->addWidget(export_idList);


        horizontalLayout_8->addLayout(verticalLayout_8);

        horizontalSpacer_9 = new QSpacerItem(49, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        horizontalSpacer_11 = new QSpacerItem(49, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);

        horizontalSpacer_10 = new QSpacerItem(49, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);

        horizontalSpacer_8 = new QSpacerItem(49, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        horizontalSpacer_6 = new QSpacerItem(49, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        horizontalSpacer_5 = new QSpacerItem(136, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_25->addWidget(groupBox_4);

        infDisplay = new QTextBrowser(Network);
        infDisplay->setObjectName(QStringLiteral("infDisplay"));

        verticalLayout_25->addWidget(infDisplay);

        groupBox_6 = new QGroupBox(Network);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(16777215, 100));
        verticalLayout_23 = new QVBoxLayout(groupBox_6);
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QStringLiteral("horizontalLayout_19"));
        verticalLayout_21 = new QVBoxLayout();
        verticalLayout_21->setObjectName(QStringLiteral("verticalLayout_21"));
        label_20 = new QLabel(groupBox_6);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setMaximumSize(QSize(16777215, 31));

        verticalLayout_21->addWidget(label_20);

        label_21 = new QLabel(groupBox_6);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setMaximumSize(QSize(16777215, 31));

        verticalLayout_21->addWidget(label_21);


        horizontalLayout_19->addLayout(verticalLayout_21);

        verticalLayout_22 = new QVBoxLayout();
        verticalLayout_22->setObjectName(QStringLiteral("verticalLayout_22"));
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QStringLiteral("horizontalLayout_20"));
        infEdit = new QTextEdit(groupBox_6);
        infEdit->setObjectName(QStringLiteral("infEdit"));
        infEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_20->addWidget(infEdit);

        bt_netSend = new QPushButton(groupBox_6);
        bt_netSend->setObjectName(QStringLiteral("bt_netSend"));
        bt_netSend->setMaximumSize(QSize(16777215, 31));

        horizontalLayout_20->addWidget(bt_netSend);


        verticalLayout_22->addLayout(horizontalLayout_20);

        infReceive = new QTextBrowser(groupBox_6);
        infReceive->setObjectName(QStringLiteral("infReceive"));
        infReceive->setMaximumSize(QSize(16777215, 25));

        verticalLayout_22->addWidget(infReceive);


        horizontalLayout_19->addLayout(verticalLayout_22);


        verticalLayout_23->addLayout(horizontalLayout_19);


        verticalLayout_25->addWidget(groupBox_6);

        function->addTab(Network, QString());
        Uart = new QWidget();
        Uart->setObjectName(QStringLiteral("Uart"));
        verticalLayout_24 = new QVBoxLayout(Uart);
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(Uart);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        comboBox_port = new QComboBox(Uart);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));
        comboBox_port->setMinimumSize(QSize(120, 0));
        comboBox_port->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(comboBox_port);


        verticalLayout_17->addLayout(horizontalLayout_5);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QStringLiteral("horizontalLayout_22"));
        label_6 = new QLabel(Uart);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_22->addWidget(label_6);

        comboBox_flcntrl = new QComboBox(Uart);
        comboBox_flcntrl->setObjectName(QStringLiteral("comboBox_flcntrl"));
        comboBox_flcntrl->setMinimumSize(QSize(120, 0));
        comboBox_flcntrl->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_22->addWidget(comboBox_flcntrl);


        verticalLayout_17->addLayout(horizontalLayout_22);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName(QStringLiteral("horizontalLayout_23"));
        label_3 = new QLabel(Uart);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_23->addWidget(label_3);

        comboBox_baudrate = new QComboBox(Uart);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));
        comboBox_baudrate->setMinimumSize(QSize(120, 0));
        comboBox_baudrate->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_23->addWidget(comboBox_baudrate);


        verticalLayout_17->addLayout(horizontalLayout_23);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName(QStringLiteral("horizontalLayout_24"));
        label_5 = new QLabel(Uart);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_24->addWidget(label_5);

        comboBox_parity = new QComboBox(Uart);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));
        comboBox_parity->setMinimumSize(QSize(120, 0));
        comboBox_parity->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_24->addWidget(comboBox_parity);


        verticalLayout_17->addLayout(horizontalLayout_24);


        horizontalLayout_7->addLayout(verticalLayout_17);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        bt_apply = new QPushButton(Uart);
        bt_apply->setObjectName(QStringLiteral("bt_apply"));

        verticalLayout_15->addWidget(bt_apply);

        bt_cancel = new QPushButton(Uart);
        bt_cancel->setObjectName(QStringLiteral("bt_cancel"));

        verticalLayout_15->addWidget(bt_cancel);


        verticalLayout_16->addLayout(verticalLayout_15);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        bt_openport = new QPushButton(Uart);
        bt_openport->setObjectName(QStringLiteral("bt_openport"));

        verticalLayout_4->addWidget(bt_openport);

        bt_closeport = new QPushButton(Uart);
        bt_closeport->setObjectName(QStringLiteral("bt_closeport"));

        verticalLayout_4->addWidget(bt_closeport);


        verticalLayout_16->addLayout(verticalLayout_4);


        horizontalLayout_7->addLayout(verticalLayout_16);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_7);


        verticalLayout_24->addLayout(horizontalLayout_7);

        groupBox_2 = new QGroupBox(Uart);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        spinBox_Period = new QSpinBox(groupBox_2);
        spinBox_Period->setObjectName(QStringLiteral("spinBox_Period"));
        spinBox_Period->setMaximum(10000);
        spinBox_Period->setSingleStep(10);

        horizontalLayout_2->addWidget(spinBox_Period);

        horizontalSpacer_2 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        bt_send = new QPushButton(groupBox_2);
        bt_send->setObjectName(QStringLiteral("bt_send"));

        horizontalLayout_2->addWidget(bt_send);

        bt_stopsend = new QPushButton(groupBox_2);
        bt_stopsend->setObjectName(QStringLiteral("bt_stopsend"));

        horizontalLayout_2->addWidget(bt_stopsend);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(58, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rbt_Decout = new QRadioButton(groupBox_2);
        rbt_Decout->setObjectName(QStringLiteral("rbt_Decout"));

        horizontalLayout->addWidget(rbt_Decout);

        rbt_ASCIIout = new QRadioButton(groupBox_2);
        rbt_ASCIIout->setObjectName(QStringLiteral("rbt_ASCIIout"));

        horizontalLayout->addWidget(rbt_ASCIIout);

        rbt_BINout = new QRadioButton(groupBox_2);
        rbt_BINout->setObjectName(QStringLiteral("rbt_BINout"));

        horizontalLayout->addWidget(rbt_BINout);

        rbt_HEXout = new QRadioButton(groupBox_2);
        rbt_HEXout->setObjectName(QStringLiteral("rbt_HEXout"));

        horizontalLayout->addWidget(rbt_HEXout);


        verticalLayout->addLayout(horizontalLayout);

        textEd_out = new QTextEdit(groupBox_2);
        textEd_out->setObjectName(QStringLiteral("textEd_out"));

        verticalLayout->addWidget(textEd_out);


        verticalLayout_24->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(Uart);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);

        horizontalSpacer_1 = new QSpacerItem(58, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_1);

        rbt_Decin = new QRadioButton(groupBox_3);
        rbt_Decin->setObjectName(QStringLiteral("rbt_Decin"));

        horizontalLayout_4->addWidget(rbt_Decin);

        rbt_ASCIIin = new QRadioButton(groupBox_3);
        rbt_ASCIIin->setObjectName(QStringLiteral("rbt_ASCIIin"));

        horizontalLayout_4->addWidget(rbt_ASCIIin);

        rbt_BINin = new QRadioButton(groupBox_3);
        rbt_BINin->setObjectName(QStringLiteral("rbt_BINin"));

        horizontalLayout_4->addWidget(rbt_BINin);

        rbt_HEXin = new QRadioButton(groupBox_3);
        rbt_HEXin->setObjectName(QStringLiteral("rbt_HEXin"));

        horizontalLayout_4->addWidget(rbt_HEXin);


        verticalLayout_2->addLayout(horizontalLayout_4);

        textBr_inp = new QTextBrowser(groupBox_3);
        textBr_inp->setObjectName(QStringLiteral("textBr_inp"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textBr_inp->sizePolicy().hasHeightForWidth());
        textBr_inp->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(textBr_inp);


        verticalLayout_24->addWidget(groupBox_3);

        function->addTab(Uart, QString());
        Firmware_update = new QWidget();
        Firmware_update->setObjectName(QStringLiteral("Firmware_update"));
        verticalLayout_5 = new QVBoxLayout(Firmware_update);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_5 = new QGroupBox(Firmware_update);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_8);

        comboBox_updateMode = new QComboBox(groupBox_5);
        comboBox_updateMode->setObjectName(QStringLiteral("comboBox_updateMode"));
        comboBox_updateMode->setMinimumSize(QSize(100, 0));

        verticalLayout_7->addWidget(comboBox_updateMode);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_18 = new QVBoxLayout();
        verticalLayout_18->setObjectName(QStringLiteral("verticalLayout_18"));
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QStringLiteral("label_11"));

        verticalLayout_18->addWidget(label_11);

        packetbyte = new QComboBox(groupBox_5);
        packetbyte->setObjectName(QStringLiteral("packetbyte"));

        verticalLayout_18->addWidget(packetbyte);


        horizontalLayout_3->addLayout(verticalLayout_18);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_10);

        frimwareVersion = new QComboBox(groupBox_5);
        frimwareVersion->setObjectName(QStringLiteral("frimwareVersion"));

        verticalLayout_6->addWidget(frimwareVersion);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        label_13 = new QLabel(groupBox_5);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout_9->addWidget(label_13);

        cb_deviceType = new QComboBox(groupBox_5);
        cb_deviceType->setObjectName(QStringLiteral("cb_deviceType"));
        cb_deviceType->setMinimumSize(QSize(80, 0));

        verticalLayout_9->addWidget(cb_deviceType);


        horizontalLayout_3->addLayout(verticalLayout_9);

        horizontalSpacer_3 = new QSpacerItem(40, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        bt_getDeviceInf = new QPushButton(groupBox_5);
        bt_getDeviceInf->setObjectName(QStringLiteral("bt_getDeviceInf"));

        verticalLayout_12->addWidget(bt_getDeviceInf);

        bt_sendFirInf = new QPushButton(groupBox_5);
        bt_sendFirInf->setObjectName(QStringLiteral("bt_sendFirInf"));

        verticalLayout_12->addWidget(bt_sendFirInf);


        horizontalLayout_3->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        bt_sendPacket = new QPushButton(groupBox_5);
        bt_sendPacket->setObjectName(QStringLiteral("bt_sendPacket"));

        verticalLayout_13->addWidget(bt_sendPacket);

        pushButton_nc0 = new QPushButton(groupBox_5);
        pushButton_nc0->setObjectName(QStringLiteral("pushButton_nc0"));

        verticalLayout_13->addWidget(pushButton_nc0);


        horizontalLayout_3->addLayout(verticalLayout_13);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        bt_autoUpdate = new QPushButton(groupBox_5);
        bt_autoUpdate->setObjectName(QStringLiteral("bt_autoUpdate"));

        verticalLayout_10->addWidget(bt_autoUpdate);

        bt_stopAutoUpdate = new QPushButton(groupBox_5);
        bt_stopAutoUpdate->setObjectName(QStringLiteral("bt_stopAutoUpdate"));

        verticalLayout_10->addWidget(bt_stopAutoUpdate);


        horizontalLayout_3->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        bt_readBoot = new QPushButton(groupBox_5);
        bt_readBoot->setObjectName(QStringLiteral("bt_readBoot"));

        verticalLayout_11->addWidget(bt_readBoot);

        bt_readFirmware = new QPushButton(groupBox_5);
        bt_readFirmware->setObjectName(QStringLiteral("bt_readFirmware"));

        verticalLayout_11->addWidget(bt_readFirmware);


        horizontalLayout_3->addLayout(verticalLayout_11);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        bt_stopRead = new QPushButton(groupBox_5);
        bt_stopRead->setObjectName(QStringLiteral("bt_stopRead"));

        verticalLayout_14->addWidget(bt_stopRead);

        rb_displayRawHex = new QRadioButton(groupBox_5);
        rb_displayRawHex->setObjectName(QStringLiteral("rb_displayRawHex"));

        verticalLayout_14->addWidget(rb_displayRawHex);


        horizontalLayout_3->addLayout(verticalLayout_14);


        verticalLayout_5->addWidget(groupBox_5);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        updateFileList = new QComboBox(Firmware_update);
        updateFileList->setObjectName(QStringLiteral("updateFileList"));

        horizontalLayout_13->addWidget(updateFileList);

        bt_openFile = new QPushButton(Firmware_update);
        bt_openFile->setObjectName(QStringLiteral("bt_openFile"));
        bt_openFile->setMinimumSize(QSize(0, 0));
        bt_openFile->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_13->addWidget(bt_openFile);


        verticalLayout_5->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        readFileList = new QComboBox(Firmware_update);
        readFileList->setObjectName(QStringLiteral("readFileList"));

        horizontalLayout_14->addWidget(readFileList);

        bt_storeFile = new QPushButton(Firmware_update);
        bt_storeFile->setObjectName(QStringLiteral("bt_storeFile"));
        bt_storeFile->setMinimumSize(QSize(0, 0));
        bt_storeFile->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_14->addWidget(bt_storeFile);


        verticalLayout_5->addLayout(horizontalLayout_14);

        progressBar = new QProgressBar(Firmware_update);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_5->addWidget(progressBar);

        textBr_mess = new QTextBrowser(Firmware_update);
        textBr_mess->setObjectName(QStringLiteral("textBr_mess"));

        verticalLayout_5->addWidget(textBr_mess);

        function->addTab(Firmware_update, QString());
        location = new QWidget();
        location->setObjectName(QStringLiteral("location"));
        verticalLayout_28 = new QVBoxLayout(location);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        groupBox_7 = new QGroupBox(location);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 120));
        groupBox_7->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_18 = new QHBoxLayout(groupBox_7);
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(0, 25));
        label_9->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_15->addWidget(label_9);

        localtionFiltId = new QTextEdit(groupBox_7);
        localtionFiltId->setObjectName(QStringLiteral("localtionFiltId"));
        localtionFiltId->setMinimumSize(QSize(0, 25));
        localtionFiltId->setMaximumSize(QSize(150, 25));

        horizontalLayout_15->addWidget(localtionFiltId);


        verticalLayout_26->addLayout(horizontalLayout_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(0, 25));
        label_16->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_10->addWidget(label_16);

        localtionFiltStr = new QTextEdit(groupBox_7);
        localtionFiltStr->setObjectName(QStringLiteral("localtionFiltStr"));
        localtionFiltStr->setMinimumSize(QSize(0, 25));
        localtionFiltStr->setMaximumSize(QSize(150, 25));

        horizontalLayout_10->addWidget(localtionFiltStr);


        verticalLayout_26->addLayout(horizontalLayout_10);

        locationStopDisplay = new QRadioButton(groupBox_7);
        locationStopDisplay->setObjectName(QStringLiteral("locationStopDisplay"));

        verticalLayout_26->addWidget(locationStopDisplay);


        horizontalLayout_18->addLayout(verticalLayout_26);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_14);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_15);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_13);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer_12);


        verticalLayout_28->addWidget(groupBox_7);

        location_display = new QTextBrowser(location);
        location_display->setObjectName(QStringLiteral("location_display"));

        verticalLayout_28->addWidget(location_display);

        function->addTab(location, QString());
        cool = new QWidget();
        cool->setObjectName(QStringLiteral("cool"));
        verticalLayout_29 = new QVBoxLayout(cool);
        verticalLayout_29->setObjectName(QStringLiteral("verticalLayout_29"));
        groupBox_8 = new QGroupBox(cool);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setMinimumSize(QSize(0, 120));
        groupBox_8->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_21 = new QHBoxLayout(groupBox_8);
        horizontalLayout_21->setObjectName(QStringLiteral("horizontalLayout_21"));
        verticalLayout_27 = new QVBoxLayout();
        verticalLayout_27->setObjectName(QStringLiteral("verticalLayout_27"));
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QStringLiteral("horizontalLayout_25"));
        label_14 = new QLabel(groupBox_8);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setMinimumSize(QSize(0, 25));
        label_14->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_25->addWidget(label_14);

        coolFiltId = new QTextEdit(groupBox_8);
        coolFiltId->setObjectName(QStringLiteral("coolFiltId"));
        coolFiltId->setMinimumSize(QSize(0, 25));
        coolFiltId->setMaximumSize(QSize(100, 25));

        horizontalLayout_25->addWidget(coolFiltId);


        verticalLayout_27->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QStringLiteral("horizontalLayout_26"));
        label_23 = new QLabel(groupBox_8);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setMinimumSize(QSize(0, 25));
        label_23->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_26->addWidget(label_23);

        coolFiltStr = new QTextEdit(groupBox_8);
        coolFiltStr->setObjectName(QStringLiteral("coolFiltStr"));
        coolFiltStr->setMinimumSize(QSize(0, 25));
        coolFiltStr->setMaximumSize(QSize(100, 25));

        horizontalLayout_26->addWidget(coolFiltStr);


        verticalLayout_27->addLayout(horizontalLayout_26);

        coolStopDisplay = new QRadioButton(groupBox_8);
        coolStopDisplay->setObjectName(QStringLiteral("coolStopDisplay"));

        verticalLayout_27->addWidget(coolStopDisplay);


        horizontalLayout_21->addLayout(verticalLayout_27);

        verticalLayout_32 = new QVBoxLayout();
        verticalLayout_32->setObjectName(QStringLiteral("verticalLayout_32"));
        coolGetSn = new QPushButton(groupBox_8);
        coolGetSn->setObjectName(QStringLiteral("coolGetSn"));

        verticalLayout_32->addWidget(coolGetSn);

        coolGetTempreture = new QPushButton(groupBox_8);
        coolGetTempreture->setObjectName(QStringLiteral("coolGetTempreture"));

        verticalLayout_32->addWidget(coolGetTempreture);

        coolDisarm = new QPushButton(groupBox_8);
        coolDisarm->setObjectName(QStringLiteral("coolDisarm"));

        verticalLayout_32->addWidget(coolDisarm);


        horizontalLayout_21->addLayout(verticalLayout_32);

        verticalLayout_31 = new QVBoxLayout();
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QStringLiteral("horizontalLayout_27"));
        coolSetSn_Edit = new QTextEdit(groupBox_8);
        coolSetSn_Edit->setObjectName(QStringLiteral("coolSetSn_Edit"));
        coolSetSn_Edit->setMinimumSize(QSize(60, 25));
        coolSetSn_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_27->addWidget(coolSetSn_Edit);

        coolSetSn_Bt = new QPushButton(groupBox_8);
        coolSetSn_Bt->setObjectName(QStringLiteral("coolSetSn_Bt"));

        horizontalLayout_27->addWidget(coolSetSn_Bt);


        verticalLayout_31->addLayout(horizontalLayout_27);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QStringLiteral("horizontalLayout_30"));
        coolTemVerification_Edit = new QTextEdit(groupBox_8);
        coolTemVerification_Edit->setObjectName(QStringLiteral("coolTemVerification_Edit"));
        coolTemVerification_Edit->setMinimumSize(QSize(60, 25));
        coolTemVerification_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_30->addWidget(coolTemVerification_Edit);

        coolTemVerification_Bt = new QPushButton(groupBox_8);
        coolTemVerification_Bt->setObjectName(QStringLiteral("coolTemVerification_Bt"));

        horizontalLayout_30->addWidget(coolTemVerification_Bt);


        verticalLayout_31->addLayout(horizontalLayout_30);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QStringLiteral("horizontalLayout_29"));
        coolHumVerification_Edit = new QTextEdit(groupBox_8);
        coolHumVerification_Edit->setObjectName(QStringLiteral("coolHumVerification_Edit"));
        coolHumVerification_Edit->setMinimumSize(QSize(60, 25));
        coolHumVerification_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_29->addWidget(coolHumVerification_Edit);

        coolHumVerification_Bt = new QPushButton(groupBox_8);
        coolHumVerification_Bt->setObjectName(QStringLiteral("coolHumVerification_Bt"));

        horizontalLayout_29->addWidget(coolHumVerification_Bt);


        verticalLayout_31->addLayout(horizontalLayout_29);


        horizontalLayout_21->addLayout(verticalLayout_31);

        verticalLayout_30 = new QVBoxLayout();
        verticalLayout_30->setObjectName(QStringLiteral("verticalLayout_30"));
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QStringLiteral("horizontalLayout_31"));
        coolTemAlarmH_Edit = new QTextEdit(groupBox_8);
        coolTemAlarmH_Edit->setObjectName(QStringLiteral("coolTemAlarmH_Edit"));
        coolTemAlarmH_Edit->setMinimumSize(QSize(60, 25));
        coolTemAlarmH_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_31->addWidget(coolTemAlarmH_Edit);

        coolTemAlarmL_Edit = new QTextEdit(groupBox_8);
        coolTemAlarmL_Edit->setObjectName(QStringLiteral("coolTemAlarmL_Edit"));
        coolTemAlarmL_Edit->setMinimumSize(QSize(60, 25));
        coolTemAlarmL_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_31->addWidget(coolTemAlarmL_Edit);


        verticalLayout_30->addLayout(horizontalLayout_31);

        coolTemAlarm_Bt = new QPushButton(groupBox_8);
        coolTemAlarm_Bt->setObjectName(QStringLiteral("coolTemAlarm_Bt"));

        verticalLayout_30->addWidget(coolTemAlarm_Bt);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QStringLiteral("horizontalLayout_28"));
        coolSetRepTime_Edit = new QTextEdit(groupBox_8);
        coolSetRepTime_Edit->setObjectName(QStringLiteral("coolSetRepTime_Edit"));
        coolSetRepTime_Edit->setMinimumSize(QSize(60, 25));
        coolSetRepTime_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_28->addWidget(coolSetRepTime_Edit);

        coolSetRepTime_Bt = new QPushButton(groupBox_8);
        coolSetRepTime_Bt->setObjectName(QStringLiteral("coolSetRepTime_Bt"));

        horizontalLayout_28->addWidget(coolSetRepTime_Bt);


        verticalLayout_30->addLayout(horizontalLayout_28);


        horizontalLayout_21->addLayout(verticalLayout_30);

        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_17);

        horizontalSpacer_18 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_18);

        horizontalSpacer_19 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_19);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_21->addItem(horizontalSpacer_16);


        verticalLayout_29->addWidget(groupBox_8);

        cool_display = new QTextBrowser(cool);
        cool_display->setObjectName(QStringLiteral("cool_display"));

        verticalLayout_29->addWidget(cool_display);

        function->addTab(cool, QString());
        energy = new QWidget();
        energy->setObjectName(QStringLiteral("energy"));
        function->addTab(energy, QString());
        injection = new QWidget();
        injection->setObjectName(QStringLiteral("injection"));
        function->addTab(injection, QString());
        custom = new QWidget();
        custom->setObjectName(QStringLiteral("custom"));
        function->addTab(custom, QString());

        horizontalLayout_12->addWidget(function);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1112, 23));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(comboBox_port, comboBox_parity);
        QWidget::setTabOrder(comboBox_parity, comboBox_flcntrl);
        QWidget::setTabOrder(comboBox_flcntrl, bt_cancel);
        QWidget::setTabOrder(bt_cancel, textEd_out);
        QWidget::setTabOrder(textEd_out, bt_send);
        QWidget::setTabOrder(bt_send, textBr_inp);

        retranslateUi(MainWindow);

        function->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt_comport", 0));
        actionFirmware_update->setText(QApplication::translate("MainWindow", "firmware update", 0));
        actionUart_tool->setText(QApplication::translate("MainWindow", "uart tool", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "PORT SETTINGS", 0));
        label_12->setText(QApplication::translate("MainWindow", "\351\200\232\344\277\241\346\216\245\345\217\243", 0));
        comunication_protocal->clear();
        comunication_protocal->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Server", 0)
         << QApplication::translate("MainWindow", "Client", 0)
         << QApplication::translate("MainWindow", "Uart", 0)
        );
        pb_addAddr->setText(QApplication::translate("MainWindow", "Add", 0));
        pb_deleteAddr->setText(QApplication::translate("MainWindow", "Change", 0));
#ifndef QT_NO_STATUSTIP
        bt_clear->setStatusTip(QApplication::translate("MainWindow", "Clear input data", 0));
#endif // QT_NO_STATUSTIP
        bt_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        groupBox_4->setTitle(QString());
        label_17->setText(QApplication::translate("MainWindow", "IP", 0));
        bt_listen->setText(QApplication::translate("MainWindow", " \347\233\221\345\220\254", 0));
        label_18->setText(QApplication::translate("MainWindow", "PORT", 0));
        bt_stopListen->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\347\233\221\345\220\254", 0));
        label_22->setText(QApplication::translate("MainWindow", "ID", 0));
        bt_search_net->setText(QApplication::translate("MainWindow", "Search NET", 0));
        label_19->setText(QApplication::translate("MainWindow", "ID", 0));
        bt_searchId->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242ID\344\277\241\346\201\257", 0));
        export_idList->setText(QApplication::translate("MainWindow", "  \345\257\274\345\207\272ID\350\241\250", 0));
        groupBox_6->setTitle(QString());
        label_20->setText(QApplication::translate("MainWindow", "send message", 0));
        label_21->setText(QApplication::translate("MainWindow", "receive message", 0));
        bt_netSend->setText(QApplication::translate("MainWindow", "send", 0));
        function->setTabText(function->indexOf(Network), QApplication::translate("MainWindow", "Network", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0));
        label_6->setText(QApplication::translate("MainWindow", "Flowcontrol", 0));
        label_3->setText(QApplication::translate("MainWindow", "Baudrate", 0));
        label_5->setText(QApplication::translate("MainWindow", "Parity", 0));
#ifndef QT_NO_STATUSTIP
        bt_apply->setStatusTip(QApplication::translate("MainWindow", "Apply port settings", 0));
#endif // QT_NO_STATUSTIP
        bt_apply->setText(QApplication::translate("MainWindow", "APPLY", 0));
#ifndef QT_NO_STATUSTIP
        bt_cancel->setStatusTip(QApplication::translate("MainWindow", "Cancel new settings ", 0));
#endif // QT_NO_STATUSTIP
        bt_cancel->setText(QApplication::translate("MainWindow", "CANCEL", 0));
#ifndef QT_NO_STATUSTIP
        bt_openport->setStatusTip(QApplication::translate("MainWindow", "Open port", 0));
#endif // QT_NO_STATUSTIP
        bt_openport->setText(QApplication::translate("MainWindow", "OPEN", 0));
#ifndef QT_NO_STATUSTIP
        bt_closeport->setStatusTip(QApplication::translate("MainWindow", "Close port", 0));
#endif // QT_NO_STATUSTIP
        bt_closeport->setText(QApplication::translate("MainWindow", "CLOSE", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "OUTPUT DATA", 0));
        label_7->setText(QApplication::translate("MainWindow", "Period", 0));
        spinBox_Period->setSuffix(QApplication::translate("MainWindow", " ms", 0));
#ifndef QT_NO_STATUSTIP
        bt_send->setStatusTip(QApplication::translate("MainWindow", "Send data", 0));
#endif // QT_NO_STATUSTIP
        bt_send->setText(QApplication::translate("MainWindow", "SEND", 0));
#ifndef QT_NO_STATUSTIP
        bt_stopsend->setStatusTip(QApplication::translate("MainWindow", "Stop send", 0));
#endif // QT_NO_STATUSTIP
        bt_stopsend->setText(QApplication::translate("MainWindow", "STOP", 0));
        label->setText(QApplication::translate("MainWindow", "Data for send", 0));
        rbt_Decout->setText(QApplication::translate("MainWindow", "Decimal", 0));
        rbt_ASCIIout->setText(QApplication::translate("MainWindow", "ASCII", 0));
        rbt_BINout->setText(QApplication::translate("MainWindow", "BIN", 0));
        rbt_HEXout->setText(QApplication::translate("MainWindow", "HEX", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "INPUT DATA", 0));
        label_4->setText(QApplication::translate("MainWindow", "Data for input", 0));
        rbt_Decin->setText(QApplication::translate("MainWindow", "Decimal", 0));
        rbt_ASCIIin->setText(QApplication::translate("MainWindow", "ASCII", 0));
        rbt_BINin->setText(QApplication::translate("MainWindow", "BIN", 0));
        rbt_HEXin->setText(QApplication::translate("MainWindow", "HEX", 0));
        function->setTabText(function->indexOf(Uart), QApplication::translate("MainWindow", "Uart", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "   \351\205\215\347\275\256\351\200\211\351\241\271", 0));
        label_8->setText(QApplication::translate("MainWindow", "\346\250\241\345\274\217", 0));
        comboBox_updateMode->clear();
        comboBox_updateMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "OTA\346\211\213\345\212\250\345\215\207\347\272\247", 0)
         << QApplication::translate("MainWindow", "OTA\345\215\225\347\213\254\345\215\207\347\272\247", 0)
         << QApplication::translate("MainWindow", "OTA\346\211\271\351\207\217\345\215\207\347\272\247", 0)
         << QApplication::translate("MainWindow", "OTA\345\233\272\344\273\266\350\257\273\345\217\226", 0)
        );
        label_11->setText(QApplication::translate("MainWindow", " \346\225\260\346\215\256\345\214\205\345\244\247\345\260\217", 0));
        packetbyte->clear();
        packetbyte->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "88", 0)
         << QApplication::translate("MainWindow", "1000", 0)
        );
        label_10->setText(QApplication::translate("MainWindow", " \345\233\272\344\273\266\347\211\210\346\234\254", 0));
        frimwareVersion->clear();
        frimwareVersion->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "0", 0)
         << QApplication::translate("MainWindow", "1", 0)
         << QApplication::translate("MainWindow", "2", 0)
         << QApplication::translate("MainWindow", "3", 0)
         << QApplication::translate("MainWindow", "4", 0)
         << QApplication::translate("MainWindow", "5", 0)
         << QApplication::translate("MainWindow", "6", 0)
         << QApplication::translate("MainWindow", "7", 0)
         << QApplication::translate("MainWindow", "8", 0)
         << QApplication::translate("MainWindow", "9", 0)
         << QApplication::translate("MainWindow", "10", 0)
         << QApplication::translate("MainWindow", "11", 0)
         << QApplication::translate("MainWindow", "12", 0)
         << QApplication::translate("MainWindow", "13", 0)
         << QApplication::translate("MainWindow", "14", 0)
         << QApplication::translate("MainWindow", "15", 0)
         << QApplication::translate("MainWindow", "16", 0)
         << QApplication::translate("MainWindow", "17", 0)
         << QApplication::translate("MainWindow", "18", 0)
         << QApplication::translate("MainWindow", "19", 0)
         << QApplication::translate("MainWindow", "20", 0)
         << QApplication::translate("MainWindow", "21", 0)
         << QApplication::translate("MainWindow", "22", 0)
         << QApplication::translate("MainWindow", "23", 0)
         << QApplication::translate("MainWindow", "24", 0)
         << QApplication::translate("MainWindow", "25", 0)
         << QApplication::translate("MainWindow", "26", 0)
         << QApplication::translate("MainWindow", "27", 0)
         << QApplication::translate("MainWindow", "28", 0)
         << QApplication::translate("MainWindow", "29", 0)
         << QApplication::translate("MainWindow", "30", 0)
         << QApplication::translate("MainWindow", "31", 0)
         << QApplication::translate("MainWindow", "32", 0)
         << QApplication::translate("MainWindow", "33", 0)
         << QApplication::translate("MainWindow", "34", 0)
         << QApplication::translate("MainWindow", "35", 0)
         << QApplication::translate("MainWindow", "36", 0)
         << QString()
        );
        label_13->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\347\261\273\345\236\213", 0));
        cb_deviceType->clear();
        cb_deviceType->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\347\275\221\345\205\263", 0)
         << QApplication::translate("MainWindow", "\346\210\220\344\272\272\350\205\225\345\270\246", 0)
         << QApplication::translate("MainWindow", "\347\262\276\347\245\236\347\227\205\350\205\225\345\270\246", 0)
         << QApplication::translate("MainWindow", "\345\251\264\345\204\277\350\205\225\345\270\246", 0)
         << QApplication::translate("MainWindow", "SOS\346\214\211\351\224\256", 0)
         << QApplication::translate("MainWindow", "\346\217\222\345\272\247", 0)
         << QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\346\271\277\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\345\244\232\345\212\237\350\203\275\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\350\265\204\344\272\247\346\240\207\347\255\276", 0)
        );
        bt_getDeviceInf->setText(QApplication::translate("MainWindow", " \350\216\267\345\217\226\351\205\215\344\273\266\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        bt_sendFirInf->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\272\344\273\266\344\277\241\346\201\257", 0));
        bt_sendPacket->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\272\344\273\266\346\225\260\346\215\256\345\214\205", 0));
        pushButton_nc0->setText(QApplication::translate("MainWindow", "NC", 0));
        bt_autoUpdate->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\215\207\347\272\247\345\233\272\344\273\266", 0));
        bt_stopAutoUpdate->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\350\207\252\345\212\250\345\215\207\347\272\247", 0));
        bt_readBoot->setText(QApplication::translate("MainWindow", " \350\257\273\345\217\226boot", 0));
        bt_readFirmware->setText(QApplication::translate("MainWindow", "  \350\257\273\345\217\226\345\233\272\344\273\266", 0));
        bt_stopRead->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\350\257\273\345\217\226", 0));
        rb_displayRawHex->setText(QApplication::translate("MainWindow", "displayRawHex", 0));
        bt_openFile->setText(QApplication::translate("MainWindow", " \346\211\223\345\274\200\345\233\272\344\273\266", 0));
        bt_storeFile->setText(QApplication::translate("MainWindow", " \345\255\230\345\202\250\345\233\272\344\273\266", 0));
        function->setTabText(function->indexOf(Firmware_update), QApplication::translate("MainWindow", "Firmware update", 0));
        groupBox_7->setTitle(QString());
        label_9->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_16->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        locationStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        function->setTabText(function->indexOf(location), QApplication::translate("MainWindow", "location", 0));
        groupBox_8->setTitle(QString());
        label_14->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_23->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        coolStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        coolGetSn->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\274\226\345\217\267", 0));
        coolGetTempreture->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\270\251\346\271\277\345\272\246", 0));
        coolDisarm->setText(QApplication::translate("MainWindow", "\350\247\243\351\231\244\346\212\245\350\255\246", 0));
        coolSetSn_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\274\226\345\217\267", 0));
        coolTemVerification_Bt->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\241\346\255\243", 0));
        coolHumVerification_Bt->setText(QApplication::translate("MainWindow", " \346\271\277\345\272\246\346\240\241\346\255\243", 0));
        coolTemAlarm_Bt->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\212\344\270\213\351\231\220\346\270\251\345\272\246", 0));
        coolSetRepTime_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\212\346\212\245\346\227\266\351\227\264", 0));
        function->setTabText(function->indexOf(cool), QApplication::translate("MainWindow", "cool", 0));
        function->setTabText(function->indexOf(energy), QApplication::translate("MainWindow", "energy", 0));
        function->setTabText(function->indexOf(injection), QApplication::translate("MainWindow", "injection", 0));
        function->setTabText(function->indexOf(custom), QApplication::translate("MainWindow", " custom", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_FORM_H
