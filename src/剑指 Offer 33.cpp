// id:373306895
// runtime:4 ms
// memory:6.8 MB
// title:二叉搜索树的后序遍历序列 LCOF
// translatedTitle:二叉搜索树的后序遍历序列
// questionId:100315
// time:2022-10-15 21:17:29

class Solution {
public:
    vector<int>V;
    bool solve(int l,int r){
        if(l>=r)return 1;
        int root=V[r];
        r--;
        int p1=l,p2=r;
        while(p1<=r&&V[p1]<root)p1++;
        while(p2>=l&&V[p2]>root)p2--;
        p1--;p2++;
        return p1==p2-1&&solve(l,p1)&&solve(p2,r);
    }
    bool verifyPostorder(vector<int>& postorder) {
        V=postorder;
        return solve(0,V.size()-1);
    }
};