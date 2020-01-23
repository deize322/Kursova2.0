#include "database.h"

DataBase::DataBase(QObject *parent) : QObject(parent)
{

}

DataBase::~DataBase()
{

}


    void DataBase::connectToDataBase()
{
  if(!QFile(DATABASE_NAME).exists()){
      this->restoreDataBase();
  } else {
      this->openDataBase();
    }
}
    bool DataBase::restoreDataBase()
{
  if(this->openDataBase()){
      if(!this->createTable()){
 return false;
        } else {
            return true;
        }
    } else {
        qDebug() << "Не вдалося відновити базу даних"
                    ;
        return false;
    }
    return false;
}

bool DataBase::openDataBase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName(DATABASE_HOSTNAME);
    db.setDatabaseName(DATABASE_NAME);
    if(db.open()){
        return true;
    } else {
        return false;
    }
}

void DataBase::closeDataBase()
{
    db.close();
}

bool DataBase::createTable()
{
    QSqlQuery query;
    if(!query.exec( "CREATE TABLE " TABLE " ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, "
                            TABLE_NAME      " VARCHAR(255)      NOT NULL,"
                            TABLE_PRICE     " DOUBLE            NOT NULL,"
                            TABLE_COUNT     " INTEGER           NOT NULL,"
                            TABLE_CAT_NAME  " VARCHAR(255)      NOT NULL,"
                            TABLE_DATE      " DATE              NOT NULL"
                    " )"
                    )){
        qDebug() << "DataBase: error of create " << TABLE;
        qDebug() << query.lastError().text();
        return  false;
    }
        if(!query.exec( "CREATE TABLE " TABLE_CAT " ("
                       TABLE_CAT_NAME  " VARCAHR(255)                       NOT NULL"
                   " ) "
                        )){
            qDebug() << "DataBase: error of create " << TABLE_CAT;
            qDebug() << query.lastError().text();

        return false;
    }
        if(!query.exec("CREATE TABLE sell_goods (id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,"
                   "Name_Sell VARCHAR(255)                  NOT NULL,"
                       "Price_Sell INTEGER NOT NULL)"));
        else {
        return true;
    }
    return false;
}

bool DataBase::inserIntoTable(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE " ( " TABLE_NAME ", "
                                             TABLE_PRICE ", "
                                             TABLE_COUNT ", "
                                             TABLE_CAT_NAME " , "
                                             TABLE_DATE " ) "
                  "VALUES (:Name, :Price, :Count, :Cat, :Date )");
    query.bindValue(":Name",       data[0].toString());
    query.bindValue(":Price",      data[1].toDouble());
    query.bindValue(":Count",      data[2].toInt());
    query.bindValue(":Cat",      data[3].toString());
    query.bindValue(":Date",       data[4].toDate());
    if(!query.exec()){
        qDebug() << "error insert into " << TABLE;
        qDebug() << query.lastError().text();
        return false;
    } else {
        return true;
    }
}

bool DataBase::insertIntoCat(const QVariantList &data)
{
    QSqlQuery query;
    query.prepare("INSERT INTO " TABLE_CAT " ( " TABLE_CAT_NAME " ) "
                  "VALUES (:Name)");
    query.bindValue(":Name",        data[0].toString());
    if(!query.exec()){
        qDebug() << "error insert into" << TABLE_CAT;
        qDebug() << query.lastError().text();
        return  false;
    } else {
            return true;
    }
}

void DataBase::fillCat(QString name)
{
    QSqlQuery query("SELECT Cat_Name FROM Categories where Cat_Name='"+name + "'");
            query.first();
    if(query.value(0).toString()==""){
    QVariantList data;

    data.append(name);
    insertIntoCat(data);
    data.clear();
}
}
