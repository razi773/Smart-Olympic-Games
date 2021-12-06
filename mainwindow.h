#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"employe.h"
#include"admin.h"
#include "arduino.h"
#include "joueurs.h"
#include "jeux.h"

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

    void on_pushButton_12_clicked();

    void on_supp_id_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_rech_3_textChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_3_clicked();
     void verif_mdp_arduino();

     void on_pushButton_36_clicked();

     void on_pushButton_38_clicked();

     void on_pushButton_17_clicked();

     void on_supp_id_2_clicked();

     void on_pushButton_25_clicked();

     void on_pushButton_24_clicked();

     void on_pushButton_23_clicked();

     void on_pushButton_18_clicked();

     void on_rech_4_clicked();

     void on_pushButton_22_clicked();

     void on_pushButton_21_clicked();

     void on_pushButton_19_clicked();

     void on_rech_5_cursorPositionChanged(int arg1, int arg2);

     void on_lineEdit_2_textEdited(const QString &arg1);

     void on_rech_5_textEdited(const QString &arg1);

     void on_pushButton_26_clicked();

     void on_pushButton_27_clicked();

     void on_pushButton_31_clicked();

     void on_pushButton_41_clicked();

     void on_pushButton_33_clicked();

     void on_le_id_cherch_textEdited(const QString &arg1);

     void on_le_id_cherch_cursorPositionChanged(int arg1, int arg2);

     void on_comboBox_6_activated(const QString &arg1);

     void on_pushButton_32_clicked();

     void on_pushButton_29_clicked();

     void on_pushButton_40_clicked();

     void on_pushButton_28_clicked();

     void on_pushButton_39_clicked();

     void on_pushButton_35_clicked();

private:
    Ui::MainWindow *ui;
    historique tmphistorique ;
    ADMIN A;
    QByteArray data; // variable contenant les données reçues
    Jeux j2;
    Arduino A1;
};

#endif // MAINWINDOW_H
