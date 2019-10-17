#include <bits/stdc++.h>
#define D(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool dfs(vector<vector<int>> &maze, vector<vector<int>> &visited, int x, int y) {

<<<<<<< HEAD
void backtrack(vector<vector <int> > maze, int i, int j, vector<vector <Coordinate> > coordinates, stack<Coordinate> steps_mem)
{
    //std::cout << "after stack thing recursion" << endl;
    // if we are inside the ranges of maze and we have a possible solution and a possible start
    // for cops
	if (!result && !maze[4][4] && !maze[0][0])
    {
        coordinates[i][j].visited = true;
        //cout << "debugging -> i: "<< i << " j:" << j << endl;
        //cout << "debugging coordinates --> x: " << coordinates[i][j].x << " y: " << coordinates[i][j].y << endl;
        steps_mem.push(coordinates[i][j]);

        if(i == 4 && j == 4)
        {
            result = 1;
            return;
        }
        else
        {
            if (j + 1 < 5 && maze[i][j + 1] == 0 && !coordinates[i][j + 1].visited)
            {
                // right
                j = j + 1;
                backtrack(maze, i, j, coordinates, steps_mem);
            }
            else if (i + 1 < 5 && maze[i + 1][j] == 0 && !coordinates[i + 1][j].visited)
            {
                // down
                i = i + 1;
                backtrack(maze, i, j, coordinates, steps_mem);
            }
            else if (j - 1 >= 0 && maze[i][j - 1] == 0 && !coordinates[i][j - 1].visited)
            {
                // left
                j = j - 1;
                backtrack(maze, i, j, coordinates, steps_mem);
            }
            else if (i - 1 >= 0 && maze[i - 1][j] == 0 && !coordinates[i - 1][j].visited)
            {
                // above
                i = i - 1;
                backtrack(maze, i, j, coordinates, steps_mem);
            }
            else
            {
                //cout << "the stack thing" << endl;
                // If there's no move to do, pop the stack until we have a new move 
                Coordinate temp; 
                // cout << "temp declaration" << endl;
                steps_mem.pop();
                if (steps_mem.empty()) 
                {
                    return;
                }
                temp = steps_mem.top();   
                //cout << "top attribution to temp" << endl;            
                steps_mem.pop();
                //cout << "no pop? stack thing" << endl;
                if (steps_mem.empty())
                {
                    //cout << "empty stack" << endl;
                    return;
                }
                //cout << "no empty? stack thing" << endl;
                coordinates[i][j] = steps_mem.top();
                if (coordinates[i][j].x == temp.x && coordinates[i][j].y == temp.y)
                {
                    // if last step equals this step, we have no one else to go and must end:
                    //cout << "out for last step equal actual step" << endl;;
                    //cout << " actual x: "<< coordinates[i][j].x << " y: " << coordinates[i][j].y << endl;
                    //cout << " last x: " << temp.x << " y: " << temp.y << endl;
                    return;
                }
                //cout << "no top? stack thing" << endl;
                //cout << " after stack --> x: " << coordinates[i][j].x << " y: " << coordinates[i][j].y << endl;
                backtrack(maze, temp.x, temp.y, coordinates, steps_mem);
            }
        }
    }
}

int main()
{
    int T;
    ios_base :: sync_with_stdio(0); cin.tie(0);
	cin >> T;

	while (T--)
	{
	    vector<vector <Coordinate> > coordinates(5);
	    vector<vector <int> > maze(5);
=======
  visited[x][y] = true;
>>>>>>> 893089eec15ddad97210c77a28c7fb2df99097ab

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