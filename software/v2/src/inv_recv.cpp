#include <stdio.h>
#include "inv_data.hpp"


int update_broadcast_data(unsigned long id, unsigned char dta[8]){
    if (id == 0x0A0){
        inv_data.temp_a = (dta[0] + dta[1] << 8) / 10;
    }
}
