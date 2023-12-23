#include "stdafx.h"
#include "QubeMeshing.h"
#include "OpenGLWindow.h"
#include "BezierCurve.h"
#include "Hermite.h"
#include "BSpline.h"
#include "Line.h"
#include "Bresenhams.h"
#include "SimpleDDA.h"
#include <Grid.h>
#include <cmath>
QubeMeshing::QubeMeshing(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();
    connect(mPushButton, &QPushButton::clicked, this, &QubeMeshing::addPoints);
    connect(mPushButton_5, &QPushButton::clicked, this, &QubeMeshing::bezierCurve);
    connect(mPushButton_4, &QPushButton::clicked, this, &QubeMeshing::hermiteCurve);
    connect(mPushButton_3, &QPushButton::clicked, this, &QubeMeshing::bresenham);
    connect(mPushButton_2, &QPushButton::clicked, this, &QubeMeshing::simpleDDA);
    connect(mPushButton_6, &QPushButton::clicked, this, &QubeMeshing::bsplineCurve);
    connect(mRenderer, SIGNAL(shapeUpdate()), mRenderer, SLOT(update()));
}

QubeMeshing::~QubeMeshing()
{}
void QubeMeshing::setupUi() {
    resize(600, 500);
    mCentralWidget = new QWidget(this);
    mtabWidget = new QTabWidget(mCentralWidget);
    mtabWidget->setObjectName("tabWidget");
    mtabWidget->setGeometry(QRect(300, 100, 271, 101));
    mtab1 = new QWidget();
    mtab1->setObjectName("tab");
    mPushButton_2 = new QPushButton(mtab1);
    mPushButton_2->setText("SimpleDDA");
    mPushButton_2->setObjectName("pushButton_2");
    mPushButton_2->setGeometry(QRect(10, 10, 81, 24));
    mPushButton_3 = new QPushButton(mtab1);
    mPushButton_3->setText("Bresenhams");
    mPushButton_3->setObjectName("pushButton_3");
    mPushButton_3->setGeometry(QRect(120, 10, 91, 24));
    mtabWidget->addTab(mtab1, "Lines");
    mtab2 = new QWidget();
    mtab2->setObjectName("tab_2");
    mPushButton_4 = new QPushButton(mtab2);
    mPushButton_4->setObjectName("pushButton_4");
    mPushButton_4->setText("Hermite");
    mPushButton_4->setGeometry(QRect(10, 10, 81, 24));
    mPushButton_5 = new QPushButton(mtab2);
    mPushButton_5->setObjectName("pushButton_5");
    mPushButton_5->setGeometry(QRect(130, 10, 81, 24));
    mPushButton_5->setText("Bezier");
    mPushButton_6 = new QPushButton(mtab2);
    mPushButton_6->setObjectName("pushButton_6");
    mPushButton_6->setGeometry(QRect(80, 40, 81, 24));
    mPushButton_6->setText("BSpline");
    mtabWidget->addTab(mtab2, "Splines");
    
    mCentralWidget->setObjectName("mCentralWidget");
    mDoubleSpinBox = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBox->setObjectName("doubleSpinBox");
    mDoubleSpinBox->setMinimum(-100.000000000000000);
    mDoubleSpinBox->setMaximum(100.000000000000000);
    mDoubleSpinBox->setGeometry(QRect(300, 60, 62, 22));
    mDoubleSpinBox_2 = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBox_2->setObjectName("mDoubleSpinBox_2");
    mDoubleSpinBox_2->setMinimum(-100.000000000000000);
    mDoubleSpinBox_2->setMaximum(100.000000000000000);
    mDoubleSpinBox_2->setGeometry(QRect(370, 60, 62, 22));
    mDoubleSpinBox_3 = new QDoubleSpinBox(mCentralWidget);
    mDoubleSpinBox_3->setObjectName("mDoubleSpinBox_3");
    mDoubleSpinBox_3->setMinimum(-100.000000000000000);
    mDoubleSpinBox_3->setMaximum(100.000000000000000);
    mDoubleSpinBox_3->setGeometry(QRect(440, 60, 62, 22));
   
    
    mPushButton = new QPushButton(mCentralWidget);
    mPushButton->setObjectName("pushButton");
    mPushButton->setGeometry(QRect(510, 60, 75, 24));
    mPushButton->setText("ADD");
   
    
    mListWidget = new QListWidget(mCentralWidget);
    mListWidget->setObjectName("listWidget");
    mListWidget->setGeometry(QRect(30, 60, 256, 131));

    mlabel = new QLabel(mCentralWidget);
    mlabel->setObjectName("label");
    mlabel->setGeometry(QRect(50, 30, 111, 16));
    mlabel->setText("Input Data");
    mlabel_2 = new QLabel(mCentralWidget);
    mlabel_2->setObjectName("label_2");
    mlabel_2->setGeometry(QRect(300, 30, 49, 16));
    mlabel_2->setText("X - Value");
    mlabel_3 = new QLabel(mCentralWidget);
    mlabel_3->setObjectName("label_3");
    mlabel_3->setGeometry(QRect(370, 30, 49, 16));
    mlabel_3->setText("Y - Value");
    mlabel_4 = new QLabel(mCentralWidget);
    mlabel_4->setObjectName("label_4");
    mlabel_4->setGeometry(QRect(440, 30, 49, 16));
    mlabel_4->setText("Z - Value");

    
    mRenderer = new OpenGLWindow(QColor(0, 0, 0), this);
    mRenderer->setGeometry(QRect(30, 210, 531, 200));

    setCentralWidget(mCentralWidget);
    menuBar = new QMenuBar(this);
    menuBar->setObjectName("menuBar");
    menuBar->setGeometry(QRect(0, 0, 458, 22));
    setMenuBar(menuBar);
    mainToolBar = new QToolBar(this);
    mainToolBar->setObjectName("mainToolBar");
    addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(this);
    statusBar->setObjectName("statusBar");
    setStatusBar(statusBar);
}
void  QubeMeshing::addPoints() {
    double xValue = mDoubleSpinBox->value();
    double yValue = mDoubleSpinBox_2->value();
    double zValue = mDoubleSpinBox_3->value();
    QString itemText = QString("%1, %2, %3").arg(xValue).arg(yValue).arg(zValue);
    Point3D p(xValue, yValue,zValue);
    mPoints.push_back(p);
    QListWidgetItem* newItem = new QListWidgetItem(itemText);
    mListWidget->addItem(newItem);
    mVertices.clear();
    
}
void QubeMeshing::bezierCurve() {
    mVertices.empty();
    mColors.empty();
    BezierCurve bezicurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mColors << 0.0f << 1.0f << 0.0f;
    bezicurve.drawCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size(); i += 3)
    {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i += 3)
    {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    mVertices << mPoints[3].getX() << mPoints[3].getY() << mPoints[3].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
    mRenderer->updateData(mVertices, mColors,1);
    mVertices.empty();
    mColors.empty();
    mPoints.clear();
    mcurvePoint.clear();
    mcurveColor.clear();
    mListWidget->clear();
}
void QubeMeshing::simpleDDA() {
    mVertices.empty();
    mColors.empty();
    Line l(mPoints[0], mPoints[1]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mVertices << mPoints[1].getX() << mPoints[1].getY() << mPoints[1].getZ();

    mColors << 0.0f << 1.0f << 0.0f;
    mColors << 0.0f << 1.0f << 0.0f;
    
    Grid grid(mcurvePoint, mcurveColor, 20);
    SimpleDDA simpledda(l, mcurvePoint, mcurvePoint);
    for (int i = 0; i < mcurvePoint.size(); i += 3) {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i += 3) {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    
    mRenderer->updateData(mVertices, mColors,1);
    mVertices.clear();
    mColors.clear();
    mcurveColor.clear();
    mcurvePoint.clear();
    mPoints.clear();
    mListWidget->clear();
}
void QubeMeshing::hermiteCurve() {
   
    mVertices.empty();
    mColors.empty();
    Hermite hermitecurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
   
    hermitecurve.drawCurve(mPoints[0], mPoints[1], mPoints[2], mPoints[3], mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size(); i += 3)
    {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i += 3)
    {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }
    mVertices << mPoints[3].getX() << mPoints[3].getY() << mPoints[3].getZ();
    mColors << 1.0f << 1.0f << 0.0f;
    mRenderer->updateData(mVertices, mColors, 1);
    mVertices.empty();
    mColors.empty();
    mcurvePoint.clear();
    mcurveColor.clear();
    mListWidget->clear();
}
void QubeMeshing::bresenham() {
    mVertices.clear();
    mColors.clear();
    Line l(mPoints[0], mPoints[1]);
    mVertices << mPoints[0].getX() << mPoints[0].getY() << mPoints[0].getZ();
    mVertices << mPoints[1].getX() << mPoints[1].getY() << mPoints[1].getZ();
    mColors << 1.00f << 0.00f << 1.0f;
    mColors << 1.00f << 0.00f << 1.0f;
   
    Grid gride(mcurvePoint, mcurveColor, 20);
    Bresenhams bresenhams(l, mcurvePoint, mcurveColor);
    for (int i = 0; i < mcurvePoint.size(); i +=3) {
        mVertices << mcurvePoint[i] << mcurvePoint[i + 1] << mcurvePoint[i + 2];
    }
    for (int i = 0; i < mcurveColor.size(); i +=3) {
        mColors << mcurveColor[i] << mcurveColor[i + 1] << mcurveColor[i + 2];
    }

    mRenderer->setColorOfLines(mColors);
    mRenderer->setVectorOfLines(mVertices);
    mRenderer->updateData(mVertices, mColors, 1);
    mVertices.clear();
    mColors.clear();
    mPoints.clear();
    mcurvePoint.clear();
    mcurveColor.clear();
    mListWidget->clear();
}
void QubeMeshing::bsplineCurve() {
    BSpline bspline(3);
    mCurvePoints=bspline.evaluate(mPoints, 100);
    mCurvePoints.pop_back();
   for (int i = 0; i < mCurvePoints.size()-1; i++) {
       mVertices << mCurvePoints[i].getX() << mCurvePoints[i].getY() << mCurvePoints[i].getZ();
       mVertices << mCurvePoints[i+1].getX() << mCurvePoints[i+1].getY() << mCurvePoints[i+1].getZ();
       mColors << 01.0f << 0.0f << 1.0f;
       mColors << 01.0f << 0.0f << 1.0f;
    }
    mRenderer->updateData(mVertices, mColors,1);
    mVertices.clear();
    mColors.clear();
    mPoints.clear();
    mCurvePoints.clear();
    mListWidget->clear();
}