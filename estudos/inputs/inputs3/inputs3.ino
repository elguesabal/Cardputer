#include <M5Cardputer.h>

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);
}

std::string line;
std::vector<std::string> lines;

void renderText(void) {
    M5Cardputer.Display.fillRect(0, 0, M5Cardputer.Display.width(), M5Cardputer.Display.height(), BLACK);

    M5Cardputer.Display.drawString(line.c_str(), 0, M5Cardputer.Display.height() - 10);

    unsigned int margin = 50;
    for (unsigned int i = 0; i < lines.size() && i < 4; i++) {
        M5Cardputer.Display.drawString(lines[i].c_str(), 0, M5Cardputer.Display.height() - margin);
        margin += 15;
    }
}

void loop(void) {
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange() || M5Cardputer.Keyboard.isPressed()) {
        if (M5Cardputer.Keyboard.keysState().enter) {
            if (!line.empty()) {
                lines.insert(lines.begin(), line);
                line.clear();
            }
        }

        if (M5Cardputer.Keyboard.keysState().del) {
            line.pop_back();
        }

        for (auto key : M5Cardputer.Keyboard.keysState().word) {
            line += key;
        }

        renderText();
    }
    delay(200);
}