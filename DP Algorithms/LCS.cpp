#include<bits/stdc++.h>
using namespace std;
vector<char> buildSubSequence(vector<vector<int> > dpTable, string string1);
//Time complexity: O(nm * min(n,m)), Space complexity: O(nm * min(n,m))
vector<char> LCS(string string1,string string2)
{
    vector<vector<vector<char> > > dpTable;

   //initializing the dp table
    for(int i = 0; i < string2.size() + 1; i++){
        dpTable.push_back(vector<vector<char> > ());
        for(int j = 0; j < string1.size() + 1; j++){
            dpTable[i].push_back(vector<char> ());
        }
    }
    for(int i = 1; i < string2.size() + 1; i++){
        for(int j = 1; j < string1.size() + 1; j++){
            if(string2[i - 1] == string1[j - 1]){

            /*
             *if the characters are equal we are taking
             * the LCS of the two strings without this character
             * which is located diagonally i.e. dpTable[i - 1] [j - 1]
             * if we have 2 strings "abc" and "ac"
             * and we're comparing 'c' from both strings
             * then we will take lcs of "ab" and "a"
             * which will be "a" and append "c" to it
             * LCS of "ab" and "a" will be located diagonally
             */
                vector<char> copyLcs = dpTable[i - 1][j - 1];
                copyLcs.push_back(string2[i - 1]);
                dpTable[i][j] = copyLcs;

            }else{
                /*
                * if the characters are not equal
                * will check if the LCS without the character from string2 is greater
                * or the LCS without the character from string1 is greater
                */
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
            /*
             *if the characters are equal we are taking
             * the length of the LCS of the two strings without this character
             * which is located diagonally i.e. dpTable[i - 1] [j - 1]
             * if we have 2 strings "abc" and "ac"
             * and we're comparing 'c' from both strings
             * then we will take the length of the lcs of "ab" and "a"
             * which will be 1 and add 1 to it and get 2
             * LCS of "ab" and "a" will be located diagonally
             */
                dpTable[i][j] = dpTable[i - 1][j - 1] + 1;

            }else{
                /*
                * if the characters are not equal
                * will check if the length of the LCS without the character from string2 is greater
                * or the length of the LCS without the character from string1 is greater
                */
                dpTable[i][j] = max(dpTable[i - 1][j], dpTable[i][j - 1]);
            }
        }
    }
    // calling function which where we'll build our LCS
    return buildSubSequence(dpTable, string1);
}
vector<char> buildSubSequence(vector<vector<int> > dpTable, string string1){
    vector<char> sequence;
    //We will start from the last index of our dp table
    int i = dpTable.size() - 1;
    int j = dpTable[0].size() - 1;
    while(i != 0 && j != 0){
        if(dpTable[i][j] == dpTable[i - 1][j]){
            //if LCS length of the previous column is equal
            i--;
        }else if(dpTable[i][j] == dpTable[i][j - 1]){
            //if LCS length of the previous row is equal
            j--;
        }else{
            /*
            * if LCS length of the previous column and LCS length of the previous row
            * is not equal, that means we will add the character to our LCS
            * the insert function puts character at the beginning of the vector
            * so, we will get the LCS in correct order as we are traversing from the end
            */
            sequence.insert(sequence.begin(), string1[j - 1]);
            i--;
            j--;
        }
    }
    return sequence;
}
int main()
{
    string x = "abdez", y = "bxide";
    //cin>>x>>y;
    vector<char> ans = LCS2(x,y);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
