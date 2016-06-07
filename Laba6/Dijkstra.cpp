#include <iostream>
#include <vector>
#include <list>

int main() {
	unsigned V = 0, E = 0, a = 0;
	std::cin >> V >> E >> a;
	std::cin.get();
	std::vector<std::list<std::pair<unsigned, unsigned>>> graph(V);
	for (unsigned i = 0; i < E; ++i) {
		unsigned vertex = 0, vertexTo = 0, weight = 0;
		std::cin >> vertex >> vertexTo >> weight;
		graph[vertex].push_back({ vertexTo , weight });
	}
	std::vector<unsigned> distance(V, -1);
	for (auto pr : graph[a]) {
		distance[pr.first] = pr.second;
	}
	for (unsigned i = 0; i < V; ++i) {
		if (i == a) {
			distance[i] = 0;
			continue;
		}
		for (auto pr : graph[i]) {
			if ((distance[i] == -1 ? -1 : distance[i] + pr.second) < distance[pr.first])
				distance[pr.first] = distance[i] + pr.second;
		}
	}
	for (auto el : distance)
		std::cout << el << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}
