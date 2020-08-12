/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
        if(!l1) return l2;
        if(!l2) return l1;
        if(l1->val >= l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        } else {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
    }
    // ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {        
    //     ListNode* l=nullptr;
    //     merge(l1, l2, l);
    //     return l;
    // }
    // void merge(ListNode* l1, ListNode* l2, ListNode* &l) {
    //     if(!l1) {l = l2; return;}
    //     if(!l2) {l = l1; return;}        
    //     if (l1->val >= l2->val) {
    //         l = l2;
    //         l2 = l2->next;
    //     } else {
    //         l = l1;
    //         l1 = l1->next;
    //     }
    //     merge(l1, l2, l->next);
    // }
};
// @lc code=end

