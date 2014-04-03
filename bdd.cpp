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

BDD::BDD()
    {

    }




bool BDD::Connexion(QString login, QString password)
{
    this->login=login;
    QSqlQuery requeteur;
    requeteur.prepare("Select login, password "
                      "from Personne "
                      "where login=:login AND mdp=:password");
    requeteur.bindValue(":login",login);
    requeteur.bindValue(":password",password);
    requeteur.exec();
    if(requeteur.size()==0)
        return false;
    return true;
}

bool BDD::isProf()
{
    QSqlQuery requeteur;
    requeteur.prepare("Select professeur "
                      "from Personne "
                      "where login=:login");
    requeteur.bindValue(":login",this->login);
    requeteur.exec();
    requeteur.next();
    return requeteur.value(0).toBool();
}

QList<QString> BDD::selectTypeSalle(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select libelle from typesalle ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectTypeCours(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select libelle from typecours ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectTypeEquipement(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select libelle from typeequipement ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectUE(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select nom from uniteenseignement ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QList<QString> > BDD::selectSalle(){
    QSqlQuery requeteur;
    QList<QString> tmpList;
    QList<QList<QString> > result;
    requeteur.prepare("Select batiment, numsalle from Salle ");
    requeteur.exec();
    while(requeteur.next()){
        tmpList.clear();
        tmpList.append(requeteur.value(0).toString());
        tmpList.append(requeteur.value(1).toString());
        result.append(tmpList);
    }
    return result;
}

QList<QString> BDD::selectEquipement(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select nom from Equipement ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectPromotion(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select nom from promotion ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectGroupe(QString nompromo){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select nom from groupe join groupe.promotionid = promotion.id where "
                      "promotion.nom=:nompromo");
    requeteur.bindValue(":nompromo",nompromo);
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}

QList<QString> BDD::selectProfesseur(){
    QSqlQuery requeteur;
    QList<QString> result;
    requeteur.prepare("Select CONCAT(nom,' ',prenom) from personne where professeur=true ");
    requeteur.exec();
    while(requeteur.next()){
        result.append(requeteur.value(0).toString());
    }
    return result;
}


QList<QList<QString> > BDD::selectEquipementDispo(QString typeequipement,QString date,QString hdebut,QString duree){
    QList<QList<QString> > result;
    QList<QString> tmpList;
    QSqlQuery requeteur;

    requeteur.prepare("Select numequipement, libelle "
                      "from equipement equ,typeequipement te "
                      "where typeequipement = te.id "
                      "And te.libelle= :typeequipement "
                      "And equipement.id Not in (Select equipementid "
                      "from reservationequipement "
                      "where date= :date "
                      "and :hdebut between :hdebut and :hdebut+:duree "
                      "or :hdebut+:duree between :hdebut and :hdebut+:duree);");
    requeteur.bindValue(":typeequipement",typeequipement);
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":hdebut",hdebut);
    requeteur.bindValue(":duree",duree);
    requeteur.exec();

    while(requeteur.next())
    {
            tmpList.clear();
            tmpList.append(requeteur.value(0).toString());
            tmpList.append(requeteur.value(1).toString());
            result.append(tmpList);
    }
    return result;
}
void BDD::creerReservationSalle(QString date, QString hdebut, QString duree, QString salleid, QString typecours, QString profNom, QString profPrenom, QString ue, QString groupeid){

    QSqlQuery requeteur;
    requeteur.prepare("INSERT INTO cours( "
                      "id, date, heuredebut, duree, salleid, typecoursid) "
                      "Select Max(c.id)+1,:date, :hdebut,:duree, :salleid, tc.id "
                      "from cours c, typecours tc "
                      "where tc.libelle = :typecours; "
                      "Insert into uniteenseignement_cours (uniteenseignementid,coursid) "
                      "Select ue.id, max(cours.id) "
                      "From uniteenseignement ue, cours "
                      "Where ue.nom=:ue; "
                      "Insert into prof_cours(coursid, personneid) "
                      "Select prof.id, max(cours.id) "
                      "From personne prof, cours "
                      "Where prof.nom=:profNom "
                      "And prof.prenom = :profPrenom "
                      "And prof.professeur = true; "
                      "Insert into cours_groupe (coursid, groupeid) "
                      "Select max(cours.id),gr.id "
                      "from cours, groupe gr "
                      "Where gr.nom = :groupeid;");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":hdebut",hdebut);
    requeteur.bindValue(":duree",duree);
    requeteur.bindValue(":salleid",salleid);
    requeteur.bindValue(":typecours",typecours);
    requeteur.bindValue(":ue",ue);
    requeteur.bindValue(":profNom",profNom);
    requeteur.bindValue(":profPrenom",profPrenom);
    requeteur.bindValue(":groupeid",groupeid);
    requeteur.exec();
}

QList<QList<QString> > BDD::selectSalleVide(QString date,QString typesalle,QString promotion,QString groupe,QString hdebut,QString duree){
    QList<QList<QString> > result;
     QList<QString> tmpList;
    QSqlQuery requeteur;

    requeteur.prepare("Select salle.id, numsalle, batiment from salle, typesalle ts, cours "
                      "where salle.typesalle = ts.id And ts.libelle= :typesalle "
                      "And salle.id Not in (Select salleid from cours where "
                      "date= :date and :hdebut between :hdebut "
                      "and :hdebut+:duree or :hdebut+:duree "
                      "between :hdebut and :hdebut+:duree) and "
                      "salle.capacite<=(select capacite from groupe g join "
                      "promotion p on p.id=g.promotionid where "
                      "p.nom = :promotion and g.nom=:groupe);");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":typesalle",typesalle);
    requeteur.bindValue(":promotion",promotion);
    requeteur.bindValue(":groupe",groupe);
    requeteur.bindValue(":hdebut",hdebut);
    requeteur.bindValue(":duree",duree);
    requeteur.exec();

    while(requeteur.next())
    {
        tmpList.clear();
        tmpList.append(requeteur.value(0).toString());
        tmpList.append(requeteur.value(1).toString());
        tmpList.append(requeteur.value(2).toString());
        tmpList.append(requeteur.value(3).toString());
        tmpList.append(requeteur.value(4).toString());
        result.append(tmpList);
    }
    return result;
}

QList<QList<QString>> BDD::SelectAllReservationsProf()
{
    QSqlQuery requeteur;
    QList<QList<QString>> result;
    QList<QString> tmpList;
    requeteur.prepare("SELECT tc.libelle, "
                              "ue.nom, "
                              "gr.nom, "
                              "salle.numsalle, "
                              "salle.batiment, "
                              "date, "
                              "heuredebut, "
                              "duree+heuredebut as heurefin "
                      "FROM cours, "
                              "personne, "
                              "prof_cours, "
                              "salle, "
                              "uniteenseignement_cours uecours, "
                              "uniteenseignement ue, "
                              "typecours tc, "
                              "groupe gr, "
                              "cours_groupe cgr "
                      "Where personne.login = 'EboueyaM' and "
                              "personne.id = prof_cours.personneid and "
                              "cours.id = prof_cours.coursid and "
                              "cours.id = uecours.coursid and "
                              "ue.id = uecours.uniteenseignementid and "
                              "cours.salleid = salle.id and  "
                              "tc.id = cours.typecoursid and "
                              "cours.id = cgr.coursid and "
                              "gr.id=cgr.groupeid;");
    while(requeteur.next())
        {
            tmpList.clear();
            tmpList.append(requeteur.value(0).toString());
            tmpList.append(requeteur.value(1).toString());
            tmpList.append(requeteur.value(2).toString());
            tmpList.append(requeteur.value(3).toString());
            tmpList.append(requeteur.value(4).toString());
            tmpList.append(requeteur.value(5).toString());
            tmpList.append(requeteur.value(6).toString());
            tmpList.append(requeteur.value(7).toString());
            result.append(tmpList);
        }
    return result;
}

bool BDD::DeleteReservationParDateEtEquipement(QString nomEquipement, QString date)
{
    QSqlQuery requeteur;
    requeteur.prepare("DELETE FROM cours "
                      "Where Date =:date "
                      "And equ.libelle=:nomEquipement;");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":nomEquipement",nomEquipement);
    requeteur.exec();
    if(requeteur.size()==0)
        return false;
    return true;
}

QString BDD::SelectReservationsParDateEtEquipement(QString nomEquipement, QString date)
{
    QList<QList<QString> > result;
     QList<QString> tmpList;
    QSqlQuery requeteur;
    requeteur.prepare("SELECT distinct resa.date, resa.heure, rasa.heure+resa.duree, pers.nom, pers.prenom "
                      "FROM reservationequipement resa,equipement equ, personne pers "
                      "Where equ.id=resa.equipementid "
                      "And pers.id=resa.personneid "
                      "And equ.libelle=:nomEquipement "
                      "And resa.date=:date");
    requeteur.bindValue(":nomEquipement",nomEquipement);
    requeteur.bindValue(":date",date);
    while(requeteur.next())
        {
            tmpList.clear();
            tmpList.append(requeteur.value(0).toString());
            tmpList.append(requeteur.value(1).toString());
            tmpList.append(requeteur.value(2).toString());
            tmpList.append(requeteur.value(3).toString());
            tmpList.append(requeteur.value(4).toString());
            result.append(tmpList);
    }            

    QString aEnvoyer="";
    for(QList<QString> vs : result)
    {

        aEnvoyer=aEnvoyer+vs.at(0)+" - "+vs.at(1)+"\n"+vs.at(2) +" : "+vs.at(3)+ " | " +vs.at(4)+"\n \n";
    }
    return aEnvoyer;
}

bool BDD::DeleteReservationParDateEtSalle(QString batiment,QString numsalle, QString date)
{
    QSqlQuery requeteur;
    requeteur.prepare("DELETE FROM cours "
                      "Where Date =:date "
                      "And salleid= (Select from salle where numsalle = :numsalle and batiment = :batiment);");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":salle",numsalle);
    requeteur.bindValue(":batiment",batiment);
    requeteur.exec();
    if(requeteur.size()==0)
        return false;
    return true;
}

QString BDD::SelectReservationsParDateEtSalle(QString batiment,QString numsalle, QString date)
{
    QList<QList<QString> > result;
     QList<QString> tmpList;
    QList<QString> idCours;
    QSqlQuery requeteur;

    requeteur.prepare("Select c.heuredebut, c.heuredebut+c.duree as HeureFin, t.libelle, c.id "
                      "from cours c,typecours t, salle s "
                      "Where t.id=c.typecoursid "
                      "And s.batiment = :batiment "
                      "And s.numsalle = :numsalle "
                      "And c.salleid=s.id "
                      "AND date = :date "
                      "ORDER BY c.heuredebut");
    requeteur.bindValue(":batiment",batiment);
    requeteur.bindValue(":numsalle",numsalle);
    requeteur.bindValue(":date",date);
    requeteur.exec();


    while(requeteur.next())
        {
            tmpList.clear();
            tmpList.append(requeteur.value(0).toString());
            tmpList.append(requeteur.value(1).toString());
            tmpList.append(requeteur.value(2).toString());
            result.append(tmpList);
            idCours.append(requeteur.value(3).toString());
        }

        for (int i=0;i<idCours.length();i++)
        {
            requeteur.clear();
            requeteur.prepare("Select nom from groupe g join cours_groupe c on g.id = c.groupeid Where c.coursid=:id");
            requeteur.bindValue(":id",idCours.at(i));
            requeteur.exec();
            while(requeteur.next())
                {
                   if(result.at(i).length()<4)
                        {
                        result[i].append(requeteur.value(0).toString());

                        }
                    else
                    {
                        result[i].last().append(" - "+requeteur.value(0).toString());
                    }
                }
            requeteur.clear();
            requeteur.prepare("Select nom, prenom from personne p join prof_cours pc on p.id=pc.personneid where coursid=:id");
            requeteur.bindValue(":id",idCours[i]);
            requeteur.exec();
            while(requeteur.next())
                {
                if(result[i].length()<5)
                    result[i].append(requeteur.value(0).toString() + " " + requeteur.value(1).toString());
                else
                    result[i].last().append(" - "+requeteur.value(0).toString() + " " + requeteur.value(1).toString());


                }

        }
    //result[i][0] = heure de debut
    //result[i][1] = heure de fin
    //result[i][2] = nom du cours
    //result[i][3] = nom DES groupes
    //result[i][5] = nom DES profs

    QString aEnvoyer="";
    for(QList<QString> vs : result)
    {

        aEnvoyer=aEnvoyer+vs.at(0)+" - "+vs.at(1)+"\n"+vs.at(2) +" : "+vs.at(3)+ " | " +vs.at(4)+"\n \n";
    }
    return aEnvoyer;
}

void BDD::creerReservationEquipement(QString date, QString hdebut,QString duree,QString nomequipement,QString nomprof,QString prenomprof){
    QSqlQuery requeteur;
    requeteur.prepare("INSERT INTO reservationequipement( "
                      "id, date, heure, duree, equipementid, personneid) "
                      "Select Max(resa.id)+1, :date,:hdebut,:duree,equ.id,prof.id "
                      "From reservationequipement resa, equipement equ, personne prof "
                      "Where equ.libelle = :nomequipement "
                      "And prof.nom=:nomprof "
                      "And prof.prenom =:prenomprof;");
    requeteur.bindValue(":date",date);
    requeteur.bindValue(":hdebut",hdebut);
    requeteur.bindValue(":duree",duree);
    requeteur.bindValue(":nomequipement",nomequipement);
    requeteur.bindValue(":nomprof",nomprof);
    requeteur.bindValue(":prenomprof",prenomprof);

    requeteur.exec();
}






