#include <M5Cardputer.h>
#include <SPI.h>
#include <SD.h>

#define SCK 40
#define MISO 39
#define MOSI 14
#define CS 12

void setup(void) {
    M5Cardputer.begin(M5.config());
    M5Cardputer.Display.setTextColor(GREEN);
    M5Cardputer.Display.setTextSize(1);
    M5Cardputer.Display.setTextDatum(middle_center);


    // SD Card Initialization
    SPI.begin(SCK, MISO, MOSI, CS);

    if (!SD.begin(CS, SPI, 25000000)) {
        // Print a message if the SD card initialization
        // fails orif the SD card does not exist.
        // 如果SD卡初始化失败或者SD卡不存在，则打印消息.
        // println_log("Card failed, or not present");
        M5Cardputer.Display.drawString("Card failed, or not present", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);

        while (1) {

        }
    } else {
        M5Cardputer.Display.drawString("leu certinho", M5Cardputer.Display.width() / 2, M5Cardputer.Display.height() / 2);
    }
}

void loop(void) {

}