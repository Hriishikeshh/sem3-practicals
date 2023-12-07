/********************************************************************************
** Form generated from reading UI file 'pixel.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXEL_H
#define UI_PIXEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pixel
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QTextEdit *textEdit_3;
    QTextEdit *textEdit_4;
    QTextEdit *textEdit_5;
    QTextEdit *textEdit_6;
    QTextEdit *textEdit_7;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *pixel)
    {
        if (pixel->objectName().isEmpty())
            pixel->setObjectName("pixel");
        pixel->resize(800, 600);
        centralwidget = new QWidget(pixel);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 30, 381, 371));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(410, 30, 58, 19));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(410, 70, 58, 19));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 110, 58, 19));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(410, 170, 58, 19));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(410, 210, 58, 19));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(420, 260, 58, 19));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(410, 320, 61, 20));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(480, 10, 104, 41));
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(480, 60, 104, 41));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(480, 110, 104, 31));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(480, 150, 104, 41));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(480, 200, 104, 41));
        textEdit_6 = new QTextEdit(centralwidget);
        textEdit_6->setObjectName("textEdit_6");
        textEdit_6->setGeometry(QRect(480, 250, 104, 41));
        textEdit_7 = new QTextEdit(centralwidget);
        textEdit_7->setObjectName("textEdit_7");
        textEdit_7->setGeometry(QRect(480, 310, 104, 41));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(490, 380, 80, 27));
        pixel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(pixel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        pixel->setMenuBar(menubar);
        statusbar = new QStatusBar(pixel);
        statusbar->setObjectName("statusbar");
        pixel->setStatusBar(statusbar);

        retranslateUi(pixel);

        QMetaObject::connectSlotsByName(pixel);
    } // setupUi

    void retranslateUi(QMainWindow *pixel)
    {
        pixel->setWindowTitle(QCoreApplication::translate("pixel", "pixel", nullptr));
        label->setText(QCoreApplication::translate("pixel", "TextLabel", nullptr));
        label_2->setText(QCoreApplication::translate("pixel", "x1", nullptr));
        label_3->setText(QCoreApplication::translate("pixel", "y1", nullptr));
        label_4->setText(QCoreApplication::translate("pixel", "x2", nullptr));
        label_5->setText(QCoreApplication::translate("pixel", "y2", nullptr));
        label_6->setText(QCoreApplication::translate("pixel", "xc", nullptr));
        label_7->setText(QCoreApplication::translate("pixel", "yc", nullptr));
        label_8->setText(QCoreApplication::translate("pixel", "r", nullptr));
        pushButton->setText(QCoreApplication::translate("pixel", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pixel: public Ui_pixel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXEL_H
