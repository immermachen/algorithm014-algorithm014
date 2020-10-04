/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode  dummy(0);
        dummy.next = head;
        ListNode *pre=&dummy, *L=pre, *R=pre, *end=head;
        int i=0;
        while(end!=nullptr) {            
            while(i<k && R!=nullptr){
                R=R->next;
                i++;
            }
            if(R==nullptr) return dummy.next;            
            
            i=0;
            end=R->next;
            L = pre->next; 
            R->next = nullptr;                
            pre->next=reverseList(L);
            L->next = end;
            pre = L;
            R = pre;                            
        }
        return dummy.next;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=head, *next=head->next;
        pre->next=nullptr;
        while(next) {
            head = next;
            next = next->next;
            head->next = pre;
            pre = head;
        }
        return head;
    }
};
// @lc code=end

