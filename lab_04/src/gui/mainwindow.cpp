#include "../gui/mainwindow.h"
#include "../gui/ui_mainwindow.h"
#include "qdebug.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    qDebug() << "Stopped at 1 floor, doors are closed.\n"
                "Waiting state...";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_button_cabin_1_clicked()
{
    qDebug() << "Cabin pressed button 1.";
    lift.click(1);
}

void MainWindow::on_button_cabin_2_clicked()
{
    qDebug() << "Cabin pressed button 2.";
    lift.click(2);
}

void MainWindow::on_button_cabin_3_clicked()
{
    qDebug() << "Cabin pressed button 3.";
    lift.click(3);
}

void MainWindow::on_button_cabin_4_clicked()
{
    qDebug() << "Cabin pressed button 4.";
    lift.click(4);
}

void MainWindow::on_button_cabin_5_clicked()
{
    qDebug() << "Cabin pressed button 5.";
    lift.click(5);
}

void MainWindow::on_button_cabin_6_clicked()
{
    qDebug() << "Cabin pressed button 6.";
    lift.click(6);
}

void MainWindow::on_button_cabin_7_clicked()
{
    qDebug() << "Cabin pressed button 7.";
    lift.click(7);
}

void MainWindow::on_button_cabin_8_clicked()
{
    qDebug() << "Cabin pressed button 8.";
    lift.click(8);
}

void MainWindow::on_button_cabin_9_clicked()
{
    qDebug() << "Cabin pressed button 9.";
    lift.click(9);
}

void MainWindow::on_button_cabin_10_clicked()
{
    qDebug() << "Cabin pressed button 10.";
    lift.click(10);
}

void MainWindow::on_button_floor_1_clicked()
{
    qDebug() << "Floor 1 call.";
    lift.click(1);
}

void MainWindow::on_button_floor_2_clicked()
{
    qDebug() << "Floor 2 call.";
    lift.click(2);
}

void MainWindow::on_button_floor_3_clicked()
{
    qDebug() << "Floor 3 call.";
    lift.click(3);
}

void MainWindow::on_button_floor_4_clicked()
{
    qDebug() << "Floor 4 call.";
    lift.click(4);
}

void MainWindow::on_button_floor_5_clicked()
{
    qDebug() << "Floor 5 call.";
    lift.click(5);
}

void MainWindow::on_button_floor_6_clicked()
{
    qDebug() << "Floor 6 call.";
    lift.click(6);
}

void MainWindow::on_button_floor_7_clicked()
{
    qDebug() << "Floor 7 call.";
    lift.click(7);
}

void MainWindow::on_button_floor_8_clicked()
{
    qDebug() << "Floor 8 call.";
    lift.click(8);
}

void MainWindow::on_button_floor_9_clicked()
{
    qDebug() << "Floor 9 call.";
    lift.click(9);
}

void MainWindow::on_button_floor_10_clicked()
{
    qDebug() << "Floor 10 call.";
    lift.click(10);
}

