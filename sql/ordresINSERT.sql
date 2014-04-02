--En premier, on créé les types

--Ordres Insert des EtatEquipement
INSERT INTO etatequipement(
            id, libelle)
    VALUES (0, 'Libre');

INSERT INTO etatequipement(
            id, libelle)
    VALUES (1, 'Utilisé');

INSERT INTO etatequipement(
            id, libelle)
    VALUES (2, 'En maintenance');

INSERT INTO etatequipement(
            id, libelle)
    VALUES (3, 'Irréparable');
		
		
--Ordres Insert des Type-Cours
INSERT INTO typecours(
            id, libelle)
    VALUES (0, 'CM');
	
	INSERT INTO typecours(
            id, libelle)
    VALUES (1, 'TD');
	
	INSERT INTO typecours(
            id, libelle)
    VALUES (2, 'TP');
	
	INSERT INTO typecours(
            id, libelle)
    VALUES (3, 'Conférence');

--Ordres Insert des TypeEquipements
INSERT INTO typeequipement(
            id, libelle)
    VALUES (0, 'VidéoProjecteur');
	
	INSERT INTO typeequipement(
            id, libelle)
    VALUES (1, 'RétroProjecteur');
	
	INSERT INTO typeequipement(
            id, libelle)
    VALUES (2, 'Ordinateur');
	
	INSERT INTO typeequipement(
            id, libelle)
    VALUES (3, 'Tableau Electronique Portable');

--Ordres Insert des TypeGroupe	
INSERT INTO typegroupe(
            id, libelle)
    VALUES (0, 'TD');
	
INSERT INTO typegroupe(
            id, libelle)
    VALUES (1, 'TP');

INSERT INTO typegroupe(
            id, libelle)
    VALUES (2, 'Demi Promo');

INSERT INTO typegroupe(
            id, libelle)
    VALUES (3, 'Promotion Complète');	

--Ordres Insert des TypeSalle
INSERT INTO typesalle(
            id, libelle)
    VALUES (0, 'Salle TP');
	
INSERT INTO typesalle(
            id, libelle)
    VALUES (1,'Salle TD/CM');

INSERT INTO typesalle(
            id, libelle)
    VALUES (2, 'Amphi');

INSERT INTO typesalle(
            id, libelle)
    VALUES (3,'Labo');



--Ordres Insert des Promotion
INSERT INTO promotion(
            id, nom)
    VALUES (0, 'Informatique');
INSERT INTO promotion(
            id, nom)
    VALUES (1, 'Bordel');
	


--Ordres Insert des Equipements
INSERT INTO equipement(
            id, libelle, typeequipement, commentaire, etat, commentaireetat)
    VALUES (0, 'Vidéo Projecteur Toshiba', 0,'Attention à la keystone', 0 , null);

INSERT INTO equipement(
            id, libelle, typeequipement, commentaire, etat, commentaireetat)
    VALUES (1, 'PCPortableHP', 2,'WindowsXP/Linux', 0 , null);
INSERT INTO equipement(
            id, libelle, typeequipement, commentaire, etat, commentaireetat)
    VALUES (2, 'PC Portable Asus', 2,'MacOS/Windows7', 2 , 'Dualboot ne fonctionne plus');
	
INSERT INTO equipement(
            id, libelle, typeequipement, commentaire, etat, commentaireetat)
    VALUES (3, 'RétroProjecteur', 1,null, 0 , null);	

	--Ordres Insert des Groupes
INSERT INTO groupe(
            id, nom, capacite, typegroupe, promotionid)
    VALUES (0, 'TPGL1', 1, 1, 0);

INSERT INTO groupe(
            id, nom, capacite, typegroupe, promotionid)
    VALUES (1, 'TPGL2', 1, 1, 0);
	
	INSERT INTO groupe(
            id, nom, capacite, typegroupe, promotionid)
    VALUES (2, 'TDGL', 2, 1, 0);
	INSERT INTO groupe(
            id, nom, capacite, typegroupe, promotionid)
    VALUES (3, 'PromoComplete', 1, 3, 1);

	--Ordres Insert des Personne
INSERT INTO personne(
            id, nom, prenom, professeur, promotionid, su, login, mdp)
    VALUES (0, 'Caballol', 'Julien', false, 0, true, 'JulienC', 'GL1');
INSERT INTO personne(
            id, nom, prenom, professeur, promotionid, su, login, mdp)
    VALUES (1, 'Alias', 'Thomas', false, 0, false, 'toto', 'toto');
INSERT INTO personne(
            id, nom, prenom, professeur, promotionid, su, login, mdp)
    VALUES (2, 'Leveque', 'Hugo', false, 1, false, 'HugoL', 'mdp00');
INSERT INTO personne(
            id, nom, prenom, professeur, promotionid, su, login, mdp)
    VALUES (3, 'Guillou', 'Hugo', true, 0, false, 'HugoG', 'ENT');
INSERT INTO personne(
            id, nom, prenom, professeur, promotionid, su, login, mdp)
    VALUES (4, 'Eboueya', 'Mike', true, null, false, 'EboueyaM', 'Mike');	

--Ordres Insert des Groupe-Personne
INSERT INTO groupe_personne(
            groupeid, personneid)
    VALUES (0, 1);

INSERT INTO groupe_personne(
            groupeid, personneid)
    VALUES (1, 0);
	
INSERT INTO groupe_personne(
            groupeid, personneid)
    VALUES (2, 1);
	INSERT INTO groupe_personne(
            groupeid, personneid)
    VALUES (2, 0);
	INSERT INTO groupe_personne(
            groupeid, personneid)
    VALUES (3, 2);


--Ordres Insert des Salle
INSERT INTO salle(
            id, batiment, numsalle, capacite, typesalle)
    VALUES (0, 'Pascal', 'P136' , 25, 0);
INSERT INTO salle(
            id, batiment, numsalle, capacite, typesalle)
    VALUES (1, 'Orbigny', 'I300' , 200, 2);
INSERT INTO salle(
            id, batiment, numsalle, capacite, typesalle)
    VALUES (2, 'MSI', 'MSI216' , 30, 1);

INSERT INTO salle(
            id, batiment, numsalle, capacite, typesalle)
    VALUES (3, 'Orbigny', 'B14' , 20, 3);

	
--Ordres Insert des Modules
INSERT INTO module(
            id, nom, semestre, domaine)
    VALUES (0, 'Matières Générales', 'Semestre 5', 'InfoL3');
INSERT INTO module(
            id, nom, semestre, domaine)
    VALUES (1, 'Génie Logiciel', 'Semestre 6', 'InfoL3');
	
	
--Ordres Insert des UniteEnseignement
	INSERT INTO uniteenseignement(
            id, nom, moduleid)
    VALUES (0, 'Mathématiques pour Ingénieur', 0);

	INSERT INTO uniteenseignement(
            id, nom, moduleid)
    VALUES (1, 'Anglais', 0);

	INSERT INTO uniteenseignement(
            id, nom, moduleid)
    VALUES (2, 'Génie Logiciel', 1);		
	
	
	
	
--Ordres Insert des Cours
INSERT INTO cours(
            id, date, heuredebut, duree, salleid, typecoursid)
    VALUES (0, '17/04/2014', '09:35:00', '0 01:30:00', 0, 2);

	INSERT INTO cours(
            id, date, heuredebut, duree, salleid, typecoursid)
    VALUES (1, '19/04/2014', '09:35:00', '0 01:30:00', 0, 2);
	
INSERT INTO cours(
            id, date, heuredebut, duree, salleid, typecoursid)
    VALUES (2, '17/04/2014', '11:10:00', '0 01:30:00', 2, 1);

INSERT INTO cours(
            id, date, heuredebut, duree, salleid, typecoursid)
    VALUES (3, '18/04/2014', '09:35:00', '0 03:00:00', 2, 0);

	
--Ordres Insert des ReservationEquipement
INSERT INTO reservationequipement(
            id, Date, heure, duree, equipementid, personneid)
    VALUES (0, '17/04/2014', '09:35:00', '0 01:30:00', 0, 4);

INSERT INTO reservationequipement(
            id, Date, heure, duree, equipementid, personneid)
    VALUES (1, '18/04/2014', '09:35:00', '0 03:00:00', 0, 3);
		

	--Ordres Insert des Cours-Groupes
INSERT INTO cours_groupe(
            coursid, groupeid)
    VALUES (0, 0);

	INSERT INTO cours_groupe(
            coursid, groupeid)
    VALUES (1, 1);

INSERT INTO cours_groupe(
            coursid, groupeid)
    VALUES (2, 2);

INSERT INTO cours_groupe(
            coursid, groupeid)
    VALUES (3, 3);	
	
--Ordres Insert des Prof-Cours
INSERT INTO prof_cours(
            coursid, personneid)
    VALUES (3, 3);
	
	INSERT INTO prof_cours(
            coursid, personneid)
    VALUES (2,3 );

	INSERT INTO prof_cours(
            coursid, personneid)
    VALUES (1, 4);
	
	INSERT INTO prof_cours(
            coursid, personneid)
    VALUES (0, 4);
	
--Ordres Insert des Prof_UE
INSERT INTO prof_uniteenseignement(
            personneid, uniteenseignementid)
    VALUES (3, 0);
	
INSERT INTO prof_uniteenseignement(
            personneid, uniteenseignementid)
    VALUES (3, 1);
	
INSERT INTO prof_uniteenseignement(
            personneid, uniteenseignementid)
    VALUES (4, 2);

	INSERT INTO prof_uniteenseignement(
            personneid, uniteenseignementid)
    VALUES (3, 2);


--Ordres Insert des UniteEnseignement-Cours
INSERT INTO uniteenseignement_cours(
            uniteenseignementid, coursid)
    VALUES (2, 0);
	
INSERT INTO uniteenseignement_cours(
            uniteenseignementid, coursid)
    VALUES (2,1 );
	
INSERT INTO uniteenseignement_cours(
            uniteenseignementid, coursid)
    VALUES (2, 2);
	
	INSERT INTO uniteenseignement_cours(
            uniteenseignementid, coursid)
    VALUES (0, 3);
	

	
