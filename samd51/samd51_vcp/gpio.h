


#ifndef GPIO_H_
#define GPIO_H_


// direction control
#define IO_DIR_IN(...)      /*(port, pin), set direction to input */            IO_DIR_IN_SUB(__VA_ARGS__)

#define IO_DIR_OUT(...)     /*(port, pin), set direction to output */           IO_DIR_OUT_SUB(__VA_ARGS__)

// output control
#define IO_OUT_TYPE(...)    /*(port, pin, type), set IO output type */          IO_OUT_TYPE_SUB(__VA_ARGS__)

#define IO_OUT_SPEED(...)   /*(port, pin, strength), set IO drive strength */   IO_OUT_SPEED_SUB(__VA_ARGS__)

#define IO_OUT_SET(...)     /*(port, pin), set output high */                   IO_OUT_SET_SUB(__VA_ARGS__)

#define IO_OUT_CLR(...)     /*(port, pin), set output low */                    IO_OUT_CLR_SUB(__VA_ARGS__)

#define IO_OUT_TGL(...)     /*(port, pin), toggle output */                     IO_OUT_TGL_SUB(__VA_ARGS__)

#define IO_OUT(...)         /*(port, pin, value), set output high or low */     IO_OUT_SUB(__VA_ARGS__)

// input
#define IO_READ(...)        /*(port, pin), read input */                        IO_READ_SUB(__VA_ARGS__)

#define IO_ISHIGH(...)		/*(port, pin), return true if input is high */      IO_READ(__VA_ARGS__)

#define IO_ISLOW(...)		/*(port, pin), return true if input is low */       (!IO_READ(__VA_ARGS__))

#define IO_IN_EN(...)       /*(port, pin), enable input buffer */               IO_IN_EN_SUB(__VA_ARGS__)

#define IO_IN_DIS(...)      /*(port, pin), disable input buffer */              IO_IN_DIS_SUB(__VA_ARGS__)

// pull configuration
#define IO_PULL_UP(...)     /*(port, pin), enable input pullup */               IO_PULL_UP_SUB(__VA_ARGS__)

#define IO_PULL_DOWN(...)   /*(port, pin), enable input pulldown */             IO_PULL_DOWN_SUB(__VA_ARGS__)

#define IO_PULL_OFF(...)    /*(port, pin), disable input pullup/down */         IO_PULL_OFF_SUB(__VA_ARGS__)

// functional mode
#define IO_MODE(...)        /*(port, pin, mode), set IO mode */                 IO_MODE_SUB(__VA_ARGS__)

#define IO_AF_SEL(...)      /*(port, pin, af), select alternate function */     IO_AF_SEL_SUB(__VA_ARGS__)

#define IO_AF_EN(...)       /*(port, pin), enable alternate function */         IO_AF_EN_SUB(__VA_ARGS__)

#define IO_AF_DIS(...)      /*(port, pin), disable alternate function */        IO_AF_DIS_SUB(__VA_ARGS__)

#define CPABL_TARGET_IOPORT_COUNT 2

#if CPABL_TARGET_IOPORT_COUNT > 0
#define PORTA	PORT->Group[0]
#endif
#if CPABL_TARGET_IOPORT_COUNT > 1
#define PORTB	PORT->Group[1]
#endif
#if CPABL_TARGET_IOPORT_COUNT > 2
#define PORTC   PORT->Group[2]
#endif
#if CPABL_TARGET_IOPORT_COUNT > 3
#define PORTD   PORT->Group[3]
#endif

#define INDIRECT_PORT(port)			PORT##port
#define INDIRECT_PIN(port, pin)		PORT_P##port##pin

#define INDIRECT_PINCFG(pin)		PINCFG[pin]

#define IO_PINCFG_REG(port, pin)	INDIRECT_PORT(port).PINCFG[pin].reg

#define IO_OUT_SET_SUB(port, pin)		INDIRECT_PORT(port).OUTSET.reg = (1<<pin)

#define IO_OUT_CLR_SUB(port, pin)		INDIRECT_PORT(port).OUTCLR.reg = (1<<pin)

#define IO_OUT_TGL_SUB(port, pin)		INDIRECT_PORT(port).OUTTGL.reg = (1<<pin)

#define IO_OUT_SUB(port, pin, value)    do {if(value) INDIRECT_PORT(port).OUTSET.reg = (1<<pin); else INDIRECT_PORT(port).OUTCLR.reg = (1<<pin);} while(0);

#define IO_DIR_OUT_SUB(port, pin)	INDIRECT_PORT(port).DIRSET.reg = (1<<pin)

#define IO_DIR_IN_SUB(port, pin)		do { \
    INDIRECT_PORT(port).DIRCLR.reg = (1<<pin); \
    INDIRECT_PORT(port).INDIRECT_PINCFG(pin).reg |= PORT_PINCFG_INEN; \
} while(0);

#define IO_PULLMODE(...)				IO_PULLMODE_SUB(__VA_ARGS__)
#define IO_PULLMODE_SUB(port, pin, mode)	IO_PULLMODE_##mode(port,pin)

#define IO_PULLMODE_NONE(...)			IO_PULLMODE_NONE_SUB(__VA_ARGS__)
#define IO_PULLMODE_NONE_SUB(port,pin)	INDIRECT_PORT(port).INDIRECT_PINCFG(pin).reg &= ~PORT_PINCFG_PULLEN

#define IO_PULL_UP_SUB(port,pin)	do { \
    INDIRECT_PORT(port).INDIRECT_PINCFG(pin).reg |= PORT_PINCFG_PULLEN; \
    IO_OUT_SET(port,pin);\
} while(0);

#define IO_PULL_DOWN_SUB(port,pin)	do { \
    INDIRECT_PORT(port).INDIRECT_PINCFG(pin).reg |= PORT_PINCFG_PULLEN; \
    IO_OUT_CLR(port,pin);\
} while(0);

#define IO_AF_SEL(...)					IO_AF_SEL_SUB(__VA_ARGS__)
#define IO_AF_SEL_SUB(port, pin, mux)	IO_PINMUX_SEL_P##pin(port, mux)

#define IO_PINMUX_SEL_P0(port, mux)		IO_PINMUX_SEL_EVEN(port, 0, mux)
#define IO_PINMUX_SEL_P1(port, mux)		IO_PINMUX_SEL_ODD(port, 1, mux)
#define IO_PINMUX_SEL_P2(port, mux)		IO_PINMUX_SEL_EVEN(port, 2, mux)
#define IO_PINMUX_SEL_P3(port, mux)		IO_PINMUX_SEL_ODD(port, 3, mux)
#define IO_PINMUX_SEL_P4(port, mux)		IO_PINMUX_SEL_EVEN(port, 4, mux)
#define IO_PINMUX_SEL_P5(port, mux)		IO_PINMUX_SEL_ODD(port, 5, mux)
#define IO_PINMUX_SEL_P6(port, mux)		IO_PINMUX_SEL_EVEN(port, 6, mux)
#define IO_PINMUX_SEL_P7(port, mux)		IO_PINMUX_SEL_ODD(port, 7, mux)
#define IO_PINMUX_SEL_P8(port, mux)		IO_PINMUX_SEL_EVEN(port, 8, mux)
#define IO_PINMUX_SEL_P9(port, mux)		IO_PINMUX_SEL_ODD(port, 9, mux)
#define IO_PINMUX_SEL_P10(port, mux)	IO_PINMUX_SEL_EVEN(port, 10, mux)
#define IO_PINMUX_SEL_P11(port, mux)	IO_PINMUX_SEL_ODD(port, 11, mux)
#define IO_PINMUX_SEL_P12(port, mux)	IO_PINMUX_SEL_EVEN(port, 12, mux)
#define IO_PINMUX_SEL_P13(port, mux)	IO_PINMUX_SEL_ODD(port, 13, mux)
#define IO_PINMUX_SEL_P14(port, mux)	IO_PINMUX_SEL_EVEN(port, 14, mux)
#define IO_PINMUX_SEL_P15(port, mux)	IO_PINMUX_SEL_ODD(port, 15, mux)
#define IO_PINMUX_SEL_P16(port, mux)	IO_PINMUX_SEL_EVEN(port, 16, mux)
#define IO_PINMUX_SEL_P17(port, mux)	IO_PINMUX_SEL_ODD(port, 17, mux)
#define IO_PINMUX_SEL_P18(port, mux)	IO_PINMUX_SEL_EVEN(port, 18, mux)
#define IO_PINMUX_SEL_P19(port, mux)	IO_PINMUX_SEL_ODD(port, 19, mux)
#define IO_PINMUX_SEL_P20(port, mux)	IO_PINMUX_SEL_EVEN(port, 20, mux)
#define IO_PINMUX_SEL_P21(port, mux)	IO_PINMUX_SEL_ODD(port, 21, mux)
#define IO_PINMUX_SEL_P22(port, mux)	IO_PINMUX_SEL_EVEN(port, 22, mux)
#define IO_PINMUX_SEL_P23(port, mux)	IO_PINMUX_SEL_ODD(port, 23, mux)
#define IO_PINMUX_SEL_P24(port, mux)	IO_PINMUX_SEL_EVEN(port, 24, mux)
#define IO_PINMUX_SEL_P25(port, mux)	IO_PINMUX_SEL_ODD(port, 25, mux)
#define IO_PINMUX_SEL_P26(port, mux)	IO_PINMUX_SEL_EVEN(port, 26, mux)
#define IO_PINMUX_SEL_P27(port, mux)	IO_PINMUX_SEL_ODD(port, 27, mux)
#define IO_PINMUX_SEL_P28(port, mux)	IO_PINMUX_SEL_EVEN(port, 28, mux)
#define IO_PINMUX_SEL_P29(port, mux)	IO_PINMUX_SEL_ODD(port, 29, mux)
#define IO_PINMUX_SEL_P30(port, mux)	IO_PINMUX_SEL_EVEN(port, 30, mux)
#define IO_PINMUX_SEL_P31(port, mux)	IO_PINMUX_SEL_ODD(port, 31, mux)

#define IO_PINMUX_SEL_EVEN(port, pin, mux) ( INDIRECT_PORT(port).PMUX[pin/2].reg = INDIRECT_PMUX(E,mux) | (INDIRECT_PORT(port).PMUX[pin/2].reg & ~PORT_PMUX_PMUXE_Msk ) )
#define IO_PINMUX_SEL_ODD(port, pin, mux)  ( INDIRECT_PORT(port).PMUX[pin/2].reg = INDIRECT_PMUX(O,mux) | (INDIRECT_PORT(port).PMUX[pin/2].reg & ~PORT_PMUX_PMUXO_Msk ) )

// #define INDIRECT_PMUX(EorO, mux)	PORT_PMUX_PMUX##EorO##_##mux
#define INDIRECT_PMUX(EorO, mux)	PORT_PMUX_PMUX##EorO(ALPHA_TO_INDEX(mux))

//TODO: these might already be defined for some parts, but not others? not defined for SAMD51P20A

#define IO_AF_EN_SUB(port, pin)		IO_PINCFG_REG(port,pin) |= PORT_PINCFG_PMUXEN

#define IO_AF_DIS_SUB(port,pin)		IO_PINCFG_REG(port,pin) &= ~PORT_PINCFG_PMUXEN

#define IO_WRCONFIG_SINGLE(...)			IO_WRCONFIG_SINGLE_SUB(__VA_ARGS__)
#define IO_WRCONFIG_SINGLE_SUB(port,pin,config)	INDIRECT_PORT(port).WRCONFIG.reg = ( (config) | ( (pin>15)?( PORT_WRCONFIG_HWSEL | (0xffff & ( 1<<pin)>>16 )):( 0xffff & ( 1<<pin) ) ) )

#define IO_READ_SUB(port,pin)		((INDIRECT_PORT(port).IN.reg & (1<<pin)) ? 1 : 0)

// used to convert from letter notation to an index, ie in AF select macros
#define ALPHA_TO_INDEX(l)       ALPHA_##l
#define ALPHA_A                 0
#define ALPHA_B                 1
#define ALPHA_C                 2
#define ALPHA_D                 3
#define ALPHA_E                 4
#define ALPHA_F                 5
#define ALPHA_G                 6
#define ALPHA_H                 7
#define ALPHA_I                 8
#define ALPHA_J                 9
#define ALPHA_K                 10
#define ALPHA_L                 11
#define ALPHA_M                 12
#define ALPHA_N                 13
#define ALPHA_O                 14
#define ALPHA_P                 15
#define ALPHA_Q                 16
#define ALPHA_R                 17
#define ALPHA_S                 18
#define ALPHA_T                 19
#define ALPHA_U                 20
#define ALPHA_V                 21
#define ALPHA_W                 22
#define ALPHA_X                 23
#define ALPHA_Y                 24
#define ALPHA_Z                 25

#define USB_DM                  A,24
#define USB_DP                  A,25

#endif /* GPIO.H_H_ */