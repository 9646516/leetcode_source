// id:373666920
// runtime:40 ms
// memory:15.7 MB
// title:单词长度的最大乘积
// translatedTitle:单词长度的最大乘积
// questionId:1000236
// time:2022-10-16 23:33:32

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<pair<int,int>>V;
        for(auto&i:words){
            int mask=0;
            for(int j:i){
                mask|=1<<(j-'a');
            }
            V.push_back({mask,i.size()});
        }
        int ans=0;
        for(int i=0;i<V.size();i++)
            for(int j=i+1;j<V.size();j++){
                if((V[i].first&V[j].first)==0){
                    ans=max(ans,V[i].second*V[j].second);
                }
            }
        return ans;
    }
};