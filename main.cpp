#include "BDD.h"
#include "mainwindow.h"
#include <QMessageBox>

#include "ConsulterReservation2AllUsers.h"

#include "IHM_CreerReservationEquipementSU.h"
#include <QApplication>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD* b=new BDD("10.7.36.4","EDT","postgres","root");
    ConsulterReservation2AllUsers * w = new ConsulterReservation2AllUsers(b,"P136","Pascal");
    w->show();
    return a.exec();
}
