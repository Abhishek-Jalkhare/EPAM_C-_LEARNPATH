    //
    // Created by AbhishekJalkhare on 02-04-2026.
    //

    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;
    mutex mtx;
    class Logger {
    public:
        static Logger& getInstance() {
            static Logger logger_instance;
            return logger_instance;
        }
        void log() const {
            lock_guard<mutex> lock(mtx); // Protect console output
            cout << "[Thread ID: " << this_thread::get_id() << "] "
                 << "Address Of Instance: " << this<<endl;
        }

        Logger( Logger&& obj ) = delete;
        Logger( Logger& obj ) = delete;

    private:
        Logger() {
            cout<<"Logger Created"<<endl;
        }
    };

    void worker() {
        const Logger& lg  = Logger::getInstance();
        lg.log();
    }

    int main(int argc, char* argv[]) {
        vector<thread> threads;
        for (int i = 1; i <= 5; ++i) {
            threads.emplace_back(worker);
        }

        for (auto& t : threads) {
            t.join();
        }

    }
