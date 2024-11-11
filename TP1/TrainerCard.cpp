#include "PokemonCard.h"
#include "TrainerCard.h"
#include <iostream>

TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect)
    : Card(trainerName), trainerEffect(effect) {}

void TrainerCard::applyEffect(std::vector<PokemonCard*>& activePokemon) const {
    if (trainerEffect == "heal all your action pokemon") {
        for (auto& pokemon : activePokemon) {
            pokemon->heal();
        }
    }
}