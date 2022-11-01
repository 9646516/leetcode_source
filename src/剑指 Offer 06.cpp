// id:373272600
// runtime:0 ms
// memory:8.9 MB
// title:从尾到头打印链表 LCOF
// translatedTitle:从尾到头打印链表
// questionId:100282
// time:2022-10-15 19:08:36

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
    vector<int>ret;
    void dfs(ListNode*x){
        if(x==nullptr)return;
        dfs(x->next);
        ret.push_back(x->val);
    }
    vector<int> reversePrint(ListNode* head) {
        dfs(head);
        return ret;
    }
};