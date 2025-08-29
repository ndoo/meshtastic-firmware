#ifndef _VARIANT_IKOKA_PRO_
#define _VARIANT_IKOKA_PRO_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

// #define USE_LFXO // Board uses 32khz crystal for LF
#define USE_LFRC // Board uses RC for LF

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Number of pins defined in PinDescription array
#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

// Analog pins

// BATTERY_PIN - Battery <-300kΩ-> P0.31 <-100kΩ-> GND
#define BATTERY_PIN (0 + 31)
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 1.8 // 4.2 V at divider gives 1.05 V
#define VBAT_AR_INTERNAL AR_INTERNAL_1_8
#define ADC_MULTIPLIER 4

// WIRE IC AND IIC PINS
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (0 + 13) // P0.13
#define PIN_WIRE_SCL (0 + 9)  // P0.09

// LED
#define PIN_LED1 (32 + 9) // P1.09
#define LED_BUILTIN PIN_LED1
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1

// GPS
#define GPS_L76K

#ifdef IKOKA_PRO_V0_9_0
// GPS TX and RX got swapped in PCB v0.9.0
#define PIN_GPS_TX (0 + 28) // P0.28
#define PIN_GPS_RX (0 + 29) // P0.29
#else
#define PIN_GPS_TX (0 + 29) // P0.29
#define PIN_GPS_RX (0 + 28) // P0.28
#endif
#define PIN_GPS_STANDBY (0 + 24) // P0.24

// UART interfaces
#define PIN_SERIAL1_RX PIN_GPS_TX
#define PIN_SERIAL1_TX PIN_GPS_RX

#define PIN_SERIAL2_RX -1
#define PIN_SERIAL2_TX -1

// Serial interfaces
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO (0 + 3) // P0.03
#define PIN_SPI_MOSI (0 + 2) // P0.02
#define PIN_SPI_SCK (0 + 5)  // P0.05

// LORA MODULES
// #define USE_LLCC68
#define USE_SX1262
// #define USE_RF95
// #define USE_SX1268

// LORA CONFIG
#define SX126X_CS (32 + 13)      // P1.13
#define SX126X_DIO1 (0 + 10)     // P0.10 IRQ
#define SX126X_DIO2_AS_RF_SWITCH // DIO2 is externally connected to TXEN for automatic TX/RX switching.
#define SX126X_TXEN RADIOLIB_NC
#define SX126X_BUSY (32 + 11)    // P1.11
#define SX126X_RESET (32 + 10)   // P1.10
#define SX126X_RXEN (0 + 30)     // P0.30
#define SX126X_DIO3_TCXO_VOLTAGE 1.8 // EBYTE E22 TCXO

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif
