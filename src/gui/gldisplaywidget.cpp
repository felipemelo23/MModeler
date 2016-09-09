#include "gldisplaywidget.h"

#include <iostream>
using namespace std;

glDisplayWidget::glDisplayWidget(QWidget *parent) : QGLWidget(parent)
{
    setMinimumHeight(300);
    setMinimumWidth(400);

    backgroundColor[0] = 0.1;
    backgroundColor[1] = 0.1;
    backgroundColor[2] = 0.1;

    lmbPressed = false;
    mmbPressed = false;
    rmbPressed = false;

    mouseX = 0;
    mouseY = 0;

    rotX = 0;
    rotY = 0;
    rotZ = 0;

    transX = 0;
    transY = 0;

    zoom = -10;

    gizmo = true;
    grid = true;
}

glDisplayWidget::~glDisplayWidget() {}

void glDisplayWidget::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    int key = event->key();

    cout << key << endl;

    switch (key) {
    case Qt::Key_R:
        resetView();
        break;
    case Qt::Key_A:
        gizmo = !gizmo;
        break;
    case Qt::Key_G:
        grid = !grid;
        break;
    default:
        break;
    }

    updateGL();
}

void glDisplayWidget::initializeGL()
{
    glClearColor(backgroundColor[0],
                 backgroundColor[1],
                 backgroundColor[2],1);


    glEnable(GL_DEPTH_TEST);

    initDisplay();
}

void glDisplayWidget::resizeGL(int w, int h)
{
    width = w;
    height = h;
    glViewport(0,0,w,h);
}

void glDisplayWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    double norm = max(minimumWidth(),minimumHeight());
    windowWidth = width/norm;
    windowHeight = height/norm;

    glBegin(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glFrustum(-windowWidth/20,windowWidth/20,-windowHeight/20,windowHeight/20,0.1,10000);
    glEnd();

    glPushMatrix();
    glTranslated(transX,transY,zoom);
    glRotated(rotX,1,0,0);
    glRotated(rotY,0,1,0);
    glRotated(rotZ,0,0,1);

    if (grid) drawGrid();
    drawScene();
    glPopMatrix();

    if (gizmo) drawGizmo();
}

void glDisplayWidget::resetView()
{
    rotX = 0;
    rotY = 0;
    rotZ = 0;

    transX = 0;
    transY = 0;

    zoom = -10;
}

void glDisplayWidget::mousePressEvent(QMouseEvent *event)
{
    mouseX = event->x();
    mouseY = event->y();

    if (event->button() == Qt::LeftButton) lmbPressed = true;
    if (event->button() == Qt::MidButton) mmbPressed = true;
    if (event->button() == Qt::RightButton) rmbPressed = true;
}

void glDisplayWidget::mouseReleaseEvent(QMouseEvent *event)
{
    lmbPressed = mmbPressed = rmbPressed = false;
}

void glDisplayWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (rmbPressed) {
        transX += ((double)(event->x() - mouseX))/100;
        transY += -((double)(event->y() - mouseY))/100;
        mouseX = event->x();
        mouseY = event->y();
    }

    if (mmbPressed) {
        if (zoom - ((double)(event->y() - mouseY))/100 >= -50) {
            zoom -= ((double)(event->y() - mouseY))/100;
        }

        mouseY = event->y();
    }

    if (lmbPressed) {
        rotZ += ((double)(event->x() - mouseX))/5;
        rotX += ((double)(event->y() - mouseY))/5;
        mouseX = event->x();
        mouseY = event->y();
    }

    updateGL();
}

void glDisplayWidget::wheelEvent(QWheelEvent *event)
{
    if (zoom + event->delta()/500.0f >= -50) {
        zoom += event->delta()/500.0f;
    }

    updateGL();
}

void glDisplayWidget::setGizmo(bool value)
{
    gizmo = value;
}

void glDisplayWidget::setGrid(bool value)
{
    grid = value;
}

void glDisplayWidget::drawGizmo()
{
    glPushMatrix();

    glLineWidth(2);
    glTranslated(-windowWidth/2,-windowHeight/2,-1.1);
    glRotated(rotX,1,0,0);
    glRotated(rotY,0,1,0);
    glRotated(rotZ,0,0,1);

    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    double sizeOfAxis = 0.05;

    glColor3d(1,0,0);
    renderText(sizeOfAxis+0.01,0,0,QString("x"));
    glColor3d(0,1,0);
    renderText(0,sizeOfAxis+0.01,0,QString("y"));
    glColor3d(0,0,1);
    renderText(0,0,sizeOfAxis+0.01,QString("z"));

    glBegin(GL_LINES);
    /* Draw X Axis */
    glColor3d(1,0,0);
    glVertex3d(0,0,0);
    glVertex3d(sizeOfAxis,0,0);
    glVertex3d(sizeOfAxis,0,0);
    glVertex3d(sizeOfAxis-(sizeOfAxis/5),0,(sizeOfAxis/10));
    glVertex3d(sizeOfAxis,0,0);
    glVertex3d(sizeOfAxis-(sizeOfAxis/5),0,-(sizeOfAxis/10));
    glVertex3d(sizeOfAxis,0,0);
    glVertex3d(sizeOfAxis-(sizeOfAxis/5),-(sizeOfAxis/10),0);
    glVertex3d(sizeOfAxis,0,0);
    glVertex3d(sizeOfAxis-(sizeOfAxis/5),(sizeOfAxis/10),0);
    /* Draw Y Axis */
    glColor3d(0,1,0);
    glVertex3d(0,0,0);
    glVertex3d(0,sizeOfAxis,0);
    glVertex3d(0,sizeOfAxis,0);
    glVertex3d((sizeOfAxis/10),sizeOfAxis-(sizeOfAxis/5),0);
    glVertex3d(0,sizeOfAxis,0);
    glVertex3d(-(sizeOfAxis/10),sizeOfAxis-(sizeOfAxis/5),0);
    glVertex3d(0,sizeOfAxis,0);
    glVertex3d(0,sizeOfAxis-(sizeOfAxis/5),(sizeOfAxis/10));
    glVertex3d(0,sizeOfAxis,0);
    glVertex3d(0,sizeOfAxis-(sizeOfAxis/5),-(sizeOfAxis/10));
    /* Draw Z Axis */
    glColor3d(0,0,1);
    glVertex3d(0,0,0);
    glVertex3d(0,0,sizeOfAxis);
    glVertex3d(0,0,sizeOfAxis);
    glVertex3d((sizeOfAxis/10),0,sizeOfAxis-(sizeOfAxis/5));
    glVertex3d(0,0,sizeOfAxis);
    glVertex3d(-(sizeOfAxis/10),0,sizeOfAxis-(sizeOfAxis/5));
    glVertex3d(0,0,sizeOfAxis);
    glVertex3d(0,(sizeOfAxis/10),sizeOfAxis-(sizeOfAxis/5));
    glVertex3d(0,0,sizeOfAxis);
    glVertex3d(0,-(sizeOfAxis/10),sizeOfAxis-(sizeOfAxis/5));
    glEnd();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);

    glLineWidth(1);

    glPopMatrix();
}

void glDisplayWidget::drawGrid()
{
    glDisable(GL_LIGHTING);
    glColor3d(0.8,0.8,0.8);
    glLineWidth(2);
    for (int i=0;i<11;i++) {
        glBegin(GL_LINES);
        glVertex3d(-5+i*(10.0/10),-5,0);
        glVertex3d(-5+i*(10.0/10),5,0);
        glEnd();
    }

    for (int i=0;i<11;i++) {
        glBegin(GL_LINES);
        glVertex3d(-5,-5+i*(10.0/10),0);
        glVertex3d(5,-5+i*(10.0/10),0);
        glEnd();
    }

    glLineWidth(0.5);
    for (int i=0;i<51;i++) {
        glBegin(GL_LINES);
        glVertex3d(-5+i*(10.0/50),-5,0);
        glVertex3d(-5+i*(10.0/50),5,0);
        glEnd();
    }

    for (int i=0;i<51;i++) {
        glBegin(GL_LINES);
        glVertex3d(-5,-5+i*(10.0/50),0);
        glVertex3d(5,-5+i*(10.0/50),0);
        glEnd();
    }

    glEnable(GL_LIGHTING);
}

void glDisplayWidget::initDisplay() {
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };
    GLfloat light_position[] = { 5.0, 5.0, 5.0, 0.0 };
    glShadeModel (GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
}

void glDisplayWidget::drawScene() {}

