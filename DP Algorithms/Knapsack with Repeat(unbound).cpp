#include<bits/stdc++.h>
using namespace std;
/**
* Knapsack with repetition
* written two algorithms: one with 2d array and second with 1d array.
* both gives same output
* Time complexity: O(nB)
*/
int knapsack1(int v[],int w[],int  n,int B)
{
    int k[n+5][B+5],i,b;
    for(i = 0;i <= n;i++)
    {
        k[i][0] = 0;
    }
    for(b = 0;b <= B;b++)
    {
        k[0][b] = 0;
    }
    for(i = 1;i <= n;i++)
    {
        for(b = 1;b <= B;b++)
        {
            if(w[i - 1] <= b)
            {
                int p = w[i-1];
                k[i][b] = max(v[i-1] + k[i][b - p],k[i-1][b]);
            }else{
                k[i][b] = k[i - 1][b];
                //cout<<k[i][b]<<" not mx "<<w[i-1]<<endl;
            }
            //cout<<w[i]<<" "<<b<<endl;
        }

    }
    return k[n][B];
}
/**or we can just make the array 1D because we were keeping 2d array in no repeat
* knapsack to keep track of which weight we have used
* but in unbound knapsack we don't have to keep that track
*/
int knapsack2(int v[],int w[],int  n,int B)
{
    int k[B+5],i,b;
    for(b = 0;b <= B;b++)
    {
        k[b] = 0;
        for(i = 1;i <= n;i++)
        {
            if(w[i - 1] <= b)
            {
                k[b] = max(v[i-1] + k[b - w[i-1]],k[b]);
            }
        }

    }
    return k[B];
}
int main()
{
    int n,i,B;
    cin>>n>>B;
    int w[n+5],v[n+5];
    for(i=0;i<n;i++)
    {
        cin>>v[i];
    }
    for(i=0;i<n;i++)
    {
        cin>>w[i];
    }
    cout<<knapsack1(v,w,n,B)<<endl;
    cout<<knapsack2(v,w,n,B)<<endl;
    return 0;
}
