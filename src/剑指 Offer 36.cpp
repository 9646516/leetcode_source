// id:373322263
// runtime:8 ms
// memory:7.7 MB
// title:二叉搜索树与双向链表  LCOF
// translatedTitle:二叉搜索树与双向链表
// questionId:100305
// time:2022-10-15 22:01:21

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    pair<Node*,Node*> solve(Node*x){
        if(x->left&&x->right){
            auto[h1,t1]=solve(x->left);
            auto[h2,t2]=solve(x->right);
            x->left=t1;
            t1->right=x;
            x->right=h2;
            h2->left=x;
            return {h1,t2};
        }else if(x->left){
            auto[h1,t1]=solve(x->left);
            x->left=t1;
            t1->right=x;
            return {h1,x};
        }else if(x->right){
            auto[h2,t2]=solve(x->right);
            x->right=h2;
            h2->left=x;
            return {x,t2};
        }else{
            return {x,x};
        }
    }
    Node* treeToDoublyList(Node* root) {
        if(!root)return nullptr;
        auto[h,t]=solve(root);
        t->right=h;
        h->left=t;
        return h;
    }
};