#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    /*QTableWidgetItem *item = tableWidget;
    item->setBackgroundColor(QColor(50,60,10));*/


    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(9);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->viewport()->setStyleSheet("QTableview::Item{background-color:red}");
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(31);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.drawLine(10,10,80,60);
}


