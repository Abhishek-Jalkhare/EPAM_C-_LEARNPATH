#include <iostream>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <thread>

using namespace std;

queue<int> buffer;
mutex mtx;
condition_variable cv;
bool done = false;



void producer() {
    // Dynamically allocated integer (not used in this example, but demonstrates dynamic memory)
    for (int i = 0 ; i < 20 ; i++) {
        {
            // Lock only for the push
            lock_guard<mutex> lg(mtx); 
            buffer.push(i);
        } // Lock is released here
        cv.notify_one(); // Notify consumer that 1 item is ready
    }
    
    // Notify consumer we are completely finished
    {
        lock_guard<mutex> lg(mtx);
        done = true;
    }
    cv.notify_one(); 
}

void consumer() {
    while (true) {
        unique_lock<mutex> ul(mtx);
        // Wait until there is data OR the producer is completely done
        cv.wait(ul, []() { return !buffer.empty() || done; });
        
        while (!buffer.empty()) {
            cout << buffer.front() << endl;
            buffer.pop();
        }
        
        // If buffer is empty and producer is done, exit the thread
        if (done && buffer.empty()) {
            break; 
        }
    } // ul automatically unlocks at the end of the loop scope
}

int main() {
    thread t1(producer);
    thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}