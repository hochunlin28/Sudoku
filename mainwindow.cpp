#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudoku.h"
#include "sudokusol.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(9);
    ui->tableWidget->setRowCount(9);
    ui->tableWidget->horizontalHeader()->setVisible(false);
    ui->tableWidget->verticalHeader()->setVisible(false);
    ui->tableWidget->horizontalHeader()->setDefaultSectionSize(37);
    ui->tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setStyleSheet("QTableWidget{gridline-color : black}");
    connect(ui->play,SIGNAL(clicked()),this,SLOT(on_play_clicked()));
    connect(ui->clear,SIGNAL(clicked()),this,SLOT(on_clear_clicked()));
    connect(ui->finishSudoku,SIGNAL(clicked()),this,SLOT(on_finishSudoku_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_play_clicked()
{
    ui->play->hide();
    ui->solve->hide();
    Sudoku su;
    su.getQuestion();
    su.setQuestion();
    for(int i=0 ; i<Sudoku::sudokuSize ; ++i){
        int row = i/9;
        int column = i%9;
        if(su.question[i] != 0){
            QString str = QString::number(su.question[i]);
            QTableWidgetItem *item = new QTableWidgetItem(str);
            item->setFlags(Qt::ItemIsEnabled);
            ui->tableWidget->setItem(row,column,item);
            ui->tableWidget->item(row,column)->setBackground(Qt::lightGray);
        }
    }

}

void MainWindow::on_clear_clicked()
{
        ui->tableWidget->clear();
        ui->textEdit->clear();
        ui->play->show();
        ui->solve->show();
}

void MainWindow::on_finishSudoku_clicked()
{
    Sudoku su;
    int currentMap[Sudoku::sudokuSize];
    for(int i=0 ; i<Sudoku::sudokuSize ; ++i){
        int row = i/9;
        int column = i%9;
        QTableWidgetItem *item = ui->tableWidget->item(row,column);
        if(item != NULL){
            QString text = item->text();
            currentMap[i] = text.toInt();
        }
        else{
            currentMap[i] = 0;
        }

    }
    su.setMap(currentMap);

    if(su.isCorrect()){
        QMessageBox::information(NULL,tr("Your score"),tr("correct!"));
    }
    else{
        QMessageBox::information(NULL,tr("Your score"),tr("Wrong!"));
    }
    return;
}

void MainWindow::on_solve_clicked()
{
    SudokuSol su;
    Sudoku question,ans;
    int currentMap[Sudoku::sudokuSize];
    for(int i=0 ; i<Sudoku::sudokuSize ; ++i){
        int row = i/9;
        int column = i%9;
        QTableWidgetItem *item = ui->tableWidget->item(row,column);
        if(item != NULL && item != 0){
            QString text = item->text();
            currentMap[i] = text.toInt();
        }
        else{
            currentMap[i] = 0;
        }

    }
    question.setMap(currentMap);
    su.backtracking(question,ans);
    if(su.getIsSolvable()){
        for(int i=0 ; i<Sudoku::sudokuSize ; ++i){
            if(question.getElement(i) == 0){
                int row = i/9;
                int column = i%9;
                QString str = QString::number(ans.getElement(i));
                QTableWidgetItem *item = new QTableWidgetItem(str);
                item->setFlags(Qt::ItemIsEnabled);
                ui->tableWidget->setItem(row,column,item);
                QMessageBox::information(NULL,tr("question"),tr("solvable!"));
            }
        }
        return;
    }
    else{
        QMessageBox::information(NULL,tr("question"),tr("unsolvable!"));
        return;
    }
}
