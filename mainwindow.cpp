#include "mainwindow.hh"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // alustetaan ajastin
    timer = new QTimer(parent);

    // yhdistetään
    connect(timer, &QTimer::timeout, this, &MainWindow::updateLcd);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startTimer);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopTimer);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetTimer);
    connect(ui->closeButton, &QPushButton::clicked, this, &MainWindow::closeTimer);
    ui->lcdNumberMin->setStyleSheet("background-color: darkblue ");
    ui->lcdNumberSec->setStyleSheet("background-color: orange ");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startTimer()
{
    timer->start(1000);
    time_ = 0;

}

void MainWindow::stopTimer()
{
    timer->stop();

}

void MainWindow::resetTimer()
{
    // tyhjentää lcd
    ui->lcdNumberMin->display(0);
    ui->lcdNumberSec->display(0);
    startTimer();

}

void MainWindow::closeTimer()
{
    this->close();

}

void MainWindow::updateLcd()
{
    time_++;
    ui->lcdNumberMin->display(time_/60);
    ui->lcdNumberSec->display(time_%60);

}
