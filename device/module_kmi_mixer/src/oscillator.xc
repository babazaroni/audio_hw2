
#include <xs1.h>
#include <xs1_su.h>
#include "platform.h"
#include <print.h>
#include "xs1_su_registers.h"


void internal_oscillator_shut_off(void)
{
    unsigned char reg_val[1];

    read_periph_8(usb_tile,XS1_SU_PER_OSC_CHANEND_NUM,XS1_SU_PER_OSC_ON_SI_CTRL_NUM,1,reg_val);  // was xs1_su

    printstr("internal_oscillator_shut_off:\t");
    printhexln(reg_val[0]);

    reg_val[0] = 0;  // disable internal oscillator

    write_periph_8(tile[0],XS1_SU_PER_OSC_CHANEND_NUM,XS1_SU_PER_OSC_ON_SI_CTRL_NUM,1,reg_val);

}
int oscillator_source(void)
{
    unsigned char read_vals[1];

    read_periph_8(usb_tile,XS1_SU_PER_OSC_CHANEND_NUM,XS1_SU_PER_OSC_GEN_CTRL_NUM,1,read_vals);

//    printstr("internal_oscillator_state:\t");
//    printhexln(read_vals[0] & 1);

    return read_vals[0] & 1;
}
void external_oscillator_switch_to(void)
{
    unsigned char read_vals[1];

    if (oscillator_source())
    {
        read_vals[0] = 0;  // switch to external oscillator and no reset

        write_periph_8(usb_tile,XS1_SU_PER_OSC_CHANEND_NUM,XS1_SU_PER_OSC_GEN_CTRL_NUM,1,read_vals);
    }


}
void internal_oscillator_switch_to(void)
{
    unsigned char read_vals[1];

    if (oscillator_source())
        return;   // return, we are already using the internal oscillator

    read_vals[0] = 1;  // switch to internal oscillator and no reset

    write_periph_8(usb_tile,XS1_SU_PER_OSC_CHANEND_NUM,XS1_SU_PER_OSC_GEN_CTRL_NUM,1,read_vals);

}
unsigned char clock_44p1_diff[] =
{
        34,0x0C,
        35,0x35,
        37,0x0B,
        38,0x8C,
        40,0x02,
        41,0x04,
        45,0x1C,
        49,0x00
};
unsigned char clock_48_diff[] =
{
        34,0x0C,
        35,0x35,
        37,0x0B,
        38,0xC3,
        40,0x02,
        41,0xA1,
        45,0x1A,
        49,0x00
};
unsigned char clock_88p2_diff[] =
{
        34,0x3D,
        35,0x09,
        37,0x0C,
        38,0x73,
        40,0x16,
        41,0xF5,
        45,0x0E,
        49,0x00
};
unsigned char clock_96_diff[] =
{
        34,0x02,
        35,0x71,
        37,0x0C,
        38,0xBE,
        40,0x02,
        41,0x22,
        45,0x0D,
        49,0x00
};
/*
0Ch 0Ch 3Dh 02h
35h 35h 09h 71h
0Bh 0Bh 0Ch 0Ch
8Ch C3h 73h BEh
02h 02h 16h 02h
04h A1h F5h 22h
1Ch 1Ah 0Eh 0Dh
*/


// 25mhz 6pf
unsigned char clock_config_enable_all_96[] =
{
0x00,
0x00,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6F,
0x0F,
0x4F,
0x80,
0x80,
0x80,
0xC0,
0x80,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x02,
0x71,
0x00,
0x0C,
0xBE,
0x00,
0x02,
0x22,
0x00,
0x01,
0x00,
0x0D,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x80,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x00,
0x52,
0x60,
0x60,
0x00,
0xC0,
};
unsigned char clock_config_enable_all_48[] =
{
0x00,
0x00,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6F,
0x0F,
0x4F,
0x80,
0x80,
0x80,
0xC0,
0x80,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x35,
0x00,
0x0B,
0xC3,
0x00,
0x02,
0xA1,
0x00,
0x01,
0x00,
0x1A,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x80,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x00,
0x52,
0x60,
0x60,
0x00,
0xC0,
};
unsigned char clock_config_enable_all_441[] =
{
0x00,
0x00,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6F,
0x0F,
0x4F,
0x80,
0x80,
0x80,
0xC0,
0x80,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x0C,
0x35,
0x00,
0x0B,
0x8C,
0x00,
0x02,
0x04,
0x00,
0x01,
0x00,
0x1C,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x80,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x00,
0x52,
0x60,
0x60,
0x00,
0xC0,
};

unsigned char clock_config_enable_all_882[] =
{
0x00,
0x00,
0x18,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x6F,
0x0F,
0x4F,
0x80,
0x80,
0x80,
0xC0,
0x80,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x3D,
0x09,
0x00,
0x0C,
0x73,
0x00,
0x16,
0xF5,
0x00,
0x01,
0x00,
0x0E,
0x00,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x80,
0x00,
0x00,
0x00,
0x00,
0x01,
0x00,
0x0A,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x00,
0x30,
0x00,
0x52,
0x60,
0x60,
0x00,
0xC0,
};
