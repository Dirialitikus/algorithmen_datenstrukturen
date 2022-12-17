#include "mst.h"

MST::MST()
{

}


MST::MST(Graph &g)
{
    this->numvertices = g.GetNumVertices();
    MakeMST(g);
}

void MST::MakeMST(Graph & g) {
    double weight = 0.0;
    bool isVisited[numvertices];

    // Achtung: alle Markierungen auf Basis von Graph g

    // Alle Knoten übertragen und Markierung auf false setzen
    for (int v = g.FirstVertex(); v != -1; v = g.NextVertex(v)) {
        InsertVertex(v, g.GetVertexName(v));

        isVisited[v] = false;
    }

    int v_0 = g.FirstVertex(); // Startknoten v_0;
    isVisited[v_0] = true; // markiere v_0 als besucht

    for (int i = 0; i < numvertices - 1; i++) {
        int v, w = 0;
        v = v_0;
        // Wähle eine Kante {v,w}, deren Gewicht minimal ist und die einen bereits markierten Knoten v mit einem noch unmarkierten Knoten w verbindet.
        weight += GetMinDvertex(g, v, w, isVisited);
        isVisited[w] = true; // markiere w als besucht
        this->setGewicht(g.GetArc(v,w));
        InsertArc(v, w, g.GetArc(v, w));
    }

    return;
}

double MST::GetMinDvertex(Graph &g, int& v, int& w, bool isVisited[])
{

    double min = 87848.0;
    double tmp = 5000;
    int tmpID;
    int tmpV;


    for(v = 0; v<this->numvertices; v++){
        if(isVisited[v]){
            for(u_int i = 0; i<g.getVec()[v]->getVec().size(); i++){
                tmpID = g.getVec()[v]->getVec()[i].first->getID();
                if(!isVisited[tmpID]){
                    tmp = g.GetArc(v, tmpID);
                    if(tmp<=min && tmp != -1){
                        min = tmp;
                        w = tmpID;
                        tmpV = v;
                    }
                }
            }
        }
    }

    v = tmpV;

    return min;
}
