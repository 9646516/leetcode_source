// id:373802407
// runtime:124 ms
// memory:89.1 MB
// title:0 和 1 个数相同的子数组
// translatedTitle:0 和 1 个数相同的子数组
// questionId:1000247
// time:2022-10-17 14:24:38

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int xs=0;
        vector<int>V;
        for(int i:nums){
            if(i)xs++;
            else xs--;
            V.push_back(xs);
        }
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=0;
        for(int i=0;i<V.size();i++){
            if(mp.count(V[i])){
                ans=max(ans,i-mp[V[i]]);
            }else{
                mp[V[i]]=i;
            }
        }
        return ans;
    }
};