#include "BDD.h"
#include "mainwindow.h"
#include <QMessageBox>

#include "IHM_CreerReservationEquipementSU.h"
#include <QApplication>
#include <QPluginLoader>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD* b=new BDD("localhost","EDT","postgres","root");
    QMessageBox::critical(0,"test",b->request("Select * from promotion").at(0));

    return a.exec();
}
