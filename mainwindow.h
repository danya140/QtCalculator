#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void listeners();

private slots:
    void on_But1_clicked();
    void on_But2_clicked();
    void on_But3_clicked();
    void on_But4_clicked();
    void on_But5_clicked();
    void on_But6_clicked();
    void on_But7_clicked();
    void on_But8_clicked();
    void on_But9_clicked();
    void on_But0_clicked();

    void on_delBut_clicked();

    void on_plusBut_clicked();
    void on_minusBut_clicked();
    void on_multiplBut_clicked();
    void on_devideBut_clicked();
    void on_sqrtBut_clicked();
    void on_expBut_clicked();
    void on_sinBut_clicked();
    void on_cosBut_clicked();

    void on_solveBut_clicked();

    void on_play_clicked();

private:
    void parse();
    Ui::MainWindow *ui;
    QString expr = "";
};

#endif // MAINWINDOW_H
