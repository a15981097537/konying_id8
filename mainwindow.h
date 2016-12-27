 #ifndef MAINWINDOW_H	
 #define MAINWINDOW_H

#include <QMainWindow>
#include "ui_main_window_form.h"
#include <threadcomport.h>
#define Q_WS_WIN 1
enum TypeDataInOut {DEC_, ASCII_, HEX_, BIN_};

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
public:
    MainWindow();
    ~MainWindow();
protected:
     void closeEvent(QCloseEvent *event);

private:
	Qthreadcomport *port;
	QMainComThread *mainComThread;
	QTimer *timerout;
	QMenu *fileMenu;
	QMenu *helpMenu;
	QMenu *editMenu;
	QAction *exitAct;
	QAction *aboutAct;
	QAction *calcTimeoutAct;
	QTime *timeoutTime;
	QLabel *labelReceive;
	QLabel *labelTransmit;
	int counter_in,counter_out;
    QByteArray file_send;
    long file_send_count;

	bool bRTS;
	bool bDTR;
	void createMainMenu();
	void getdataout(QByteArray *data);
	void readSettings(PortSettings *portsettings);
	QString transformInpData(const unsigned char *data, int size);
    void writeSettings();
	
private slots:
	void about();
	void applyPortOptions();
	void btsendClick();
	void btstopsendClick();
	void closePort();
	void enabledPortBt();
	void openPort();
	void receiveMsg(const QTime timesl, const unsigned char *data, const int size);
	void SetCurComboBState();
	void setTimeoutTimer(bool state);
	void transmitMsg();
	void intervalChange(int value);
    void on_File_clicked();
};

 #endif