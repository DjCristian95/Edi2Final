#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseconnection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlQueryModel;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void buildComboBoxPaises();

private slots:
    void showTime();
    void on_cmbPaises_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    DataBaseConnection mDbConnection;
    QSqlQueryModel *mModel;
};
#endif // MAINWINDOW_H
