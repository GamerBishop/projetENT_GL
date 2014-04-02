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
    return a.exec();
}
