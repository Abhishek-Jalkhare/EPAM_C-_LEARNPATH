//
// Created by AbhishekJalkhare on 15-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//component interface
class inotifier {
public:
    virtual ~inotifier() = default;
    virtual void send(const string& msg) = 0;
};

//plain component
class plain_notifier : public inotifier {
public:
    void send(const string &msg) override {
        cout<<"Printing at console..."<<msg<<endl;
    }
};

class notifier_decorator : public inotifier{
protected:
    unique_ptr<inotifier> notifier;
    notifier_decorator(unique_ptr<inotifier> ptr) : notifier(move(ptr)){}

};

class sms_decorator : public notifier_decorator {
public:
    sms_decorator(unique_ptr<inotifier> ptr):notifier_decorator(move(ptr)){}
    void send(const string &msg) override {
        notifier->send(msg);
        cout<<"Sending sms ..."<<msg<<endl;
    }
};

class email_decorator : public notifier_decorator {
public:
    email_decorator(unique_ptr<inotifier> ptr):notifier_decorator(move(ptr)){}
    void send(const string &msg) override {
        notifier->send(msg);
        cout<<"Sending email ..."<<msg<<endl;
    }
};

class slack_decorator : public notifier_decorator {
public:
    slack_decorator(unique_ptr<inotifier> ptr):notifier_decorator(move(ptr)){}
    void send(const string &msg) override {
        notifier->send(msg);
        cout<<"Posting to slack ..."<<msg<<endl;
    }
};

int main(int argc, char *argv[]) {
    unique_ptr<inotifier> notifier =  make_unique<sms_decorator>
    (make_unique<email_decorator>
        (make_unique<slack_decorator>(
            make_unique<plain_notifier>()
        )));

    notifier->send("Alertttt!!!");
}
