#include "card.h"

Card::Card(QWidget *parent)
    : QWidget{parent}
{
    setFixedWidth(140);
    cardLayout = new QVBoxLayout(this);

    thumbnail = new QLabel();
    image = new QPixmap("/home/mds/Work/lab/cpp/qt/projrtFinalCPP/projetFinalCPPL2/asset/projet.jpg");
    thumbnail->setPixmap(image->scaled(120, 120, Qt::KeepAspectRatio));
    thumbnail->setMaximumSize(QSize(120, 120)); //   setFixedSize(120, 120);

    title = new QLabel("Mon Titre tres tres tres longrhgeriogherogheriognrelgeuiAGNeruiobvgoagiPergvjopzaeg", this);
    status = new QLabel("Status", this);

    readMore = new QPushButton("Lire Plus", this);

    cardLayout->addWidget(thumbnail);
    cardLayout->addWidget(title);
    cardLayout->addWidget(status);
    cardLayout->addWidget(readMore);

    setLayout(cardLayout);
}

Card::~Card(){}
