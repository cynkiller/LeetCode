#include <iostream>
#include <vector>
#include "limits.h"

using namespace std;

#if 0
class Solution {
public:
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)   //保证数组1一定最短
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //我们目前是虚拟加了'#'所以数组1是2*n长度
        while(lo <= hi)   //二分
        {
            c1 = (lo+hi)/2;  //c1是二分的结果
            c2 = m+n- c1;
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)
                hi = c1-1;
            else if(L2 > R1)
                lo = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
};
#endif

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int N1 = nums1.size(), N2 = nums2.size();
        int medean = (N1 + N2 + 1) / 2, i = 0, j = 0;
        for(int k = 1; k < medean; k++)
        {
            if(i < N1 && j < N2)
            {
                if(nums1[i] < nums2[j])i++;
                else j++;
            }
            else if(i >= N1)//数组nums1到达末尾
                j++;
            else if(j >= N2)//数组nums2到达末尾
                i++;
        }
        if(i < N1 && j < N2)
            return nums1[i] < nums2[j] ? nums1[i] : nums2[j];
        else if(i >= N1)
            return nums2[j];
        else if(j >= N2)
            return nums1[i];
    }
};

#if 0
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // write your code here  
        int len1=nums1.size();  
        int len2=nums2.size();  
        int len=len1+len2;  
        if(len & 1){  
            return findKth(nums1,0,nums2,0,len/2+1);  
        }  
        return (findKth(nums1,0,nums2,0,len/2)+findKth(nums1,0,nums2,0,len/2+1))/2;  
    }  
  
    double findKth(vector<int>& nums1,int i1,vector<int>& nums2,int i2,int k){  
        if(i1>=nums1.size()){  
            return nums2[i2+k-1];  
        }  
        if(i2>=nums2.size()){  
            return nums1[i1+k-1];  
        }  
        if(k==1){  
            return min(nums1[i1],nums2[i2]);  
        }  
  
        int key1=i1+k/2-1>=nums1.size()?INT_MAX:nums1[i1+k/2-1];  
        int key2=i2+k/2-1>=nums2.size()?INT_MAX:nums2[i2+k/2-1];  
        if(key1<key2){  
            return findKth(nums1,i1+k/2,nums2,i2,k-k/2);  
        }else{  
            return findKth(nums1,i1,nums2,i2+k/2,k-k/2);  
        }  
    }  
  
};
#endif

int main(int argc, char const *argv[])
{
    vector<int> nums1(2);
    vector<int> nums2(2);
    nums1[0] = 1;
    nums1[1] = 2;
    nums2[0] = 3;
    nums2[1] = 4;
    Solution s;
    for (vector<int>::iterator p = nums1.begin(); p != nums1.end(); p++)
        cout << *p << "\t";
    cout << endl;
    for (vector<int>::iterator p = nums2.begin(); p != nums2.end(); p++)
        cout << *p << "\t";
    cout << endl;
    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}