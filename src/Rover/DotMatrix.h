#ifndef _DOT_MATRIX_H_
#define _DOT_MATRIX_H_

#include <stdint.h>

class DotMatrix {
 public:
  DotMatrix(uint8_t sclPin, uint8_t sdaPin);
  void initialize();
  void display(unsigned char matrix_value[]);

 private:
  uint8_t sclPin;
  uint8_t sdaPin;
  void iicStart();
  void iicSend(unsigned char send_data);
  void iicEnd();
};

#endif
