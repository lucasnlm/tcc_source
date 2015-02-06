#ifndef CONTROL_PINS_HPP_INCLUDED
#define CONTROL_PINS_HPP_INCLUDED

#include <string>

namespace controller
{    
    /**
     * ID's dos pinos da Beaglebone Black.
     * Incluindo apelidos.
     * Os pinos GND são nulos.
     * 
     * Baseado na implementação de:
     *  https://github.com/laugga/bonekit-c
     **/
    enum PinCode : int
    {
        // Bit mask = GPIO (0-7), AIN (8-15), PWM (16-23)
        
        USR0 = 0x35ffff,
        USR1 = 0x36ffff,
        USR2 = 0x37ffff,
        USR3 = 0x38ffff,
        
        P8_1 = 0xffffff,
        P8_2 = 0xffffff,
        P8_3 = 0x26ffff,
        P8_4 = 0x27ffff,
        P8_5 = 0x22ffff,
        P8_6 = 0x23ffff,
        P8_7 = 0x42ffff,
        P8_8 = 0x43ffff,
        P8_9 = 0x45ffff,
        P8_10 = 0x44ffff,
        P8_11 = 0x2dffff,
        P8_12 = 0x2cffff,
        P8_13 = 0x17ff04,
        P8_14 = 0x1affff,
        P8_15 = 0x2fffff, 
        P8_16 = 0x2effff,
        P8_17 = 0x1bffff,
        P8_18 = 0x41ffff, 
        P8_19 = 0x16ff04,
        P8_20 = 0x3fffff,
        P8_21 = 0x3effff,
        P8_22 = 0x25ffff,
        P8_23 = 0x24ffff, 
        P8_24 = 0x21ffff,
        P8_25 = 0x20ffff,
        P8_26 = 0x3dffff,
        P8_27 = 0x56ffff,
        P8_28 = 0x58ffff,
        P8_29 = 0x57ffff,
        P8_30 = 0x59ffff,
        P8_31 = 0x0affff,
        P8_32 = 0x0bffff,
        P8_33 = 0x09ffff,
        P8_34 = 0x51ff02,
        P8_35 = 0x08ffff,
        P8_36 = 0x50ff02,
        P8_37 = 0x4effff, 
        P8_38 = 0x4fffff,
        P8_39 = 0x4cffff, 
        P8_40 = 0x4dffff,
        P8_41 = 0x4affff,
        P8_42 = 0x4bffff,
        P8_43 = 0x48ffff,
        P8_44 = 0x49ffff,
        P8_45 = 0x46ff03,
        P8_46 = 0x47ff03,
        
        P9_1  = 0xffffff,
        P9_2  = 0xffffff,
        P9_3  = 0xffffff,
        P9_4  = 0xffffff,
        P9_5  = 0xffffff,
        P9_6  = 0xffffff,
        P9_7  = 0xffffff,
        P9_8  = 0xffffff,
        P9_9  = 0xffffff,
        P9_10 = 0xffffff, 
        P9_11 = 0x1effff,
        P9_12 = 0x3cffff,
        P9_13 = 0x1fffff,
        P9_14 = 0x32ff06,
        P9_15 = 0x30ffff,
        P9_16 = 0x33ff06,
        P9_17 = 0x05ffff,
        P9_18 = 0x04ffff,
        P9_19 = 0x0dffff,
        P9_20 = 0x0cffff,
        P9_21 = 0x03ff03, 
        P9_22 = 0x02ff03, 
        P9_23 = 0x31ffff,
        P9_24 = 0x0fffff,
        P9_25 = 0x75ffff,
        P9_26 = 0x0effff,
        P9_27 = 0x73ffff,
        P9_28 = 0x71ff04,
        P9_29 = 0x6fff01,
        P9_30 = 0x70ffff,
        P9_31 = 0x6eff01,
        P9_32 = 0xffffff,
        P9_33 = 0xff04ff,
        P9_34 = 0xffffff,
        P9_35 = 0xff06ff,
        P9_36 = 0xff05ff,
        P9_37 = 0xff02ff,
        P9_38 = 0xff03ff,
        P9_39 = 0xff00ff,
        P9_40 = 0xff01ff,
        P9_41 = 0x14ffff,
        P9_42 = 0x07ff00,
        P9_43 = 0xffffff,
        P9_44 = 0xffffff,
        P9_45 = 0xffffff,
        P9_46 = 0xffffff,
        
        GPIO1_6 = P8_3,
        GPIO1_7 = P8_4,
        GPIO1_2 = P8_5,
        GPIO1_3 = P8_6,
        GPIO1_13 = P8_11,
        GPIO1_12 = P8_12,
        GPIO0_26 = P8_14,
        GPIO1_15 = P8_15,
        GPIO1_14 = P8_16,
        GPIO0_27 = P8_17,
        GPIO2_1 = P8_18,
        GPIO1_31 = P8_20,
        GPIO1_30 = P8_21,
        GPIO1_5 = P8_22,
        GPIO1_4 = P8_23,
        GPIO1_1 = P8_24,
        GPIO1_0 = P8_25,
        GPIO1_29 = P8_26,
        GPIO2_22 = P8_27,
        GPIO2_24 = P8_28,
        GPIO2_23 = P8_29,
        GPIO2_25 = P8_30,
        GPIO2_12 = P8_39,
        GPIO2_13 = P8_40,
        GPIO2_10 = P8_41,
        GPIO2_11 = P8_42,
        GPIO2_8 = P8_43,
        GPIO2_9 = P8_44,
        GPIO2_6 = P8_45,
        GPIO2_7 = P8_46,
        GPIO1_28 = P9_12,
        GPIO1_16 = P9_15,
        GPIO1_17 = P9_23,
        GPIO3_21 = P9_25,
        GPIO3_19 = P9_27,

        TIMER4 = P8_7,
        TIMER7 = P8_8,
        TIMER5 = P8_9,
        TIMER6 = P8_10,

        EHRPWM2B = P8_13,
        EHRPWM2A = P8_19,
        EHRPWM1A = P9_14,
        EHRPWM1B = P9_16,

        I2C1_SCL = P9_17,
        I2C1_SDA = P9_18,
        I2C2_SCL = P9_19,
        I2C2_SDA = P9_20,

        SPI1_CS0 = P9_28,
        SPI1_D0 = P9_29,
        SPI1_D1 = P9_30,
        SPI1_SCLK = P9_31,

        CLKOUT2 = P9_41,
        GPIO0_7 = P9_42,

        VDD_ADC = 0xffffff,
        GNDA_ADC = P9_34,
        AIN6 = P9_35,
        AIN5 = P9_36,
        AIN4 = P9_33,
        AIN3 = P9_38,
        AIN2 = P9_37,
        AIN1 = P9_40,
        AIN0 = P9_39,

        UART5_CTSN = P8_31,
        UART5_RTSN = P8_32,
        UART4_RTSN = P8_33,
        UART3_RTSN = P8_34,
        UART4_CTSN = P8_35,
        UART3_CTSN = P8_36,
        UART5_TXD = P8_37,
        UART5_RXD = P8_38,
        UART4_RXD = P9_11,
        UART4_TXD = P9_13,
        UART2_TXD = P9_21,
        UART2_RXD = P9_22,
        UART1_TXD = P9_24,
        UART1_RXD = P9_26,

        DGND = 0xffffff,
        VDD_3V3 = 0xffffff,
        VDD_5V = 0xffffff,
        SYS_5V = 0xffffff,
        PWR_BUT = 0xffffff,
        SYS_RESETn = 0xffffff,
    };
    
    /**
     * Verifica se um pino é GPIO dado o código.
     * @param pin O código do Pino.
     * @return Retorna o número do pino GPIO ou -1 se não for GPIO.
     **/
    int toGPIO(PinCode pin);

    /**
     * Verifica se um pino é AIN dado o código.
     * @param pin O código do Pino.
     * @return Retorna o número do pino AIN ou -1 se não for AIN.
     **/
    int toAIN(PinCode pin);

    /**
     * Verifica se um pino é PWM dado o código.
     * @param pin O código do Pino.
     * @return Retorna o número do pino PWM ou -1 se não for PWM.
     **/
    int toPWM(PinCode pin);
    
    enum Direction : int
    {
        INPUT = 1,
        OUTPUT = 0,
        UNDEFINED = -1,
    };
    
    enum Level : int
    {
        HIGH = 1,
        LOW = 0,
        INVALID = -1
    };
}

#endif
