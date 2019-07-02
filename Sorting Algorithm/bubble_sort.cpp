#include<bits/stdc++.h>
using namespace std;
vector<int> bubbleSort(vector<int> array)
{
    for(int i = 0; i < array.size(); i++)
    {
        for(int j = 1; j < array.size() - i; j++)
        {
            if(array[j - 1] > array[j])
            {
                swap(array[j - 1], array[j]);
            }
        }
    }
    return array;
}


int main()
{
    vector<int> array = {8, 5, 2, 9, 5, 6,3};
    vector<int> ans = bubbleSort(array);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
