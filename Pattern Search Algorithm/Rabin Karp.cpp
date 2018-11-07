#include<bits/stdc++.h>
using namespace std;
void search(string text, string pattern, int primeNumber)
{
    int textSize = text.size();
    int patternSize = pattern.size();
    int h = 1, i;
    for( i = 0; i < patternSize - 1; i++)
    {
        h = (h * 256) % primeNumber; //h = 256 ^ (patternSize -1)
    }
    int hashValueOfText = 0, hashValueOfPattern = 0;
    for( i = 0; i < patternSize; i++)
    {
        hashValueOfPattern = (256 * hashValueOfPattern + pattern[i]) % primeNumber;
        hashValueOfText = (256 * hashValueOfText + text[i]) % primeNumber;
    }
    int j;
    for( i = 0; i <= textSize - patternSize; i++)
    {
        if(hashValueOfPattern == hashValueOfText)
        {
            for(j = 0; j < patternSize; j++)
            {
                if(text[i + j] != pattern[j])
                {
                    break;
                }
            }
            if(j == patternSize)
            {
                cout << "pattern found at index: " << i << endl;
            }
        }

        if(i < textSize - patternSize)
        {
            hashValueOfText = (256 * (hashValueOfText - text[i] * h) + text[i + patternSize]) % primeNumber;
            if(hashValueOfText < 0)
            {
                hashValueOfText += primeNumber;
            }
        }
    }
}
int main()
{
    string text, pattern;
    text = "absdab";
    pattern = "ab";
    search(text, pattern, 101);
    return 0;
}
