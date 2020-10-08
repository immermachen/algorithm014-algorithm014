/*
 * @lc app=leetcode id=1122 lang=cpp
 *
 * [1122] Relative Sort Array
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int N=1001;
        int a1[1001]={0}; 
        for(int i=0;i<arr1.size();++i) {
            a1[arr1[i]]++;
        }
        int idx1=0;
        for(int i=0;i<arr2.size();++i) {
            for(int j=0; j<a1[arr2[i]]; ++j){
                arr1[idx1++] = arr2[i];
            }
            a1[arr2[i]]=0;
        }
        for(int i=0; i<N; ++i) {
            for(int j=0; j<a1[i]; ++j){
                arr1[idx1++] = i;
            }
        }
        return arr1;           
    }
};
// @lc code=end

