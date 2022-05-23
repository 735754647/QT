#-------------------------------------------------
#
# Project created by QtCreator 2020-05-14T20:05:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StudyQT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    hikvisionsdk.cpp \
    camerainterface.cpp \
    mythread.cpp

HEADERS  += mainwindow.h \
    hikvisionsdk.h \
    camerainterface.h \
    mythread.h

FORMS    += mainwindow.ui

win32:CONFIG(debug, debug|release): {
LIBS += -L$$PWD/lib \
-lopencv_calib3d300d \
-lopencv_core300d \
-lopencv_features2d300d \
-lopencv_flann300d \
-lopencv_highgui300d \
-lopencv_imgcodecs300d \
-lopencv_imgproc300d \
-lopencv_ml300d \
-lopencv_objdetect300d \
-lopencv_photo300d \
-lopencv_shape300d \
-lopencv_stitching300d \
-lopencv_superres300d \
-lopencv_video300d \
-lopencv_videoio300d \
-lopencv_videostab300d

} else:win32:CONFIG(release, debug|release): {
LIBS += -L$$PWD/lib \
-lopencv_calib3d300 \
-lopencv_core300 \
-lopencv_features2d300 \
-lopencv_flann300 \
-lopencv_highgui300 \
-lopencv_imgcodecs300 \
-lopencv_imgproc300 \
-lopencv_ml300 \
-lopencv_objdetect300 \
-lopencv_photo300 \
-lopencv_shape300 \
-lopencv_stitching300 \
-lopencv_superres300 \
-lopencv_video300 \
-lopencv_videoio300 \
-lopencv_videostab300
}


INCLUDEPATH += $$PWD/opencv2 \
               $$PWD/Hik_Includes

LIBS += -L$$PWD/Hik_Libs/ -lMvCameraControl\
