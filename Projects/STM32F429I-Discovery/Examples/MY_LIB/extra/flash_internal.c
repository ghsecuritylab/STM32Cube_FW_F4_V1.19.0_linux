/* Copyright (C) 2018 Rayling <https://github.com/Rayling35>
 * SPDX-License-Identifier: MIT
 */
#include "stm32f4xx_hal.h"
#include "flash_internal.h"


static uint32_t get_sector(enum flash_sector address)
{
	uint32_t sector = 0;
	
	if(address == SECTOR_0_16KB_8000000) {
		sector = FLASH_SECTOR_0;
	}else if(address == SECTOR_1_16KB_8004000) {
		sector = FLASH_SECTOR_1;
	}else if(address == SECTOR_2_16KB_8008000) {
		sector = FLASH_SECTOR_2;
	}else if(address == SECTOR_3_16KB_800C000) {
		sector = FLASH_SECTOR_3;
	}else if(address == SECTOR_4_64KB_8010000) {
		sector = FLASH_SECTOR_4;
	}else if(address == SECTOR_5_128KB_8020000) {
		sector = FLASH_SECTOR_5;
	}else if(address == SECTOR_6_128KB_8040000) {
		sector = FLASH_SECTOR_6;
	}else if(address == SECTOR_7_128KB_8060000) {
		sector = FLASH_SECTOR_7;
	}else if(address == SECTOR_8_128KB_8080000) {
		sector = FLASH_SECTOR_8;
	}else if(address == SECTOR_9_128KB_80A0000) {
		sector = FLASH_SECTOR_9;
	}else if(address == SECTOR_10_128KB_80C0000) {
		sector = FLASH_SECTOR_10;
	}else if(address == SECTOR_11_128KB_80E0000) {
		sector = FLASH_SECTOR_11;
	}else if(address == SECTOR_12_16KB_8100000) {
		sector = FLASH_SECTOR_12;
	}else if(address == SECTOR_13_16KB_8104000) {
		sector = FLASH_SECTOR_13;
	}else if(address == SECTOR_14_16KB_8108000) {
		sector = FLASH_SECTOR_14;
	}else if(address == SECTOR_15_16KB_810C000) {
		sector = FLASH_SECTOR_15;
	}else if(address == SECTOR_16_64KB_8110000) {
		sector = FLASH_SECTOR_16;
	}else if(address == SECTOR_17_128KB_8120000) {
		sector = FLASH_SECTOR_17;
	}else if(address == SECTOR_18_128KB_8140000) {
		sector = FLASH_SECTOR_18;
	}else if(address == SECTOR_19_128KB_8160000) {
		sector = FLASH_SECTOR_19;
	}else if(address == SECTOR_20_128KB_8180000) {
		sector = FLASH_SECTOR_20;
	}else if(address == SECTOR_21_128KB_81A0000) {
		sector = FLASH_SECTOR_21;
	}else if(address == SECTOR_22_128KB_81C0000) {
		sector = FLASH_SECTOR_22;
	}else {
		sector = FLASH_SECTOR_23;
	}
	
	return sector;
}

int flash_internal_erase(enum flash_sector sector)
{
	FLASH_EraseInitTypeDef erase;
	uint32_t first_sector = get_sector(sector);
	uint32_t Nb_of_sectors = get_sector(sector);
	uint32_t sector_error = 0;
	
	erase.TypeErase    = FLASH_TYPEERASE_SECTORS;
	erase.Banks        = 0;
	erase.Sector       = first_sector;
	erase.NbSectors    = Nb_of_sectors - first_sector + 1;
	erase.VoltageRange = FLASH_VOLTAGE_RANGE_3;
	
	HAL_FLASH_Unlock();
	if(HAL_FLASHEx_Erase(&erase, &sector_error) != HAL_OK) { 
		return 1;
	}
	HAL_FLASH_Lock();
	
	return 0;
}

int flash_internal_write(enum flash_sector sector, uint32_t offset, uint8_t data)
{
	uint32_t address = sector + offset;
	
	HAL_FLASH_Unlock();
	if(HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE, address, data) != HAL_OK) {
		return 1;
	}
	HAL_FLASH_Lock();
	
	return 0;
}

uint8_t flash_internal_read(enum flash_sector sector, uint32_t offset)
{
	uint32_t address = sector + offset;
	__IO uint8_t data = *(__IO uint8_t *)address;;
	
	return data;
}