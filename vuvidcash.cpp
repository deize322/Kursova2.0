#include "vuvidcash.h"
#include "ui_vuvidcash.h"

vuvidcash::vuvidcash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::vuvidcash)
{
    ui->setupUi(this);
    db = new DataBase();
    db->connectToDataBase();
    this->setupModel("sell_goods",
                     QStringList() << tr("id")
                                   << tr("Назва товару")
                                   << tr("Ціна")
               );

    this->createUI();
    QSqlQuery q;
    q.prepare("SELECT SUM(Price_Sell) FROM sell_goods");
    q.exec();
    q.next();
    ui->moneyLabel->setText(q.value(0).toString());
}

vuvidcash::~vuvidcash()
{
    delete ui;
}
void vuvidcash::createUI()
{
    ui->tableView->setModel(model);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    //ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
    ui->tableView->horizontalHeader()->setStretchLastSection(false);
}

void vuvidcash::setupModel(const QString &tableName, const QStringList &headers)
{
    model = new QSqlTableModel(this);
    model->setTable(tableName);

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}
