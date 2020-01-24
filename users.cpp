#include "users.h"
#include "ui_users.h"
users::users(QWidget *parent) :
    QWidget(parent),
  ui(new Ui::users)
{
  ui->setupUi(this);
    this->setWindowTitle("Вибір користувача");
}
users::~users()
{
    delete ui;
}
void users::on_adminButton_clicked()
{
    loginWindow *login = new loginWindow;
  login->setWindowTitle("Логін");
  login->show();
    this->close();
}
void users::on_userButton_clicked()
{
   windowuser *user = new windowuser;
  user->setWindowTitle("Користувач");
  user->show();
    this->close();
}
