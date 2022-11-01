// id:373877319
// runtime:4 ms
// memory:7.3 MB
// title:展平多级双向链表
// translatedTitle:展平多级双向链表
// questionId:1000264
// time:2022-10-17 17:25:04

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    pair<Node*,Node*> dfs(Node*x){
        auto next=x->next;
        auto child=x->child;
        x->next=x->child=x->prev=nullptr;
        auto tail=x;
        if(child){
            auto [h,t]=dfs(child);
            tail->next=h;
            h->prev=tail;
            tail=t;
        }
        if(next){
            auto [h,t]=dfs(next);
            tail->next=h;
            h->prev=tail;
            tail=t;
        }
        return {x,tail};
    }
    Node* flatten(Node* head) {
        if(!head)return nullptr;
        auto [h,t]=dfs(head);
        return h;
    }
};