// id:373867454
// runtime:36 ms
// memory:18.1 MB
// title:重排链表
// translatedTitle:重排链表
// questionId:1000262
// time:2022-10-17 17:00:41

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
    void reorderList(ListNode* head) {
        deque<ListNode*>V;
        {
            auto now=head;
            while(now){
                V.push_back(now);
                now=now->next;
            }
        }
        auto root=new ListNode();
        auto now=root;
        int op=0;
        while(!V.empty()){
            if(op==0){
                now->next=V.front();
                V.pop_front();
            }else{
                now->next=V.back();
                V.pop_back();
            }
            op^=1;
            now=now->next;
        }
        now->next=nullptr;
        head=root->next;
        delete root;
    }
};