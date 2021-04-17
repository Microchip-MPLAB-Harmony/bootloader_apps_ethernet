---
grand_parent: Ethernet Bootloader Applications
parent: UDP Live Update
title: Building and Running on Curiosity PIC32MZ EF 2.0 Development Board
has_toc: false
---

[![MCHP](https://www.microchip.com/ResourcePackages/Microchip/assets/dist/images/logo.png)](https://www.microchip.com)

# Building and Running the UDP Live Update applications

## Downloading and building the application

To clone or download this application from Github,go to the [main page of this repository](https://github.com/Microchip-MPLAB-Harmony/bootloader_apps_ethernet) and then click Clone button to clone this repo or download as zip file. This content can also be download using content manager by following [these instructions](https://github.com/Microchip-MPLAB-Harmony/contentmanager/wiki)

Path of the application within the repository is **apps/udp_live_update/**

To build the application, refer to the following table and open the project using its IDE.

### Switcher Application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| switcher/firmware/pic32mz_ef_curiosity_v2.X    | MPLABX Project for [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)|


### Live Update Application

| Project Name      | Description                                    |
| ----------------- | ---------------------------------------------- |
| live_update_app/firmware/pic32mz_ef_curiosity_v2.X    | MPLABX Project for [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)|

## Setting up [Curiosity PIC32MZ EF 2.0 Development Board](https://www.microchip.com/developmenttools/ProductDetails/DM320209)

- For programming and UART Console, connect a micro USB cable to the USB Debug port J700

- Mount a LAN8740 PHY daughter board on to the Ethernet Phy Module connector

- Establish a connection between Host PC and the device through the RJ45 Ethernet connector on the LAN8740 PHY daughter board using an Ethernet cable

## Running the Application

1. Open the switcher application project *switcher/firmware/pic32mz_ef_curiosity_v2.X* in the IDE

2. Make sure that the *live_update_app/firmware/pic32mz_ef_curiosity_v2.X* is added as a loadable project to switcher application
    - As the Switcher application does not have any programming capabilities, Adding the **live_update_app as loadable** allows MPLAB X to create a **unified hex file** and program both these application in thier respective memory location based on the respective linker scripts

    ![switcher_mplab_pic32mz_ef_curiosity_v2](./images/switcher_mplab_pic32mz_ef_curiosity_v2.png)

3. Open the Terminal application (Ex.:Tera Term) on the computer to get live update application messages through UART once loaded
4. Configure the serial port settings as follows:
    - Baud : 115200
    - Data : 8 Bits
    - Parity : None
    - Stop : 1 Bit
    - Flow Control : None

5. Build and program the **switcher** application using the IDE

6. **LED3** should start blinking once programming is completed and below message has to be displayed on the Console
    - You can see how the live update application was loaded in BANK 1 by IDE and switcher application jumped BANK 1 to run it

    ![udp_live_update_bank_1](./images/udp_live_update_bank_1.png)

7. Configure the Host PC for setting up IP Address to communicate with the device
    - Go to **Control Panel/Network and Internet/Network Connections**
    - Open **Ethernet properties**

        ![ethernetProperties](../../docs/images/udp_host_pc_ethernet_properties.png)

    - Double Click on **Internet Protocol Version 4 (TCP/IPv4)**

        ![ethernetProperties](../../docs/images/udp_host_pc_ipv4_click.png)

    - Configure the IP Address as shown below
        - **IP address : 192.168.1.12**
        - **Subnet Mask : 255.255.255.0**

        ![ethernetProperties](../../docs/images/udp_host_pc_ip_address.png)

8. Launch the Unified Host application from below path
    - \<harmony3_path\>/bootloader/tools/UnifiedHost-\*/UnifiedHost-\*.jar

9. Configure the Unified host application
    - Select the **Device architecture** and **Protocol** as shown below

        ![hostConfig](../../docs/images/unified_host_config.png)

    - Click on configure button to configure UDP port Number and IP Address

        ![hostUSBSetting](../../docs/images/unified_host_udp_setting.png)

    - Load the live update application hex file to be programmed using below option
        - *\<harmony3_path\>/bootloader_apps_ethernet/apps/udp_live_update/live_update_app/firmware/pic32mz_ef_curiosity_v2.X/dist/pic32mz_ef_curiosity_v2/production/pic32mz_ef_curiosity_v2.X.production.hex*

        ![hostLoadHex](../../docs/images/unified_host_load_hex.png)

    - Open the **Console** window of the host application to view application bootloading sequence

        ![hostToolsConsole](../../docs/images/unified_host_tools_console.png)

10. Click on **Program Device** button to program the loaded live update application hex file on to the device
    - You can note that throughout the programming sequence and after programming the **LED3** will be blinking as the application task is running along with bootloader task **(Live Update Feature)**

    ![hostProgramDevice](../../docs/images/unified_host_program_device.png)

11. Following snapshot shows output of successfully programming the test application
    - Ignore the Device Reset Messages from the host tool. The live update application ignores the reset command received and waits for a switch press to update serial number and reset

    ![hostSuccess](../../docs/images/unified_host_success.png)

12. Press the Switch **SW1** to update serial of **Inactive Bank** and trigger reset. You should see below output on success
    - This step shows that the new firmware programmed in **BANK 2** is running which is mapped to lower region by switcher at reset

    ![udp_live_update_bank_2](./images/udp_live_update_bank_2.png)

13. Repeat Steps 10-12 for further updates and observe the Banks from which application is running at every update

## Configurations to be Noted

### Switcher Application

- The UDP Live Update application requires the **FMIIEN** Device configuration bit to be set to **OFF**. This has to be done in Switcher as the device configuration bits are part of Boot flash memory and can be only programmed by Debugger.
    - The Device configuration bits of the **Live Update Application** will be discarded

- As we are using custom linker script for Switcher, the default linker file generation has to be disabled

![switcher_config](./images/switcher_config.png)

### Live Update Application

- Enable Live Update Option to configure UDP bootloader in **Live Update Mode**

![live_update_app_config_pic32mz_ef_curiosity_v2](./images/live_update_app_config_pic32mz_ef_curiosity_v2.png)

- **Normalize hex file:**
    - Check the Normalize hex file option as shown below, as the Unified bootloader host application takes hex file as an input. Normalizing the hex file will make sure the data in the hex file is arranged sequentially.

![live_update_app_mplab_config_pic32m](./images/live_update_app_mplab_config_pic32m.png)
