#include<bits/stdc++.h>
using namespace std;
/**
*finding the length of Longest Common Subsequence
*Time Complexity: O(n^2)
*/
int LCS(string x,string y)
{
    int n1 = x.size(),n2 = y.size();
    int l[n1+5][n2+5];
    for(int i = 0;i <= n1 ;i++)
    {
        l[i][0] = 0;
    }
    for(int j = 0;j <= n2 ;j++)
    {
        l[0][j] = 0;
    }
    for(int i = 1;i <= n1;i++)
    {
        for(int j = 1;j <= n2;j++)
        {
            if(x[i-1] == y[j-1])
            {
                l[i][j] = 1 + l[i - 1][j - 1];
            }else{
                l[i][j] = max(l[i][j - 1],l[i - 1][j]);
            }
        }
    }

    return l[n1][n2];
}
int main()
{
    string x,y;
    cin>>x>>y;
    cout<<LCS(x,y)<<endl;
    return 0;
}
