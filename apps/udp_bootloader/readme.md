---
parent: Ethernet Bootloader Applications
title: UDP Bootloader
has_children: false
has_toc: false
nav_order: 1
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

To clone or download these application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_ethernet) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

# UDP Bootloader

This example application shows how to use the Bootloader Library to bootload an application using UDP protocol.

### Bootloader Application

- This is a bootloader application which resides from
    - The starting location of the flash memory region for SAM devices
    - The starting location of the Boot flash memory region for PIC32MZ devices
    - The starting location of Program Flash memory for PIC32MK and PIC32MX devices
- It uses the UDP port to receive application hex from host PC using the Unified Bootloader Host Application
    - **Port number : 6234**
    - **IP Address  : 192.168.1.11**
- It calls the bootloader_Tasks() function which receives application to be programmed into flash memory over the configured UDP port
- It glows an LED once bootloader firmware is running
- It uses the On board Switch as bootloader trigger pin to force enter the bootloader at reset of device
- It checks for bootloader request pattern **(0x5048434D)** from the starting 16 Bytes of RAM to force enter bootloader at reset of device

### Test Application

- This is a test application which resides from
    - The end of bootloader size in device flash memory for SAM devices
    - The end of bootloader size in Program Flash memory for PIC32MK and PIC32MX devices
    - The start of Program Flash memory for PIC32MZ devices
- It will be loaded into flash memory by bootloader application
- It blinks an LED and provides console output
- It uses the On board Switch to trigger the bootloader from firmware
    - Once the switch is pressed it loads first 16 bytes of RAM with bootloader request pattern **(0x5048434D)** and resets the device

## Development Kits
The following table provides links to documentation on how to build and run USB Device HID bootloader on different development kits

| Development Kit |
|:---------|
|[PIC32MX Ethernet Starter Kit II](docs/readme_pic32mx_eth_sk2.md) |
|[PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](docs/readme_pic32mz_das_sk.md) |
|[PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](docs/readme_pic32mz_ef_sk.md) |
|[SAM E54 Xplained Pro Evaluation Kit](docs/readme_sam_e54_xpro.md) |
|[SAM V71 Xplained Ultra Evaluation Kit](docs/readme_sam_v71_xult.md) |
