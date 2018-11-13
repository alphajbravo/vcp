################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL := cmd.exe
RM := rm -rf

USER_OBJS :=

LIBS := 
PROJ := 

O_SRCS := 
C_SRCS := 
S_SRCS := 
S_UPPER_SRCS := 
OBJ_SRCS := 
ASM_SRCS := 
PREPROCESSING_SRCS := 
OBJS := 
OBJS_AS_ARGS := 
C_DEPS := 
C_DEPS_AS_ARGS := 
EXECUTABLES := 
OUTPUT_FILE_PATH :=
OUTPUT_FILE_PATH_AS_ARGS :=
AVR_APP_PATH :=$$$AVR_APP_PATH$$$
QUOTE := "
ADDITIONAL_DEPENDENCIES:=
OUTPUT_FILE_DEP:=
LIB_DEP:=
LINKER_SCRIPT_DEP:=

# Every subdirectory with source files must be described here
SUBDIRS :=  \
../include \
../include/component \
../include/instance \
../include/pio


# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS +=  \
../../startup_samd11.c \
../../main.c \
../../uart.c \
../../usb.c \
../../usb_cdc.c \
../../usb_descriptors.c \
../../usb_std.c


PREPROCESSING_SRCS += 


ASM_SRCS += 


OBJS +=  \
startup_samd11.o \
main.o \
uart.o \
usb.o \
usb_cdc.o \
usb_descriptors.o \
usb_std.o

OBJS_AS_ARGS +=  \
startup_samd11.o \
main.o \
uart.o \
usb.o \
usb_cdc.o \
usb_descriptors.o \
usb_std.o

C_DEPS +=  \
startup_samd11.d \
main.d \
uart.d \
usb.d \
usb_cdc.d \
usb_descriptors.d \
usb_std.d

C_DEPS_AS_ARGS +=  \
startup_samd11.d \
main.d \
uart.d \
usb.d \
usb_cdc.d \
usb_descriptors.d \
usb_std.d

OUTPUT_FILE_PATH +=vcp.elf

OUTPUT_FILE_PATH_AS_ARGS +=vcp.elf

ADDITIONAL_DEPENDENCIES:=

OUTPUT_FILE_DEP:= ./makedep.mk

LIB_DEP+= 

LINKER_SCRIPT_DEP+= 


# AVR32/GNU C Compiler















./%.o: ../../%.c
	@echo Building file: $<
	@echo Invoking: ARM/GNU C Compiler : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE)  -x c -funsigned-char -funsigned-bitfields -mthumb -D__SAMD11D14AM__ -D__SAMD11D14AM__ -DDONT_USE_CMSIS_INIT -DF_CPU=48000000  -I"../../include" -I"../.."  -Os -ffunction-sections -fdata-sections -g3 -Wall -mcpu=cortex-m0plus -c -std=gnu99 -MD -MP -MF "$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)"   -o "$@" "$<" 
	@echo Finished building: $<
	



# AVR32/GNU Preprocessing Assembler



# AVR32/GNU Assembler




ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: $(OUTPUT_FILE_PATH) $(ADDITIONAL_DEPENDENCIES)

$(OUTPUT_FILE_PATH): $(OBJS) $(USER_OBJS) $(OUTPUT_FILE_DEP) $(LIB_DEP) $(LINKER_SCRIPT_DEP)
	@echo Building target: $@
	@echo Invoking: ARM/GNU Linker : 6.3.1
	$(QUOTE)C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-gcc.exe$(QUOTE) -o$(OUTPUT_FILE_PATH_AS_ARGS) $(OBJS_AS_ARGS) $(USER_OBJS) $(LIBS) -mthumb -Wl,--start-group  -Wl,--end-group -L"..\\Device_Startup"  -Wl,--gc-sections -mcpu=cortex-m0plus -Wl,--script=../../linker/samd11d14.ld  
	@echo Finished building target: $@
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O binary "vcp.elf" "vcp.bin"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-objcopy.exe" -O ihex -R .eeprom -R .fuse -R .lock -R .signature  "vcp.elf" "vcp.hex"
	"C:\Program Files (x86)\Atmel\Studio\7.0\toolchain\arm\arm-gnu-toolchain\bin\arm-none-eabi-size.exe" "vcp.elf"
	
	





# Other Targets
clean:
	-$(RM) $(OBJS_AS_ARGS) $(EXECUTABLES)  
	-$(RM) $(C_DEPS_AS_ARGS)   
	rm -rf "vcp.elf" "vcp.a" "vcp.hex" "vcp.bin" "vcp.lss" "vcp.eep" "vcp.map" "vcp.srec"
	