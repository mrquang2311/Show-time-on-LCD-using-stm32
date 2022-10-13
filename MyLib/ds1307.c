#include "ds1307.h"

//
extern I2C_HandleTypeDef hi2c1;

//I2C_HandleTypeDef *hi2c;
#define DS3231_ADDR (0x68<<1)

uint8_t DecimaToBCD(uint8_t Num)
{
		return (Num/10)<<4|(Num%10);
}

uint8_t BCDToDecimal(uint8_t Num)
{
		return (Num>>4)*10+(Num&0x0F);
}

// ds1307 datasheet: https://datasheets.maximintegrated.com/en/ds/DS1307.pdf
void rtc_write_time(uint8_t hour,uint8_t min, uint8_t sec)
{
	uint8_t data_write[] = {DecimaToBCD(sec), DecimaToBCD(min), DecimaToBCD(hour)};
	HAL_I2C_Mem_Write(&hi2c1,DS3231_ADDR,0x00,I2C_MEMADD_SIZE_8BIT,data_write,3,100);
}

void rtc_write_date(uint8_t day,uint8_t month,uint8_t year)
{
	uint8_t data_write[] = {DecimaToBCD(day), DecimaToBCD(month), DecimaToBCD(year)};
	HAL_I2C_Mem_Write(&hi2c1,DS3231_ADDR,0x04,I2C_MEMADD_SIZE_8BIT,data_write,3,100);
}

void rtc_read_time(uint8_t *hour,uint8_t *min, uint8_t *sec)
{
	uint8_t data_read[3];
	HAL_I2C_Mem_Read(&hi2c1,DS3231_ADDR,0x00,I2C_MEMADD_SIZE_8BIT,data_read,3,100);
	*hour = BCDToDecimal(data_read[2]);
	*min = BCDToDecimal(data_read[1]);
	*sec = BCDToDecimal(data_read[0]);
}

void rtc_read_date(uint8_t *day,uint8_t *month, uint8_t *year)
{
	uint8_t data_read[3];
	HAL_I2C_Mem_Read(&hi2c1,DS3231_ADDR,0x04,I2C_MEMADD_SIZE_8BIT,data_read,3,100);
	*year = BCDToDecimal(data_read[2]);
	*month = BCDToDecimal(data_read[1]);
	*day = BCDToDecimal(data_read[0]);
}

//void rtc_init(I2C_HandleTypeDef *hi2c_init)
//{
//	hi2c = hi2c_init;
//}
//down a line for not warning
