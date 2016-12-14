#include "glmesh.h"

glMesh::glMesh(Mesh *mesh)
{
    this->mesh = mesh;
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
        }
    }

    for (std::pair<string, MEdge *> edge : mesh->getEdges()) {
        if (!contains(mesh->getActiveEdges(), edge.first)) {
            glColor4d(color[0],color[1],color[2],opacity);
            glBegin(GL_LINES);
            glVertex3d(edge.second->getStart()->getX(),edge.second->getStart()->getY(),edge.second->getStart()->getZ());
            glVertex3d(edge.second->getEnd()->getX(),edge.second->getEnd()->getY(),edge.second->getEnd()->getZ());
            glEnd();
        }
    }

    if (mesh->getActiveEdges().size() > 0) {
        for (string id : mesh->getActiveEdges()) {
            MEdge* edge = mesh->getEdge(id);

            glLineWidth(2);
            glColor4d(0,100,0,1);
            glBegin(GL_LINES);
            glVertex3d(edge->getStart()->getX(),edge->getStart()->getY(),edge->getStart()->getZ());
            glVertex3d(edge->getEnd()->getX(),edge->getEnd()->getY(),edge->getEnd()->getZ());
            glEnd();
            glLineWidth(1);
        }
    }

    if (mesh->getActiveVertices().size() > 0) {
        for (string id : mesh->getActiveVertices()) {
            MVertex *vertex = mesh->getVertex(id);

            glPointSize(5);
            glColor4d(0,1,0,opacity);
            glBegin(GL_POINTS);
            glVertex3d(vertex->getX(),vertex->getY(),vertex->getZ());
            glEnd();
            glPointSize(1);
        }
    }
}

bool glMesh::contains(vector<string> list, string item) {
    for (string listItem : list)
        if (listItem == item) return true;
    return false;
}
