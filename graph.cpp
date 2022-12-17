#include "graph.h"
#include <sstream>
#include <stack>

Graph::Graph()
{
    numvertices = 0;

}


void Graph::InsertVertex(int m, string s)
{
    static int i = 0;
    Vertex* newVertex = new Vertex;
    newVertex->setVertex(m, s);
    i++;
    numvertices++;

    this->vertex.push_back(newVertex);

}

void Graph::InsertArc(int v, int w, double weight)
{
    Vertex* vertexOne = NULL;
    Vertex* vertexTwo = NULL;

    vertexOne = this->getVertex(v);
    vertexTwo = this->getVertex(w);

    pair<Vertex*,double> conOne = make_pair(vertexTwo, weight);
    pair<Vertex*,double> conTwo = make_pair(vertexOne, weight);

    vertexOne->addArc(conOne);
    vertexTwo->addArc(conTwo);

    vertexOne->incrementIndegree();
    vertexTwo->incrementIndegree();

}

int Graph::FirstVertex()
{
    return 0;
}

int Graph::NextVertex(int n)
{
    if(n<(numvertices -1))
        return n+1;
    else
        return -1;
}

bool Graph::IsArc(int v, int w)
{
    bool isArc = false;
    Vertex* from = NULL;
    Vertex* to = NULL;

    from = getVec()[v];
    to = getVec()[w];

    for(u_int i = 0; i<from->getVec().size(); i++){
        if(from->getVec()[i].first == to)
            isArc = true;
    }

    return isArc;
}

double Graph::GetArc(int v, int w)
{
    Vertex* from  = NULL;
    Vertex* to = NULL;

    from = this->getVec()[v];
    to = this->getVec()[w];

    double weight = -1;

    for(u_int i = 0; i<from->getVec().size(); i++){
        if(from->getVec()[i].first == to)
            weight = from->getVec()[i].second;
    }

    return weight;
}

int Graph::FirstArc(int v)
{
    Vertex* thisVertex = NULL;
    int Arc = -1;

    thisVertex = this->getVec()[v];

    if(thisVertex->getVec().size()>0)
        Arc = thisVertex->getVec()[0].first->getID();

    return Arc;

}

int Graph::NextArc(int v, int n)
{
    Vertex* from = NULL;
    int Arc = -1;

    from = this->getVec()[v];

    for(u_int i = 0; i<from->getVec().size(); i++){
        if(from->getVec()[i].first->getID() == n){
            if(i < (from->getVec().size() -1)){
                Arc = from->getVec()[i+1].first->getID();
            }
        }
    }

    return Arc;
}

void Graph::Dfs(Graph &g, int v, bool isVisited[])
{
    if(!isVisited[v]){
        isVisited[v] = true;
        std::cout << "ID:" << this->getVec()[v]->getID() << " Name:" <<  this->getVec()[v]->getName() << std::endl ;
        int w = FirstArc(v);

        while(w != -1){
            if(!isVisited[w])
                Dfs(g, w, isVisited);
            w = g.NextArc(v, w);
        }
    }
}


int Graph::minDist(double distance[], bool isVisited[])
{

    int minimum = INT32_MAX;
    u_int index;
    u_int anzKnoten = vertex.size();


    for(u_int i = 0; i<anzKnoten; i++){
        if(isVisited[i] == false && distance[i] <= minimum){
            minimum = distance[i];
            index = i;
        }
    }

    return index;

}

void Graph::dijkstraAlleVerbindungen()
{


}


void Graph::Dijkstra(/*Graph::Vertex *begin, Graph::Vertex *end*/)
{
    stack<pair<string,double>> output;
    int n = 0;
    cout << "Geben sie ihren Flughafen an(ID): ";
    cin >> n;

    Vertex* start = this->getVec()[n];

    for(int i = 0; i<numvertices; i++){
        if(i !=n ){

            u_int anzKnoten = vertex.size();

            double distance[anzKnoten];
            bool isVisited[anzKnoten];


            int startID = n;
            int endID = i;


            for(u_int i = 0; i<anzKnoten; i++){
                distance[i] = INT32_MAX;
                isVisited[i] = false;
            }

            distance[startID] = 0;

            for(u_int i = 0; i<anzKnoten; i++){

                int min = minDist(distance,isVisited);
                isVisited[min] = true;
                if(isVisited[endID])
                    break;

                u_int anzNachbarn = vertex[min]->getVec().size();

                for(u_int j = 0; j<anzNachbarn; j++){

                    int indexNachbar = vertex[min]->getVec()[j].first->getID();
                    if(!isVisited[indexNachbar] && distance[min] != INT32_MAX && distance[min] + vertex[min]->getVec()[j].second < distance[indexNachbar]){
                        vertex[indexNachbar]->setPrevious(vertex[min]);
                        distance[indexNachbar] = distance[min] + vertex[min]->getVec()[j].second;
                        vertex[indexNachbar]->setDistance(distance[indexNachbar]);
                    }
                }
            }
            Vertex* current = new Vertex;
            current = vertex[endID];
            pair<string, double> newPair;
            newPair = make_pair(current->getName(),current->getDistance());
            output.push(newPair);

        }
    }

    int i = 1;
    while(!output.empty()){
        pair<string, double> newPair;
        newPair = output.top();
        output.pop();
        cout << i << ". Zielflughafen:" << newPair.first << " zurückgelegte Gesamtdistanz:" << newPair.second << ".000" << "\n";
        i++;
    }


    /*   Vertex* current = vertex[endID];

        stack<pair<string,double>> output;

        while(current->getPrevious() != NULL){
            pair<string, double> newPair;
            newPair = make_pair(current->getName(), current->getDistance());
            output.push(newPair);
            current = current->getPrevious();
        }

        pair<string, double> newPair;
        newPair = make_pair(current->getName(), current->getDistance());
        output.push(newPair);

        int i = 1;
        while(!output.empty()){
            pair<string, double> newPair;
            newPair = output.top();
            output.pop();
            cout << i << ". Hopname:" << newPair.first << " zurückgelegte Distanz:" << newPair.second << ".000" << "\n";
            i++;
        }
        */


}

void Graph::operator=(Graph &g)
{

    u_int size = g.GetNumVertices();

    for(u_int i = 0; i<size; i++){
        Vertex* newVertex = new Vertex;
        newVertex->setVertexCpy(g.getVec()[i]->getID(),g.getVec()[i]->getName(),g.getVec()[i]->getInd());
        this->vertex.push_back(newVertex);
    }

    for(u_int i = 0; i<size; i++){
        for(u_int j = 0; j<g.getVec()[i]->getVec().size(); j++){
            int m = g.getVec()[i]->getVec()[j].first->getID();
            pair<Vertex*, double> cpyPair = make_pair(this->vertex[m],g.getVec()[i]->getVec()[j].second);
            this->vertex[i]->addArc(cpyPair);
        }
    }

    this->numvertices = g.numvertices;

}



void Graph::Vertex::addArc(pair<Graph::Vertex *, double> m)
{
    this->neighbour.push_back(m);
}
