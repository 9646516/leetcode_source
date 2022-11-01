// id:374856285
// runtime:104 ms
// memory:34.5 MB
// title:Pond Sizes LCCI
// translatedTitle:水域大小
// questionId:1000005
// time:2022-10-20 16:22:17

const int dx[]={1,1,1,0,0,-1,-1,-1};
const int dy[]={-1,0,1,-1,1,-1,0,1};
int fa[1000*1000+5];
int seek(int x){
    return fa[x]==x?x:fa[x]=seek(fa[x]);
}
void merge(int x,int y){
    int f1=seek(x);
    int f2=seek(y);
    fa[f1]=f2;
}
#define IDX(x,y) ((x)*(M)+(y))
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        const int N=land.size();
        const int M=land.front().size();
        for(int i=0;i<N*M;i++)fa[i]=i;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(land[i][j])continue;
                for(int k=0;k<8;k++){
                    int x=i+dx[k];
                    int y=j+dy[k];
                    if(x>=0&&x<N&&y>=0&&y<M){
                        if(land[x][y])continue;
                        merge(IDX(i,j),IDX(x,y));
                    }
                }
            }
        }
        unordered_map<int,int>mp;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(land[i][j])continue;
                mp[seek(IDX(i,j))]++;
            }
        }
        vector<int>ret;
        for(auto &i:mp)ret.push_back(i.second);
        return ret;
    }
};