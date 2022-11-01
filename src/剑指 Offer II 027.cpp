// id:373870166
// runtime:188 ms
// memory:125.1 MB
// title:回文链表
// translatedTitle:回文链表
// questionId:1000263
// time:2022-10-17 17:07:05

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
    bool isPalindrome(ListNode* head) {
        vector<int>V;
        {
            auto now=head;
            while(now){
                V.push_back(now->val);
                now=now->next;
            }
        }
        int L=0,R=(int)V.size()-1;
        while(L<=R){
            if(V[L]!=V[R])return 0;
            L++;R--;
        }
        return 1;
    }
};