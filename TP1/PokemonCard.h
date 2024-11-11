#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include "Card.h"
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

class PokemonCard :public Card{
    protected:
        std::string pokemonType;
        std::string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        std::vector<std::tuple<int, int, std::string, int>>attacks;
    public :
        PokemonCard(const std::string& name, const std::string& type, const std::string& family, int level, int maxHp,
                    int energyCost1, const std::string& desc1, int damage1, int energyCost2, const std::string& desc2, int damage2);
        
        

        void attachEnergy(int attackIndex);
        void attack(PokemonCard& opponent, int attackIndex);
        void heal();
        void displayPokemonCard() const;


};

#endif