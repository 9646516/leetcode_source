// id:374907074
// runtime:328 ms
// memory:90.9 MB
// title:Baby Names LCCI
// translatedTitle:婴儿名字
// questionId:1000035
// time:2022-10-20 19:03:15

int fa[100000+5];
class Solution {
public:
    int seek(int x){
        return fa[x]==x?x:fa[x]=seek(fa[x]);
    }
    void merge(int x,int y){
        int f1=seek(x);
        int f2=seek(y);
        fa[f1]=f2;
    }
    vector<string> trulyMostPopular(vector<string>& names, vector<string>& synonyms) {
        vector<string>H;
        vector<pair<string,int>>V;
        for(auto&i:names){
            int j=i.size()-1;
            for(;j>=0;j--){
                if(i[j]=='(')break;
            }
            string name=i.substr(0,j);
            int cnt=0;
            for(int k=j;k<i.size();k++){
                if(isdigit(i[k]))cnt=cnt*10+i[k]-'0';
            }
            H.push_back(name);
            V.push_back({name,cnt});
        }
        sort(H.begin(),H.end());
        H.resize(unique(H.begin(),H.end())-H.begin());
        for(int i=0;i<=H.size();i++)fa[i]=i;
        for(auto&i:synonyms){
            int j=0;
            for(;j<i.size();j++){
                if(i[j]==',')break;
            }
            string a=i.substr(1,j-1-1+1);
            string b=i.substr(j+1,i.size()-2-(j+1)+1);
            int u=lower_bound(H.begin(),H.end(),a)-H.begin();
            int v=lower_bound(H.begin(),H.end(),b)-H.begin();
            merge(u,v);
        }
        unordered_map<int,pair<int,string>>mp;
        for(auto&[a,b]:V){
            int u=lower_bound(H.begin(),H.end(),a)-H.begin();
            int f=seek(u);
            auto &pos=mp[f];
            pos.first+=b;
            if(pos.second=="")pos.second=a;
            else pos.second=min(pos.second,a);
        }
        vector<string>ret;
        for(auto[f,s]:mp){
            stringstream ss;
            ss<<s.second<<"("<<s.first<<")";
            ret.push_back(ss.str());
        }
        return ret;
    }   
};