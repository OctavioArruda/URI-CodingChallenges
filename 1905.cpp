#include <bits/stdc++.h>

using namespace std;

/* 5 x 5 maze
0 1 2 3 4 
x x x x x 0
x x x x x 1 
x x x x x 2 
x x x x x 3
x x x x x 4
*/
int maze[4][4];

int value(int i, int j)
{
	return i >= 0 && i < 5 && j >= 0 && j < 5;
}

void backtrack(int i, int j, vector<int> prev)
{
	// when next call isn't a valid position to continue:
	// robber's wins
	if (maze[i][j]) return;
	// If the path to walk is out of the range:
	// robber's wins
	if (!value(i, j)) return;
	// if the last position was reached(cop's wins):
	if (prev[5 * i + j]) return;

	// Mark it as previously visited
	prev[5 * i + j] = 1;

	if (i + 1 < 5 && maze[i + 1][j] == 0) 
	{
		// down		
		maze[i][j] ==  1;
		backtrack(++i, j, prev);
	}
	if (j + 1 < 5 && maze[i][j + 1] == 0) 
	{
		// right
		maze[i][j] == 1;
		backtrack(i, ++j, prev);
	}
	if (j - 1 >= 0 && maze[i][j - 1] == 0) 
	{
		// left
		maze[i][j] == 1;
		backtrack(i, --j, prev);
	}
	if (i - 1 >= 0 && maze[i - 1][j] == 0) 
	{
		// above 
		maze[i][j] == 1;
		backtrack(--i, j, prev);
	}
	if (i == 4 && j == 4) 
	{
		return;
	}

	return;
}

int main()
{
    int nCasos;
    //ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> nCasos;
    vector<int> prev;

	while (nCasos--)
	{	
		for (int i = 0; i < 5; ++i) 
		{
			for (int j = 0; j < 5; ++j) 
			{					
				cin >> maze[i][j];
			}
		} 

		prev.assign(24, 0);

		backtrack(0,0, prev);

        // If cops reach the last maze position they've won ;
		if (prev[24])
        {
            cout << "COPS\n";
		}
		else
        {
            cout << "ROBBERS\n";
        }
	}
}
