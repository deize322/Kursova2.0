#include "windowuser.h"
#include "ui_userwindow.h"

userWindow::userWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::userWindow)
{
        ui->setupUi(this);
    db = new DataBase();
db->connectToDataBase();
db->fillCat("Меблі для ванної");
db->fillCat("Унитази");
db->fillCat("Ванни");
db->fillCat("Біде");
db->fillCat("Плитка");
db->fillCat("Джакузі");
        this->setupModel(TABLE,
    QStringList() << tr("id")
<< tr("Назва товару")
<< tr("Ціна")
<< tr("Кількість")
<< tr("Категорія")
<< tr("Дата добавлення")
               );
    this->createUI();
}

userWindow::~userWindow()
{
  delete ui;
}

    void userWindow::createUI()
{
ui->tableView->setModel(model);
ui->tableView->setColumnHidden(0, true);
ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
ui->tableView->setSelectionMode(QAbstractItemView::SingleSelection);
ui->tableView->horizontalHeader()->setStretchLastSection(true);
ui->tableView->setSortingEnabled(true);
ui->tableView->horizontalHeader()->setStretchLastSection(false);
ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    slotUpdateModels();
}

            void userWindow::slotUpdateModels()
{
        model->select();
}

            void userWindow::setupModel(const QString &tableName, const QStringList &headers)
{
        model = new QSqlTableModel(this);
        model->setTable(tableName);

    for(int i = 0, j = 0; i < model->columnCount(); i++, j++){
        model->setHeaderData(i,Qt::Horizontal,headers[j]);
    }
    model->setSort(0,Qt::AscendingOrder);
}

void userWindow::on_pushButton_clicked()
{
QSqlQuery qu;
QString n=model->data(model->index(ui->tableView->currentIndex().row(), 1)).toString();
QString p=model->data(model->index(ui->tableView->currentIndex().row(), 2)).toString();
    qu.prepare("UPDATE Goods set Count = Count-1  where Name ='"+n+"'");
    qu.exec();
    qu.prepare("INSERT INTO sell_goods(`Name_Sell`,`Price_Sell`) VALUES('"+n+"','"+p+"')");
    qu.exec();
        createUI();
}
