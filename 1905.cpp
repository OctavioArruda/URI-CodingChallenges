#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(vector<vector<int>> &maze, vector<vector<int>> &visited, int x, int y) {

  visited[x][y] = true;

  if (x == 4 && y == 4)
  {
    return true;
  }

  int ok = 0;
  for (int i = 0; i < 4; ++i) 
  {
    int nx = x + dx[i], ny = y + dy[i];

    if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visited[nx][ny] && maze[nx][ny] == 0) 
    {
      ok |= dfs(maze, visited, nx, ny);
    }
  }
  return ok;
}
int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int tc;
  cin >> tc;
  
  while (tc--) 
  {
    vector<vector<int>> maze(5, vector<int>(5));
    for (auto &i : maze)
      for (auto &j : i)
        cin >> j;

    vector<vector<int>> visited(5, vector<int>(5));

    if (dfs(maze, visited, 0, 0))
      cout << "COPS" << endl;
    else
      cout << "ROBBERS" << endl;
  }
  return 0;
}