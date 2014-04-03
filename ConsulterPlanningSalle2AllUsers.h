#ifndef CONSULTERPLANINGSALLE2ALLUSERS_H
#define CONSULTERPLANINGSALLE2ALLUSERS_H

#include <QMainWindow>
#include "BDD.h"

namespace Ui {
class ConsulterPlanningSalle2AllUsers;
}
class ConsulterPlanningSalle2AllUsers : public QMainWindow
{
    Q_OBJECT

public:
    explicit ConsulterPlanningSalle2AllUsers(BDD *b,QString salle, QString batiment, QWidget *parent = 0);
    ~ConsulterPlanningSalle2AllUsers();

private slots:
    void on_calendar_clicked(const QDate &date);

private:
    BDD *b;
    QString batiment;
    QString salle;
    Ui::ConsulterPlanningSalle2AllUsers *ui;
};

#endif // ConsulterPlanningSalle2AllUsers_H
