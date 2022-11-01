// id:373830556
// runtime:8 ms
// memory:10.3 MB
// title:删除链表的倒数第 n 个结点
// translatedTitle:删除链表的倒数第 n 个结点
// questionId:1000257
// time:2022-10-17 15:35:23

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz=0;
        {
            auto now=head;
            while(now){
                now=now->next;
                sz++;
            }
        }
        int k=sz-n+1;
        auto root=new ListNode();
        root->next=head;
        ListNode* prev=root,*now=head;
        for(int i=1;i<k;i++){
            prev=now;
            now=now->next;
        }
        prev->next=now->next;
        auto ret=root->next;
        delete root;
        return ret;
    }
};