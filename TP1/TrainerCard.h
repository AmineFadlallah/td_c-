#ifndef TRAINERCARD_H
#define TRAINERCARD_H
#include "Card.h"
#include <string>
#include <vector>
class  TrainerCard : public Card{
    private : 
        std::string trainerEffect;
    public : 
        TrainerCard(const std::string& trainerName, const std::string& effect);
        void applyEffect(std::vector<PokemonCard*>& activePokemon ) const;


};

#endif