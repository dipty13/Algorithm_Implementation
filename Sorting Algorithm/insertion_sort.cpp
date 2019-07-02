#include<bits/stdc++.h>
using namespace std;
vector<int> insertionSort(vector<int> array)
{
    for(int i = 1; i < array.size(); i++)
    {
        int temp = array[i];
        int j = i - 1;
        while(j >= 0 && array[j] > temp)
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    return array;
}


int main()
{
    vector<int> array = {8, 5, 2, 9, 5, 6,3};
    vector<int> ans = insertionSort(array);
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
