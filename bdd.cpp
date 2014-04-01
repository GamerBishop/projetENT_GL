#include "BDD.h"



BDD::BDD(QString host, QString nomDB, QString login, QString mdp)
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setHostName(host);
        db.setDatabaseName(nomDB); 
        db.setUserName(login);
        db.setPassword(mdp);

        if(!db.open())
          {
              QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
              exit(1);
          }
    }

QVector<QString> BDD::request(QString requete)
{
    QVector<QString> result;
    QSqlQuery requeteur;
    requeteur.exec(requete);
    while(requeteur.next())
       {
        result.append(requeteur.value(1).toString());
       }
    return result;


}


