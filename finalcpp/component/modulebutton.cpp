#include "modulebutton.h"

ModuleButton::ModuleButton(const QString &icon, QWidget *parent)
    : QPushButton{parent}
{
    setFlat(true);
    setFocusPolicy(Qt::NoFocus);
    setFixedSize(100, 100);
    setIconSize(QSize(90, 90));
    setIcon(QPixmap(icon));
//    setText("Service Name");
}

ModuleButton::~ModuleButton(){}
