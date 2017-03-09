#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logic.h"
#include <QMediaPlayer>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

logic lg;

void MainWindow::parse(){
    char delim=lg.getDelimiter();
    if(delim=='s' || delim=='c' || delim == 'q'){

        if(delim == 'q'){
            expr = expr.replace(QString("√"),QString("q"));
        }else{
            delim='(';
        }

        QStringList tmp = expr.split(delim);
        if(delim == 'q'){
            QString right = tmp.at(1);
            //right.remove(0,1);
            lg.setRightNum(right.toDouble());
        } else{
            QString right = tmp.at(1);
            right.chop(1);
            lg.setRightNum(right.toDouble());
        }
    } else{
        QStringList tmp = expr.split(delim);
        lg.setLeftNum(tmp.at(0).toDouble());
        lg.setRightNum(tmp.at(1).toDouble());
    }


}


//Buttons listeners start here
void MainWindow::on_But1_clicked(){
    ui->textEdit->setText(expr+="1");
}

void MainWindow::on_But2_clicked(){
    ui->textEdit->setText(expr+="2");
}
void MainWindow::on_But3_clicked(){
    ui->textEdit->setText(expr+="3");
}

void MainWindow::on_But4_clicked()
{
    ui->textEdit->setText(expr+="4");
}

void MainWindow::on_But5_clicked()
{
    ui->textEdit->setText(expr+="5");
}

void MainWindow::on_But6_clicked()
{
    ui->textEdit->setText(expr+="6");
}

void MainWindow::on_But7_clicked()
{
    ui->textEdit->setText(expr+="7");
}

void MainWindow::on_But8_clicked()
{
    ui->textEdit->setText(expr+="8");
}

void MainWindow::on_But9_clicked()
{
    ui->textEdit->setText(expr+="9");
}

void MainWindow::on_But0_clicked()
{
    ui->textEdit->setText(expr+="0");
}

void MainWindow::on_delBut_clicked()
{
    expr.chop(1);
    ui->textEdit->setText(expr);
}

void MainWindow::on_plusBut_clicked()
{
    ui->textEdit->setText(expr+="+");
    lg.setDelimiter('+');
}

void MainWindow::on_minusBut_clicked()
{
    ui->textEdit->setText(expr+="-");
    lg.setDelimiter('-');
}

void MainWindow::on_multiplBut_clicked()
{
    ui->textEdit->setText(expr+="*");
    lg.setDelimiter('*');
}

void MainWindow::on_devideBut_clicked()
{
    ui->textEdit->setText(expr+="/");
    lg.setDelimiter('/');
}

void MainWindow::on_sqrtBut_clicked()
{
    ui->textEdit->setText(expr="√"+expr);
    lg.setDelimiter('q');
}

void MainWindow::on_expBut_clicked()
{
    ui->textEdit->setText(expr+="^");
    lg.setDelimiter('^');
}

void MainWindow::on_sinBut_clicked()
{
    ui->textEdit->setText(expr="sin("+expr+")");
    lg.setDelimiter('s');
}

void MainWindow::on_cosBut_clicked()
{
    ui->textEdit->setText(expr="cos("+expr+")");
    lg.setDelimiter('c');
}

void MainWindow::on_solveBut_clicked()
{
    expr=ui->textEdit->toPlainText();
    parse();
    lg.calc();
    expr=std::to_string(lg.getResult()).c_str();
    ui->textEdit->setText(expr);
}

void MainWindow::on_play_clicked()
{
        QMediaPlayer *player = new QMediaPlayer;
        player->setMedia(QUrl("qrc:/drDRE.mp3"));
        player->setVolume(50);
        player->play();
}
