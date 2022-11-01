// id:374627877
// runtime:8 ms
// memory:8.8 MB
// title:Sorted Merge LCCI
// translatedTitle:合并排序的数组
// questionId:1000012
// time:2022-10-19 21:23:53

class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int>V;
        int p1=0,p2=0;
        while(p1<m&&p2<n){
            if(A[p1]<B[p2]){
                V.push_back(A[p1++]);
            }else{
                V.push_back(B[p2++]);
            }
        }
        while(p1<m){
            V.push_back(A[p1++]);
        }
        while(p2<n){
            V.push_back(B[p2++]);
        }
        A=move(V);
    }
};