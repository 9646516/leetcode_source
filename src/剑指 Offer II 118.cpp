// id:374291033
// runtime:4 ms
// memory:8.4 MB
// title:多余的边
// translatedTitle:多余的边
// questionId:1000318
// time:2022-10-18 21:05:56

int fa[1005];
class Solution {
public:
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(int i=0;i<=1000;i++)fa[i]=i;
        for(auto&i:edges){
            int a=i[0];
            int b=i[1];
            int f1=seek(a);
            int f2=seek(b);
            if(f1==f2)return {a,b};
            fa[f1]=f2;
        }
        return {};
    }
};