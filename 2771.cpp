#include <bits/stdc++.h>
#include <iomanip>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

bool rev(double a, double b){
    return a > b;
}

int main (int argc, char *argv[])
{
    int N, K;
    int a[112];
    double avg;

    while (!cin.eof())
    {
        cin >> N >> K;
        for (int i = 0; i < N; ++i)
        {
            cin >> a[i]; 
        }

        vector<double> avgList;

        for (int  i = 0; i < N; ++i)
        {
            for (int j = i + 1; j < N; ++j)
            {
                for (int k = j + 1; k < N; ++k)
                {
                    avg = (double)(a[i] + a[j] + a[k]) / 3.0;
                    avgList.push_back(avg);
                }
            }
        }

        sort(avgList.begin(), avgList.end(), rev);
        cout << fixed << setprecision(1) << avgList[K - 1] << endl;
    }
    return 0;
}