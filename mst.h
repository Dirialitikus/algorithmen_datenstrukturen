#ifndef MST_H
#define MST_H
#include "graph.h"
#include <iostream>


class MST : public Graph
{
private:
    int numvertices;
    double gewicht = 0;
public:
    MST();
    MST(Graph& g);
    void MakeMST(Graph & g);
    double GetMinDvertex(Graph&g, int& v, int& w, bool isVisited[]);
    void setGewicht(double d){this->gewicht = gewicht + d;}
    double getGewicht(){return this->gewicht;}
};

#endif // MST_H
