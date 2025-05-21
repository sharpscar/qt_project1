QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    extra_select.cpp \
    first.cpp \
    main.cpp \
    menu.cpp \
    menubtn.cpp \
    menubtn2.cpp \
    mw.cpp \
    option.cpp \
    popup_happy.cpp \
    popup_order_method.cpp

HEADERS += \
    extra_select.h \
    first.h \
    menu.h \
    menubtn.h \
    menubtn2.h \
    mw.h \
    option.h \
    popup_happy.h \
    popup_order_method.h

FORMS += \
    extra_select.ui \
    first.ui \
    menu.ui \
    menubtn.ui \
    menubtn2.ui \
    mw.ui \
    popup_happy.ui \
    popup_order_method.ui

QT += \
    sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
