// id:374917798
// runtime:96 ms
// memory:58 MB
// title:Find Closest LCCI
// translatedTitle:单词距离
// questionId:1000039
// time:2022-10-20 19:40:58

class Solution {
public:
    int findClosest(vector<string>& words, string word1, string word2) {
        vector<int>v1,v2;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1)v1.push_back(i);
            if(words[i]==word2)v2.push_back(i);
        }
        int ans=1e9;
        int pos=0;//lower_bound
        for(int i=0;i<v1.size();i++){
            while(pos<v2.size()&&v2[pos]<v1[i])pos++;
            for(int j=-1;j<=0;j++){
                int idx=pos+j;
                if(idx<v2.size()){
                    ans=min(ans,abs(v1[i]-v2[idx]));
                }
            }
        }
        return ans;
    }
};