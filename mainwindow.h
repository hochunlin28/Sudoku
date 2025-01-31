#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QTableWidget>
#include <QTableView>
#include <QHeaderView>
#include <QPainter>
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QPalette>
#include <QLabel>
#include <QMovie>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:


    void on_play_clicked();

    void on_clear_clicked();

    void on_finishSudoku_clicked();

    void on_solve_clicked();

    void on_start_clicked();

    void on_setQuestion_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
