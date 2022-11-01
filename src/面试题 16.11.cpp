// id:374838429
// runtime:16 ms
// memory:19.6 MB
// title:Diving Board LCCI
// translatedTitle:跳水板
// questionId:100352
// time:2022-10-20 15:40:05

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        if(k==0)return {};
        int mn=shorter*k;
        int step=longer-shorter;
        if(step==0)return {mn};
        vector<int>V;
        for(int i=0;i<=k;i++){
            V.push_back(mn+i*step);
        }
        return V;
    }
};