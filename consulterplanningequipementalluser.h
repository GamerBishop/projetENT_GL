#ifndef CONSULTERPLANNINGEQUIPEMENTALLUSER_H
#define CONSULTERPLANNINGEQUIPEMENTALLUSER_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class ConsulterPlanningEquipementAllUser;
}

class ConsulterPlanningEquipementAllUser : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterPlanningEquipementAllUser(BDD *b, QString nomEquipement, QWidget *parent = 0);
    ~ConsulterPlanningEquipementAllUser();

private slots:
    void on_calendar_2_clicked(const QDate &date);

    void on_calendar_clicked(const QDate &date);

private:
    BDD *b;
    QString nomEquipement;
    Ui::ConsulterPlanningEquipementAllUser *ui;
};

#endif // CONSULTERPLANNINGEQUIPEMENTALLUSER_H
