#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFuture>
#include <QtConcurrent/QtConcurrent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);

    // set slider to current brightness
    int currentBrightness = displayUtil.getCurrentBrightness();
    ui->slider->setValue(currentBrightness);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_slider_valueChanged(int value)
{
    displayUtil.setBrightness(value);
}
