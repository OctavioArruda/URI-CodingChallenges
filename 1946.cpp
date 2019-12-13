#include <bits/stdc++.h>

#define MAX 5001

using namespace std;

double a[MAX][MAX];
void p(int s){
    a[1][0]=100;
    for(int i=1; i<=s; i++){
        for(int j=0;j<= i; j++){
            if(j == 0)
            {
                a[i+1][j]=a[i][j]/2;
            }
            else if( j == i ){
                a[i+1][j]=a[i][0]/2;}
            else{
                a[i+1][j]=a[i][j]/2+a[i][j-1]/2;
            }
        }
    }
}

double prob(int s)
{
    return a[s][s / 2];
}
int main(){
    int s;
    cin >> s;
    p(s);
    cout.precision(2);
    cout << fixed << prob(s) << endl;
    return 0;
}