#include "GraphClass.h"
#include <stdexcept>
#include <algorithm>


//constructor
GraphClass::GraphClass(int vertices) : vertices(vertices) {
    for (int i = 0; i < vertices; ++i) {
        inbound[i] = std::vector<int>();
        outbound[i] = std::vector<int>();
    }
}


int GraphClass::getVertices() const {
    return static_cast<int>(inbound.size());
}

int GraphClass::getEdges() const {
    return static_cast<int>(cost.size());
}

const std::unordered_map<std::pair<int, int>, int, PairHash>& GraphClass::getCostDict() const {
    return cost;
}

const std::vector<int>& GraphClass::getInbound(int vertex) const {
    return inbound.at(vertex); 
}

const std::vector<int>& GraphClass::getOutbound(int vertex) const {
    return outbound.at(vertex);
}

void GraphClass::setInbound(int vertex, const std::vector<int>& edges) {
    inbound[vertex] = edges;
}

void GraphClass::setOutbound(int vertex, const std::vector<int>& edges) {
    outbound[vertex] = edges;
}


void GraphClass::addEdge(int from, int to, int edgeCost) {
    outbound[from].push_back(to);
    inbound[to].push_back(from);
    cost[{from, to}] = edgeCost;
}

std::vector<int> GraphClass::getVertexList() const {
    std::vector<int> verticesList;
    for (const auto& pair : inbound) {  
        verticesList.push_back(pair.first);
    }
    return verticesList;
}



void GraphClass::removeVertex(int vertex) {
    if (inbound.find(vertex) == inbound.end())
        throw std::runtime_error("Vertex does not exist");

    for (int to : outbound[vertex]) {
        auto& inVec = inbound[to];
        inVec.erase(std::remove(inVec.begin(), inVec.end(), vertex), inVec.end());
        cost.erase({ vertex, to });
    }

    for (int from : inbound[vertex]) {
        auto& outVec = outbound[from];
        outVec.erase(std::remove(outVec.begin(), outVec.end(), vertex), outVec.end());
        cost.erase({ from, vertex });
    }

    inbound.erase(vertex);
    outbound.erase(vertex);
}

void GraphClass::removeEdge(int from, int to) {
    auto it = cost.find({ from, to });
    if (it == cost.end())
        throw std::runtime_error("Edge does not exist");

    cost.erase(it);

    auto& outVec = outbound[from];
    outVec.erase(std::remove(outVec.begin(), outVec.end(), to), outVec.end());

    auto& inVec = inbound[to];
    inVec.erase(std::remove(inVec.begin(), inVec.end(), from), inVec.end());
}

void GraphClass::addVertex(int vertex) {
    if (inbound.find(vertex) != inbound.end())
        throw std::runtime_error("Vertex already exists");

    inbound[vertex] = std::vector<int>();
    outbound[vertex] = std::vector<int>();
}


void GraphClass::changeCost(int x, int y, int newCost)
{
    auto it = cost.find({ x, y });
    if (it == cost.end())
        throw std::runtime_error("Edge does not exist");

    it->second = newCost;
}