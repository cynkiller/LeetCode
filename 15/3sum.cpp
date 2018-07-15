#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <sys/time.h>

using namespace std;

void print_vec(vector<int>& vec) {
    for(auto i: vec)
        cout << i << ' ';
    cout << endl;
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        if (size < 3) return ans;

        int zeroPosition = 0;
        int i;
        // sort array
        //print_vec(nums);
        sort(nums.begin(), nums.end());
        //print_vec(nums);

        // precheck: first element >0 or last element <0, just return
        if (nums[0] > 0 || nums[size - 1] < 0)
            return ans;

        // get the 0 position or the first non-negative position
        i = 0;
        while(nums[i++] < 0) ;
        zeroPosition = i - 1; // 0 or 1st >0 element position

        // negetive elements i0 range starts from left
        for( int j = 0; j <= zeroPosition; j++) {
            if (j > 0 && nums[j] == nums[j - 1]) continue;
            // positive elements j0 range starts from right
            for (int k = size - 1; k >= zeroPosition; k-- ){
                if (k < size - 1 && nums[k] == nums[k + 1]) continue;
                int twosum = nums[j] + nums[k];
                if (twosum < 0) {
                    // search from right to 0 position if i0 + j0 negtive
                    for(int h = k - 1; h >= zeroPosition; h--) {
                        if (twosum + nums[h] < 0) break;
                        if (twosum + nums[h] == 0) {
                            ans.push_back({nums[j], nums[h], nums[k]});
                            break;
                        }
                    }
                } else if ( twosum > 0) {
                    // search from left to 0 position if i0 + j0 positive
                    for(int h = j + 1; h < zeroPosition; h++) {
                        if (twosum + nums[h] > 0) break;
                        if (twosum + nums[h] == 0) {
                            ans.push_back({nums[j], nums[h], nums[k]});
                            break;
                        }
                    }
                } else {
                    // check 0 exists if 0
                    for(int h = zeroPosition; h < k; h++) {
                        if (j == h) continue;
                        if (nums[h] != 0) break;
                        if (twosum + nums[h] == 0) {
                            ans.push_back({nums[j], nums[h], nums[k]});
                            break;
                        }
                    }
                }
                
            }

        }

        return ans;
    }

    vector<vector<int>> threeSumRef(vector<int>& nums) {
        std::sort(nums.begin() , nums.end());
        vector<vector<int>> res ;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] > 0 ) break;
            if(i > 0 && nums[i] == nums[i-1]) continue ;
            int left = i+1 , right = nums.size()-1, target = -nums[i];
            while(left<right){
                if(nums[left] + nums[right] > target) right--;
                else if(nums[left] + nums[right] < target) left ++;
                else {
                    res.push_back({nums[i] , nums[left] , nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;right--;
                }
            }
        }
        return res ;
    }
};


int main(int argc, char const *argv[])
{
    Solution *s = new Solution();
    //vector<int> nums = {-1, 0, 1, 2, -1, -4};
    //vector<int> nums = {0, 0, 0};
    //vector<int> nums = {1, 1, -2};
    //vector<int> nums = {-1, 0, 1, 0};
    //vector<int> nums = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    //vector<int> nums = {-4,-2,1,-5,-4,-4,4,-2,0,4,0,-2,3,1,-5,0};
    vector<int> nums = {6,-5,-6,-1,-2,8,-1,4,-10,-8,-10,-2,-4,-1,-8,-2,8,9,-5,-2,-8,-9,-3,-5};
    //-10 -10 -9 -8 -8 -8 -6 -5 -5 -5 -4 -3 -2 -2 -2 -2 -1 -1 -1 4 6 8 8 9
    vector<vector<int>> ans;
    struct timeval tp;
    long long start, end;

    gettimeofday(&tp, NULL);
    start = (long long) tp.tv_sec * 1000 + tp.tv_usec / 1000;
    for (int i = 0; i < 10000; i++)
        ans = s->threeSum(nums);
    gettimeofday(&tp, NULL);
    end = (long long) tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << start << " " << end << endl;
    cout << "threeSum took " << end - start << " seconds." << endl;
    for (auto i: ans) {
        print_vec(i);
    }
    gettimeofday(&tp, NULL);
    start = (long long) tp.tv_sec * 1000 + tp.tv_usec / 1000;
    for (int i = 0; i < 10000; i++)
        ans = s->threeSumRef(nums);
    gettimeofday(&tp, NULL);
    end = (long long) tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << start << " " << end << endl;
    cout << "threeSumRef took " << end - start << " seconds." << endl;
 
    /* should be:
    [
      [-1, 0, 1],
      [-1, -1, 2]
    ]
    */
    return 0;
}