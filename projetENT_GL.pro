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


SOURCES += main.cpp\
    mainwindow.cpp \
    consulteplanning.cpp \
    BDD.cpp \
    ihm_choixprof.cpp \
    ihm_consulterreservations.cpp \
    ihm_creerreservationchoixequipement.cpp \
    ihm_creerreservationchoixsalle.cpp \
    ihm_creerreservationequipement.cpp \
    ihm_creerreservationequipementSU.cpp


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
    ihm_creerreservationequipementSU.h
	

FORMS    += mainwindow.ui \
    consulteplanning.ui \
    ihm_choixprof.ui \
    ihm_consulterreservations.ui \
    ihm_creerreservationchoixequipement.ui \
    ihm_creerreservationchoixsalle.ui \
    ihm_creerreservationequipement.ui \
    ihm_creerreservationequipementSU.ui
