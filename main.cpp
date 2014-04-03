#include "BDD.h"
#include "mainwindow.h"
#include <QMessageBox>

#include "ConsulterReservation2AllUsers.h"
#include "consulterreservation2su.h"
#include "creerresevationsalle.h"
#include "consulterplanningequipementsu.h"
#include "IHM_CreerReservationEquipementSU.h"
#include "ihm_choixprof.h"
#include <QApplication>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD* b=new BDD();
    QString * s = new QString("Ta mere en slip");
    IHM_ChoixProf * w = new IHM_ChoixProf();
    w->show();
    return a.exec();
}
