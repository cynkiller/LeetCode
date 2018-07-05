#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

static const int speedUp = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

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
    map<char, int> r_units;
    vector<int> v;
public:
    Solution() {
        for (auto& unit : units) {
            v.push_back(unit.first);
            r_units.insert(pair<char, int>(unit.second, unit.first));
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

    int romanToInt(string s) {
        int num = 0;
        for (int i = 0; i < s.size(); i++) {
            //cout << c << ' ';
            int current = r_units[s[i]];
            if (i < (s.size() - 1)) {
                int next = r_units[s[i + 1]];
                if (next > current) {
                    current = next - current;
                    i++;
                }
            }
            num = num + current;
        }
        return num;
    }

/* A simple way
    string intToRoman(int num) {
        vector<int> values =  {1000,900, 500,400, 100, 90, 50, 40,  10,  9,   5,   4,  1};
        vector<string> strs = {"M", "CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        
        string res = "";
        for (int i=0; i<values.size(); i++) {
            while (num >= values[i]) {
                num -= values[i];
                res.append(strs[i]);
            }
        } 
        return res;
    }
*/

/* Another simple answer
public static String intToRoman(int num) {
    String M[] = {"", "M", "MM", "MMM"};
    String C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    String X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    String I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}
*/
};

int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    int testcases[] = {3, 9, 10, 20, 50, 100, 500, 1000, 1994, 1998, 2000};
    for (auto i : testcases) {
        string roman = s->intToRoman(i);
        cout << i << ": " << roman << " -> " << s->romanToInt(roman) << endl;
    }
    return 0;
}