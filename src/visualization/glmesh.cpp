#include "glmesh.h"

glMesh::glMesh(Mesh *mesh, QGLWidget *widget)
{
    this->mesh = mesh;
    this->widget = widget;
}

void glMesh::draw()
{
    if (mesh->getFaces().size() > 1) {
        for (std::pair<string,MFace *> face : mesh->getFaces()) {
            vector<MVertex*> vertices = mesh->vf(face.first);

            glBegin(GL_POLYGON);
            if ((mesh->getActiveFaces().size() > 0)&&contains(mesh->getActiveFaces(),face.first))
                glColor4d(0,1,0,opacity);
            else
                glColor4d(color[0],color[1],color[2],opacity);

            Vec3 faceCenter = Vec3(0,0,0);
            for (MVertex* vertex : vertices) {
                glVertex3d(vertex->getX(), vertex->getY(), vertex->getZ());
                faceCenter = faceCenter + *vertex;
            }
            glEnd();

            faceCenter = faceCenter*(1.0/vertices.size());
            glColor4d(0,0,1,1);
        }
    }

    for (std::pair<string,MVertex *> vertex : mesh->getVertices()) {
        if (!contains(mesh->getActiveVertices(),vertex.first)) {
            glPointSize(5);
            glColor4d(color[0],color[1],color[2],opacity);
            glBegin(GL_POINTS);
            glVertex3d(vertex.second->getX(),vertex.second->getY(),vertex.second->getZ());
            glEnd();
            glPointSize(1);

            glColor4d(1,0,0,opacity);
            widget->renderText(vertex.second->getX(), vertex.second->getY()+0.1, vertex.second->getZ(), QString::fromStdString(vertex.first));
        }
    }

    for (std::pair<string, MEdge *> edge : mesh->getEdges()) {
        if (!contains(mesh->getActiveEdges(), edge.first)) {
            Vec3 dir = *(edge.second->getEnd()) - *(edge.second->getStart());
            dir.normalize();

            glBegin(GL_LINES);
            glColor4d(color[0]/2,color[1]/2,color[2]/2,1);
            glVertex3d(edge.second->getStart()->getX(),edge.second->getStart()->getY(),edge.second->getStart()->getZ());
            glColor4d(color[0],color[1],color[2],1);
            glVertex3d(edge.second->getEnd()->getX(),edge.second->getEnd()->getY(),edge.second->getEnd()->getZ());
            glEnd();

            Vec3 center = (*(edge.second->getStart()) + *(edge.second->getEnd()))*0.5;

            glColor4d(0,0,1,opacity);
            widget->renderText(center.getX(), center.getY()+0.1, center.getZ(), QString::fromStdString(edge.first));
        }
    }

    if (mesh->getActiveEdges().size() > 0) {
        for (string id : mesh->getActiveEdges()) {
            MEdge* edge = mesh->getEdge(id);

            glLineWidth(2);
            glColor4d(0,10,0,1);
            glBegin(GL_LINES);
            glVertex3d(edge->getStart()->getX(),edge->getStart()->getY(),edge->getStart()->getZ());
            glVertex3d(edge->getEnd()->getX(),edge->getEnd()->getY(),edge->getEnd()->getZ());
            glEnd();
            glLineWidth(1);

            Vec3 center = (*(edge->getStart()) + *(edge->getEnd()))*0.5;

            glColor4d(0,0,1,opacity);
            widget->renderText(center.getX(), center.getY()+0.1, center.getZ(), QString::fromStdString(id));
        }
    }

    if (mesh->getActiveVertices().size() > 0) {
        for (string id : mesh->getActiveVertices()) {
            MVertex *vertex = mesh->getVertex(id);

            glPointSize(5);
            glColor4d(0,100,0,1);
            glBegin(GL_POINTS);
            glVertex3d(vertex->getX(),vertex->getY(),vertex->getZ());
            glEnd();
            glPointSize(1);

            glColor4d(1,0,0,opacity);
            widget->renderText(vertex->getX(), vertex->getY()+0.1, vertex->getZ(), QString::fromStdString(id));
        }
    }
}

bool glMesh::contains(vector<string> list, string item) {
    for (string listItem : list)
        if (listItem == item) return true;
    return false;
}
