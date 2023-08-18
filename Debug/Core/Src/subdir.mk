################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/main.c \
../Core/Src/stm32h7xx_hal_msp.c \
../Core/Src/stm32h7xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32h7xx.c 

CPP_SRCS += \
../Core/Src/PID.cpp \
../Core/Src/TIM_IT.cpp \
../Core/Src/chassis_DCmotor.cpp \
../Core/Src/chassis_kinetic_model.cpp \
../Core/Src/mainpp.cpp \
../Core/Src/pusher.cpp \
../Core/Src/script.cpp 

C_DEPS += \
./Core/Src/main.d \
./Core/Src/stm32h7xx_hal_msp.d \
./Core/Src/stm32h7xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32h7xx.d 

OBJS += \
./Core/Src/PID.o \
./Core/Src/TIM_IT.o \
./Core/Src/chassis_DCmotor.o \
./Core/Src/chassis_kinetic_model.o \
./Core/Src/main.o \
./Core/Src/mainpp.o \
./Core/Src/pusher.o \
./Core/Src/script.o \
./Core/Src/stm32h7xx_hal_msp.o \
./Core/Src/stm32h7xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32h7xx.o 

CPP_DEPS += \
./Core/Src/PID.d \
./Core/Src/TIM_IT.d \
./Core/Src/chassis_DCmotor.d \
./Core/Src/chassis_kinetic_model.d \
./Core/Src/mainpp.d \
./Core/Src/pusher.d \
./Core/Src/script.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.cpp Core/Src/subdir.mk
	arm-none-eabi-g++ "$<" -mcpu=cortex-m7 -std=gnu++14 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -fno-exceptions -fno-rtti -fno-use-cxa-atexit -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"
Core/Src/%.o Core/Src/%.su: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32H723xx -c -I../Core/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc -I../Drivers/STM32H7xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32H7xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/PID.d ./Core/Src/PID.o ./Core/Src/PID.su ./Core/Src/TIM_IT.d ./Core/Src/TIM_IT.o ./Core/Src/TIM_IT.su ./Core/Src/chassis_DCmotor.d ./Core/Src/chassis_DCmotor.o ./Core/Src/chassis_DCmotor.su ./Core/Src/chassis_kinetic_model.d ./Core/Src/chassis_kinetic_model.o ./Core/Src/chassis_kinetic_model.su ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/mainpp.d ./Core/Src/mainpp.o ./Core/Src/mainpp.su ./Core/Src/pusher.d ./Core/Src/pusher.o ./Core/Src/pusher.su ./Core/Src/script.d ./Core/Src/script.o ./Core/Src/script.su ./Core/Src/stm32h7xx_hal_msp.d ./Core/Src/stm32h7xx_hal_msp.o ./Core/Src/stm32h7xx_hal_msp.su ./Core/Src/stm32h7xx_it.d ./Core/Src/stm32h7xx_it.o ./Core/Src/stm32h7xx_it.su ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32h7xx.d ./Core/Src/system_stm32h7xx.o ./Core/Src/system_stm32h7xx.su

.PHONY: clean-Core-2f-Src

