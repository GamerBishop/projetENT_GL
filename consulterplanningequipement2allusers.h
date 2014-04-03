#ifndef CONSULTERPLANINGEQUIPEMENT2ALLUSERS_H
#define CONSULTERPLANINGEQUIPEMENT2ALLUSERS_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class ConsulterPlanningEquipement2AllUsers;
}
class ConsulterPlanningEquipement2AllUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterPlanningEquipement2AllUsers(BDD *b,QString salle, QString batiment, QWidget *parent = 0);
    ~ConsulterPlanningEquipement2AllUsers();

private slots:
    void on_calendar_clicked(const QDate &date);

private:
    BDD *b;
    QString batiment;
    QString salle;
    Ui::ConsulterPlanningEquipement2AllUsers *ui;
};

#endif // ConsulterPlanningSalle2AllUsers_H
