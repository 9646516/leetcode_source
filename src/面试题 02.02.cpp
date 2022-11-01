// id:374508789
// runtime:8 ms
// memory:10.1 MB
// title:Kth Node From End of List LCCI
// translatedTitle:返回倒数第 k 个节点
// questionId:1000007
// time:2022-10-19 15:38:18

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
    int kthToLast(ListNode* head, int k) {
        int sz=0;
        {
            auto now=head;
            while(now){
                now=now->next;
                sz++;
            }
        }
        k=sz+1-k;
        auto now=head;
        while(k!=1){
            now=now->next;
            k--;
        }
        return now->val;
    }
};