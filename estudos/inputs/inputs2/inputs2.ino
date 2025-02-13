/**
 * @file inputText.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief M5Cardputer input text test
 * @version 0.1
 * @date 2023-10-13
 *
 *
 * @Hardwares: M5Cardputer
 * @Platform Version: Arduino M5Stack Board Manager v2.0.7
 * @Dependent Library:
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5Unified: https://github.com/m5stack/M5Unified
 */

//  #include "M5Cardputer.h"
//  #include "M5GFX.h"
 
//  M5Canvas canvas(&M5Cardputer.Display);
//  String data = "> ";
 
//  void setup() {
//      auto cfg = M5.config();
//      M5Cardputer.begin(cfg, true);
//      M5Cardputer.Display.setRotation(1);
//      M5Cardputer.Display.setTextSize(0.5);
//      M5Cardputer.Display.drawRect(0, 0, M5Cardputer.Display.width(),
//                                   M5Cardputer.Display.height() - 28, GREEN);
//      M5Cardputer.Display.setTextFont(&fonts::FreeSerifBoldItalic18pt7b);
 
//      M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 4,
//                                   M5Cardputer.Display.width(), 4, GREEN);
 
//      canvas.setTextFont(&fonts::FreeSerifBoldItalic18pt7b);
//      canvas.setTextSize(0.5);
//      canvas.createSprite(M5Cardputer.Display.width() - 8,
//                          M5Cardputer.Display.height() - 36);
//      canvas.setTextScroll(true);
//      canvas.println("Press Key and Enter to Input Text");
//      canvas.pushSprite(4, 4);
//      M5Cardputer.Display.drawString(data, 4, M5Cardputer.Display.height() - 24);
//  }
 
//  void loop() {
//      M5Cardputer.update();
//      if (M5Cardputer.Keyboard.isChange()) {
//          if (M5Cardputer.Keyboard.isPressed()) {
//              Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();
 
//              for (auto i : status.word) {
//                  data += i;
//              }
 
//              if (status.del) {
//                  data.remove(data.length() - 1);
//              }
 
//              if (status.enter) {
//                  data.remove(0, 2);
//                  canvas.println(data);
//                  canvas.pushSprite(4, 4);
//                  data = "> ";
//              }
 
//              M5Cardputer.Display.fillRect(0, M5Cardputer.Display.height() - 28,
//                                           M5Cardputer.Display.width(), 25,
//                                           BLACK);
 
//              M5Cardputer.Display.drawString(data, 4,
//                                             M5Cardputer.Display.height() - 24);
//          }
//      }
//  }



// #include <M5Cardputer.h>
// #include <M5GFX.h>

// M5Canvas canvas(&M5Cardputer.Display);
// Keyboard_Class::KeysState status;
// String key;
// unsigned int width = M5Cardputer.Display.width();
// unsigned int height = M5Cardputer.Display.height();

// void setup(void) {
//     auto cfg = M5.config();
//     M5Cardputer.begin(cfg, true);
//     canvas.createSprite(M5Cardputer.Display.width() - 8, M5Cardputer.Display.height() - 36);
//     canvas.setTextScroll(true);
//     M5Cardputer.Display.drawString("key.c_str()", width / 2, height / 2, GREEN);
// }


// void loop(void) {
//     M5Cardputer.Display.fillRect(0, 0, width, height, BLACK);
//     M5Cardputer.update();
    
//     if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
//         status = M5Cardputer.Keyboard.keysState();
    
//         for (auto i : status.word) {
//             key = i;
//         }
//         canvas.println(key);
//         canvas.pushSprite(4, 4);
//     }
// }



#include <M5Cardputer.h>

unsigned int width = M5Cardputer.Display.width();
unsigned int height = M5Cardputer.Display.height();

void setup(void) {
    M5Cardputer.begin();
    M5Cardputer.Display.drawString("key.c_str()", width / 2, height / 2, GREEN);
}

// Keyboard_Class::KeysState status;
// String key;

void loop(void) {
    // M5Cardputer.Display.fillRect(0, 0, width, height, BLACK);
    // M5Cardputer.update();
    
    // if (M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
    //     status = M5Cardputer.Keyboard.keysState();
    
    //     for (auto i : status.word) {
    //         key = i;
    //     }
    //     M5Cardputer.Display.drawString(key.c_str(), width / 2, height / 2);
    // }
    // delay(100);
}