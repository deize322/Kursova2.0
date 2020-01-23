#ifndef ADMINCHECK_H
#define ADMINCHECK_H

#include <QWidget>
#include <database.h>
#include <QSqlTableModel>
namespace Ui {
class adminCheck;
}
class adminCheck : public QWidget
{
    Q_OBJECT
public:
explicit adminCheck(QWidget *parent = nullptr);
~adminCheck();
private:
Ui::adminCheck *ui;
DataBase        *db;
QSqlTableModel  *model;
void setupModel(const QString &tableName, const QStringList &headers);
void createUI();
};

#endif // ADMINCHECK_H
