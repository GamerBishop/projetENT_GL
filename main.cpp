#include "mainwindow.h"
#include "IHM_CreerReservationEquipementSU.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IHM_CreerReservationEquipementSU w;
    w.show();

    return a.exec();
}
