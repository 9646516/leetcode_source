// id:374242547
// runtime:556 ms
// memory:14 MB
// title:单词演变
// translatedTitle:单词演变
// questionId:1000300
// time:2022-10-18 18:49:09

class Solution {
public:
    vector<int>V[5005];
    void add(int x,int y){
        V[x].push_back(y);
        V[y].push_back(x);
    }
    int seek( vector<string>& wordList,string&s){
        int idx=-1;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==s){
                idx=i;
                break;
            }
        }
        return idx;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int src=seek(wordList,beginWord);
        if(src==-1){
            wordList.push_back(beginWord);
            src=wordList.size()-1;
        }
        int dst=seek(wordList,endWord);
        if(dst==-1)return 0;
        const int sz=endWord.size();
        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                int d=0;
                for(int k=0;k<sz;k++){
                    if(wordList[i][k]!=wordList[j][k])d++;
                    if(d>1)break;
                }
                if(d==1){
                    add(i,j);
                }
            }
        }
        int dis[5005];
        memset(dis,0x3f,sizeof(dis));
        dis[src]=1;
        queue<pair<int,int>>q;
        q.push({1,src});
        while(!q.empty()){
            auto [d,now]=q.front();
            q.pop();
            for(int i:V[now]){
                if(dis[i]>d+1){
                    dis[i]=d+1;
                    q.push({d+1,i});
                }
            }
        }
        int ans=dis[dst];
        if(ans==0x3f3f3f3f)ans=0;
        return ans;
    }
};