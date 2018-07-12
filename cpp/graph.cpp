// To run the program, try the command below:
// g++ graph.cpp -lgtest_main -lgtest

// some common graph functionalities.

#include <iostream>
#include <string>
#include <limits.h>
#include "gtest/gtest.h"

#include <list>

class Graph {
    int vertices;
    std::list<int> *adjacent; // Pointer to an array of adjacent lists

    public:
        Graph(int vertices);
        void addEdge (int vertices, int value);
        std::string breadthFirstTraversal (int source);
        std::string depthFirstTraversal ();
        void depthFirstTraversalUtil (int source, bool visited[], std::string& traversedString);
};

Graph::Graph (int vertices) {
    this->vertices = vertices;
    adjacent = new std::list<int>[vertices];
}

void Graph::addEdge (int vertices, int value) {
    adjacent[vertices].push_back(value);
}

std::string Graph::breadthFirstTraversal (int source) {
    std::string traversedString = "";

    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    visited[source] = true;
    std::list<int> queue;
    queue.push_back(source);

    while ( !queue.empty()) {
        source = queue.front();
        traversedString = traversedString + std::to_string(source);
        queue.pop_front();

        for (std::list<int>::iterator i = adjacent[source].begin(); i != adjacent[source].end(); i++) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }

    return traversedString;
}

void Graph::depthFirstTraversalUtil (int source, bool visited[], std::string& traversedString) {
    visited[source] = true;
    traversedString = traversedString + std::to_string(source);

    for (std::list<int>::iterator i = adjacent[source].begin(); i != adjacent[source].end(); i++) {
        if (!visited[*i]) {
            depthFirstTraversalUtil(*i, visited, traversedString);
        }
    }
}

std::string Graph::depthFirstTraversal () {
    std::string traversedString = "";
    bool *visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            depthFirstTraversalUtil(i, visited, traversedString);
        }
    }

    return traversedString;
}

Graph initialise () {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    return g;
}

TEST(GraphTest, BreadthFirstTraversal) {
    Graph g = initialise();
    EXPECT_EQ("2031", g.breadthFirstTraversal(2));
}

TEST(GraphTest, DepthFirstTraversal) {
    Graph g = initialise();
    EXPECT_EQ("0123", g.depthFirstTraversal());
}

