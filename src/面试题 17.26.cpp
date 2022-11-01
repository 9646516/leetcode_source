// id:375218075
// runtime:408 ms
// memory:98.1 MB
// title:Sparse Similarity LCCI
// translatedTitle:稀疏相似度
// questionId:1000051
// time:2022-10-21 17:48:48

int cnt[500][500];
char sb[123];
class Solution {
public:
    vector<string> computeSimilarities(vector<vector<int>>& docs) {
        const int N=docs.size();
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)cnt[i][j]=0;
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<N;i++){
            for(int j:docs[i]){
                mp[j].push_back(i);
            }
        }
        for(auto [a,b]:mp){
            for(int i=0;i<b.size();i++){
                for(int j=i+1;j<b.size();j++){
                    cnt[b[i]][b[j]]++;
                }
            }
        }
        vector<string>ret;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(cnt[i][j]){
                    int join=docs[i].size()+docs[j].size()-cnt[i][j];
                    double iou=1.0*cnt[i][j]/join;
                    sprintf(sb,"%d,%d: %.4f",i,j,iou+1e-9);
                    ret.push_back(sb);
                }
            }
        }
        return ret;
    }
};