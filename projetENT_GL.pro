#-------------------------------------------------
#
# Project created by QtCreator 2014-03-24T12:15:41
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++1y

TARGET = projetENT_GL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp\
    consulteplanning.cpp \
    consulterplanningequipement2allusers.cpp \
    consulterplanningequipementalluser.cpp \
    consulterplanningequipementsu.cpp \
    ConsulterPlanningSalle2AllUsers.cpp \
    ConsulterReservation2SU.cpp \
    creerreservationsalle.cpp \
    creerreservationsallesu.cpp \
    ihm_choixprof.cpp \
    ihm_consulterplanning.cpp \
    ihm_consulterreservations.cpp \
    ihm_creerreservationchoixequipement.cpp \
    ihm_creerreservationchoixsalle.cpp \
    ihm_creerreservationequipement.cpp \
    ihm_creerreservationequipementSU.cpp \
    bdd.cpp

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
    bdd.h \
    consulteplanning.h \
    consulterplanningequipement2allusers.h \
    consulterplanningequipementalluser.h \
    consulterplanningequipementsu.h \
    ConsulterPlanningSalle2AllUsers.h \
    ConsulterReservation2SU.h \
    creerreservationsalle.h \
    creerreservationsallesu.h \
    ihm_choixprof.h \
    ihm_consulterplanning.h \
    ihm_consulterreservations.h \
    ihm_creerreservationchoixequipement.h \
    ihm_creerreservationchoixsalle.h \
    ihm_creerreservationequipement.h \
    ihm_creerreservationequipementSU.h \


FORMS    += mainwindow.ui \
    consulteplanning.ui \
    consulterPlanning.ui \
    consulterplanningequipement2allusers.ui \
    consulterplanningequipementalluser.ui \
    consulterplanningequipementsu.ui \
    ConsulterPlanningSalle2AllUsers.ui \
    ConsulterReservation2SU.ui \
    creerreservationsalle.ui \
    creerreservationsallesu.ui \
    ihm_choixprof.ui \
    ihm_consulterplanning.ui \
    ihm_consulterreservations.ui \
    ihm_creerreservationchoixequipement.ui \
    ihm_creerreservationchoixsalle.ui \
    ihm_creerreservationequipement.ui \
    ihm_creerreservationequipementSU.ui

OTHER_FILES += \
    Drivers (lire readme).zip \
    projetENT_GL.pro.user \
    projetENT_GL.pro.user.1.3 \
    projetENT_GL.pro.user.1de26af \
    projetENT_GL.pro.user.8193733 \
    README.md
