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
	

FORMS    += mainwindow.ui \
    consulteplanning.ui
