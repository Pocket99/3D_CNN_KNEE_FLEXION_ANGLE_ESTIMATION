QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QT += multimedia
QT += multimediawidgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    main.cpp \
    mainwindow.cpp \
    userinfo.cpp

HEADERS += \
    database.h \
    mainwindow.h \
    userinfo.h

FORMS += \
    mainwindow.ui \
    userinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world455
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world455d
else:unix: LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world455

INCLUDEPATH += C:/opencv/build/include
DEPENDPATH += C:/opencv/build/include
