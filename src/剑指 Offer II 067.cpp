// id:374006437
// runtime:196 ms
// memory:63.6 MB
// title:最大的异或
// translatedTitle:最大的异或
// questionId:1000331
// time:2022-10-17 23:25:31

struct node{
    node*next[2];
};
class Solution {
public:
    void add(node*now,int val){
        for(int i=31;i>=0;i--){
            int B=(val>>i)&1;
            if(!now->next[B])now->next[B]=new node();
            now=now->next[B];
        }
    }
    int query(node*now,int val) {
        int ans=0;
        for(int i=31;i>=0;i--){
            int B=(val>>i)&1;
            if(now->next[B^1]){
                now=now->next[B^1];
                ans|=1<<i;
            }else{
                now=now->next[B];
            }
        }
        return ans;
    }
    int findMaximumXOR(vector<int>& nums) {
        node*root=new node();
        for(int i:nums)add(root,i);
        int ans=0;
        for(int i:nums)ans=max(ans,query(root,i));
        return ans;
    }
};



