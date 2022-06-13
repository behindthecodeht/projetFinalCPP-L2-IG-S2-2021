#include "employe.h"

// Constructors
Employe::Employe(QString nom, QString prenom, QString mail, QString telephone,
        double salaire, int fonction, int service)
{
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->salaire = salaire;
    this->fonction = fonction;
    this->service = service;
}

Employe::Employe(int id, QString nom, QString prenom, QString mail, QString telephone,
                 double salaire, int fonction, int service)
{
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->telephone = telephone;
    this->salaire = salaire;
    this->fonction = fonction;
    this->service = service;
}

// Functions
bool Employe::creer()
{
    QString sql = "INSERT INTO employe(id_fonction, id_service, nom, prenom, mail, telephone, salaire) "
                  "VALUES ('" + QString::number(this->getFonctionId()) + "', '" + QString::number(this->getServiceId()) + "', '"
                  + this->getNom() + "', '" + this->getPrenom() +"', '" + this->getMail() +"', '"
                  + this->getTelephone() +"', '" + QString::number(this->getSalaire()) + "')";
    qDebug() << sql;
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Employe::supprimer()
{
    QString sql = "DELETE FROM employe WHERE id='" + QString::number(this->getId()) + "'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}

QSqlQueryModel* Employe::fetchModel(QSqlQueryModel *model){
    QString sql = "SELECT * FROM employe "
                  "INNER JOIN fonction ON fonction.id=id_fonction "
                  "INNER JOIN service ON service.id=id_service";
    return DB::FETCHMODEL(model, sql);
}

QSqlQueryModel* Employe::fetchProjetByAffectModel(QSqlQueryModel *model, int id){
    QString sql = "SELECT * FROM projet "
                  "INNER JOIN affectation ON projet.id=affectation.id_projet "
                  "WHERE affectation.id_employe ='" + QString::number(id) + "'";
    qDebug()  << sql;
    return DB::FETCHMODEL(model, sql);
}

QSqlQuery Employe::fetchAll(){
    QString sql = "SELECT * FROM employe";
    return DB::REQUEST(sql);
}
