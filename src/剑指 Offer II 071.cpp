// id:374150355
// runtime:68 ms
// memory:39.3 MB
// title:按权重生成随机数
// translatedTitle:按权重生成随机数
// questionId:1000335
// time:2022-10-18 14:38:03

class Solution {
public:
    vector<int>V;
    int xs;
    Solution(vector<int>& w) {
        V=w;
        for(int i=1;i<V.size();i++)V[i]+=V[i-1];
        xs=V.back();
    }
    
    int pickIndex() {
        int idx=rand()%xs+1;
        int L=0,R=V.size()-1,ans=V.size()-1;
        while(L<=R){
            int mid=(L+R)/2;
            if(V[mid]>=idx){
                ans=mid;
                R=mid-1;
            }else{
                L=mid+1;
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */