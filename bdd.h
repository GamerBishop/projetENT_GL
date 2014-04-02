#ifndef BDD_H
#define BDD_H

#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QMessageBox>
#include <QVector>

class BDD:public QObject
{
Q_OBJECT
public:
    explicit BDD(QString host, QString nomDB, QString login, QString mdp);
    QSqlDatabase db;
    bool Connexion(QString login, QString password);
    QVector<QVector<QString> >SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date);

};

#endif // BDD_H
