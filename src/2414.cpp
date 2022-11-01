// id:364222227
// runtime:104 ms
// memory:17.6 MB
// title:Length of the Longest Alphabetical Continuous Substring
// translatedTitle:最长的字母序连续子字符串的长度
// questionId:2492
// time:2022-09-18 10:32:52

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans=0;
        deque<char>q;
        for(char i:s){
            while(!q.empty()&&q.back()+1!=i){
                q.pop_front();
            }
            q.push_back(i);
            ans=max(ans,(int)q.size());
        }
        return ans;
    }
};