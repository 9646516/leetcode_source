// id:375245427
// runtime:596 ms
// memory:394.6 MB
// title:Word Rectangle LCCI
// translatedTitle:单词矩阵
// questionId:1000049
// time:2022-10-21 20:04:28

struct node{
    node* next[26];
    int end;
    node(){
        end=0;
        for(int i=0;i<26;i++)next[i]=nullptr;
    }
};
void insert(node*root,const string&x){
    for(int i=0;i<x.size();i++){
        if(!root->next[x[i]-'a'])root->next[x[i]-'a']=new node();
        root=root->next[x[i]-'a'];
    }
    root->end++;
}
const int OK=0;
const int END=1;
const int BAD=2;
class Solution {
public:
    vector<string>V[105];
    node*root;
    vector<string>ans;
    vector<string>now;
    void update(){
        if(now.empty())return;
        if(ans.empty())ans=now;
        else{
            int sz=now.size()*now.front().size();
            int sz2=ans.size()*ans.front().size();
            if(sz>sz2)ans=now;
        }
    }
    int test(){
        if(now.empty())return OK;
        const int N=now.size();
        const int M=now.front().size();
        int end=1;
        for(int i=0;i<M;i++){
            node*head=root;
            for(int j=0;j<N;j++){
                if(!head->next[now[j][i]-'a']){
                    return BAD;
                }
                head=head->next[now[j][i]-'a'];
            }
            if(!head->end){
                end=0;
            }
        }
        if(end)return END;
        else return OK;
    }
    void dfs(int idx){
        int state=test();
        if(state==BAD)return;
        if(state==END)update();
        if(now.size()==idx)return;
        for(auto&i:V[idx]){
            now.push_back(i);
            dfs(idx);
            now.pop_back();
        }
    }
    vector<string> maxRectangle(vector<string>& words) {
        for(auto&i:words){
            V[i.size()].push_back(i);
        }
        root=new node();
        for(int i=1;i<=100;i++){
            for(auto&j:V[i]){
                insert(root,j);
            }
        }
        for(int i=1;i<=100;i++){
            if(!V[i].empty())
                dfs(i);
        }
        return ans;
    }
};