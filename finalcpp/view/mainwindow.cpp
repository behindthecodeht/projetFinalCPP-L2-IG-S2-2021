#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setWindowTitle("Application");
    setFixedSize(600, 300);

    // MainWindow Content //
    mainWidget = new QWidget(this);
    mainLayout = new QGridLayout(this);
    moduleGroup = new QGroupBox(mainWidget);
        moduleGroup->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
    moduleLayout = new QHBoxLayout(moduleGroup);

    // Module Buttons
    projetBtn = new ModuleButton(":/asset/projet.jpg", moduleGroup);
    employeBtn = new ModuleButton(":/asset/person.png", moduleGroup);
    servicesBtn = new ModuleButton(":/asset/services.png", moduleGroup);
    adresseBtn = new ModuleButton(":/asset/adresse.png", moduleGroup);

    // Event Listerner
    connect(servicesBtn, SIGNAL(clicked(bool)), new ServicePage, SLOT(show()));
    connect(adresseBtn, SIGNAL(clicked(bool)), new AdressePage, SLOT(show()));
    connect(projetBtn, SIGNAL(clicked(bool)), new ProjetPage, SLOT(show()));
    connect(employeBtn, SIGNAL(clicked(bool)), new EmployePage, SLOT(show()));

    // Utilisation //
    moduleLayout->addWidget(projetBtn);
    moduleLayout->addWidget(employeBtn);
    moduleLayout->addWidget(servicesBtn);
    moduleLayout->addWidget(adresseBtn);

    moduleGroup->setLayout(moduleLayout);

    // Central Widget
    mainLayout->addWidget(moduleGroup, 0, 0);
    mainWidget->setLayout(mainLayout);

    setCentralWidget(mainWidget);
}
MainWindow::~MainWindow(){}

