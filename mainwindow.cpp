#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <iostream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->polyEdit->setFocus();
    model = new QStringListModel(this);
    Polynomial p1 = Polynomial("(X.0)^2+1(X.1)^2-1");
    g.addPolynomial(p1);
    Polynomial p2 = Polynomial("(X.0)(X.1)");
    g.addPolynomial(p2);
    Polynomial p3 = Polynomial("(X.1)^3-1(X.1)");
    g.addPolynomial(p3);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_addPolyButton_clicked()
{
    list << ui->polyEdit->text();
    std::string poly = ui->polyEdit->text().toStdString();
    Polynomial p = Polynomial(poly);
    g.addPolynomial(p);
    model->setStringList(list);
    ui->polyList->setModel(model);
    ui->polyEdit->setText("");
}

void MainWindow::on_calculate_clicked()
{
    g.buchberger();
    ui->answerEdit->setText(g.toQString());
}


void MainWindow::on_variableButton_clicked()
{
    ui->polyEdit->setText(ui->polyEdit->text() + "(X.)");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->cursorPosition()-1);
}
/*
    TODO: Clean this code up
*/
void MainWindow::on_number0Button_clicked()
{
    ui->polyEdit->insert("0");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number1Button_clicked()
{
    ui->polyEdit->insert("1");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number2Button_clicked()
{
    ui->polyEdit->insert("2");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number3Button_clicked()
{
    ui->polyEdit->insert("3");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number4Button_clicked()
{
    ui->polyEdit->insert("4");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}
void MainWindow::on_number5Button_clicked()
{
    ui->polyEdit->insert("5");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number6Button_clicked()
{
    ui->polyEdit->insert("6");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}
void MainWindow::on_number7Button_clicked()
{
    ui->polyEdit->insert("7");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_number8Button_clicked()
{
    ui->polyEdit->insert("8");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}
void MainWindow::on_number9Button_clicked()
{
    ui->polyEdit->insert("9");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}
void MainWindow::on_decimalButton_clicked()
{
    ui->polyEdit->insert(".");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_plusButton_clicked()
{
    ui->polyEdit->insert("+");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_minusButton_clicked()
{
    ui->polyEdit->insert("-");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_multiplyButton_clicked()
{
    ui->polyEdit->insert("*");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_divideButton_clicked()
{
    ui->polyEdit->insert("/");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_rightBracketButton_clicked()
{
    ui->polyEdit->insert(")");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_leftBracketButton_clicked()
{
    ui->polyEdit->insert("(");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_exponentButton_clicked()
{
    ui->polyEdit->insert("^");
    ui->polyEdit->setFocus();
    ui->polyEdit->setCursorPosition(ui->polyEdit->text().length());
}

void MainWindow::on_ACbutton_clicked()
{
    g.clear();
    list.clear();
    model->setStringList(list);
    ui->polyList->setModel(model);
    ui->answerEdit->clear();
    ui->polyEdit->clear();
}
