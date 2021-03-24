#include "wnd_shop.h"
#include "ui_wnd_shop.h"

wnd_Shop::wnd_Shop(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wnd_Shop)
{
    ui->setupUi(this);

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setMargin(5);

    menubar = new QMenuBar(this);

    actionSaveFile = new QAction(this);
    actionSaveFile->setText("&Save File");
    actionSaveFile->setShortcut(QKeySequence::Save);

    actionCloseWindow = new QAction(this);
    actionCloseWindow->setText("&Close Window");
    actionCloseWindow->setShortcut(QKeySequence::Close);

    menubar->addAction(actionSaveFile);
    menubar->addAction(actionCloseWindow);
    connect(actionSaveFile, SIGNAL(triggered()), this, SLOT(on_actionSaveFile_triggered()));
    connect(actionCloseWindow, SIGNAL(triggered()), this, SLOT(on_actionCloseWindow_triggered()));

    vbox->addWidget(menubar);
    this->layout()->setMenuBar(menubar);

    this->move(QApplication::desktop()->width() / 2 - this->width(), QApplication::desktop()->height() / 2 - this->height() * 0.7);
    this->setFixedSize(static_cast<int>(QApplication::desktop()->width() * 0.7), static_cast<int>(QApplication::desktop()->height() * 0.7));

    ui->txtb_GuitarShop->setParent(this);
    ui->txtb_GuitarShop->setStyleSheet("QTextBrowser { background-color: black; color: white }");
    ui->txtb_GuitarShop->resize((this->width() / 12) * 5.5 , this->height() - 6*margin);
    ui->txtb_GuitarShop->move(margin, 11*margin/2);

    ui->txtb_CarShop->setParent(this);
    ui->txtb_CarShop->setStyleSheet("QTextBrowser { background-color: black; color: white }");
    ui->txtb_CarShop->resize(ui->txtb_GuitarShop->width(), ui->txtb_GuitarShop->height());
    ui->txtb_CarShop->move(this->width() - ui->txtb_CarShop->width() - margin, ui->txtb_GuitarShop->y());

    ui->txtb_moneyCarShop->setParent(this);
    ui->txtb_moneyCarShop->setStyleSheet("background-color: black; color: white; ");
    ui->txtb_moneyCarShop->resize(ui->txtb_CarShop->width(), 2*margin);
    ui->txtb_moneyCarShop->move(ui->txtb_CarShop->x(), ui->txtb_CarShop->y() - ui->txtb_moneyCarShop->height());

    ui->txtb_moneyGuitarShop->setParent(this);
    ui->txtb_moneyGuitarShop->setStyleSheet("QTextBrowser { background-color: black; color: white }");
    ui->txtb_moneyGuitarShop->resize(ui->txtb_moneyCarShop->width(), ui->txtb_moneyCarShop->height());
    ui->txtb_moneyGuitarShop->move(ui->txtb_GuitarShop->x(), ui->txtb_moneyCarShop->y());

    ui->lbl_CarShop->setParent(this);
    ui->lbl_CarShop->move(ui->txtb_CarShop->x() + ui->txtb_CarShop->width() - ui->lbl_CarShop->width(), ui->txtb_CarShop->y() - 2.25*ui->lbl_CarShop->height());

    ui->lbl_GuitarShop->setParent(this);
    ui->lbl_GuitarShop->move(ui->txtb_GuitarShop->x(), ui->lbl_CarShop->y());

    ui->lbl_Date->setParent(this);
    ui->lbl_Date->move(this->width() / 2 - ui->lbl_Date->width() / 2, ui->lbl_CarShop->y());
}

wnd_Shop::~wnd_Shop()
{
    delete ui;
}
void wnd_Shop::on_actionSaveFile_triggered()
{
    QString sfilename = QFileDialog::getSaveFileName(
                this,
                "Save file",
                ":/",
                "Text files (*.txt)");
    if(sfilename != NULL)
    {
        city->saveFile(sfilename);
        city->end_of_app = true;
    }
}
void wnd_Shop::on_actionCloseWindow_triggered()
{
    this->close();
}
void wnd_Shop::getRange(int range)
{
    this->CityRange = range;
    city->setRange(range);
}
void wnd_Shop::getCityName(string name)
{
    city->setName(name);
}
void wnd_Shop::startSimulation()
{
    this->setWindowTitle(QString::fromStdString(city->name));
    while(city->date < city->getRangeOfCity() + 1)
    {
        if(city->end_of_app == true)
        {
            break;
        }
        ui->lbl_Date->setText("Current year: " + QString::number(city->showDate()));
        city->nextYear();
        ui->txtb_moneyGuitarShop->setText(city->g_shop->show_info());
        ui->txtb_moneyCarShop->setText(city->c_shop->show_info());
        textCarShop += city->textCShop;
        textGuitarShop += city->textGShop;;
        ui->txtb_CarShop->append(QString::fromStdString(textCarShop));
        ui->txtb_GuitarShop->append(QString::fromStdString(textGuitarShop));
        QTest::qWait(1000);
    }
    ui->txtb_CarShop->append("End of symulation!");
    ui->txtb_GuitarShop->append("End of symulation!");
}
void wnd_Shop::getInsurance(int insurance)
{
    city->setInsurance(insurance);
}
void wnd_Shop::closeEvent(QCloseEvent *event)
{
    city->setEndOfApp(true);
    event->accept();
}
void wnd_Shop::ReadFile(QString ofilename)
{
    if(ofilename != NULL) city->readFile(ofilename);
}
