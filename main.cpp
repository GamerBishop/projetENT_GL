#include "BDD.h"
#include "mainwindow.h"
#include <QMessageBox>

#include "ConsulterReservation2AllUsers.h"
#include "consulterreservation2su.h"
#include "creerresevationsalle.h"

#include "IHM_CreerReservationEquipementSU.h"
#include <QApplication>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //BDD* b=new BDD("10.7.36.4","EDT","postgres","root");
    ConsulterReservation2SU * w = new ConsulterReservation2SU();
    w->show();
    return a.exec();
}
