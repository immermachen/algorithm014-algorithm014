// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem66.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool rest = true;
        int i = digits.size()-1;     
        while (rest)
        {
            if(i==-1) {
                digits.insert(digits.begin(), 1);
                rest = false;
            }else{
                if(digits[i]==9){
                    digits[i--] = 0;                    
                }else{
                    digits[i] += 1;
                    rest = false;
                }
            }     
        }
        return digits;
    }
};
// @lc code=end

