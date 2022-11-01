// id:374640599
// runtime:8 ms
// memory:13 MB
// title:Peaks and Valleys LCCI
// translatedTitle:峰与谷
// questionId:1000013
// time:2022-10-19 21:58:06

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int>V(nums.size());
        sort(nums.begin(),nums.end());
        int pos=0;
        for(int i=0;i<nums.size();i+=2){
            V[i]=nums[pos++];
        }
        for(int i=1;i<nums.size();i+=2){
            V[i]=nums[pos++];
        }
        nums=move(V);
    }
};