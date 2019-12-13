#include <bits/stdc++.h>

int main(int argc, char *argv[])
{
    int a, b;

    while(true)
    {
        scanf("%d", &a);

        if(a == 0) 
        {
            break;
        }
        else 
        {
            b = (a * (a + 1) *((2 * a) + 1)) / 6;
        }
        
        printf("%d\n",b);
    }

    return 0;
}
