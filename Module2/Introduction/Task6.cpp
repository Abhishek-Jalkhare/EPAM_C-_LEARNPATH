    //
    // Created by AbhishekJalkhare on 27-01-2026.
    //

    #include <iostream>
    using namespace std;

    class Counter {
    inline static int count = 0;
    public:
    Counter () {
        count++;
    }

    static void getCount()  {
        cout<<count<<endl;
    }

    ~Counter() {
        count--;
    }
    };


    // int Counter::count = 0; if we don't use inline we have to define the variable once in filescope

    int main(int argc, char *argv[]) {
    {
        Counter c1 ;
        Counter c2;
        Counter::getCount();
    }
    Counter c3;
    Counter::getCount();


    }
