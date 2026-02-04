#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

class SoundManager {
public:
    enum SoundType {
        WELCOME,
        GAME_START,
        MOVE_PLACED,
        WIN,
        ERROR_SOUND,
        DRAW,
        EXIT
    };
    
    static void playSound(SoundType type);
};

#endif