#include<bits/stdc++.h>
using namespace std;
/**
*finding the length of Longest Increasing Subsequence
*/
int LIS(int a[],int  n)
{
    int l[n+5];
    for(int i=1;i<=n;i++)
    {
        l[i] = 1;
        for(int j = 1;j<i;j++)
        {
            if(a[j]<a[i]&&l[i]<l[j]+1)
            {
                l[i] = l[j]+1;
            }
        }
    }
    int mx = 1;
    for(int i = 2;i<=n;i++)
    {
        if(l[i]>l[mx])
        {
            mx = i;
        }
    }
    return l[mx];
}
int main()
{
    int n,i;
    cin>>n;
    int a[n+5];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    cout<<LIS(a,n)<<endl;
    return 0;
}
