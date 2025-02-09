#include <M5Unified.h>
#include <string>

void setup(void) {
    M5.begin();

    std::string teste;
    teste = "aaaaaaaaaaaaaaa";
    teste += "bbbbbbbbbbbbbbb";
    M5.Display.println(teste.c_str());
}

void loop(void) {
    static unsigned int i = 0;
    if (i < 5) {
        char n = 48 + i;
        M5.Display.println(n);
        i++;
        delay(1000);
    }
}
