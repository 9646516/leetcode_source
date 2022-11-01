// id:374869526
// runtime:56 ms
// memory:38.9 MB
// title:Langtons Ant LCCI
// translatedTitle:兰顿蚂蚁
// questionId:1000050
// time:2022-10-20 16:52:53

const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const char ord[]={'R','D','L','U'};
class Solution {
public:
    vector<string> printKMoves(int K) {
        int dir=0;
        int x=0,y=0;
        map<pair<int,int>,int>mp;
        int xmax=0,ymax=0;
        int xmin=0,ymin=0;
        for(int i=0;i<K;i++){
            if(mp[{x,y}]){
                dir--;
                if(dir<0)dir+=4;
            }else{
                dir++;
                if(dir>=4)dir-=4;
            }
            mp[{x,y}]^=1;
            int x2=x+dx[dir];
            int y2=y+dy[dir];
            x=x2;y=y2;
            xmax=max(xmax,x);
            ymax=max(ymax,y);
            xmin=min(xmin,x);
            ymin=min(ymin,y);
        }
        vector<string>ret(xmax-xmin+1,string(ymax-ymin+1,'_'));
        for(auto [a,b]:mp){
            if(b)ret[a.first-xmin][a.second-ymin]='X';
            else ret[a.first-xmin][a.second-ymin]='_';
        }
        ret[x-xmin][y-ymin]=ord[dir];
        return ret;
    }
};