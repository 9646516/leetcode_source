// id:374897569
// runtime:120 ms
// memory:92.6 MB
// title:Find Longest Subarray LCCI
// translatedTitle: 字母与数字
// questionId:1000033
// time:2022-10-20 18:18:27


int P[100005];
class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        const int N=array.size();
        for(int i=0;i<N;i++){
            if(isdigit(array[i][0]))P[i]=1;
            else P[i]=-1;
        }
        for(int i=1;i<N;i++)P[i]+=P[i-1];
        unordered_map<int,int>mp;
        mp[0]=-1;
        int len=-1,pos=-1;
        for(int i=0;i<N;i++){
            if(mp.count(P[i])){
                int len2=i-mp[P[i]];
                if(len2>len){
                    len=len2;
                    pos=mp[P[i]]+1;
                }
            }else{
                mp[P[i]]=i;
            }
        }
        if(len==-1)return {};
        vector<string>ret;
        for(int i=0;i<len;i++){
            ret.push_back(array[i+pos]);
        }
        return ret;
    }
};