PROJECT = Qt_comport
TEMPLATE = app
DEPENDPATH += .
INCLUDEPATH += qextserialport threadcomport

FORMS += main_window_form.ui

HEADERS += 	mainwindow.h \
		threadcomport/threadcomport.h \
		qextserialport/qextserialbase.h \
		qextserialport/qextserialport.h \
    user_md5.h \
    mangeid.h


SOURCES += 	main.cpp \
		mainwindow.cpp \
		threadcomport/threadcomport.cpp \
		qextserialport/qextserialbase.cpp \
		qextserialport/qextserialport.cpp \
    user_md5.cpp \
    mangeid.cpp


RESOURCES     = resources.grc

unix:{
	DEFINES   = _TTY_POSIX_
	HEADERS +=  qextserialport/posix_qextserialport.h
	SOURCES +=  qextserialport/posix_qextserialport.cpp
}
win32 {
	DEFINES  = _TTY_WIN_
	RC_FILE = Qt_comport.rc
	HEADERS +=  qextserialport/win_qextserialport.h
	SOURCES +=  qextserialport/win_qextserialport.cpp
        QT += widgets
}

QT += network
