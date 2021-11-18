#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"employe.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    //void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_imprimer_clicked();

    void on_pushButton_9_clicked();

    void on_pushbutton_13_clicked();

    //void on_pushButton_3_clicked();

    void on_retour_2_clicked();

    void on_comboBox_2_activated(const QString &arg1);

    //void on_rech_2_cursorPositionChanged(int arg1, int arg2);

    void on_rech_2_textChanged(const QString &arg1);

    void on_comboBox_activated();

    void on_Push_Button_Afficher_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    historique tmphistorique ;
};

#endif // MAINWINDOW_H
