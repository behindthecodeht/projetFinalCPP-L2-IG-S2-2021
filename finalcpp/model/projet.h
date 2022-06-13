#ifndef PROJET_H
#define PROJET_H


#include "config/utility.h"
#include "config/db.h"
#include <QString>


class Projet
{
    int id;
    QString nom;
    int duree;
    double cout;
    QString etat;

public:
    // Constructors
    Projet();
    Projet(QString nom, int duree, double cout, QString etat);
    Projet(int id, QString nom, int duree, double cout, QString etat);

    // Getters
    int getId(){ return this->id; }
    QString getNom(){ return this->nom; }
    int getDuree(){ return this->duree; }
    double getCout(){ return this->cout; }
    QString getEtat(){ return this->etat; }

    // Setters
    void setDuree(int val){ this->duree = val; }
    void setCout(int val){ this->cout = val; }

    // Functions
    bool creer();
    bool modifier();
    bool supprimer();
    static QSqlQueryModel* fetchModel(QSqlQueryModel *model);
    static QSqlQuery fetchAll();
};

#endif // PROJET_H
