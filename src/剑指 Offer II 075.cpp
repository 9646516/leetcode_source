// id:374160331
// runtime:4 ms
// memory:7.4 MB
// title:数组相对排序
// translatedTitle:数组相对排序
// questionId:1000339
// time:2022-10-18 15:05:00

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int ord[1005];
        memset(ord,-1,sizeof(ord));
        for(int i=0;i<arr2.size();i++)ord[arr2[i]]=i;
        vector<int>V,V2;
        for(int i:arr1)if(ord[i]!=-1)V.push_back(i);else V2.push_back(i);
        sort(V.begin(),V.end(),[&](int a,int b){return ord[a]<ord[b];});
        sort(V2.begin(),V2.end());
        for(int i:V2)V.push_back(i);
        return V;
    }
};