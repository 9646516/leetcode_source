// id:374295028
// runtime:184 ms
// memory:38.5 MB
// title:最长连续序列
// translatedTitle:最长连续序列
// questionId:1000320
// time:2022-10-18 21:15:45

class Solution {
public:
    unordered_set<int>vis;
    unordered_map<int,int>fa;
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    void merge(int x,int y){
        int f1=seek(x);
        int f2=seek(y);
        fa[f1]=f2;
    }
    int longestConsecutive(vector<int>& nums) {
        for(int i:nums){
            fa[i]=i;
            vis.insert(i);
        }
        for(int i:vis){
            if(vis.count(i-1)){
                merge(i-1,i);
            }
            if(vis.count(i+1)){
                merge(i+1,i);
            }
        }
        unordered_map<int,int>cnt;
        for(int i:vis)cnt[seek(i)]++;
        int ans=0;
        for(auto[a,b]:cnt)ans=max(ans,b);
        return ans;
    }
};