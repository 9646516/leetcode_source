// id:373890130
// runtime:12 ms
// memory:7.9 MB
// title:排序的循环链表
// translatedTitle:排序的循环链表
// questionId:1000265
// time:2022-10-17 18:07:01

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    void solve(Node*F,Node* val){
        Node*prev=F;
        Node*now=F->next;
        while(1){
            if(now->val>=val->val&&val->val>=prev->val){
                prev->next=val;
                val->next=now;
                break;
            }
            prev=now;
            now=now->next;
        }
    }
    Node* insert(Node* head, int insertVal) {
        if(!head){
            auto ret=new Node();
            ret->next=ret;
            ret->val=insertVal;
            return ret;
        }else if(head==head->next){
            auto nx=new Node();
            nx->val=insertVal;
            head->next=nx;
            nx->next=head;
            return head;
        }else{
            Node*prev=head;
            Node*now=head->next;
            while(now!=head){
                if(now->val<prev->val)break;
                prev=now;
                now=now->next;
            }
            auto nx=new Node();
            nx->val=insertVal;
            if(now->val>=insertVal||prev->val<=insertVal){
                prev->next=nx;
                nx->next=now;
            }else{
                solve(now,nx);
            }
            return head;
        }
    }
};