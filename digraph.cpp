#include "digraph.h"
#include <queue>

Digraph::Digraph()
{

}

void Digraph::insertVertex(int id, string name, int dauer)
{
    Vertex* newVertex = new Vertex(id, name, dauer);
    this->vertex.push_back(newVertex);
    this->numvertices++;
}

void Digraph::insertArc(int v, int w)
{
    Vertex* tmp = vertex[w];
    vertex[v]->addArc(tmp);
    vertex[w]->setIndegree();
}

void Digraph::printProject()
{
    for(int i = 0; i<numvertices; i++){
        for(u_int j = 0; j<this->vertex[i]->getVec().size(); j++){
            cout << this->vertex[i]->getName() << " Nachbarn:" << this->vertex[i]->getVec()[j]->getName() << " Dauer:" << this->vertex[i]->getVec()[j]->getDauer() << "\n";
        }
        cout << endl;
    }
}

void Digraph::operator=(Digraph &g)
{
    for(int i = 0; i<g.numvertices; i++){
        Vertex* newVertex = new Vertex(g.vertex[i]->getId(), g.vertex[i]->getName(), g.vertex[i]->getDauer());
        this->vertex.push_back(newVertex);
    }

    for(int i = 0; i<numvertices; i++){
        for(u_int j = 0; j<g.vertex[i]->getVec().size(); j++){
            this->insertArc(i,g.vertex[i]->getVec()[j]->getId());
            this->vertex[i]->setIndegree();
        }
    }


}

void Digraph::topSort()
{
    int* indegree = new int[numvertices];
    queue <int> q;
    int v = this->FirstVertex();
    int ord = 1;
    int gesamtDauer = 0;

    while(v != -1){
        indegree[v] = this->vertex[v]->getIndegree();
        if(vertex[v]->getIndegree() == 0)
            q.push(v);

        v = this->NextVertex(v);
    }

    while(!q.empty()){
        v = q.front();
        q.pop();
        this->vertex[v]->setOrder(ord);
        ord++;
        int w = this->FirstArc(v);

        while(w != -1){
            indegree[w] -= 1;
            if(indegree[w] == 0)
                q.push(w);
            w = this->NextArc(v, w);
        }
    }

    bool isDone[numvertices];
    for(int i = 0; i<numvertices; i++)
        isDone[i] = false;

    for(int i = 0; i<numvertices; i++){
        if(vertex[i]->getIndegree() == 0)
            gesamtDauer += vertex[i]->getDauer();
        int tmpW = 0;
        for(u_int j = 0; j<vertex[i]->getVec().size(); j++){
            int nID = vertex[i]->getVec()[j]->getId();
            if(tmpW<vertex[i]->getVec()[j]->getDauer() && isDone[nID] == false){
                tmpW = vertex[i]->getVec()[j]->getDauer();
                isDone[nID] = true;
            }
        }

        gesamtDauer += tmpW;

    }

    this->gesamtDauer = gesamtDauer;

    delete [] indegree;
}

void Digraph::printTopSort()
{
    for(int i = 0; i<numvertices; i++){
        for(int j = 0; j<numvertices; j++){
            if(vertex[j]->getOrder() == i)
                cout << i << ". " << vertex[j]->getName() << " "<<vertex[j]->getDauer() << endl;
        }
    }

    cout << numvertices << ". " << vertex[numvertices-1]->getName() << " "<<vertex[numvertices-1]->getDauer() << endl;
    cout << "Gesamtdauer des Projekts: " << this->gesamtDauer;
}

int Digraph::FirstVertex()
{
    return 0;
}

int Digraph::NextVertex(int n)
{
    if(n<(numvertices -1))
        return n+1;
    else
        return -1;
}

int Digraph::FirstArc(int v)
{
    Vertex* thisVertex = NULL;
    int Arc = -1;

    thisVertex = vertex[v];

    if(thisVertex->getVec().size()>0)
        Arc = thisVertex->getVec()[0]->getId();

    return Arc;
}

int Digraph::NextArc(int v, int n)
{
    Vertex* from = NULL;
    int Arc = -1;

    from = this->vertex[v];

    for(u_int i = 0; i<from->getVec().size(); i++){
        if(from->getVec()[i]->getId() == n){
            if(i < (from->getVec().size() -1)){
                Arc = from->getVec()[i+1]->getId();
            }
        }
    }

    return Arc;
}

bool Digraph::IsArc(int v, int w)
{
    bool isArc = false;
    Vertex* from = NULL;
    Vertex* to = NULL;

    from = vertex[v];
    to = vertex[w];

    for(u_int i = 0; i<from->getVec().size(); i++){
        if(from->getVec()[i] == to)
            isArc = true;
    }

    return isArc;
}
