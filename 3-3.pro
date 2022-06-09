#-------------------------------------------------
#
# Project created by QtCreator 2019-09-18T18:52:30
#
#-------------------------------------------------

QT       += core gui\
            core gui multimedia multimediawidgets\
            core gui multimedia\
            core gui quick

QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3-3
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    logindialog.cpp \
    widget.cpp \
    kuan.cpp \
    dialog.cpp \
    dialog1.cpp \
    dialog2.cpp \
    mainwindow2.cpp \
    digitslclock.cpp \
    clockwidget.cpp \
    form.cpp \
    tetrixwindow.cpp \
    tetrixboard.cpp \
    tetrixpiece.cpp \
    form_game.cpp \
    form_home.cpp \
    form_dianzi.cpp \
    form_zhong.cpp \
    huitu.cpp \
    mainwidget.cpp \
    geometryengine.cpp \
    form_camera.cpp \
    form_luyin.cpp \
    camera.cpp \
    recorder.cpp \
    form_sound.cpp \
    form_video.cpp \
    vedio.cpp \
    sound.cpp \
    initwidget.cpp \
    widget1.cpp \
    form_time.cpp \
    form_nine.cpp \
    form_clo.cpp \
    QtMineSweep-master/game_model.cpp \
    QtMineSweep-master/main_game_window.cpp

HEADERS  += mainwindow.h \
    logindialog.h \
    widget.h \
    kuan.h \
    dialog.h \
    dialog1.h \
    dialog2.h \
    mainwindow2.h \
    digitslclock.h \
    clockwidget.h \
    form.h \
    tetrixwindow.h \
    tetrixboard.h \
    tetrixpiece.h \
    form_game.h \
    form_home.h \
    form_dianzi.h \
    form_zhong.h \
    huitu.h \
    mainwidget.h \
    geometryengine.h \
    form_camera.h \
    form_luyin.h \
    camera.h \
    recorder.h \
    form_sound.h \
    form_video.h \
    vedio.h \
    sound.h \
    initwidget.h \
    widget1.h \
    form_time.h \
    form_nine.h \
    form_clo.h \
    QtMineSweep-master/game_model.h \
    QtMineSweep-master/main_game_window.h

FORMS    += mainwindow.ui \
    logindialog.ui \
    widget.ui \
    kuan.ui \
    dialog.ui \
    dialog1.ui \
    dialog2.ui \
    mainwindow2.ui \
    digitslclock.ui \
    clockwidget.ui \
    form.ui \
    form_game.ui \
    form_home.ui \
    form_dianzi.ui \
    form_zhong.ui \
    huitu.ui \
    form_camera.ui \
    form_luyin.ui \
    camera.ui \
    recorder.ui \
    form_sound.ui \
    form_video.ui \
    vedio.ui \
    sound.ui \
    initwidget.ui \
    widget1.ui \
    form_time.ui \
    form_nine.ui \
    form_clo.ui \
    QtMineSweep-master/maingamewindow.ui

RC_ICONS=myico.ico

RESOURCES += \
    myimages1.qrc \
    QtMineSweep-master/resource.qrc

DISTFILES += \
    my.qss \
    my1.qss \
    my2.qss \
    my3.qss \
    image/beijing2.jpg \
    image/bj.jpg \
    image/hd.jpg \
    image/riqi.jpg \
    QtMineSweep-master/QtMineSweep.pro.user \
    QtMineSweep-master/QtMineSweep.pro.user.861cae8 \
    QtMineSweep-master/README.md

SUBDIRS += \
    QtMineSweep-master/QtMineSweep.pro


