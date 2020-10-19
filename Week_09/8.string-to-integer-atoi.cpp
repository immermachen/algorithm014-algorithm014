/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string str) {
        int i = 0, sign = 1;     
        long newInt = 0;
        while (str[i]==' ') i++;
        if (str[i]=='-') { sign = -1; i++; } 
        else if (str[i]=='+') i++;          
        while (str[i]>='0' && str[i]<='9') {
            newInt = newInt*10 + (str[i]-'0');
            if(sign*newInt > INT_MAX) return INT_MAX;
            if(sign*newInt < INT_MIN) return INT_MIN;    
            i++;
        }
        return sign*newInt;        
    }
};
// @lc code=end

