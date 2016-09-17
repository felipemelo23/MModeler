#ifndef GLDISPLAYWIDGET_H
#define GLDISPLAYWIDGET_H

#include "objectsmanager.h"

#include <QGLWidget>
#include <QMouseEvent>
#include <QTimer>

#include <visualization/glscene.h>

class glDisplayWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit glDisplayWidget(QWidget *parent = 0);
    ~glDisplayWidget();

    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);


    void setGizmo(bool value);
    void setGrid(bool value);

    void setObjects(ObjectsManager *objects);

protected:
    glScene *scene;
    ObjectsManager *objects;

    double backgroundColor[3];

    int width;
    int height;

    double windowWidth;
    double windowHeight;

    bool lmbPressed;
    bool mmbPressed;
    bool rmbPressed;

    int mouseX;
    int mouseY;

    double rotX;
    double rotY;
    double rotZ;

    double transX;
    double transY;

    double zoom;

    bool gizmo;
    bool grid;

    QTimer *timer;

    void drawGizmo();
    void drawGrid();

    virtual void initDisplay();
    virtual void drawScene();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void resetView();

private slots:
    void checkDirts();
};

#endif // GLDISPLAYWIDGET_H
