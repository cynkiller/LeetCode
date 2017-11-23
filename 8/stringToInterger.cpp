#include <iostream>
#include <string>
#include "limits.h"
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int base = 0;
        long num = 0;
        int flag = 1;
        string::iterator p = str.begin();
        while (*p == ' ') p++;
        if (*p == '+') {
            p++;
        } else if (*p == '-') {
            p++;
            flag = -1;
        }
        if (!str.compare(0, 2, "0x") || !str.compare(0, 2, "0X")) {
            base = 16;
            p++;
            p++;
        } else
            base = 10;

        for (; p != str.end(); p++) {
            if(*p > '9' || *p < '0') return num * flag;
            num = num * base + *p - '0';
            if (num > 0 && (long)((int) num) != num) return flag > 0 ? INT_MAX : INT_MIN;
        }
        return (int)num * flag;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.myAtoi("2147483648") << endl;
    return 0;
}