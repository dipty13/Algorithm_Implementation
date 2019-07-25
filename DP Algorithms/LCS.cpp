#include<bits/stdc++.h>
using namespace std;
vector<char> buildSubSequence(vector<vector<int> > dpTable, string string1);
//Time complexity: O(nm * min(n,m)), Space complexity: O(nm * min(n,m))
vector<char> LCS(string string1,string string2)
{
    vector<vector<vector<char> > > dpTable;
    //initializing the
    for(int i = 0; i < string2.size() + 1; i++){
        dpTable.push_back(vector<vector<char> > ());
        for(int j = 0; j < string1.size() + 1; j++){
            dpTable[i].push_back(vector<char> ());
        }
    }
    for(int i = 1; i < string2.size() + 1; i++){
        for(int j = 1; j < string1.size() + 1; j++){
            if(string2[i - 1] == string1[j - 1]){
                vector<char> copyLcs = dpTable[i - 1][j - 1];
                copyLcs.push_back(string2[i - 1]);
                dpTable[i][j] = copyLcs;

            }else{
                dpTable[i][j] = dpTable[i - 1][j].size() > dpTable[i][j - 1].size() ? dpTable[i - 1][j] : dpTable[i][j - 1];
            }
        }
    }
    return dpTable[string2.size()][string1.size()];
}
//Time complexity: O(nm), Space complexity: O(nm)
vector<char> LCS2(string string1,string string2)
{
    vector<vector<int> > dpTable(string2.size() + 1, vector<int> (string1.size() + 1, 0));
    for(int i = 1; i < string2.size() + 1; i++){
        for(int j = 1; j < string1.size() + 1; j++){
            if(string2[i - 1] == string1[j - 1]){
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;
               // cout << dpTable[i][j] << endl;
            }else{
                dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i][j - 1]);
            }
        }
        //cout << dpTable[i][string1.size()] << endl;
    }
    //cout << dpTable[string2.size()][string1.size()] <<endl;
    return buildSubSequence(dpTable, string1);
}
vector<char> buildSubSequence(vector<vector<int> > dpTable, string string1){
    vector<char> sequence;
    int i = dpTable.size() - 1;
    int j = dpTable[0].size() - 1;
    while(i != 0 && j != 0){
        if(dpTable[i][j] == dpTable[i - 1][j]){
            i--;
        }else if(dpTable[i][j] == dpTable[i][j - 1]){
            j--;
        }else{
            sequence.insert(sequence.begin(), string1[j - 1]);
            //cout << sequence[0] << endl;
            i--;
            j--;
        }
    }
    return sequence;
}
int main()
{
    string x = "ZXVVYZW", y = "XKYKZPW";
    //cin>>x>>y;
    vector<char> ans = LCS2(x,y);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
