//
// Created by AbhishekJalkhare on 14-05-2026.
//

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class pc {
public:
     string cpu;
     string ram;
     string gpu;
     string storage;
     bool sound_card;
     bool liquid_cooling;
public:
     pc() = default;
     void show_specs() const{
          cout<<"cpu : "<<cpu<<endl;
     }
};

class builder{
protected:
     unique_ptr<pc> m_pc;
     builder():m_pc(make_unique<pc>()){}
public:
     virtual ~builder() = default;
     virtual void buildCPU() = 0;
     virtual void buildRAM() = 0;
     virtual void buildGPU() = 0;
     virtual void buildStorage() = 0;
     virtual void buildSoundCard() = 0;
     virtual void buildLiquidCooling() = 0;

     void reset() {
          m_pc = make_unique<pc>();
     }
     unique_ptr<pc> getPC() {
          auto temp = std::move(m_pc);
          reset();
          return temp;
     }

};

class gamingPC_builder : public builder{
public:
     void buildCPU() override {
          m_pc->cpu = "Intel i9";
     }

     void buildRAM() override {
          m_pc->ram = "32GB DDR5";
     }

     void buildGPU() override {
          m_pc->gpu = "RTX 5090";
     }

     void buildStorage() override {
          m_pc->storage = "2TB NVMe SSD";
     }

     void buildSoundCard() override {
          m_pc->sound_card = true;
     }

     void buildLiquidCooling() override {
          m_pc->liquid_cooling = true;
     }

};

class office_PC_builder : public builder {
public:
     void buildCPU() override {
          m_pc->cpu = "Intel i5";
     }

     void buildRAM() override {
          m_pc->ram = "16GB DDR4";
     }

     void buildGPU() override {
          m_pc->gpu = "Integrated Graphics";
     }

     void buildStorage() override {
          m_pc->storage = "512GB SSD";
     }

     void buildSoundCard() override {
          m_pc->sound_card = false;
     }

     void buildLiquidCooling() override {
          m_pc->liquid_cooling = false;
     }
};


class Director {
public:
     static unique_ptr<pc> buildPC(builder& b) {
          b.buildCPU();
          b.buildGPU();
          b.buildLiquidCooling();
          b.buildRAM();
          b.buildSoundCard();
          b.buildStorage();
          return b.getPC();
     }
};


int main(int argc, char *argv[]) {
     unique_ptr<builder> b = make_unique<gamingPC_builder>();
     unique_ptr<pc> pc1 = Director::buildPC(*b);
     unique_ptr<pc> pc2 = Director::buildPC(*b);
     pc1->show_specs();
     pc2->show_specs();

}
