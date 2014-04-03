#-------------------------------------------------
#
# Project created by QtCreator 2014-03-24T12:15:41
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = projetENT_GL
TEMPLATE = app
QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp\
    mainwindow.cpp \
    consulteplanning.cpp \
    BDD.cpp \
    ihm_choixprof.cpp \
    ihm_consulterreservations.cpp \
    ihm_creerreservationchoixequipement.cpp \
    ihm_creerreservationchoixsalle.cpp \
    ihm_creerreservationequipement.cpp \
    ihm_creerreservationequipementSU.cpp \
    ConsulterReservation2AllUsers.cpp \
    creerresevationsalle.cpp \
    consulterreservation2su.cpp \
    consulterplanningequipementalluser.cpp \
    consulterplanningequipementsu.cpp \
    creerreservationsallesu.cpp


HEADERS  += mainwindow.h \
    Cours.h \
    Eleve.h \
    Enseignant.h \
    Equipement.h \
    Groupe.h \
    Module.h \
    Personne.h \
    Promotion.h \
    ReservationEquipement.h \
    Salle.h \
    TypeGroupe.h \
    TypeSalle.h \
    UniteEnseignement.h \
    consulteplanning.h\
    BDD.h \
    ihm_choixprof.h \
    ihm_consulterreservations.h \
    ihm_creerreservationchoixequipement.h \
    ihm_creerreservationchoixsalle.h \
    ihm_creerreservationequipement.h \
    ihm_creerreservationequipementSU.h \
    ConsulterReservation2AllUsers.h \
    creerresevationsalle.h \
    consulterreservation2su.h \
    consulterplanningequipementalluser.h \
    consulterplanningequipementsu.h \
    consulterplanningequipementsu.cpp.autosave \
    consulterplanningequipementsu.h.autosave \
    creerreservationsallesu.h
	

FORMS    += mainwindow.ui \
    consulteplanning.ui \
    ihm_choixprof.ui \
    ihm_consulterreservations.ui \
    ihm_creerreservationchoixequipement.ui \
    ihm_creerreservationchoixsalle.ui \
    ihm_creerreservationequipement.ui \
    ihm_creerreservationequipementSU.ui \
    ConsulterReservation2AllUsers.ui \
    consulterPlanning.ui \
    creerresevationsalle.ui \
    consulterreservation2su.ui \
    consulterplanningequipementalluser.ui \
    consulterplanningequipementsu.ui \
    creerreservationsallesu.ui

OTHER_FILES += \
    Drivers (lire readme).zip \
    projetENT_GL.pro.user \
    projetENT_GL.pro.user.1.3 \
    projetENT_GL.pro.user.1de26af \
    projetENT_GL.pro.user.8193733 \
    README.md \
    Drivers (lire readme).zip \
    Drivers (lire readme).zip
