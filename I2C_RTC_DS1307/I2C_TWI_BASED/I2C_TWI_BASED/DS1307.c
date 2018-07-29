/*
 * DS1307.c
 *
 * Created: 7/21/2018 4:39:28 PM
 *  Author: Ram
 */ 

#include "I2C_TWI.h"
#include "DS1307.h"
#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

static int DecimalToBCD(int Decimal);
static int BCDToDecimal(int BCD);

void DS1307_Write(DataDateTime SetDateTime)
{	
	BcdDateTime SetInputBcdFormat;
	
	/* Convert DataDateTime data into BCDFormat data */
	Data2Bcd(&SetDateTime, &SetInputBcdFormat);
	
	/* Start I2C Transfer */
	I2C_start();
	
	/* Select Slave device to Write of Address D0H */
	I2C_write(WriteAddress, SLAVE_ADDRESS);
	
	/* Set Reg Address to 00H */
	I2C_write(WriteData, SLAVE_REG_ADDRESS);
	
	/* Setting up Seconds */
	I2C_write(WriteData, SetInputBcdFormat.Secs);
	
	/* Setting up Minutes */
	I2C_write(WriteData, SetInputBcdFormat.Mins);
	
	/* Setting up Hours */
	I2C_write(WriteData, SetInputBcdFormat.Hrs);
	
	/* Setting up Day */
	I2C_write(WriteData, SetInputBcdFormat.Day);
	
	/* Setting up Date */
	I2C_write(WriteData, SetInputBcdFormat.Date);
	
	/* Setting up Months */
	I2C_write(WriteData, SetInputBcdFormat.Months);
	
	/* Setting up Year */
	I2C_write(WriteData, SetInputBcdFormat.Year);
	
	/* Stop I2C Transfer */
	I2C_stop();
}

DataDateTime DS1307_Read(void)
{
	BcdDateTime BcdregData;
	DataDateTime GetDateTime;
	
	/* Start I2C Transfer */
	I2C_start();
	
	/* Select Slave device to Write of Address D0H */
	I2C_write(WriteAddress, SLAVE_ADDRESS);
	
	/* Set Reg Address to 00H */
	I2C_write(WriteData, SLAVE_REG_ADDRESS);
	
	/* Start I2C Transfer */
	I2C_stop();
	
	/* Start I2C Transfer */
	I2C_start();
	
	/* Select Slave device to Read of Address D1H */
	I2C_write(ReadAddress, SLAVE_ADDRESS);
	
	/* Reading Seconds Value */
	BcdregData.Secs = I2C_Read(ACK);
	
	/* Reading Minutes Value */
	BcdregData.Mins = I2C_Read(ACK);
	
	/* Reading Hours Value */
	BcdregData.Hrs = I2C_Read(ACK);
	
	/* Reading Day Value */
	BcdregData.Day = I2C_Read(ACK);
	
	/* Reading Date Value */
	BcdregData.Date = I2C_Read(ACK);
	
	/* Reading Months Value */
	BcdregData.Months = I2C_Read(ACK);
	
	/* Reading Year Value */
	BcdregData.Year = I2C_Read(ACK);
	
	/* Reading 07H Reg Value */
	BcdregData.Unknown = I2C_Read(NACK);
	
	/* Start I2C Transfer */
	I2C_stop();
	
	/*Converting BCDFormat data into Format of DataDateTime data */
	Bcd2Data(&BcdregData, &GetDateTime);
	
	return GetDateTime;
}

void Data2Bcd(DataDateTime *pInputData, BcdDateTime *pOutputData)
{
	char *ptoken;
	
	/* Parsing Input Time Data */
	ptoken = strtok((char*)pInputData->Time, ":");
	pOutputData->Hrs = DecimalToBCD(atoi(ptoken));
	ptoken = strtok(NULL, ":");
	pOutputData->Mins = DecimalToBCD(atoi(ptoken));
	ptoken = strtok(NULL, " ");
	pOutputData->Secs = DecimalToBCD(atoi(ptoken));

	/* Switching between 12 or 24 Hrs Format based on input */
	ptoken = strtok(NULL, " ");
	if(ptoken != NULL)
	{
		if(!(strcmp(ptoken, "PM")))
		{
			pOutputData->Hrs |= 0x60;
		}
		else
		{
			pOutputData->Hrs |= 0x40;
		}
	}
	
	/* Setting Day No */
	pOutputData->Day = pInputData->eDay;

	/* Parsing Input Date Data */
	ptoken = strtok((char*)pInputData->Date, "-");
	pOutputData->Date = DecimalToBCD(atoi(ptoken));
	ptoken = strtok(NULL, "-");
	pOutputData->Months = DecimalToBCD(atoi(ptoken));
	ptoken = strtok(NULL, " ");
	pOutputData->Year = DecimalToBCD(atoi(ptoken));	
}

void Bcd2Data(BcdDateTime *pInputData, DataDateTime *pOutputData)
{
	uint8_t TimeFormat[10]={0};

	/* Storing Day No */
	pOutputData->eDay = pInputData->Day;
		
	/* Framing Date String */
	sprintf((char*)pOutputData->Date, "%02d-%02d-%04d", BCDToDecimal(pInputData->Date), BCDToDecimal(pInputData->Months), (2000+BCDToDecimal(pInputData->Year)));
	
	/* Refining the Data based on 12 or 24 hrs format */
	if((pInputData->Hrs & 0x40) == 0x40)
	{
		if((pInputData->Hrs & 0x20) == 0x20)
		{
			strcpy((char*)TimeFormat, " PM");
		}
		else
		{
			strcpy((char*)TimeFormat, " AM");
		}
		pInputData->Hrs &= 0x1F;
	}
	
	/* Framing Time String */
	sprintf((char*)pOutputData->Time, "%02d:%02d:%02d%s", BCDToDecimal(pInputData->Hrs), BCDToDecimal(pInputData->Mins), BCDToDecimal(pInputData->Secs), TimeFormat);
}

static int DecimalToBCD(int Decimal)
{
	return (((Decimal/10) << 4) | (Decimal % 10));
}

static int BCDToDecimal(int BCD)
{
	return (((BCD>>4)*10) + (BCD & 0xF));
}