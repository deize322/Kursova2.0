#ifndef WINDOWUSER_H
#define WINDOWUSER_H

#include <QWidget>
#include "database.h"
#include <QtSql/QSqlTableModel>

namespace Ui {
class windowuser;
}

class windowuser : public QWidget
{
    Q_OBJECT

public:
    explicit windowuser(QWidget *parent = nullptr);
    ~windowuser();

private slots:
    void slotUpdateModels();

    void on_pushButton_clicked();

private:
    Ui::windowuser *ui;
    DataBase        *db;
    QSqlTableModel  *model;
    QSqlQuery *query;
    QSqlQueryModel *querymodel;

private:
    void setupModel(const QString &tableName, const QStringList &headers);
    void createUI();
};


#endif // WINDOWUSER_H
