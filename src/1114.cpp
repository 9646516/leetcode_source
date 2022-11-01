// id:376113126
// runtime:64 ms
// memory:7 MB
// title:Print in Order
// translatedTitle:按序打印
// questionId:1203
// time:2022-10-24 21:03:42

mutex m;
condition_variable cv;
int turn;
class Foo {
public:
    Foo() {
        turn=0;
    }

    void first(function<void()> printFirst) {
        unique_lock lk(m);
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        turn=2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock lk(m);
        while(turn!=2){
            cv.wait(lk);
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        turn=3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock lk(m);
        while(turn!=3){
            cv.wait(lk);
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};