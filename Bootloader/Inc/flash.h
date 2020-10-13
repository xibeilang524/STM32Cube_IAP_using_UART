////////////////////////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Create by AnKun on 2019/10/10
 */

#ifndef __FLASH_H
#define __FLASH_H

#include "main.h"

//////////////////////////////////////////// 移植修改区 ///////////////////////////////////////////////

/* FLASH大小：128K */
#define STM32FLASH_SIZE  0x00020000UL

/* FLASH起始地址 */
#define STM32FLASH_BASE  FLASH_BASE

/* FLASH结束地址 */
#define STM32FLASH_END   (STM32FLASH_BASE | STM32FLASH_SIZE)

/* FLASH页大小：1K */
#define STM32FLASH_PAGE_SIZE FLASH_PAGE_SIZE

/* FLASH总页数 */
#define STM32FLASH_PAGE_NUM  (STM32FLASH_SIZE / STM32FLASH_PAGE_SIZE)

/* 获取页地址，X=0~STM32FLASH_PAGE_NUM */
#define ADDR_FLASH_PAGE_X(X)    (STM32FLASH_BASE | (X * STM32FLASH_PAGE_SIZE))


///////////////////////////////////// Bootloader 相关移植修改区 /////////////////////////////////////

typedef struct
{
	uint32_t fearure;
	uint32_t filesize;
	char filename[64];
}env_t;

#define ENV_FEATURE ((uint32_t)0xA1B2C3D4)

/* 环境变量存放地址 */
#define ENV_ADDRESS  ADDR_FLASH_PAGE_X(127)

/* 应用程序存放地址 */
#define APPLICATION_ADDRESS  ADDR_FLASH_PAGE_X(16)

/* 应用程序最大限制 */
#define USER_FLASH_SIZE      0x8000

env_t* env_load(void);
int env_save(void);


/////////////////////////////////////////// 导出函数声明 ////////////////////////////////////////////
void FLASH_Init(void);
uint32_t FLASH_Read(uint32_t Address, uint16_t *Buffer, uint32_t NumToRead);
uint32_t FLASH_Write(uint32_t Address, const uint16_t *Buffer, uint32_t NumToWrite);

#endif // !__FLASH_H

//////////////////////////////////////////////////////// end of file ////////////////////////////////////////////////////////////////
