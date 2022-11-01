// id:374845843
// runtime:68 ms
// memory:40.8 MB
// title:Sub Sort LCCI
// translatedTitle:部分排序
// questionId:100356
// time:2022-10-20 15:57:16

class Solution {
public:
    vector<int> subSort(vector<int>& array) {
        const int N=array.size();
        bool ok=1;
        for(int i=1;i<N;i++){
            if(array[i]<array[i-1]){
                ok=0;
                break;
            }
        }
        if(ok)return {-1,-1};
        vector<int>rmin=array,lmax=array;
        for(int i=1;i<N;i++){
            lmax[i]=max(lmax[i],lmax[i-1]);
        }
        for(int i=N-2;i>=0;i--){
            rmin[i]=min(rmin[i],rmin[i+1]);
        }
        int L=0,R=N-1;
        for(int i=0;i<N;i++){
            if(i&&array[i]<array[i-1])break;
            if(array[i]<=rmin[i+1])L=i+1;
        }
        for(int i=N-1;i>=0;i--){
            if(i!=N-1&&array[i]>array[i+1])break;
            if(array[i]>=lmax[i-1])R=i-1;
        }
        return {L,R};
    }
};