// id:374512264
// runtime:4 ms
// memory:9.9 MB
// title:Partition List LCCI
// translatedTitle:分割链表
// questionId:1000008
// time:2022-10-19 15:46:32

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
    ListNode* partition(ListNode* head, int x) {
        auto h1=new ListNode();
        auto t1=h1;
        auto h2=new ListNode();
        auto t2=h2;
        while(head){
            if(head->val<x){
                t1->next=head;
                t1=t1->next;
            }else{
                t2->next=head;
                t2=t2->next;
            }
            head=head->next;
        }
        t2->next=nullptr;
        t1->next=h2->next;
        head=h1->next;
        delete h1;
        delete h2;
        return head;
    }
};