#include <bits/stdc++.h>

using namespace std;

class Coordinate
{
public:
	int x, y;
	bool visited;
};

int result = 0;

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

		for(int i = 0; i < 5; i++)
		{
		    maze[i].resize(5);
			coordinates[i].resize(5);
		}

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{   
			    cin >> maze[i][j];

				coordinates[i][j].x = i;
				coordinates[i][j].y = j;
				coordinates[i][j].visited = false;
			}
		}

        result = 0;
        stack<Coordinate> steps_mem;
		backtrack(maze, 0, 0, coordinates, steps_mem);
        //cout << "out of backtrack" << endl;

        // If cops reach the last maze position they've won ;
		if (result)
        {
            cout << "COPS" << endl;
		}
		else
        {
            cout << "ROBBERS" << endl;
        }
	}

	return 0;
}
