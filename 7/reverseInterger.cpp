/****************************************************************************
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Note:
The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
*****************************************************************************/

#include <iostream>
#include "limits.h"

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        int temp;
        while( x) {
            temp = sum * 10 + x % 10;
            if (temp / 10 !=  sum) return 0;
            x /= 10;
            sum = temp;
        }
        return sum;
    }
};

int main() {
    Solution slt;
    std::cout << slt.reverse(1534236469) << std::endl;
    std::cout << slt.reverse(-2147483648) << std::endl;
    return 0;
}