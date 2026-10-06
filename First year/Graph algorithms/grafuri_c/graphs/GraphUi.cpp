#include "GraphService.h"
#include "GraphRepo.h"
#include <iostream>
#include <limits>
#include "GraphUi.h"

Menu::Menu(GraphRepo* repo) : repository(repo), service(nullptr), copiedService(nullptr) {
	if (repository->getGraph() == nullptr) {
		GraphClass *emptyGraph = new GraphClass(0);
		service = new GraphService(emptyGraph);
	}
	else {
		service = new GraphService(repository->getGraph());
	}
}


Menu::~Menu() {
	delete service;
	delete copiedService;
}

void Menu::run()
{
	copiedService = nullptr;
	std::cout << "\nWELCOME TO THE MENU\n";
	std::cout << "0.Generate a random graph\n";
	std::cout << "1.Create a copy of the graph\n";
	std::cout << "2.See the graph\n";
	std::cout << "3.Get the number of vertices\n";
	std::cout << "4.Iterate the set of vertices\n";
	std::cout << "5.Check if there is an edge between 2 vertices\n";
	std::cout << "6.Get the in/out degree of a vertex\n";
	std::cout << "7.Target vertices (outbound)\n";
	std::cout << "8.Target vertices (inbound)\n";
	std::cout << "9.See endpoints of edge\n";
	std::cout << "10.Retrieve edge cost\n";
	std::cout << "11.Modify edge cost\n";
	std::cout << "12.Add a new edge\n";
	std::cout << "13.Remove an edge\n";
	std::cout << "14.Add a new vertex\n";
	std::cout << "15.Remove a vertex\n";
	std::cout << "16.Load a graph from a file\n";
	std::cout << "17.See the copied graph\n";
	std::cout << "18.Save the copied graph\n";
	std::cout << "19.Find connected components (DFS)";
	std::cout << "20.Display the minimum cost path between two vertices and the corresponding cost";
	std::cout << "21.Exit\n";

	while (true)
	{
		

		int choice;
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number between 0 and 16.\n";
			continue;
		}
		switch(choice){
			case 0:
			{
				int n, m;
				std::cout << "Enter the number of vertices: ";
				std::cin >> n;
				std::cout << "Enter the number of edges: ";
				std::cin >> m;

				delete service; 
				repository->createRandomGraph(n, m);
				service = new GraphService(repository->getGraph());

				std::string filename;
				std::cout << "Enter file name to save: ";
				std::cin >> filename;
				repository->saveFile(filename);
				break;

			}
			case 1:{
				copiedService = service->copyGraph();
				std::cout<< "Graph copied successfully.\n";
				break;
			}
			case 18:{
				std::string filename;
				std::cout << "Enter file name to save the copied graph: ";
				std::cin >> filename;
				break;
			}
			case 2: {
				std::cout << "Vertices:\n";
				for (auto v : service->getVertexList()) {
					std::cout << v << " ";
				}
				std::cout << "\nEdges and costs:\n";
				for (auto& p : service->getCostDict()) {
					std::cout << p.first.first << " -> " << p.first.second << " : " << p.second << "\n";
				}
				break;
			}
			case 3: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				std::cout << "Number of vertices: " << copiedService->getVertices() << "\n";
				break;
			}
			case 4:{
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				std::cout << "Vertices:\n";
				for (auto v : copiedService->getVertexList()) {
					std::cout << v << " ";
				}
				std::cout << "\n";
				break;
			}
			case 5: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int x, y;
				std::cout << "Enter source vertex: ";
				std::cin >> x;
				std::cout << "Enter target vertex: ";
				std::cin >> y;

				auto costMap = copiedService->getCostDict();
				if (costMap.find({ x, y }) != costMap.end()) {
					std::cout << "Edge exists.\n";
				}
				else {
					std::cout << "Edge does not exist.\n";
				}
				break;
			}
			case 6: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int v;
				std::cout << "Enter vertex: ";
				std::cin >> v;
				try{
					size_t indeg = copiedService->inEdges(v).size();
					size_t outdeg = copiedService->outEdges(v).size();
					std::cout<< "Vertex " << v << " has in-degree: "
					<< indeg << " and out-degree: " << outdeg << "\n";
				}
				catch (const std::out_of_range& e) {
					std::cout << "Vertex " << v << " does not exist.\n";
				}
				break;
			}
			case 7: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int v;
				std::cout << "Enter vertex: ";
				std::cin >> v;

				try{
					auto targets = copiedService->outEdges(v);
					std::cout << "Outbound targets: ";
					for(int u: targets) 
					   std::cout << u << " ";
					std::cout << "\n";
				}
				catch (const std::out_of_range&) {
					std::cout << "Vertex " << v << " does not exist.\n";
				}
				break;
			}
			case 8: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int v;
				std::cout << "Enter vertex: ";
				std::cin >> v;

				try{
					auto sources = copiedService->inEdges(v);
					std::cout << "Inbound sources: ";
					for (int u : sources)
						std::cout << u << " ";
					std::cout << "\n";
				}
				catch (const std::out_of_range&) {
					std::cout<< "Vertex " << v << " does not exist.\n";
				}
				break;
			}
			case 9: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				const auto& costMap = copiedService->getCostDict();
				if (costMap.empty()) {
					std::cout << "The graph has no edges.\n";
				}
				else {
					std::cout << "Edges and their endpoints:\n";
					for (const auto& pairCost : costMap) {
						int from = pairCost.first.first;
						int to = pairCost.first.second;
						int cost = pairCost.second;
						std::cout << "Edge from " << from << " to " << to
							<< " with cost: " << cost << "\n";
					}
				}
				break;
			}  
			case 10: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int x, y;
				std::cout << "Enter source: ";
				std::cin >> x;
				std::cout << "Enter target: ";
				std::cin >> y;
				std::cout << "Cost: " << copiedService->getCost(x, y) << "\n";
				break;
			}
			case 11: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				try {
					int x, y, c;
					std::cout << "Enter source: "; std::cin >> x;
					std::cout << "Enter target: "; std::cin >> y;
					std::cout << "Enter new cost: "; std::cin >> c;
					copiedService->changeCost(x, y, c);
				}
				catch (std::runtime_error& e)
				{
					std::cout << e.what();
				}
				
				break;
			}
			case 12: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int x, y, c;
				std::cout << "Enter source: "; std::cin >> x;
				std::cout << "Enter target: "; std::cin >> y;
				std::cout << "Enter cost: "; std::cin >> c;
				try{
					copiedService->addEdge(x, y, c);
					std::cout << "Edge added successfully.\n";
				}catch(const std::runtime_error& e){
				     std::cout << "Cannot add edge: " << e.what() << "\n";}
				break;
			}
			case 13: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int x, y;
				std::cout << "Enter source: "; std::cin >> x;
				std::cout << "Enter target: "; std::cin >> y;
				try{
					copiedService->removeEdge(x, y);
					std::cout << "Edge removed successfully.\n";
				}
				catch (const std::runtime_error& e) {
					std::cout << "Cannot remove edge: " << e.what() << "\n";
				}
				break;
			}
			case 14: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int v;
				std::cout << "Enter new vertex: "; std::cin >> v;
				try {
					copiedService->addVertex(v);
					std::cout<< "Vertex added successfully.\n";
				}
				catch (const std::runtime_error& e) {
					std::cout << "Cannot add vertex: " << e.what() << "\n";
				}
				break;
			}
			case 15: {
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				int v;
				std::cout << "Enter vertex to delete: "; std::cin >> v;
				try {
					copiedService->removeVertex(v);
					std::cout<< "Vertex removed successfully.\n";
				}
				catch (const std::runtime_error& e) {
					std::cout << "Cannot remove vertex: " << e.what() << "\n";
				}
				break;
			}
			case 21: {
				return;
			}
			case 17:
			{
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}
				std::cout << "Copied graph vertices:\n";
				for(auto v:copiedService->getVertexList())
				    std::cout << v << " ";
			    std::cout << "\nCopied graph edges and costs: \n";
				for(auto &p : copiedService->getCostDict())
				   std::cout << p.first.first << "->" << p.first.second << ":" << p.second << "\n";
				break;
			}
			case 16: {
				std::string filename;
				std::cout << "Enter the file name to load: ";
				std::cin >> filename;

				try {
					
					GraphClass* loadedGraph = repository->loadFile(filename);

					
					delete service;
					service = new GraphService(loadedGraph);

					
					delete copiedService;
					copiedService = nullptr;

					std::cout << "Graph loaded successfully.\n";
				}
				catch (const std::exception& e) {
					std::cout << "Failed to load graph: " << e.what() << "\n";
				}
				break;
			}
			case 19:
			{
				if (!copiedService) {
					std::cout << "Graph not copied.\n";
					break;
				}

				auto components = copiedService->connectedComponents();
				std::cout << "Connected components:\n";
				for (size_t i = 0; i < components.size(); ++i) {
					std::cout << "Component " << i + 1 << ": ";
					for (int v : components[i])
						std::cout << v << " ";
					std::cout << "\n";
				}
				break;
			}
			case 20:
			{
				if (!copiedService)
				{
					std::cout << "graph not copied";
					break;
				}

				int s, t;
				std::cout << "Enter source vertex: ";
				std::cin >> s;
				std::cout << "Enter target vertex: ";
				std::cin >> t;

				try {
					auto result = copiedService->lowestCostWalk(s, t);

					const auto& path = result.first;
					int cost = result.second;

					std::cout << "Lowest cost walk: ";
					for (int v : path)
						std::cout << v << " ";

					std::cout << "\nCost = " << cost << "\n";
				}
				catch (const std::runtime_error& e) {
					std::cout << e.what() << "\n";
				}

				break;
			}
			default:
			{
				std::cout << "Invalid choice!\n";
			}
		}
	}
}
