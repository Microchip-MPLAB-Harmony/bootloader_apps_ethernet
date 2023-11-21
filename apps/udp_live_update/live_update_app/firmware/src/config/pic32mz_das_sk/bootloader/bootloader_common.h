/*******************************************************************************
  Bootloader Common Header File

  File Name:
    bootloader_common.h

  Summary:
    This file contains common definitions and functions.

  Description:
    This file contains common definitions and functions.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#ifndef BOOTLOADER_COMMON_H
#define BOOTLOADER_COMMON_H

#include "definitions.h"
#include <device.h>
#include "sys/kmem.h"

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************

#define FLASH_START                             (0x9d000000UL)
#define FLASH_LENGTH                            (0x200000UL)
#define PAGE_SIZE                               (2048UL)
#define ERASE_BLOCK_SIZE                        (16384UL)
#define PAGES_IN_ERASE_BLOCK                    (ERASE_BLOCK_SIZE / PAGE_SIZE)


#define BOOTLOADER_SIZE                         90112

/* Starting location of Bootloader in Inactive bank */
#define INACTIVE_BANK_OFFSET                    (FLASH_LENGTH / 2U)

#define INACTIVE_BANK_START                     (FLASH_START + INACTIVE_BANK_OFFSET)

#define FLASH_END_ADDRESS                       (INACTIVE_BANK_START + INACTIVE_BANK_OFFSET)


#define APP_START_ADDRESS                       INACTIVE_BANK_START


#define LOWER_FLASH_START                       (FLASH_START)
#define LOWER_FLASH_SERIAL_START                (LOWER_FLASH_START + (FLASH_LENGTH / 2U) - PAGE_SIZE)
#define LOWER_FLASH_SERIAL_SECTOR               (LOWER_FLASH_START + (FLASH_LENGTH / 2U) - ERASE_BLOCK_SIZE)

#define UPPER_FLASH_START                       INACTIVE_BANK_START
#define UPPER_FLASH_SERIAL_START                (FLASH_END_ADDRESS - PAGE_SIZE)
#define UPPER_FLASH_SERIAL_SECTOR               (FLASH_END_ADDRESS - ERASE_BLOCK_SIZE)

#define FLASH_SERIAL_PROLOGUE                   0xDEADBEEFU
#define FLASH_SERIAL_EPILOGUE                   0xBEEFDEADU
#define FLASH_SERIAL_CLEAR                      0xFFFFFFFFU

#define LOWER_FLASH_SERIAL_READ                 ((T_FLASH_SERIAL *)KVA0_TO_KVA1(LOWER_FLASH_SERIAL_START))
#define UPPER_FLASH_SERIAL_READ                 ((T_FLASH_SERIAL *)KVA0_TO_KVA1(UPPER_FLASH_SERIAL_START))

typedef enum
{
    PROGRAM_FLASH_BANK_1,
    PROGRAM_FLASH_BANK_2,
} T_FLASH_BANK;

/* Structure to validate the Flash serial and its checksum
 * Note: The order of the members should not be changed
 */
typedef struct
{
    uint32_t prologue;
    uint32_t serial;
    uint32_t epilogue;
    uint32_t dummy;
} T_FLASH_SERIAL;


// *****************************************************************************

void SYS_DeInitialize( void *data );

/* Function:
    uint16_t bootloader_GetVersion( void );

Summary:
    Returns the current bootloader version.

Description:
    This function can be used to read the current version of bootloader.

    The bootloader version is of 2 Bytes. MAJOR version is sent first
    followed by MINOR version

    This function is defined as __WEAK in bootloader core and defines the bootloader
    version to current release version of bootloader repo.

    It can be overridden with custom implementation by user based on his requirement.

    User can make use of bootloader read version command to read the current version
    from the respective host.

Precondition:
    None

Parameters:
    None.

Returns:
    bootloader version - 2 Bytes (MAJOR version is sent first followed by MINOR version)

Example:
    <code>
    
    #define BTL_MAJOR_VERSION       3
    #define BTL_MINOR_VERSION       6

    uint16_t bootloader_GetVersion( void )
    {
        uint16_t btlVersion = (((BTL_MAJOR_VERSION & 0xFF) << 8) | (BTL_MINOR_VERSION & 0xFF));

        return btlVersion;
    }

    </code>
*/
uint16_t bootloader_GetVersion( void );

/* MISRA C-2012 Rule 5.8 deviated below. Deviation record ID -
   H3_MISRAC_2012_R_5_8_DR_1 */

// *****************************************************************************
/* Function:
    uint32_t bootloader_CRCGenerate(uint32_t start_addr, uint32_t size)

Summary:
    Generates CRC on the contents of Flash memory from the given start address and size

Description:
    This function can be used to verify the programmed image in flash when a Verify
    command is received from the host

Precondition:
    The application binary is already programmed in flash memory

Parameters:
    start_addr - Start address of flash memory to calculate the CRC from
    size - Size of the memory area to calculate CRC for

Returns:
    Returns the calculated CRC

Example:
    <code>
        uint32_t appImageStartAddr;
        uint32_t appImageSize;
        uint32_t receivedCRC;

        appImageStartAddr = 0x00002000;
        appImageSize = 0x8000;
        

        if (bootloader_CRCGenerate(appImageStartAddr, appImageSize) != receivedCRC)
        {
            
        }
        else
        {
            
        }

    </code>
*/

uint32_t bootloader_CRCGenerate(uint32_t start_addr, uint32_t size);

// *****************************************************************************
/* Function:
    void bootloader_TriggerReset(void)

Summary:
    Triggers a reset

Description:
    This function can be used to reset the device in response to the RESET command
    received from the host

Precondition:
    None.

Parameters:
    None

Returns:
    None

Example:
    <code>        

        bootloader_TriggerReset();

    </code>
*/
void bootloader_TriggerReset(void);

/* Function to read the Serial number from Flash bank mapped to lower region */
uint32_t bootloader_GetLowerFlashSerial(void);

/* Function to update the serial number based on address */
void bootloader_UpdateFlashSerial(uint32_t serial, uint32_t addr);

/* Function to update the serial number in upper flash panel (Inactive Panel) */
void bootloader_UpdateUpperFlashSerial(void);



#endif      //BOOTLOADER_COMMON_H