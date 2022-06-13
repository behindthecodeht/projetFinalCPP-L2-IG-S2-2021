#include "projetpage.h"

ProjetPage::ProjetPage(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Projet");
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
    listProjetLayout = new QVBoxLayout(this);
    addProjetLayout = new QVBoxLayout(this);

    listProjet = new QWidget(this);
    addProjet = new QWidget(this);

    //?? CONFIG SCREEN ??//

    // Set Widget to Layouts
    menuGroup->setLayout(menuLayout);
    menuLayout->addWidget(btnAdd);
    menuLayout->addWidget(btnList);

    contentGroup->setLayout(contentLayout);
    contentLayout->addWidget(addProjet);
    contentLayout->addWidget(listProjet);

    // Screen Layout Configuration
    setLayout(mainLayout);
    mainLayout->addWidget(menuGroup, 0, 0);
    mainLayout->addWidget(contentGroup, 0, 1);
    //?? END CONFIG SCREEN ??//

    // List Projet //
    listProjetTitle = new QLabel("Liste Des Projets", this);
    listProjetTable = new QTableView(this);
        listProjetTable->setAutoFillBackground(true);
        listProjetTable->setAutoScroll(true);
    listProjetTableModel = new QSqlQueryModel(this);

    listProjetLayout->addWidget(listProjetTitle);
    listProjetLayout->addWidget(listProjetTable);

    listProjet->setLayout(listProjetLayout);
    // END List Projet //

    // Add Projet //
    addProjetTitle = new QLabel("Ajouter Un Nouveau Projet", this);
    libele = new QLabel("Nom du Projet", this);
    etat = new QLabel("Statut", this);
    duree = new QLabel("Duree", this);
    coutEstime = new QLabel("Cout Estimé", this);
    libeleEdit = new QLineEdit(this);
    dureEdit = new QLineEdit(this);
    coutEstimeEdit = new QLineEdit(this);
    etatEdit = new QComboBox(this);
        etatEdit->addItem("--Choisir--");
        etatEdit->addItem("Creer");
        etatEdit->addItem("Demarrer");
        etatEdit->addItem("Pause");
        etatEdit->addItem("Terminer");

    btnSave = new QPushButton("Ajouter", this);
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveProjet()));

    addProjetLayout->addWidget(addProjetTitle);
    addProjetLayout->addWidget(libele);
    addProjetLayout->addWidget(libeleEdit);
    addProjetLayout->addWidget(duree);
    addProjetLayout->addWidget(dureEdit);
    addProjetLayout->addWidget(coutEstime);
    addProjetLayout->addWidget(coutEstimeEdit);
    addProjetLayout->addWidget(etat);
    addProjetLayout->addWidget(etatEdit);
    addProjetLayout->addWidget(btnSave);

    addProjet->setLayout(addProjetLayout);
    // END AddProjet //
}


void ProjetPage::switchToList(){
    listProjetTableModel = Projet::fetchModel(listProjetTableModel);
    if(listProjetTableModel){
        listProjetTable->setModel(listProjetTableModel);
        listProjetTable->setColumnHidden(0, true);
    }else
        QMessageBox::information(this, "Information", "Aucune Donnee Disponible !!!");
    contentLayout->setCurrentIndex(1);
}

void ProjetPage::switchToAdd(){
    contentLayout->setCurrentIndex(0);
}

void ProjetPage::saveProjet(){
    if(etatEdit->currentIndex() == 0
        || libeleEdit->text().isEmpty()
        || dureEdit->text().isEmpty()
        || coutEstimeEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Tous les champs doit etre remplis !!!");
    }else{
        Projet projet(libeleEdit->text(), dureEdit->text().toInt(), coutEstimeEdit->text().toDouble(), etatEdit->currentText());
        if(projet.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Projet Sauvegardée avec Succès !");
            clearForm();
        }
    }
}

void ProjetPage::clearForm(){
    libeleEdit->clear();
    etatEdit->setCurrentIndex(0);
    dureEdit->clear();
    coutEstimeEdit->clear();
}



