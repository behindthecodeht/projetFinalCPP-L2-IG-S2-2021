#ifndef ADRESSEPAGE_H
#define ADRESSEPAGE_H

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
#include <QSqlQueryModel>
#include <QMessageBox>
#include "component/modulebutton.h"
#include "model/adresse.h"

class AdressePage : public QWidget
{
    Q_OBJECT
public:
    explicit AdressePage(QWidget *parent = nullptr);
    void clearForm();

public slots:
    void switchToList();
    void switchToAdd();
    void saveAdresse();
    void updateAdresse();

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
    QGridLayout *addAdresseLayout;
    QVBoxLayout *listAdresseLayout;

    QWidget *addAdresse;
    QWidget *listAdresse;

    // List Adresse Elements
    QLabel *listAdresseTitle;
    QTableView *listAdresseTable;
    QSqlQueryModel *listAdresseTableModel;

    // Add and Update Adresse Elements
    QLabel *addAdresseTitle;
    QLabel *ligne;
    QLabel *departement;
    QLabel *commune;
    QLabel *telephone;
    QLineEdit *ligneEdit;
    QLineEdit *telephoneEdit;
    QLineEdit *communeEdit;
    QComboBox *departementEdit;
    QPushButton *btnSave;

};

#endif // ADRESSEPAGE_H
