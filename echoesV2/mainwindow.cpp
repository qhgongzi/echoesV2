#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../echoes/function.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    echttp::UrlEncode("cc");
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
