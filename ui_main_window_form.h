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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
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
#include <QtWidgets/QSlider>
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
    QPushButton *StoreDir;
    QTextEdit *te_addrEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pb_addAddr;
    QPushButton *pb_deleteAddr;
    QLabel *total_id_display;
    QListWidget *shortAddr;
    QPushButton *bt_clear;
    QTabWidget *function;
    QWidget *Network;
    QVBoxLayout *verticalLayout_25;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_68;
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
    QVBoxLayout *verticalLayout_38;
    QRadioButton *networkAutoIdStatus;
    QRadioButton *networkManuIdStatus;
    QHBoxLayout *horizontalLayout_60;
    QLabel *label_34;
    QTextEdit *textEdit_MIN_ID;
    QHBoxLayout *horizontalLayout_59;
    QLabel *label_33;
    QTextEdit *textEdit_MAX_ID;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_32;
    QTextEdit *textEdit_ID;
    QHBoxLayout *horizontalLayout_58;
    QPushButton *bt_searchId;
    QPushButton *bt_clearId;
    QHBoxLayout *horizontalLayout_57;
    QPushButton *networkResetIdTable;
    QPushButton *export_idList;
    QVBoxLayout *verticalLayout_61;
    QHBoxLayout *horizontalLayout_61;
    QLabel *label_35;
    QTextEdit *textEdit_ID_2;
    QHBoxLayout *horizontalLayout_62;
    QLabel *label_36;
    QTextEdit *textEdit_ID_3;
    QPushButton *export_idList_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_6;
    QVBoxLayout *verticalLayout_63;
    QHBoxLayout *horizontalLayout_63;
    QLabel *label_39;
    QTextEdit *textEdit_panID;
    QHBoxLayout *horizontalLayout_66;
    QLabel *label_41;
    QTextEdit *textEdit_shortID;
    QHBoxLayout *horizontalLayout_67;
    QLabel *label_42;
    QTextEdit *textEdit_power;
    QHBoxLayout *horizontalLayout_65;
    QLabel *label_40;
    QTextEdit *textEdit_channel;
    QVBoxLayout *verticalLayout_62;
    QPushButton *pushButton_setNetPar;
    QPushButton *pushButton_requestNetPar;
    QSpacerItem *verticalSpacer_2;
    QPushButton *export_idList_3;
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
    QHBoxLayout *horizontalLayout_46;
    QGroupBox *groupBox_15;
    QVBoxLayout *verticalLayout_47;
    QRadioButton *coolStopDisplay;
    QGroupBox *groupBox_16;
    QVBoxLayout *verticalLayout_48;
    QRadioButton *coolDisplayMac;
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
    QLabel *label_37;
    QTextEdit *coolTemAlarmH_Edit;
    QLabel *label_38;
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
    QVBoxLayout *verticalLayout_37;
    QGroupBox *groupBox_9;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *verticalLayout_33;
    QHBoxLayout *horizontalLayout_33;
    QLabel *label_15;
    QTextEdit *energyFiltId;
    QHBoxLayout *horizontalLayout_34;
    QLabel *label_24;
    QTextEdit *energyFiltStr;
    QHBoxLayout *horizontalLayout_45;
    QGroupBox *groupBox_13;
    QVBoxLayout *verticalLayout_45;
    QRadioButton *energyStopDisplay;
    QGroupBox *groupBox_14;
    QVBoxLayout *verticalLayout_46;
    QRadioButton *energyDisplayMac;
    QVBoxLayout *verticalLayout_36;
    QPushButton *energyGetMeasurement;
    QHBoxLayout *horizontalLayout_39;
    QTextEdit *energySetRepTime_Edit;
    QPushButton *energySetRepTime_Bt;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_21;
    QSpacerItem *horizontalSpacer_24;
    QSpacerItem *horizontalSpacer_25;
    QSpacerItem *horizontalSpacer_23;
    QSpacerItem *horizontalSpacer_22;
    QSpacerItem *horizontalSpacer_20;
    QSpacerItem *horizontalSpacer_11;
    QTextBrowser *energy_display;
    QWidget *injection;
    QVBoxLayout *verticalLayout_42;
    QGroupBox *groupBox_10;
    QHBoxLayout *horizontalLayout_56;
    QVBoxLayout *verticalLayout_35;
    QHBoxLayout *horizontalLayout_35;
    QLabel *label_19;
    QTextEdit *injectionFiltId;
    QHBoxLayout *horizontalLayout_36;
    QLabel *label_25;
    QTextEdit *injectionFiltStr;
    QHBoxLayout *horizontalLayout_47;
    QGroupBox *groupBox_17;
    QVBoxLayout *verticalLayout_49;
    QRadioButton *injectionStopDisplay;
    QGroupBox *groupBox_18;
    QVBoxLayout *verticalLayout_50;
    QRadioButton *injectionDisplayMac;
    QVBoxLayout *verticalLayout_59;
    QHBoxLayout *horizontalLayout_32;
    QVBoxLayout *verticalLayout_41;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_27;
    QTextEdit *injectionTemAlarmH_Edit;
    QVBoxLayout *verticalLayout_57;
    QSpacerItem *verticalSpacer_7;
    QLabel *label_28;
    QTextEdit *injectionTemAlarmM_Edit;
    QVBoxLayout *verticalLayout_58;
    QSpacerItem *verticalSpacer_8;
    QLabel *label_29;
    QTextEdit *injectionTemAlarmL_Edit;
    QPushButton *injectionTemAlarm_Bt;
    QVBoxLayout *verticalLayout_40;
    QHBoxLayout *horizontalLayout_37;
    QTextEdit *injectionSetSn_Edit;
    QPushButton *injectionSetSn_Bt;
    QHBoxLayout *horizontalLayout_42;
    QTextEdit *injectionSetRepTime_Edit;
    QPushButton *injectionSetRepTime_Bt;
    QPushButton *injectionSetSpeaker_Bt;
    QVBoxLayout *verticalLayout_56;
    QPushButton *injectionStart_Bt;
    QPushButton *injectionStop_Bt;
    QPushButton *injectionFinish_Bt;
    QVBoxLayout *verticalLayout_39;
    QHBoxLayout *horizontalLayout_40;
    QTextEdit *injectionSetTotalDi_Edit;
    QPushButton *injectionSetTotalDi_Bt;
    QHBoxLayout *horizontalLayout_51;
    QTextEdit *injectionSetStopTimeOut_Edit;
    QPushButton *injectionSetStopTimeOut_Bt;
    QHBoxLayout *horizontalLayout_52;
    QComboBox *injectionDeviceParameters_list;
    QPushButton *injectionGetDeviceParameters_Bt;
    QVBoxLayout *verticalLayout_60;
    QHBoxLayout *horizontalLayout_55;
    QTextEdit *injectionDiInit_Edit;
    QPushButton *injectionDiInit_Bt;
    QHBoxLayout *horizontalLayout_54;
    QTextEdit *injectionSetDi_Edit;
    QPushButton *injectionSetDi_Bt;
    QHBoxLayout *horizontalLayout_53;
    QTextEdit *injectionSetName_Edit;
    QPushButton *injectionSetName_Bt;
    QSpacerItem *horizontalSpacer_14;
    QSpacerItem *horizontalSpacer_26;
    QTextBrowser *injection_display;
    QWidget *tab;
    QVBoxLayout *verticalLayout_55;
    QGroupBox *groupBox_19;
    QHBoxLayout *horizontalLayout_38;
    QVBoxLayout *verticalLayout_51;
    QHBoxLayout *horizontalLayout_41;
    QLabel *label_30;
    QTextEdit *sosFiltId;
    QHBoxLayout *horizontalLayout_48;
    QLabel *label_31;
    QTextEdit *sosFiltStr;
    QHBoxLayout *horizontalLayout_49;
    QGroupBox *groupBox_20;
    QVBoxLayout *verticalLayout_52;
    QRadioButton *sosStopDisplay;
    QGroupBox *groupBox_21;
    QVBoxLayout *verticalLayout_53;
    QRadioButton *sosDisplayMac;
    QVBoxLayout *verticalLayout_54;
    QHBoxLayout *horizontalLayout_50;
    QTextEdit *sosSetRepTime_Edit;
    QPushButton *sosSetRepTime_Bt;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *horizontalSpacer_28;
    QSpacerItem *horizontalSpacer_29;
    QSpacerItem *horizontalSpacer_30;
    QSpacerItem *horizontalSpacer_37;
    QSpacerItem *horizontalSpacer_38;
    QSpacerItem *horizontalSpacer_39;
    QSpacerItem *horizontalSpacer_42;
    QTextBrowser *sos_display;
    QWidget *location;
    QVBoxLayout *verticalLayout_28;
    QGroupBox *groupBox_7;
    QHBoxLayout *horizontalLayout_82;
    QVBoxLayout *verticalLayout_26;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_9;
    QTextEdit *localtionFiltId;
    QTextEdit *localtionFiltId_1;
    QHBoxLayout *horizontalLayout_44;
    QTextEdit *localtionFiltId_2;
    QTextEdit *localtionFiltId_3;
    QTextEdit *localtionFiltId_4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_16;
    QTextEdit *localtionFiltStr;
    QVBoxLayout *verticalLayout_64;
    QGroupBox *groupBox_11;
    QVBoxLayout *verticalLayout_43;
    QRadioButton *locationStopDisplay;
    QGroupBox *groupBox_12;
    QVBoxLayout *verticalLayout_44;
    QRadioButton *locationDisplayMac;
    QSpacerItem *horizontalSpacer_9;
    QVBoxLayout *verticalLayout_71;
    QHBoxLayout *horizontalLayout_43;
    QLabel *label_46;
    QTextEdit *location125KIDtextEdit;
    QHBoxLayout *horizontalLayout_74;
    QLabel *label_47;
    QTextEdit *location125KRssitextEdit;
    QPushButton *bt_setHeartBeatTime_3;
    QSpacerItem *horizontalSpacer_36;
    QVBoxLayout *verticalLayout_34;
    QHBoxLayout *horizontalLayout_18;
    QTextEdit *textEdit_heartbeat_time;
    QLabel *label_26;
    QPushButton *bt_setHeartBeatTime;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *horizontalSpacer_5;
    QSpacerItem *horizontalSpacer_12;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *horizontalSpacer_15;
    QSpacerItem *horizontalSpacer_40;
    QSpacerItem *horizontalSpacer_27;
    QSpacerItem *horizontalSpacer_13;
    QTextBrowser *location_display;
    QWidget *BLE_data;
    QVBoxLayout *verticalLayout_70;
    QGroupBox *groupBox_22;
    QHBoxLayout *horizontalLayout_79;
    QVBoxLayout *verticalLayout_65;
    QHBoxLayout *horizontalLayout_70;
    QLabel *label_43;
    QTextEdit *BLE_FiltId;
    QTextEdit *BLE_FiltId_1;
    QHBoxLayout *horizontalLayout_71;
    QTextEdit *BLE_FiltId_2;
    QTextEdit *BLE_FiltId_3;
    QTextEdit *BLE_FiltId_4;
    QHBoxLayout *horizontalLayout_72;
    QLabel *label_44;
    QTextEdit *BLE_FiltStr;
    QVBoxLayout *verticalLayout_66;
    QGroupBox *groupBox_23;
    QVBoxLayout *verticalLayout_67;
    QRadioButton *BLE_StopDisplay;
    QGroupBox *groupBox_24;
    QVBoxLayout *verticalLayout_68;
    QRadioButton *BLE_DisplayMac;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_31;
    QSpacerItem *horizontalSpacer_32;
    QSpacerItem *horizontalSpacer_33;
    QSpacerItem *horizontalSpacer_35;
    QSpacerItem *horizontalSpacer_34;
    QVBoxLayout *verticalLayout_73;
    QHBoxLayout *horizontalLayout_77;
    QLabel *label_50;
    QTextEdit *BLE_125KIDtextEdit;
    QHBoxLayout *horizontalLayout_78;
    QLabel *label_53;
    QTextEdit *BLE_125KRssitextEdit;
    QPushButton *BLE__set125KRssi;
    QVBoxLayout *verticalLayout_69;
    QHBoxLayout *horizontalLayout_73;
    QTextEdit *BLE_textEdit_heartbeat_time;
    QLabel *label_45;
    QPushButton *BLE_bt_setHeartBeatTime;
    QSpacerItem *verticalSpacer_4;
    QCheckBox *BLE_displayLog;
    QTextBrowser *BLE_display;
    QWidget *BLE_map;
    QVBoxLayout *verticalLayout_72;
    QHBoxLayout *horizontalLayout_64;
    QGroupBox *groupBox_25;
    QVBoxLayout *verticalLayout_74;
    QHBoxLayout *horizontalLayout_81;
    QLabel *label_51;
    QTextEdit *BLE_xPointEdit;
    QLabel *label_52;
    QTextEdit *BLE_yPointEdit;
    QHBoxLayout *horizontalLayout_69;
    QPushButton *BLE_addAnt;
    QPushButton *BLE_deleteAnt;
    QLabel *BLE_rssiCalculatorLabel;
    QSlider *BLE_rssiCalculatorSlider;
    QLabel *BLE_roundMeter;
    QSlider *horizontalSlider;
    QPushButton *BLE_showDeviceInf;
    QPushButton *BLE_hideDeviceInf;
    QPushButton *BLE_showAllDeviceInf;
    QPushButton *BLE_hideAllDeviceInf;
    QHBoxLayout *horizontalLayout_76;
    QLabel *label_56;
    QTextEdit *BLE_virtualAntIdEdit;
    QHBoxLayout *horizontalLayout_80;
    QLabel *label_57;
    QTextEdit *BLE_virtualDeviceIdEdit;
    QHBoxLayout *horizontalLayout_84;
    QLabel *label_59;
    QTextEdit *BLE_virtualSeqEdit;
    QHBoxLayout *horizontalLayout_83;
    QLabel *label_58;
    QTextEdit *BLE_virtualRssiEdit;
    QPushButton *BLE_virtualSetBt;
    QCheckBox *BLE_attenuationcheckBox;
    QCheckBox *BLE_attenuationWithoutCentercheckBox;
    QCheckBox *BLE_FiltercheckBox;
    QCheckBox *BLE_xyPointCheckBox;
    QCheckBox *BLE_radiusCheckBox;
    QCheckBox *BLE_AreaCheckBox;
    QCheckBox *BLE_AreaAloneCheckBox;
    QHBoxLayout *horizontalLayout_85;
    QLabel *label_60;
    QTextEdit *BLE_virtualRatio;
    QSpacerItem *verticalSpacer_9;
    QGraphicsView *graphicsView_BLE;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1298, 731);
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

        StoreDir = new QPushButton(groupBox);
        StoreDir->setObjectName(QStringLiteral("StoreDir"));

        verticalLayout_3->addWidget(StoreDir);

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

        total_id_display = new QLabel(groupBox);
        total_id_display->setObjectName(QStringLiteral("total_id_display"));

        verticalLayout_3->addWidget(total_id_display);

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
        groupBox_4->setMaximumSize(QSize(16777215, 150));
        horizontalLayout_68 = new QHBoxLayout(groupBox_4);
        horizontalLayout_68->setObjectName(QStringLiteral("horizontalLayout_68"));
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


        horizontalLayout_68->addLayout(verticalLayout_20);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName(QStringLiteral("verticalLayout_38"));
        networkAutoIdStatus = new QRadioButton(groupBox_4);
        networkAutoIdStatus->setObjectName(QStringLiteral("networkAutoIdStatus"));

        verticalLayout_38->addWidget(networkAutoIdStatus);

        networkManuIdStatus = new QRadioButton(groupBox_4);
        networkManuIdStatus->setObjectName(QStringLiteral("networkManuIdStatus"));

        verticalLayout_38->addWidget(networkManuIdStatus);

        horizontalLayout_60 = new QHBoxLayout();
        horizontalLayout_60->setObjectName(QStringLiteral("horizontalLayout_60"));
        label_34 = new QLabel(groupBox_4);
        label_34->setObjectName(QStringLiteral("label_34"));
        label_34->setMaximumSize(QSize(36, 16777215));
        label_34->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_60->addWidget(label_34);

        textEdit_MIN_ID = new QTextEdit(groupBox_4);
        textEdit_MIN_ID->setObjectName(QStringLiteral("textEdit_MIN_ID"));
        textEdit_MIN_ID->setMaximumSize(QSize(100, 25));

        horizontalLayout_60->addWidget(textEdit_MIN_ID);


        verticalLayout_38->addLayout(horizontalLayout_60);

        horizontalLayout_59 = new QHBoxLayout();
        horizontalLayout_59->setObjectName(QStringLiteral("horizontalLayout_59"));
        label_33 = new QLabel(groupBox_4);
        label_33->setObjectName(QStringLiteral("label_33"));
        label_33->setMaximumSize(QSize(36, 16777215));
        label_33->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_59->addWidget(label_33);

        textEdit_MAX_ID = new QTextEdit(groupBox_4);
        textEdit_MAX_ID->setObjectName(QStringLiteral("textEdit_MAX_ID"));
        textEdit_MAX_ID->setMaximumSize(QSize(100, 25));

        horizontalLayout_59->addWidget(textEdit_MAX_ID);


        verticalLayout_38->addLayout(horizontalLayout_59);


        horizontalLayout_68->addLayout(verticalLayout_38);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_32 = new QLabel(groupBox_4);
        label_32->setObjectName(QStringLiteral("label_32"));
        label_32->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_8->addWidget(label_32);

        textEdit_ID = new QTextEdit(groupBox_4);
        textEdit_ID->setObjectName(QStringLiteral("textEdit_ID"));
        textEdit_ID->setMaximumSize(QSize(100, 25));

        horizontalLayout_8->addWidget(textEdit_ID);


        verticalLayout_8->addLayout(horizontalLayout_8);

        horizontalLayout_58 = new QHBoxLayout();
        horizontalLayout_58->setObjectName(QStringLiteral("horizontalLayout_58"));
        bt_searchId = new QPushButton(groupBox_4);
        bt_searchId->setObjectName(QStringLiteral("bt_searchId"));
        bt_searchId->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_58->addWidget(bt_searchId);

        bt_clearId = new QPushButton(groupBox_4);
        bt_clearId->setObjectName(QStringLiteral("bt_clearId"));

        horizontalLayout_58->addWidget(bt_clearId);


        verticalLayout_8->addLayout(horizontalLayout_58);

        horizontalLayout_57 = new QHBoxLayout();
        horizontalLayout_57->setObjectName(QStringLiteral("horizontalLayout_57"));
        networkResetIdTable = new QPushButton(groupBox_4);
        networkResetIdTable->setObjectName(QStringLiteral("networkResetIdTable"));

        horizontalLayout_57->addWidget(networkResetIdTable);

        export_idList = new QPushButton(groupBox_4);
        export_idList->setObjectName(QStringLiteral("export_idList"));

        horizontalLayout_57->addWidget(export_idList);


        verticalLayout_8->addLayout(horizontalLayout_57);


        horizontalLayout_68->addLayout(verticalLayout_8);

        verticalLayout_61 = new QVBoxLayout();
        verticalLayout_61->setObjectName(QStringLiteral("verticalLayout_61"));
        horizontalLayout_61 = new QHBoxLayout();
        horizontalLayout_61->setObjectName(QStringLiteral("horizontalLayout_61"));
        label_35 = new QLabel(groupBox_4);
        label_35->setObjectName(QStringLiteral("label_35"));
        label_35->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_61->addWidget(label_35);

        textEdit_ID_2 = new QTextEdit(groupBox_4);
        textEdit_ID_2->setObjectName(QStringLiteral("textEdit_ID_2"));
        textEdit_ID_2->setMaximumSize(QSize(100, 25));

        horizontalLayout_61->addWidget(textEdit_ID_2);


        verticalLayout_61->addLayout(horizontalLayout_61);

        horizontalLayout_62 = new QHBoxLayout();
        horizontalLayout_62->setObjectName(QStringLiteral("horizontalLayout_62"));
        label_36 = new QLabel(groupBox_4);
        label_36->setObjectName(QStringLiteral("label_36"));
        label_36->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_62->addWidget(label_36);

        textEdit_ID_3 = new QTextEdit(groupBox_4);
        textEdit_ID_3->setObjectName(QStringLiteral("textEdit_ID_3"));
        textEdit_ID_3->setMaximumSize(QSize(100, 25));

        horizontalLayout_62->addWidget(textEdit_ID_3);


        verticalLayout_61->addLayout(horizontalLayout_62);

        export_idList_2 = new QPushButton(groupBox_4);
        export_idList_2->setObjectName(QStringLiteral("export_idList_2"));

        verticalLayout_61->addWidget(export_idList_2);


        horizontalLayout_68->addLayout(verticalLayout_61);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_68->addItem(horizontalSpacer_4);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_68->addItem(horizontalSpacer_6);

        verticalLayout_63 = new QVBoxLayout();
        verticalLayout_63->setObjectName(QStringLiteral("verticalLayout_63"));
        horizontalLayout_63 = new QHBoxLayout();
        horizontalLayout_63->setObjectName(QStringLiteral("horizontalLayout_63"));
        label_39 = new QLabel(groupBox_4);
        label_39->setObjectName(QStringLiteral("label_39"));
        label_39->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_63->addWidget(label_39);

        textEdit_panID = new QTextEdit(groupBox_4);
        textEdit_panID->setObjectName(QStringLiteral("textEdit_panID"));
        textEdit_panID->setMaximumSize(QSize(100, 25));

        horizontalLayout_63->addWidget(textEdit_panID);


        verticalLayout_63->addLayout(horizontalLayout_63);

        horizontalLayout_66 = new QHBoxLayout();
        horizontalLayout_66->setObjectName(QStringLiteral("horizontalLayout_66"));
        label_41 = new QLabel(groupBox_4);
        label_41->setObjectName(QStringLiteral("label_41"));
        label_41->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_66->addWidget(label_41);

        textEdit_shortID = new QTextEdit(groupBox_4);
        textEdit_shortID->setObjectName(QStringLiteral("textEdit_shortID"));
        textEdit_shortID->setMaximumSize(QSize(100, 25));

        horizontalLayout_66->addWidget(textEdit_shortID);


        verticalLayout_63->addLayout(horizontalLayout_66);

        horizontalLayout_67 = new QHBoxLayout();
        horizontalLayout_67->setObjectName(QStringLiteral("horizontalLayout_67"));
        label_42 = new QLabel(groupBox_4);
        label_42->setObjectName(QStringLiteral("label_42"));
        label_42->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_67->addWidget(label_42);

        textEdit_power = new QTextEdit(groupBox_4);
        textEdit_power->setObjectName(QStringLiteral("textEdit_power"));
        textEdit_power->setMaximumSize(QSize(100, 25));

        horizontalLayout_67->addWidget(textEdit_power);


        verticalLayout_63->addLayout(horizontalLayout_67);

        horizontalLayout_65 = new QHBoxLayout();
        horizontalLayout_65->setObjectName(QStringLiteral("horizontalLayout_65"));
        label_40 = new QLabel(groupBox_4);
        label_40->setObjectName(QStringLiteral("label_40"));
        label_40->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_65->addWidget(label_40);

        textEdit_channel = new QTextEdit(groupBox_4);
        textEdit_channel->setObjectName(QStringLiteral("textEdit_channel"));
        textEdit_channel->setMaximumSize(QSize(100, 25));

        horizontalLayout_65->addWidget(textEdit_channel);


        verticalLayout_63->addLayout(horizontalLayout_65);


        horizontalLayout_68->addLayout(verticalLayout_63);

        verticalLayout_62 = new QVBoxLayout();
        verticalLayout_62->setObjectName(QStringLiteral("verticalLayout_62"));
        pushButton_setNetPar = new QPushButton(groupBox_4);
        pushButton_setNetPar->setObjectName(QStringLiteral("pushButton_setNetPar"));

        verticalLayout_62->addWidget(pushButton_setNetPar);

        pushButton_requestNetPar = new QPushButton(groupBox_4);
        pushButton_requestNetPar->setObjectName(QStringLiteral("pushButton_requestNetPar"));

        verticalLayout_62->addWidget(pushButton_requestNetPar);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_62->addItem(verticalSpacer_2);

        export_idList_3 = new QPushButton(groupBox_4);
        export_idList_3->setObjectName(QStringLiteral("export_idList_3"));

        verticalLayout_62->addWidget(export_idList_3);


        horizontalLayout_68->addLayout(verticalLayout_62);


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

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setObjectName(QStringLiteral("horizontalLayout_46"));
        groupBox_15 = new QGroupBox(groupBox_8);
        groupBox_15->setObjectName(QStringLiteral("groupBox_15"));
        groupBox_15->setMinimumSize(QSize(0, 35));
        verticalLayout_47 = new QVBoxLayout(groupBox_15);
        verticalLayout_47->setObjectName(QStringLiteral("verticalLayout_47"));
        coolStopDisplay = new QRadioButton(groupBox_15);
        coolStopDisplay->setObjectName(QStringLiteral("coolStopDisplay"));

        verticalLayout_47->addWidget(coolStopDisplay);


        horizontalLayout_46->addWidget(groupBox_15);

        groupBox_16 = new QGroupBox(groupBox_8);
        groupBox_16->setObjectName(QStringLiteral("groupBox_16"));
        groupBox_16->setMinimumSize(QSize(0, 35));
        verticalLayout_48 = new QVBoxLayout(groupBox_16);
        verticalLayout_48->setObjectName(QStringLiteral("verticalLayout_48"));
        coolDisplayMac = new QRadioButton(groupBox_16);
        coolDisplayMac->setObjectName(QStringLiteral("coolDisplayMac"));
        coolDisplayMac->setChecked(true);

        verticalLayout_48->addWidget(coolDisplayMac);


        horizontalLayout_46->addWidget(groupBox_16);


        verticalLayout_27->addLayout(horizontalLayout_46);


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
        label_37 = new QLabel(groupBox_8);
        label_37->setObjectName(QStringLiteral("label_37"));
        label_37->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_31->addWidget(label_37);

        coolTemAlarmH_Edit = new QTextEdit(groupBox_8);
        coolTemAlarmH_Edit->setObjectName(QStringLiteral("coolTemAlarmH_Edit"));
        coolTemAlarmH_Edit->setMinimumSize(QSize(60, 25));
        coolTemAlarmH_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_31->addWidget(coolTemAlarmH_Edit);

        label_38 = new QLabel(groupBox_8);
        label_38->setObjectName(QStringLiteral("label_38"));
        label_38->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_31->addWidget(label_38);

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
        verticalLayout_37 = new QVBoxLayout(energy);
        verticalLayout_37->setObjectName(QStringLiteral("verticalLayout_37"));
        groupBox_9 = new QGroupBox(energy);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setMinimumSize(QSize(0, 120));
        groupBox_9->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_9 = new QHBoxLayout(groupBox_9);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        verticalLayout_33 = new QVBoxLayout();
        verticalLayout_33->setObjectName(QStringLiteral("verticalLayout_33"));
        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QStringLiteral("horizontalLayout_33"));
        label_15 = new QLabel(groupBox_9);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setMinimumSize(QSize(0, 25));
        label_15->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_33->addWidget(label_15);

        energyFiltId = new QTextEdit(groupBox_9);
        energyFiltId->setObjectName(QStringLiteral("energyFiltId"));
        energyFiltId->setMinimumSize(QSize(0, 25));
        energyFiltId->setMaximumSize(QSize(100, 25));

        horizontalLayout_33->addWidget(energyFiltId);


        verticalLayout_33->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QStringLiteral("horizontalLayout_34"));
        label_24 = new QLabel(groupBox_9);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setMinimumSize(QSize(0, 25));
        label_24->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_34->addWidget(label_24);

        energyFiltStr = new QTextEdit(groupBox_9);
        energyFiltStr->setObjectName(QStringLiteral("energyFiltStr"));
        energyFiltStr->setMinimumSize(QSize(0, 25));
        energyFiltStr->setMaximumSize(QSize(100, 25));

        horizontalLayout_34->addWidget(energyFiltStr);


        verticalLayout_33->addLayout(horizontalLayout_34);

        horizontalLayout_45 = new QHBoxLayout();
        horizontalLayout_45->setObjectName(QStringLiteral("horizontalLayout_45"));
        groupBox_13 = new QGroupBox(groupBox_9);
        groupBox_13->setObjectName(QStringLiteral("groupBox_13"));
        groupBox_13->setMinimumSize(QSize(0, 35));
        verticalLayout_45 = new QVBoxLayout(groupBox_13);
        verticalLayout_45->setObjectName(QStringLiteral("verticalLayout_45"));
        energyStopDisplay = new QRadioButton(groupBox_13);
        energyStopDisplay->setObjectName(QStringLiteral("energyStopDisplay"));

        verticalLayout_45->addWidget(energyStopDisplay);


        horizontalLayout_45->addWidget(groupBox_13);

        groupBox_14 = new QGroupBox(groupBox_9);
        groupBox_14->setObjectName(QStringLiteral("groupBox_14"));
        groupBox_14->setMinimumSize(QSize(0, 35));
        verticalLayout_46 = new QVBoxLayout(groupBox_14);
        verticalLayout_46->setObjectName(QStringLiteral("verticalLayout_46"));
        energyDisplayMac = new QRadioButton(groupBox_14);
        energyDisplayMac->setObjectName(QStringLiteral("energyDisplayMac"));
        energyDisplayMac->setChecked(true);

        verticalLayout_46->addWidget(energyDisplayMac);


        horizontalLayout_45->addWidget(groupBox_14);


        verticalLayout_33->addLayout(horizontalLayout_45);


        horizontalLayout_9->addLayout(verticalLayout_33);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QStringLiteral("verticalLayout_36"));
        energyGetMeasurement = new QPushButton(groupBox_9);
        energyGetMeasurement->setObjectName(QStringLiteral("energyGetMeasurement"));

        verticalLayout_36->addWidget(energyGetMeasurement);

        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setObjectName(QStringLiteral("horizontalLayout_39"));
        energySetRepTime_Edit = new QTextEdit(groupBox_9);
        energySetRepTime_Edit->setObjectName(QStringLiteral("energySetRepTime_Edit"));
        energySetRepTime_Edit->setMinimumSize(QSize(60, 25));
        energySetRepTime_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_39->addWidget(energySetRepTime_Edit);

        energySetRepTime_Bt = new QPushButton(groupBox_9);
        energySetRepTime_Bt->setObjectName(QStringLiteral("energySetRepTime_Bt"));

        horizontalLayout_39->addWidget(energySetRepTime_Bt);


        verticalLayout_36->addLayout(horizontalLayout_39);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_36->addItem(verticalSpacer);


        horizontalLayout_9->addLayout(verticalLayout_36);

        horizontalSpacer_21 = new QSpacerItem(64, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_21);

        horizontalSpacer_24 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_24);

        horizontalSpacer_25 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_25);

        horizontalSpacer_23 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_23);

        horizontalSpacer_22 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_22);

        horizontalSpacer_20 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_20);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);


        verticalLayout_37->addWidget(groupBox_9);

        energy_display = new QTextBrowser(energy);
        energy_display->setObjectName(QStringLiteral("energy_display"));

        verticalLayout_37->addWidget(energy_display);

        function->addTab(energy, QString());
        injection = new QWidget();
        injection->setObjectName(QStringLiteral("injection"));
        verticalLayout_42 = new QVBoxLayout(injection);
        verticalLayout_42->setObjectName(QStringLiteral("verticalLayout_42"));
        groupBox_10 = new QGroupBox(injection);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        groupBox_10->setMinimumSize(QSize(0, 120));
        groupBox_10->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_56 = new QHBoxLayout(groupBox_10);
        horizontalLayout_56->setObjectName(QStringLiteral("horizontalLayout_56"));
        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName(QStringLiteral("verticalLayout_35"));
        horizontalLayout_35 = new QHBoxLayout();
        horizontalLayout_35->setObjectName(QStringLiteral("horizontalLayout_35"));
        label_19 = new QLabel(groupBox_10);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setMinimumSize(QSize(0, 25));
        label_19->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_35->addWidget(label_19);

        injectionFiltId = new QTextEdit(groupBox_10);
        injectionFiltId->setObjectName(QStringLiteral("injectionFiltId"));
        injectionFiltId->setMinimumSize(QSize(0, 25));
        injectionFiltId->setMaximumSize(QSize(100, 25));

        horizontalLayout_35->addWidget(injectionFiltId);


        verticalLayout_35->addLayout(horizontalLayout_35);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QStringLiteral("horizontalLayout_36"));
        label_25 = new QLabel(groupBox_10);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setMinimumSize(QSize(0, 25));
        label_25->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_36->addWidget(label_25);

        injectionFiltStr = new QTextEdit(groupBox_10);
        injectionFiltStr->setObjectName(QStringLiteral("injectionFiltStr"));
        injectionFiltStr->setMinimumSize(QSize(0, 25));
        injectionFiltStr->setMaximumSize(QSize(100, 25));

        horizontalLayout_36->addWidget(injectionFiltStr);


        verticalLayout_35->addLayout(horizontalLayout_36);

        horizontalLayout_47 = new QHBoxLayout();
        horizontalLayout_47->setObjectName(QStringLiteral("horizontalLayout_47"));
        groupBox_17 = new QGroupBox(groupBox_10);
        groupBox_17->setObjectName(QStringLiteral("groupBox_17"));
        groupBox_17->setMinimumSize(QSize(0, 35));
        verticalLayout_49 = new QVBoxLayout(groupBox_17);
        verticalLayout_49->setObjectName(QStringLiteral("verticalLayout_49"));
        injectionStopDisplay = new QRadioButton(groupBox_17);
        injectionStopDisplay->setObjectName(QStringLiteral("injectionStopDisplay"));

        verticalLayout_49->addWidget(injectionStopDisplay);


        horizontalLayout_47->addWidget(groupBox_17);

        groupBox_18 = new QGroupBox(groupBox_10);
        groupBox_18->setObjectName(QStringLiteral("groupBox_18"));
        groupBox_18->setMinimumSize(QSize(0, 35));
        verticalLayout_50 = new QVBoxLayout(groupBox_18);
        verticalLayout_50->setObjectName(QStringLiteral("verticalLayout_50"));
        injectionDisplayMac = new QRadioButton(groupBox_18);
        injectionDisplayMac->setObjectName(QStringLiteral("injectionDisplayMac"));
        injectionDisplayMac->setChecked(true);

        verticalLayout_50->addWidget(injectionDisplayMac);


        horizontalLayout_47->addWidget(groupBox_18);


        verticalLayout_35->addLayout(horizontalLayout_47);


        horizontalLayout_56->addLayout(verticalLayout_35);

        verticalLayout_59 = new QVBoxLayout();
        verticalLayout_59->setObjectName(QStringLiteral("verticalLayout_59"));
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QStringLiteral("horizontalLayout_32"));
        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setObjectName(QStringLiteral("verticalLayout_41"));
        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_41->addItem(verticalSpacer_6);

        label_27 = new QLabel(groupBox_10);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setAlignment(Qt::AlignCenter);

        verticalLayout_41->addWidget(label_27);

        injectionTemAlarmH_Edit = new QTextEdit(groupBox_10);
        injectionTemAlarmH_Edit->setObjectName(QStringLiteral("injectionTemAlarmH_Edit"));
        injectionTemAlarmH_Edit->setMinimumSize(QSize(60, 25));
        injectionTemAlarmH_Edit->setMaximumSize(QSize(60, 25));

        verticalLayout_41->addWidget(injectionTemAlarmH_Edit);


        horizontalLayout_32->addLayout(verticalLayout_41);

        verticalLayout_57 = new QVBoxLayout();
        verticalLayout_57->setObjectName(QStringLiteral("verticalLayout_57"));
        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_57->addItem(verticalSpacer_7);

        label_28 = new QLabel(groupBox_10);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setAlignment(Qt::AlignCenter);

        verticalLayout_57->addWidget(label_28);

        injectionTemAlarmM_Edit = new QTextEdit(groupBox_10);
        injectionTemAlarmM_Edit->setObjectName(QStringLiteral("injectionTemAlarmM_Edit"));
        injectionTemAlarmM_Edit->setMinimumSize(QSize(60, 25));
        injectionTemAlarmM_Edit->setMaximumSize(QSize(60, 25));

        verticalLayout_57->addWidget(injectionTemAlarmM_Edit);


        horizontalLayout_32->addLayout(verticalLayout_57);

        verticalLayout_58 = new QVBoxLayout();
        verticalLayout_58->setObjectName(QStringLiteral("verticalLayout_58"));
        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_58->addItem(verticalSpacer_8);

        label_29 = new QLabel(groupBox_10);
        label_29->setObjectName(QStringLiteral("label_29"));
        label_29->setAlignment(Qt::AlignCenter);

        verticalLayout_58->addWidget(label_29);

        injectionTemAlarmL_Edit = new QTextEdit(groupBox_10);
        injectionTemAlarmL_Edit->setObjectName(QStringLiteral("injectionTemAlarmL_Edit"));
        injectionTemAlarmL_Edit->setMinimumSize(QSize(60, 25));
        injectionTemAlarmL_Edit->setMaximumSize(QSize(60, 25));

        verticalLayout_58->addWidget(injectionTemAlarmL_Edit);


        horizontalLayout_32->addLayout(verticalLayout_58);


        verticalLayout_59->addLayout(horizontalLayout_32);

        injectionTemAlarm_Bt = new QPushButton(groupBox_10);
        injectionTemAlarm_Bt->setObjectName(QStringLiteral("injectionTemAlarm_Bt"));

        verticalLayout_59->addWidget(injectionTemAlarm_Bt);


        horizontalLayout_56->addLayout(verticalLayout_59);

        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setObjectName(QStringLiteral("verticalLayout_40"));
        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setObjectName(QStringLiteral("horizontalLayout_37"));
        injectionSetSn_Edit = new QTextEdit(groupBox_10);
        injectionSetSn_Edit->setObjectName(QStringLiteral("injectionSetSn_Edit"));
        injectionSetSn_Edit->setMinimumSize(QSize(60, 25));
        injectionSetSn_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_37->addWidget(injectionSetSn_Edit);

        injectionSetSn_Bt = new QPushButton(groupBox_10);
        injectionSetSn_Bt->setObjectName(QStringLiteral("injectionSetSn_Bt"));

        horizontalLayout_37->addWidget(injectionSetSn_Bt);


        verticalLayout_40->addLayout(horizontalLayout_37);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setObjectName(QStringLiteral("horizontalLayout_42"));
        injectionSetRepTime_Edit = new QTextEdit(groupBox_10);
        injectionSetRepTime_Edit->setObjectName(QStringLiteral("injectionSetRepTime_Edit"));
        injectionSetRepTime_Edit->setMinimumSize(QSize(60, 25));
        injectionSetRepTime_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_42->addWidget(injectionSetRepTime_Edit);

        injectionSetRepTime_Bt = new QPushButton(groupBox_10);
        injectionSetRepTime_Bt->setObjectName(QStringLiteral("injectionSetRepTime_Bt"));

        horizontalLayout_42->addWidget(injectionSetRepTime_Bt);


        verticalLayout_40->addLayout(horizontalLayout_42);

        injectionSetSpeaker_Bt = new QPushButton(groupBox_10);
        injectionSetSpeaker_Bt->setObjectName(QStringLiteral("injectionSetSpeaker_Bt"));

        verticalLayout_40->addWidget(injectionSetSpeaker_Bt);


        horizontalLayout_56->addLayout(verticalLayout_40);

        verticalLayout_56 = new QVBoxLayout();
        verticalLayout_56->setObjectName(QStringLiteral("verticalLayout_56"));
        injectionStart_Bt = new QPushButton(groupBox_10);
        injectionStart_Bt->setObjectName(QStringLiteral("injectionStart_Bt"));

        verticalLayout_56->addWidget(injectionStart_Bt);

        injectionStop_Bt = new QPushButton(groupBox_10);
        injectionStop_Bt->setObjectName(QStringLiteral("injectionStop_Bt"));

        verticalLayout_56->addWidget(injectionStop_Bt);

        injectionFinish_Bt = new QPushButton(groupBox_10);
        injectionFinish_Bt->setObjectName(QStringLiteral("injectionFinish_Bt"));

        verticalLayout_56->addWidget(injectionFinish_Bt);


        horizontalLayout_56->addLayout(verticalLayout_56);

        verticalLayout_39 = new QVBoxLayout();
        verticalLayout_39->setObjectName(QStringLiteral("verticalLayout_39"));
        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QStringLiteral("horizontalLayout_40"));
        injectionSetTotalDi_Edit = new QTextEdit(groupBox_10);
        injectionSetTotalDi_Edit->setObjectName(QStringLiteral("injectionSetTotalDi_Edit"));
        injectionSetTotalDi_Edit->setMinimumSize(QSize(60, 25));
        injectionSetTotalDi_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_40->addWidget(injectionSetTotalDi_Edit);

        injectionSetTotalDi_Bt = new QPushButton(groupBox_10);
        injectionSetTotalDi_Bt->setObjectName(QStringLiteral("injectionSetTotalDi_Bt"));

        horizontalLayout_40->addWidget(injectionSetTotalDi_Bt);


        verticalLayout_39->addLayout(horizontalLayout_40);

        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setObjectName(QStringLiteral("horizontalLayout_51"));
        injectionSetStopTimeOut_Edit = new QTextEdit(groupBox_10);
        injectionSetStopTimeOut_Edit->setObjectName(QStringLiteral("injectionSetStopTimeOut_Edit"));
        injectionSetStopTimeOut_Edit->setMinimumSize(QSize(60, 25));
        injectionSetStopTimeOut_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_51->addWidget(injectionSetStopTimeOut_Edit);

        injectionSetStopTimeOut_Bt = new QPushButton(groupBox_10);
        injectionSetStopTimeOut_Bt->setObjectName(QStringLiteral("injectionSetStopTimeOut_Bt"));

        horizontalLayout_51->addWidget(injectionSetStopTimeOut_Bt);


        verticalLayout_39->addLayout(horizontalLayout_51);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setObjectName(QStringLiteral("horizontalLayout_52"));
        injectionDeviceParameters_list = new QComboBox(groupBox_10);
        injectionDeviceParameters_list->setObjectName(QStringLiteral("injectionDeviceParameters_list"));

        horizontalLayout_52->addWidget(injectionDeviceParameters_list);

        injectionGetDeviceParameters_Bt = new QPushButton(groupBox_10);
        injectionGetDeviceParameters_Bt->setObjectName(QStringLiteral("injectionGetDeviceParameters_Bt"));

        horizontalLayout_52->addWidget(injectionGetDeviceParameters_Bt);


        verticalLayout_39->addLayout(horizontalLayout_52);


        horizontalLayout_56->addLayout(verticalLayout_39);

        verticalLayout_60 = new QVBoxLayout();
        verticalLayout_60->setObjectName(QStringLiteral("verticalLayout_60"));
        horizontalLayout_55 = new QHBoxLayout();
        horizontalLayout_55->setObjectName(QStringLiteral("horizontalLayout_55"));
        injectionDiInit_Edit = new QTextEdit(groupBox_10);
        injectionDiInit_Edit->setObjectName(QStringLiteral("injectionDiInit_Edit"));
        injectionDiInit_Edit->setMinimumSize(QSize(60, 25));
        injectionDiInit_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_55->addWidget(injectionDiInit_Edit);

        injectionDiInit_Bt = new QPushButton(groupBox_10);
        injectionDiInit_Bt->setObjectName(QStringLiteral("injectionDiInit_Bt"));

        horizontalLayout_55->addWidget(injectionDiInit_Bt);


        verticalLayout_60->addLayout(horizontalLayout_55);

        horizontalLayout_54 = new QHBoxLayout();
        horizontalLayout_54->setObjectName(QStringLiteral("horizontalLayout_54"));
        injectionSetDi_Edit = new QTextEdit(groupBox_10);
        injectionSetDi_Edit->setObjectName(QStringLiteral("injectionSetDi_Edit"));
        injectionSetDi_Edit->setMinimumSize(QSize(60, 25));
        injectionSetDi_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_54->addWidget(injectionSetDi_Edit);

        injectionSetDi_Bt = new QPushButton(groupBox_10);
        injectionSetDi_Bt->setObjectName(QStringLiteral("injectionSetDi_Bt"));

        horizontalLayout_54->addWidget(injectionSetDi_Bt);


        verticalLayout_60->addLayout(horizontalLayout_54);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setObjectName(QStringLiteral("horizontalLayout_53"));
        injectionSetName_Edit = new QTextEdit(groupBox_10);
        injectionSetName_Edit->setObjectName(QStringLiteral("injectionSetName_Edit"));
        injectionSetName_Edit->setMinimumSize(QSize(60, 25));
        injectionSetName_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_53->addWidget(injectionSetName_Edit);

        injectionSetName_Bt = new QPushButton(groupBox_10);
        injectionSetName_Bt->setObjectName(QStringLiteral("injectionSetName_Bt"));

        horizontalLayout_53->addWidget(injectionSetName_Bt);


        verticalLayout_60->addLayout(horizontalLayout_53);


        horizontalLayout_56->addLayout(verticalLayout_60);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_14);

        horizontalSpacer_26 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_56->addItem(horizontalSpacer_26);


        verticalLayout_42->addWidget(groupBox_10);

        injection_display = new QTextBrowser(injection);
        injection_display->setObjectName(QStringLiteral("injection_display"));

        verticalLayout_42->addWidget(injection_display);

        function->addTab(injection, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_55 = new QVBoxLayout(tab);
        verticalLayout_55->setObjectName(QStringLiteral("verticalLayout_55"));
        groupBox_19 = new QGroupBox(tab);
        groupBox_19->setObjectName(QStringLiteral("groupBox_19"));
        groupBox_19->setMinimumSize(QSize(0, 120));
        groupBox_19->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_38 = new QHBoxLayout(groupBox_19);
        horizontalLayout_38->setObjectName(QStringLiteral("horizontalLayout_38"));
        verticalLayout_51 = new QVBoxLayout();
        verticalLayout_51->setObjectName(QStringLiteral("verticalLayout_51"));
        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QStringLiteral("horizontalLayout_41"));
        label_30 = new QLabel(groupBox_19);
        label_30->setObjectName(QStringLiteral("label_30"));
        label_30->setMinimumSize(QSize(0, 25));
        label_30->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_41->addWidget(label_30);

        sosFiltId = new QTextEdit(groupBox_19);
        sosFiltId->setObjectName(QStringLiteral("sosFiltId"));
        sosFiltId->setMinimumSize(QSize(0, 25));
        sosFiltId->setMaximumSize(QSize(100, 25));

        horizontalLayout_41->addWidget(sosFiltId);


        verticalLayout_51->addLayout(horizontalLayout_41);

        horizontalLayout_48 = new QHBoxLayout();
        horizontalLayout_48->setObjectName(QStringLiteral("horizontalLayout_48"));
        label_31 = new QLabel(groupBox_19);
        label_31->setObjectName(QStringLiteral("label_31"));
        label_31->setMinimumSize(QSize(0, 25));
        label_31->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_48->addWidget(label_31);

        sosFiltStr = new QTextEdit(groupBox_19);
        sosFiltStr->setObjectName(QStringLiteral("sosFiltStr"));
        sosFiltStr->setMinimumSize(QSize(0, 25));
        sosFiltStr->setMaximumSize(QSize(100, 25));

        horizontalLayout_48->addWidget(sosFiltStr);


        verticalLayout_51->addLayout(horizontalLayout_48);

        horizontalLayout_49 = new QHBoxLayout();
        horizontalLayout_49->setObjectName(QStringLiteral("horizontalLayout_49"));
        groupBox_20 = new QGroupBox(groupBox_19);
        groupBox_20->setObjectName(QStringLiteral("groupBox_20"));
        groupBox_20->setMinimumSize(QSize(0, 35));
        verticalLayout_52 = new QVBoxLayout(groupBox_20);
        verticalLayout_52->setObjectName(QStringLiteral("verticalLayout_52"));
        sosStopDisplay = new QRadioButton(groupBox_20);
        sosStopDisplay->setObjectName(QStringLiteral("sosStopDisplay"));

        verticalLayout_52->addWidget(sosStopDisplay);


        horizontalLayout_49->addWidget(groupBox_20);

        groupBox_21 = new QGroupBox(groupBox_19);
        groupBox_21->setObjectName(QStringLiteral("groupBox_21"));
        groupBox_21->setMinimumSize(QSize(0, 35));
        verticalLayout_53 = new QVBoxLayout(groupBox_21);
        verticalLayout_53->setObjectName(QStringLiteral("verticalLayout_53"));
        sosDisplayMac = new QRadioButton(groupBox_21);
        sosDisplayMac->setObjectName(QStringLiteral("sosDisplayMac"));
        sosDisplayMac->setChecked(true);

        verticalLayout_53->addWidget(sosDisplayMac);


        horizontalLayout_49->addWidget(groupBox_21);


        verticalLayout_51->addLayout(horizontalLayout_49);


        horizontalLayout_38->addLayout(verticalLayout_51);

        verticalLayout_54 = new QVBoxLayout();
        verticalLayout_54->setObjectName(QStringLiteral("verticalLayout_54"));
        horizontalLayout_50 = new QHBoxLayout();
        horizontalLayout_50->setObjectName(QStringLiteral("horizontalLayout_50"));
        sosSetRepTime_Edit = new QTextEdit(groupBox_19);
        sosSetRepTime_Edit->setObjectName(QStringLiteral("sosSetRepTime_Edit"));
        sosSetRepTime_Edit->setMinimumSize(QSize(60, 25));
        sosSetRepTime_Edit->setMaximumSize(QSize(60, 25));

        horizontalLayout_50->addWidget(sosSetRepTime_Edit);

        sosSetRepTime_Bt = new QPushButton(groupBox_19);
        sosSetRepTime_Bt->setObjectName(QStringLiteral("sosSetRepTime_Bt"));

        horizontalLayout_50->addWidget(sosSetRepTime_Bt);


        verticalLayout_54->addLayout(horizontalLayout_50);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_54->addItem(verticalSpacer_5);


        horizontalLayout_38->addLayout(verticalLayout_54);

        horizontalSpacer_28 = new QSpacerItem(64, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_28);

        horizontalSpacer_29 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_29);

        horizontalSpacer_30 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_30);

        horizontalSpacer_37 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_37);

        horizontalSpacer_38 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_38);

        horizontalSpacer_39 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_39);

        horizontalSpacer_42 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_38->addItem(horizontalSpacer_42);


        verticalLayout_55->addWidget(groupBox_19);

        sos_display = new QTextBrowser(tab);
        sos_display->setObjectName(QStringLiteral("sos_display"));

        verticalLayout_55->addWidget(sos_display);

        function->addTab(tab, QString());
        location = new QWidget();
        location->setObjectName(QStringLiteral("location"));
        verticalLayout_28 = new QVBoxLayout(location);
        verticalLayout_28->setObjectName(QStringLiteral("verticalLayout_28"));
        groupBox_7 = new QGroupBox(location);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMinimumSize(QSize(0, 120));
        groupBox_7->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_82 = new QHBoxLayout(groupBox_7);
        horizontalLayout_82->setObjectName(QStringLiteral("horizontalLayout_82"));
        verticalLayout_26 = new QVBoxLayout();
        verticalLayout_26->setObjectName(QStringLiteral("verticalLayout_26"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_9 = new QLabel(groupBox_7);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setMinimumSize(QSize(80, 25));
        label_9->setMaximumSize(QSize(80, 25));
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_15->addWidget(label_9);

        localtionFiltId = new QTextEdit(groupBox_7);
        localtionFiltId->setObjectName(QStringLiteral("localtionFiltId"));
        localtionFiltId->setMinimumSize(QSize(80, 25));
        localtionFiltId->setMaximumSize(QSize(80, 25));

        horizontalLayout_15->addWidget(localtionFiltId);

        localtionFiltId_1 = new QTextEdit(groupBox_7);
        localtionFiltId_1->setObjectName(QStringLiteral("localtionFiltId_1"));
        localtionFiltId_1->setMinimumSize(QSize(80, 25));
        localtionFiltId_1->setMaximumSize(QSize(80, 25));

        horizontalLayout_15->addWidget(localtionFiltId_1);


        verticalLayout_26->addLayout(horizontalLayout_15);

        horizontalLayout_44 = new QHBoxLayout();
        horizontalLayout_44->setObjectName(QStringLiteral("horizontalLayout_44"));
        localtionFiltId_2 = new QTextEdit(groupBox_7);
        localtionFiltId_2->setObjectName(QStringLiteral("localtionFiltId_2"));
        localtionFiltId_2->setMinimumSize(QSize(80, 25));
        localtionFiltId_2->setMaximumSize(QSize(80, 25));

        horizontalLayout_44->addWidget(localtionFiltId_2);

        localtionFiltId_3 = new QTextEdit(groupBox_7);
        localtionFiltId_3->setObjectName(QStringLiteral("localtionFiltId_3"));
        localtionFiltId_3->setMinimumSize(QSize(80, 25));
        localtionFiltId_3->setMaximumSize(QSize(80, 25));

        horizontalLayout_44->addWidget(localtionFiltId_3);

        localtionFiltId_4 = new QTextEdit(groupBox_7);
        localtionFiltId_4->setObjectName(QStringLiteral("localtionFiltId_4"));
        localtionFiltId_4->setMinimumSize(QSize(80, 25));
        localtionFiltId_4->setMaximumSize(QSize(80, 25));

        horizontalLayout_44->addWidget(localtionFiltId_4);


        verticalLayout_26->addLayout(horizontalLayout_44);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_16 = new QLabel(groupBox_7);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setMinimumSize(QSize(80, 25));
        label_16->setMaximumSize(QSize(80, 25));
        label_16->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(label_16);

        localtionFiltStr = new QTextEdit(groupBox_7);
        localtionFiltStr->setObjectName(QStringLiteral("localtionFiltStr"));
        localtionFiltStr->setMinimumSize(QSize(165, 25));
        localtionFiltStr->setMaximumSize(QSize(165, 25));

        horizontalLayout_10->addWidget(localtionFiltStr);


        verticalLayout_26->addLayout(horizontalLayout_10);


        horizontalLayout_82->addLayout(verticalLayout_26);

        verticalLayout_64 = new QVBoxLayout();
        verticalLayout_64->setObjectName(QStringLiteral("verticalLayout_64"));
        groupBox_11 = new QGroupBox(groupBox_7);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        groupBox_11->setMinimumSize(QSize(0, 35));
        verticalLayout_43 = new QVBoxLayout(groupBox_11);
        verticalLayout_43->setObjectName(QStringLiteral("verticalLayout_43"));
        locationStopDisplay = new QRadioButton(groupBox_11);
        locationStopDisplay->setObjectName(QStringLiteral("locationStopDisplay"));

        verticalLayout_43->addWidget(locationStopDisplay);


        verticalLayout_64->addWidget(groupBox_11);

        groupBox_12 = new QGroupBox(groupBox_7);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        groupBox_12->setMinimumSize(QSize(0, 35));
        verticalLayout_44 = new QVBoxLayout(groupBox_12);
        verticalLayout_44->setObjectName(QStringLiteral("verticalLayout_44"));
        locationDisplayMac = new QRadioButton(groupBox_12);
        locationDisplayMac->setObjectName(QStringLiteral("locationDisplayMac"));
        locationDisplayMac->setChecked(true);

        verticalLayout_44->addWidget(locationDisplayMac);


        verticalLayout_64->addWidget(groupBox_12);


        horizontalLayout_82->addLayout(verticalLayout_64);

        horizontalSpacer_9 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_9);

        verticalLayout_71 = new QVBoxLayout();
        verticalLayout_71->setObjectName(QStringLiteral("verticalLayout_71"));
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setObjectName(QStringLiteral("horizontalLayout_43"));
        label_46 = new QLabel(groupBox_7);
        label_46->setObjectName(QStringLiteral("label_46"));
        label_46->setMaximumSize(QSize(16777215, 16777215));
        label_46->setAlignment(Qt::AlignCenter);

        horizontalLayout_43->addWidget(label_46);

        location125KIDtextEdit = new QTextEdit(groupBox_7);
        location125KIDtextEdit->setObjectName(QStringLiteral("location125KIDtextEdit"));
        location125KIDtextEdit->setMaximumSize(QSize(80, 25));

        horizontalLayout_43->addWidget(location125KIDtextEdit);


        verticalLayout_71->addLayout(horizontalLayout_43);

        horizontalLayout_74 = new QHBoxLayout();
        horizontalLayout_74->setObjectName(QStringLiteral("horizontalLayout_74"));
        label_47 = new QLabel(groupBox_7);
        label_47->setObjectName(QStringLiteral("label_47"));
        label_47->setMaximumSize(QSize(16777215, 16777215));
        label_47->setAlignment(Qt::AlignCenter);

        horizontalLayout_74->addWidget(label_47);

        location125KRssitextEdit = new QTextEdit(groupBox_7);
        location125KRssitextEdit->setObjectName(QStringLiteral("location125KRssitextEdit"));
        location125KRssitextEdit->setMaximumSize(QSize(80, 25));

        horizontalLayout_74->addWidget(location125KRssitextEdit);


        verticalLayout_71->addLayout(horizontalLayout_74);

        bt_setHeartBeatTime_3 = new QPushButton(groupBox_7);
        bt_setHeartBeatTime_3->setObjectName(QStringLiteral("bt_setHeartBeatTime_3"));
        bt_setHeartBeatTime_3->setMaximumSize(QSize(16777215, 25));

        verticalLayout_71->addWidget(bt_setHeartBeatTime_3);


        horizontalLayout_82->addLayout(verticalLayout_71);

        horizontalSpacer_36 = new QSpacerItem(15, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_36);

        verticalLayout_34 = new QVBoxLayout();
        verticalLayout_34->setObjectName(QStringLiteral("verticalLayout_34"));
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QStringLiteral("horizontalLayout_18"));
        textEdit_heartbeat_time = new QTextEdit(groupBox_7);
        textEdit_heartbeat_time->setObjectName(QStringLiteral("textEdit_heartbeat_time"));
        textEdit_heartbeat_time->setMaximumSize(QSize(80, 25));

        horizontalLayout_18->addWidget(textEdit_heartbeat_time);

        label_26 = new QLabel(groupBox_7);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_18->addWidget(label_26);


        verticalLayout_34->addLayout(horizontalLayout_18);

        bt_setHeartBeatTime = new QPushButton(groupBox_7);
        bt_setHeartBeatTime->setObjectName(QStringLiteral("bt_setHeartBeatTime"));
        bt_setHeartBeatTime->setMaximumSize(QSize(16777215, 25));

        verticalLayout_34->addWidget(bt_setHeartBeatTime);

        verticalSpacer_3 = new QSpacerItem(95, 31, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_34->addItem(verticalSpacer_3);


        horizontalLayout_82->addLayout(verticalLayout_34);

        horizontalSpacer_5 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_5);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_12);

        horizontalSpacer_10 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_10);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_15);

        horizontalSpacer_40 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_40);

        horizontalSpacer_27 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_27);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_82->addItem(horizontalSpacer_13);


        verticalLayout_28->addWidget(groupBox_7);

        location_display = new QTextBrowser(location);
        location_display->setObjectName(QStringLiteral("location_display"));

        verticalLayout_28->addWidget(location_display);

        function->addTab(location, QString());
        BLE_data = new QWidget();
        BLE_data->setObjectName(QStringLiteral("BLE_data"));
        verticalLayout_70 = new QVBoxLayout(BLE_data);
        verticalLayout_70->setObjectName(QStringLiteral("verticalLayout_70"));
        groupBox_22 = new QGroupBox(BLE_data);
        groupBox_22->setObjectName(QStringLiteral("groupBox_22"));
        groupBox_22->setMinimumSize(QSize(0, 120));
        groupBox_22->setMaximumSize(QSize(16777215, 120));
        horizontalLayout_79 = new QHBoxLayout(groupBox_22);
        horizontalLayout_79->setObjectName(QStringLiteral("horizontalLayout_79"));
        verticalLayout_65 = new QVBoxLayout();
        verticalLayout_65->setObjectName(QStringLiteral("verticalLayout_65"));
        horizontalLayout_70 = new QHBoxLayout();
        horizontalLayout_70->setObjectName(QStringLiteral("horizontalLayout_70"));
        label_43 = new QLabel(groupBox_22);
        label_43->setObjectName(QStringLiteral("label_43"));
        label_43->setMinimumSize(QSize(80, 25));
        label_43->setMaximumSize(QSize(80, 25));
        label_43->setAlignment(Qt::AlignCenter);

        horizontalLayout_70->addWidget(label_43);

        BLE_FiltId = new QTextEdit(groupBox_22);
        BLE_FiltId->setObjectName(QStringLiteral("BLE_FiltId"));
        BLE_FiltId->setMinimumSize(QSize(80, 25));
        BLE_FiltId->setMaximumSize(QSize(80, 25));

        horizontalLayout_70->addWidget(BLE_FiltId);

        BLE_FiltId_1 = new QTextEdit(groupBox_22);
        BLE_FiltId_1->setObjectName(QStringLiteral("BLE_FiltId_1"));
        BLE_FiltId_1->setMinimumSize(QSize(80, 25));
        BLE_FiltId_1->setMaximumSize(QSize(80, 25));

        horizontalLayout_70->addWidget(BLE_FiltId_1);


        verticalLayout_65->addLayout(horizontalLayout_70);

        horizontalLayout_71 = new QHBoxLayout();
        horizontalLayout_71->setObjectName(QStringLiteral("horizontalLayout_71"));
        BLE_FiltId_2 = new QTextEdit(groupBox_22);
        BLE_FiltId_2->setObjectName(QStringLiteral("BLE_FiltId_2"));
        BLE_FiltId_2->setMinimumSize(QSize(80, 25));
        BLE_FiltId_2->setMaximumSize(QSize(80, 25));

        horizontalLayout_71->addWidget(BLE_FiltId_2);

        BLE_FiltId_3 = new QTextEdit(groupBox_22);
        BLE_FiltId_3->setObjectName(QStringLiteral("BLE_FiltId_3"));
        BLE_FiltId_3->setMinimumSize(QSize(80, 25));
        BLE_FiltId_3->setMaximumSize(QSize(80, 25));

        horizontalLayout_71->addWidget(BLE_FiltId_3);

        BLE_FiltId_4 = new QTextEdit(groupBox_22);
        BLE_FiltId_4->setObjectName(QStringLiteral("BLE_FiltId_4"));
        BLE_FiltId_4->setMinimumSize(QSize(80, 25));
        BLE_FiltId_4->setMaximumSize(QSize(80, 25));

        horizontalLayout_71->addWidget(BLE_FiltId_4);


        verticalLayout_65->addLayout(horizontalLayout_71);

        horizontalLayout_72 = new QHBoxLayout();
        horizontalLayout_72->setObjectName(QStringLiteral("horizontalLayout_72"));
        label_44 = new QLabel(groupBox_22);
        label_44->setObjectName(QStringLiteral("label_44"));
        label_44->setMinimumSize(QSize(80, 25));
        label_44->setMaximumSize(QSize(80, 25));
        label_44->setAlignment(Qt::AlignCenter);

        horizontalLayout_72->addWidget(label_44);

        BLE_FiltStr = new QTextEdit(groupBox_22);
        BLE_FiltStr->setObjectName(QStringLiteral("BLE_FiltStr"));
        BLE_FiltStr->setMinimumSize(QSize(165, 25));
        BLE_FiltStr->setMaximumSize(QSize(165, 25));

        horizontalLayout_72->addWidget(BLE_FiltStr);


        verticalLayout_65->addLayout(horizontalLayout_72);


        horizontalLayout_79->addLayout(verticalLayout_65);

        verticalLayout_66 = new QVBoxLayout();
        verticalLayout_66->setObjectName(QStringLiteral("verticalLayout_66"));
        groupBox_23 = new QGroupBox(groupBox_22);
        groupBox_23->setObjectName(QStringLiteral("groupBox_23"));
        groupBox_23->setMinimumSize(QSize(0, 35));
        verticalLayout_67 = new QVBoxLayout(groupBox_23);
        verticalLayout_67->setObjectName(QStringLiteral("verticalLayout_67"));
        BLE_StopDisplay = new QRadioButton(groupBox_23);
        BLE_StopDisplay->setObjectName(QStringLiteral("BLE_StopDisplay"));

        verticalLayout_67->addWidget(BLE_StopDisplay);


        verticalLayout_66->addWidget(groupBox_23);

        groupBox_24 = new QGroupBox(groupBox_22);
        groupBox_24->setObjectName(QStringLiteral("groupBox_24"));
        groupBox_24->setMinimumSize(QSize(0, 35));
        verticalLayout_68 = new QVBoxLayout(groupBox_24);
        verticalLayout_68->setObjectName(QStringLiteral("verticalLayout_68"));
        BLE_DisplayMac = new QRadioButton(groupBox_24);
        BLE_DisplayMac->setObjectName(QStringLiteral("BLE_DisplayMac"));
        BLE_DisplayMac->setChecked(true);

        verticalLayout_68->addWidget(BLE_DisplayMac);


        verticalLayout_66->addWidget(groupBox_24);


        horizontalLayout_79->addLayout(verticalLayout_66);

        horizontalSpacer_8 = new QSpacerItem(85, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_8);

        horizontalSpacer_31 = new QSpacerItem(84, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_31);

        horizontalSpacer_32 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_32);

        horizontalSpacer_33 = new QSpacerItem(37, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_33);

        horizontalSpacer_35 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_35);

        horizontalSpacer_34 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_79->addItem(horizontalSpacer_34);

        verticalLayout_73 = new QVBoxLayout();
        verticalLayout_73->setObjectName(QStringLiteral("verticalLayout_73"));
        horizontalLayout_77 = new QHBoxLayout();
        horizontalLayout_77->setObjectName(QStringLiteral("horizontalLayout_77"));
        label_50 = new QLabel(groupBox_22);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setMaximumSize(QSize(16777215, 16777215));
        label_50->setAlignment(Qt::AlignCenter);

        horizontalLayout_77->addWidget(label_50);

        BLE_125KIDtextEdit = new QTextEdit(groupBox_22);
        BLE_125KIDtextEdit->setObjectName(QStringLiteral("BLE_125KIDtextEdit"));
        BLE_125KIDtextEdit->setMaximumSize(QSize(80, 25));

        horizontalLayout_77->addWidget(BLE_125KIDtextEdit);


        verticalLayout_73->addLayout(horizontalLayout_77);

        horizontalLayout_78 = new QHBoxLayout();
        horizontalLayout_78->setObjectName(QStringLiteral("horizontalLayout_78"));
        label_53 = new QLabel(groupBox_22);
        label_53->setObjectName(QStringLiteral("label_53"));
        label_53->setMaximumSize(QSize(16777215, 16777215));
        label_53->setAlignment(Qt::AlignCenter);

        horizontalLayout_78->addWidget(label_53);

        BLE_125KRssitextEdit = new QTextEdit(groupBox_22);
        BLE_125KRssitextEdit->setObjectName(QStringLiteral("BLE_125KRssitextEdit"));
        BLE_125KRssitextEdit->setMaximumSize(QSize(80, 25));

        horizontalLayout_78->addWidget(BLE_125KRssitextEdit);


        verticalLayout_73->addLayout(horizontalLayout_78);

        BLE__set125KRssi = new QPushButton(groupBox_22);
        BLE__set125KRssi->setObjectName(QStringLiteral("BLE__set125KRssi"));
        BLE__set125KRssi->setMaximumSize(QSize(16777215, 25));

        verticalLayout_73->addWidget(BLE__set125KRssi);


        horizontalLayout_79->addLayout(verticalLayout_73);

        verticalLayout_69 = new QVBoxLayout();
        verticalLayout_69->setObjectName(QStringLiteral("verticalLayout_69"));
        horizontalLayout_73 = new QHBoxLayout();
        horizontalLayout_73->setObjectName(QStringLiteral("horizontalLayout_73"));
        BLE_textEdit_heartbeat_time = new QTextEdit(groupBox_22);
        BLE_textEdit_heartbeat_time->setObjectName(QStringLiteral("BLE_textEdit_heartbeat_time"));
        BLE_textEdit_heartbeat_time->setMaximumSize(QSize(80, 25));

        horizontalLayout_73->addWidget(BLE_textEdit_heartbeat_time);

        label_45 = new QLabel(groupBox_22);
        label_45->setObjectName(QStringLiteral("label_45"));
        label_45->setMaximumSize(QSize(10, 16777215));

        horizontalLayout_73->addWidget(label_45);


        verticalLayout_69->addLayout(horizontalLayout_73);

        BLE_bt_setHeartBeatTime = new QPushButton(groupBox_22);
        BLE_bt_setHeartBeatTime->setObjectName(QStringLiteral("BLE_bt_setHeartBeatTime"));
        BLE_bt_setHeartBeatTime->setMaximumSize(QSize(16777215, 25));

        verticalLayout_69->addWidget(BLE_bt_setHeartBeatTime);

        verticalSpacer_4 = new QSpacerItem(95, 70, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_69->addItem(verticalSpacer_4);

        BLE_displayLog = new QCheckBox(groupBox_22);
        BLE_displayLog->setObjectName(QStringLiteral("BLE_displayLog"));

        verticalLayout_69->addWidget(BLE_displayLog);


        horizontalLayout_79->addLayout(verticalLayout_69);


        verticalLayout_70->addWidget(groupBox_22);

        BLE_display = new QTextBrowser(BLE_data);
        BLE_display->setObjectName(QStringLiteral("BLE_display"));

        verticalLayout_70->addWidget(BLE_display);

        function->addTab(BLE_data, QString());
        BLE_map = new QWidget();
        BLE_map->setObjectName(QStringLiteral("BLE_map"));
        verticalLayout_72 = new QVBoxLayout(BLE_map);
        verticalLayout_72->setObjectName(QStringLiteral("verticalLayout_72"));
        horizontalLayout_64 = new QHBoxLayout();
        horizontalLayout_64->setObjectName(QStringLiteral("horizontalLayout_64"));
        groupBox_25 = new QGroupBox(BLE_map);
        groupBox_25->setObjectName(QStringLiteral("groupBox_25"));
        groupBox_25->setMinimumSize(QSize(150, 0));
        groupBox_25->setMaximumSize(QSize(150, 16777215));
        verticalLayout_74 = new QVBoxLayout(groupBox_25);
        verticalLayout_74->setObjectName(QStringLiteral("verticalLayout_74"));
        horizontalLayout_81 = new QHBoxLayout();
        horizontalLayout_81->setObjectName(QStringLiteral("horizontalLayout_81"));
        label_51 = new QLabel(groupBox_25);
        label_51->setObjectName(QStringLiteral("label_51"));
        label_51->setAlignment(Qt::AlignCenter);

        horizontalLayout_81->addWidget(label_51);

        BLE_xPointEdit = new QTextEdit(groupBox_25);
        BLE_xPointEdit->setObjectName(QStringLiteral("BLE_xPointEdit"));
        BLE_xPointEdit->setMaximumSize(QSize(50, 25));

        horizontalLayout_81->addWidget(BLE_xPointEdit);

        label_52 = new QLabel(groupBox_25);
        label_52->setObjectName(QStringLiteral("label_52"));
        label_52->setAlignment(Qt::AlignCenter);

        horizontalLayout_81->addWidget(label_52);

        BLE_yPointEdit = new QTextEdit(groupBox_25);
        BLE_yPointEdit->setObjectName(QStringLiteral("BLE_yPointEdit"));
        BLE_yPointEdit->setMaximumSize(QSize(50, 25));

        horizontalLayout_81->addWidget(BLE_yPointEdit);


        verticalLayout_74->addLayout(horizontalLayout_81);

        horizontalLayout_69 = new QHBoxLayout();
        horizontalLayout_69->setObjectName(QStringLiteral("horizontalLayout_69"));
        BLE_addAnt = new QPushButton(groupBox_25);
        BLE_addAnt->setObjectName(QStringLiteral("BLE_addAnt"));
        BLE_addAnt->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_69->addWidget(BLE_addAnt);

        BLE_deleteAnt = new QPushButton(groupBox_25);
        BLE_deleteAnt->setObjectName(QStringLiteral("BLE_deleteAnt"));
        BLE_deleteAnt->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_69->addWidget(BLE_deleteAnt);


        verticalLayout_74->addLayout(horizontalLayout_69);

        BLE_rssiCalculatorLabel = new QLabel(groupBox_25);
        BLE_rssiCalculatorLabel->setObjectName(QStringLiteral("BLE_rssiCalculatorLabel"));

        verticalLayout_74->addWidget(BLE_rssiCalculatorLabel);

        BLE_rssiCalculatorSlider = new QSlider(groupBox_25);
        BLE_rssiCalculatorSlider->setObjectName(QStringLiteral("BLE_rssiCalculatorSlider"));
        BLE_rssiCalculatorSlider->setMaximum(100);
        BLE_rssiCalculatorSlider->setOrientation(Qt::Horizontal);

        verticalLayout_74->addWidget(BLE_rssiCalculatorSlider);

        BLE_roundMeter = new QLabel(groupBox_25);
        BLE_roundMeter->setObjectName(QStringLiteral("BLE_roundMeter"));

        verticalLayout_74->addWidget(BLE_roundMeter);

        horizontalSlider = new QSlider(groupBox_25);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(99);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_74->addWidget(horizontalSlider);

        BLE_showDeviceInf = new QPushButton(groupBox_25);
        BLE_showDeviceInf->setObjectName(QStringLiteral("BLE_showDeviceInf"));

        verticalLayout_74->addWidget(BLE_showDeviceInf);

        BLE_hideDeviceInf = new QPushButton(groupBox_25);
        BLE_hideDeviceInf->setObjectName(QStringLiteral("BLE_hideDeviceInf"));

        verticalLayout_74->addWidget(BLE_hideDeviceInf);

        BLE_showAllDeviceInf = new QPushButton(groupBox_25);
        BLE_showAllDeviceInf->setObjectName(QStringLiteral("BLE_showAllDeviceInf"));

        verticalLayout_74->addWidget(BLE_showAllDeviceInf);

        BLE_hideAllDeviceInf = new QPushButton(groupBox_25);
        BLE_hideAllDeviceInf->setObjectName(QStringLiteral("BLE_hideAllDeviceInf"));

        verticalLayout_74->addWidget(BLE_hideAllDeviceInf);

        horizontalLayout_76 = new QHBoxLayout();
        horizontalLayout_76->setObjectName(QStringLiteral("horizontalLayout_76"));
        label_56 = new QLabel(groupBox_25);
        label_56->setObjectName(QStringLiteral("label_56"));
        label_56->setMinimumSize(QSize(36, 0));
        label_56->setMaximumSize(QSize(36, 16777215));
        label_56->setAlignment(Qt::AlignCenter);

        horizontalLayout_76->addWidget(label_56);

        BLE_virtualAntIdEdit = new QTextEdit(groupBox_25);
        BLE_virtualAntIdEdit->setObjectName(QStringLiteral("BLE_virtualAntIdEdit"));
        BLE_virtualAntIdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_76->addWidget(BLE_virtualAntIdEdit);


        verticalLayout_74->addLayout(horizontalLayout_76);

        horizontalLayout_80 = new QHBoxLayout();
        horizontalLayout_80->setObjectName(QStringLiteral("horizontalLayout_80"));
        label_57 = new QLabel(groupBox_25);
        label_57->setObjectName(QStringLiteral("label_57"));
        label_57->setMinimumSize(QSize(36, 0));
        label_57->setMaximumSize(QSize(36, 16777215));
        label_57->setAlignment(Qt::AlignCenter);

        horizontalLayout_80->addWidget(label_57);

        BLE_virtualDeviceIdEdit = new QTextEdit(groupBox_25);
        BLE_virtualDeviceIdEdit->setObjectName(QStringLiteral("BLE_virtualDeviceIdEdit"));
        BLE_virtualDeviceIdEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_80->addWidget(BLE_virtualDeviceIdEdit);


        verticalLayout_74->addLayout(horizontalLayout_80);

        horizontalLayout_84 = new QHBoxLayout();
        horizontalLayout_84->setObjectName(QStringLiteral("horizontalLayout_84"));
        label_59 = new QLabel(groupBox_25);
        label_59->setObjectName(QStringLiteral("label_59"));
        label_59->setMinimumSize(QSize(36, 0));
        label_59->setMaximumSize(QSize(36, 16777215));
        label_59->setAlignment(Qt::AlignCenter);

        horizontalLayout_84->addWidget(label_59);

        BLE_virtualSeqEdit = new QTextEdit(groupBox_25);
        BLE_virtualSeqEdit->setObjectName(QStringLiteral("BLE_virtualSeqEdit"));
        BLE_virtualSeqEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_84->addWidget(BLE_virtualSeqEdit);


        verticalLayout_74->addLayout(horizontalLayout_84);

        horizontalLayout_83 = new QHBoxLayout();
        horizontalLayout_83->setObjectName(QStringLiteral("horizontalLayout_83"));
        label_58 = new QLabel(groupBox_25);
        label_58->setObjectName(QStringLiteral("label_58"));
        label_58->setMinimumSize(QSize(36, 0));
        label_58->setMaximumSize(QSize(36, 16777215));
        label_58->setAlignment(Qt::AlignCenter);

        horizontalLayout_83->addWidget(label_58);

        BLE_virtualRssiEdit = new QTextEdit(groupBox_25);
        BLE_virtualRssiEdit->setObjectName(QStringLiteral("BLE_virtualRssiEdit"));
        BLE_virtualRssiEdit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_83->addWidget(BLE_virtualRssiEdit);


        verticalLayout_74->addLayout(horizontalLayout_83);

        BLE_virtualSetBt = new QPushButton(groupBox_25);
        BLE_virtualSetBt->setObjectName(QStringLiteral("BLE_virtualSetBt"));

        verticalLayout_74->addWidget(BLE_virtualSetBt);

        BLE_attenuationcheckBox = new QCheckBox(groupBox_25);
        BLE_attenuationcheckBox->setObjectName(QStringLiteral("BLE_attenuationcheckBox"));

        verticalLayout_74->addWidget(BLE_attenuationcheckBox);

        BLE_attenuationWithoutCentercheckBox = new QCheckBox(groupBox_25);
        BLE_attenuationWithoutCentercheckBox->setObjectName(QStringLiteral("BLE_attenuationWithoutCentercheckBox"));

        verticalLayout_74->addWidget(BLE_attenuationWithoutCentercheckBox);

        BLE_FiltercheckBox = new QCheckBox(groupBox_25);
        BLE_FiltercheckBox->setObjectName(QStringLiteral("BLE_FiltercheckBox"));

        verticalLayout_74->addWidget(BLE_FiltercheckBox);

        BLE_xyPointCheckBox = new QCheckBox(groupBox_25);
        BLE_xyPointCheckBox->setObjectName(QStringLiteral("BLE_xyPointCheckBox"));

        verticalLayout_74->addWidget(BLE_xyPointCheckBox);

        BLE_radiusCheckBox = new QCheckBox(groupBox_25);
        BLE_radiusCheckBox->setObjectName(QStringLiteral("BLE_radiusCheckBox"));

        verticalLayout_74->addWidget(BLE_radiusCheckBox);

        BLE_AreaCheckBox = new QCheckBox(groupBox_25);
        BLE_AreaCheckBox->setObjectName(QStringLiteral("BLE_AreaCheckBox"));

        verticalLayout_74->addWidget(BLE_AreaCheckBox);

        BLE_AreaAloneCheckBox = new QCheckBox(groupBox_25);
        BLE_AreaAloneCheckBox->setObjectName(QStringLiteral("BLE_AreaAloneCheckBox"));

        verticalLayout_74->addWidget(BLE_AreaAloneCheckBox);

        horizontalLayout_85 = new QHBoxLayout();
        horizontalLayout_85->setObjectName(QStringLiteral("horizontalLayout_85"));
        label_60 = new QLabel(groupBox_25);
        label_60->setObjectName(QStringLiteral("label_60"));
        label_60->setMinimumSize(QSize(36, 0));
        label_60->setMaximumSize(QSize(36, 16777215));
        label_60->setAlignment(Qt::AlignCenter);

        horizontalLayout_85->addWidget(label_60);

        BLE_virtualRatio = new QTextEdit(groupBox_25);
        BLE_virtualRatio->setObjectName(QStringLiteral("BLE_virtualRatio"));
        BLE_virtualRatio->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_85->addWidget(BLE_virtualRatio);


        verticalLayout_74->addLayout(horizontalLayout_85);

        verticalSpacer_9 = new QSpacerItem(20, 200, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_74->addItem(verticalSpacer_9);


        horizontalLayout_64->addWidget(groupBox_25);

        graphicsView_BLE = new QGraphicsView(BLE_map);
        graphicsView_BLE->setObjectName(QStringLiteral("graphicsView_BLE"));

        horizontalLayout_64->addWidget(graphicsView_BLE);


        verticalLayout_72->addLayout(horizontalLayout_64);

        function->addTab(BLE_map, QString());

        horizontalLayout_12->addWidget(function);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1298, 23));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(comboBox_port, comboBox_parity);
        QWidget::setTabOrder(comboBox_parity, comboBox_flcntrl);
        QWidget::setTabOrder(comboBox_flcntrl, bt_cancel);
        QWidget::setTabOrder(bt_cancel, textEd_out);
        QWidget::setTabOrder(textEd_out, bt_send);
        QWidget::setTabOrder(bt_send, textBr_inp);

        retranslateUi(MainWindow);

        function->setCurrentIndex(9);


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
        StoreDir->setText(QApplication::translate("MainWindow", "Store History Dir", 0));
        pb_addAddr->setText(QApplication::translate("MainWindow", "Add", 0));
        pb_deleteAddr->setText(QApplication::translate("MainWindow", "Clear", 0));
        total_id_display->setText(QApplication::translate("MainWindow", "select:", 0));
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
        networkAutoIdStatus->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\210\206\351\205\215ID\350\241\250", 0));
        networkManuIdStatus->setText(QApplication::translate("MainWindow", "\345\233\272\345\256\232\345\210\206\351\205\215ID\350\241\250", 0));
        label_34->setText(QApplication::translate("MainWindow", "ID_MIN", 0));
        textEdit_MIN_ID->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1</p></body></html>", 0));
        label_33->setText(QApplication::translate("MainWindow", "ID_MAX", 0));
        textEdit_MAX_ID->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1000</p></body></html>", 0));
        label_32->setText(QApplication::translate("MainWindow", " Device_Id", 0));
        bt_searchId->setText(QApplication::translate("MainWindow", "\346\220\234\347\264\242ID\344\277\241\346\201\257", 0));
        bt_clearId->setText(QApplication::translate("MainWindow", " \346\270\205\351\231\244ID\344\277\241\346\201\257", 0));
        networkResetIdTable->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215ID\350\241\250", 0));
        export_idList->setText(QApplication::translate("MainWindow", "\345\257\274\345\207\272ID\350\241\250", 0));
        label_35->setText(QApplication::translate("MainWindow", "\350\212\202\347\202\271MAC", 0));
        label_36->setText(QApplication::translate("MainWindow", " \350\256\276\347\275\256ID", 0));
        export_idList_2->setText(QApplication::translate("MainWindow", "E-HH", 0));
        label_39->setText(QApplication::translate("MainWindow", "PANID", 0));
        textEdit_panID->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0xFFFF</p></body></html>", 0));
        label_41->setText(QApplication::translate("MainWindow", "short ID", 0));
        textEdit_shortID->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0xFFFF</p></body></html>", 0));
        label_42->setText(QApplication::translate("MainWindow", "power", 0));
        textEdit_power->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0xFF</p></body></html>", 0));
        label_40->setText(QApplication::translate("MainWindow", "channel", 0));
        textEdit_channel->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0xFF</p></body></html>", 0));
        pushButton_setNetPar->setText(QApplication::translate("MainWindow", " \350\256\276\347\275\256\350\212\202\347\202\271\347\275\221\347\273\234\345\217\202\346\225\260", 0));
        pushButton_requestNetPar->setText(QApplication::translate("MainWindow", " \346\237\245\350\257\242\347\275\221\347\273\234\345\217\202\346\225\260", 0));
        export_idList_3->setText(QApplication::translate("MainWindow", "system reset", 0));
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
         << QApplication::translate("MainWindow", "SOS\346\214\211\351\224\256(\345\270\246\345\256\232\344\275\215)", 0)
         << QApplication::translate("MainWindow", "\346\217\222\345\272\247", 0)
         << QApplication::translate("MainWindow", "\346\270\251\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\346\271\277\345\272\246\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\345\244\232\345\212\237\350\203\275\344\274\240\346\204\237\345\231\250", 0)
         << QApplication::translate("MainWindow", "\350\265\204\344\272\247\346\240\207\347\255\276", 0)
         << QApplication::translate("MainWindow", "\345\233\233\351\200\232\351\201\223\350\257\273\345\244\264", 0)
         << QApplication::translate("MainWindow", "125k\350\265\204\344\272\247\346\240\207\347\255\276", 0)
         << QApplication::translate("MainWindow", "SOS\346\214\211\351\224\256(\344\270\215\345\270\246\345\256\232\344\275\215)", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\211\231\351\200\217\344\274\240863\346\250\241\345\235\227", 0)
         << QApplication::translate("MainWindow", "\346\211\213\346\234\257\345\256\244863\346\250\241\345\235\227", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\211\231\350\265\204\344\272\247\346\240\207\347\255\276", 0)
         << QApplication::translate("MainWindow", "\350\223\235\347\211\231\345\256\232\344\275\215\345\244\251\347\272\277", 0)
         << QApplication::translate("MainWindow", "\344\270\255\347\273\247\345\231\250", 0)
         << QApplication::translate("MainWindow", "\346\231\256\351\200\232\350\212\202\347\202\271", 0)
         << QApplication::translate("MainWindow", "\344\275\216\345\212\237\350\200\227\350\212\202\347\202\271", 0)
         << QApplication::translate("MainWindow", "\346\234\252\347\237\245\350\212\202\347\202\271", 0)
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
        groupBox_8->setTitle(QString());
        label_14->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_23->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_15->setTitle(QString());
        coolStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_16->setTitle(QString());
        coolDisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        coolGetSn->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\274\226\345\217\267", 0));
        coolGetTempreture->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\346\270\251\346\271\277\345\272\246", 0));
        coolDisarm->setText(QApplication::translate("MainWindow", "\350\247\243\351\231\244\346\212\245\350\255\246", 0));
        coolSetSn_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\274\226\345\217\267", 0));
        coolTemVerification_Bt->setText(QApplication::translate("MainWindow", "\346\270\251\345\272\246\346\240\241\346\255\243", 0));
        coolHumVerification_Bt->setText(QApplication::translate("MainWindow", " \346\271\277\345\272\246\346\240\241\346\255\243", 0));
        label_37->setText(QApplication::translate("MainWindow", "H", 0));
        label_38->setText(QApplication::translate("MainWindow", "L", 0));
        coolTemAlarm_Bt->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\344\270\212\344\270\213\351\231\220\346\270\251\345\272\246", 0));
        coolSetRepTime_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\212\346\212\245\346\227\266\351\227\264", 0));
        function->setTabText(function->indexOf(cool), QApplication::translate("MainWindow", "cool", 0));
        groupBox_9->setTitle(QString());
        label_15->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_24->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_13->setTitle(QString());
        energyStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_14->setTitle(QString());
        energyDisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        energyGetMeasurement->setText(QApplication::translate("MainWindow", "\346\237\245\350\257\242\347\224\265\351\207\217\345\217\202\346\225\260", 0));
        energySetRepTime_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\212\346\212\245\346\227\266\351\227\264", 0));
        function->setTabText(function->indexOf(energy), QApplication::translate("MainWindow", "energy", 0));
        groupBox_10->setTitle(QString());
        label_19->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_25->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_17->setTitle(QString());
        injectionStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_18->setTitle(QString());
        injectionDisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        label_27->setText(QApplication::translate("MainWindow", "max", 0));
        injectionTemAlarmH_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">60</p></body></html>", 0));
        label_28->setText(QApplication::translate("MainWindow", "average", 0));
        injectionTemAlarmM_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">45</p></body></html>", 0));
        label_29->setText(QApplication::translate("MainWindow", "min", 0));
        injectionTemAlarmL_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">30</p></body></html>", 0));
        injectionTemAlarm_Bt->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\346\273\264\351\200\237(\346\273\264/S)", 0));
        injectionSetSn_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">01</p></body></html>", 0));
        injectionSetSn_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\347\274\226\345\217\267", 0));
        injectionSetRepTime_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5000</p></body></html>", 0));
        injectionSetRepTime_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\212\346\212\245\346\227\266\351\227\264(mS)", 0));
        injectionSetSpeaker_Bt->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\345\226\207\345\217\255", 0));
        injectionStart_Bt->setText(QApplication::translate("MainWindow", " \345\274\200\345\247\213\350\276\223\346\266\262", 0));
        injectionStop_Bt->setText(QApplication::translate("MainWindow", "\346\232\202\345\201\234\350\276\223\346\266\262", 0));
        injectionFinish_Bt->setText(QApplication::translate("MainWindow", "\345\256\214\346\210\220\350\276\223\346\266\262", 0));
        injectionSetTotalDi_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">5000</p></body></html>", 0));
        injectionSetTotalDi_Bt->setText(QApplication::translate("MainWindow", "\350\276\223\346\266\262\347\223\266\346\273\264\351\207\217", 0));
        injectionSetStopTimeOut_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">15</p></body></html>", 0));
        injectionSetStopTimeOut_Bt->setText(QApplication::translate("MainWindow", "\347\241\256\350\256\244\346\232\202\345\201\234\346\227\266\351\227\264(S)", 0));
        injectionDeviceParameters_list->clear();
        injectionDeviceParameters_list->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "00\346\211\200\346\234\211\345\217\202\346\225\260", 0)
         << QApplication::translate("MainWindow", "01\345\274\200\345\205\263\346\234\272\347\212\266\346\200\201", 0)
         << QApplication::translate("MainWindow", "02\344\270\212\344\270\213\351\231\220", 0)
         << QApplication::translate("MainWindow", "03\350\256\276\345\244\207\345\226\207\345\217\255\345\274\200\347\212\266\346\200\201", 0)
         << QApplication::translate("MainWindow", "04\346\230\276\347\244\272\347\274\226\345\217\267", 0)
         << QApplication::translate("MainWindow", "05\344\270\212\346\212\245\346\227\266\351\227\264", 0)
         << QApplication::translate("MainWindow", "06\347\224\265\346\234\272\347\212\266\346\200\201", 0)
         << QApplication::translate("MainWindow", "08\350\276\223\346\266\262\347\212\266\346\200\201", 0)
         << QApplication::translate("MainWindow", "0E\346\200\273\346\273\264\351\207\217", 0)
         << QApplication::translate("MainWindow", "0F\346\232\202\345\201\234\350\266\205\346\227\266", 0)
        );
        injectionGetDeviceParameters_Bt->setText(QApplication::translate("MainWindow", " \346\237\245\350\257\242", 0));
        injectionDiInit_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        injectionDiInit_Bt->setText(QApplication::translate("MainWindow", "\347\264\257\345\212\240\346\273\264\351\207\217", 0));
        injectionSetDi_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">0</p></body></html>", 0));
        injectionSetDi_Bt->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\267\262\350\276\223\346\273\264\351\207\217", 0));
        injectionSetName_Edit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\346\235\216\346\260\270\345\263\260</p></body></html>", 0));
        injectionSetName_Bt->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\220\215\347\247\260", 0));
        function->setTabText(function->indexOf(injection), QApplication::translate("MainWindow", "injection", 0));
        groupBox_19->setTitle(QString());
        label_30->setText(QApplication::translate("MainWindow", "ID    \347\255\233\351\200\211", 0));
        label_31->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_20->setTitle(QString());
        sosStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_21->setTitle(QString());
        sosDisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        sosSetRepTime_Bt->setText(QApplication::translate("MainWindow", "\344\277\256\346\224\271\344\270\212\346\212\245\346\227\266\351\227\264", 0));
        function->setTabText(function->indexOf(tab), QApplication::translate("MainWindow", " sos", 0));
        groupBox_7->setTitle(QString());
        label_9->setText(QApplication::translate("MainWindow", "ID\347\255\233\351\200\211", 0));
        label_16->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_11->setTitle(QString());
        locationStopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_12->setTitle(QString());
        locationDisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        label_46->setText(QApplication::translate("MainWindow", "125K ID", 0));
        label_47->setText(QApplication::translate("MainWindow", "RSSI", 0));
        bt_setHeartBeatTime_3->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256125K\345\244\251\347\272\277\347\201\265\346\225\217\345\272\246", 0));
        label_26->setText(QApplication::translate("MainWindow", "S ", 0));
        bt_setHeartBeatTime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\277\203\350\267\263\345\214\205\346\227\266\351\227\264", 0));
        function->setTabText(function->indexOf(location), QApplication::translate("MainWindow", "location", 0));
        groupBox_22->setTitle(QString());
        label_43->setText(QApplication::translate("MainWindow", "ID\347\255\233\351\200\211", 0));
        label_44->setText(QApplication::translate("MainWindow", "\345\255\227\347\254\246\344\270\262\347\255\233\351\200\211", 0));
        groupBox_23->setTitle(QString());
        BLE_StopDisplay->setText(QApplication::translate("MainWindow", "  \346\232\202\345\201\234\346\230\276\347\244\272", 0));
        groupBox_24->setTitle(QString());
        BLE_DisplayMac->setText(QApplication::translate("MainWindow", " \346\230\276\347\244\272MAC\345\234\260\345\235\200", 0));
        label_50->setText(QApplication::translate("MainWindow", "125K ID", 0));
        label_53->setText(QApplication::translate("MainWindow", "RSSI", 0));
        BLE__set125KRssi->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256125K\345\244\251\347\272\277\347\201\265\346\225\217\345\272\246", 0));
        label_45->setText(QApplication::translate("MainWindow", "S ", 0));
        BLE_bt_setHeartBeatTime->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256\345\277\203\350\267\263\345\214\205\346\227\266\351\227\264", 0));
        BLE_displayLog->setText(QApplication::translate("MainWindow", "BLE_displayLog", 0));
        function->setTabText(function->indexOf(BLE_data), QApplication::translate("MainWindow", "BLE_data", 0));
        groupBox_25->setTitle(QString());
        label_51->setText(QApplication::translate("MainWindow", "X", 0));
        label_52->setText(QApplication::translate("MainWindow", "Y", 0));
        BLE_addAnt->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\345\244\251\347\272\277", 0));
        BLE_deleteAnt->setText(QApplication::translate("MainWindow", " \345\210\240\351\231\244\345\244\251\347\272\277", 0));
        BLE_rssiCalculatorLabel->setText(QApplication::translate("MainWindow", "\345\244\251\347\272\277\346\240\241\345\207\2060dBm", 0));
        BLE_roundMeter->setText(QApplication::translate("MainWindow", "\345\215\212\345\276\2040\347\261\263\345\234\206\345\275\242", 0));
        BLE_showDeviceInf->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\212\202\347\202\271\344\277\241\346\201\257", 0));
        BLE_hideDeviceInf->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217\350\212\202\347\202\271\344\277\241\346\201\257", 0));
        BLE_showAllDeviceInf->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\346\211\200\346\234\211\350\212\202\347\202\271\344\277\241\346\201\257", 0));
        BLE_hideAllDeviceInf->setText(QApplication::translate("MainWindow", "\351\232\220\350\227\217\346\211\200\346\234\211\350\212\202\347\202\271\344\277\241\346\201\257", 0));
        label_56->setText(QApplication::translate("MainWindow", "\345\244\251\347\272\277ID", 0));
        label_57->setText(QApplication::translate("MainWindow", "\346\240\207\347\255\276ID", 0));
        label_59->setText(QApplication::translate("MainWindow", "\345\272\217\345\210\227\345\217\267", 0));
        label_58->setText(QApplication::translate("MainWindow", "RSSI", 0));
        BLE_virtualSetBt->setText(QApplication::translate("MainWindow", "\346\250\241\346\213\237\346\240\207\347\255\276\346\225\260\346\215\256", 0));
        BLE_attenuationcheckBox->setText(QApplication::translate("MainWindow", "\350\241\260\345\207\217\347\256\227\346\263\225", 0));
        BLE_attenuationWithoutCentercheckBox->setText(QApplication::translate("MainWindow", "\344\270\255\345\277\203\344\270\215\350\241\260\345\207\217\347\256\227\346\263\225", 0));
        BLE_FiltercheckBox->setText(QApplication::translate("MainWindow", "\346\273\244\346\263\242\347\256\227\346\263\225", 0));
        BLE_xyPointCheckBox->setText(QApplication::translate("MainWindow", "\351\231\220\345\210\266xy\345\235\220\346\240\207", 0));
        BLE_radiusCheckBox->setText(QApplication::translate("MainWindow", "\351\231\220\345\210\266\345\234\206\345\215\212\345\276\204", 0));
        BLE_AreaCheckBox->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\214\272\345\237\237", 0));
        BLE_AreaAloneCheckBox->setText(QApplication::translate("MainWindow", "\345\210\206\345\274\200\346\230\276\347\244\272", 0));
        label_60->setText(QApplication::translate("MainWindow", "\346\257\224\345\200\274", 0));
        function->setTabText(function->indexOf(BLE_map), QApplication::translate("MainWindow", "BLE_map", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_FORM_H
