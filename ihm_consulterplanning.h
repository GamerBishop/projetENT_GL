#ifndef IHM_CONSULTERPLANNING_H
#define IHM_CONSULTERPLANNING_H

#include <QMainWindow>
#include "BDD.h"
namespace Ui {
class IHM_ConsulterPlanning;
}

class IHM_ConsulterPlanning : public QMainWindow
{
    Q_OBJECT

public:
    explicit IHM_ConsulterPlanning(BDD *bdd,bool focusSalle, QWidget *parent = 0);
    ~IHM_ConsulterPlanning();

private:
    Ui::IHM_ConsulterPlanning *ui;
    BDD * bdd;
signals:
    void signalRetour(bool salle);
public slots :
    void planningEquipement();
    void planningSalle();
    void retourEquipement();
    void retourSalle();
};

#endif // IHM_CONSULTERPLANNING_H
