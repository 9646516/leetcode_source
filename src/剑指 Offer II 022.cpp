// id:373847590
// runtime:12 ms
// memory:7.4 MB
// title:链表中环的入口节点
// translatedTitle:链表中环的入口节点
// questionId:1000258
// time:2022-10-17 16:15:47

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
    ListNode *detectCycle(ListNode *head) {
        auto A=head,B=head;
        do {
            if(!A||!B||!B->next)return nullptr;
            A=A->next;
            B=B->next->next;
        }while(A!=B);
        B=head;
        while(A!=B){
            A=A->next;
            B=B->next;
        }
        return A;
    }
};