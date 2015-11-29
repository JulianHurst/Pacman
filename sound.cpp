#include "sound.h"

Sound::Sound()
{
    intro = new QSound(":/Sounds/res/sound/pacman_beginning.wav");
    chomp = new QSound(":/Sounds/res/sound/chomp.wav");
    fruit = new QSound(":/Sounds/res/sound/pacman_eatfruit.wav");
    dying = new QSound(":/Sounds/res/sound/pacman_death.wav");
    chomploop=0;
}

QSound * Sound::getintro(){
    return intro;
}

QSound * Sound::getdying(){
    return dying;
}

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
