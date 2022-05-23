#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "wimage.h"
#include <QFileDialog>
#include <QDebug>
#include <QFile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnNext->setEnabled(false);
    ui->btnPre->setEnabled(false);

    // set which pic in the total pics
    m_labelStatus = new QLabel(this);
    statusBar()->addPermanentWidget(m_labelStatus, 50);

    //set window title
    setWindowTitle("PicRect");

    connect(ui->wImage, SIGNAL(arriveFirst()), this, SLOT(setPicLoc()));
    connect(ui->wImage, SIGNAL(arriveLast()), this, SLOT(setPicLoc()));
    connect(ui->wImage, SIGNAL(midPic()), this, SLOT(setPicLoc()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnPre_clicked()
{
    ui->wImage->onBtnPreClicked();
}

void MainWindow::on_btnNext_clicked()
{
    ui->wImage->onBtnNextClicked();
}

void MainWindow::on_actionSetImgPath_triggered()
{
//    QString fileName =
//            QFileDialog::getOpenFileName(this,
//                                         tr("打开工程"),
//                                         QCoreApplication::applicationDirPath()+"/../images", tr("JPEG (*.jpg)"));

    QStringList listFileName = QFileDialog::getOpenFileNames(this,
                                                             tr("打开工程"),
                                                             QCoreApplication::applicationDirPath()+"/../images",
                                                             tr("JPEG (*.jpg)"));

    ui->wImage->onSetImagePath(listFileName);

    setPicLoc();
}


void MainWindow::setPicLoc()
{
    m_labelStatus->setText("图片: " +
                 QString::number(ui->wImage->currIndex()+1) +
                 "/" +
                 QString::number(ui->wImage->numImages()));

    setBtnState();
}

void MainWindow::on_btnSave_clicked()
{
    if (ui->wImage->rectsInfo().isEmpty())
    {
        return;
    }

    QFile file(QCoreApplication::applicationDirPath()+"/../picInfo.txt");

    if (!file.open(QIODevice::WriteOnly))
    {
        qDebug() << "write failed!";
    }

    file.write(ui->wImage->rectsInfo().toLocal8Bit());
    file.close();
}

void MainWindow::setBtnState()
{

    ui->btnPre->setEnabled(true);
    ui->btnNext->setEnabled(true);

    if (ui->wImage->currIndex() == 0)
    {
        ui->btnPre->setEnabled(false);
    }

    if (ui->wImage->currIndex() == ui->wImage->numImages()-1)
    {
        ui->btnNext->setEnabled(false);
    }
}














