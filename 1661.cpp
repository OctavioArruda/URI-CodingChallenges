#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll d[100005];

int main ()
{
    ll inhabitants, count, workamount;
    ios_base::sync_with_stdio(0); cin.tie(0);

    while (cin >> inhabitants, inhabitants)
    {
        for (count = 0; count < inhabitants; count++)
        {
            cin >> d[count];
        }
          
        workamount = 0;
        for (count = 1; count < inhabitants; count++)
        {
            if (d[count - 1] < 0)
            {
                workamount = workamount + -1 * d[count - 1];
            }

            else
            {
                workamount += d[count - 1];
            }
                
            d[count] += d[count - 1];
        }
        cout << workamount << '\n';
    }
}