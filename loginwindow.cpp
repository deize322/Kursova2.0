#include "loginwindow.h"
#include "ui_loginwindow.h"

loginWindow::loginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}
loginWindow::~loginWindow()
{
    delete ui;

}
bool loginWindow::checkLog()
{
   if( ui->login->text() == "admin322" && ui->pass->text() == "qwerty322" ){
       return true;
    }
   else
    {
       QMessageBox::about(this,"Error","Неправильний Логін або Пароль");
       return false;
    }
}
void loginWindow::on_signIn_clicked()
{
   if(checkLog()){
      MainWindow *adminWindow = new MainWindow;
      adminWindow->setWindowTitle("Вікно Адміністратора");
      adminWindow->show();
       this->close();
    }
}
