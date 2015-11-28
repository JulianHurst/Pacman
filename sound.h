#ifndef SOUND_H
#define SOUND_H

#include <QSound>

class Sound
{
public:
    Sound();
    QSound * getintro();
    QSound * getdying();
    QSound * getchomp();
    int getchomploop();
    void setchomploop(int chomploop);
    void playintro();
    void playchomp();
    void playdying();

private:
    QSound *intro;
    QSound *chomp;
    QSound *dying;
    int chomploop;

};

#endif // SOUND_H
