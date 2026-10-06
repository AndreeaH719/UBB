#include "GraphService.h"
#include <algorithm>
#include <stdexcept>
#include <unordered_set>

GraphService::GraphService(GraphClass *g) : graph(g) {}

const std::vector<int>& GraphService::getInbound(int vertex) const {
	return graph->getInbound(vertex);
}

const std::vector<int>& GraphService::getOutbound(int vertex) const {
	return graph->getOutbound(vertex);
}


int GraphService::getCost(int x, int y) const
{
	auto& costMap = graph->getCostDict();
	auto it = costMap.find({x, y});
	if (it == costMap.end())
	{
		throw std::runtime_error("Edge does not exist");
	}
	return it->second;
}

void GraphService::addEdge(int x, int y, int cost)
{
	auto& costMap = graph->getCostDict();
	if (costMap.find({ x, y }) != costMap.end())
		throw std::runtime_error("Edge already exists");
	graph->addEdge(x, y, cost);
}

void GraphService::removeEdge(int x, int y)
{
	auto &costMap = graph->getCostDict();

	if (costMap.find({x, y}) == costMap.end())
	{
		throw std::runtime_error("Edge does not exist");
	}

	graph->removeEdge(x, y);
}

void GraphService::addVertex(int vertex) {
	std::vector<int> vertexList = graph->getVertexList();
	if (std::find(vertexList.begin(), vertexList.end(), vertex) != vertexList.end())
		throw std::runtime_error("Vertex already exists");

	graph->addVertex(vertex);
}

void GraphService::removeVertex(int vertex) {
	std::vector<int> vertexList = graph->getVertexList();
	if (std::find(vertexList.begin(), vertexList.end(), vertex) == vertexList.end())
		throw std::runtime_error("Vertex does not exist");

	graph->removeVertex(vertex);
}

std ::vector<int> GraphService::outEdges(int vertex) const
{
	return graph->getOutbound(vertex);
}

std::vector<int> GraphService::inEdges(int vertex) const
{
	return graph->getInbound(vertex);
}

int GraphService::getVertices() const
{
	return graph->getVertices();
}

int GraphService::getEdges() const
{
	return graph->getEdges();
}

const std::unordered_map<std::pair<int, int>, int, PairHash>& GraphService::getCostDict() const
{
	return graph->getCostDict();
}

/*
std::vector<int> GraphService::getVertexList() const {
	std::vector<int> vertices;
	for (int v = 0; v < graph->getVertices(); ++v)
		vertices.push_back(v);
	return vertices;
}*/
std::vector<int> GraphService::getVertexList() const {
	return graph->getVertexList();
}

void GraphService::changeCost(int from, int to, int newCost)
{
	graph->changeCost(from, to, newCost);
}

GraphClass* GraphService::getGraph() const {
	return graph;
}

GraphService* GraphService::copyGraph() const
{
    GraphClass *original = this->graph;

	GraphClass* copy = new GraphClass(0);
	for(int v:original->getVertexList())
	    copy->addVertex(v);

	for (const auto& pairCost : original->getCostDict())
	{
		int from = pairCost.first.first;
		int to = pairCost.first.second;
		int cost = pairCost.second;
		copy->addEdge(from, to, cost);
	}

	return new GraphService(copy);
}



void GraphService::dfsUtil(int vertex, std::unordered_set<int>& visited, std::vector<int>& component) const {
	visited.insert(vertex);//the vertex to the visited list
	component.push_back(vertex);//add it to the current component

	//take all the neigbours fof the vertex
	std::vector<int> neighbors = graph->getOutbound(vertex);
	const std::vector<int>& inNeighbors = graph->getInbound(vertex);
	neighbors.insert(neighbors.end(), inNeighbors.begin(), inNeighbors.end());

	//eliminate the duplicates
	std::sort(neighbors.begin(), neighbors.end());
	neighbors.erase(std::unique(neighbors.begin(), neighbors.end()), neighbors.end());

	for (int neighbor : neighbors) {
		if (visited.find(neighbor) == visited.end()) {
		    //if it s not visited we go recursively to next node(its neighbour)
			dfsUtil(neighbor, visited, component);
		}
	}
}

std::vector<std::vector<int>> GraphService::connectedComponents() const {
	std::unordered_set<int> visited;
	std::vector<std::vector<int>> components;

	//go through to all the vertices
	for (int v : graph->getVertexList()) {
		if (visited.find(v) == visited.end()) 
		{   
		    //if it s not visited
			std::vector<int> component;
			dfsUtil(v, visited, component);//in the component will be stored all the current connected component
			std::sort(component.begin(), component.end());
			components.push_back(component);//add it to the final list of connected components
		}
	}

	return components;
}

std::pair<std::vector<int>, int> GraphService::lowestCostWalk(int s, int t)
{
	std::vector<int> vertices = graph->getVertexList();
	std::sort(vertices.begin(), vertices.end());

	int n = vertices.size();
	const int INF = 1000000000;

	std::unordered_map<int, int> idx;
	std::unordered_map<int, int> inv;

	for (int i = 0; i < n; i++)
	{
		idx[vertices[i]] = i;
		inv[i] = vertices[i];
	}

	// dist[x][k] = minimum cost from s to x with exactly k edges
	std::vector<std::vector<int>> dist(n, std::vector<int>(n + 1, INF));
	std::vector<std::vector<int>> parent(n, std::vector<int>(n + 1, -1));

	dist[idx[s]][0] = 0;

	// Build matrix
	for (int k = 1; k <= n; k++)
	{
		for (const auto& edge : graph->getCostDict())
		{
			int u = edge.first.first;
			int v = edge.first.second;
			int cost = edge.second;

			if (dist[idx[u]][k - 1] != INF)
			{
				int newCost = dist[idx[u]][k - 1] + cost;

				if (newCost < dist[idx[v]][k])
				{
					dist[idx[v]][k] = newCost;
					parent[idx[v]][k] = idx[u];
				}
			}
		}
	}

	// Negative cycle detection
	for (const auto& edge : graph->getCostDict())
	{
		int u = edge.first.first;
		int v = edge.first.second;
		int cost = edge.second;

		if (dist[idx[u]][n - 1] != INF &&
			dist[idx[u]][n - 1] + cost < dist[idx[v]][n])
		{
			throw std::runtime_error("Negative cost cycle reachable from source");
		}
	}

	int bestCost = INF;
	int bestK = -1;

	for (int k = 0; k <= n; k++)
	{
		if (dist[idx[t]][k] < bestCost)
		{
			bestCost = dist[idx[t]][k];
			bestK = k;
		}
	}

	if (bestCost == INF)
		throw std::runtime_error("No path exists");

	// Reconstruct path
	std::vector<int> path;
	int current = idx[t];
	int k = bestK;

	while (current != -1 && k >= 0)
	{
		path.push_back(inv[current]);
		current = parent[current][k];
		k--;
	}

	std::reverse(path.begin(), path.end());

	return { path, bestCost };
}