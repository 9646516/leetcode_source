// id:374517354
// runtime:8 ms
// memory:7.3 MB
// title:Linked List Cycle LCCI
// translatedTitle:环路检测
// questionId:100168
// time:2022-10-19 15:58:44

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
        ListNode* p1=head, * p2=head;
        do{
            if(!p1||!p2||!p2->next)return nullptr;
            p1=p1->next;
            p2=p2->next->next;
        }while(p1!=p2);
        p2=head;
        while(p1!=p2){
            p1=p1->next;
            p2=p2->next;
        }
        return p1;
    }
};