################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/Secure/Src/system_stm32l5xx_s.c 

OBJS += \
./Drivers/CMSIS/system_stm32l5xx_s.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l5xx_s.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l5xx_s.o: C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/Secure/Src/system_stm32l5xx_s.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -I../../../Secure/Inc -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../../../../../../Drivers/CMSIS/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Device/ST/STM32L5xx/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -mcmse -MMD -MP -MF"Drivers/CMSIS/system_stm32l5xx_s.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

