#include "mainwindow.h"
#include "ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Symulation");
    this->move(QApplication::desktop()->width() / 2 - this->width(), QApplication::desktop()->height() / 2 - this->height() * 0.7);
    this->setFixedSize(static_cast<int>(QApplication::desktop()->width() * 0.7), static_cast<int>(QApplication::desktop()->height() * 0.7));

    ui->btn_Symulate->setParent(this);
    ui->btn_Symulate->setFixedSize(this->width() / 2 , this->height() / 10);
    ui->btn_Symulate->move(this->width()/2 - ui->btn_Symulate->width()/2, this->height() - ui->btn_Symulate->height()/2 - 3*margin);
    ui->btn_Symulate->setEnabled(false);

    ui->txt_Range->setParent(this);
    ui->txt_Range->setFixedSize(this->width() / 10 , this->height() / 10);
    ui->txt_Range->move(this->width()/2 - ui->txt_Range->width()/2, 5*margin);

    ui->btn_SetRange->setParent(this);
    ui->btn_SetRange->resize(ui->txt_Range->width(), ui->txt_Range->height());
    ui->btn_SetRange->move(ui->txt_Range->x() - ui->btn_SetRange->width() - margin, ui->txt_Range->y());

    ui->lbl_Range->setParent(this);
    ui->lbl_Range->move(ui->txt_Range->x() + ui->txt_Range->width()/2 - ui->lbl_Range->width()/2, ui->txt_Range->y() - ui->txt_Range->height() / 2);

    ui->txt_Name->setParent(this);
    ui->txt_Name->setFixedSize(ui->txt_Range->size());
    ui->txt_Name->move(ui->txt_Range->x(), ui->txt_Range->y() + 5*margin + ui->txt_Name->height()/2);

    ui->btn_SetName->setParent(this);
    ui->btn_SetName->resize(ui->txt_Name->width(), ui->txt_Name->height());
    ui->btn_SetName->move(ui->txt_Name->x() - ui->btn_SetName->width() - margin, ui->txt_Name->y());

    ui->lbl_Name->setParent(this);
    ui->lbl_Name->move(ui->txt_Name->x() + ui->txt_Name->width()/2 - ui->lbl_Name->width()/2, ui->txt_Range->y() + ui->txt_Range->height() * 1.25);

    ui->txt_Insurance->setParent(this);
    ui->txt_Insurance->setFixedSize(ui->txt_Range->size());
    ui->txt_Insurance->move(ui->txt_Name->x(), ui->txt_Name->y() + 5*margin + ui->txt_Insurance->height()/2);

    ui->btn_SetInsurance->setParent(this);
    ui->btn_SetInsurance->resize(ui->txt_Insurance->width(), ui->txt_Insurance->height());
    ui->btn_SetInsurance->move(ui->txt_Insurance->x() - ui->btn_SetInsurance->width() - margin, ui->txt_Insurance->y());

    ui->lbl_Insurance->setParent(this);
    ui->lbl_Insurance->move(ui->txt_Insurance->x() + ui->txt_Insurance->width()/2 - ui->lbl_Insurance->width()/2,
                            ui->txt_Name->y() + ui->txt_Name->height() * 1.25);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionWczytaj_triggered()
{
    QString ofilename = QFileDialog::getOpenFileName(
                this,
                "Choose city to load",
                ":/",
                "Text files (*.txt)");
    if(ofilename != NULL)
    {
        shop_window->ReadFile(ofilename);
        shop_window->show();
        this->close();
        shop_window->startSimulation();
    }
}

void MainWindow::on_actionZamknij_triggered()
{
    this->close();
}

void MainWindow::on_actionZminimalizuj_triggered()
{
    this->lower();
}

void MainWindow::on_btn_Symulate_clicked()
{
    shop_window->getRange(range);
    shop_window->getCityName(CityName);
    shop_window->getInsurance(insurance);
    shop_window->show();
    this->close();
    shop_window->startSimulation();

}
void MainWindow::on_btn_SetRange_clicked()
{
    bool ok;
    ui->txt_Range->text().toInt(&ok);
    if(ui->txt_Range->text().isEmpty() || !ok || ui->txt_Range->text().toInt() > 100 || ui->txt_Range->text().toInt() < 1)
    {
        this->ErrorMessage();
    }
    else
    {
        range = ui->txt_Range->text().toInt();
        ui->txt_Range->setEnabled(false);
        ui->btn_SetRange->setEnabled(false);
    }
    CheckingEnteredData();
}
void MainWindow::on_btn_SetName_clicked()
{
    if(ui->txt_Name->text().isEmpty())
    {
        this->ErrorMessage();
    }
    else
    {
        CityName = ui->txt_Name->text().toStdString();
        ui->txt_Name->setEnabled(false);
        ui->btn_SetName->setEnabled(false);
    }
    CheckingEnteredData();
}
void MainWindow::on_btn_SetInsurance_clicked()
{
    bool ok;
    ui->txt_Insurance->text().toInt(&ok);
    if(ui->txt_Insurance->text().isEmpty() || !ok || ui->txt_Insurance->text().toInt() < 0 || ui->txt_Insurance->text().toInt() > 100)
    {
        this->ErrorMessage();
    }
    else
    {
        insurance = ui->txt_Insurance->text().toInt();
        ui->txt_Insurance->setEnabled(false);
        ui->btn_SetInsurance->setEnabled(false);
    }
    CheckingEnteredData();
}
void MainWindow::ErrorMessage()
{
    QMessageBox msg(this);
    msg.setWindowTitle("ERROR");
    msg.setText("You need to enter a proper value");
    msg.setIcon(QMessageBox::Critical);
    msg.exec();
}
void MainWindow::CheckingEnteredData()
{
    if(!ui->btn_SetRange->isEnabled() && !ui->btn_SetName->isEnabled() && !ui->btn_SetInsurance->isEnabled())
    {
        ui->btn_Symulate->setEnabled(true);
    }
}
