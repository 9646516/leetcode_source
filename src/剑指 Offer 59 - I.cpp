// id:373649609
// runtime:268 ms
// memory:131.7 MB
// title:滑动窗口的最大值 LCOF
// translatedTitle:滑动窗口的最大值
// questionId:100336
// time:2022-10-16 22:30:47

deque<pair<int,int>>q;
vector<int>ret;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        q.clear();
        ret.clear();
        for(int i=0;i<nums.size();i++){
            while(!q.empty()&&i-q.front().first+1>k)q.pop_front();
            while(!q.empty()&&q.back().second<=nums[i])q.pop_back();
            q.push_back({i,nums[i]});
            if(i>=k-1){
                ret.push_back(q.front().second);
            }
        }
        return ret;
    }
};