# =================== Settings ====================
MCU     = atmega32
F_CPU   = 8000000UL
CC      = avr-gcc
OBJCOPY = avr-objcopy

CFLAGS  = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os
INCLUDES = -I./MCAL/DIO -I./LIBRARIES

TARGET_NAME = calculator
BUILD_DIR = build

SRC = App/main.c \
      MCAL/DIO/DIO_program.c \
      HALL/LED/LED_program.c \
	  HALL/Button/Button_program.c \
	  HALL/Kpad/Kpad_program.c \
	  HALL/LCD/LCD_program.c

OBJ = $(SRC:.c=.o)

# =================== Rules =======================
all: prepare $(BUILD_DIR)/$(TARGET_NAME).hex

prepare:
	mkdir $(BUILD_DIR) 2>nul || exit 0

$(BUILD_DIR)/$(TARGET_NAME).elf: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

$(BUILD_DIR)/$(TARGET_NAME).hex: $(BUILD_DIR)/$(TARGET_NAME).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	del /Q /S $(BUILD_DIR) 2>nul || exit 0
	del /Q App\*.o MECAL\DIO\*.o 2>nul || exit 0
