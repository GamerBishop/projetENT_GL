#include "BDD.h"



BDD::BDD(QString nomDB, QString login, QString mdp)
    {
        db = QSqlDatabase::addDatabase("QPSQL");
        db.setDatabaseName(nomDB); 
        db.setUserName(login);
        db.setPassword(mdp);
        if(!db.open())
          {
              QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
          }
    }

BDD::QVector<QString> request(QString requete)
{
    QVector<QString> result=new QVector<QString>();
    QSqlQuery requeteur;
    requeteur.exec(requete);
    while(requeteur.next())
       {result.append(requesteur.v);

           QMessageBox::information(
               0,
               QObject::tr("Information récupérée"),
               "Id : " + QString::number(id_rubrique) + "\nLibellé : " + libelle_rubrique
               );
       }


}


