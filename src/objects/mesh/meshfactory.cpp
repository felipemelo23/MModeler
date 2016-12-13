#include "meshfactory.h"

Mesh *MeshFactory::buildGenMesh(vector<Vec3 *> vertices, vector<Face> faces)
{
//para converter de PolygonMesh para Winged Edge, precisamos primeiro saber todas
//as arestas existentes no modelo. Apenas precisaremos de uma delas, portanto
//arestas repetidas nao serao contadas.
    vector< pair<Vec3,Vec3> > edges = getEdges(faces);
    unsigned int i=0;

    Mesh* mesh = new Mesh();
//vamos então criar as WEDs
    buildGenMesh_recursive(faces, mesh, edges.size());
}

void MeshFactory::buildGenMesh_recursive(vector< pair<Vec3,Vec3> > edges, Mesh *mesh, int edge_qtd, int eID, int vID, int fID, int it, int parent_edge)
{
    if(it==1)
    {
    //criando a primeira aresta:
    //adicionamos a aresta a malha:
        mesh->addEdge(to_string(++eID), new MEdge(to_string(eID)));
        pair<Vec3,Vec3> edge = edges.at(eID);
        int p_edge = eID;

    //adicionamos seus vertices a malha:
        mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), edge.first.getX(), edge.first.getY(), edge.first.getZ()));
        mesh->addVertex(to_string(++vID), new MVertex(to_string(vID), to_string(eID), edge.second.getX(), edge.second.getY(), edge.second.getZ()));
    //linkamos estes vertices com a aresta:
        mesh->getEdge(to_string(eID))->setStart(mesh->getVertex(to_string(vID-1)));
        mesh->getEdge(to_string(eID))->setEnd(mesh->getVertex(to_string(vID)));
    //adicionamos duas faces a malha:
        mesh->addFace(to_string(++fID), new MFace(to_string(fID), to_string(eID)));
        mesh->addFace(to_string(++fID), new MFace(to_string(fID), to_string(eID)));
    //linkamos as duas faces na aresta:
        mesh->getEdge(to_string(eID))->setLeft(mesh->getFace(to_string(fID-1)));
        mesh->getEdge(to_string(eID))->setLeft(mesh->getFace(to_string(fID)));
    //adicionamos entao quatro arestas adjascentes:
        for(int i=0; i<4; i++)
        {
            buildGenMesh_recursive(edges,mesh,eID,vID,fID,++it,edge_qtd,p_edge);
        }
    }
    else if(it == edge_qtd)
    {
        break;
    }
    else if(it>1)
    {
    //primeiramente vamos observar as arestas adjascente a aresta pai:
        int *pos_neighbors = getNeighborEdges(edges.at(parent_edge), edges);

    //precisamos enchaixar a nova aresta em alguma das quatro arestas adjascentes a aresta pai
        if(mesh->getEdge(parent_edge)->getRnext() == NULL)  //se eh possivel inserir uma aresta ncw
        {

        }
        else if(mesh->getEdge(parent_edge)->getRprev() == NULL)  //se eh possivel inserir uma aresta pcw
        {

        }
        else if(mesh->getEdge(parent_edge)->getLnext() == NULL)  //se eh possivel inserir uma aresta nccw
        {

        }
        else if(mesh->getEdge(parent_edge)->getLprev() == NULL)  //se eh possivel inserir uma aresta pccw
        {

        }
    }
}

Mesh *MeshFactory::buildBox()
{

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
