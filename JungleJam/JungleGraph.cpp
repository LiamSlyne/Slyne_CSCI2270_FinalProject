#include "JungleGraph.h"
#include <vector>
#include <iostream>

using namespace std;

Graph::Graph()
{
    clockTemp = 0;
}

Graph::~Graph()
{
    //dtor
}

void Graph::addEdge(string v1, string v2, int weight)
{
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == v1)
        {
            for(int j = 0; j < vertices.size(); j++)
            {
                if(vertices[j].name == v2 && i != j)
                {
                    adjVertex av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);

                    adjVertex av2;
                    av2.v = &vertices[i];
                    av2.weight = weight;
                    vertices[j].adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n)
{
    bool found = false;
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].name == n)
        {
            found = true;
        }
    }
    if(found == false)
    {
        vertex v;
        v.name = n;
        vertices.push_back(v);
    }
}

void Graph::displayEdges()
{
    for(int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].name << "--->";
        for(int j = 0; j < vertices[i].adj.size(); j++)
        {
            cout << vertices[i].adj[j].v->name << " - ";
        }
        cout << endl;
    }
}

void Graph::findShortestDistance(string starting, string destination)
{
    vertex *s = NULL;
    vertex *d = NULL;
    bool find1 = false;
    bool find2 = false;
    bool dist = true;
    int minDistance;
    vector<vertex*> solved;
    vector<vertex> minV;
    for (int i = 0; i < vertices.size(); i++)
    {
        vertices[i].visited = false;
        vertices[i].previous = NULL;
        vertices[i].distance = 32767;
        if (starting == vertices[i].name){
            s = &vertices[i];
            find1 = true;
        }
        if (destination == vertices[i].name)
        {
            d = &vertices[i];
            find2 = true;
        }
    }
    if (find1 && find2)
    {
        s->visited = true;
        s->distance = 0;
        solved.push_back(s);
        vertex *u = NULL;
        vertex *min = NULL;
        vertex *prevVertex = NULL;
        int edgeW = 0;
        while (d->visited == false)
        {
            minDistance = 32767;
            for (int i = 0; i < solved.size(); i++)
            {
                u = solved[i];
                for (int j = 0; j< u->adj.size(); j++)
                {
                    if (u->adj[j].v->visited == false)
                    {
                        edgeW = u->distance + u->adj[j].weight;
                        if (edgeW < minDistance)
                        {
                            minDistance = edgeW;
                            min = u->adj[j].v;
                            prevVertex = u;
                        }
                    }
                }
            }
            solved.push_back(min);
            min->distance = minDistance;
            min->previous = prevVertex;
            min->visited = true;
        }
        vector <string> path;
        vertex *temp = d;
        while (temp != NULL)
        {
            path.push_back(temp->name);
            temp = temp->previous;
        }
        cout << "It took " << d->distance << " seconds for you to travel ";
        clockTemp = d->distance;
        for (int i = path.size() - 1; i >=0; i--)
        {
            cout << "--->" << path[i];
        }
        cout << endl;
    }
    if (find1 == false || find2 == false){
        cout << "That location does not exist." << endl;
    }
}

void Graph::viewADJvertex(string location)
{

}
