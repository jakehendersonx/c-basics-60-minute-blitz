#include <iostream>
#include <string>

struct Gamecharacter {
    std::string name;
    int health;
    int strength;
}; // structs have the closing semi-colon

void createCharacter() {
    Gamecharacter character;
    character.name = "time wizard";
    character.health = 300;
    character.strength = 100;
    std::cout << "Character created: " << character.name << " (Health: " << character.health << ", Strength: " << character.strength << ")" << std::endl;
}

int main() {
    createCharacter();
    return 0;
}