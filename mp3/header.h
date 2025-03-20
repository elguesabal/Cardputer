#ifndef HEADER_H
# define HEADER_H

#include <M5Cardputer.h>
#include <SPI.h>
#include <SD.h>
#include <Audio.h>

#define SCK 40                                      // SCK:G40
#define MISO 39                                     // MISO:G39
#define MOSI 14                                     // MOSI:G14
#define CS 12                                       // CS:G12

#define BK 41                                       // BK:G41
#define DAT 42                                      // DAT:G42

// ./M5Cardputer.cpp
void cardputerStart(void);
void vampeta(void);

// ./sdCard.cpp
void sdStart(void);

#endif