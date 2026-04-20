    //
    // Created by AbhishekJalkhare on 01-04-2026.
    //
    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    bool isReady = false;
    mutex mt;
    condition_variable cv;

    void producer() {
        lock_guard<mutex> lg(mt);
        cout<<"Data Produced"<<endl;
        isReady = true;
        cv.notify_one();
    }

    void consumer(){
        unique_lock<mutex> ul(mt);
        cv.wait(ul  , []( ) {
            return isReady;
        });
        cout<<"consumed"<<endl;
        isReady = false;
        ul.unlock();
        cv.notify_one();

    }


    int main(int argc, char* argv[]) {
        thread t1(consumer);
        thread t2(producer);

        t1.join();
        t2.join();

    }
