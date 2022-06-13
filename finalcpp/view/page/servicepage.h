#ifndef SERVICEPAGE_H
#define SERVICEPAGE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QStackedLayout>
#include <QGroupBox>
#include <QSizePolicy>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include "component/modulebutton.h"
#include "model/service.h"
#include "model/adresse.h"


class ServicePage : public QWidget
{
    Q_OBJECT

public:
    explicit ServicePage(QWidget *parent = nullptr);
    void clearForm();

public slots:
    void switchToList();
    void switchToAdd();
    void saveService();

signals:

private:
    QGridLayout *mainLayout;
    QVBoxLayout *menuLayout;
    QStackedLayout *contentLayout;

    QGroupBox *menuGroup;
    QGroupBox *contentGroup;

    // Menu Button
    ModuleButton *btnList;
    ModuleButton *btnAdd;

    // Content Layouts
    QVBoxLayout *addServiceLayout;
    QVBoxLayout *listServiceLayout;

    QWidget *addService;
    QWidget *listService;

    // List Service Elements
    QLabel *listServiceTitle;
    QTableView *listServiceTable;
    QSqlQueryModel *listServiceTableModel;

    // Add Service Elements
    QLabel *addServiceTitle;
    QLabel *etat;
    QLabel *libele;
    QLabel *adresse;
    QLineEdit *libeleEdit;
    QComboBox *etatEdit;
    QComboBox *adresseEdit;
    QPushButton *btnSave;

};

#endif // SERVICEPAGE_H
