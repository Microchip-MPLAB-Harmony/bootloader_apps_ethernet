# UDP Bootloader

This example application shows how to use the Bootloader Library to bootload an application using UDP protocol.

**Bootloader Application**

-   This is a bootloader application which resides from

    -   The starting location of the flash memory region for SAM devices

    -   The starting location of the Boot flash memory region for PIC32MZ devices

    -   The starting location of Program Flash memory for PIC32MX devices

-   It uses the UDP port to receive application hex from host PC using the Unified Bootloader Host Application

    -   **Port number : 6234**

    -   **IP Address : 192.168.1.11**

-   It calls the bootloader\_Tasks\(\) function which receives application to be programmed into flash memory over the configured UDP port

-   It glows an LED once bootloader firmware is running

-   It uses the On board Switch as bootloader trigger pin to force enter the bootloader at reset of device

-   It checks for bootloader request pattern **\(0x5048434D\)** from the starting 16 Bytes of RAM to force enter bootloader at reset of device


**Test Application**

-   This is a test application which resides from

    -   The end of bootloader size in device flash memory for SAM devices

    -   The end of bootloader size in Program Flash memory for PIC32MX devices

    -   The start of Program Flash memory for PIC32MZ devices

-   It will be loaded into flash memory by bootloader application

-   It blinks an LED and provides console output

-   It uses the On board Switch to trigger the bootloader from firmware

    -   Once the switch is pressed it loads first 16 bytes of RAM with bootloader request pattern **\(0x5048434D\)** and resets the device


**Development Kits**<br />The following table provides links to documentation on how to build and run UDP bootloader on different development kits

-   **[PIC32CZ CA80 Curiosity Ultra Development Board: Building and Running the UDP Bootloader applications](../../docs/GUID-FE7D494A-9FEF-4DBB-917E-3B092DCF1578.md)**  

-   **[PIC32MX Ethernet Starter Kit II: Building and Running the UDP Bootloader applications](../../docs/GUID-EBA7A6EE-EC1F-4E07-9AA3-E5F64D26D721.md)**  

-   **[PIC32MZ Embedded Graphics with Stacked DRAM \(DA\) Starter Kit \(Crypto\): Building and Running the UDP Bootloader applications](../../docs/GUID-CA4B603B-45A8-4087-B75C-D476AF24F0F8.md)**  

-   **[PIC32MZ Embedded Connectivity with FPU \(EF\) Starter Kit: Building and Running the UDP Bootloader applications](../../docs/GUID-C537B303-18AA-4B26-BD05-5E8E4B6B9D7E.md)**  

-   **[SAM E54 Xplained Pro Evaluation Kit: Building and Running the UDP Bootloader applications](../../docs/GUID-1268502A-DC6C-4F6C-83EB-9578D4103BE3.md)**  

-   **[SAM V71 Xplained Ultra Evaluation Kit: Building and Running the UDP Bootloader applications](../../docs/GUID-CA9A479B-DFCA-4ACB-BE76-0600DA8DBDD6.md)**  


**Parent topic:**[MPLAB® Harmony 3 Ethernet Bootloader Application Examples](../../docs/GUID-679DF5A7-EF8F-4A53-ABD6-7C82CA6A2DA1.md)

