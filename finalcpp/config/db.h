#ifndef DB_H
#define DB_H

#include "qdebug.h"
#include <QString>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>

class DB
{

private:
    QSqlDatabase db;

public:
    DB();
    ~DB();

    static QSqlQuery REQUEST(const QString & sql);
    static QSqlQueryModel* FETCHMODEL(QSqlQueryModel *model, const QString & sql);
};

#endif // DB_H
