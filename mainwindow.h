#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "joueurs.h"
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

    void on_supp_id_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_12_clicked();

    void on_rech_clicked();

    void on_pushButton_8_clicked();//nom

    void on_pushButton_9_clicked();//prenom

    void on_pushButton_13_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_textEdited(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Joueurs J;
};

#endif // MAINWINDOW_H
