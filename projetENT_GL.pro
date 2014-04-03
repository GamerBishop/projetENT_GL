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
    BDD.cpp \
    ihm_choixprof.cpp \
    ihm_consulterreservations.cpp \
    ihm_creerreservationchoixequipement.cpp \
    ihm_creerreservationchoixsalle.cpp \
    ihm_creerreservationequipement.cpp \
    ihm_creerreservationequipementSU.cpp \
    ConsulterPlanningSalle2AllUsers.cpp \
    consulterplanningequipement2allusers.cpp \
    creerreservationsalle.cpp \
    creerreservationsallesu.cpp \
    ihm_consulterplanning.cpp


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
    ConsulterPlanningSalle2AllUsers.h \
    consulterplanningequipement2allusers.h \
    creerreservationsalle.h \
    creerreservationsallesu.h \
    ihm_consulterplanning.h
	

FORMS    += mainwindow.ui \
    ihm_choixprof.ui \
    ihm_consulterreservations.ui \
    ihm_creerreservationchoixequipement.ui \
    ihm_creerreservationchoixsalle.ui \
    ihm_creerreservationequipement.ui \
    ihm_creerreservationequipementSU.ui \
    ConsulterPlanningSalle2AllUsers.ui \
    consulterplanningequipement2allusers.ui \
    creerreservationsalle.ui \
    creerreservationsallesu.ui \
    ihm_consulterplanning.ui

OTHER_FILES += \
    Drivers (lire readme).zip \
    projetENT_GL.pro.user \
    projetENT_GL.pro.user.1.3 \
    projetENT_GL.pro.user.8193733 \
    README.md
