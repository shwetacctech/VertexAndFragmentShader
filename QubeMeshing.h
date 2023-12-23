#pragma once
#include <QtWidgets/QMainWindow>
#include "ui_QubeMeshing.h" 
#include "Point3D.h"
#include "OpenGLWindow.h"

class QubeMeshing : public QMainWindow
{
    Q_OBJECT

public:
    QubeMeshing(QWidget *parent = nullptr);
    ~QubeMeshing();
    void setupUi();
public slots:
    void addPoints();
    void bresenham();
    void bezierCurve();
    void hermiteCurve();
    void bsplineCurve();
    void simpleDDA();
private:
   Ui::QubeMeshingClass ui;
   QWidget* mCentralWidget;
    QDoubleSpinBox* mDoubleSpinBox;
    QDoubleSpinBox* mDoubleSpinBox_2;
    QDoubleSpinBox* mDoubleSpinBox_3;
    QPushButton* mPushButton;
    QPushButton* mPushButton_2;
    QPushButton* mPushButton_3;
    QPushButton* mPushButton_4;
    QPushButton* mPushButton_5;
    QPushButton* mPushButton_6;
    QListWidget* mListWidget;
    QTabWidget* mtabWidget;
    QWidget* mtab1;
    QWidget* mtab2;
    QMenuBar* menuBar;
    QToolBar* mainToolBar;
    QStatusBar* statusBar;
    QLabel* mlabel;
    QLabel* mlabel_2;
    QLabel* mlabel_3;
    QLabel* mlabel_4;
    QPalette* mPalette;
    std::vector< Point3D> mPoints;
    std::vector< Point3D> mCurvePoints;
    QVector<GLfloat> mVertices;
    QVector<GLfloat> mColors;
    OpenGLWindow* mRenderer;

    std::vector<float> mcurvePoint;
    std::vector<float> mcurveColor;

};

