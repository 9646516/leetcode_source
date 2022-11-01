// id:374837032
// runtime:56 ms
// memory:28.6 MB
// title:Living People LCCI
// translatedTitle:生存人数
// questionId:100351
// time:2022-10-20 15:36:51

int P[10000*2+55];
class Solution {
public:
    int maxAliveYear(vector<int>& birth, vector<int>& death) {
        vector<int>H;
        for(int i:birth)H.push_back(i);
        for(int i:death)H.push_back(i);
        sort(H.begin(),H.end());
        H.resize(unique(H.begin(),H.end())-H.begin());
        memset(P,0,sizeof(P));
        for(int i=0;i<birth.size();i++){
            int u=lower_bound(H.begin(),H.end(),birth[i])-H.begin();
            int v=lower_bound(H.begin(),H.end(),death[i])-H.begin();
            P[u]++;
            P[v+1]--;
        }
        int ans=-1,val=-1;
        int now=0;
        for(int i=0;i<H.size();i++){
            now+=P[i];
            if(now>val){
                val=now;
                ans=i;
            }
        }
        return H[ans];
    }
};