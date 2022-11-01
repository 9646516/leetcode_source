// id:65879179
// runtime:296 ms
// memory:32.6 MB
// title:寻宝
// translatedTitle:寻宝
// questionId:1000093
// time:2020-04-25 19:27:34

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

#define POW2(X) (1<<(X))
#define CKBIT(S,X) (((S)&POW2(X))!=0)
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void ckmin(T &a,T b){ a=min(a,b); }
template<class T> inline void ckmax(T &a,T b){ a=max(a,b); }
template<class T> inline T sqr(T x){ return x*x; }
#define SIZE(A) ((int)A.size())
#define LENGTH(A) ((int)A.length())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,a) for(int i=0;i<(a);++i)
#define ALL(A) A.begin(),A.end()
template<class T> int CMP(T a[],const T b[],int n) { return memcmp(a,b,n*sizeof(T)); }
template<class T> void COPY(T a[],const T b[],int n) { memcpy(a,b,n*sizeof(T)); }
template<class T> void SET(T a[],int val,int n) { memset(a,val,n*sizeof(T)); }
using uint=unsigned int;
using int64=long long;
using uint64=unsigned long long;
using ipair=pair<int,int>;
using VI=vector<int>;
using VD=vector<double>;
using VVI=vector<VI>;

struct Point
{
	int x,y;
	Point(int x=0,int y=0) : x(x),y(y) {}
};

const int INF=100000000;

class Solution
{
public:
	VVI bfs(const vector<string>& a,Point src)
	{
		int sx=SIZE(a);
		int sy=SIZE(a[0]);
		VVI d(sx,VI(sy,INF));
		vector<Point> que;
		que.push_back(src);
		d[src.x][src.y]=0;
		REP(cl,SIZE(que))
		{
			int x=que[cl].x;
			int y=que[cl].y;
			for (int dx=-1;dx<=1;dx++) for (int dy=-1;dy<=1;dy++) if (abs(dx)+abs(dy)==1)
			{
				int x2=x+dx;
				int y2=y+dy;
				if (x2<0 || x2>=sx || y2<0 || y2>=sy) continue;
				if (a[x2][y2]=='#') continue;
				if (d[x2][y2]<INF) continue;
				d[x2][y2]=d[x][y]+1;
				que.push_back(Point(x2,y2));
			}
		}
		return d;
	}
    int minimalSteps(vector<string>& maze) 
	{
		int sx=SIZE(maze);
		int sy=SIZE(maze[0]);
		Point src;
		Point dst;
		vector<Point> b;
		vector<Point> a;
		REP(x,sx) REP(y,sy) 
		{
			char c=maze[x][y];
			if (c=='S') src=Point(x,y);
			if (c=='T') dst=Point(x,y);
			if (c=='O') b.push_back(Point(x,y));
			if (c=='M') a.push_back(Point(x,y));
		}
		VVI d_src=bfs(maze,src);
		if (d_src[dst.x][dst.y]>=INF) return -1;
		int n=SIZE(a);
		REP(i,n) if (d_src[a[i].x][a[i].y]>=INF) return -1;
		int m=SIZE(b);
		if (n==0) return d_src[dst.x][dst.y];
		if (m==0) return -1;
		vector<VVI> d_a(n);
		REP(i,n) d_a[i]=bfs(maze,a[i]);
		VVI f(POW2(n),VI(n,INF));
		REP(i,n) REP(k,m) ckmin(f[POW2(i)][i],d_src[b[k].x][b[k].y]+d_a[i][b[k].x][b[k].y]);
		VVI g(n,VI(n,INF));
		REP(i,n) REP(j,n) REP(k,m) ckmin(g[i][j],d_a[i][b[k].x][b[k].y]+d_a[j][b[k].x][b[k].y]);
		REP(set,POW2(n)) REP(i,n) if (f[set][i]<INF)
			REP(j,n) if (!CKBIT(set,j))
				ckmin(f[set|POW2(j)][j],f[set][i]+g[i][j]);
		int ret=INF;
		REP(i,n) ckmin(ret,f[POW2(n)-1][i]+d_a[i][dst.x][dst.y]);
		return (ret>=INF?-1:ret);
	}
};