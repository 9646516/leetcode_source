// id:373292993
// runtime:0 ms
// memory:9.6 MB
// title:反转链表 LCOF
// translatedTitle:反转链表
// questionId:100298
// time:2022-10-15 20:30:07

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
        auto [h,t]=dfs(x->next);
        t->next=x;
        return {h,x};
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        auto [h,t]=dfs(head);
        t->next=nullptr;
        return h;
    }
};