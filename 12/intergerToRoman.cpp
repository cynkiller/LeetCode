#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    map<int, char> units = {
        {1, 'I'},
        {5, 'V'},
        {10, 'X'},
        {50, 'L'},
        {100, 'C'},
        {500, 'D'},
        {1000, 'M'}
    };
    vector<int> v;
public:
    Solution() {
        for (auto& unit : units) {
            v.push_back(unit.first);
        }
    }
    string intToRoman(int num) {
        string out;
              
        // Handle the largest unit
        int i = v.size() - 1;
        int count = num / v[i];
        out.append(string(count, units[v[i]]));
        num = num - v[i] * count;
        for (i = v.size() - 1; i > 0; i--) {
            // Current unit minus prefix unit
            int prefix = int( (i - 1) / 2) * 2;
            int preunit = v[i] - v[prefix];
            count = num / preunit;
            out.append(string(count, units[v[prefix]]));
            out.append(string(count > 0 ? 1 : 0, units[v[i]]));
            num = num - preunit * count;

            // Next unit
            count = num / v[i - 1];
            out.append(string(count, units[v[i - 1]]));
            num = num - v[i - 1] * count;
        }
        return out;
    }
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    int testcases[] = {3, 9, 10, 20, 50, 100, 500, 1000, 1998, 2000};
    for (auto i : testcases) {
        cout << i << ": " << s->intToRoman(i) << endl;
    }
    return 0;
}