// id:373292376
// runtime:8 ms
// memory:10.3 MB
// title:链表中倒数第k个节点 LCOF
// translatedTitle:链表中倒数第k个节点
// questionId:100294
// time:2022-10-15 20:27:41

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
    int len(ListNode*x){
        if(!x)return 0;
        return 1+len(x->next);
    }
    ListNode* dfs(ListNode*x,int k){
        if(k==1)return x;
        return dfs(x->next,k-1);
    }
    ListNode* getKthFromEnd(ListNode* head, int k) {
        int sz=len(head);
        k=sz-k+1;
        return dfs(head,k);
    }
};