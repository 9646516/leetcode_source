// id:374290258
// runtime:44 ms
// memory:9.9 MB
// title:相似的字符串
// translatedTitle:相似的字符串
// questionId:1000317
// time:2022-10-18 21:04:04

int fa[333];
class Solution {
public:
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    int numSimilarGroups(vector<string>& strs) {
        const int N=strs.size();
        const int sz=strs.front().size();
        for(int i=0;i<N;i++)fa[i]=i;
        vector<int>V;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                V.clear();
                for(int k=0;k<sz;k++){
                    if(strs[i][k]!=strs[j][k]){
                        V.push_back(k);
                    }
                    if(V.size()>2)break;
                }
                int ok=0;
                if(V.size()==0)ok=1;
                else if(V.size()==2){
                    int a=V[0],b=V[1];
                    if(strs[i][a]==strs[j][b]&&strs[i][b]==strs[j][a]){
                        ok=1;
                    }
                }
                if(ok){
                    int f1=seek(i);
                    int f2=seek(j);
                    fa[f1]=f2;
                }
            }
        }
        unordered_set<int>st;
        for(int i=0;i<N;i++)st.insert(seek(i));
        return st.size();
    }
};