//
// Created by AbhishekJalkhare on 15-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class observer;
class subject {
public:
    virtual ~subject() = default;
    virtual void attach(weak_ptr<observer> obs) = 0;
    virtual void detach(weak_ptr<observer> obs) = 0;
    virtual void notify() = 0;
    virtual void getState() = 0;
};

class observer {
protected:
    weak_ptr<subject> sub;
    observer(const weak_ptr<subject> &sub) :sub{sub}{}
public:
    virtual ~observer() = default;
    virtual void update() = 0;
};


class weather_station : public subject {
    int temp ;
   // vector<shared_ptr<observer>> observers; // use weak ptr instead of
    // shared ptr so when an object dies in main this vector do not keep them alive
    // so in notify we need to a dead ptr check

    vector<weak_ptr<observer>> observers;
public:
    void attach(weak_ptr<observer> obs) override {
        observers.push_back(obs);
    }
    void detach(weak_ptr<observer> obs) override {
        auto obs_shared = obs.lock();
        if (!obs_shared) return;
        for (auto it = observers.begin() ; it != observers.end();) {
            auto shared = it->lock();
            if (!shared) {
                it = observers.erase(it);
            }
            else {
                if (it->lock() == shared) {
                    it = observers.erase(it);
                }
                else ++it;
            }
        }
    }


    void notify() override {
        for (auto it = observers.begin() ; it != observers.end() ; ) {
             if (it->expired()) {
                it = observers.erase(it);
             }
            else {
                it->lock()->update();
                ++it;
            }
        }
    }

    void getState() override {
        cout<<"New Temprature "<<temp<<endl;
    }

    void updateTemp(int x =0) {
        temp = x;
        notify();
    }

};

class devices : public observer {
public:
    devices(const weak_ptr<subject>& sub): observer(sub) {}
    void update() override {
        (sub.lock() == nullptr ? throw runtime_error("Subject destroyed") : sub.lock()->getState());
    }
};


int main(int argc, char *argv[]) {
    auto sub =  make_shared<weather_station>(); // use auto for type
    // do not use shared<subject> because updateTemp() is only in weather_station
    auto phone = make_shared<devices>(sub);
    auto tablet = make_shared<devices>(sub);

    sub->attach(phone);
    sub->attach(tablet);

    sub->updateTemp(245);

}
