################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/NonSecure/Src/system_stm32l5xx_ns.c 

OBJS += \
./Drivers/CMSIS/system_stm32l5xx_ns.o 

C_DEPS += \
./Drivers/CMSIS/system_stm32l5xx_ns.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/CMSIS/system_stm32l5xx_ns.o: C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/NonSecure/Src/system_stm32l5xx_ns.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m33 -std=gnu11 -g3 '-DMBEDTLS_CONFIG_FILE="mbedtls_config.h"' -DUSE_HAL_DRIVER -DSTM32L552xx -DDEBUG -c -I../../../../../../../../Drivers/CMSIS/Device/ST/STM32L5xx/Include -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../../Secure_nsclib -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -I../../../../../../../../Drivers/BSP/STM32L5xx_Nucleo -I../../../../../../../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -I../../../../../../../../Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -I../../../NonSecure/Inc -I../../../../../../../../Drivers/CMSIS/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Device/ST/STM32L5xx/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/STM32L5xx_HAL_Driver/Inc/Legacy -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/non_secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM33/secure -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Drivers/CMSIS/Include -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/mbedTLS/include/mbedtls -IC:/Users/Maste/STM32Cube/Repository/STM32Cube_FW_L5_V1.3.1/Middlewares/Third_Party/mbedTLS/include -I"C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/STM32CubeIDE/NonSecure/Application/User/SWP_Module/include" -I"C:/Users/Maste/git/STM32CubeL5/Projects/NUCLEO-L552ZE-Q/Applications/FreeRTOS/FreeRTOS_SecureIOToggle_TrustZone/STM32CubeIDE/NonSecure/Application/User/SWP_Module" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Drivers/CMSIS/system_stm32l5xx_ns.d" -MT"$@" --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

