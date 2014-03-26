#ifndef BDD_H
#define BDD_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

class BDD
{
Q_OBJECT
public:
    explicit BDD(QString driver,QString nomDB, QString login, QString mdp);
    ~BDD();
};

#endif // BDD_H
