#include<bits/stdc++.h>
using namespace std;
// time complexity: O(nm) space complexity: O(nm)
int editDistance(string word1, string word2){
    vector<vector<int> > dpTable(word2.size() + 5, vector<int> (word1.size() + 5, 0));
    for(int i = 0; i < word2.size() + 1; i++){
        for(int j = 0; j <word1.size() + 1; j++){
            dpTable[i][j] = j;
        }
        //initializing the column for empty string
        dpTable[i][0] = i;

    }
    for(int i = 1; i < word2.size() + 1; i++){
        for(int j = 1; j <word1.size() + 1; j++){
            if(word1[j - 1] == word2[i - 1]){
                dpTable[i][j] = dpTable[i - 1][j - 1];
            }else{
                dpTable[i][j] = min(dpTable[i][j - 1], min(dpTable[i - 1][j], dpTable[i - 1][j - 1])) + 1;
            }
        }
    }
    return dpTable[word2.size()][word1.size()];
}
// time complexity: O(nm) space complexity: O(min(n,m))
int editDistance2(string word1, string word2){
  string small = word1.size() < word2.size() ? word1 : word2;
  string big = word1.size() >= word2.size() ? word1 : word2;
  int *evenEdits = new int[small.size() + 1];
  int *oddEdits = new int[small.size()  + 1];
  for (int j = 0; j < small.size()  + 1; j++) {
    evenEdits[j] = j;
  }
  for (int i = 1; i < big.size() + 1; i++) {
    int *currentEdits = new int[small.size()  + 1];
    int *previousEdits = new int[small.size()  + 1];
    if (i % 2 == 1) {
      currentEdits = oddEdits;
      previousEdits = evenEdits;
    } else {
      currentEdits = evenEdits;
      previousEdits = oddEdits;
    }
    currentEdits[0] = i;
    for (int j = 1; j < small.size()  + 1; j++) {
      if (big[i - 1] == small[j - 1]) {
        currentEdits[j] = previousEdits[j - 1];
      } else {
        currentEdits[j] = 1 + min(previousEdits[j - 1], min(previousEdits[j], currentEdits[j - 1]));
      }
    }
  }
  return big.size()  % 2 == 0 ? evenEdits[small.size()] : oddEdits[small.size()];
}
int main()
{
    cout << editDistance("horse","ros") << endl;
    cout << editDistance2("horse","ros")<< endl;
    return 0;
}
