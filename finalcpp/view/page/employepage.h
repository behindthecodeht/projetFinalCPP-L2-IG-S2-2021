#ifndef EMPLOYEPAGE_H
#define EMPLOYEPAGE_H

#include <QObject>
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
#include <QDialog>
#include <QMessageBox>
#include <QTableView>
#include "component/modulebutton.h"
#include "model/fonction.h"
#include "model/service.h"
#include "model/employe.h"
#include "model/affectation.h"
#include "model/projet.h"


class EmployePage : public QWidget
{
    Q_OBJECT
public:
    explicit EmployePage(QWidget *parent = nullptr);
    void clearForm();

public slots:
    void switchToList();
    void switchToAdd();
    void switchToAff();
    void switchToView();
    void saveFonction();
    void saveEmploye();
    void saveAffect();
    void search();

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
    ModuleButton *btnAffect;
    ModuleButton *btnView;

    // Content Layouts
    QGridLayout *addEmployeLayout;
    QVBoxLayout *listEmployeLayout;
    QVBoxLayout *affectEmployeLayout;
    QVBoxLayout *viewEmployeLayout;

    QWidget *addEmploye;
    QWidget *listEmploye;
    QWidget *affectEmploye;
    QWidget *viewEmploye;

    // List Employe Elements
    QLabel *listEmployeTitle;
    QTableView *listEmployeTable;
    QSqlQueryModel *listEmployeTableModel;

    // Add Employe Elements
    QLabel *addEmployeTitle;
    QLabel *nom;
    QLabel *prenom;
    QLabel *fonction;
    QLabel *mail;
    QLabel *telephone;
    QLabel *service;
    QLabel *salaire;
    QLineEdit *nomEdit;
    QLineEdit *prenomEdit;
    QLineEdit *mailEdit;
    QLineEdit *telephoneEdit;
    QLineEdit *salaireEdit;
    QComboBox *serviceEdit;
    QComboBox *fonctionEdit;
    QPushButton *btnSave;
    QPushButton *btnShowAddFunction;

    // Function Dialog
    QDialog *addFonction;
    QVBoxLayout *addFunctionLayout;
    QLabel *libelefonction;
    QLineEdit *libelefonctionEdit;
    QPushButton *btnSaveFunction;

    // Add Employe Elements
    QLabel *affectEmployeTitle;
    QLabel *eName;
    QLabel *sName;
    QComboBox *eEdit;
    QComboBox *sEdit;
    QPushButton *btnSaveAffect;

    // View Employe Projet
    QLabel *nEmp;
    QComboBox *combo;
    QPushButton *btnSearch;
    QTableView *table;
    QSqlQueryModel *tableModel;

};

#endif // EMPLOYEPAGE_H
