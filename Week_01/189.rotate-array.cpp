/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        if(nums.size()==k || nums.size()<2 || k==0) return;        
        int i=0 , tmp=0;
        int gcdk = gcd(nums.size(), k);
        for (int j=0; j<gcdk; ++j) {          
            i=k+j;
            while( i!=j ) {     
                tmp = nums[i];
                nums[i] = nums[j];
                nums[j] = tmp;
                i+=k;
                i = i%nums.size();
            }   
        }
    }    
    //Greatest common divisor
    int gcd(int m, int n) {
        return n == 0 ? m : gcd(n, m % n);
    }
    
    
    // My Method 1: slowly
    // void rotate(vector<int>& nums, int k) {
    //     k = k % nums.size();
    //     int tmp=0;
    //     while(k--) {
    //         tmp = nums[nums.size()-1];
    //         nums.pop_back();
    //         nums.insert(nums.begin(), tmp);
    //     }
    // }
};
// @lc code=end

