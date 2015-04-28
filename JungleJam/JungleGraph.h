#ifndef JUNGLEGRAPH_H_INCLUDED
#define JUNGLEGRAPH_H_INCLUDED
#include <vector>
#include <iostream>

struct vertex;

struct adjVertex{
    vertex *v;
    int weight;
};

struct vertex{
    std::string name;
    bool visited;
    int distance;
    vertex *previous;
    std::vector<adjVertex> adj;
};

class Graph
{
public:
    Graph();
    ~Graph();
    void addEdge(std::string v1, std::string v2, int weight);
    void addVertex(std::string name);
    void displayEdges();
    void findShortestDistance(std::string starting, std::string destination);
    void viewADJvertex(std::string location);
    void Dijkstra(std::string starting, std::string destination);
protected:
private:
    std::vector<vertex> vertices;
};


#endif // JUNGLEGRAPH_H_INCLUDED
