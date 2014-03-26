#ifndef BDD_H
#define BDD_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QArray>

class BDD
{
Q_OBJECT
public:
    explicit BDD(QString nomDB, QString login, QString mdp);
    ~BDD();
    QSqlDatabase db;
    QVector<QString> request(QString requete);

};

#endif // BDD_H
