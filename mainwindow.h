#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QStringListModel>
#include "Groebner.h"
#include "Polynomial.h"

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
    void on_addPolyButton_clicked();

    void on_calculate_clicked();


    void on_variableButton_clicked();

    void on_number0Button_clicked();
    void on_number1Button_clicked();
    void on_number2Button_clicked();
    void on_number3Button_clicked();
    void on_number4Button_clicked();
    void on_number5Button_clicked();
    void on_number6Button_clicked();
    void on_number7Button_clicked();
    void on_number8Button_clicked();
    void on_number9Button_clicked();

    void on_decimalButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_multiplyButton_clicked();

    void on_divideButton_clicked();

    void on_rightBracketButton_clicked();

    void on_leftBracketButton_clicked();

    void on_exponentButton_clicked();

    void on_ACbutton_clicked();

private:
    Ui::MainWindow *ui;
    QStringListModel *model;
    QStringList list;
    Groebner g;
};

#endif // MAINWINDOW_H
