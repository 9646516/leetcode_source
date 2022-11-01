// id:374287323
// runtime:24 ms
// memory:13.4 MB
// title:省份数量
// translatedTitle:省份数量
// questionId:1000346
// time:2022-10-18 20:57:05


int fa[202];
class Solution {
public:
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        const int N=isConnected.size();
        for(int i=0;i<N;i++)fa[i]=i;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(isConnected[i][j]){
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