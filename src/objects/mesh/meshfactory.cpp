#include "meshfactory.h"

Mesh *MeshFactory::buildGenMesh(vector<Vec3 *> vertices, vector<Face> faces)
{
//para converter de PolygonMesh para Winged Edge, precisamos primeiro saber todas
//as arestas existentes no modelo. Apenas precisaremos de uma delas, portanto
//arestas repetidas nao serao contadas.
    vector< pair<Vec3,Vec3> > edges = getEdges(faces);

    Mesh* mesh = new Mesh();

    int eID = -1;
    int vID = -1;
    int fID = -1;

//primeiro criamos as arestas com seus respectivos vertices finais:
    mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
    Vec3 newV = edges.at(eID).second;

    mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
    mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));

    for(unsigned int i=1; i<edges.size(); i++)
    {
        mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
        newV = edges.at(eID).second;

        for(int j=0; j <= eID; j++)
        {
            if(mesh->getEdge(to_string(j))->getEnd() != newV)
            {
                mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
                mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
            }
            else    //flipamos a aresta
            {
                newV = edges.at(eID).first;

                if(mesh->getEdge(to_string(j))->getStart() != newV)
                {
                    mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), newV.getX(), newV.getY(), newV.getZ()));
                    mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
                }
            }
        }
    }

//agora conferimos os pontos finais de todas as arestas e fazemos as ligações com os pontos iniciais:
    for(int i=0; i<=eID; i++)
    {
        Vec3 vStt = edges.at(i).first;

        for(int j=0; j<=eID; j++)
        {
            if(j!=i)
            {
                if(mesh->getEdge(to_string(j))->getEnd() == vStt)
                {
                    mesh->getEdge(to_string(i))->setStart(mesh->getEdge(to_string(j))->getEnd());
                }
            }
        }
    }

//sabendo os pontos iniciais e finais podemos entao setar as arestas adjascentes:
    for(int i=0; i<=eID; i++)
    {
        for(int j=0; j<=eID; j++)
        {
            if(j!=i)
            {
                if(mesh->getEdge(to_string(i))->getEnd() == mesh->getEdge(to_string(j))->getStart())
                {
                    mesh->getEdge(to_string(i))->setRnext(mesh->getEdge(to_string(j)));
                }
                else if(mesh->getEdge(to_string(i))->getEnd() == mesh->getEdge(to_string(j))->getEnd())
                {
                    mesh->getEdge(to_string(i))->setLprev(mesh->getEdge(to_string(j)));
                }
                else if(mesh->getEdge(to_string(i))->getStart() == mesh->getEdge(to_string(j))->getEnd())
                {
                    mesh->getEdge(to_string(i))->setRprev(mesh->getEdge(to_string(j)));
                }
                else if(mesh->getEdge(to_string(i))->getStart() == mesh->getEdge(to_string(j))->getStart())
                {
                    mesh->getEdge(to_string(i))->setLnext(mesh->getEdge(to_string(j)));
                }
            }
        }
    }

//por fim, como sabemos todos os vertices que pertencem as arestas, e as ligacoes entre as arestas adjascentes,
//basta consruirmos as faces:
    bool isInFace;

    for(int i=0; i<=eID; i++)
    {
        for(unsigned int j=0; j<faces.size(); j++)
        {
            vector< pair<Vec3,Vec3> > edges = faces.at(j).getEdges();
            isInFace=false;

            for(unsigned int k=0; k<edges.size; k++)
            {
                if(edgeEqual(*mesh->getEdge(i), edges.at(k)))
                {
                    isInFace=true;
                }
            }
            if(isInFace)
            {
                for(unsigned int k=0; k<edges.size; k++)
                {
                    if(edgeEqual(mesh->getEdge(i)->getRnext(), edges.at(k)))    //se contem o Rnext a face esta a direita
                    {
                        mesh->getEdge(i)->setRight(new MFace(to_string(++fID), mesh->getEdge(i)->getRnext()->getId()));
                    }
                    if(edgeEqual(mesh->getEdge(i)->getLnext(), edges.at(k)))    //se contem o Lnext a face esta a esquerda
                    {
                        mesh->getEdge(i)->setLeft(new MFace(to_string(++fID), mesh->getEdge(i)->getLnext()->getId()));
                    }
                }
            }
        }
    }

//a malha foi totalmente convertida para WED

    return mesh;
}

//void MeshFactory::buildGenMesh_recursive(vector<Face> faces, vector< pair<Vec3,Vec3> > edges, Mesh *mesh, int edge_qtd, int eID, int vID, int fID, int it, int parent_edge)
//{
//    if(it==1)
//    {
//    //criando a primeira aresta:
//    //adicionamos a aresta a malha:
//        mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
//        pair<Vec3,Vec3> edge = edges.at(eID);
//        int p_edge = eID;

//    //adicionamos seus vertices a malha:
//        mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), edge.first.getX(), edge.first.getY(), edge.first.getZ()));
//        mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), edge.second.getX(), edge.second.getY(), edge.second.getZ()));
//    //linkamos estes vertices com a aresta:
//        mesh->getEdge(to_string(eID))->setStart(mesh->getVertex(to_string(vID-1)));
//        mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
//    //adicionamos duas faces a malha:
//        mesh->addFace(to_string(++fID), new MFace(to_string(fID), to_string(eID)));
//        mesh->addFace(to_string(++fID), new MFace(to_string(fID), to_string(eID)));
//    //linkamos as duas faces na aresta:
//        mesh->getEdge(to_string(eID))->setRight(mesh->getFace(to_string(fID-1)));
//        mesh->getEdge(to_string(eID))->setLeft(mesh->getFace(to_string(fID)));
//    //adicionamos entao quatro arestas adjascentes:
//        for(int i=0; i<4; i++)
//        {
//            buildGenMesh_recursive(edges,mesh,eID,vID,fID,++it,edge_qtd,p_edge);
//        }
//    }
//    else if(it == edge_qtd)
//    {
//        break;
//    }
//    else if(it>1)
//    {
//    //primeiramente vamos observar as arestas adjascente a aresta pai:
//        int *pos_neighbors = getNeighborEdges(edges.at(parent_edge), edges);
//        int *pos_faces = getNeighborFaces(edges.at(parent_edge), faces);

//    //precisamos enchaixar a nova aresta em alguma das quatro arestas adjascentes a aresta pai
//        if(mesh->getEdge(parent_edge)->getRnext() == NULL)  //se eh possivel inserir uma aresta ncw
//        {

//        }
//        else if(mesh->getEdge(parent_edge)->getRprev() == NULL)  //se eh possivel inserir uma aresta pcw
//        {

//        }
//        else if(mesh->getEdge(parent_edge)->getLnext() == NULL)  //se eh possivel inserir uma aresta nccw
//        {

//        }
//        else if(mesh->getEdge(parent_edge)->getLprev() == NULL)  //se eh possivel inserir uma aresta pccw
//        {

//        }
//    }
//}

Mesh *MeshFactory::buildBox()
{
    Mesh* mesh = new Mesh();

    int eID = -1;
    int vID = -1;
    int fID = -1;

    for(int i=0; i<18; i++) //numero de arestas de um cubo triangularizado
    {
        mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
    }
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
    if(
    ((e1.at(j).first == e2.at(k).first)
        && (e1.at(j).second == e2.at(k).second))
    ||
    ((e1.at(j).first == e2.at(k).second)
        && (e1.at(j).second == e2.at(k).first))
    )
    {
        return true;
    }
    return false;
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
    if(
    ((e1.getStart() == e2.at(k).first)
        && (e1.getEnd() == e2.at(k).second))
    ||
    ((e1.getStart() == e2.at(k).second)
        && (e1.getEnd() == e2.at(k).first))
    )
    {
        return true;
    }
    return false;
}
