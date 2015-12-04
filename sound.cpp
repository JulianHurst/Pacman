#include "sound.h"

/**
 * @brief Sound::Sound constructeur par défaut, charge tout les sont nécessaire
 */
Sound::Sound()
{
    intro = new QSound(":/Sounds/res/sound/pacman_beginning.wav");
    chomp = new QSound(":/Sounds/res/sound/chomp.wav");
    fruit = new QSound(":/Sounds/res/sound/pacman_eatfruit.wav");
    dying = new QSound(":/Sounds/res/sound/pacman_death.wav");
    chomploop=0;
}

/**
 * @brief Sound::getintro retourne l'intro de début de partie
 * @return intro
 */
QSound * Sound::getintro(){
    return intro;
}

/**
 * @brief Sound::getdying son déclenché en cas de mort du pacman
 * @return dying
 */
QSound * Sound::getdying(){
    return dying;
}

/**
 * @brief Sound::getchomp sont déclenché lors de la consommation d'une croquette
 * @return chomp
 */
QSound * Sound::getchomp(){
    return chomp;
}

int Sound::getchomploop(){
    return chomploop;
}

void Sound::setchomploop(int chomploop){
    this->chomploop=chomploop;
    chomp->setLoops(this->chomploop);
}

QSound * Sound::getfruit(){
    return fruit;
}

void Sound::playintro(){
    intro->play();
}

void Sound::playchomp(){
    chomp->play();
}

void Sound::playfruit(){
    fruit->play();
}

void Sound::playdying(){
    dying->play();
}
