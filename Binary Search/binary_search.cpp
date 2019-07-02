#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<int> array, int target) {
	int leftIndex = 0, rightIndex = array.size() - 1;
	while(leftIndex <= rightIndex){
			int mid = leftIndex + (rightIndex - leftIndex) / 2;
			if(array[mid] == target){
				 return mid;
			}else if(array[mid] > target){
				 rightIndex = mid - 1;
			}else{
				 leftIndex = mid + 1;
			}
	}

	return -1;
}

int main()
{
    vector<int> array = {0, 1, 21, 33, 45, 45, 61, 71, 72, 73};
    cout << binarySearch(array, 33) << endl;
    return 0;
}
