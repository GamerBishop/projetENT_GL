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
    BDD* b=new BDD("localhost","EDT","postgres","root");
    ConsulterReservation2AllUsers * w = new ConsulterReservation2AllUsers(b);
    w->show();
    return a.exec();
}
