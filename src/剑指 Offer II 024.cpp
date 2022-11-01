// id:373848953
// runtime:8 ms
// memory:9.6 MB
// title:反转链表
// translatedTitle:反转链表
// questionId:1000260
// time:2022-10-17 16:18:46

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
    pair<ListNode*,ListNode*> dfs(ListNode*x){
        if(!x->next)return {x,x};
        else{
            auto [h,t]=dfs(x->next);
            t->next=x;
            return {h,x};
        }
    }
    ListNode* reverseList(ListNode* head) {
        if(!head)return nullptr;
        auto [h,t]=dfs(head);
        t->next=nullptr;
        return h;
    }
};