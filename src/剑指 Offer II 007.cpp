// id:373669698
// runtime:88 ms
// memory:19.4 MB
// title:数组中和为 0 的三个数
// translatedTitle:数组中和为 0 的三个数
// questionId:1000239
// time:2022-10-16 23:45:54

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& V) {
        sort(V.begin(),V.end());
        vector<vector<int>>ret;
        for(int i=0;i<V.size();i++){
            if(i&&V[i]==V[i-1])continue;
            int pos=V.size()-1;
            for(int j=i+1;j<V.size();j++){
                if(j!=i+1&&V[j]==V[j-1])continue;
                while(pos>i&&V[i]+V[j]+V[pos]>0){
                    pos--;
                }
                if(j>=pos)break;
                if(pos>i&&V[i]+V[j]+V[pos]==0){
                    ret.push_back({V[j],V[i],V[pos]});
                }
            }
        }
        return ret;
    }   
};