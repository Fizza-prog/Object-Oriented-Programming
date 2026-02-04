#include "soundmanager.h"
#include <windows.h>

void SoundManager::playSound(SoundType type) {
    switch (type) {
        case WELCOME:
            Beep(523, 200); 
            Beep(659, 200); 
            Beep(784, 300); 
            break;
            
        case GAME_START:
            Beep(784, 150); 
            Beep(880, 150); 
            Beep(988, 300); 
            break;
            
        case MOVE_PLACED:
            Beep(659, 100); 
            Beep(784, 100); 
            break;
            
        case WIN:
            Beep(988, 200); 
            Beep(880, 150); 
            Beep(988, 150); 
            Beep(1047, 300); 
            break;
            
        case ERROR_SOUND:
            Beep(200, 300);
            Beep(150, 300);
            break;
            
        case DRAW:
            Beep(392, 300); 
            Beep(349, 300); 
            Beep(330, 500); 
            break;
            
        case EXIT:
            Beep(784, 200); 
            Beep(659, 200); 
            Beep(523, 400); 
            break;
    }
}