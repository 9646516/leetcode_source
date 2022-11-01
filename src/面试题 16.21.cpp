// id:374861973
// runtime:44 ms
// memory:31.9 MB
// title:Sum Swap LCCI
// translatedTitle:交换和
// questionId:1000048
// time:2022-10-20 16:35:28

class Solution {
public:
    vector<int> findSwapValues(vector<int>& array1, vector<int>& array2) {
        int s1=accumulate(array1.begin(),array1.end(),0);
        int s2=accumulate(array2.begin(),array2.end(),0);
        int o=s1-s2;
        int need=o/2;
        if(need+need!=o)return {};
        sort(array1.begin(),array1.end());
        sort(array2.begin(),array2.end());
        int pos=0;
        for(int i=0;i<array1.size();i++){
            while(pos<array2.size()&&array2[pos]<array1[i]-need)pos++;
            if(pos<array2.size()&&array1[i]-need==array2[pos]){
                return {array1[i],array2[pos]};
            }
        }
        return {};
    }
};