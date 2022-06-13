#include "adressepage.h"

AdressePage::AdressePage(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Adresse");
    setFixedSize(600, 400);

    mainLayout = new QGridLayout(this);

    menuGroup = new QGroupBox(this);
    menuGroup->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);

    contentGroup = new QGroupBox(this);
    menuGroup->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

    menuLayout = new QVBoxLayout(menuGroup);
    contentLayout = new QStackedLayout(contentGroup);

    // Menu Button
    btnList = new ModuleButton(":/asset/projet.jpg", this);
    connect(btnList, SIGNAL(clicked(bool)), this, SLOT(switchToList()));

    btnAdd = new ModuleButton(":/asset/person.png", this);
    connect(btnAdd, SIGNAL(clicked(bool)), this, SLOT(switchToAdd()));

    // Content Layouts
    listAdresseLayout = new QVBoxLayout(this);
    addAdresseLayout = new QGridLayout(this);

    listAdresse = new QWidget(this);
    addAdresse = new QWidget(this);

    // Set Widget to Layouts
    menuGroup->setLayout(menuLayout);
    menuLayout->addWidget(btnAdd);
    menuLayout->addWidget(btnList);


    contentGroup->setLayout(contentLayout);
    contentLayout->addWidget(addAdresse);
    contentLayout->addWidget(listAdresse);

    // Screen Layout Configuration
    setLayout(mainLayout);
    mainLayout->addWidget(menuGroup, 0, 0);
    mainLayout->addWidget(contentGroup, 0, 1);
    //?? END CONFIG SCREEN ??//

    // List Service //
    listAdresseTitle = new QLabel("Liste Des Adresses Disponible", this);
    listAdresseTable = new QTableView(this);
        listAdresseTable->setAutoFillBackground(true);
        listAdresseTable->setAutoScroll(true);
    listAdresseTableModel = new QSqlQueryModel(this);

    listAdresseLayout->addWidget(listAdresseTitle);
    listAdresseLayout->addWidget(listAdresseTable);

    listAdresse->setLayout(listAdresseLayout);
    // END List Service //

    // Add Service //
    addAdresseTitle = new QLabel("Ajouter Une Nouvelle Adresse", this);

    ligne = new QLabel("Ligne Adresse", this);
    departement = new QLabel("Departement", this);
    commune = new QLabel("Commune", this);
    telephone = new QLabel("Telephone", this);

    ligneEdit = new QLineEdit(this);
    telephoneEdit = new QLineEdit(this);
    communeEdit = new QLineEdit(this);
    departementEdit = new QComboBox(this);
        departementEdit->addItem("--choisir--");
        departementEdit->addItem("Ouest");
        departementEdit->addItem("Nord");
        departementEdit->addItem("Nord-Est");
        departementEdit->addItem("Nord-Ouest");
        departementEdit->addItem("Sud");
        departementEdit->addItem("Sud-Est");
        departementEdit->addItem("Centre");
        departementEdit->addItem("Artibonite");
        departementEdit->addItem("Grand-Anse");
        departementEdit->addItem("Nippes");
    btnSave = new QPushButton("Ajouter", this);
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveAdresse()));

    addAdresseLayout->addWidget(addAdresseTitle, 0, 0, 1, 3);
    addAdresseLayout->addWidget(ligne, 1, 0, 1, 3);
    addAdresseLayout->addWidget(ligneEdit, 2, 0, 1, 3);
    addAdresseLayout->addWidget(commune, 3, 0, 1, 2);
    addAdresseLayout->addWidget(departement, 3, 2);
    addAdresseLayout->addWidget(communeEdit, 4, 0, 1, 2);
    addAdresseLayout->addWidget(departementEdit, 4, 2);
    addAdresseLayout->addWidget(telephone, 5, 0, 1, 3);
    addAdresseLayout->addWidget(telephoneEdit, 6, 0, 1, 3);
    addAdresseLayout->addWidget(btnSave, 7, 0, 1, 3);

    addAdresse->setLayout(addAdresseLayout);
    // END AddService //
}

void AdressePage::switchToList(){
    listAdresseTableModel = Adresse::fetchModel(listAdresseTableModel);
    if(listAdresseTableModel){
        listAdresseTable->setModel(listAdresseTableModel);
        listAdresseTable->setColumnHidden(0, true);
    }else
        QMessageBox::information(this, "Information", "Aucune Donnee Disponible !!!");
    contentLayout->setCurrentIndex(1);
}

void AdressePage::switchToAdd(){
    contentLayout->setCurrentIndex(0);
}

void AdressePage::saveAdresse(){
    if(departementEdit->currentIndex() == 0
        || ligneEdit->text().isEmpty()
        || communeEdit->text().isEmpty()
        || telephoneEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Tous les champs doit etre remplis !!!");
    }else{
        Adresse adresse(ligneEdit->text(), departementEdit->currentText(), communeEdit->text(), telephoneEdit->text());
        if(adresse.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Adresse Sauvegardée avec Succès !");
            clearForm();
        }
    }
}

void AdressePage::clearForm(){
    ligneEdit->clear();
    departementEdit->setCurrentIndex(0);
    communeEdit->clear();
    telephoneEdit->clear();
}

void AdressePage::updateAdresse(){
    if(departementEdit->currentIndex() == 0
        || ligneEdit->text().isEmpty()
        || communeEdit->text().isEmpty()
        || telephoneEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Tous les champs doit etre remplis !!!");
    }else{
        Adresse adresse(ligneEdit->text(), departementEdit->currentText(), communeEdit->text(), telephoneEdit->text());
        if(adresse.modifier()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Adresse Sauvegardée avec Succès !");
            clearForm();
        }
    }
}


