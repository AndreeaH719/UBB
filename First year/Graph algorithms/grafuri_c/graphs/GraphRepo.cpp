#include "GraphRepo.h"
#include "GraphService.h"

//constructor
GraphRepo::GraphRepo(const std::string& fileName) : fileName(fileName), graph(nullptr) {
	if (!fileName.empty()) {
		graph = loadFile(fileName);
	}
}

GraphRepo::~GraphRepo() {
	delete graph;
}

GraphClass* GraphRepo::loadFile(const std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw std::runtime_error("Cannot be opened: " + fileName);
	}
	int n, m;
	file >> n >> m;
	GraphClass* g = new GraphClass(n);
	GraphService service(g);

	for (int i = 0; i < m; i++)
	{
	   int x, y, cost;
	   file >> x >> y >> cost;
	   service.addEdge(x, y, cost);
	}

	file.close();
	return g;
}

GraphClass* GraphRepo::getGraph() const
{
	return graph;
}

void GraphRepo::saveFile(const std::string& fileName)
{
	if(!graph) return;

	std::ofstream file(fileName);
	if (!file.is_open())
	{
		throw std::runtime_error("Cannot be opened: " + fileName);
	}

	int n = graph->getVertices();
	int m = graph->getEdges();
	file << n << " " << m << "\n";

	const auto& costDict = graph->getCostDict();
	for (const auto& pairCost : costDict)
	{
		int x = pairCost.first.first;
		int y = pairCost.first.second;
		int cost = pairCost.second;
		file << x << " " << y << " " << cost << "\n";
	}

	file.close();
}

GraphClass* GraphRepo::createRandomGraph(int n, int m)
{
	if(n < 0 || m < 0)
		throw std::invalid_argument("Number must be positive.");

	GraphClass* g = new GraphClass(n);
	GraphService service(g);

	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> vertexDist(0, n-1);
	std::uniform_int_distribution<> costDist(1, 100);

	int edgesAdded = 0;
	while (edgesAdded < m)
	{
		int x = vertexDist(gen);
		int y = vertexDist(gen);
		const auto& costDict = g->getCostDict();
		if (costDict.find({ x, y }) == costDict.end())
		{
			int cost = costDist(gen);
			service.addEdge(x, y, cost);
			edgesAdded++;
		}
	}
	delete graph;
	graph = g;
	return g;
}