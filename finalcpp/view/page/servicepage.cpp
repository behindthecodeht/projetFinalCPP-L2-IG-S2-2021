#include "servicepage.h"

ServicePage::ServicePage(QWidget *parent)
    : QWidget{parent}
{
    setWindowTitle("Service");
    setFixedSize(800, 400);

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
    listServiceLayout = new QVBoxLayout(this);
    addServiceLayout = new QVBoxLayout(this);

    listService = new QWidget(this);
    addService = new QWidget(this);


    //?? CONFIG SCREEN ??//

    // Set Widget to Layouts
    menuGroup->setLayout(menuLayout);
    menuLayout->addWidget(btnAdd);
    menuLayout->addWidget(btnList);

    contentGroup->setLayout(contentLayout);
    contentLayout->addWidget(addService);
    contentLayout->addWidget(listService);

    // Screen Layout Configuration
    setLayout(mainLayout);
    mainLayout->addWidget(menuGroup, 0, 0);
    mainLayout->addWidget(contentGroup, 0, 1);
    //?? END CONFIG SCREEN ??//

    // List Service //
    listServiceTitle = new QLabel("Liste Des Services Disponible", this);
    listServiceTable = new QTableView(this);
        listServiceTable->setAutoFillBackground(true);
        listServiceTable->setAutoScroll(true);
    listServiceTableModel = new QSqlQueryModel(this);

    listServiceLayout->addWidget(listServiceTitle);
    listServiceLayout->addWidget(listServiceTable);

    listService->setLayout(listServiceLayout);
    // END List Service //

    // Add Service //
    addServiceTitle = new QLabel("Ajouter Un Nouveau Service", this);
    libele = new QLabel("Entrer Le Nom du Service", this);
    etat = new QLabel("Statut", this);
    adresse = new QLabel("Service", this);
    libeleEdit = new QLineEdit(this);
    etatEdit = new QComboBox(this);
        etatEdit->addItem("--Choisir--");
        etatEdit->addItem("Inactif");
        etatEdit->addItem("Actif");
    adresseEdit = new QComboBox(this);
    QSqlQuery r = Adresse::fetchAll();
        adresseEdit->addItem("--Choisir--");
        while(r.next()){
            QString option =  r.value(1).toString() + ", " + r.value(3).toString() + " - ID:" + r.value(0).toString();
            adresseEdit->addItem(option);
        }

    btnSave = new QPushButton("Ajouter", this);
    connect(btnSave, SIGNAL(clicked(bool)), this, SLOT(saveService()));

    addServiceLayout->addWidget(addServiceTitle);
    addServiceLayout->addWidget(libele);
    addServiceLayout->addWidget(libeleEdit);
    addServiceLayout->addWidget(adresse);
    addServiceLayout->addWidget(adresseEdit);
    addServiceLayout->addWidget(etat);
    addServiceLayout->addWidget(etatEdit);
    addServiceLayout->addWidget(btnSave);

    addService->setLayout(addServiceLayout);
    // END AddService //


}

void ServicePage::switchToList(){
    listServiceTableModel = Service::fetchModel(listServiceTableModel);
    if(listServiceTableModel){
        listServiceTable->setModel(listServiceTableModel);
        listServiceTable->setColumnHidden(0, true);
        listServiceTable->setColumnHidden(1, true);
        listServiceTable->setColumnHidden(4, true);
    }else
        QMessageBox::information(this, "Information", "Aucune Donnee Disponible !!!");
    contentLayout->setCurrentIndex(1);
}

void ServicePage::switchToAdd(){
    contentLayout->setCurrentIndex(0);
}


void ServicePage::saveService(){
    if(etatEdit->currentIndex() == 0
        || adresseEdit->currentIndex() == 0
        || libeleEdit->text().isEmpty()){
        QMessageBox::information(this, "Message", "Tous les champs doit etre remplis !!!");
    }else{
        Service service(libeleEdit->text(), etatEdit->currentText(), adresseEdit->currentText().right(1));
        if(service.creer()){
            QMessageBox::information(this, "Rapport d'Enregistrement", "Service Sauvegardée avec Succès !");
            clearForm();
        }
    }
}

void ServicePage::clearForm(){
    libeleEdit->clear();
    etatEdit->setCurrentIndex(0);
    adresseEdit->setCurrentIndex(0);
}
