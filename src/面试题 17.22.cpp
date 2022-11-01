// id:374966116
// runtime:412 ms
// memory:12.9 MB
// title:Word Transformer LCCI
// translatedTitle:单词转换
// questionId:1000030
// time:2022-10-20 21:52:43

class Solution {
public:
    bool cmp(string&a,string&b){
        if(a.size()!=b.size())return 0;
        int bad=0;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i])bad++;
            if(bad>1)return 0;
        }
        return 1;
    }
    vector<string> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int ok1=0,ok2=0;
        for(auto&i:wordList){
            if(i==endWord){ok2=1;}
            if(i==beginWord){ok1=1;}
        }
        if(!ok2)return {};
        if(!ok1)wordList.push_back(beginWord);
        vector<vector<int>>V(wordList.size());

        for(int i=0;i<wordList.size();i++){
            for(int j=i+1;j<wordList.size();j++){
                if(cmp(wordList[i],wordList[j])){
                    V[i].push_back(j);
                    V[j].push_back(i);
                }
            }
        }
        int src,dst;
        for(int i=0;i<wordList.size();i++){
            if(wordList[i]==endWord)dst=i;
            if(wordList[i]==beginWord)src=i;
        }
        vector<int>dis(wordList.size(),2e9);
        vector<int>fa(wordList.size(),-1);
        dis[src]=0;
        queue<pair<int,int>>q;
        q.push({0,src});
        while(!q.empty()){
            auto [d,now]=q.front();
            q.pop();
            for(int i:V[now]){
                if(dis[i]>d+1){
                    dis[i]=d+1;
                    q.push({d+1,i});
                    fa[i]=now;
                }
            }
        }
        if(dis[dst]>1e9)return {};
        int now=dst;
        vector<int>s;
        while(now!=src){
            s.push_back(now);
            now=fa[now];
        }
        s.push_back(src);
        reverse(s.begin(),s.end());
        vector<string>ans;
        for(int i:s)ans.push_back(wordList[i]);
        return ans;
    }
};