#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QDateTime>
#include <QStringList>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    buildComboBoxPaises();
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start();
}

void MainWindow::showTime() {
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    ui->DigitalClock->setText(timeText);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::buildComboBoxPaises() {
    QStringList listPaises;
    listPaises << "Argentina" << "Estados Unidos" << "España";
    ui->cmbPaises->addItems(listPaises);
    //foreach (const QString pais, listPaises) {
     //
    //}

}

void MainWindow::on_cmbPaises_currentTextChanged(const QString &arg1) {
    QTime time = QTime::currentTime();
    QString timeText = time.toString("hh : mm : ss");
    if (arg1 == "Argentina"){
        ui->DigitalClock->setText("18 : 58 : 10");
    } else if (arg1 == "España"){
        ui->DigitalClock->setText("10 : 10 : 10");
    }

}
