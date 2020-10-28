#include "mainwindow.h"
#include <ui_mainwindow.h>
#include <QTimer>
#include <QDateTime>
#include <QStringList>
#include <QStringList>
#include <iostream>
using namespace std;
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
    , mDbConnection("localhost", "SQL SERVER",
                    "root", "", "paises", true){
    ui->setupUi(this);
    mModel = nullptr;
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
    QString error;
    if (!mDbConnection.openDatabase(&error)) {
        cout << "error de conexión a BDD: " << endl;
    }
    // if (mModel == nullptr) {
     //    mModel = new QSqlQueryModel(this);
     //    mModel->setQuery("SELECT * FROM paises");
     //    mModel->query()
    // }
     QSqlQuery query;
     query.exec("SELECT * FROM paises");
     while(query.next()) {
         ui->cmbPaises->addItem(query.value(2).toString());
     }

     //QStringList listPaises;
     //listPaises << "Argentina" << "Estados Unidos" << "España";
     //ui->cmbPaises->addItems(listPaises);
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
