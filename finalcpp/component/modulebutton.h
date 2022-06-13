#ifndef MODULEBUTTON_H
#define MODULEBUTTON_H

#include <QPushButton>
#include <QObject>

class ModuleButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ModuleButton(const QString &icon, QWidget * parent = nullptr);
    ~ModuleButton();
};

#endif // MODULEBUTTON_H
