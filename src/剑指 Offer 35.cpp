// id:373316013
// runtime:8 ms
// memory:11.3 MB
// title:复杂链表的复制  LCOF
// translatedTitle:复杂链表的复制
// questionId:100300
// time:2022-10-15 21:41:30

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    unordered_map<Node*,Node*>mp;
    Node*dfs(Node*x){
        if(!x)return nullptr;
        Node*ret=new Node(x->val);
        mp[x]=ret;
        ret->next=dfs(x->next);
        return ret;
    }
    void dfs2(Node*x,Node*x2){
        if(!x)return;
        if(x->random==nullptr)x2->random=nullptr;
        else x2->random=mp[x->random];
        dfs2(x->next,x2->next);
    }
    Node* copyRandomList(Node* head) {
        if(!head)return nullptr;
        auto root=dfs(head);
        dfs2(head,root);
        return root;
    }
};