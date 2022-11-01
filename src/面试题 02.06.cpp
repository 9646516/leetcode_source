// id:374516048
// runtime:12 ms
// memory:21.1 MB
// title:Palindrome Linked List LCCI
// translatedTitle:回文链表
// questionId:100164
// time:2022-10-19 15:55:30

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    pair<ListNode*,ListNode*>dfs(ListNode*x){
        if(!x->next)return {x,x};
        else{
            auto [h,t]=dfs(x->next);
            t->next=x;
            return {h,x};
        }
    }
    bool isPalindrome(ListNode* head) {
        int sz=0;
        {
            auto now=head;
            while(now){
                now=now->next;
                sz++;
            }
        }
        if(sz<=1)return 1;
        int sz1=sz/2;
        ListNode*now=head;
        for(int i=1;i<sz1;i++)now=now->next;
        auto head2=now->next;
        now->next=nullptr;
        auto [h,t]=dfs(head2);
        t->next=nullptr;
        for(int i=0;i<sz1;i++){
            if(head->val!=h->val){
                return 0;
            }
            head=head->next;
            h=h->next;
        }
        return 1;
    }
};