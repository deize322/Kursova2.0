#ifndef ADDNEWPRODUCT_H
#define ADDNEWPRODUCT_H

#include <QDialog>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>
#include "database.h"

namespace Ui {
class addnewproduct;
}
class addnewproduct : public QDialog
{
    Q_OBJECT
public:
explicit addnewproduct(QWidget *parent = nullptr);
~addnewproduct();

signals:
void signalReady();

private slots:
void on_insert_clicked();


void on_category_currentIndexChanged(const QString &arg1);

private:
Ui::addnewproduct *ui;
DataBase *db;
QSqlTableModel *model;
QSqlQueryModel *queryModel;
QSqlQuery *query;
QVariantList *data;

private:
void setupModel();
void createUI();
void addRow();
};

#endif // ADDNEWPRODUCT_H
