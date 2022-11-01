// id:374966615
// runtime:4 ms
// memory:13.6 MB
// title:Volume of Histogram LCCI
// translatedTitle:直方图的水量
// questionId:1000029
// time:2022-10-20 21:54:09

class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        stack<tuple<int,int,int>>s;
        for(int i=0;i<height.size();i++){
            int L=i;
            while(!s.empty()){
                auto [h1,l1,r1]=s.top();
                if(h1>height[i])break;
                s.pop();
                L=min(L,l1);
                if(!s.empty()){
                    auto [h2,l2,r2]=s.top();
                    if(height[i]>h2){
                        ans+=(r1-l1+1)*(h2-h1);
                        s.top()={h2,l2,r1};
                    }else{
                        ans+=(r1-l1+1)*(height[i]-h1);
                        L=l1;
                    }
                }
            }
            s.push({height[i],L,i});
        }
        return ans;
    }
};