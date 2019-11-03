#include <bits/stdc++.h>

using namespace std;
 
typedef struct {
    int src;
    int dst;
    int weight;
} edge;
 
bool comp(edge A, edge B) {
    return (A.weight < B.weight);
}
 
int checa_ciclo(int p[], int src, int dst) {
    while (p[src] > -1) {
        src = p[src];
    }
     
    while (p[dst] > -1) {
        dst = p[dst];
    }
     
    if (src != dst) {
        p[dst]=src;
         
        return 1;
    }
     
    return 0;
}
 
int main(int argc, char *argv[]) {
    int vertixAmount, edgeAmount;
     
    int p[200000]; 
    edge edges[200000];
 
    while (cin >> vertixAmount >> edgeAmount) 
    {
        if (vertixAmount == 0 and edgeAmount == 0) 
        {
            return 0;
        }
         
        int cost = 0;
        int totalCost = 0;
         
        for (int i = 0; i < vertixAmount; ++i) 
        {
            p[i] = -1;
        }
         
        for (int i = 0; i < edgeAmount; ++i) 
        {
            cin >> edges[i].src >> edges[i].dst >> edges[i].weight;
            totalCost += edges[i].weight;
        }
     
        sort(edges, edges + edgeAmount, comp);
     
        int i = 0;
        int j = 1;
         
        while (j < vertixAmount && i < edgeAmount) 
        {
            if (checa_ciclo(p, edges[i].src, edges[i].dst)) 
            {
                j++;
                cost = cost + edges[i].weight;
            }
             
            ++i;
        }
         
        cout << totalCost - cost << endl;
    }
     
    return 0;
}