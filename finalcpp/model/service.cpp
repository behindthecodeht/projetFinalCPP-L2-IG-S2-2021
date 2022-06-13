#include "service.h"

// Constructors
Service::Service(QString libele, QString etat, QString addId){
    this->libele = libele;
    this->etat = etat;
    this->idAdresse = addId;
}

Service::Service(QString id, QString libele, QString etat, QString addId){
    this->id = id;
    this->libele = libele;
    this->etat = etat;
    this->idAdresse = addId;
}

// Functions
bool Service::creer()
{
    QString sql = "INSERT INTO service(libelle, etat, id_adresse) "
                  "VALUES('" + this->getLibele() + "', '" + this->getEtat() + "', '" + this->getIdAdresse() + "')";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Service::modifier()
{
    QString sql = "UPDATE service SET libelle='" + this->getLibele() + "', etat='"
            + this->getEtat() + "', id_adresse='" + this->getIdAdresse()
            +"' WHERE id='" + this->getId() +"'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Service::supprimer()
{
    QString sql = "DELETE FROM service WHERE id='" + this->getId() + "'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


QSqlQueryModel* Service::fetchModel(QSqlQueryModel *model){
    QString sql = "SELECT * FROM service INNER JOIN adresse WHERE adresse.id=id_adresse";
    return DB::FETCHMODEL(model, sql);
}

QSqlQuery Service::fetchAll(){
    QString sql = "SELECT * FROM service";
    return DB::REQUEST(sql);
}
