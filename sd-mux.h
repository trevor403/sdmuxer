#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

#include <libftdi1/ftdi.h>

#define PRODUCT 0x6001
#define SAMSUNG_VENDOR 0x04e8

// SDMUX specific definitions
#define SOCKET_SEL      (0x01 << 0x00)
#define USB_SEL         (0x01 << 0x03)
#define POWER_SW_OFF    (0x01 << 0x02)
#define POWER_SW_ON     (0x01 << 0x04)
#define DYPER1          (0x01 << 0x05)
#define DYPER2          (0x01 << 0x06)

// USBMUX specific definitions
#define UM_SOCKET_SEL	(0x01 << 0x00)
#define UM_DEVICE_PWR	(0x01 << 0x01)
#define UM_DUT_LED		(0x01 << 0x02)
#define UM_GP_LED		(0x01 << 0x03)


#define DELAY_100MS     100000
#define DELAY_500MS     500000

#define CCDT_SDMUX_STR  "sd-mux"
#define CCDT_SDWIRE_STR "sd-wire"
#define CCDT_USBMUX_STR "usb-mux"

#define STRING_SIZE     128

enum CCCommand {
    CCC_List,
    CCC_DUT,
    CCC_TS,
    CCC_Tick,
    CCC_Pins,
    CCC_Info,
    CCC_ShowSerial,
    CCC_SetSerial,
    CCC_Init,
    CCC_Status,
    CCC_DyPer1,
    CCC_DyPer2,
    CCC_None
};

typedef enum CCCommand CCCommand_t;

// enum Target {
//     T_DUT,
//     T_TS
// };

// typedef enum Target_t Target_t;

#define T_DUT 0
#define T_TS 1
typedef unsigned char Target_t;

enum CCDeviceType {
    CCDT_SDMUX,
    CCDT_SDWIRE,
	CCDT_USBMUX,
    CCDT_MAX
};

typedef enum CCDeviceType CCDeviceType_t;

enum CCFeature {
    CCF_SDMUX,
    CCF_POWERSWITCH,
    CCF_USBMUX,
    CCF_DYPERS,
    CCF_MAX
};

typedef enum CCFeature CCFeature_t;

enum CCOption {
    CCO_DeviceId,
    CCO_DeviceSerial,
    CCO_TickTime,
    CCO_BitsInvert,
    CCO_Vendor,
    CCO_Product,
    CCO_DyPer,
    CCO_DeviceType,
    CCO_MAX
};

union CCOptionValue {
    int argn;
    char *args;
};

typedef union CCOptionValue CCOptionValue_t;

int doPower(bool off, bool on, CCOptionValue_t options[]);
int selectTarget(Target_t target, CCOptionValue_t options[]);

// custom function
int external_selectTarget(Target_t target);
