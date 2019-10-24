#include <bits/stdc++.h>

#define MAX 1010

using namespace std;

int w[MAX];
int v[MAX];

int dp[2][100000];

int main(int argc, char *argv[])
{
  int n, c, i, j; 
  
  int cont = 1;

  while (scanf("%d %d", &n, &c) , (n || c))
  {
    for (i = 1 ; i <= n; ++i) 
    {
        scanf("%d %d", &w[i], &v[i]);
    }
      
    for (i = 0 ; i <= c; ++i) 
    {
        dp[0][i] = 0;
    }

    dp[1][0] = 0;
    
    for (i = 1 ; i <= n; ++i)
    {
      for(j = 1 ; j <= c; ++j)
      {
        if (w[i]  <= j)
        {
          dp[i % 2][j] = max(dp[(i - 1) % 2][j],dp[(i - 1) % 2][j - w[i]] + v[i]);
        }
        else
        {
          dp[i % 2][j] = dp[(i - 1) % 2][j];
        }
      }
    }
    printf("Caso %d: %d\n", cont, dp[n % 2][c]);
    
    ++cont;
  }

  return 0;
}