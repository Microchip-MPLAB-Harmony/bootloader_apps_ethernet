/*******************************************************************************
  Helper Functions for Microchip tcpip

  Summary:
    TCP/IP Stack Library Helpers
    
  Description:
    Common Microchip helper functions
*******************************************************************************/

/*
Copyright (C) 2012-2023, Microchip Technology Inc., and its subsidiaries. All rights reserved.

The software and documentation is provided by microchip and its contributors
"as is" and any express, implied or statutory warranties, including, but not
limited to, the implied warranties of merchantability, fitness for a particular
purpose and non-infringement of third party intellectual property rights are
disclaimed to the fullest extent permitted by law. In no event shall microchip
or its contributors be liable for any direct, indirect, incidental, special,
exemplary, or consequential damages (including, but not limited to, procurement
of substitute goods or services; loss of use, data, or profits; or business
interruption) however caused and on any theory of liability, whether in contract,
strict liability, or tort (including negligence or otherwise) arising in any way
out of the use of the software and documentation, even if advised of the
possibility of such damage.

Except as expressly permitted hereunder and subject to the applicable license terms
for any third-party software incorporated in the software and any applicable open
source software license terms, no license or other rights, whether express or
implied, are granted under any patent or other intellectual property rights of
Microchip or any third party.
*/











#include <ctype.h>
#include <stdarg.h>
#include <string.h>

#include "helpers.h"

typedef union 
{
    uint16_t Val;
    uint8_t v[2];
} MCHP_UINT16_VAL;

typedef union
{
    uint32_t Val;
    uint16_t w[2] __attribute__((packed));
    uint8_t  v[4];
} MCHP_UINT32_VAL;

/*****************************************************************************
  Function:
    void uitoa(uint16_t Value, uint8_t* Buffer)

  Summary:
    Converts an unsigned integer to a decimal string.
    
  Description:
    Converts a 16-bit unsigned integer to a null-terminated decimal string.
    
  Precondition:
    None

  Parameters:
    Value   - The number to be converted
    Buffer  - Pointer in which to store the converted string

  Returns:
    None
  ***************************************************************************/
void uitoa(uint16_t Value, uint8_t* Buffer)
{
    uint8_t i;
    uint16_t Digit;
    uint16_t Divisor;
    bool Printed = false;

    if(Value)
    {
        for(i = 0, Divisor = 10000; i < 5u; i++)
        {
            Digit = Value/Divisor;
            if(Digit || Printed)
            {
                *Buffer++ = '0' + Digit;
                Value -= Digit*Divisor;
                Printed = true;
            }
            Divisor /= 10;
        }
    }
    else
    {
        *Buffer++ = '0';
    }

    *Buffer = '\0';
}               


/*****************************************************************************
  Function:
    uint8_t hexatob(uint16_t AsciiVal)

  Summary:
    Converts a hex string to a single byte.
    
  Description:
    Converts a two-character ASCII hex string to a single packed byte.
    
  Precondition:
    None

  Parameters:
    AsciiVal - uint16_t where the LSB is the ASCII value for the lower nibble
                    and MSB is the ASCII value for the upper nibble.  Each
                    must range from '0'-'9', 'A'-'F', or 'a'-'f'.

  Returns:
    Resulting packed byte 0x00 - 0xFF.
  ***************************************************************************/
uint8_t hexatob(uint16_t AsciiVal)
{
    MCHP_UINT16_VAL AsciiChars;
    AsciiChars.Val = AsciiVal;

    // Convert lowercase to uppercase
    if(AsciiChars.v[1] > 'F')
        AsciiChars.v[1] -= 'a'-'A';
    if(AsciiChars.v[0] > 'F')
        AsciiChars.v[0] -= 'a'-'A';

    // Convert 0-9, A-F to 0x0-0xF
    if(AsciiChars.v[1] > '9')
        AsciiChars.v[1] -= 'A' - 10;
    else
        AsciiChars.v[1] -= '0';

    if(AsciiChars.v[0] > '9')
        AsciiChars.v[0] -= 'A' - 10;
    else
        AsciiChars.v[0] -= '0';

    // Concatenate
    return (AsciiChars.v[1]<<4) |  AsciiChars.v[0];
}

/*****************************************************************************
  Function:
    uint8_t btohexa_high(uint8_t b)

  Summary:
    Converts the upper nibble of a binary value to a hexadecimal ASCII byte.

  Description:
    Converts the upper nibble of a binary value to a hexadecimal ASCII byte.
    For example, btohexa_high(0xAE) will return 'a'.

  Precondition:
    None

  Parameters:
    b - the byte to convert

  Returns:
    The upper hexadecimal ASCII byte '0'-'9' or 'a'-'f'.
  ***************************************************************************/
uint8_t btohexa_high(uint8_t b)
{
    b >>= 4;
    return (b>0x9u) ? b+'a'-10:b+'0';
}

/*****************************************************************************
  Function:
    uint8_t btohexa_high(uint8_t b)

  Summary:
    Converts the lower nibble of a binary value to a hexadecimal ASCII byte.

  Description:
    Converts the lower nibble of a binary value to a hexadecimal ASCII byte.
    For example, btohexa_high(0xAE) will return 'e'.

  Precondition:
    None

  Parameters:
    b - the byte to convert

  Returns:
    The lower hexadecimal ASCII byte '0'-'9' or 'a'-'f'.
  ***************************************************************************/
uint8_t btohexa_low(uint8_t b)
{
    b &= 0x0F;
    return (b>9u) ? b+'a'-10:b+'0';
}

/*****************************************************************************
  Function:
    char* strncpy_m(char* destStr, size_t destSize, int nStrings, ...)

  Summary:
    Copies multiple strings to a destination

  Description:
    Copies multiple strings to a destination
    but doesn't copy more than destSize characters.
    Useful where the destination is actually an array and an extra \0
    won't be appended to overflow the buffer
    
  Precondition:
    - valid string pointers
    - destSize should be > 0

  Parameters:
    destStr - Pointer to a string to be initialized with the multiple strings provided as arguments.

    destSize    - the maximum size of the destStr field, that cannot be exceeded.
                  An \0 won't be appended if the resulting size is > destSize

    nStrings    - number of string parameters to be copied into destStr

    ...         - variable number of arguments
    
    
  Returns:
    Length of the destination string, terminating \0 (if exists) not included
  ***************************************************************************/
size_t strncpy_m(char* destStr, size_t destSize, int nStrings, ...)
{
    va_list     args = {0};
    const char* str;
    char*       end;
    size_t      len;

    destStr[0] = '\0';
    end = destStr + destSize - 1;
    *end = '\0';
    len = 0;
    
    va_start( args, nStrings );
    
    while(nStrings--)
    {
        if(*end)
        {   // if already full don't calculate strlen outside the string area
            len = destSize;
            break;
        }
        
        str = va_arg(args, const char*);
        strncpy(destStr + len, str, destSize - len);
        len += strlen(str);
    }

    va_end( args );
    
    return len;
}

int stricmp(const char *s1, const char *s2)
{
    if (s1 == 0 || s2 == 0)
    {
        return s1 == 0 ? s2 == 0 ? 0 : -(*s2) : *s1;
    }

    int c1, c2;
    do
    {
        c1 = tolower((uint8_t)*s1++);
        c2 = tolower((uint8_t)*s2++);
    }while(c1 != 0 && c1 == c2);

    return (c1 - c2); 
}




