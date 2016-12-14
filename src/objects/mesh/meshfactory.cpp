#include "meshfactory.h"

Mesh *MeshFactory::buildGenMesh(vector<Vec3 *> vertices, vector<Face> faces)
{

}

void MeshFactory::buildGenMesh_recursive(vector< pair<Vec3,Vec3> > edges, Mesh *mesh, int edge_qtd, int eID, int vID, int fID, int it, int parent_edge)
{

}

Mesh *MeshFactory::buildBox()
{

}

Mesh *MeshFactory::buildSphere()
{

}

vector<pair<Vec3, Vec3> > MeshFactory::getEdges(vector<Face> faces)
{

}

//retorn as posicoes das arestas vizinhas dentro do vetor edge
int *MeshFactory::getNeighborEdges(pair<Vec3, Vec3> edge, vector< pair<Vec3,Vec3> > edges)
{

}

bool MeshFactory::edgeEqual(pair<Vec3, Vec3> e1, pair<Vec3, Vec3> e2)
{

}
