//
// Created by AbhishekJalkhare on 02-02-2026.
//

#include <iostream>
#include <vector>
using namespace std;

class Character {
    int health ;
    int mana;

public:
    [[nodiscard]] int getHealth() const {
        return health;
    }

    [[nodiscard]] int getMana() const {
        return mana;
    }

    void setHealth(const int health) {
        if (health < 0 || health > 100) {
            cout<<"Enter a valid health value between 0 to 100"<<endl;
        }
        this->health = health;
    }

    void setMana(const int mana) {
        if (mana < 0 || mana > 100) {
            cout<<"Enter a valid mana value between 0 to 100"<<endl;
        }
        this->mana = mana;
    }

    Character(const int health, const int mana)
        : health(health),
          mana(mana) {
        setHealth(health);
        setMana(mana);
    }

    virtual void attack() = 0;
    virtual ~Character() = default;
};

class Warrior : public Character {
public:
    void attack() override {
        if (getHealth() > 0) {
            cout<<"Threee Sword style onigirrrri"<<endl;
            setHealth(getHealth()-2);
        }
        else {
            cout<<"Not enough health"<<endl;
        }
    }

    Warrior(const int health, const int mana)
        : Character(health, mana) {
    }
};

class Mage : public Character {
public:
    Mage(const int health, const int mana)
        : Character(health, mana) {
    }

    void attack() override {
        if (getMana() > 0) {
            cout<<"Ice ageeee magic spell"<<endl;
            setMana(getMana()- 10) ;
        }
        else {
            cout<<"not enough mana"<<endl;
        }
    }
};

int main(int argc, char* argv[]) {
    vector<Character *> li = {new Warrior(40 , 0) , new Mage(20 , 80)};
    for (Character * c : li) {
        c->attack();
    }
}
