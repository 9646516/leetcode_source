// id:374217555
// runtime:448 ms
// memory:14.2 MB
// title:Length of Longest Fibonacci Subsequence
// translatedTitle:最长的斐波那契子序列的长度
// questionId:905
// time:2022-10-18 17:18:35

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        const int N=arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]].push_back(i);
        }
        deque<int>V;
        int ans=0;
        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                int A=arr[i],B=arr[j],len=2;
                int pos=j;
                while(1){
                    bool found=0;
                    int need=A+B;
                    if(mp.count(need)){
                        const auto&v=mp[need];
                        auto nx=upper_bound(v.begin(),v.end(),pos);
                        if(nx!=v.end()){
                            A=B;
                            B=need;
                            len++;
                            pos=*nx;
                            found=1;
                        }
                    }
                    if(!found)break;
                }
                if(len>2)
                    ans=max(ans,len);
            }
        }
        return ans;
    }
};