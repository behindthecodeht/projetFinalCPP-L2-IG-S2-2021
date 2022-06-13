#include "affectation.h"
#include "config/db.h"

Affectation::Affectation(int ide, int ids)
{
    this->id_emp = ide;
    this->id_ser = ids;
}

// Functions
bool Affectation::creer()
{
    QString sql = "INSERT INTO affectation(id_employe, id_projet) "
                  "VALUES('" + QString::number(this->getIdE()) + "', '" + QString::number(this->getIdS()) + "')";
    QSqlQuery r = DB::REQUEST(sql);
    if(r.numRowsAffected() != -1)
        return true;
    else
        return false;
}

//QSqlQuery Affectation::fetchAll(){
//    QString sql = "SELECT * FROM fonction";
//    return DB::REQUEST(sql);
//}
