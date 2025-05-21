QT       += core gui


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    # blockmouseevents.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_extra_select.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_first.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_menu.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_menubtn.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_menubtn2.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_mw.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_popup_happy.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_popup_order_method.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_select_flavor.cpp \
    # build/Desktop_Qt_6_9_0-Debug/moc_select_menu.cpp \
    # build/Desktop_Qt_6_9_0-Debug/qrc_image.cpp \
    cart_concup.cpp \
    extra_select.cpp \
    first.cpp \
    first_widget.cpp \
    # image.cpp \
    main.cpp \
    menu.cpp \
    menubtn.cpp \
    menubtn2.cpp \
    mw.cpp \
    option.cpp \
    popup_happy.cpp \
    popup_order_method.cpp \
    second_widget.cpp \
    select_flavor.cpp \
    select_menu.cpp

HEADERS += \
    # blockmouseevents.h \
    build/Desktop_Qt_6_9_0-Debug/moc_predefs.h \
    cart_concup.h \
    extra_select.h \
    first.h \
    first_widget.h \
    menu.h \
    menubtn.h \
    menubtn2.h \
    mw.h \
    option.h \
    popup_happy.h \
    popup_order_method.h \
    second_widget.h \
    select_flavor.h \
    select_menu.h

FORMS += \
    cart_concup.ui \
    extra_select.ui \
    first.ui \
    first_widget.ui \
    menu.ui \
    menubtn.ui \
    menubtn2.ui \
    mw.ui \
    popup_happy.ui \
    popup_order_method.ui \
    second_widget.ui \
    select_flavor.ui \
    select_menu.ui

QT += \
    sql

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc
