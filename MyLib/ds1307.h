#ifndef __DS1307_H__
#define __DS1307_H__
#include "main.h"
void rtc_write_time(uint8_t hour,uint8_t min, uint8_t sec);
void rtc_write_date(uint8_t day,uint8_t month,uint8_t year);
void rtc_read_time(uint8_t *hour,uint8_t *min, uint8_t *sec);
void rtc_read_date(uint8_t *day,uint8_t *month, uint8_t *year);
//void rtc_init(I2C_HandleTypeDef *hi2c_init)
#endif //down a line for not warning
