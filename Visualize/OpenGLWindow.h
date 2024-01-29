

#pragma once
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer>
#include "Line.h"
#include <vector>
#include "Point2D.h"

class QOpenGLTexture;
class QOpenGLShader;
class QOpenGLShaderProgram;
class QOpenGLPaintDevice;

class OpenGLWindow :public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
signals:
    void shapeUpdate();
public:
    OpenGLWindow(const QColor& background, QMainWindow* parent);
    ~OpenGLWindow();
    void selectColor();
protected:
    void paintGL() override;
    void initializeGL() override;

private:
    void reset();
    
    void shaderWatcher();
    QString readShader(QString filePath);

private:
    QOpenGLShader* mVshader = nullptr;
    QOpenGLShader* mFshader = nullptr;
    QOpenGLShaderProgram* mProgram = nullptr;
    QOpenGLBuffer mVbo;
    int mVertexAttr;
    int mNormalAttr;
    int mMatrixUniform;
    QColor mBackground;
    QMetaObject::Connection mContextWatchConnection;
    GLint m_posAttr = 0;
    GLint m_colAttr = 0;
    GLint m_matrixUniform = 0;
    QVector<QVector2D> mPixelVertices;
    std::vector<float> baC;
    std::vector<float> heC;
    QVector<GLfloat> curveVertices;
    QVector<GLfloat> curveColors;
    QColor mBackgroundColor;
    QFileSystemWatcher* mShaderWatcher;
    float r = 1.0f, g = 1.0f, b = 1.0f;

public:
    QVector<GLfloat> vertices;
    QVector<GLfloat> colors;
    int gridSize;
    void bezierCurve(std::vector<Point2D> v);
    void hermiteCurve(std::vector<Point2D> v);
    void setBackgroundColor(const QColor& color);
};