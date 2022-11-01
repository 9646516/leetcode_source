// id:374947790
// runtime:36 ms
// memory:22.6 MB
// title:Missing Two LCCI
// translatedTitle:消失的两个数字
// questionId:1000044
// time:2022-10-20 21:02:31

class Solution {
public:
    int solve(vector<int>&V,int l,int r){
        int sz=(r-l+1);
        if(sz==1){
            if(V[l]!=l){
                return l;
            }
            return -1;
        }

        if(sz==2){
            if(V[l]>V[r])swap(V[l],V[r]);
            for(int i=l;i<=r;i++){
                if(V[i]!=i){
                    return i;
                }
            }
            return -1;
        }
        int cmp=rand()%sz;
        swap(V[l+cmp],V[r]);
        int pos=l;
        for(int i=l;i<r;i++){
            if(V[i]<V[r]){
                swap(V[pos],V[i]);
                pos++;
            }
        }
        swap(V[r],V[pos]);
        if(V[pos]==pos){
            return solve(V,pos+1,r);
        }else{
            return solve(V,l,pos);
        }
    }
    vector<int> missingTwo(vector<int>& nums) {
        const int N=nums.size();//1..N+2
        int xs=0;
        for(int i=1;i<=N+2;i++)xs^=i;
        for(int i:nums)xs^=i;
        nums.insert(nums.begin(),0);
        int fst=solve(nums,1,N);
        if(fst==-1)fst=N+1;
        int snd=xs^fst;
        return {fst,snd};
    }   
};