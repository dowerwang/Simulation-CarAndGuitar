#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QPushButton>
#include <QDesktopWidget>
#include <QDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QToolBar>
#include <QVBoxLayout>
#include <QLineEdit>
#include "year.h"
#include "city.h"
#include "wnd_shop.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionWczytaj_triggered();
    void on_actionZamknij_triggered();
    void on_actionZminimalizuj_triggered();
    void on_btn_Symulate_clicked();
    void on_btn_SetRange_clicked();
    void on_btn_SetName_clicked();
    void on_btn_SetInsurance_clicked();
private:
    Ui::MainWindow *ui;
    shared_ptr<wnd_Shop> shop_window{new wnd_Shop};

    const int margin = 10;
    int range, insurance;
    string CityName;

    void ErrorMessage();
    void CheckingEnteredData();
};

#endif // MAINWINDOW_H
