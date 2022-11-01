// id:325872645
// runtime:4 ms
// memory:11.8 MB
// title:Next Permutation
// translatedTitle:下一个排列
// questionId:31
// time:2022-06-16 14:42:31

class Solution {
public:
    void nextPermutation(vector<int>& V) {
        if(V.size()<=1)return;
        const int n=V.size();
        int first=-1;
        for(int i=n-2;i>=0;i--){
            if(V[i]<V[i+1]){
                first=i;
                break;
            }
        }
        if(first==-1){
            reverse(V.begin(),V.end());
        }else{
            for(int i=n-1;i>=0;i--){
                if(V[i]>V[first]){
                    swap(V[i],V[first]);
                    reverse(V.begin()+first+1,V.end());
                    break;
                }
            }
        }
    }
};