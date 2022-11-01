// id:376068499
// runtime:104 ms
// memory:10.8 MB
// title:The Dining Philosophers
// translatedTitle:哲学家进餐
// questionId:1340
// time:2022-10-24 19:01:14

mutex m;
condition_variable cv;
int state[5];

class DiningPhilosophers {
public:

    DiningPhilosophers() {
        for (int i = 0; i < 5; i++)state[i] = 0;
    }

    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int a = philosopher, b = (philosopher + 1) % 5;
        {
            std::unique_lock<std::mutex> l1(m);
            while (state[a]||state[b]) {
                cv.wait(l1);
            }
            state[a] = 1;
            state[b] = 1;
            pickLeftFork();
            pickRightFork();
            eat();
            putLeftFork();
            putRightFork();
            state[a] = 0;
            state[b] = 0;
        }
        cv.notify_one();

    }
};