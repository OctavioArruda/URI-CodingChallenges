#include <bits/stdc++.h>

using namespace std;

class Edge
{
	int vertice1, vertice2, weight;

public:

	Edge(int v1, int v2, int weight)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->weight = weight;
	}

	int getVertice1()
	{
		return vertice1;
	}

	int getVertice2()
	{
		return vertice2;
	}

	int getWeight()
	{
		return weight;
	}

	bool operator < (const Edge& edge2) const
	{
		return (weight < edge2.weight);
	}
};

class Graph
{
	int V; 
	vector<Edge> edges; 

public:

	Graph(int V)
	{
		this->V = V;
	}

	void addEdge(int v1, int v2, int weight)
	{
		Edge edge(v1, v2, weight);
		edges.push_back(edge);
	}


	int search(int subset[], int i)
	{
		if(subset[i] == -1)
        {
			return i;
        }

		return search(subset, subset[i]);
	}

	void join(int subset[], int v1, int v2)
	{
		int v1_set = search(subset, v1);
		int v2_set = search(subset, v2);
		subset[v1_set] = v2_set;
	}

	int kruskal()
	{
		vector<Edge> tree;
		int size_edges= edges.size();

		sort(edges.begin(), edges.end());

		int* subset = new int[V];

		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_edges; i++)
		{
			int v1 = search(subset, edges[i].getVertice1());
			int v2 = search(subset, edges[i].getVertice2());

			if(v1 != v2)
			{
				tree.push_back(edges[i]);
				join(subset, v1, v2); 
			}
		}

		int size_tree = tree.size();
		int minCost = 0;

		for(int i = 0; i < size_tree; ++i)
		{
			minCost += (tree[i].getWeight());
		}
        
		return minCost;
	}
};

int main(int argc, char *argv[])
{
	Graph g(61); 

	int V, W, P, R, C;

	cin >> R >> C;

	for (int i = 0; i < C; i++)
	{
		cin >> V >> W >> P;
		g.addEdge(V-1, W-1, P);
	}

	cout << g.kruskal() << endl;

	return 0;
}