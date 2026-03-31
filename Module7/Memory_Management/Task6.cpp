//
// Created by AbhishekJalkhare on 18-03-2026.
//
#include <future>
#include <iostream>
#include <memory>
#include <string>

class Texture {
private:
    std::string name;

public:
    // Constructor
    Texture(const std::string& name) : name(name) {
        std::cout << "[Texture] Loading: " << this->name << std::endl;
    }

    // Destructor
    ~Texture() {
        std::cout << "[Texture] Unloading: " << this->name << std::endl;
    }

    // Render function
    void render() const {
        std::cout << "[Texture] Rendering with: " << name << std::endl;
    }
};

class Shader {
private:
    std::string name;

public:
    // Constructor
    Shader(const std::string& name) : name(name) {
        std::cout << "[Shader] Compiling: " << this->name << std::endl;
    }

    // Destructor
    ~Shader() {
        std::cout << "[Shader] Deleting: " << this->name << std::endl;
    }

    // Apply function
    void apply() const {
        std::cout << "[Shader] Applying: " << name << std::endl;
    }
};

class GameObject {
    std::unique_ptr<Texture> texture_;
    std::shared_ptr<Shader> shader_;
public:
    GameObject(const std::string& name , std::shared_ptr<Shader> shader)  :
    texture_(std::make_unique<Texture>(name)), shader_(std::move(shader)) {
        std::cout <<"[GameObject] Created."<<std::endl;
    }

    ~GameObject() {
        std::cout <<"[GameObject] Destroyed."<<std::endl;
    }

    void draw () const {
        texture_->render();
        shader_->apply();
    }

    void changeTexture(const std::string& newTextureName) {
        texture_ = std::make_unique<Texture>(newTextureName);
    }

};

int main(int argc, char* argv[]) {
    auto defaultLightingShader = std::make_shared<Shader>("BasicLightingShader");
    auto postFxShader = std::make_shared<Shader>("GrayscaleFilterShader");
    GameObject player("PlayerTexture", defaultLightingShader);
    GameObject enemy("EnemyTexture", defaultLightingShader); // Shares the same defaultLightingShader as player GameObject background("BackgroundTexture", postFxShader); // Uses a different shared shader
    GameObject background("BackgroundTexture", postFxShader); // Uses a different shared shader
    std::cout << "\n--- Drawing GameObjects ---" << std::endl;
    player.draw();
    enemy.draw();
    background.draw();

    player.changeTexture("PlayerDamagedTexture");
    std::cout << "\n--- Demonstrate Scope-based Cleanup ---" << std::endl;
    {
        std::cout << "Entering a local scope..." << std::endl;
        GameObject temporaryProp("TempPropTexture", defaultLightingShader); // Creates a GameObject`
        temporaryProp.draw();
        std::cout << "Exiting local scope..." << std::endl;
    }

    // when player goes out of scope -> its texture unique ptr is also destroyed
    // similarly for object their texture is destroyed when they go out of scope
    // shaders will be destroyed when the go out of scope since declared first will be destroyed last

}


