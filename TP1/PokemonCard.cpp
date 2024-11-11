#include "PokemonCard.h"
#include <iostream>

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family, int level, int maxHp,
                         int energyCost1, const std::string& desc1, int damage1, int energyCost2, const std::string& desc2, int damage2)
    : Card(name), pokemonType(type), familyName(family), evolutionLevel(level), maxHP(maxHp), hp(maxHp) {
    attacks.emplace_back(energyCost1, 0, desc1, damage1);
    attacks.emplace_back(energyCost2, 0, desc2, damage2);
}

void PokemonCard::attachEnergy(int attackIndex){
    std::get<1>(attacks[attackIndex])+=1;
}
void PokemonCard::attack(PokemonCard& opponent, int attackIndex) {
    int damage = std::get<3>(attacks[attackIndex]);
    opponent.hp -= damage;
    if (opponent.hp < 0) opponent.hp = 0;
}

void PokemonCard::heal(){ hp = maxHP;}

void PokemonCard::displayPokemonCard() const {
    displayInfo();
    std::cout << "Type: " << pokemonType << ", HP: " << hp << "/" << maxHP << std::endl;
    for (const auto& attack : attacks) {
        std::cout << "Attack: " << std::get<2>(attack) << ", Damage: " << std::get<3>(attack)
                  << ", Energy Cost: " << std::get<0>(attack) << std::endl;
    }
}
