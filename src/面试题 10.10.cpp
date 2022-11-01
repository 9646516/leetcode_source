// id:374639823
// runtime:32 ms
// memory:13.4 MB
// title:Rank from Stream LCCI
// translatedTitle:数字流的秩
// questionId:1000041
// time:2022-10-19 21:55:49

class StreamRank {
public:
    vector<int>V;
    StreamRank() {

    }
    
    void track(int x) {
        auto pos=lower_bound(V.begin(),V.end(),x);
        V.insert(pos,x);
    }
    
    int getRankOfNumber(int x) {
        auto pos=upper_bound(V.begin(),V.end(),x);
        return pos-V.begin();
    }
};

/**
 * Your StreamRank object will be instantiated and called as such:
 * StreamRank* obj = new StreamRank();
 * obj->track(x);
 * int param_2 = obj->getRankOfNumber(x);
 */