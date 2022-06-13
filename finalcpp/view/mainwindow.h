#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QSizePolicy>
#include "component/modulebutton.h"
#include "view/page/servicepage.h"
#include "view/page/adressepage.h"
#include "view/page/projetpage.h"
#include "view/page/employepage.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:

    QWidget *mainWidget;

    QGridLayout *mainLayout;
    QHBoxLayout *moduleLayout;

    QGridLayout *employePageLayout;

    QGroupBox *moduleGroup;

    // Module Buttons
    ModuleButton *employeBtn;
    ModuleButton *servicesBtn;
    ModuleButton *adresseBtn;
    ModuleButton *projetBtn;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

};
#endif // MAINWINDOW_H
