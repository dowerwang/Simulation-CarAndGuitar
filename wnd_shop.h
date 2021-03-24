#ifndef WND_SHOP_H
#define WND_SHOP_H

#include <QWidget>
#include <QDesktopWidget>
#include <QFile>
#include <QFileDialog>
#include <QDir>
#include <QMenuBar>
#include <QVBoxLayout>
#include "city.h"
#include <QFont>
#include <QMessageBox>
#include <string>
#include <QAction>

using namespace std;

namespace Ui {
class wnd_Shop;
}

class wnd_Shop : public QWidget
{
    Q_OBJECT

public:
    explicit wnd_Shop(QWidget *parent = nullptr);
    ~wnd_Shop();

    void getRange(int range);
    void getInsurance(int insurance);
    void getCityName(string name);
    void startSimulation();
    string getCityName();
    void closeEvent(QCloseEvent *event);
    void ReadFile(QString ofilename);
public slots:
    void on_actionSaveFile_triggered();
    void on_actionCloseWindow_triggered();
private:
    Ui::wnd_Shop *ui;

    QMenuBar *menubar;
    QAction *actionSaveFile;
    QAction *actionCloseWindow;

    const int margin = 10;

    string CityName, textGuitarShop, textCarShop;
    int CityRange;
    QString ofilename;

    shared_ptr<City> city{new City()};
};

#endif // WND_SHOP_H
