//
// Created by AbhishekJalkhare on 05-02-2026.
//

#include <iostream>
class Playable {
public:
    virtual void play() = 0;
    virtual void pause() = 0;

    virtual ~Playable() = default;
};

class Recordable {
public:
    virtual void record() = 0;
    virtual  void stop() = 0;

};

class MediaPlayer : public  Playable , public  Recordable {
   void stop() override {
       std::cout<<"Media recording stopped..."<<std::endl;
   }
   void record() override {
       std::cout<<"Media recirding started..."<<std::endl;
   }

    void pause() override {
       std::cout<<"media is paused ..."<<std::endl;
   }

    void play() override {
       std::cout<<"media is played..."<<std::endl;
   }
};

int main(int argc, char* argv[]) {
    MediaPlayer mp;
    Playable* pl = (Playable *)&mp;
    Recordable* rl = (Recordable *)&mp;

    pl->pause();
    pl->play();
    rl->record();
    rl->stop();

    // this show that mp has both capability of Playable and Recordable

}
