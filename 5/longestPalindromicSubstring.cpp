#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        //string max, sub;
#if 0 /* Time exceeded */
        for(int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                sub = s.substr(i, j - i + 1);
                if( checkPadmc(sub)) {
                    if (sub.length() > max.length())
                        max = sub;
                }
            }
        }
#endif
#if 0 /* my method */
        for(int i = 0; i < s.length(); i++) {
            int found = s.length();
            while((found = s.find_last_of(s[i], found)) != string::npos) {
            // find the largest padmc substr start from the current position
                sub = s.substr(i, found - i + 1);
                if( checkPadmc(sub)) {
                    if (sub.length() > max.length())
                        max = sub;
                    break;
                }
                found -= 1;
            }
        }
#endif
        //return max;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i , i + 1);
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1)/2;
                end = i + len /2;
            }
        }
        return s.substr(start, end - start + 1);
    }

    bool checkPadmc(string s) {
        int i = 0;
        int j = s.length() - 1;
        while ( i <= j ) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }
        return true;
    }

    int expandAroundCenter(string s, int left, int right) {
        int l = left;
        int r = right;
        while (l >= 0 && r < s.length() &&
                s[r] == s[l]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};

int main(int argc, char const *argv[])
{
    string str("tattarrattat");
    Solution s;
    cout << s.longestPalindrome(str) << endl;
    return 0;
}