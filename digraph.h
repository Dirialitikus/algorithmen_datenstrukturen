#ifndef DIGRAPH_H
#define DIGRAPH_H
#include <vector>
#include <iostream>

using namespace std;


class Digraph
{
private:
    class Vertex{
        int id = 0;
        int dauer = 0;
        int indegree = 0;
        string name = "";
        int order = 1;
        vector <Vertex*> neighbour;
        bool isReady = false;
    public:
        Vertex(int id, string name, int dauer){this->id = id; this->name = name; this->dauer = dauer;};
        Vertex(){ };
        ~Vertex(){ };
        vector <Vertex*> getVec(){return this->neighbour;}
        void setIndegree(){this->indegree += 1;}
        int getIndegree(){return this->indegree;}
        int getId(){return this->id;}
        int getDauer(){return this->dauer;}
        string getName(){return this->name;}
        void setOrder(int ord){this->order = ord;}
        int getOrder(){return this->order;}
        void addArc(Vertex* ptr){this->neighbour.push_back(ptr);}
    };

    int numvertices = 0;;
    vector<Vertex*> vertex;
public:
    int gesamtDauer = 0;
    Digraph();
    void insertVertex(int id, string name, int dauer);
    void insertArc(int v, int w);
    void printProject();
    void operator=(Digraph& g);
    void topSort();
    void printTopSort();



    int FirstVertex(); // Erster Knoten des Graphen
    int NextVertex(int n); // nächster Knoten nach n (-1 wenn keiner existiert)
    int FirstArc(int v); // Erste Kante des Knoten v des Graphen
    int NextArc(int v, int n); // nächste Kante des Knotens v nach n (-1 wenn keiner existiert)

    bool IsArc(int v, int w); // existiert Kante (v,w)?


    void incrementNumVertices(){this->numvertices++;}
    int getNumVertices(){return this->numvertices;}
};

#endif // DIGRAPH_H
