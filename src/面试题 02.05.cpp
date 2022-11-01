// id:374513597
// runtime:36 ms
// memory:69.2 MB
// title:Sum Lists LCCI
// translatedTitle:链表求和
// questionId:100188
// time:2022-10-19 15:49:40

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto head=new ListNode();
        auto tail=head;
        int lbit=0;
        while(l1||l2){
            int val=0;
            if(l1){
                val+=l1->val;
                l1=l1->next;
            }
            if(l2){
                val+=l2->val;
                l2=l2->next;
            }
            val+=lbit;
            if(val>=10){
                lbit=1;
                val-=10;
            }else{
                lbit=0;
            }
            tail->next=new ListNode();
            tail->next->val=val;
            tail=tail->next;
        }
        if(lbit){
            tail->next=new ListNode();
            tail->next->val=1;
            tail=tail->next;
        }
        tail->next=nullptr;
        auto ret=head->next;
        delete head;
        return ret;
    }
};