/*******************************************************************************
  UDP Bootloader Header File

  File Name:
    bootloader_udp.h

  Summary:
    This file contains Interface definitions of bootloder

  Description:
    This file defines interface for bootloader.
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

#ifndef BOOTLOADER_UDP_H
#define BOOTLOADER_UDP_H

#include <stdint.h>
#include <stdbool.h>
#include "bootloader_common.h"

#include "sys/kmem.h"


// *****************************************************************************
/* Function:
    void bootloader_SwapAndReset( void );
 Summary:
    Updates the Serial number in Inactive Bank and triggers Reset.

 Description:
    This function can be used by the application to update the serial number in inactive
    bank and trigger reset after Live Update is Completed.

    Switcher in Boot Flash Memory should know the address at compile time where the serial
    number is stored in each bank. It reads the serial number from both banks, Compares the
    values and maps the bank with highest serial number to lower region.

 Precondition:
    - Live Update has to be completed before calling this function

 Parameters:
    None.
 Returns:
    None.

 Example:
    <code>

        bootloader_SwapAndReset( void );

    </code>
*/
void bootloader_SwapAndReset( void );



// *****************************************************************************
/* Function:
    void bootloader_UDP_Tasks( void )

 Summary:
    Starts bootloader execution.

 Description:
    This function can be used to start bootloader execution.

    The function continuously waits for application firmware from the HOST via
    selected communication protocol to program into internal flash memory.

    Once the complete application is received, programmed and verified successfully,
    It resets the device to jump into programmed application.

    Note:
    For Optimized Bootloaders:
        - This function never returns.
        - This function will be directly called from main function

    For Unified and File System based Bootloaders:
        - This function returns once the state machine execution is completed
        - This function will be called from SYS_Tasks() routine from the super loop

 Precondition:
    bootloader_Trigger() must be called to check for bootloader triggers at startup.

 Parameters:
    None.

 Returns:
    None

 Example:
    <code>

        bootloader_UDP_Tasks();

    </code>
*/
void bootloader_UDP_Tasks( void );

#endif  //BOOTLOADER_UDP_H