################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/2020HW4starter.cpp \
../src/AdjMat.cpp \
../src/HW4starter20210223.cpp \
../src/Production.cpp \
../src/Tests.cpp 

OBJS += \
./src/2020HW4starter.o \
./src/AdjMat.o \
./src/HW4starter20210223.o \
./src/Production.o \
./src/Tests.o 

CPP_DEPS += \
./src/2020HW4starter.d \
./src/AdjMat.d \
./src/HW4starter20210223.d \
./src/Production.d \
./src/Tests.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


