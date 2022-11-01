// id:374003479
// runtime:44 ms
// memory:72.1 MB
// title:Short Encoding of Words
// translatedTitle:单词的压缩编码
// questionId:839
// time:2022-10-17 23:16:34

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