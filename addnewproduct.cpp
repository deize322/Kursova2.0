#include "addnewproduct.h"
#include "ui_addnewproduct.h"

addnewproduct::addnewproduct(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addnewproduct)
{
    ui->setupUi(this);
    db = new DataBase();


    addRow();
}

addnewproduct::~addnewproduct()
{
    delete ui;
}

void addnewproduct::on_insert_clicked()
{
    data = new QVariantList;
    data->append(ui->nameLine->text());
    data->append(ui->priceLine->text());
    data->append(ui->countLine->text());
    data->append(ui->category->currentText());
    data->append(QDate::currentDate());
    db->inserIntoTable(*data);
    emit signalReady();
    this->close();
    ui->nameLine->clear();
    ui->countLine->clear();
    ui->priceLine->clear();

}

void addnewproduct::setupModel()
{
        model = new QSqlTableModel(this);
        model->setTable(TABLE);
        model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model->select();
}

void addnewproduct::addRow()
{
    query = new QSqlQuery;
    ui->category->clear();

    queryModel = new QSqlQueryModel(this);
    query->prepare("SELECT " TABLE_CAT_NAME " FROM " TABLE_CAT);
    query->exec();
    queryModel->setQuery(*query);

    ui->category->setModel(queryModel);
}


void addnewproduct::on_category_currentIndexChanged(const QString &arg1)
{
    ui->category->setEditText(ui->category->currentText());
        qDebug()<<ui->category->currentText();
}
