---
title: Release notes
nav_order: 99
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes

## Ethernet Bootloader Applications Release v3.2.0

### Development kit and demo application support

- The following table provides bootloader demo applications available for different development kits.

    | Product Family                 | Development Kits                                    | UDP              | UDP Live Update             |
    | ------------------------------ | --------------------------------------------------- | ---------------- | --------------------------- |
    | SAM D5x/E5x                    | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/ATSAME54-XPRO)               | Yes              | Yes                         |
    | SAM E70/S70/V70/V71            | [SAM V71 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMV71-XULT)        | Yes              | NA                          |
    | PIC32MX5XX/6XX/7XX             | [PIC32MX Ethernet Starter Kit II](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320004-2)                                                                                       | Yes              | NA                          |
    | PIC32MZ DA                     | [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320010-C)                  | Yes              | Yes                         |
    | PIC32MZ EF                     | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/Dm320007)                    | Yes              | Yes                         |
    | PIC32MZ EF                     | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)                    |                  | Yes                         |

- **NA:** Lack of product capability

### Known Issues
- N/A

### Development Tools

* [MPLAB® X IDE v6.05](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v4.20](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
  * MPLAB® Code Configurator (MCC) v5.1.17


## Ethernet Bootloader Applications Release v3.1.0

### New Features

- This release includes support of
    - UDP Live Update Applications for devices with dual flash bank support

### Development kit and demo application support

- The following table provides bootloader demo applications available for different development kits.

    | Product Family                 | Development Kits                                    | UDP              | UDP Live Update             |
    | ------------------------------ | --------------------------------------------------- | ---------------- | --------------------------- |
    | SAM D5x/E5x                    | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/ATSAME54-XPRO)               | Yes              | Yes                         |
    | SAM E70/S70/V70/V71            | [SAM V71 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMV71-XULT)        | Yes              | NA                          |
    | PIC32MX5XX/6XX/7XX             | [PIC32MX Ethernet Starter Kit II](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320004-2)                                                                                       | Yes              | NA                          |
    | PIC32MZ DA                     | [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320010-C)                  | Yes              | Yes                         |
    | PIC32MZ EF                     | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/Dm320007)                    | Yes              | Yes                         |
    | PIC32MZ EF                     | [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)                    |                  | Yes                         |

- **NA:** Lack of product capability

### Known Issues
- N/A

### Development Tools

* [MPLAB® X IDE v5.50](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v3.00](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
    * MPLAB® Harmony 3 Launcher v3.6.4 and above.

## Ethernet Bootloader Applications Release v3.0.2
- Added discover.microchip.com metadata

### Known Issues
- No changes from v3.0.0

### Development Tools
- No changes from v3.0.0

## Ethernet Bootloader Applications Release v3.0.1

- Updated test application projects to disable default linker file generation added in csp v3.8.0 as it requires custom linker file

### Known Issues
- No changes from v3.0.0

### Development Tools
- No changes from v3.0.0

## Ethernet Bootloader Applications Release v3.0.0
### New Features

- This release includes support of
    - UDP Bootloader Applications for SAM and PIC32M family of 32-bit microcontrollers.

### Development kit and demo application support
- The following table provides bootloader demo applications available for different development kits.

    | Product Family                 | Development Kits                                    | UDP              |
    | ------------------------------ | --------------------------------------------------- | ---------------- |
    | SAM D5x/E5x                    | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/ATSAME54-XPRO)               | Yes              |
    | SAM E70/S70/V70/V71            | [SAM V71 Xplained Ultra Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/ATSAMV71-XULT)        | Yes              |
    | PIC32MX5XX/6XX/7XX             | [PIC32MX Ethernet Starter Kit II](https://www.microchip.com/DevelopmentTools/ProductDetails/dm320004-2)                                                                                       | Yes              |
    | PIC32MZ DA                     | [PIC32MZ Embedded Graphics with Stacked DRAM (DA) Starter Kit (Crypto)](https://www.microchip.com/DevelopmentTools/ProductDetails/DM320010-C)                  | Yes              |
    | PIC32MZ EF                     | [PIC32MZ Embedded Connectivity with FPU (EF) Starter Kit](https://www.microchip.com/Developmenttools/ProductDetails/Dm320007)                    | Yes              |


### Known Issues

* N/A


### Development Tools

* [MPLAB® X IDE v5.40](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v2.41](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
    * MPLAB® Harmony Configurator (MHC) v3.5.0 and above.
