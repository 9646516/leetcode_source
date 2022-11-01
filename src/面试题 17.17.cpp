// id:374929710
// runtime:48 ms
// memory:28.3 MB
// title:Multi Search LCCI
// translatedTitle:多次搜索
// questionId:1000024
// time:2022-10-20 20:13:42

uint64_t H[1005];
uint64_t POW[1005];

class Solution {
public:
    uint64_t get(int l,int r){
        uint64_t ret=H[r];
        if(l)ret-=H[l-1]*POW[r-l+1];
        return ret;
    }
    vector<vector<int>> multiSearch(string big, vector<string>& smalls) {
        const int N=big.size();
        H[0]=big[0];
        for(int i=1;i<N;i++)H[i]=H[i-1]*233+big[i];
        POW[0]=1;
        for(int i=1;i<=N;i++)POW[i]=POW[i-1]*233;
        vector<vector<int>>ret;
        for(auto&i:smalls){
            vector<int>G;
            uint64_t h=0;
            for(int j:i)h=h*233+j;
            for(int j=0;j+i.size()-1<N;j++){
                if(get(j,j+i.size()-1)==h){
                    G.push_back(j);
                }
            }
            ret.emplace_back(move(G));
        }
        return ret;
    }
};