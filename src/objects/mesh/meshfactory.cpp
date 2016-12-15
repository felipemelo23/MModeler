#include "meshfactory.h"

//Mesh *MeshFactory::buildGenMesh(vector<Vec3 *> vertices, vector<Face> faces)
//{
////para converter de PolygonMesh para Winged Edge, precisamos primeiro saber todas
////as arestas existentes no modelo. Apenas precisaremos de uma delas, portanto
////arestas repetidas nao serao contadas.
//    vector< pair<Vec3,Vec3> > edges = getEdges(faces);

//    Mesh* mesh = new Mesh();

//    int eID = -1;
//    int vID = -1;
//    int fID = -1;

////primeiro criamos as arestas com seus respectivos vertices finais:
//    mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
//    Vec3 newV = edges.at(eID).second;

//    mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
//    mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));

//    for(unsigned int i=1; i<edges.size(); i++)
//    {
//        mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
//        newV = edges.at(eID).second;

//        for(int j=0; j <= eID; j++)
//        {
//            if(mesh->getEdge(to_string(j))->getEnd() != newV)
//            {
//                mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
//                mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
//            }
//            else    //flipamos a aresta
//            {
//                newV = edges.at(eID).first;

//                if(mesh->getEdge(to_string(j))->getStart() != newV)
//                {
//                    mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
//                    mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
//                }
//            }
//        }
//    }

////agora conferimos os pontos finais de todas as arestas e fazemos as ligações com os pontos iniciais:
//    for(int i=0; i<=eID; i++)
//    {
//        Vec3 vStt = edges.at(i).first;

//        for(int j=0; j<=eID; j++)
//        {
//            if(j!=i)
//            {
//                if(mesh->getEdge(to_string(j))->getEnd() == vStt)
//                {
//                    mesh->getEdge(to_string(i))->setStart(mesh->getEdge(to_string(j))->getEnd());
//                }
//            }
//        }
//    }

////sabendo os pontos iniciais e finais podemos entao setar as arestas adjascentes:
//    for(int i=0; i<=eID; i++)
//    {
//        for(int j=0; j<=eID; j++)
//        {
//            if(j!=i)
//            {
//                if(mesh->getEdge(to_string(i))->getEnd() == mesh->getEdge(to_string(j))->getStart())
//                {
//                    mesh->getEdge(to_string(i))->setRnext(mesh->getEdge(to_string(j)));
//                }
//                else if(mesh->getEdge(to_string(i))->getEnd() == mesh->getEdge(to_string(j))->getEnd())
//                {
//                    mesh->getEdge(to_string(i))->setLprev(mesh->getEdge(to_string(j)));
//                }
//                else if(mesh->getEdge(to_string(i))->getStart() == mesh->getEdge(to_string(j))->getEnd())
//                {
//                    mesh->getEdge(to_string(i))->setRprev(mesh->getEdge(to_string(j)));
//                }
//                else if(mesh->getEdge(to_string(i))->getStart() == mesh->getEdge(to_string(j))->getStart())
//                {
//                    mesh->getEdge(to_string(i))->setLnext(mesh->getEdge(to_string(j)));
//                }
//            }
//        }
//    }

////por fim, como sabemos todos os vertices que pertencem as arestas, e as ligacoes entre as arestas adjascentes,
////basta consruirmos as faces:
//    bool isInFace;

//    for(int i=0; i<=eID; i++)
//    {
//        for(unsigned int j=0; j<faces.size(); j++)
//        {
//            vector< pair<Vec3,Vec3> > edges = faces.at(j).getEdges();
//            isInFace=false;

//            for(unsigned int k=0; k<edges.size; k++)
//            {
//                if(edgeEqual(*mesh->getEdge(i), edges.at(k)))
//                {
//                    isInFace=true;
//                }
//            }
//            if(isInFace)
//            {
//                for(unsigned int k=0; k<edges.size; k++)
//                {
//                    if(edgeEqual(mesh->getEdge(i)->getRnext(), edges.at(k)))    //se contem o Rnext a face esta a direita
//                    {
//                        mesh->getEdge(i)->setRight(new MFace(to_string(++fID), mesh->getEdge(i)->getRnext()->getId()));
//                    }
//                    if(edgeEqual(mesh->getEdge(i)->getLnext(), edges.at(k)))    //se contem o Lnext a face esta a esquerda
//                    {
//                        mesh->getEdge(i)->setLeft(new MFace(to_string(++fID), mesh->getEdge(i)->getLnext()->getId()));
//                    }
//                }
//            }
//        }
//    }

////a malha foi totalmente convertida para WED

//    return mesh;
//}

Mesh *MeshFactory::buildBox()
{
    Mesh* mesh = new Mesh();

//criamos os vertices do cubo:
    mesh->addVertex(to_string(0), new MVertex(to_string(0), to_string(3), -1, -1, 1));
    mesh->addVertex(to_string(1), new MVertex(to_string(1), to_string(0), 1, -1, 1));
    mesh->addVertex(to_string(2), new MVertex(to_string(2), to_string(1), 1, -1, -1));
    mesh->addVertex(to_string(3), new MVertex(to_string(3), to_string(2), -1, -1, -1));
    mesh->addVertex(to_string(4), new MVertex(to_string(4), to_string(7), -1, 1, 1));
    mesh->addVertex(to_string(5), new MVertex(to_string(5), to_string(9), 1, 1, 1));
    mesh->addVertex(to_string(6), new MVertex(to_string(6), to_string(11), 1, 1, -1));
    mesh->addVertex(to_string(7), new MVertex(to_string(7), to_string(13), -1, 1, -1));
    mesh->addVertex(to_string(8), new MVertex(to_string(8), to_string(16), 0, 1, 0));
    mesh->addVertex(to_string(9), new MVertex(to_string(9), to_string(20), 0, -1, 0));

//construimos as arestas
    buildEdge(mesh, 0, mesh->getVertex(to_string(0)), mesh->getVertex(to_string(1)));
    buildEdge(mesh, 1, mesh->getVertex(to_string(1)), mesh->getVertex(to_string(2)));
    buildEdge(mesh, 2, mesh->getVertex(to_string(2)), mesh->getVertex(to_string(3)));
    buildEdge(mesh, 3, mesh->getVertex(to_string(3)), mesh->getVertex(to_string(0)));
    buildEdge(mesh, 4, mesh->getVertex(to_string(4)), mesh->getVertex(to_string(5)));
    buildEdge(mesh, 5, mesh->getVertex(to_string(5)), mesh->getVertex(to_string(6)));
    buildEdge(mesh, 6, mesh->getVertex(to_string(6)), mesh->getVertex(to_string(7)));
    buildEdge(mesh, 7, mesh->getVertex(to_string(7)), mesh->getVertex(to_string(4)));
    buildEdge(mesh, 8, mesh->getVertex(to_string(0)), mesh->getVertex(to_string(4)));
    buildEdge(mesh, 9, mesh->getVertex(to_string(0)), mesh->getVertex(to_string(5)));
    buildEdge(mesh, 10, mesh->getVertex(to_string(1)), mesh->getVertex(to_string(5)));
    buildEdge(mesh, 11, mesh->getVertex(to_string(1)), mesh->getVertex(to_string(6)));
    buildEdge(mesh, 12, mesh->getVertex(to_string(2)), mesh->getVertex(to_string(6)));
    buildEdge(mesh, 13, mesh->getVertex(to_string(2)), mesh->getVertex(to_string(7)));
    buildEdge(mesh, 14, mesh->getVertex(to_string(3)), mesh->getVertex(to_string(7)));
    buildEdge(mesh, 15, mesh->getVertex(to_string(3)), mesh->getVertex(to_string(4)));
    buildEdge(mesh, 16, mesh->getVertex(to_string(5)), mesh->getVertex(to_string(8)));
    buildEdge(mesh, 17, mesh->getVertex(to_string(6)), mesh->getVertex(to_string(8)));
    buildEdge(mesh, 18, mesh->getVertex(to_string(7)), mesh->getVertex(to_string(8)));
    buildEdge(mesh, 19, mesh->getVertex(to_string(4)), mesh->getVertex(to_string(8)));
    buildEdge(mesh, 20, mesh->getVertex(to_string(1)), mesh->getVertex(to_string(9)));
    buildEdge(mesh, 21, mesh->getVertex(to_string(2)), mesh->getVertex(to_string(9)));
    buildEdge(mesh, 22, mesh->getVertex(to_string(3)), mesh->getVertex(to_string(9)));
    buildEdge(mesh, 23, mesh->getVertex(to_string(0)), mesh->getVertex(to_string(9)));

//adicionamos as relacoes entre as arestas
    makeAdjascents(mesh,0,mesh->getEdge(to_string(9)),mesh->getEdge(to_string(23)),mesh->getEdge(to_string(10)),mesh->getEdge(to_string(20)));
    makeAdjascents(mesh,1,mesh->getEdge(to_string(11)),mesh->getEdge(to_string(20)),mesh->getEdge(to_string(12)),mesh->getEdge(to_string(21)));
    makeAdjascents(mesh,2,mesh->getEdge(to_string(13)),mesh->getEdge(to_string(21)),mesh->getEdge(to_string(14)),mesh->getEdge(to_string(22)));
    makeAdjascents(mesh,3,mesh->getEdge(to_string(15)),mesh->getEdge(to_string(22)),mesh->getEdge(to_string(8)),mesh->getEdge(to_string(23)));
    makeAdjascents(mesh,4,mesh->getEdge(to_string(19)),mesh->getEdge(to_string(8)),mesh->getEdge(to_string(16)),mesh->getEdge(to_string(9)));
    makeAdjascents(mesh,5,mesh->getEdge(to_string(16)),mesh->getEdge(to_string(10)),mesh->getEdge(to_string(17)),mesh->getEdge(to_string(11)));
    makeAdjascents(mesh,6,mesh->getEdge(to_string(17)),mesh->getEdge(to_string(12)),mesh->getEdge(to_string(18)),mesh->getEdge(to_string(13)));
    makeAdjascents(mesh,7,mesh->getEdge(to_string(18)),mesh->getEdge(to_string(14)),mesh->getEdge(to_string(19)),mesh->getEdge(to_string(15)));
    makeAdjascents(mesh,8,mesh->getEdge(to_string(3)),mesh->getEdge(to_string(9)),mesh->getEdge(to_string(7)),mesh->getEdge(to_string(4)));
    makeAdjascents(mesh,9,mesh->getEdge(to_string(8)),mesh->getEdge(to_string(0)),mesh->getEdge(to_string(4)),mesh->getEdge(to_string(10)));
    makeAdjascents(mesh,10,mesh->getEdge(to_string(0)),mesh->getEdge(to_string(11)),mesh->getEdge(to_string(9)),mesh->getEdge(to_string(5)));
    makeAdjascents(mesh,11,mesh->getEdge(to_string(10)),mesh->getEdge(to_string(1)),mesh->getEdge(to_string(5)),mesh->getEdge(to_string(12)));
    makeAdjascents(mesh,12,mesh->getEdge(to_string(1)),mesh->getEdge(to_string(13)),mesh->getEdge(to_string(11)),mesh->getEdge(to_string(6)));
    makeAdjascents(mesh,13,mesh->getEdge(to_string(12)),mesh->getEdge(to_string(2)),mesh->getEdge(to_string(6)),mesh->getEdge(to_string(14)));
    makeAdjascents(mesh,14,mesh->getEdge(to_string(2)),mesh->getEdge(to_string(15)),mesh->getEdge(to_string(13)),mesh->getEdge(to_string(7)));
    makeAdjascents(mesh,15,mesh->getEdge(to_string(14)),mesh->getEdge(to_string(3)),mesh->getEdge(to_string(7)),mesh->getEdge(to_string(15)));
    makeAdjascents(mesh,16,mesh->getEdge(to_string(4)),mesh->getEdge(to_string(5)),mesh->getEdge(to_string(19)),mesh->getEdge(to_string(17)));
    makeAdjascents(mesh,17,mesh->getEdge(to_string(5)),mesh->getEdge(to_string(6)),mesh->getEdge(to_string(16)),mesh->getEdge(to_string(18)));
    makeAdjascents(mesh,18,mesh->getEdge(to_string(6)),mesh->getEdge(to_string(7)),mesh->getEdge(to_string(17)),mesh->getEdge(to_string(19)));
    makeAdjascents(mesh,19,mesh->getEdge(to_string(7)),mesh->getEdge(to_string(4)),mesh->getEdge(to_string(18)),mesh->getEdge(to_string(16)));
    makeAdjascents(mesh,20,mesh->getEdge(to_string(0)),mesh->getEdge(to_string(1)),mesh->getEdge(to_string(23)),mesh->getEdge(to_string(21)));
    makeAdjascents(mesh,21,mesh->getEdge(to_string(1)),mesh->getEdge(to_string(2)),mesh->getEdge(to_string(20)),mesh->getEdge(to_string(22)));
    makeAdjascents(mesh,22,mesh->getEdge(to_string(2)),mesh->getEdge(to_string(3)),mesh->getEdge(to_string(21)),mesh->getEdge(to_string(23)));
    makeAdjascents(mesh,23,mesh->getEdge(to_string(3)),mesh->getEdge(to_string(0)),mesh->getEdge(to_string(22)),mesh->getEdge(to_string(20)));

//adicionamos as faces:
    mesh->addFace(to_string(0), new MFace(to_string(0), to_string(9)));
    mesh->addFace(to_string(1), new MFace(to_string(1), to_string(10)));
    mesh->addFace(to_string(2), new MFace(to_string(2), to_string(5)));
    mesh->addFace(to_string(3), new MFace(to_string(3), to_string(11)));
    mesh->addFace(to_string(4), new MFace(to_string(4), to_string(12)));
    mesh->addFace(to_string(5), new MFace(to_string(5), to_string(2)));
    mesh->addFace(to_string(6), new MFace(to_string(6), to_string(15)));
    mesh->addFace(to_string(7), new MFace(to_string(7), to_string(8)));
    mesh->addFace(to_string(8), new MFace(to_string(8), to_string(4)));
    mesh->addFace(to_string(9), new MFace(to_string(9), to_string(16)));
    mesh->addFace(to_string(10), new MFace(to_string(10), to_string(18)));
    mesh->addFace(to_string(11), new MFace(to_string(11), to_string(7)));
    mesh->addFace(to_string(12), new MFace(to_string(12), to_string(0)));
    mesh->addFace(to_string(13), new MFace(to_string(13), to_string(21)));
    mesh->addFace(to_string(14), new MFace(to_string(14), to_string(21)));
    mesh->addFace(to_string(15), new MFace(to_string(15), to_string(3)));

//agora adicionamos as relações das arestas c as faces:
    linkEdgeFace(mesh,0,1,12);
    linkEdgeFace(mesh,1,3,13);
    linkEdgeFace(mesh,2,5,14);
    linkEdgeFace(mesh,3,7,15);
    linkEdgeFace(mesh,4,0,8);
    linkEdgeFace(mesh,5,2,9);
    linkEdgeFace(mesh,6,4,10);
    linkEdgeFace(mesh,7,6,11);
    linkEdgeFace(mesh,8,7,0);
    linkEdgeFace(mesh,9,0,1);
    linkEdgeFace(mesh,10,1,2);
    linkEdgeFace(mesh,11,2,3);
    linkEdgeFace(mesh,12,3,4);
    linkEdgeFace(mesh,13,4,5);
    linkEdgeFace(mesh,14,5,6);
    linkEdgeFace(mesh,15,6,7);
    linkEdgeFace(mesh,16,8,9);
    linkEdgeFace(mesh,17,9,10);
    linkEdgeFace(mesh,18,10,11);
    linkEdgeFace(mesh,19,11,8);
    linkEdgeFace(mesh,20,12,13);
    linkEdgeFace(mesh,21,13,14);
    linkEdgeFace(mesh,22,14,15);
    linkEdgeFace(mesh,23,15,12);
//RETORNAMOS O OBJETO
    return mesh;
}

Mesh *MeshFactory::buildSphere()
{

}

vector<pair<Vec3, Vec3> > MeshFactory::getEdges(vector<Face> faces)
{
    vector< pair<Vec3,Vec3> > edges_aux;
    vector< pair<Vec3,Vec3> > edges;

    for(unsigned int i=0; i<faces.size(); i++)
    {
        edges_aux = faces.at(i).getEdges();

        if(i>0)
        {
            for(unsigned int j=0; j<edges_aux.size(); j++)
            {
                bool can_add = true;

                for(unsigned int k=0; k<edges.size(); k++)
                {
                    if(edgeEqual(edges_aux.at(j), edges.at(k)))
                    {
                        can_add = false;
                        break;
                    }
                }

                if(can_add)
                    edges.push_back(edges_aux.at(j));
            }
        }
        else
        {
            edges = edges_aux;
        }
    }

    return edges;
}

//retorn as posicoes das arestas vizinhas dentro do vetor edge
int *MeshFactory::getNeighborEdges(pair<Vec3, Vec3> edge, vector< pair<Vec3,Vec3> > edges)
{
    int output[4];
    int pos=-1;

    for(unsigned int i=0; i<edges.size(); i++)
    {
        if(!edgeEqual(edges.at(i), edge))
        {
            if((edge.first == edges.at(i).first)
                || (edge.second == edges.at(i).first)
                || (edge.second == edges.at(i).second))
            {
                output[++pos] = i;
            }
        }
    }

    return output;
}

int *MeshFactory::getNeighborFaces(pair<Vec3, Vec3> edge, vector<Face> faces)
{
    int output[2];
    int pos=-1;

    for(unsigned int i=0; i<faces.size(); i++)
    {
        vector< pair<Vec3,Vec3> > edges = faces.at(i).getEdges();

        for(unsigned int j=0; j<edges.size(); j++)
        {
            if(edgeEqual(edges.at(i), edge))
            {
                output[++pos] = i;
            }
        }
    }

    return output;
}

bool MeshFactory::edgeEqual(pair<Vec3, Vec3> e1, pair<Vec3, Vec3> e2)
{
//    if(
//    ((e1.at(j).first == e2.at(k).first)
//        && (e1.at(j).second == e2.at(k).second))
//    ||
//    ((e1.at(j).first == e2.at(k).second)
//        && (e1.at(j).second == e2.at(k).first))
//    )
//    {
//        return true;
//    }
//    return false;
}

bool MeshFactory::edgeEqual(MEdge e1, MEdge e2)
{
    if((e1.getEnd() == e2.getEnd()) && (e1.getStart() == e2.getStart())
        || (e1.getStart() == e2.getEnd()) && (e1.getEnd() == e2.getStart()))
    {
        return true;
    }
    return false;
}

bool MeshFactory::edgeEqual(MEdge e1, pair<Vec3, Vec3> e2)
{
//    if(
//    ((e1.getStart() == e2.at(k).first)
//        && (e1.getEnd() == e2.at(k).second))
//    ||
//    ((e1.getStart() == e2.at(k).second)
//        && (e1.getEnd() == e2.at(k).first))
//    )
//    {
//        return true;
//    }
//    return false;
}

void MeshFactory::buildEdge(Mesh *mesh, int eID, MVertex *vs, MVertex *ve)
{
    mesh->addEdge(to_string(eID), new MEdge(to_string(eID)));
    mesh->getEdge(to_string(eID))->setStart(vs);
    mesh->getEdge(to_string(eID))->setEnd(ve);
}

void MeshFactory::makeAdjascents(Mesh *mesh, int eID, MEdge *rprev, MEdge *lnext, MEdge *rnext, MEdge *lprev)
{
    mesh->getEdge(to_string(eID))->setLnext(lnext);
    mesh->getEdge(to_string(eID))->setLprev(lprev);
    mesh->getEdge(to_string(eID))->setRnext(rnext);
    mesh->getEdge(to_string(eID))->setRprev(rprev);
}

void MeshFactory::linkEdgeFace(Mesh *mesh, int eID, int RfID, int LfID)
{
    mesh->getEdge(to_string(eID))->setLeft(mesh->getFace(to_string(LfID)));
    mesh->getEdge(to_string(eID))->setRight(mesh->getFace(to_string(RfID)));
}
