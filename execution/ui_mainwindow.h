/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_3;
    QLabel *label_8;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_3;
    QWidget *tab;
    QGroupBox *groupBox;
    QLineEdit *le_nom;
    QLineEdit *le_age;
    QLineEdit *le_email;
    QLineEdit *le_id;
    QLabel *label_2;
    QLabel *label_5;
    QLabel *label_11;
    QLineEdit *le_prenom;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_14;
    QLabel *label_15;
    QComboBox *comboBox_3;
    QPushButton *pushButton_6;
    QPushButton *supp_id;
    QPushButton *rech;
    QPushButton *pushButton_12;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QPushButton *pushButton_11;
    QLabel *label_4;
    QPushButton *pushButton_10;
    QTableView *tableView;
    QLineEdit *supp;
    QLineEdit *rech_2;
    QLineEdit *le_pays;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QLabel *label_7;
    QLineEdit *fichier;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1249, 753);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 1181, 651));
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(0, 0, 1041, 561));
        label_8->setPixmap(QPixmap(QString::fromUtf8("../game day.jpg")));
        pushButton_5 = new QPushButton(tab_3);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(470, 390, 93, 28));
        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(470, 350, 93, 28));
        pushButton_2 = new QPushButton(tab_3);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(470, 310, 93, 28));
        pushButton_7 = new QPushButton(tab_3);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(470, 430, 93, 28));
        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(470, 270, 93, 28));
        tabWidget->addTab(tab_3, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 1131, 581));
        le_nom = new QLineEdit(groupBox);
        le_nom->setObjectName(QStringLiteral("le_nom"));
        le_nom->setGeometry(QRect(120, 90, 113, 22));
        le_age = new QLineEdit(groupBox);
        le_age->setObjectName(QStringLiteral("le_age"));
        le_age->setGeometry(QRect(120, 180, 113, 22));
        le_email = new QLineEdit(groupBox);
        le_email->setObjectName(QStringLiteral("le_email"));
        le_email->setGeometry(QRect(120, 220, 113, 22));
        le_id = new QLineEdit(groupBox);
        le_id->setObjectName(QStringLiteral("le_id"));
        le_id->setGeometry(QRect(120, 50, 113, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 90, 56, 16));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 220, 51, 20));
        label_5->setStyleSheet(QStringLiteral("FFFFFF"));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 180, 56, 16));
        le_prenom = new QLineEdit(groupBox);
        le_prenom->setObjectName(QStringLiteral("le_prenom"));
        le_prenom->setGeometry(QRect(120, 130, 113, 22));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 56, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 130, 56, 16));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(350, 370, 93, 28));
        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(20, 310, 56, 16));
        label_15 = new QLabel(groupBox);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(880, 50, 56, 16));
        comboBox_3 = new QComboBox(groupBox);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setGeometry(QRect(120, 310, 151, 22));
        pushButton_6 = new QPushButton(groupBox);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(350, 410, 93, 28));
        supp_id = new QPushButton(groupBox);
        supp_id->setObjectName(QStringLiteral("supp_id"));
        supp_id->setGeometry(QRect(350, 450, 93, 28));
        rech = new QPushButton(groupBox);
        rech->setObjectName(QStringLiteral("rech"));
        rech->setGeometry(QRect(730, 270, 93, 28));
        pushButton_12 = new QPushButton(groupBox);
        pushButton_12->setObjectName(QStringLiteral("pushButton_12"));
        pushButton_12->setGeometry(QRect(990, 390, 93, 28));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 350, 91, 16));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(120, 350, 161, 22));
        pushButton_11 = new QPushButton(groupBox);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(580, 270, 93, 28));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 260, 56, 16));
        pushButton_10 = new QPushButton(groupBox);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(350, 490, 93, 28));
        tableView = new QTableView(groupBox);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(450, 350, 521, 192));
        supp = new QLineEdit(groupBox);
        supp->setObjectName(QStringLiteral("supp"));
        supp->setGeometry(QRect(230, 450, 101, 21));
        rech_2 = new QLineEdit(groupBox);
        rech_2->setObjectName(QStringLiteral("rech_2"));
        rech_2->setGeometry(QRect(730, 310, 111, 21));
        le_pays = new QLineEdit(groupBox);
        le_pays->setObjectName(QStringLiteral("le_pays"));
        le_pays->setGeometry(QRect(120, 260, 113, 22));
        pushButton_8 = new QPushButton(groupBox);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(990, 430, 93, 28));
        pushButton_9 = new QPushButton(groupBox);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(990, 470, 93, 28));
        pushButton_13 = new QPushButton(groupBox);
        pushButton_13->setObjectName(QStringLiteral("pushButton_13"));
        pushButton_13->setGeometry(QRect(820, 90, 161, 28));
        pushButton_14 = new QPushButton(groupBox);
        pushButton_14->setObjectName(QStringLiteral("pushButton_14"));
        pushButton_14->setGeometry(QRect(820, 130, 161, 28));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 20, 1101, 551));
        label_7->setPixmap(QPixmap(QString::fromUtf8("../Hnet.com-image.jpg")));
        fichier = new QLineEdit(groupBox);
        fichier->setObjectName(QStringLiteral("fichier"));
        fichier->setGeometry(QRect(680, 130, 113, 22));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(860, 310, 113, 22));
        label_7->raise();
        le_nom->raise();
        le_age->raise();
        le_email->raise();
        le_id->raise();
        label_2->raise();
        label_5->raise();
        label_11->raise();
        le_prenom->raise();
        label->raise();
        label_3->raise();
        pushButton->raise();
        label_14->raise();
        label_15->raise();
        comboBox_3->raise();
        pushButton_6->raise();
        supp_id->raise();
        rech->raise();
        pushButton_12->raise();
        label_6->raise();
        comboBox_2->raise();
        pushButton_11->raise();
        label_4->raise();
        pushButton_10->raise();
        tableView->raise();
        supp->raise();
        rech_2->raise();
        le_pays->raise();
        pushButton_8->raise();
        pushButton_9->raise();
        pushButton_13->raise();
        pushButton_14->raise();
        fichier->raise();
        lineEdit->raise();
        tabWidget->addTab(tab, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1249, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des Clients", Q_NULLPTR));
        label_8->setText(QString());
        pushButton_5->setText(QApplication::translate("MainWindow", "Stades", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Spectateurs", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Employee", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "Jeux", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Joueurs", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Ajout Joueurs", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "Email", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Prenom", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "Sexe", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "Fichier", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choisir votre Sexe", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Homme", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Femme", Q_NULLPTR)
        );
        pushButton_6->setText(QApplication::translate("MainWindow", "Actualiser", Q_NULLPTR));
        supp_id->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        rech->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        pushButton_12->setText(QApplication::translate("MainWindow", "Trier ID", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Type de Sport", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Choisir votre Sport", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Athletisme", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Boxe", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Gymnastique", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Natation", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Escrime", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Cyclisme", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Esclavade Sportive", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Voile", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tir", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Tennis", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Trampoline", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Plongons", Q_NULLPTR)
        );
        pushButton_11->setText(QApplication::translate("MainWindow", "Statistique", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Pays", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("MainWindow", "Trier Nom", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("MainWindow", "Trier Prenom", Q_NULLPTR));
        pushButton_13->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer PDF", Q_NULLPTR));
        pushButton_14->setText(QApplication::translate("MainWindow", "G\303\251n\303\251rer Fichier Excel", Q_NULLPTR));
        label_7->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Ajouter Joueurs", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
