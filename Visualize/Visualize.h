#pragma once

#include <QtWidgets/QMainWindow>
#include "Visualize.h"
#include "OpenGLWindow.h"
//#include "SymmetricDDA.h"

class OpenGLWindow;

class Visualize : public QMainWindow
{
    Q_OBJECT

public:
    Visualize(QWindow* parent = nullptr);
    ~Visualize();

private:
    void setupUi();
    void showColorDialog();

public:
    QVector<QVector2D> mPixelVertices;
    QVector<GLfloat>   mVertices;
    QVector<GLfloat>   mColors;

private:
    OpenGLWindow* mRenderer;

    QPushButton* mPushButton1;
    QPushButton* mPushButton2;
    QPushButton* mPushButton3;
    QPushButton* mPushButton4;
    QPushButton* mPushButton5;
    QPushButton* mPushButton6;
    QPushButton* mColorButton;
    QLineEdit* mLineEdit1;
    QLineEdit* mLineEdit2;
    QLineEdit* mLineEdit3;
    QLineEdit* mLineEdit4;
    QLineEdit* mLineEdit5;
    QLineEdit* mLineEdit6;
    QLineEdit* mLineEdit7;
    QLineEdit* mLineEdit8;
    QLineEdit* mLineEdit9;
    QLineEdit* mLineEdit10;
    QLineEdit* mLineEdit11;
    QLineEdit* mLineEdit12;
    QLineEdit* mLineEdit13;
    QLabel* mLabel1;
    QLabel* mLabel2;
    QLabel* mLabel3;
    QLabel* mLabel4;
    QLabel* mLabel5;
    QLabel* mLabel6;
    QLabel* mLabel7;
    QLabel* mLabel8;
    QLabel* mLabel9;
    QLabel* mLabel10;
    QLabel* mLabel11;
    QLabel* mLabel12;
    QLabel* mLabel13;


public slots:

    void bezier();
    void hermite();
};