// id:376114031
// runtime:156 ms
// memory:8.1 MB
// title:Print FooBar Alternately
// translatedTitle:交替打印 FooBar
// questionId:1187
// time:2022-10-24 21:06:00

mutex m;
condition_variable cv;
int turn;
class FooBar {
private:
    int n;
public:
    FooBar(int n) {
        this->n = n;
        turn=0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            while(turn!=0){
                cv.wait(lk); 
            }
        	printFoo();
            turn=1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock lk(m);
            while(turn!=1){
                cv.wait(lk); 
            }
        	printBar();
            turn=0;
            cv.notify_all();
        }
    }
};