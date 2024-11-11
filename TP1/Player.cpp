#include "Player.h"
#include <iostream>

Player::Player(const std::string& name) : playerName(name) {}

Player::~Player() {
    for (auto card : benchCards) delete card;
    for (auto pokemon : actionCards) delete pokemon;
}
void Player::addCardToBench(Card* card){
    benchCards.push_back(card);
}

void Player ::activatePokemonCard(int index){
    if(index < benchCards.size()){
        PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemon) {
            actionCards.push_back(pokemon);
            benchCards.erase(benchCards.begin() + index);
        }
    }
}
void Player::attachEnergyCard(int benchIndex, int attackIndex) {
    if (benchIndex < actionCards.size()) {
        actionCards[benchIndex]->attachEnergy(attackIndex);
    }
}

void Player::displayBench() const {
    std::cout << playerName << "'s Cartes de banc:" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}
void Player::displayAction()const {
    std::cout <<playerName<<"'s Cartes d'actions:"<<std::endl;
    for (const auto& pokemonCard : actionCards){
        pokemonCard->displayPokemonCard();
    }
}
void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex < actionCards.size() && targetIndex < opponent.actionCards.size()) {
        actionCards[attackerIndex]->attack(*opponent.actionCards[targetIndex], attackIndex);
    }
}

void Player::useTrainer(int index) {
    if (index < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainer) {
            trainer->applyEffect(actionCards);
        }
    }
}


