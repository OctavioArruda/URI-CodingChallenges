#include <bits/stdc++.h>
#define debug(x) cout << #x " = " << (x) << endl
#define endl '\n'

using namespace std;

int findGreatestSubstringSize(string str1, string str2)
{
    int linelen = str1.length();
    int columnlen = str2.length();

    // Using a matrix to save substring parts 
    int matrix[linelen + 1][columnlen + 1];
    int result = 0;

    for (int i = 0; i <= linelen; ++i)
    {
        for (int j = 0; j <= columnlen; ++j)
        {
            if (i == 0 && j == 0)
            {
                matrix[i][j] = 0;
            }
            else if (str1[i - 1] == str2[j - 1])
            {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
                result = std::max(result, matrix[i][j]);
            }
            else 
            {
                matrix[i][j] = 0;
            }
        }
    }

    return result;
}   

int main (int argc, char *argv[]) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    
    string str1, str2;
    getline(cin, str1);
    while(getline(cin, str2))
    {   
        int size = findGreatestSubstringSize(str1, str2);
        cout << size << endl;
        getline(cin, str1);
    }
    return 0;
}