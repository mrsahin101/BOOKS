################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/MemMang/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2/subdir.mk
-include Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
-include Drivers/STM32F4xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := 024_FreeRTOS_Phone_Backlight_Emulator
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
024_FreeRTOS_Phone_Backlight_Emulator.elf \

MAP_FILES += \
024_FreeRTOS_Phone_Backlight_Emulator.map \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
024_FreeRTOS_Phone_Backlight_Emulator.list \


# All Target
all: main-build

# Main-build Target
main-build: 024_FreeRTOS_Phone_Backlight_Emulator.elf secondary-outputs

# Tool invocations
024_FreeRTOS_Phone_Backlight_Emulator.elf 024_FreeRTOS_Phone_Backlight_Emulator.map: $(OBJS) $(USER_OBJS) C:\Users\mehmet.sahin\Desktop\BOOKS\Embedded_Systems\FreeRTOS\Mastering_the_FreeRTOS_Real_Time_Kernel\ST_Workspace\024_FreeRTOS_Phone_Backlight_Emulator\STM32F407VGTX_FLASH.ld makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-gcc -o "024_FreeRTOS_Phone_Backlight_Emulator.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"C:\Users\mehmet.sahin\Desktop\BOOKS\Embedded_Systems\FreeRTOS\Mastering_the_FreeRTOS_Real_Time_Kernel\ST_Workspace\024_FreeRTOS_Phone_Backlight_Emulator\STM32F407VGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="024_FreeRTOS_Phone_Backlight_Emulator.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

024_FreeRTOS_Phone_Backlight_Emulator.list: $(EXECUTABLES) makefile objects.list $(OPTIONAL_TOOL_DEPS)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "024_FreeRTOS_Phone_Backlight_Emulator.list"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) 024_FreeRTOS_Phone_Backlight_Emulator.elf 024_FreeRTOS_Phone_Backlight_Emulator.list 024_FreeRTOS_Phone_Backlight_Emulator.map default.size.stdout
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents main-build fail-specified-linker-script-missing warn-no-linker-script-specified

-include ../makefile.targets
