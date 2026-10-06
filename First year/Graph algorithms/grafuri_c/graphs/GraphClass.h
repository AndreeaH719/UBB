#pragma once
#include <vector>
#include <unordered_map>
#include <utility>
#include <functional>

struct PairHash {
    size_t operator()(const std::pair<int, int>& p) const{
        return std::hash<int>()(p.first)^(std::hash<int>()(p.second) << 1);
    }
};

class GraphClass {
private:
    int vertices;
    std::unordered_map<int, std::vector<int>> inbound;
    std::unordered_map<int, std::vector<int>> outbound;
    std::unordered_map<std::pair<int, int>, int, PairHash> cost;

public:
    GraphClass(int vertices);

	const std::unordered_map<std::pair<int, int>, int, PairHash>& getCostDict() const;
    int getVertices() const;
    int getEdges() const;

    const std::vector<int>& getInbound(int vertex) const;
    const std::vector<int>& getOutbound(int vertex) const;

    void setInbound(int vertex, const std::vector<int>& edges);
    void setOutbound(int vertex, const std::vector<int>& edges);

    void addEdge(int from, int to, int edgeCost);
    void removeEdge(int from, int to);

    
    void addVertex(int vertex);
    void removeVertex(int vertex);

    std::vector<int> getVertexList() const;

    void changeCost(int x, int y, int newCost);
 
};