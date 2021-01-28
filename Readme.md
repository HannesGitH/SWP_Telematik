# Diese Readme wird nur als Fallback verwendet, bitte öffnen Sie unser [WIKI](https://github.com/HannesGitH/SWP_Telematik/wiki)

# SWP Telematik

dem Projekt wird demnächst alles nötige an Information hinzugefügt, bis dahin verweisen wir auf ein [Fork](https://github.com/KurfuerstPilz/Softwareprojekt) des Vorgängerprojektes.

### Used Hardware and Software, useful Documents
#### Soft- & Hardware
- NUCLEO Board L552ZE-Q
- STM32CubeIDE and STM32CubeProgrammer
- ST-Link Driver
#### Documents Links etc.
- [freeRTOS on M33](https://www.freertos.org/2020/04/using-freertos-on-armv8-m-microcontrollers.html)

### Getting started Guide
- befindet sich [hier](https://github.com/HannesGitH/SWP_Telematik/wiki/getting_started)

### STM32CubeIDE and STM32CubeProgrammer

### TF-M and FreeRTOS
#### TF-M

#### FreeRTOS
The main Feature of FreeRTOS is the support to use multiple Tasks. FreeRTOS can be easily integrated in a STM32-Project within the STM32CubeIDE by selecting the associated .ioc File an enabling of CMSIS (Cortex Microcontroller Software Interface Standard). A detailed description on how to enable this option and how the STM32CubeIDE facilitates the developement of applications based on FreeRTOS will be given in Chapter 3. We will focus in this subsection on some Backgrounds that are important to understand for the project. 

### Demonstrations

### Troubleshooting

#### Disable TrustZone and Read Out Protection
If TrustZone is enabled it is not possible to disable it without activating the Read Out Protection and boot to RSS (Root Security Service), which boots the core in an unsecure state. However, before one should enable TrustZone and the Read Out Protection there are some important things to be checked:
1. NEVER use Read Out Protection Level 2, once activated, the board will be locked forever
2. Before enabling Read Out Protection Level 0.5 or 1, make sure to check the following options in the STM32CubeProgrammer:
    - The BOOT LOCK Bit has to be set to 0
    - The nSWBOOT0 has to be set to 1
3. Also in the STM32CubeProgrammer, at the adresse 0x0BF97FFE, the Value should not be 0x00D0
Once these options have been checked, you may proceed to set the RDP Level to 0.5 or 1. Once you have raised the Level of the Read Out Protection you will not be able to connect yout device with the STM32CubeProgrammer, at least not until you boot to RSS.
RSS can be booted by connecting Pin 5 and 7 at C11. Once these Pins are connected, you can reset the device. If the blue and red LED are turned on, you have sucessfully bootes to RSS. Now you can connect with the STM32CubeProgrammer and disable the Read Out Protection and TrustZone (TZEN Bit). After another reset, the device should be fully accessible and TrustZone is diabled

### FreeRTOS is having trouble with creating new tasks
We decided to create a task from an Interrupt triggered by pressing the blue user button. CMSIS doesn't support this option, so the code at cmsis_os2.c has been changed: in line 415 the condition !IS_IRQ() has been removed. There are no issues as far as we can tell, but in the case that FreeRTOS is havng trouble creating tasks or is stuck at some point, you might want to consider this.
Be also aware that, if you want to use HAL while running FreeRTOS, that you need to call HAL_ResumeTick first, as it is suspended during before the NonSecure_Init. You may also deactivate sysTick wit HAL_SuspendTick.
