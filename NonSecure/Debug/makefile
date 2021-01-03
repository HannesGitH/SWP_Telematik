################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/mbedTLS/subdir.mk
-include Middlewares/FreeRTOS/subdir.mk
-include Drivers/STM32L5xx_HAL_Driver/subdir.mk
-include Drivers/CMSIS/subdir.mk
-include Drivers/BSP/STM32L5xx_Nucleo/subdir.mk
-include Application/User/SWP_Module/subdir.mk
-include Application/User/subdir.mk
-include Application/Startup/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := FreeRTOS_SecureIOToggle_TrustZone_NonSecure
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
FreeRTOS_SecureIOToggle_TrustZone_NonSecure.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
FreeRTOS_SecureIOToggle_TrustZone_NonSecure.list \

OBJCOPY_BIN += \
FreeRTOS_SecureIOToggle_TrustZone_NonSecure.bin \


# All Target
all: main-build

# Main-build Target
main-build: FreeRTOS_SecureIOToggle_TrustZone_NonSecure.elf secondary-outputs

# Tool invocations
FreeRTOS_SecureIOToggle_TrustZone_NonSecure.elf: $(OBJS) $(USER_OBJS) C:\Users\Maste\git\STM32CubeL5\Projects\NUCLEO-L552ZE-Q\Applications\FreeRTOS\FreeRTOS_SecureIOToggle_TrustZone\STM32CubeIDE\NonSecure\STM32L552ZETXQ_FLASH.ld
	arm-none-eabi-gcc -o "FreeRTOS_SecureIOToggle_TrustZone_NonSecure.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m33 -T"C:\Users\Maste\git\STM32CubeL5\Projects\NUCLEO-L552ZE-Q\Applications\FreeRTOS\FreeRTOS_SecureIOToggle_TrustZone\STM32CubeIDE\NonSecure\STM32L552ZETXQ_FLASH.ld" --specs=nosys.specs -Wl,-Map="FreeRTOS_SecureIOToggle_TrustZone_NonSecure.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

FreeRTOS_SecureIOToggle_TrustZone_NonSecure.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "FreeRTOS_SecureIOToggle_TrustZone_NonSecure.list"
	@echo 'Finished building: $@'
	@echo ' '

FreeRTOS_SecureIOToggle_TrustZone_NonSecure.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "FreeRTOS_SecureIOToggle_TrustZone_NonSecure.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
