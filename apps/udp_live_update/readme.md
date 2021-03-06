---
parent: Ethernet Bootloader Applications
title: UDP Live Update
has_children: false
has_toc: false
nav_order: 2
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

To clone or download these application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_ethernet) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

# UDP Live Update

This example application shows how to use the Bootloader Library as a Live Update application using UDP protocol on devices with Dual Bank Support

### Memory Layout

- For CORTEX-M based MCUs refer to [Live Update Memory Layout For CORTEX-M Based MCUs](../docs/readme_live_update_memory_layout_sam.md)

- For MIPS Based MCUs refer to [Live Update Memory Layout For MIPS Based MCUs](../docs/readme_live_update_memory_layout_pic32m.md)

### Switcher Application (For PIC32MZ Devices Only)

- This is a Switcher application which resides from the starting location of the Boot flash memory region
    - A Custom linker file has to be **added manually to project** to place the application in **Boot Flash Memory**

- It Performs below operations
    - At reset it always maps the Program Flash Memory BANK 1 to lower memory region **(0x9D000000)**
    - At **First Bootup** it initializes the Flash Serial region of **both banks** and jumps to **BANK 1** which is mapped to lower region **(0x9D000000)**
    - At subsequent resets it reads the **Serial number** from both the banks to decide which bank has the latest firmware
        - If Bank 1 serial number is **greater than** Bank 2 serial number it jumps to **(0x9D000000)** location, As Bank 1 is already mapped to lower region in above step application in Bank 1 starts running and this becomes **Active Bank**

        - If Bank 2 serial number is **greater than** Bank 1 serial number it maps Bank 2 to lower region by setting the **Swap bit** and jumps to **(0x9D000000)** location. As Bank 2 is now mapped to lower region, application in Bank 2 starts running and this becomes **Active Bank**

- **NOTE: The Switcher project does not have any programing capabilities. It just performs above mentioned operation at reset**


### Live Update Application

- This is a UDP Live update application which resides from start of
    - Program Flash memory **(0x9D000000)** for PIC32MZ Devices
        - A custom linker file **live_update.ld** will be **generated by MHC** to place the application in **Program Flash memory**

    - Internal Flash memory **(0x00000000)** for SAM Devices

- This project uses the **UDP Bootloader library** to receive the new firmware to be programmed to **Inactive Bank**.
    - Here the new firmware will be a updated version of same **Live Update Application**, As the firmware running in other bank also needs to have the programming capability

- Apart from the programming capability this project can perform **other application tasks** simultanously which makes it a **Live Update Application**

- It calls the bootloader_Tasks() function which receives application to be programmed into **Inactive Bank** over the configured UDP port
    - It uses the UDP port to receive application hex from host PC using the Unified Bootloader Host Application
        - **Port number : 6234**
        - **IP Address  : 192.168.1.11**
- It calls Application Tasks routine which
    - Blinks an LED every 1 second
    - Prints Messages over UART console

- It uses the On board Switch to
    - Update the **Serial Number** of Inactive bank where the new firmware is programmed and then trigger a reset to **run new firmware** for PIC32M devices

    - Swap the bank and trigger reset to **run new firmware** programmed in Inactive bank for SAM devices

## Development Kits
The following table provides links to documentation on how to build and run UDP Live Update on different development kits

| Development Kit |
|:---------|
|[PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](docs/readme_pic32mz_das_sk.md) |
|[Curiosity PIC32MZ EF 2.0 Development Board](docs/readme_pic32mz_ef_curiosity_v2.md) |
|[PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](docs/readme_pic32mz_ef_sk.md) |
|[SAM E54 Xplained Pro Evaluation Kit](docs/readme_sam_e54_xpro.md) |
