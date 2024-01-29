#include "stdafx.h"
#include "OpenGLWindow.h"
#include <QOpenGLContext>
#include <QOpenGLPaintDevice>
#include <QOpenGLShaderProgram>
#include <QPainter>

#include "BezierCurve.h"
#include "HermiteCurve.h"

OpenGLWindow::OpenGLWindow(const QColor& background, QMainWindow* parent) :
    mBackground(background)
{
    setParent(parent);
    setMinimumSize(720, 550);
    const QStringList list = { "vertexShader.glsl" , "fragmentShader.glsl" };
    mShaderWatcher = new QFileSystemWatcher(list, this);
    connect(mShaderWatcher, &QFileSystemWatcher::fileChanged, this, &OpenGLWindow::shaderWatcher);
}

OpenGLWindow::~OpenGLWindow()
{
    reset();
}

void OpenGLWindow::reset()
{
    // And now release all OpenGL resources.
    makeCurrent();
    delete mProgram;
    mProgram = nullptr;
    delete mVshader;
    mVshader = nullptr;
    delete mFshader;
    mFshader = nullptr;
    mVbo.destroy();
    doneCurrent();

    QObject::disconnect(mContextWatchConnection);
}

void OpenGLWindow::paintGL()
{


    glClear(GL_COLOR_BUFFER_BIT);

    mProgram->bind();

    QMatrix4x4 matrix;
    matrix.ortho(-3.0f - (gridSize / 2), 3.0f + (gridSize / 2), -3.0f - (gridSize / 2), 3.0f + (gridSize / 2), 0.1f, 100.0f);
    matrix.translate(0, 0, -2);

    mProgram->setUniformValue(m_matrixUniform, matrix);
    mProgram->setUniformValue("r", r);
    mProgram->setUniformValue("g", g);
    mProgram->setUniformValue("b", b);

    glVertexAttribPointer(m_posAttr, 2, GL_FLOAT, GL_FALSE, 0, curveVertices.data());
    glVertexAttribPointer(m_colAttr, 3, GL_FLOAT, GL_FALSE, 0, curveColors.data());


    glEnableVertexAttribArray(m_posAttr);
    glEnableVertexAttribArray(m_colAttr);

    glDrawArrays(GL_LINES, 0, curveVertices.size() / 2);

    glDisableVertexAttribArray(m_colAttr);
    glDisableVertexAttribArray(m_posAttr);

}
QString OpenGLWindow::readShader(QString filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return "Invalid file";

    QTextStream stream(&file);
    QString line = stream.readLine();

    while (!stream.atEnd()) {
        line.append(stream.readLine());
    }
    file.close();
    return line;
}

void OpenGLWindow::shaderWatcher()
{
    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    mProgram->release();
    mProgram->removeAllShaders();
    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
}

void OpenGLWindow::initializeGL()
{
    QString vertexShaderSource = readShader("vertexShader.glsl");
    QString fragmentShaderSource = readShader("fragmentShader.glsl");

    initializeOpenGLFunctions();

    mProgram = new QOpenGLShaderProgram(this);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Vertex, vertexShaderSource);
    mProgram->addShaderFromSourceCode(QOpenGLShader::Fragment, fragmentShaderSource);
    mProgram->link();
    m_posAttr = mProgram->attributeLocation("posAttr");
    Q_ASSERT(m_posAttr != -1);
    m_colAttr = mProgram->attributeLocation("colAttr");
    Q_ASSERT(m_colAttr != -1);
    m_matrixUniform = mProgram->uniformLocation("matrix");
    Q_ASSERT(m_matrixUniform != -1);
}

void OpenGLWindow::bezierCurve(std::vector<Point2D> v)
{

    curveColors.clear();
    curveVertices.clear();
    BezierCurve baz(v, baC);
    float maxSize = 0;
    for (int i = 0; i < v.size(); i++) {
        gridSize = std::max(maxSize, std::max(v[i].x(), v[i].y()));
    }
    gridSize *= 2;
    for (int i = 0; i < baC.size() / 2; i++) {
        curveColors << 1.0f << 0.0f << 0.0f;
    }
    for (int i = 0; i < baC.size(); i++) {
        curveVertices.push_back(baC[i]);
    }
    emit shapeUpdate();
}

void OpenGLWindow::hermiteCurve(std::vector<Point2D> v)
{
    curveColors.clear();
    curveVertices.clear();
    HermiteCurve her(v, heC);
    float maxSize = 0;
    for (int i = 0; i < v.size(); i++) {
        gridSize = std::max(maxSize, std::max(v[i].x(), v[i].y()));
    }
    gridSize *= 2;
    for (int i = 0; i < heC.size() / 2; i++) {
        curveColors << 1.0f << 1.0f << 0.0f;
    }
    for (int i = 0; i < heC.size(); i++) {
        curveVertices.push_back(heC[i]);
    }
    emit shapeUpdate();
    update();
}

void OpenGLWindow::setBackgroundColor(const QColor& color)
{
    mBackgroundColor = color;
    update(); // Trigger a repaint to show the new background color
}

void OpenGLWindow::selectColor()
{
    QColorDialog colorDialog(this);
    QColor selectedColor = colorDialog.getColor();

    if (selectedColor.isValid()) {
        // Set the selected color
        r = selectedColor.redF();
        g = selectedColor.greenF();
        b = selectedColor.blueF();
        update();
    }
}