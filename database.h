#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSql>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlDatabase>
#include <QFile>
#include "ui_mainwindow.h"
#include <QDate>
#include <QDebug>
#include <QString>
#define DATABASE_HOSTNAME   "ExampleDataBase"
#define DATABASE_NAME       "DataBase.db"
#define TABLE                   "Goods"
#define TABLE_CAT               "Categories"
#define TABLE_CAT_ID            "Cat_ID"
#define TABLE_CAT_NAME          "Cat_Name"
#define TABLE_CAT_COUNT         "Cat_Count"
#define TABLE_NAME              "Name"
#define TABLE_COUNT             "Count"
#define TABLE_PRICE             "Price"
#define TABLE_DATE              "Date"
class DataBase : public QObject
{
    Q_OBJECT
public:
explicit DataBase(QObject *parent = 0);
~DataBase();
void connectToDataBase();
bool inserIntoTable(const QVariantList &data);
bool insertIntoCat(const QVariantList &data);
void fillCat(QString name);
private:
    QSqlDatabase    db;
private:
bool restoreDataBase();
bool createTable();
void closeDataBase();
bool openDataBase();
};

#endif // DATABASE_H
