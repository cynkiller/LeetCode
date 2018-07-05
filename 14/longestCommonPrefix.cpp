#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int maxstr = strs.size();
        if (maxstr == 0) return prefix;

        int minlen = strs[0].size();
        for (auto i: strs) {
            if (i.size() < minlen) minlen = i.size();
        }
        
        for (int i = 0; i < minlen; i++) {
            char ss = strs[0][i];
            for(int j = 1; j < maxstr; j++) {
                if (strs[j][i] != ss) {
                    return prefix;
                }
            }
            prefix.push_back(ss);
        }
        return prefix;
    }
};


int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    vector<string> strs = {"flower","flow","flight"};
    cout << s->longestCommonPrefix(strs) << endl;
    return 0;
}