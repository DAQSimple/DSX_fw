################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DSX_Library/Blink/Src/Blink.c 

OBJS += \
./DSX_Library/Blink/Src/Blink.o 

C_DEPS += \
./DSX_Library/Blink/Src/Blink.d 


# Each subdirectory must supply rules for building sources it contributes
DSX_Library/Blink/Src/Blink.o: ../DSX_Library/Blink/Src/Blink.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32G474xx -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/jpaca/Desktop/Programming/DSX_fw/dsx-fw/DSX_Library/Blink/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"DSX_Library/Blink/Src/Blink.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

