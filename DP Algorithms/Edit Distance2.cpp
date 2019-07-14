#include<bits/stdc++.h>
using namespace std;
// time complexity: O(nm) space complexity: O(nm)
int editDistance(string word1, string word2){
    vector<vector<int> > dpTable(word2.size() + 105, vector<int> (word1.size() + 105, 0));
    for(int i = 0; i < word2.size() + 1; i++){
        for(int j = 0; j <word1.size() + 1; j++){
            dpTable[i][j] = j;
            //cout << dpTable[i][j] << " ";
        }
        //initializing the column for empty string
        dpTable[i][0] = i;
       // cout <<endl << dpTable[i][0] << endl;
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
int editDistance2(string str1, string str2){
   string small = str1.size() < str2.size() ? str1 : str2;
   string big = str1.length() >= str2.length() ? str1 : str2;
  int *evenEdits = new int[small.length() + 1];
  int *oddEdits = new int[small.length() + 1];
  for (int j = 0; j < small.length() + 1; j++) {
    evenEdits[j] = j;
  }
  for (int i = 1; i < big.length() + 1; i++) {
    int *currentEdits = new int[small.length() + 1];
    int *previousEdits = new int[small.length() + 1];
    if (i % 2 == 1) {
      currentEdits = oddEdits;
      previousEdits = evenEdits;
    } else {
      currentEdits = evenEdits;
      previousEdits = oddEdits;
    }
    currentEdits[0] = i;
    for (int j = 1; j < small.length() + 1; j++) {
      if (big[i - 1] == small[j - 1]) {
        currentEdits[j] = previousEdits[j - 1];
      } else {
        currentEdits[j] = 1 + min(previousEdits[j - 1], min(previousEdits[j], currentEdits[j - 1]));
      }
    }
     cout << currentEdits[0] << " " << oddEdits[0] << endl;
  }
  //cout << oddEdits[0] << endl;
  return big.length() % 2 == 0 ? evenEdits[small.length()] : oddEdits[small.length()];
}
int main()
{
    cout << editDistance2("","abc")<< endl;// , "yabd") << endl;
    return 0;
}
