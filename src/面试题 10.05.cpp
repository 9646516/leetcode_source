// id:374638332
// runtime:4 ms
// memory:11.2 MB
// title:Sparse Array Search LCCI
// translatedTitle:稀疏数组搜索
// questionId:100242
// time:2022-10-19 21:51:45

class Solution {
public:
    int findString(vector<string>& words, string s) {
        int L=0,R=words.size()-1,ans=-1;
        while(L<=R){
            while(L<=R&&words[L]=="")L++;
            while(L<=R&&words[R]=="")R--;
            if(L>R)break;
            int mid=(L+R)/2;
            while(mid<=R&&words[mid]=="")mid++;
            if(mid>R){
                R=(L+R)/2;
            }else{
                if(words[mid]>=s){
                    ans=mid;
                    R=mid-1;
                }else{
                    L=mid+1;
                }
            }
        }
        if(ans==-1)return -1;
        if(words[ans]!=s)return -1;
        return ans;
    }
};