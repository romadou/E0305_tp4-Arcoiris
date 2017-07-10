################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/LED.c" \
"../Sources/MCUinit.c" \
"../Sources/MEF.c" \
"../Sources/keypad.c" \
"../Sources/main.c" \

C_SRCS += \
../Sources/LED.c \
../Sources/MCUinit.c \
../Sources/MEF.c \
../Sources/keypad.c \
../Sources/main.c \

OBJS += \
./Sources/LED_c.obj \
./Sources/MCUinit_c.obj \
./Sources/MEF_c.obj \
./Sources/keypad_c.obj \
./Sources/main_c.obj \

OBJS_QUOTED += \
"./Sources/LED_c.obj" \
"./Sources/MCUinit_c.obj" \
"./Sources/MEF_c.obj" \
"./Sources/keypad_c.obj" \
"./Sources/main_c.obj" \

C_DEPS += \
./Sources/LED_c.d \
./Sources/MCUinit_c.d \
./Sources/MEF_c.d \
./Sources/keypad_c.d \
./Sources/main_c.d \

OBJS_OS_FORMAT += \
./Sources/LED_c.obj \
./Sources/MCUinit_c.obj \
./Sources/MEF_c.obj \
./Sources/keypad_c.obj \
./Sources/main_c.obj \


# Each subdirectory must supply rules for building sources it contributes
Sources/LED_c.obj: ../Sources/LED.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/LED.args" -ObjN="Sources/LED_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/%.d: ../Sources/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MCUinit_c.obj: ../Sources/MCUinit.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MCUinit.args" -ObjN="Sources/MCUinit_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/MEF_c.obj: ../Sources/MEF.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/MEF.args" -ObjN="Sources/MEF_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/keypad_c.obj: ../Sources/keypad.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/keypad.args" -ObjN="Sources/keypad_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '

Sources/main_c.obj: ../Sources/main.c
	@echo 'Building file: $<'
	@echo 'Invoking: HCS08 Compiler'
	"$(HC08ToolsEnv)/chc08" -ArgFile"Sources/main.args" -ObjN="Sources/main_c.obj" "$<" -Lm="$(@:%.obj=%.d)" -LmCfg=xilmou
	@echo 'Finished building: $<'
	@echo ' '


