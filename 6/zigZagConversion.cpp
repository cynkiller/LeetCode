#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> sto(numRows);
        string ret;
        int size = s.length();
        int cursor = 0;
        int res;
        if ( size <= numRows || numRows == 1) return s;
        while(1) {
            if (cursor >= size) {
                for (int i = 0; i < numRows; i++) {
                    for (int j = 0; j < sto[i].length(); j++)
                        ret.push_back(sto[i][j]);
                }
                return ret;
            }
            res = cursor % (2 * numRows - 2);
            if (res < numRows)
                sto[res].push_back(s[cursor]);
            else
                sto[2 * numRows - 2 - res].push_back(s[cursor]);
            cursor++;
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.convert("ABCDE", 3) << endl;
    return 0;
}