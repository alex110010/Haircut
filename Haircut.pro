#-------------------------------------------------
#
# Project created by QtCreator 2017-11-15T13:32:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Haircut
TEMPLATE = app


SOURCES += main.cpp\
        haircutmainwidj.cpp

HEADERS  += haircutmainwidj.h

FORMS    += haircutmainwidj.ui

#Подключение заголовочных файлов OpenCV
INCLUDEPATH += D:\opencv_2.4.13\build\include

#Подключение библиотек (.dll и .lib файлов) OpenCV
CONFIG(debug, debug|release) {
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_highgui2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_imgproc2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_core2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_features2d2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_nonfree2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_calib3d2413d.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_photo2413d.lib
} else {
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_highgui2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_imgproc2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_core2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_features2d2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_nonfree2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_calib3d2413.lib
LIBS += D:\opencv_2.4.13\build\x64\vc12\lib\opencv_photo2413.lib
}
