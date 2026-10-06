#pragma once
#include "GraphClass.h"
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>

class GraphService
{
	private:
		GraphClass* graph;
	public:
	    GraphService(GraphClass *g);

		const std::vector<int>& getInbound(int vertex) const;
		const std::vector<int>& getOutbound(int vertex) const;

        int getCost(int x, int y) const;

		void addEdge(int x, int y, int cost);
		void removeEdge(int x, int y);
		
		void addVertex(int vertex);
		void removeVertex(int vertex);

		std::vector<int> outEdges(int vertex) const;
	    std::vector<int> inEdges(int vertex) const;

		int getVertices() const;
		int getEdges() const;

		const std::unordered_map<std::pair<int, int>, int, PairHash>& getCostDict() const;

		GraphService* copyGraph() const;

	    std::vector<int> getVertexList() const;

		void changeCost(int x, int y, int newCost);

		GraphClass* getGraph() const;
		 
		void dfsUtil(int vertex, std::unordered_set<int>& visited, std::vector<int>& component) const;

		std::vector<std::vector<int>> connectedComponents() const;
		std::pair<std::vector<int>, int> lowestCostWalk(int s, int t);
		
};
