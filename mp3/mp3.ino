#include "header.h"

Audio audio;

void setup(void) {
    cardputerStart();
    sdStart();

    audio.setPinout(DAT, BK, 2);
    audio.setVolume(10);
    audio.connecttoFS(SD, "/mp3/musica.mp3");
}

void loop(void) {
    audio.loop();
}