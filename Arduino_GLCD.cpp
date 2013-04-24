#include "Arduino_GLCD.h"

#if (USB_VID == 0x2341) && (USB_PID == 0x803C) // are we building for Esplora?
Arduino_GLCD EsploraLCD(7, 0, 1);
#endif

Arduino_GLCD::Arduino_GLCD(uint8_t CS, uint8_t RS, uint8_t RST) 
  : Adafruit_ST7735(CS, RS, RST)
{
  // as we already know the orientation (landscape, therefore rotated),
  // set default width and height without need to call begin() first.
  _width = ST7735_TFTHEIGHT;
  _height = ST7735_TFTWIDTH;
}

void Arduino_GLCD::begin() {
  initR(INITR_REDTAB);
  setRotation(1);
}
