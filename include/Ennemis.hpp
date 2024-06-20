#pragma once

#include <img/img.hpp>

// Type d'ennemi
enum class typeEnnemi
{
    elisabeth,
    colin,
    milan,
};

struct Ennemi 
{
    // Détermine si l'ennemi est dans la zone de dégâts
    // void SiDansZoneDegats() {
        
    // }
    typeEnnemi _typeEnnemi{};

    float PdVEnnemi{};
    float VitesseEnnemi{};
    float DegatsEnnemi{};
    int posX{};
    int posY{};

    bool SiEnnemiBouge{};
    bool SiEnnemiMort{};

    Ennemi(int posX, int posY, typeEnnemi type){
        this->posX = posX;
        this->posY = posY;
        this->_typeEnnemi = type;
    }

};