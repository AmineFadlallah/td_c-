#include "EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& type) : Card("Energy"), energyType(type) {}

void EnergyCard::displayEnergyCard() const {
    displayInfo(); 
}
