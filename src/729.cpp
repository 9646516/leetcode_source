// id:373964583
// runtime:76 ms
// memory:37.7 MB
// title:My Calendar I
// translatedTitle:我的日程安排表 I
// questionId:729
// time:2022-10-17 21:39:32

class MyCalendar {
public:
    multiset<pair<int,int>>st;
    MyCalendar() {

    }
    bool join(int a,int b,int c,int d){
        if(c>b||d<a)return 0;
        // cout<<a<<' '<<b<<' '<<c<<" "<<d<<endl;
        return 1;
    }
    bool book(int start, int end) {
        end--;
        auto pos=st.upper_bound({start,-1});
        for(int i=0;i<2;i++){
            if(pos==st.begin())break;
            pos--;
        }
        for(int i=0;i<4;i++){
            if(pos==st.end())break;
            if(join(pos->first,pos->second,start,end)){
                return 0;
            }
            pos++;
        }
        st.insert({start,end});
        return 1;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */