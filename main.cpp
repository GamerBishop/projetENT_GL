#include "BDD.h"
#include "mainwindow.h"
#include <QMessageBox>

#include "ConsulterReservation2AllUsers.h"
#include "consulterreservation2su.h"
#include "creerresevationsalle.h"
#include "consulterplanningequipementalluser.h"

#include "IHM_CreerReservationEquipementSU.h"
#include <QApplication>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD* b=new BDD();
    ConsulterPlanningEquipementAllUser * w = new ConsulterPlanningEquipementAllUser(b,"Ta mere en slip");
    w->show();
    return a.exec();
}
