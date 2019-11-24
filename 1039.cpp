#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{   
    int r1,x1,y1,r2,x2,y2;
    double distance;

    while (scanf("%d %d %d %d %d %d",&r1,&x1,&y1,&r2,&x2,&y2) != EOF)
    {
        distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        r1 >= distance + r2 ? printf("RICO\n") : printf("MORTO\n");
    }

    return 0;
}