################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Maste/git/STM32CubeL5/Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.c 

OBJS += \
./Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.o 

C_DEPS += \
./Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.o: C:/Users/Maste/git/STM32CubeL5/Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../NonSecure/Inc -I../../../../../../../../Drivers/CMSIS/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Device/ST/STM32L5xx/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/BSP/STM32L5xx_Nucleo/stm32l5xx_nucleo.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

