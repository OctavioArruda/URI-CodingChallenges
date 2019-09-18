#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

int maze[6][6];

int value(int i, int j)
{
	return i >= 0 && i < 5 && j >= 0 && j < 5;
}

void backtrack(int i, int j, vector<int> prev)
{
	if (maze[i][j]) return;
	if (!value(i, j)) return;
	if (prev[5 * i + j]) return;

	prev[5 * i + j] = 1;

	for (int l = 0 ; l < 4; ++l)
	{
		backtrack(i + dir[l][0], j + dir[l][1], prev);
	}
}

int main()
{
    int nCasos;
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> nCasos;
    vector<int> prev;

	while (nCasos--)
	{
		for (int i = 0; i < 5; ++i) for (int j = 0; j < 5; ++j) cin >> maze[i][j];

		prev.assign(26, 0);

		backtrack(0,0, prev);

        // If cops reach the last maze position they've won ;
		if (prev[24])
        {
            cout << "COPS" << endl;
		}
		else
        {
            cout << "ROBBERS" << endl;
        }
	}
}
