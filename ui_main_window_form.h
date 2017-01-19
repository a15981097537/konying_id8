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
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *comboBox_port;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *bt_openport;
    QPushButton *bt_closeport;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_3;
    QComboBox *comboBox_baudrate;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_5;
    QComboBox *comboBox_parity;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_6;
    QComboBox *comboBox_flcntrl;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *bt_apply;
    QPushButton *bt_cancel;
    QListWidget *shortAddr;
    QTabWidget *function;
    QWidget *uart;
    QVBoxLayout *verticalLayout_4;
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
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *bt_clear;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_1;
    QRadioButton *rbt_Decin;
    QRadioButton *rbt_ASCIIin;
    QRadioButton *rbt_BINin;
    QRadioButton *rbt_HEXin;
    QTextBrowser *textBr_inp;
    QWidget *firmware_update;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *updateFileList;
    QPushButton *bt_openFile;
    QHBoxLayout *horizontalLayout_14;
    QComboBox *readFileList;
    QPushButton *bt_storeFile;
    QProgressBar *progressBar;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QComboBox *comboBox_updateWay;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_8;
    QComboBox *comboBox_updateMode;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_11;
    QComboBox *frimwareVersion;
    QVBoxLayout *verticalLayout_12;
    QPushButton *bt_getDeviceInf;
    QPushButton *bt_sendFirInf;
    QVBoxLayout *verticalLayout_13;
    QPushButton *bt_sendPacket;
    QPushButton *pushButton_4;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_10;
    QPushButton *bt_autoUpdate;
    QPushButton *bt_stopAutoUpdate;
    QVBoxLayout *verticalLayout_11;
    QPushButton *bt_readBoot;
    QPushButton *bt_readFirmware;
    QVBoxLayout *verticalLayout_14;
    QPushButton *bt_stopRead;
    QPushButton *pushButton_5;
    QTextBrowser *textBr_mess;
    QWidget *CMD;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1015, 714);
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
        verticalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        comboBox_port = new QComboBox(groupBox);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));

        horizontalLayout_5->addWidget(comboBox_port);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        bt_openport = new QPushButton(groupBox);
        bt_openport->setObjectName(QStringLiteral("bt_openport"));

        horizontalLayout_7->addWidget(bt_openport);

        bt_closeport = new QPushButton(groupBox);
        bt_closeport->setObjectName(QStringLiteral("bt_closeport"));

        horizontalLayout_7->addWidget(bt_closeport);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QStringLiteral("verticalLayout_17"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_17->addWidget(label_3);

        comboBox_baudrate = new QComboBox(groupBox);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));

        verticalLayout_17->addWidget(comboBox_baudrate);


        verticalLayout_3->addLayout(verticalLayout_17);

        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QStringLiteral("verticalLayout_16"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_16->addWidget(label_5);

        comboBox_parity = new QComboBox(groupBox);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));

        verticalLayout_16->addWidget(comboBox_parity);


        verticalLayout_3->addLayout(verticalLayout_16);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QStringLiteral("verticalLayout_15"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_15->addWidget(label_6);

        comboBox_flcntrl = new QComboBox(groupBox);
        comboBox_flcntrl->setObjectName(QStringLiteral("comboBox_flcntrl"));

        verticalLayout_15->addWidget(comboBox_flcntrl);


        verticalLayout_3->addLayout(verticalLayout_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        bt_apply = new QPushButton(groupBox);
        bt_apply->setObjectName(QStringLiteral("bt_apply"));

        horizontalLayout_10->addWidget(bt_apply);

        bt_cancel = new QPushButton(groupBox);
        bt_cancel->setObjectName(QStringLiteral("bt_cancel"));

        horizontalLayout_10->addWidget(bt_cancel);


        verticalLayout_3->addLayout(horizontalLayout_10);

        shortAddr = new QListWidget(groupBox);
        shortAddr->setObjectName(QStringLiteral("shortAddr"));

        verticalLayout_3->addWidget(shortAddr);


        horizontalLayout_12->addWidget(groupBox);

        function = new QTabWidget(centralwidget);
        function->setObjectName(QStringLiteral("function"));
        uart = new QWidget();
        uart->setObjectName(QStringLiteral("uart"));
        verticalLayout_4 = new QVBoxLayout(uart);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        groupBox_2 = new QGroupBox(uart);
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


        verticalLayout_4->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(uart);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_4 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        bt_clear = new QPushButton(groupBox_3);
        bt_clear->setObjectName(QStringLiteral("bt_clear"));

        horizontalLayout_3->addWidget(bt_clear);


        verticalLayout_2->addLayout(horizontalLayout_3);

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


        verticalLayout_4->addWidget(groupBox_3);

        function->addTab(uart, QString());
        firmware_update = new QWidget();
        firmware_update->setObjectName(QStringLiteral("firmware_update"));
        verticalLayout_5 = new QVBoxLayout(firmware_update);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        groupBox_4 = new QGroupBox(firmware_update);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_9 = new QVBoxLayout(groupBox_4);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        updateFileList = new QComboBox(groupBox_4);
        updateFileList->setObjectName(QStringLiteral("updateFileList"));

        horizontalLayout_13->addWidget(updateFileList);

        bt_openFile = new QPushButton(groupBox_4);
        bt_openFile->setObjectName(QStringLiteral("bt_openFile"));
        bt_openFile->setMinimumSize(QSize(0, 0));
        bt_openFile->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_13->addWidget(bt_openFile);


        verticalLayout_9->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        readFileList = new QComboBox(groupBox_4);
        readFileList->setObjectName(QStringLiteral("readFileList"));

        horizontalLayout_14->addWidget(readFileList);

        bt_storeFile = new QPushButton(groupBox_4);
        bt_storeFile->setObjectName(QStringLiteral("bt_storeFile"));
        bt_storeFile->setMinimumSize(QSize(0, 0));
        bt_storeFile->setMaximumSize(QSize(86, 16777215));

        horizontalLayout_14->addWidget(bt_storeFile);


        verticalLayout_9->addLayout(horizontalLayout_14);


        verticalLayout_5->addWidget(groupBox_4);

        progressBar = new QProgressBar(firmware_update);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_5->addWidget(progressBar);

        groupBox_5 = new QGroupBox(firmware_update);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        horizontalLayout_15 = new QHBoxLayout(groupBox_5);
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label_9 = new QLabel(groupBox_5);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        verticalLayout_6->addWidget(label_9);

        comboBox_updateWay = new QComboBox(groupBox_5);
        comboBox_updateWay->setObjectName(QStringLiteral("comboBox_updateWay"));

        verticalLayout_6->addWidget(comboBox_updateWay);


        horizontalLayout_15->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        label_8 = new QLabel(groupBox_5);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        verticalLayout_7->addWidget(label_8);

        comboBox_updateMode = new QComboBox(groupBox_5);
        comboBox_updateMode->setObjectName(QStringLiteral("comboBox_updateMode"));

        verticalLayout_7->addWidget(comboBox_updateMode);


        horizontalLayout_15->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        verticalLayout_8->addWidget(label_10);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        frimwareVersion = new QComboBox(groupBox_5);
        frimwareVersion->setObjectName(QStringLiteral("frimwareVersion"));

        horizontalLayout_11->addWidget(frimwareVersion);


        verticalLayout_8->addLayout(horizontalLayout_11);


        horizontalLayout_15->addLayout(verticalLayout_8);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        bt_getDeviceInf = new QPushButton(groupBox_5);
        bt_getDeviceInf->setObjectName(QStringLiteral("bt_getDeviceInf"));

        verticalLayout_12->addWidget(bt_getDeviceInf);

        bt_sendFirInf = new QPushButton(groupBox_5);
        bt_sendFirInf->setObjectName(QStringLiteral("bt_sendFirInf"));

        verticalLayout_12->addWidget(bt_sendFirInf);


        horizontalLayout_15->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        bt_sendPacket = new QPushButton(groupBox_5);
        bt_sendPacket->setObjectName(QStringLiteral("bt_sendPacket"));

        verticalLayout_13->addWidget(bt_sendPacket);

        pushButton_4 = new QPushButton(groupBox_5);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout_13->addWidget(pushButton_4);


        horizontalLayout_15->addLayout(verticalLayout_13);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_3);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        bt_autoUpdate = new QPushButton(groupBox_5);
        bt_autoUpdate->setObjectName(QStringLiteral("bt_autoUpdate"));

        verticalLayout_10->addWidget(bt_autoUpdate);

        bt_stopAutoUpdate = new QPushButton(groupBox_5);
        bt_stopAutoUpdate->setObjectName(QStringLiteral("bt_stopAutoUpdate"));

        verticalLayout_10->addWidget(bt_stopAutoUpdate);


        horizontalLayout_15->addLayout(verticalLayout_10);

        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        bt_readBoot = new QPushButton(groupBox_5);
        bt_readBoot->setObjectName(QStringLiteral("bt_readBoot"));

        verticalLayout_11->addWidget(bt_readBoot);

        bt_readFirmware = new QPushButton(groupBox_5);
        bt_readFirmware->setObjectName(QStringLiteral("bt_readFirmware"));

        verticalLayout_11->addWidget(bt_readFirmware);


        horizontalLayout_15->addLayout(verticalLayout_11);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        bt_stopRead = new QPushButton(groupBox_5);
        bt_stopRead->setObjectName(QStringLiteral("bt_stopRead"));

        verticalLayout_14->addWidget(bt_stopRead);

        pushButton_5 = new QPushButton(groupBox_5);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        verticalLayout_14->addWidget(pushButton_5);


        horizontalLayout_15->addLayout(verticalLayout_14);


        verticalLayout_5->addWidget(groupBox_5);

        textBr_mess = new QTextBrowser(firmware_update);
        textBr_mess->setObjectName(QStringLiteral("textBr_mess"));

        verticalLayout_5->addWidget(textBr_mess);

        function->addTab(firmware_update, QString());
        CMD = new QWidget();
        CMD->setObjectName(QStringLiteral("CMD"));
        function->addTab(CMD, QString());

        horizontalLayout_12->addWidget(function);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1015, 23));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(comboBox_port, bt_openport);
        QWidget::setTabOrder(bt_openport, bt_closeport);
        QWidget::setTabOrder(bt_closeport, comboBox_baudrate);
        QWidget::setTabOrder(comboBox_baudrate, comboBox_parity);
        QWidget::setTabOrder(comboBox_parity, comboBox_flcntrl);
        QWidget::setTabOrder(comboBox_flcntrl, bt_apply);
        QWidget::setTabOrder(bt_apply, bt_cancel);
        QWidget::setTabOrder(bt_cancel, textEd_out);
        QWidget::setTabOrder(textEd_out, bt_send);
        QWidget::setTabOrder(bt_send, bt_clear);
        QWidget::setTabOrder(bt_clear, textBr_inp);

        retranslateUi(MainWindow);

        function->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt_comport", 0));
        actionFirmware_update->setText(QApplication::translate("MainWindow", "firmware update", 0));
        actionUart_tool->setText(QApplication::translate("MainWindow", "uart tool", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "PORT SETTINGS", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0));
#ifndef QT_NO_STATUSTIP
        bt_openport->setStatusTip(QApplication::translate("MainWindow", "Open port", 0));
#endif // QT_NO_STATUSTIP
        bt_openport->setText(QApplication::translate("MainWindow", "OPEN", 0));
#ifndef QT_NO_STATUSTIP
        bt_closeport->setStatusTip(QApplication::translate("MainWindow", "Close port", 0));
#endif // QT_NO_STATUSTIP
        bt_closeport->setText(QApplication::translate("MainWindow", "CLOSE", 0));
        label_3->setText(QApplication::translate("MainWindow", "Baudrate", 0));
        label_5->setText(QApplication::translate("MainWindow", "Parity", 0));
        label_6->setText(QApplication::translate("MainWindow", "Flowcontrol", 0));
#ifndef QT_NO_STATUSTIP
        bt_apply->setStatusTip(QApplication::translate("MainWindow", "Apply port settings", 0));
#endif // QT_NO_STATUSTIP
        bt_apply->setText(QApplication::translate("MainWindow", "APPLY", 0));
#ifndef QT_NO_STATUSTIP
        bt_cancel->setStatusTip(QApplication::translate("MainWindow", "Cancel new settings ", 0));
#endif // QT_NO_STATUSTIP
        bt_cancel->setText(QApplication::translate("MainWindow", "CANCEL", 0));
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
#ifndef QT_NO_STATUSTIP
        bt_clear->setStatusTip(QApplication::translate("MainWindow", "Clear input data", 0));
#endif // QT_NO_STATUSTIP
        bt_clear->setText(QApplication::translate("MainWindow", "CLEAR", 0));
        label_4->setText(QApplication::translate("MainWindow", "Data for input", 0));
        rbt_Decin->setText(QApplication::translate("MainWindow", "Decimal", 0));
        rbt_ASCIIin->setText(QApplication::translate("MainWindow", "ASCII", 0));
        rbt_BINin->setText(QApplication::translate("MainWindow", "BIN", 0));
        rbt_HEXin->setText(QApplication::translate("MainWindow", "HEX", 0));
        function->setTabText(function->indexOf(uart), QApplication::translate("MainWindow", "uart", 0));
        groupBox_4->setTitle(QString());
        bt_openFile->setText(QApplication::translate("MainWindow", " \346\211\223\345\274\200\345\233\272\344\273\266", 0));
        bt_storeFile->setText(QApplication::translate("MainWindow", " \345\255\230\345\202\250\345\233\272\344\273\266", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "   \351\205\215\347\275\256\351\200\211\351\241\271", 0));
        label_9->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\346\226\271\345\274\217", 0));
        comboBox_updateWay->clear();
        comboBox_updateWay->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\346\234\254\345\234\260\345\215\207\347\272\247", 0)
         << QApplication::translate("MainWindow", "OTA\345\215\207\347\272\247", 0)
        );
        label_8->setText(QApplication::translate("MainWindow", "\345\215\207\347\272\247\346\250\241\345\274\217", 0));
        comboBox_updateMode->clear();
        comboBox_updateMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\345\215\225\347\213\254\345\215\207\347\272\247", 0)
         << QApplication::translate("MainWindow", "\346\211\271\351\207\217\345\215\207\347\272\247", 0)
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
        bt_getDeviceInf->setText(QApplication::translate("MainWindow", " \350\216\267\345\217\226\351\205\215\344\273\266\350\257\246\347\273\206\344\277\241\346\201\257", 0));
        bt_sendFirInf->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\272\344\273\266\344\277\241\346\201\257", 0));
        bt_sendPacket->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201\345\233\272\344\273\266\346\225\260\346\215\256\345\214\205", 0));
        pushButton_4->setText(QApplication::translate("MainWindow", "NC", 0));
        bt_autoUpdate->setText(QApplication::translate("MainWindow", "\350\207\252\345\212\250\345\215\207\347\272\247\345\233\272\344\273\266", 0));
        bt_stopAutoUpdate->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\350\207\252\345\212\250\345\215\207\347\272\247", 0));
        bt_readBoot->setText(QApplication::translate("MainWindow", " \350\257\273\345\217\226boot", 0));
        bt_readFirmware->setText(QApplication::translate("MainWindow", "  \350\257\273\345\217\226\345\233\272\344\273\266", 0));
        bt_stopRead->setText(QApplication::translate("MainWindow", " \345\201\234\346\255\242\350\257\273\345\217\226", 0));
        pushButton_5->setText(QApplication::translate("MainWindow", "NC", 0));
        function->setTabText(function->indexOf(firmware_update), QApplication::translate("MainWindow", "firmware update", 0));
        function->setTabText(function->indexOf(CMD), QApplication::translate("MainWindow", "CMD", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_FORM_H
