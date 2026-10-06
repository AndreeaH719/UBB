#pragma once
#include "GraphClass.h"
#include <string>
#include <fstream>
#include <random>
#include <stdexcept>
#include <iostream>

class GraphRepo {
private:
    std::string fileName;
    GraphClass* graph;  

  

public:
    GraphRepo(const std::string& fileName = "");
    ~GraphRepo();

    GraphClass* getGraph() const;
    void saveFile(const std::string& fileName);
    GraphClass* createRandomGraph(int n, int m);

    void setGraph(GraphClass *g) {graph = g; } 
    GraphClass* loadFile(const std::string& fileName);
   
};
