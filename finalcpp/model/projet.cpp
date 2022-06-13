#include "projet.h"


// Constructors
Projet::Projet(){}

Projet::Projet(QString nom, int duree, double cout, QString etat){
    this->nom = nom;
    this->duree = duree;
    this->cout = cout;
    this->etat = etat;
}

Projet::Projet(int id, QString nom, int duree, double cout, QString etat){
    this->id = id;
    this->nom = nom;
    this->duree = duree;
    this->cout = cout;
    this->etat = etat;
}


// Functions
bool Projet::creer()
{
    QString sql = "INSERT INTO projet(nom, duree, cout_estime, etat_actuel) "
                  "VALUES('" + this->getNom() + "', '" + QString::number(this->getDuree()) + "', '"
                  + QString::number(this->getCout()) + "', '" + this->getEtat() + "')";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Projet::modifier()
{
    QString sql = "UPDATE projet SET nom='" + this->getNom() + "', duree='" + QString::number(this->getDuree())
            + "', cout_estime='" + QString::number(this->getCout()) + "', etat_actuel='" + this->getEtat()
            +"' WHERE id='" + QString::number(this->getId()) +"'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


bool Projet::supprimer()
{
    QString sql = "DELETE FROM projet WHERE id='" + QString::number(this->getId()) + "'";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}


QSqlQueryModel* Projet::fetchModel(QSqlQueryModel *model){
    QString sql = "SELECT * FROM projet";
    return DB::FETCHMODEL(model, sql);
}

QSqlQuery Projet::fetchAll(){
    QString sql = "SELECT * FROM projet";
    return DB::REQUEST(sql);
}
