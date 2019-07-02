#include<bits/stdc++.h>
using namespace std;
vector<int> selectionSort(vector<int> array) {
  for(int i = 0; i < array.size(); i++){
		int min = i;
		for(int j = i + 1; j < array.size(); j++){
			if(array[j] < array[min]){
				min = j;
			}
		}
		swap(array[i],array[min]);
	}
	return array;
}

int main()
{
    vector<int> array = {8, 5, 2, 9, 5, 6,3};
    vector<int> ans = selectionSort(array);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
