QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    contactdialog.cpp \
    contactswindow.cpp \
    gestiontodo.cpp \
    interactiondialog.cpp \
    interactionswindow.cpp \
    main.cpp \
    contact.cpp \
    date.cpp \
    interaction.cpp \
    lieninteractiontodo.cpp \
    gestioncontacts.cpp \
    gestioninteractions.cpp \
    mainwindow.cpp \
    todo.cpp \
    tododialog.cpp \
    todoswindow.cpp

HEADERS += \
    contact.h \
    contactdialog.h \
    contactswindow.h \
    date.h \
    gestiontodo.h \
    interaction.h \
    interactiondialog.h \
    interactionswindow.h \
    lieninteractiontodo.h \
    gestioncontacts.h \
    gestioninteractions.h \
    mainwindow.h \
    todo.h \
    tododialog.h \
    todoswindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    CRM.qrc
