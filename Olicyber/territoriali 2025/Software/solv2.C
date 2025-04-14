#include "defs.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cstdint>

uint8 raw_output[40];
uint8_t raw_input[36] = {};

void reverse_magic_black_box(char *original_input)
{
  memcpy(raw_input, raw_output, 0x24uLL);
  
  srand(0x1337u);
  
  int random_values[500];
  for (int i = 0; i <= 499; ++i) 
    random_values[i] = rand();
  
  for (int i = 499; i >= 0; --i) {
    memcpy(raw_output, raw_input, 0x24uLL);
    
    switch (i % 5) {
      case 0:
        {
          char v1 = random_values[i] & 0xFF;
          for (int j = 0; j <= 0x23; ++j)
            raw_input[j] = raw_output[j] ^ v1;
        }
        break;
        
      case 1:
        {
          char v1 = random_values[i] & 0xFF;
          for (int j = 0; j <= 0x23; ++j)
            raw_input[j] = raw_output[j] - v1;
        }
        break;
        
      case 2:
        {
          char v1 = random_values[i] & 0xFF;
          for (int j = 0; j <= 0x23; ++j)
            raw_input[j] = raw_output[j] + v1;
        }
        break;
        
      case 3:
        {
          int v1 = random_values[i] % 0x24uLL;
          for (int j = 0; j <= 0x23; ++j)
            raw_input[j] = raw_output[(j - v1 + 0x24) % 0x24];
        }
        break;
        
      case 4:
        {
          int v1 = random_values[i] % 0x24uLL;
          for (int j = 0; j <= 0x23; ++j)
            raw_input[j] = raw_output[(j + v1) % 0x24];
        }
        break;
    }
  }
  
  memcpy(original_input, raw_input, 0x24uLL);
}

int main() 
{
    memcpy(raw_output, raw_input, 0x24);
    
    uint8_t original_input[36];
    reverse_magic_black_box((char*)original_input);
    
    for (int i = 0; i < 0x24; i++) {
        printf("%02x", original_input[i]);
    }
    
    return 0;
}
