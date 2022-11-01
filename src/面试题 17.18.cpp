// id:374936035
// runtime:128 ms
// memory:46.2 MB
// title:Shortest Supersequence LCCI
// translatedTitle:最短超串
// questionId:1000043
// time:2022-10-20 20:31:00

class Solution {
public:
    vector<int> shortestSeq(vector<int>& big, vector<int>& small) {
        unordered_map<int,int>mp;
        for(int i:small)mp[i]++;
        int need=small.size();
        int pos=0;
        vector<int>ret;
        int sz=1e9;
        for(int i=0;i<big.size();i++){
            while(pos<big.size()&&need>0){
                if(mp.count(big[pos])){
                    if(mp[big[pos]]>0){
                        need--;
                    }
                    mp[big[pos]]--;
                }
                pos++;
            }
            if(need==0){
                if(pos-i<sz){
                    sz=pos-i;
                    ret={i,pos-1};
                    // ret={big[i],big[pos-1]};
                }
            }
            if(mp.count(big[i])){
                mp[big[i]]++;
                if(mp[big[i]]>0)need++;
            }
        }
        return ret;
    }
};