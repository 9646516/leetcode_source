// id:374003083
// runtime:48 ms
// memory:72 MB
// title:最短的单词编码
// translatedTitle:最短的单词编码
// questionId:1000329
// time:2022-10-17 23:15:17

struct node{
    node*next[26];
};

class Solution {
public:
    node*root;
    void add(node*now,string&s){
        for(char i:s){
            int B=i-'a';
            if(!now->next[B])now->next[B]=new node();
            now=now->next[B];
        }
    }
    int ans;
    void dfs(node*now,int dep){
        int leaf=1;
        for(int i=0;i<26;i++){
            if(now->next[i]){
                leaf=0;
                dfs(now->next[i],dep+1);
            }
        }
        if(leaf)
            ans+=dep+1;
    }
    int minimumLengthEncoding(vector<string>& words) {
        root=new node();
        for(auto&i:words){
            reverse(i.begin(),i.end());
            add(root,i);
        }
        dfs(root,0);
        return ans;
    }
};