#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"

class Player {
    private :
        std::string playerName;
        std::vector<Card*> benchCards;  
        std::vector<PokemonCard*> actionCards;
    public :
        Player(const std::string& name) ;
        void addCardToBench(Card* card);
        void activatePokemonCard(int index);
        void attachEnergyCard(int benchIndex, int attackIndex);
        void displayBench() const;
        void displayAction() const;
        void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
        void useTrainer(int index);
        ~Player();



};
   




#endif