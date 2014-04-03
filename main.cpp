#include "mainwindow.h"
#include "IHM_ChoixProf.h"
#include "BDD.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BDD * bdd = new BDD("localhost","EDT","postgres","root");
    //BDD * bdd = new BDD();
    MainWindow * w=new MainWindow(bdd,0);
    w->show();

    return a.exec();
}
