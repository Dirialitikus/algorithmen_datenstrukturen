#ifndef GRAPH_H
#define GRAPH_H


/***************************************************************************/
// Aufgaben 1-4


#include <string>
#include <limits>
#include <iostream>
#include <vector>

using namespace std;

const double MAXFLOAT = numeric_limits<float>::max();

const double noArc = MAXFLOAT;
const double INFINITY = MAXFLOAT;
const int maxNodes = 25;

class Graph {
private:
    class Vertex {
        vector <pair<Vertex*,double>> neighbour;
        string name = "";
        int id = 0;
        double distance = 0;
        Vertex* previous = NULL;
        int indegree = 0;

    public:
        void setVertex(int id, string name){this->id = id; this->name = name; }
        vector <pair<Vertex*,double>> getVec(){return this->neighbour;}
        void incrementIndegree(){this->indegree += 1;}
        void addArc(pair<Vertex*, double> m);
        int getID(){return this->id;}
        string getName(){return this->name;}
        void setVertexCpy(int id, string name, int ind){this->id = id; this->name = name; this->indegree = ind;}
        int getInd(){return this->indegree;}
        void setPrevious(Vertex* thisV){this->previous = thisV;}
        void setDistance(double d){this->distance = d;}
        Vertex* getPrevious(){return this->previous;}
        double getDistance(){return this->distance;}

    };

    int numvertices; // Anzahl der Knoten eines Graphen

    vector <Vertex*> vertex;


public:
    Graph();
    virtual ~Graph(){ };
    Graph(Graph & g){ g = *this; };

    // Operationen auf einem Graphen:

    void InsertVertex(int m, string s); // fügt neuen Knoten m mit Markierung m ein
    void InsertArc(int v, int w, double weight); // fügt neue Kante (v,w) mit Gewicht weight ein

    int FirstVertex(); // Erster Knoten des Graphen
    int NextVertex(int n); // nächster Knoten nach n (-1 wenn keiner existiert)

    bool IsArc(int v, int w); // existiert Kante (v,w)?
    double GetArc(int v, int w); // gibt Kantenbewertung  von (v,w) zurück
    int FirstArc(int v); // Erste Kante des Knoten v des Graphen
    int NextArc(int v, int n); // nächste Kante des Knotens v nach n (-1 wenn keiner existiert)

    int GetNumVertices(){return this->numvertices;}; // Anzahl der Knoten

    // weitere bei Bedarf ergänzen

    Vertex* getVertex(int i){return this->vertex[i];}
    vector <Vertex*> getVec(){return this->vertex;}
    void Dfs(Graph& g, int n, bool isVisited[]);
    void Dijkstra(/*Vertex* start, Vertex* end*/);
    int minDist(double distance[], bool isVisited[]);
    void dijkstraAlleVerbindungen();
    string GetVertexName(int v){return this->getVec()[v]->getName();}

    void operator=(Graph& g);


};

#endif // GRAPH_H
