    //
    // Created by AbhishekJalkhare on 14-05-2026.
    //

    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;


    class button {
    public:
        virtual ~button() = default;
        virtual void paint() = 0;
    };

    class win_button : public button{
    public:
        void paint() override {
            cout<<"Painting Win Button"<<endl;
        }
    };

    class mac_button : public button{
    public:
        void paint() override {
            cout<<"Painting Mac Button"<<endl;
        }
    };



    class checkbox {
    public:
        virtual  ~checkbox() = default;
        virtual void paint() = 0;
    };

    class win_checkbox : public checkbox {
    public:
        void paint() override {
            cout<<"Painting win CheckBox"<<endl;
        }
    };

    class mac_checkbox : public checkbox {
    public:
        void paint() override {
            cout<<"Painting mac CheckBox"<<endl;
        }
    };


    //Abstract Factory
    class ui_factory {
    public:
        virtual ~ui_factory() = default;
        virtual unique_ptr<checkbox> createCheckbox() = 0; // factory method 1
        virtual unique_ptr<button> createButton() = 0; // factory method 2
    };

    class win_factory : public ui_factory {
    public:
        unique_ptr<checkbox> createCheckbox() override {
            return make_unique<win_checkbox>();
        }

        unique_ptr<button> createButton() override {
            return make_unique<win_button>();
        }
    };

    class mac_factory : public  ui_factory {
    public:
        unique_ptr<checkbox> createCheckbox() override {
            return make_unique<mac_checkbox>();
        }
        unique_ptr<button> createButton() override {
            return make_unique<mac_button>();
        }
    };

    void renderUI(unique_ptr<ui_factory> up) {
        cout<<"rendering UI"<<endl;
        up->createCheckbox()->paint();
        up->createButton()->paint();
    }


    int main(int argc, char *argv[]) {

        renderUI( make_unique<mac_factory>());

        renderUI( make_unique<win_factory>());
    }
