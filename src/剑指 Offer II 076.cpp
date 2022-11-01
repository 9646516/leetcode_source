// id:374164378
// runtime:152 ms
// memory:9.9 MB
// title:数组中的第 k 大的数字
// translatedTitle:数组中的第 k 大的数字
// questionId:1000340
// time:2022-10-18 15:12:08

class Solution {
public:
    vector<int>V;
    int solve(int l,int r,int k){
        int pos=l;
        for(int i=l;i<r;i++){
            if(V[i]<V[r]){
                swap(V[pos],V[i]);
                pos++;
            }
        }
        swap(V[pos],V[r]);
        int left=pos-1-l+1;
        if(k<=left)return solve(l,pos-1,k);
        else if(k==left+1)return V[pos];
        else return solve(pos+1,r,k-left-1);
    }
    int findKthLargest(vector<int>& nums, int k) {
        V=nums;
        k=nums.size()+1-k;
        return solve(0,V.size()-1,k);
    }
};