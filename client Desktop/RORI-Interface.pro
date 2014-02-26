QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RORI-Interface
TEMPLATE = app

HEADERS += \
    RORIWidget.h \
    Toolbar.h \
    Interface.h \
    AddActionWidget.h \
    Agenda.h \
    AgendaWidget.h \
    AppearanceOptionWidget.h \
    ConnectOptionWidget.h \
    DelEventWidget.h \
    ModifyActionWidget.h \
    OptionWidget.h

SOURCES += \
    RORIWidget.cpp \
    Toolbar.cpp \
    Interface.cpp \
    main.cpp \
    AddActionWidget.cpp \
    Agenda.cpp \
    AgendaWidget.cpp \
    AppearanceOptionWidget.cpp \
    ConnectOptionWidget.cpp \
    DelEventWidget.cpp \
    ModifyActionWidget.cpp \
    OptionWidget.cpp

