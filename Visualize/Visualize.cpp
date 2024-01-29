#include "stdafx.h"
#include "Visualize.h"
#include "OpenGLWindow.h"
#include "Line.h"
#include "vector"


Visualize::Visualize(QWindow* parent) : QMainWindow(nullptr)
{
    setupUi();

    connect(mPushButton5, &QPushButton::clicked, this, &Visualize::bezier);
    connect(mPushButton6, &QPushButton::clicked, this, &Visualize::hermite);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
    connect(mColorButton, &QPushButton::clicked, mRenderer, &OpenGLWindow::selectColor);
}

Visualize::~Visualize()
{

}


//Implimentation of UI
void Visualize::setupUi() {
    resize(1530, 785);

    mPushButton5 = new QPushButton(this);
    mPushButton5->setObjectName("pushButton");
    mPushButton5->setText("Bezeir Curve");
    mPushButton5->setGeometry(QRect(1100, 80, 200, 30));

    mPushButton6 = new QPushButton(this);
    mPushButton6->setObjectName("pushButton");
    mPushButton6->setText("Hermite Curve");
    mPushButton6->setGeometry(QRect(1330, 80, 200, 30));

    mLabel6 = new QLabel(this);
    mLabel6->setObjectName("label");
    mLabel6->setText("X1");
    mLabel6->setGeometry(QRect(1130, 170, 85, 30));

    mLineEdit6 = new QLineEdit(this);
    mLineEdit6->setObjectName("lineEdit_7");
    mLineEdit6->setGeometry(QRect(1100, 200, 85, 30));
    mLabel7 = new QLabel(this);
    mLabel7->setObjectName("label");
    mLabel7->setText("Y1");
    mLabel7->setGeometry(QRect(1230, 170, 85, 30));

    mLineEdit7 = new QLineEdit(this);
    mLineEdit7->setObjectName("lineEdit_8");
    mLineEdit7->setGeometry(QRect(1200, 200, 85, 30));

    mLabel8 = new QLabel(this);
    mLabel8->setObjectName("label");
    mLabel8->setText("X2");
    mLabel8->setGeometry(QRect(1130, 270, 85, 30));

    mLineEdit8 = new QLineEdit(this);
    mLineEdit8->setObjectName("lineEdit_9");
    mLineEdit8->setGeometry(QRect(1100, 300, 85, 30));
    mLabel9 = new QLabel(this);
    mLabel9->setObjectName("label");
    mLabel9->setText("Y2");
    mLabel9->setGeometry(QRect(1230, 270, 85, 30));

    mLineEdit9 = new QLineEdit(this);
    mLineEdit9->setObjectName("lineEdit_10");
    mLineEdit9->setGeometry(QRect(1200, 300, 85, 30));

    mLabel10 = new QLabel(this);
    mLabel10->setObjectName("label");
    mLabel10->setText("X3");
    mLabel10->setGeometry(QRect(1130, 370, 85, 30));

    mLineEdit10 = new QLineEdit(this);
    mLineEdit10->setObjectName("lineEdit_11");
    mLineEdit10->setGeometry(QRect(1100, 400, 85, 30));
    mLabel11 = new QLabel(this);
    mLabel11->setObjectName("label");
    mLabel11->setText("Y3");
    mLabel11->setGeometry(QRect(1230, 370, 85, 30));

    mLineEdit11 = new QLineEdit(this);
    mLineEdit11->setObjectName("lineEdit_12");
    mLineEdit11->setGeometry(QRect(1200, 400, 85, 30));

    mLabel12 = new QLabel(this);
    mLabel12->setObjectName("label");
    mLabel12->setText("X4");
    mLabel12->setGeometry(QRect(1130, 470, 85, 30));

    mLineEdit12 = new QLineEdit(this);
    mLineEdit12->setObjectName("lineEdit_13");
    mLineEdit12->setGeometry(QRect(1100, 500, 85, 30));

    mLabel13 = new QLabel(this);
    mLabel13->setObjectName("label");
    mLabel13->setText("Y4");
    mLabel13->setGeometry(QRect(1230, 470, 85, 30));

    mLineEdit13 = new QLineEdit(this);
    mLineEdit13->setObjectName("lineEdit_13");
    mLineEdit13->setGeometry(QRect(1200, 500, 85, 30));

    mColorButton = new QPushButton(this);
    mColorButton->setObjectName("pushButton");
    mColorButton->setText("Choose Color");
    mColorButton->setGeometry(QRect(1100, 120, 200, 30));


    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(90, 140, 1000, 600));

    setWindowTitle(QCoreApplication::translate("Bezier and Hermite", "Bezier and Hermite Curve", nullptr));

}

void Visualize::showColorDialog()
{
    QColor color = QColorDialog::getColor(Qt::white, this, "Select Color");
    if (color.isValid())
    {
        // Do something with the selected color
        qDebug() << "Selected Color: " << color;
    }
}


void Visualize::bezier() {
    float x1 = mLineEdit6->text().toFloat();
    float y1 = mLineEdit7->text().toFloat();
    float x2 = mLineEdit8->text().toFloat();
    float y2 = mLineEdit9->text().toFloat();
    float x3 = mLineEdit10->text().toFloat();
    float y3 = mLineEdit11->text().toFloat();
    float x4 = mLineEdit12->text().toFloat();
    float y4 = mLineEdit13->text().toFloat();

    std::vector<Point2D> v;
    v.push_back(Point2D(x1, y1));
    v.push_back(Point2D(x2, y2));
    v.push_back(Point2D(x3, y3));
    v.push_back(Point2D(x4, y4));
    mRenderer->bezierCurve(v);
}

void Visualize::hermite() {
    float x1 = mLineEdit6->text().toFloat();
    float y1 = mLineEdit7->text().toFloat();
    float x2 = mLineEdit8->text().toFloat();
    float y2 = mLineEdit9->text().toFloat();
    float x3 = mLineEdit10->text().toFloat();
    float y3 = mLineEdit11->text().toFloat();
    float x4 = mLineEdit12->text().toFloat();
    float y4 = mLineEdit13->text().toFloat();

    std::vector<Point2D> v;
    v.push_back(Point2D(x1, y1));
    v.push_back(Point2D(x2, y2));
    v.push_back(Point2D(x3, y3));
    v.push_back(Point2D(x4, y4));
    mRenderer->hermiteCurve(v);
}