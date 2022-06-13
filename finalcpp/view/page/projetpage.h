#ifndef PROJETPAGE_H
#define PROJETPAGE_H

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
#include <QTableView>
#include <QMessageBox>
#include <QSqlQueryModel>
#include "component/modulebutton.h"
#include "model/projet.h"

class ProjetPage : public QWidget
{
    Q_OBJECT
public:
    explicit ProjetPage(QWidget *parent = nullptr);
    void clearForm();

public slots:
    void switchToList();
    void switchToAdd();
    void saveProjet();

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

    // Content Layouts
    QVBoxLayout *addProjetLayout;
    QVBoxLayout *listProjetLayout;

    QWidget *addProjet;
    QWidget *listProjet;

    // List Projet Elements
    QLabel *listProjetTitle;
    QTableView *listProjetTable;
    QSqlQueryModel *listProjetTableModel;

    // Add Projet Elements
    QLabel *addProjetTitle;
    QLabel *libele;
    QLabel *duree;
    QLabel *coutEstime;
    QLabel *etat;
    QLineEdit *libeleEdit;
    QLineEdit *dureEdit;
    QLineEdit *coutEstimeEdit;
    QComboBox *etatEdit;
    QPushButton *btnSave;

};

#endif // PROJETPAGE_H
