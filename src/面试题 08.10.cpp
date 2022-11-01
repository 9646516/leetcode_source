// id:374598182
// runtime:12 ms
// memory:13.3 MB
// title:Color Fill LCCI
// translatedTitle:颜色填充
// questionId:100201
// time:2022-10-19 20:05:45

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int need=image[sr][sc];
        if(need==newColor){
            return image;
        }
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=newColor;
        const int dx[]={1,-1,0,0};
        const int dy[]={0,0,1,-1};
        const int N=image.size();
        const int M=image.front().size();
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int x2=x+dx[i];
                int y2=y+dy[i];
                if(x2>=0&&y2>=0&&x2<N&&y2<M&&image[x2][y2]==need){
                    image[x2][y2]=newColor;
                    q.push({x2,y2});
                }
            }
        }
        return image;
    }
};