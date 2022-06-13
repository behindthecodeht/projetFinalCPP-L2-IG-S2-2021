#include "employepage.h"

EmployePage::EmployePage(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Employe");
    setFixedWidth(950);

    mainLayout = new QGridLayout();

    menuGroup = new QGroupBox();
    menuGroup->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    contentGroup = new QGroupBox();
    menuGroup->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    menuLayout = new QVBoxLayout(menuGroup);
    contentLayout = new QStackedLayout(contentGroup);

    // Menu Button
    btnList = new ModuleButton(":/asset/projet.jpg");
    connect(btnList, SIGNAL(clicked(bool)), SLOT(switchToList()));

    btnAdd = new ModuleButton(":/asset/person.png");
    connect(btnAdd, SIGNAL(clicked(bool)), SLOT(switchToAdd()));

    btnAffect = new ModuleButton(":/asset/im.png");
    connect(btnAffect, SIGNAL(clicked(bool)), SLOT(switchToAff()));

    btnView = new ModuleButton(":/asset/services.png");
    connect(btnView, SIGNAL(clicked(bool)), SLOT(switchToView()));

    // Content Layouts
    listEmployeLayout = new QVBoxLayout();
    addEmployeLayout = new QGridLayout();
    affectEmployeLayout = new QVBoxLayout();
    viewEmployeLayout = new QVBoxLayout();

    listEmploye = new QWidget();
    addEmploye = new QWidget();
    affectEmploye = new QWidget();
    viewEmploye = new QWidget();

    //?? END CONFIG SCREEN ??//

    // Set Widget to Layouts
    menuGroup->setLayout(menuLayout);
    menuLayout->addWidget(btnAdd);
    menuLayout->addWidget(btnList);
    menuLayout->addWidget(btnAffect);
    menuLayout->addWidget(btnView);

    contentGroup->setLayout(contentLayout);

    contentLayout->addWidget(addEmploye);
    contentLayout->addWidget(listEmploye);
    contentLayout->addWidget(affectEmploye);
    contentLayout->addWidget(viewEmploye);

    // Screen Layout Configuration
    setLayout(mainLayout);
    mainLayout->addWidget(menuGroup, 0, 0);
    mainLayout->addWidget(contentGroup, 0, 1);
    //?? END CONFIG SCREEN ??//

    // List Employe //
    listEmployeTitle = new QLabel("Liste Des Employes Disponible");

    listEmployeTitle = new QLabel("Liste Des Employes Disponible", this);
    listEmployeTable = new QTableView();
        listEmployeTable->setAutoFillBackground(true);
        listEmployeTable->setAutoScroll(true);
    listEmployeTableModel = new QSqlQueryModel();

    listEmployeLayout->addWidget(listEmployeTitle);
    listEmployeLayout->addWidget(listEmployeTable);

    listEmploye->setLayout(listEmployeLayout);
    // END List Employe //

    // Add Function Dialog
    addFonction = new QDialog();
    addFunctionLayout = new QVBoxLayout(addFonction);
    libelefonction = new QLabel("Nom de la Fonction", addFonction);
    libelefonctionEdit = new QLineEdit(addFonction);
    btnSaveFunction = new QPushButton("Ajouter la Fonction", addFonction);


    addFunctionLayout->addWidget(libelefonction);
    addFunctionLayout->addWidget(libelefonctionEdit);
    addFunctionLayout->addWidget(btnSaveFunction);
    addFonction->setLayout(addFunctionLayout);
    connect(btnSaveFunction, SIGNAL(clicked(bool)), this, SLOT(saveFonction()));


    // Add Employe //
    addEmployeTitle = new QLabel("Ajouter Un Nouveau Employe");

    nom = new QLabel("Nom");
    prenom = new QLabel("Prenom");
    mail = new QLabel("Mail");
    telephone = new QLabel("Telephone");
    salaire = new QLabel("Salaire");
    fonction = new QLabel("Fonction");
    service = new QLabel("Service");
    nomEdit = new QLineEdit();
    prenomEdit = new QLineEdit();
    mailEdit = new QLineEdit();
    telephoneEdit = new QLineEdit();
    salaireEdit = new QLineEdit();
    fonctionEdit = new QComboBox();
    QSqlQuery r = Fonction::fetchAll();
        fonctionEdit->addItem("--Choisir--");
        while(r.next()){
            QString f = r.value(1).toString() + " - ID:" + r.value(0).toString();
            fonctionEdit->addItem(f);
        }
    serviceEdit = new QComboBox();
    QSqlQuery s = Service::fetchAll();
        serviceEdit->addItem("--Choisir--");
        while(s.next()){
            QString se = s.value(2).toString() + " - ID:" + s.value(0).toString();
            serviceEdit->addItem(se);
        }

    btnShowAddFunction = new QPushButton("Nouveau");
    connect(btnShowAddFunction, SIGNAL(clicked(bool)), addFonction, SLOT(open()));

    btnSave = new QPushButton("Ajouter");
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveEmploye()));


    addEmployeLayout->addWidget(addEmployeTitle, 0, 0, 1, 4);
    addEmployeLayout->addWidget(nom, 1, 0, 1, 2);
    addEmployeLayout->addWidget(prenom, 1, 2, 1, 2);
    addEmployeLayout->addWidget(nomEdit, 2, 0, 1, 2);
    addEmployeLayout->addWidget(prenomEdit, 2, 2, 1, 2);
    addEmployeLayout->addWidget(mail, 3, 0, 1, 2);
    addEmployeLayout->addWidget(telephone, 3, 2, 1, 2);
    addEmployeLayout->addWidget(mailEdit, 4, 0, 1, 2);
    addEmployeLayout->addWidget(telephoneEdit, 4, 2, 1, 2);
    addEmployeLayout->addWidget(fonction, 5, 0, 1, 2);
    addEmployeLayout->addWidget(btnShowAddFunction, 6, 2, 1, 2);
    addEmployeLayout->addWidget(fonctionEdit, 6, 0, 1, 2);
    addEmployeLayout->addWidget(service, 7, 0, 1, 4);
    addEmployeLayout->addWidget(serviceEdit, 8, 0, 1, 4);
    addEmployeLayout->addWidget(salaire, 9, 0, 1, 4);
    addEmployeLayout->addWidget(salaireEdit, 10, 0, 1, 4);
    addEmployeLayout->addWidget(btnSave, 11, 0, 1, 4);

    addEmploye->setLayout(addEmployeLayout);
    // END AddEmploye //

    // Affect Employe //
    affectEmployeTitle = new QLabel("Affecter Un Nouveau Employé  a un service");

    eName = new QLabel("Nom de L'employeé");
    sName = new QLabel("Nom du Projet");
    eEdit = new QComboBox();
    QSqlQuery em = Employe::fetchAll();
        eEdit->addItem("--Choisir--");
        while(em.next()){
            QString f = em.value(3).toString() + " " + em.value(4).toString() +  " - ID:" + em.value(0).toString();
            eEdit->addItem(f);
        }
    sEdit = new QComboBox();
    QSqlQuery sv = Projet::fetchAll();
        sEdit->addItem("--Choisir--");
        while(sv.next()){
            QString se = sv.value(1).toString() + " - ID:" + sv.value(0).toString();
            sEdit->addItem(se);
        }

    btnSaveAffect = new QPushButton("Affecter");
    connect(btnSaveAffect, SIGNAL(clicked(bool)), this, SLOT(saveAffect()));

    affectEmployeLayout->addWidget(affectEmployeTitle);
    affectEmployeLayout->addWidget(eName);
    affectEmployeLayout->addWidget(eEdit);
    affectEmployeLayout->addWidget(sName);
    affectEmployeLayout->addWidget(sEdit);
    affectEmployeLayout->addWidget(btnSaveAffect);

    affectEmploye->setLayout(affectEmployeLayout);
    // END AffEmploye //

    // view Employe //
    nEmp = new QLabel("Nom de L'employé");

    combo = new QComboBox();
    QSqlQuery em2 = Employe::fetchAll();
        combo->addItem("--Choisir--");
        while(em2.next()){
            QString f = em2.value(3).toString() + " " + em2.value(4).toString() +  " - ID:" + em2.value(0).toString();
            combo->addItem(f);
        }

    table = new QTableView();
        table->setAutoFillBackground(true);
        table->setAutoScroll(true);
    tableModel = new QSqlQueryModel();

    btnSearch = new QPushButton("Affecter");
    connect(btnSearch, SIGNAL(clicked(bool)), this, SLOT(search()));

    viewEmployeLayout->addWidget(nEmp);
    viewEmployeLayout->addWidget(combo);
    viewEmployeLayout->addWidget(btnSearch);
    viewEmployeLayout->addWidget(table);

    viewEmploye->setLayout(viewEmployeLayout);
    // END AffEmploye //
}

void EmployePage::switchToList(){
    listEmployeTableModel = Employe::fetchModel(listEmployeTableModel);
    if(listEmployeTableModel){
        listEmployeTable->setModel(listEmployeTableModel);
        listEmployeTable->setColumnHidden(0, true);
        listEmployeTable->setColumnHidden(1, true);
        listEmployeTable->setColumnHidden(2, true);
        listEmployeTable->setColumnHidden(8, true);
        listEmployeTable->setColumnHidden(9, true);
        listEmployeTable->setColumnHidden(11, true);
        listEmployeTable->setColumnHidden(12, true);
        listEmployeTable->setColumnHidden(14, true);
    }else
        QMessageBox::information(this, "Information", "Aucune Donnee Disponible !!!");
    contentLayout->setCurrentIndex(1);
}

void EmployePage::switchToAdd(){
    contentLayout->setCurrentIndex(0);
}

void EmployePage::switchToAff(){
    contentLayout->setCurrentIndex(2);
}

void EmployePage::switchToView(){
    contentLayout->setCurrentIndex(3);
}


void EmployePage::saveEmploye(){
    if(fonctionEdit->currentIndex() == 0
        || serviceEdit->currentIndex() == 0
        || nomEdit->text().isEmpty()
        || prenomEdit->text().isEmpty()
        || mailEdit->text().isEmpty()
        || telephoneEdit->text().isEmpty()
        || salaireEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Tous les champs doit etre remplis !!!");
    }else{
        Employe employe(nomEdit->text(), prenomEdit->text(),
                        mailEdit->text(), telephoneEdit->text(), salaireEdit->text().toDouble(),
                        fonctionEdit->currentText().right(1).toInt(), serviceEdit->currentText().right(1).toInt());
        if(employe.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Employe Sauvegardée avec Succès !");
            clearForm();
        }
    }
}

void EmployePage::clearForm(){
    nomEdit->clear();
    fonctionEdit->setCurrentIndex(0);
    serviceEdit->setCurrentIndex(0);
    prenomEdit->clear();
    mailEdit->clear();
    telephoneEdit->clear();
    salaireEdit->clear();
}


void EmployePage::saveFonction(){
    if(libelefonctionEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Le champ doit etre rempli !!!");
    }else{
        Fonction fonction(libelefonctionEdit->text());
        if(fonction.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Fonction Sauvegardée avec Succès !");
            libelefonctionEdit->clear();
            this->close();
        }
    }
}

void EmployePage::saveAffect(){
    if(eEdit->currentIndex() == 0 || sEdit->currentIndex() == 0){
        QMessageBox::information(this, "Message", "Le champ doit etre rempli !!!");
    }else{
        Affectation affect(eEdit->currentText().right(1).toInt(), sEdit->currentText().right(1).toInt());
        if(affect.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Affectation Sauvegardée avec Succès !");
            eEdit->setCurrentIndex(0);
            sEdit->setCurrentIndex(0);
        }
    }
}

void EmployePage::search(){
    if(combo->currentIndex() == 0){
        QMessageBox::information(this, "Message", "Le champ doit etre rempli !!!");
    }else{
        tableModel = Employe::fetchProjetByAffectModel(tableModel, combo->currentText().right(1).toInt());
        if(tableModel){
            table->setModel(tableModel);
            table->setColumnHidden(0, true);
            table->setColumnHidden(5, true);
            table->setColumnHidden(6, true);
            table->setColumnHidden(7, true);
        }else
            QMessageBox::information(this, "Information", "Aucune Donnee Disponible !!!");
    }
}
