#ifndef VUVIDCASH_H
#define VUVIDCASH_H

#include <QWidget>
#include <database.h>
#include <QSqlTableModel>
namespace Ui {
class vuvidcash;
}
class vuvidcash : public QWidget
{
    Q_OBJECT
public:
explicit vuvidcash(QWidget *parent = nullptr);
~vuvidcash();
private:
Ui::vuvidcash *ui;
DataBase        *db;
QSqlTableModel  *model;
void setupModel(const QString &tableName, const QStringList &headers);
void createUI();
};

#endif // VUVIDCASH_H
