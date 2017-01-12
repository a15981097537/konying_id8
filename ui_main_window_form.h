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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QDockWidget *dockWidgetmessage;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_2;
    QTextBrowser *textBr_mess;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *bt_clear;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_1;
    QRadioButton *rbt_Decin;
    QRadioButton *rbt_ASCIIin;
    QRadioButton *rbt_BINin;
    QRadioButton *rbt_HEXin;
    QTextBrowser *textBr_inp;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QComboBox *comboBox_port;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QComboBox *comboBox_baudrate;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QComboBox *comboBox_parity;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_6;
    QComboBox *comboBox_flcntrl;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *bt_apply;
    QPushButton *bt_cancel;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *bt_openport;
    QPushButton *bt_closeport;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_7;
    QSpinBox *spinBox_Period;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *bt_send;
    QPushButton *bt_stopsend;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QRadioButton *File;
    QRadioButton *rbt_Decout;
    QRadioButton *rbt_ASCIIout;
    QRadioButton *rbt_BINout;
    QRadioButton *rbt_HEXout;
    QTextEdit *textEd_out;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(908, 666);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        dockWidgetmessage = new QDockWidget(centralwidget);
        dockWidgetmessage->setObjectName(QStringLiteral("dockWidgetmessage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetmessage->sizePolicy().hasHeightForWidth());
        dockWidgetmessage->setSizePolicy(sizePolicy);
        dockWidgetmessage->setMaximumSize(QSize(524287, 524287));
        dockWidgetmessage->setAutoFillBackground(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_2 = new QGridLayout(dockWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        textBr_mess = new QTextBrowser(dockWidgetContents);
        textBr_mess->setObjectName(QStringLiteral("textBr_mess"));

        gridLayout_2->addWidget(textBr_mess, 0, 0, 1, 1);

        dockWidgetmessage->setWidget(dockWidgetContents);

        gridLayout->addWidget(dockWidgetmessage, 1, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(5);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy1);
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        bt_clear = new QPushButton(groupBox_3);
        bt_clear->setObjectName(QStringLiteral("bt_clear"));

        horizontalLayout_3->addWidget(bt_clear);

        horizontalSpacer_4 = new QSpacerItem(308, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);


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


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        comboBox_port = new QComboBox(groupBox);
        comboBox_port->setObjectName(QStringLiteral("comboBox_port"));

        horizontalLayout_5->addWidget(comboBox_port);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        comboBox_baudrate = new QComboBox(groupBox);
        comboBox_baudrate->setObjectName(QStringLiteral("comboBox_baudrate"));

        horizontalLayout_6->addWidget(comboBox_baudrate);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_8->addWidget(label_5);

        comboBox_parity = new QComboBox(groupBox);
        comboBox_parity->setObjectName(QStringLiteral("comboBox_parity"));

        horizontalLayout_8->addWidget(comboBox_parity);


        verticalLayout_3->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_9->addWidget(label_6);

        comboBox_flcntrl = new QComboBox(groupBox);
        comboBox_flcntrl->setObjectName(QStringLiteral("comboBox_flcntrl"));

        horizontalLayout_9->addWidget(comboBox_flcntrl);


        verticalLayout_3->addLayout(horizontalLayout_9);

        verticalSpacer = new QSpacerItem(20, 21, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        bt_apply = new QPushButton(groupBox);
        bt_apply->setObjectName(QStringLiteral("bt_apply"));

        horizontalLayout_10->addWidget(bt_apply);

        bt_cancel = new QPushButton(groupBox);
        bt_cancel->setObjectName(QStringLiteral("bt_cancel"));

        horizontalLayout_10->addWidget(bt_cancel);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        bt_openport = new QPushButton(groupBox);
        bt_openport->setObjectName(QStringLiteral("bt_openport"));

        horizontalLayout_7->addWidget(bt_openport);

        bt_closeport = new QPushButton(groupBox);
        bt_closeport->setObjectName(QStringLiteral("bt_closeport"));

        horizontalLayout_7->addWidget(bt_closeport);


        verticalLayout_3->addLayout(horizontalLayout_7);


        gridLayout->addWidget(groupBox, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_11->addWidget(label_7);

        spinBox_Period = new QSpinBox(groupBox_2);
        spinBox_Period->setObjectName(QStringLiteral("spinBox_Period"));
        spinBox_Period->setMaximum(10000);
        spinBox_Period->setSingleStep(10);

        horizontalLayout_11->addWidget(spinBox_Period);

        progressBar = new QProgressBar(groupBox_2);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        horizontalLayout_11->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_11);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        bt_send = new QPushButton(groupBox_2);
        bt_send->setObjectName(QStringLiteral("bt_send"));

        horizontalLayout_2->addWidget(bt_send);

        bt_stopsend = new QPushButton(groupBox_2);
        bt_stopsend->setObjectName(QStringLiteral("bt_stopsend"));

        horizontalLayout_2->addWidget(bt_stopsend);

        horizontalSpacer_2 = new QSpacerItem(228, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(58, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        File = new QRadioButton(groupBox_2);
        File->setObjectName(QStringLiteral("File"));

        horizontalLayout->addWidget(File);

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


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 908, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        statusbar->setSizeGripEnabled(true);
        MainWindow->setStatusBar(statusbar);
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
        QWidget::setTabOrder(textBr_inp, textBr_mess);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Qt_comport", 0));
        dockWidgetmessage->setWindowTitle(QApplication::translate("MainWindow", "Messages", 0));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "PORT SETTINGS", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port", 0));
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
        File->setText(QApplication::translate("MainWindow", "File", 0));
        rbt_Decout->setText(QApplication::translate("MainWindow", "Decimal", 0));
        rbt_ASCIIout->setText(QApplication::translate("MainWindow", "ASCII", 0));
        rbt_BINout->setText(QApplication::translate("MainWindow", "BIN", 0));
        rbt_HEXout->setText(QApplication::translate("MainWindow", "HEX", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_FORM_H
