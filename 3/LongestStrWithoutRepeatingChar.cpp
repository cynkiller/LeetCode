#include <iostream>
#include <string.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int currLen = 0;
        int lastHead = 0;
        char letterMap[128];
        memset(letterMap, 0, sizeof(letterMap));
        for (int i = 0; i < s.length(); i++) {
            if (letterMap[int(s[i])]) {
                currLen = 0;
                memset(letterMap, 0, sizeof(letterMap));
                for (int j = lastHead; j < i; j++)
                    if (s[j] == s[i]) {
                        lastHead = j + 1;
                        i = j;
                        break;
                    }
            } else {
                currLen++;
                letterMap[int(s[i])] = 1;
                if (currLen > maxLen)
                    maxLen = currLen;
            }
        }
        return maxLen;
    }
};

int main(int argc, char const *argv[])
{
    Solution slt;
    //string str = "bbbbb";
    //string str = "abcabcbb";
    //string str = "dvdf";
    string str = "pwwkew";
    cout << slt.lengthOfLongestSubstring(str) << endl;
    return 0;
}