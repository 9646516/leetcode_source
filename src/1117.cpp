// id:376103204
// runtime:68 ms
// memory:8.7 MB
// title:Building H2O
// translatedTitle:H2O 生成
// questionId:1186
// time:2022-10-24 20:39:02

mutex m;
condition_variable cv;
class H2O {
    int H=0,O=0;

public:
    H2O() {}

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock lk(m);
        while(H>=2){
            cv.wait(lk);
        }
        H++;
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        {
            unique_lock lk(m);
            while(H<2){
                cv.wait(lk);
            }
            H-=2;   
            releaseOxygen();
        }
        cv.notify_all();
    }
};