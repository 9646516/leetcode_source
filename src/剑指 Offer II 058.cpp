// id:373964139
// runtime:92 ms
// memory:37.8 MB
// title:日程表
// translatedTitle:日程表
// questionId:1000322
// time:2022-10-17 21:38:32

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