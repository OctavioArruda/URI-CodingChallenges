#include <bits/stdc++.h>

using namespace std;

#define ASCII 97
typedef vector<bool> vb;
typedef set<int> vi;
typedef vector <vi> vvi;


/* deep first search to find connected components */
void deepFirstSearch(vb &visited, vi &answer, vvi &graph, int s)
{
    visited[s] = true;
    answer.insert(s);

    for (auto v : graph[s])
    {
        if (!visited[v])
        {
            deepFirstSearch(visited, answer, graph, v);
        }
    }
}

int main (int argc, char *argv[]) 
{ 
    int t, v, e, x, y, connectedComponents;
    char a, b;
    
    /* # test cases */
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        /* vertices, edges */ 
        cin >> v >> e;

        vvi graph(v);
        vb visited(v, 0);

        for (int j = 0; j < e; ++j)
        {   
            /* edges that connects the vertices */
            cin >> a >> b;

            x = (int)a - ASCII;
            y = (int)b - ASCII;
             
            graph[x].insert(y);
            graph[y].insert(x);
        }

        connectedComponents = 0;
        printf ("Case #%d:\n", i);

        for (int j = 0; j < graph.size(); ++j)
        {
            if (!visited[j])
            {
                connectedComponents++;
                vi component;
                deepFirstSearch (visited, component, graph, j);
                
                for (int item : component)
                {
                    printf ("%c,", (char)item + ASCII);
                }

                printf ("\n");
            }
        }

        printf ("%d connected components\n\n", connectedComponents);
    }
    
    return 0;
}