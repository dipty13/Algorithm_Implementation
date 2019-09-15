#include<bits/stdc++.h>
using namespace std;
int shiftedBinarySearch(vector<int> array, int target)
{
    int left = 0, right = array.size() - 1;
    while(left <= right)
    {
        int middle = left + (right - left) / 2;
        if(array[middle] == target)
        {
            return middle;
        }
        else if(array[middle] >= array[left])
        {
            if(target < array[middle] && target >= array[left])
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        else
        {
            if(target > array[middle] && target <= array[right])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
    }

    return -1;
}

int main()
{
    vector<int> array = {21, 33, 45, 1, 2, 7, 11};
    cout << shiftedBinarySearch(array, 2) << endl;
    return 0;
}
