/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_addCamera;
    QComboBox *comboBoxModel;
    QPushButton *pushButton_addModel;
    QComboBox *comboBoxCamera;
    QLabel *label;
    QPushButton *pushButton_removeModel;
    QLabel *label_2;
    QPushButton *pushButton_removeCamera;
    QPushButton *pushButton_setCamera;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_moveModel;
    QDoubleSpinBox *doubleSpinBoxDx;
    QDoubleSpinBox *doubleSpinBoxDy;
    QDoubleSpinBox *doubleSpinBoxDz;
    QLabel *label_7;
    QDoubleSpinBox *doubleSpinBoxKy;
    QDoubleSpinBox *doubleSpinBoxKz;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_scaleModel;
    QDoubleSpinBox *doubleSpinBoxKx;
    QPushButton *pushButton_rotateModel;
    QDoubleSpinBox *doubleSpinBoxOz;
    QDoubleSpinBox *doubleSpinBoxOy;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBoxOx;
    QLabel *label_6;
    QPushButton *pushButton_moveCamera;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBoxDx_c;
    QDoubleSpinBox *doubleSpinBoxDz_c;
    QLabel *label_14;
    QDoubleSpinBox *doubleSpinBoxDy_c;
    QLabel *label_15;
    QLabel *label_16;
    QPushButton *pushButton_rotateCamera;
    QDoubleSpinBox *doubleSpinBoxOy_c;
    QDoubleSpinBox *doubleSpinBoxOz_c;
    QLabel *label_17;
    QDoubleSpinBox *doubleSpinBoxOx_c;
    QGraphicsView *graphicsView;
    QLabel *label_18;
    QLabel *label_19;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1160, 609);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_addCamera = new QPushButton(centralwidget);
        pushButton_addCamera->setObjectName(QString::fromUtf8("pushButton_addCamera"));
        pushButton_addCamera->setGeometry(QRect(830, 40, 91, 23));
        comboBoxModel = new QComboBox(centralwidget);
        comboBoxModel->setObjectName(QString::fromUtf8("comboBoxModel"));
        comboBoxModel->setGeometry(QRect(730, 272, 91, 20));
        pushButton_addModel = new QPushButton(centralwidget);
        pushButton_addModel->setObjectName(QString::fromUtf8("pushButton_addModel"));
        pushButton_addModel->setGeometry(QRect(850, 270, 91, 23));
        comboBoxCamera = new QComboBox(centralwidget);
        comboBoxCamera->setObjectName(QString::fromUtf8("comboBoxCamera"));
        comboBoxCamera->setGeometry(QRect(730, 40, 91, 22));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(730, 250, 111, 21));
        pushButton_removeModel = new QPushButton(centralwidget);
        pushButton_removeModel->setObjectName(QString::fromUtf8("pushButton_removeModel"));
        pushButton_removeModel->setGeometry(QRect(960, 270, 121, 23));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(730, 10, 121, 16));
        pushButton_removeCamera = new QPushButton(centralwidget);
        pushButton_removeCamera->setObjectName(QString::fromUtf8("pushButton_removeCamera"));
        pushButton_removeCamera->setGeometry(QRect(930, 40, 121, 23));
        pushButton_setCamera = new QPushButton(centralwidget);
        pushButton_setCamera->setObjectName(QString::fromUtf8("pushButton_setCamera"));
        pushButton_setCamera->setGeometry(QRect(1060, 40, 91, 23));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(730, 410, 21, 21));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(840, 410, 21, 21));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(950, 410, 21, 21));
        pushButton_moveModel = new QPushButton(centralwidget);
        pushButton_moveModel->setObjectName(QString::fromUtf8("pushButton_moveModel"));
        pushButton_moveModel->setGeometry(QRect(1060, 410, 91, 23));
        doubleSpinBoxDx = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDx->setObjectName(QString::fromUtf8("doubleSpinBoxDx"));
        doubleSpinBoxDx->setGeometry(QRect(760, 410, 71, 22));
        doubleSpinBoxDx->setDecimals(1);
        doubleSpinBoxDx->setMinimum(-500.000000000000000);
        doubleSpinBoxDx->setMaximum(500.000000000000000);
        doubleSpinBoxDx->setValue(10.000000000000000);
        doubleSpinBoxDy = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDy->setObjectName(QString::fromUtf8("doubleSpinBoxDy"));
        doubleSpinBoxDy->setGeometry(QRect(870, 410, 71, 22));
        doubleSpinBoxDy->setDecimals(1);
        doubleSpinBoxDy->setMinimum(-500.000000000000000);
        doubleSpinBoxDy->setMaximum(500.000000000000000);
        doubleSpinBoxDy->setValue(20.000000000000000);
        doubleSpinBoxDz = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDz->setObjectName(QString::fromUtf8("doubleSpinBoxDz"));
        doubleSpinBoxDz->setGeometry(QRect(980, 410, 71, 21));
        doubleSpinBoxDz->setDecimals(1);
        doubleSpinBoxDz->setMinimum(-500.000000000000000);
        doubleSpinBoxDz->setMaximum(500.000000000000000);
        doubleSpinBoxDz->setValue(30.000000000000000);
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(950, 450, 21, 21));
        doubleSpinBoxKy = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxKy->setObjectName(QString::fromUtf8("doubleSpinBoxKy"));
        doubleSpinBoxKy->setGeometry(QRect(870, 450, 71, 22));
        doubleSpinBoxKy->setDecimals(1);
        doubleSpinBoxKy->setMinimum(-500.000000000000000);
        doubleSpinBoxKy->setMaximum(500.000000000000000);
        doubleSpinBoxKy->setValue(2.000000000000000);
        doubleSpinBoxKz = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxKz->setObjectName(QString::fromUtf8("doubleSpinBoxKz"));
        doubleSpinBoxKz->setGeometry(QRect(980, 450, 71, 21));
        doubleSpinBoxKz->setDecimals(1);
        doubleSpinBoxKz->setMinimum(-500.000000000000000);
        doubleSpinBoxKz->setMaximum(500.000000000000000);
        doubleSpinBoxKz->setValue(2.000000000000000);
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(840, 450, 21, 21));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(730, 450, 21, 21));
        pushButton_scaleModel = new QPushButton(centralwidget);
        pushButton_scaleModel->setObjectName(QString::fromUtf8("pushButton_scaleModel"));
        pushButton_scaleModel->setGeometry(QRect(1060, 450, 91, 23));
        doubleSpinBoxKx = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxKx->setObjectName(QString::fromUtf8("doubleSpinBoxKx"));
        doubleSpinBoxKx->setGeometry(QRect(760, 450, 71, 22));
        doubleSpinBoxKx->setDecimals(1);
        doubleSpinBoxKx->setMinimum(-500.000000000000000);
        doubleSpinBoxKx->setMaximum(500.000000000000000);
        doubleSpinBoxKx->setValue(2.000000000000000);
        pushButton_rotateModel = new QPushButton(centralwidget);
        pushButton_rotateModel->setObjectName(QString::fromUtf8("pushButton_rotateModel"));
        pushButton_rotateModel->setGeometry(QRect(1060, 490, 91, 23));
        doubleSpinBoxOz = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOz->setObjectName(QString::fromUtf8("doubleSpinBoxOz"));
        doubleSpinBoxOz->setGeometry(QRect(980, 490, 71, 21));
        doubleSpinBoxOz->setDecimals(1);
        doubleSpinBoxOz->setMinimum(-500.000000000000000);
        doubleSpinBoxOz->setMaximum(500.000000000000000);
        doubleSpinBoxOz->setValue(30.000000000000000);
        doubleSpinBoxOy = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOy->setObjectName(QString::fromUtf8("doubleSpinBoxOy"));
        doubleSpinBoxOy->setGeometry(QRect(870, 490, 71, 22));
        doubleSpinBoxOy->setDecimals(1);
        doubleSpinBoxOy->setMinimum(-500.000000000000000);
        doubleSpinBoxOy->setMaximum(500.000000000000000);
        doubleSpinBoxOy->setValue(20.000000000000000);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(730, 490, 21, 21));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(840, 490, 21, 21));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(950, 490, 21, 21));
        doubleSpinBoxOx = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOx->setObjectName(QString::fromUtf8("doubleSpinBoxOx"));
        doubleSpinBoxOx->setGeometry(QRect(760, 490, 71, 22));
        doubleSpinBoxOx->setDecimals(1);
        doubleSpinBoxOx->setMinimum(-500.000000000000000);
        doubleSpinBoxOx->setMaximum(500.000000000000000);
        doubleSpinBoxOx->setValue(10.000000000000000);
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(840, 150, 21, 21));
        pushButton_moveCamera = new QPushButton(centralwidget);
        pushButton_moveCamera->setObjectName(QString::fromUtf8("pushButton_moveCamera"));
        pushButton_moveCamera->setGeometry(QRect(1060, 150, 91, 23));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(730, 150, 21, 21));
        doubleSpinBoxDx_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDx_c->setObjectName(QString::fromUtf8("doubleSpinBoxDx_c"));
        doubleSpinBoxDx_c->setGeometry(QRect(760, 150, 71, 22));
        doubleSpinBoxDx_c->setDecimals(1);
        doubleSpinBoxDx_c->setMinimum(-500.000000000000000);
        doubleSpinBoxDx_c->setMaximum(500.000000000000000);
        doubleSpinBoxDx_c->setValue(10.000000000000000);
        doubleSpinBoxDz_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDz_c->setObjectName(QString::fromUtf8("doubleSpinBoxDz_c"));
        doubleSpinBoxDz_c->setGeometry(QRect(981, 150, 71, 21));
        doubleSpinBoxDz_c->setDecimals(1);
        doubleSpinBoxDz_c->setMinimum(-500.000000000000000);
        doubleSpinBoxDz_c->setMaximum(500.000000000000000);
        doubleSpinBoxDz_c->setValue(30.000000000000000);
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(950, 150, 21, 21));
        doubleSpinBoxDy_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxDy_c->setObjectName(QString::fromUtf8("doubleSpinBoxDy_c"));
        doubleSpinBoxDy_c->setGeometry(QRect(870, 150, 71, 22));
        doubleSpinBoxDy_c->setDecimals(1);
        doubleSpinBoxDy_c->setMinimum(-500.000000000000000);
        doubleSpinBoxDy_c->setMaximum(500.000000000000000);
        doubleSpinBoxDy_c->setValue(20.000000000000000);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(840, 190, 21, 21));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(730, 190, 21, 21));
        pushButton_rotateCamera = new QPushButton(centralwidget);
        pushButton_rotateCamera->setObjectName(QString::fromUtf8("pushButton_rotateCamera"));
        pushButton_rotateCamera->setGeometry(QRect(1060, 190, 91, 23));
        doubleSpinBoxOy_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOy_c->setObjectName(QString::fromUtf8("doubleSpinBoxOy_c"));
        doubleSpinBoxOy_c->setGeometry(QRect(870, 190, 71, 22));
        doubleSpinBoxOy_c->setDecimals(1);
        doubleSpinBoxOy_c->setMinimum(-500.000000000000000);
        doubleSpinBoxOy_c->setMaximum(500.000000000000000);
        doubleSpinBoxOy_c->setValue(20.000000000000000);
        doubleSpinBoxOz_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOz_c->setObjectName(QString::fromUtf8("doubleSpinBoxOz_c"));
        doubleSpinBoxOz_c->setGeometry(QRect(980, 190, 71, 21));
        doubleSpinBoxOz_c->setDecimals(1);
        doubleSpinBoxOz_c->setMinimum(-500.000000000000000);
        doubleSpinBoxOz_c->setMaximum(500.000000000000000);
        doubleSpinBoxOz_c->setValue(30.000000000000000);
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(950, 190, 21, 21));
        doubleSpinBoxOx_c = new QDoubleSpinBox(centralwidget);
        doubleSpinBoxOx_c->setObjectName(QString::fromUtf8("doubleSpinBoxOx_c"));
        doubleSpinBoxOx_c->setGeometry(QRect(760, 190, 71, 22));
        doubleSpinBoxOx_c->setDecimals(1);
        doubleSpinBoxOx_c->setMinimum(-500.000000000000000);
        doubleSpinBoxOx_c->setMaximum(500.000000000000000);
        doubleSpinBoxOx_c->setValue(10.000000000000000);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 721, 601));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(850, 110, 181, 19));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(850, 360, 181, 20));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_addCamera->setText(QApplication::translate("MainWindow", "Add Camera", nullptr));
        pushButton_addModel->setText(QApplication::translate("MainWindow", "Add Model", nullptr));
        label->setText(QApplication::translate("MainWindow", "Choose model:", nullptr));
        pushButton_removeModel->setText(QApplication::translate("MainWindow", "Remove Model", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Choose camera:", nullptr));
        pushButton_removeCamera->setText(QApplication::translate("MainWindow", "Remove Camera", nullptr));
        pushButton_setCamera->setText(QApplication::translate("MainWindow", "Set Camera", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        pushButton_moveModel->setText(QApplication::translate("MainWindow", "Move", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "kz:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "ky:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "kx:", nullptr));
        pushButton_scaleModel->setText(QApplication::translate("MainWindow", "Scale", nullptr));
        pushButton_rotateModel->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "ox:", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "oy:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "oz:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "dy:", nullptr));
        pushButton_moveCamera->setText(QApplication::translate("MainWindow", "Move", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "dx:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "dz:", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "oy:", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "ox:", nullptr));
        pushButton_rotateCamera->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "oz:", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "Camera transformations", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Model transformations", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
