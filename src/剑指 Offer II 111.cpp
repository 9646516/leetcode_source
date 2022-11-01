// id:374270786
// runtime:0 ms
// memory:7.8 MB
// title:计算除法
// translatedTitle:计算除法
// questionId:1000305
// time:2022-10-18 20:16:08

class Solution {
public:
    int fa[55];
    double rank[55];
    int seek(int x){
        if(fa[x]==x){
            return x;
        }else{
            auto f=seek(fa[x]);
            rank[x]=rank[fa[x]]*rank[x];
            fa[x]=f;
            return f;
        }
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<string>H;
        for(auto &i:equations){
            H.push_back(i[0]);
            H.push_back(i[1]);
        }
        for(int i=0;i<55;i++){
            fa[i]=i;
            rank[i]=1;
        }
        sort(H.begin(),H.end());
        H.resize(unique(H.begin(),H.end())-H.begin());
        for(int i=0;i<equations.size();i++){
            int a=lower_bound(H.begin(),H.end(),equations[i][0])-H.begin();
            int b=lower_bound(H.begin(),H.end(),equations[i][1])-H.begin();
            double val=values[i];
            int f1=seek(a);
            int f2=seek(b);
            fa[f1]=f2;
            rank[f1]=val*rank[b]/rank[a];
        }
        vector<double> ret;
        for (int i = 0; i < (int)queries.size(); i++) {
            int u = lower_bound(H.begin(), H.end(), queries[i][0]) - H.begin();
            int v = lower_bound(H.begin(), H.end(), queries[i][1]) - H.begin();
            if (u == H.size() || v == H.size() || H[u] != queries[i][0] || H[v] != queries[i][1]) {
                ret.push_back(-1.0);
            } else {
                int f1=seek(u);
                int f2=seek(v);
                if(f1!=f2)ret.push_back(-1.0);
                else
                ret.push_back(rank[u]/rank[v]);
            }
        }
        return ret;
    }
};