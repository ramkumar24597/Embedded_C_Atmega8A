/*
 * DS1307.h
 *
 * Created: 7/21/2018 4:39:53 PM
 *  Author: Ram
 */ 


#ifndef DS1307_H_
#define DS1307_H_

#define TIME_FORMAR "%02d:%02d:%02d"

typedef enum
{
	Sunday = 1,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday	
} Day;

typedef struct
{
	uint8_t Date[15];
	uint8_t Time[15];
	Day eDay;
	
} DataDateTime;

typedef struct 
{
	uint8_t Secs;
	uint8_t Mins;
	uint8_t Hrs;
	uint8_t Day;
	uint8_t Date;
	uint8_t Months;
	uint8_t Year;
	uint8_t Unknown;
} BcdDateTime;


void DS1307_Write(DataDateTime SetDateTime);

DataDateTime DS1307_Read(void);

void Data2Bcd(DataDateTime *pInputData, BcdDateTime *pOutputData);

void Bcd2Data(BcdDateTime *pInputData, DataDateTime *pOutputData);


#endif /* DS1307_H_ */