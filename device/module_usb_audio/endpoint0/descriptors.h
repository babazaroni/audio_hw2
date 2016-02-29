/**
 * @file    descriptors.h
 * @brief   Device Descriptors
 * @author  Ross Owen, XMOS Limited
*/

#ifdef KMI
/*
 *
 * clock source resources
 *
http://www.silabs.com/Support%20Documents/TechnicalDocs/usb-audio-simplified.pdf
https://developer.apple.com/library/mac/technotes/tn2274/_index.html
*/
#endif

#ifndef _DEVICE_DESCRIPTORS_
#define _DEVICE_DESCRIPTORS_

#include "devicedefines.h"          /* Device specific define */
#include "usbaudio20.h"             /* Defines from the USB Audio 2.0 Specifications */
#include "usbaudiocommon.h"
#include "usb_std_descriptors.h"

#define APPEND_VENDOR_STR(x) VENDOR_STR" "#x

#define APPEND_PRODUCT_STR_A2(x) PRODUCT_STR_A2 " "#x

#define APPEND_PRODUCT_STR_A1(x) PRODUCT_STR_A1 " "#x

#define STR_TABLE_ENTRY(name) char *name



enum {JACK_ID1=1,JACK_ID2,JACK_ID3,JACK_ID4,JACK_ID5,JACK_ID6,JACK_ID7,JACK_ID8,JACK_ID9,JACK_ID10,JACK_ID11,JACK_ID12};
enum {SOURCE_ID1=1,SOURCE_ID2,SOURCE_ID3,SOURCE_ID4,SOURCE_ID5,SOURCE_ID6,SOURCE_ID7,SOURCE_ID8,SOURCE_ID9,SOURCE_ID10,SOURCE_ID11,SOURCE_ID12};


typedef struct
{
    STR_TABLE_ENTRY(langID);
    STR_TABLE_ENTRY(vendorStr);
    STR_TABLE_ENTRY(serialStr);

    /* Audio 2.0 Strings */
    STR_TABLE_ENTRY(productStr_Audio2);           /* Product string for Audio 2 */
    STR_TABLE_ENTRY(outputInterfaceStr_Audio2);   /* iInterface for streaming intefaces */
    STR_TABLE_ENTRY(inputInterfaceStr_Audio2);    /* iInterface for streaming intefaces */
    STR_TABLE_ENTRY(usbInputTermStr_Audio2);      /* Users sees as output from host */
    STR_TABLE_ENTRY(usbOutputTermStr_Audio2);     /* User sees as input to host */

#if defined (AUDIO_CLASS_FALLBACK) || (AUDIO_CLASS == 1)
    /* Audio 1.0 Strings */
    STR_TABLE_ENTRY(productStr_Audio1);           /* Product string for Audio 1 */
    STR_TABLE_ENTRY(outputInterfaceStr_Audio1);   /* iInterface for streaming intefaces */
    STR_TABLE_ENTRY(inputInterfaceStr_Audio1);    /* iInterface for streaming intefaces */
    STR_TABLE_ENTRY(usbInputTermStr_Audio1);      /* Users sees as output from host */
    STR_TABLE_ENTRY(usbOutputTermStr_Audio1);     /* User sees as input to host */
#endif
    STR_TABLE_ENTRY(clockSelectorStr);            /* iClockSel */
    STR_TABLE_ENTRY(internalClockSourceStr);      /* iClockSource for internal clock */
#ifdef SPDIF_RX
    STR_TABLE_ENTRY(spdifClockSourceStr);         /* iClockSource for external S/PDIF clock */
#endif
#ifdef ADAT_RX
    STR_TABLE_ENTRY(adatClockSourceStr);          /* iClockSource for external S/PDIF clock */
#endif
#ifdef DFU
    STR_TABLE_ENTRY(dfuStr);                      /* iInterface for DFU interface */
#endif
#ifdef MIDI
    STR_TABLE_ENTRY(midiOutStr1);                  /* iJack for MIDI Out */
    STR_TABLE_ENTRY(midiInStr1);                   /* iJack for MIDI In */
    STR_TABLE_ENTRY(midiOutStr2);                  /* iJack for MIDI Out */
    STR_TABLE_ENTRY(midiInStr2);                   /* iJack for MIDI In */
    STR_TABLE_ENTRY(midiOutStr3);                  /* iJack for MIDI Out */
    STR_TABLE_ENTRY(midiInStr3);                   /* iJack for MIDI In */
#endif
#if (NUM_USB_CHAN_OUT > 0)
    STR_TABLE_ENTRY(outputChanStr_1);
#endif
#if (NUM_USB_CHAN_OUT > 1)
    STR_TABLE_ENTRY(outputChanStr_2);
#endif
#if (NUM_USB_CHAN_OUT > 2)
    STR_TABLE_ENTRY(outputChanStr_3);
#endif
#if (NUM_USB_CHAN_OUT > 3)
    STR_TABLE_ENTRY(outputChanStr_4);
#endif
#if (NUM_USB_CHAN_OUT > 4)
    STR_TABLE_ENTRY(outputChanStr_5);
#endif
#if (NUM_USB_CHAN_OUT > 5)
    STR_TABLE_ENTRY(outputChanStr_6);
#endif
#if (NUM_USB_CHAN_OUT > 6)
    STR_TABLE_ENTRY(outputChanStr_7);
#endif
#if (NUM_USB_CHAN_OUT > 7)
    STR_TABLE_ENTRY(outputChanStr_8);
#endif
#if (NUM_USB_CHAN_OUT > 8)
    STR_TABLE_ENTRY(outputChanStr_9);
#endif
#if (NUM_USB_CHAN_OUT > 9)
    STR_TABLE_ENTRY(outputChanStr_10);
#endif
#if (NUM_USB_CHAN_OUT > 10)
    STR_TABLE_ENTRY(outputChanStr_11);
#endif
#if (NUM_USB_CHAN_OUT > 11)
    STR_TABLE_ENTRY(outputChanStr_12);
#endif
#if (NUM_USB_CHAN_OUT > 12)
    STR_TABLE_ENTRY(outputChanStr_13);
#endif
#if (NUM_USB_CHAN_OUT > 13)
    STR_TABLE_ENTRY(outputChanStr_14);
#endif
#if (NUM_USB_CHAN_OUT > 14)
    STR_TABLE_ENTRY(outputChanStr_15);
#endif
#if (NUM_USB_CHAN_OUT > 15)
    STR_TABLE_ENTRY(outputChanStr_16);
#endif
#if (NUM_USB_CHAN_OUT > 16)
    STR_TABLE_ENTRY(outputChanStr_17);
#endif
#if (NUM_USB_CHAN_OUT > 17)
    STR_TABLE_ENTRY(outputChanStr_18);
#endif
#if (NUM_USB_CHAN_OUT > 18)
#error NUM_USB_CHAN > 18
#endif

#if (NUM_USB_CHAN_IN > 0)
    STR_TABLE_ENTRY(inputChanStr_1);
#endif
#if (NUM_USB_CHAN_IN > 1)
    STR_TABLE_ENTRY(inputChanStr_2);
#endif
#if (NUM_USB_CHAN_IN > 2)
    STR_TABLE_ENTRY(inputChanStr_3);
#endif
#if (NUM_USB_CHAN_IN > 3)
    STR_TABLE_ENTRY(inputChanStr_4);
#endif
#if (NUM_USB_CHAN_IN > 4)
    STR_TABLE_ENTRY(inputChanStr_5);
#endif
#if (NUM_USB_CHAN_IN > 5)
    STR_TABLE_ENTRY(inputChanStr_6);
#endif
#if (NUM_USB_CHAN_IN > 6)
    STR_TABLE_ENTRY(inputChanStr_7);
#endif
#if (NUM_USB_CHAN_IN > 7)
    STR_TABLE_ENTRY(inputChanStr_8);
#endif
#if (NUM_USB_CHAN_IN > 8)
    STR_TABLE_ENTRY(inputChanStr_9);
#endif
#if (NUM_USB_CHAN_IN > 9)
    STR_TABLE_ENTRY(inputChanStr_10);
#endif
#if (NUM_USB_CHAN_IN > 10)
    STR_TABLE_ENTRY(inputChanStr_11);
#endif
#if (NUM_USB_CHAN_IN > 11)
    STR_TABLE_ENTRY(inputChanStr_12);
#endif
#if (NUM_USB_CHAN_IN > 12)
    STR_TABLE_ENTRY(inputChanStr_13);
#endif
#if (NUM_USB_CHAN_IN > 13)
    STR_TABLE_ENTRY(inputChanStr_14);
#endif
#if (NUM_USB_CHAN_IN > 14)
    STR_TABLE_ENTRY(inputChanStr_15);
#endif
#if (NUM_USB_CHAN_IN > 15)
    STR_TABLE_ENTRY(inputChanStr_16);
#endif
#if (NUM_USB_CHAN_IN > 16)
    STR_TABLE_ENTRY(inputChanStr_17);
#endif
#if (NUM_USB_CHAN_IN > 17)
    STR_TABLE_ENTRY(inputChanStr_18);
#endif
#if (NUM_USB_CHAN_IN > 18)
#error NUM_USB_CHAN > 18
#endif
    STR_TABLE_ENTRY(iAPInterfaceStr);
} StringDescTable_t;

StringDescTable_t g_strTable =
{
    .langID                      = "\x09\x04", /* US English */
    .vendorStr                   = VENDOR_STR,
    .serialStr                   = "",
    .productStr_Audio2           = PRODUCT_STR_A2,
    .outputInterfaceStr_Audio2   = APPEND_PRODUCT_STR_A2(Output),
    .inputInterfaceStr_Audio2    = APPEND_PRODUCT_STR_A2(Input),
    .usbInputTermStr_Audio2      = APPEND_PRODUCT_STR_A2(Output),
    .usbOutputTermStr_Audio2     = APPEND_PRODUCT_STR_A2(Input),

#if defined (AUDIO_CLASS_FALLBACK) || (AUDIO_CLASS == 1)
    .productStr_Audio1           = PRODUCT_STR_A1,
    .outputInterfaceStr_Audio1   = APPEND_PRODUCT_STR_A1(Output),
    .inputInterfaceStr_Audio1    = APPEND_PRODUCT_STR_A1(Input),
    .usbInputTermStr_Audio1      = APPEND_PRODUCT_STR_A1(Output),
    .usbOutputTermStr_Audio1     = APPEND_PRODUCT_STR_A1(Input),
#endif
    .clockSelectorStr            = APPEND_VENDOR_STR(Clock Selector),
    .internalClockSourceStr      = APPEND_VENDOR_STR(Internal Clock),
#ifdef SPDIF_RX
    .spdifClockSourceStr         = APPEND_VENDOR_STR(S/PDIF Clock),
#endif
#ifdef ADAT_RX
    .adatClockSourceStr          = APPEND_VENDOR_STR(ADAT Clock),
#endif
#ifdef DFU
    .dfuStr                      = APPEND_VENDOR_STR(DFU),
#endif
#ifdef MIDI
#ifdef UNUSED
    .midiOutStr1                   = APPEND_VENDOR_STR(MIDI Out),
    .midiInStr1                    = APPEND_VENDOR_STR(MIDI In),
#endif
    .midiOutStr1                   = "Audio Control",
    .midiInStr1                    = "Audio Control",
    .midiOutStr2                   = "Expander",
    .midiInStr2                    = "Expander",
    .midiOutStr3                   = "Control Surface",
    .midiInStr3                    = "Control Surface",
#endif
#if (NUM_USB_CHAN_OUT > 0)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 0)
    #if defined(SPDIF) && (SPDIF_TX_INDEX < I2S_CHANS_DAC)
    /* I2S/SPDIF overlap */
    .outputChanStr_1             = "Analog 1/SPDIF 1",
    #else
    .outputChanStr_1             = "S/PDIF 1",
    #endif
#else
    .outputChanStr_1             = "Analog 1",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 1)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 1)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_2             = "Analog 2/SPDIF 1",
    #else
    .outputChanStr_2             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 0)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_2             = "Analog 2/SPDIF 2",
    #else
    .outputChanStr_2             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_2             = "Analog 2",
#endif
#endif
#if (NUM_USB_CHAN_OUT > 2)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 2)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_3             = "Analog 3/SPDIF 1",
    #else
    .outputChanStr_3             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 1)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_3             = "Analog 3/SPDIF 2",
    #else
    .outputChanStr_3             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_3             = "Analog 3",
    #endif
#endif
#if (NUM_USB_CHAN_OUT > 3)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 3)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_4             = "Analog 4/SPDIF 1",
    #else
    .outputChanStr_4             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 2)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_4             = "Analog 4/SPDIF 2",
    #else
    .outputChanStr_4             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_4             = "Analog 4",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 4)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 4)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_5             = "Analog 5/SPDIF 1",
    #else
    .outputChanStr_5             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 3)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_5             = "Analog 5/SPDIF 2",
    #else
    .outputChanStr_5             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_5             = "Analog 5",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 5)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 5)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_6             = "Analog 6/SPDIF 1",
    #else
    .outputChanStr_6             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 4)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_6             = "Analog 6/SPDIF 2",
    #else
    .outputChanStr_6             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_6             = "Analog 6",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 6)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 6)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_7             = "Analog 7/SPDIF 1",
    #else
    .outputChanStr_7             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 5)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_7             = "Analog 7/SPDIF 2",
    #else
    .outputChanStr_7             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_7             = "Analog 7",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 7)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 7)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_8             = "Analog 8/SPDIF 1",
    #else
    .outputChanStr_8             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 6)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_8             = "Analog 8/SPDIF 2",
    #else
    .outputChanStr_8             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_8             = "Analog 8",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 8)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 8)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_9             = "Analog 9/SPDIF 1",
    #else
    .outputChanStr_9             = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 7)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_9             = "Analog 9/SPDIF 2",
    #else
    .outputChanStr_9             = "S/PDIF 2",
    #endif
#else
    .outputChanStr_9             = "Analog 9",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 9)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 9)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_10            = "Analog 10/SPDIF 1",
    #else
    .outputChanStr_10            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 8)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_10            = "Analog 10/SPDIF 2",
    #else
    .outputChanStr_10            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_10            = "Analog 10",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 10)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 10)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_11            = "Analog 11/SPDIF 1",
    #else
    .outputChanStr_11            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 9)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_11            = "Analog 11/SPDIF 2",
    #else
    .outputChanStr_11            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_11            = "Analog 11",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 11)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 11)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_12            = "Analog 12/SPDIF 1",
    #else
    .outputChanStr_12            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 10)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_12            = "Analog 12/SPDIF 2",
    #else
    .outputChanStr_12            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_12            = "Analog 12",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 12)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 12)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_13            = "Analog 13/SPDIF 1",
    #else
    .outputChanStr_13            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 11)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_13            = "Analog 13/SPDIF 2",
    #else
    .outputChanStr_13            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_13            = "Analog 13",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 13)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 13)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_14            = "Analog 14/SPDIF 1",
    #else
    .outputChanStr_14            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 12)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_14            = "Analog 14/SPDIF 2",
    #else
    .outputChanStr_14            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_14            = "Analog 14",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 14)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 14)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_15            = "Analog 15/SPDIF 1",
    #else
    .outputChanStr_15            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 13)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_15            = "Analog 15/SPDIF 2",
    #else
    .outputChanStr_15            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_15            = "Analog 15",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 15)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 15)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_16            = "Analog 16/SPDIF 1",
    #else
    .outputChanStr_16            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 14)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_16            = "Analog 16/SPDIF 2",
    #else
    .outputChanStr_16            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_16            = "Analog 16",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 16)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 16)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_17            = "Analog 17/SPDIF 1",
    #else
    .outputChanStr_17            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 15)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_17            = "Analog 17/SPDIF 2",
    #else
    .outputChanStr_17            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_17            = "Analog 17",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 17)
#if defined(SPDIF) && (SPDIF_TX_INDEX == 17)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_18            = "Analog 18/SPDIF 1",
    #else
    .outputChanStr_18            = "S/PDIF 1",
    #endif
#elif defined(SPDIF) && (SPDIF_TX_INDEX == 16)
    #if(SPDIF_TX_INDEX < I2S_CHANS_DAC)
    .outputChanStr_18            = "Analog 18/SPDIF 2",
    #else
    .outputChanStr_18            = "S/PDIF 2",
    #endif
#else
    .outputChanStr_18            = "Analog 18",
#endif
#endif

#if (NUM_USB_CHAN_OUT > 18)
#error NUM_USB_CHAN > 18
#endif

#if (NUM_USB_CHAN_IN > 0)
    .inputChanStr_1              = "Analog 1",
#endif

#if (NUM_USB_CHAN_IN > 1)
    .inputChanStr_2              = "Analog 2",
#endif
#if (NUM_USB_CHAN_IN > 2)
    .inputChanStr_3              = "Analog 3",
#endif
#if (NUM_USB_CHAN_IN > 3)
    .inputChanStr_4              = "Analog 4",
#endif
#if (NUM_USB_CHAN_IN > 4)
    .inputChanStr_5              = "Analog 5",
#endif
#if (NUM_USB_CHAN_IN > 5)
    .inputChanStr_6              = "Analog 6",
#endif
#if (NUM_USB_CHAN_IN > 6)
    .inputChanStr_7              = "Analog 7",
#endif
#if (NUM_USB_CHAN_IN > 7)
    .inputChanStr_8              = "Analog 8",
#endif
#if (NUM_USB_CHAN_IN > 8)
    .inputChanStr_9              = "Analog 9",
#endif
#if (NUM_USB_CHAN_IN > 9)
    .inputChanStr_10             = "Analog 10",
#endif
#if (NUM_USB_CHAN_IN > 10)
    .inputChanStr_11             = "Analog 11",
#endif
#if (NUM_USB_CHAN_IN > 11)
    .inputChanStr_12             = "Analog 12",
#endif
#if (NUM_USB_CHAN_IN > 12)
    .inputChanStr_13             = "Analog 13",
#endif
#if (NUM_USB_CHAN_IN > 13)
    .inputChanStr_14             = "Analog 14",
#endif
#if (NUM_USB_CHAN_IN > 14)
    .inputChanStr_15             = "Analog 15",
#endif
#if (NUM_USB_CHAN_IN > 15)
    .inputChanStr_16             = "Analog 16",
#endif
#if (NUM_USB_CHAN_IN > 16)
    .inputChanStr_17             = "Analog 17",
#endif
#if (NUM_USB_CHAN_IN > 17)
    .inputChanStr_18             = "Analog 18",
#endif
#if (NUM_USB_CHAN_IN > 18)
#error NUM_USB_CHAN > 18
#endif
    .iAPInterfaceStr             = "iAP Interface",
};

/* Interface numbers enum */
enum USBInterfaceNumber
{
    INTERFACE_NUMBER_AUDIO_CONTROL = 0,
#if (NUM_USB_CHAN_OUT > 0)
    INTERFACE_NUMBER_AUDIO_OUTPUT,
#endif
#if  (NUM_USB_CHAN_IN > 0)
    INTERFACE_NUMBER_AUDIO_INPUT,
#endif
#if defined(MIDI) && (MIDI != 0)
    INTERFACE_NUMBER_MIDI_CONTROL,
    INTERFACE_NUMBER_MIDI_STREAM,
#endif
#if defined(DFU) && (DFU != 0)
    INTERFACE_NUMBER_DFU,
#endif
#if defined(IAP) && (IAP != 0)
    INTERFACE_NUMBER_IAP,
#endif
#if defined(HID_CONTROLS) && (HID_CONTROLS != 0)
    INTERFACE_NUMBER_HID,
#endif
    INTERFACE_COUNT          /* End marker */
};

#if (NUM_USB_CHAN_IN > 0) && (NUM_USB_CHAN_OUT > 0)
#define AUDIO_INTERFACE_COUNT 3
#elif (NUM_USB_CHAN_IN > 0) || (NUM_USB_CHAN_OUT > 0)
#define AUDIO_INTERFACE_COUNT 2
#else
#define AUDIO_INTERFACE_COUNT 1
#endif

/* Endpoint address defines */
#define ENDPOINT_ADDRESS_IN_CONTROL     (ENDPOINT_NUMBER_IN_CONTROL | 0x80)
#define ENDPOINT_ADDRESS_IN_FEEDBACK    (ENDPOINT_NUMBER_IN_FEEDBACK | 0x80)
#define ENDPOINT_ADDRESS_IN_AUDIO       (ENDPOINT_NUMBER_IN_AUDIO | 0x80)
#define ENDPOINT_ADDRESS_IN_INTERRUPT   (ENDPOINT_NUMBER_IN_INTERRUPT | 0x80)
#define ENDPOINT_ADDRESS_IN_MIDI        (ENDPOINT_NUMBER_IN_MIDI | 0x80)
#define ENDPOINT_ADDRESS_IN_HID         (ENDPOINT_NUMBER_IN_HID | 0x80)
#define ENDPOINT_ADDRESS_IN_IAP_INT     (ENDPOINT_NUMBER_IN_IAP_INT | 0x80)
#define ENDPOINT_ADDRESS_IN_IAP         (ENDPOINT_NUMBER_IN_IAP | 0x80)

#define ENDPOINT_ADDRESS_OUT_CONTROL    (ENDPOINT_NUMBER_OUT_CONTROL)
#define ENDPOINT_ADDRESS_OUT_AUDIO      (ENDPOINT_NUMBER_OUT_AUDIO)
#define ENDPOINT_ADDRESS_OUT_MIDI       (ENDPOINT_NUMBER_OUT_MIDI)
#define ENDPOINT_ADDRESS_OUT_IAP        (ENDPOINT_NUMBER_OUT_IAP)

/***** Device Descriptors *****/

#if defined(AUDIO_CLASS_FALLBACK) || (AUDIO_CLASS==1)
/* Device Descriptor for Audio Class 1.0 (Assumes Full-Speed) */
USB_Descriptor_Device_t devDesc_Audio1 =
{
    .bLength                        = sizeof(USB_Descriptor_Device_t),
    .bDescriptorType                = USB_DESCTYPE_DEVICE,
    .bcdUSB                         = 0x0200,
    .bDeviceClass                   = 0,
    .bDeviceSubClass                = 0,
    .bDeviceProtocol                = 0,
    .bMaxPacketSize0                = 64,
    .idVendor                       = VENDOR_ID,
    .idProduct                      = PID_AUDIO_1,
    .bcdDevice                      = BCD_DEVICE,
    .iManufacturer                  = offsetof(StringDescTable_t, vendorStr)/sizeof(char *),
    .iProduct                       = offsetof(StringDescTable_t, productStr_Audio2)/sizeof(char *),
    .iSerialNumber                  = 0,
    .bNumConfigurations             = 1
};
#endif

/* Device Descriptor for Audio Class 2.0 (Assumes High-Speed ) */
USB_Descriptor_Device_t devDesc_Audio2 =
{
    .bLength                        = sizeof(USB_Descriptor_Device_t),
    .bDescriptorType                = USB_DESCTYPE_DEVICE,
    .bcdUSB                         = 0x0200,
    .bDeviceClass                   = 0xEF,
    .bDeviceSubClass                = 0x02,
    .bDeviceProtocol                = 0x01,
    .bMaxPacketSize0                = 64,
    .idVendor                       = VENDOR_ID,
    .idProduct                      = PID_AUDIO_2,
    .bcdDevice                      = BCD_DEVICE,
    .iManufacturer                  = offsetof(StringDescTable_t, vendorStr)/sizeof(char *),
    .iProduct                       = offsetof(StringDescTable_t, productStr_Audio2)/sizeof(char *),
    .iSerialNumber                  = 0,
    .bNumConfigurations             = 0x02  /* Set to 2 such that windows does not load composite driver */
};

/* Device Descriptor for Null Device */
unsigned char devDesc_Null[] =
{
    18,                             /* 0  bLength : Size of descriptor in Bytes (18 Bytes) */
    USB_DESCTYPE_DEVICE,            /* 1  bdescriptorType */
    0,                              /* 2  bcdUSB */
    2,                              /* 3  bcdUSB */
    0x0,                            /* 4  bDeviceClass */
    0x0  ,                          /* 5  bDeviceSubClass */
    0x00,                           /* 6  bDeviceProtocol */
    64,                             /* 7  bMaxPacketSize */
    (VENDOR_ID & 0xFF),             /* 8  idVendor */
    (VENDOR_ID >> 8),               /* 9  idVendor */
    (PID_AUDIO_2 & 0xFF),           /* 10 idProduct */
    (PID_AUDIO_2 >> 8),             /* 11 idProduct */
    (BCD_DEVICE & 0xFF),            /* 12 bcdDevice : Device release number */
    (BCD_DEVICE >> 8),              /* 13 bcdDevice : Device release number */
    offsetof(StringDescTable_t, vendorStr)/sizeof(char *),
    offsetof(StringDescTable_t, productStr_Audio2)/sizeof(char *),
    0,                              /* 16 iSerialNumber : Index of serial number decriptor */
    0x01                            /* 17 bNumConfigurations : Number of possible configs */
};


/****** Device Qualifier Descriptors *****/

/* Device Qualifier Descriptor for Audio 2.0 device (Use when running at full-speed. Matches audio 2.0 device descriptor) */
unsigned char devQualDesc_Audio2[] =
{
    10,                             /* 0  bLength (10 Bytes) */
    USB_DESCTYPE_DEVICE_QUALIFIER,           /* 1  bDescriptorType */
    0x00,                           /* 2  bcdUSB (Binary Coded Decimal of usb version) */
    0x02,                           /* 3  bcdUSB */
    0xEF,                           /* 4  bDeviceClass */
    0x02,                           /* 5  bDeviceSubClass */
    0x01,                           /* 6  bDeviceProtocol */
    64,                             /* 7  bMaxPacketSize */
    0x01,                           /* 8  bNumConfigurations : Number of possible configs */
    0x00                            /* 9  bReserved (must be zero) */
};

#if defined(AUDIO_CLASS_FALLBACK) || (AUDIO_CLASS==1)
/* Device Qualifier Descriptor for running at high-speed (matches audio 1.0 device descriptor) */
unsigned char devQualDesc_Audio1[] =
{
    10,                             /* 0  bLength (10 Bytes) */
    USB_DESCTYPE_DEVICE_QUALIFIER,           /* 1  bDescriptorType */
    0x00,                           /* 2  bcdUSB (Binary Coded Decimal of usb version) */
    0x02,                           /* 3  bcdUSB */
    0x00,                           /* 4  bDeviceClass */
    0x00,                           /* 5  bDeviceSubClass */
    0x00,                           /* 6  bDeviceProtocol */
    64,                             /* 7  bMaxPacketSize */
    0x01,                           /* 8  bNumConfigurations : Number of possible configs */
    0x00                            /* 9  bReserved (must be zero) */
};
#endif

/* Device Qualifier Descriptor for Null Device (Use when running at high-speed) */
unsigned char devQualDesc_Null[] =
{
    10,                             /* 0  bLength (10 Bytes) */
    USB_DESCTYPE_DEVICE_QUALIFIER,           /* 1  bDescriptorType */
    0x00,                           /* 2  bcdUSB (Binary Coded Decimal of usb version) */
    0x02,                           /* 3  bcdUSB */
    0x00,                           /* 4  bDeviceClass */
    0x00,                           /* 5  bDeviceSubClass */
    0x00,                           /* 6  bDeviceProtocol */
    64,                             /* 7  bMaxPacketSize */
    0x01,                           /* 8  bNumConfigurations : Number of possible configs */
    0x00                            /* 9  bReserved (must be zero) */
};


#if defined(MIXER) && !defined(AUDIO_PATH_XUS) && (MAX_MIX_COUNT > 0)
#warning Extention units on the audio path are required for mixer.  Enabling them now.
#define AUDIO_PATH_XUS
#endif

#ifdef MIDI


#ifdef KMI
#define	MIDI_BASE_LENGTH	34
#define	MIDI_JACK_PAIR		30
#define	MIDI_BULK			26 + 2*NUM_MIDI_JACKS

#define MIDI_LENGTH                 (MIDI_BASE_LENGTH + MIDI_BULK + MIDI_JACK_PAIR * NUM_MIDI_JACKS)
#else
#define MIDI_LENGTH                 (92)
#define NUM_MIDI_JACKS  1
#endif

#else
#define MIDI_LENGTH                 (0)
#endif

#ifdef DFU
#define DFU_LENGTH                  (18)
#else
#define DFU_LENGTH                  (0)
#endif



#ifdef HID_CONTROLS
unsigned char hidReportDescriptor[] =
{
    0x05, 0x0c,     /* Usage Page (Consumer Device) */
    0x09, 0x01,     /* Usage (Consumer Control) */
    0xa1, 0x01,     /* Collection (Application) */
    0x15, 0x00,     /* Logical Minimum (0) */
    0x25, 0x01,     /* Logical Maximum (1) */
    0x09, 0xb0,     /* Usage (Play) */
    0x09, 0xb5,     /* Usage (Scan Next Track) */
    0x09, 0xb6,     /* Usage (Scan Previous Track) */
    0x09, 0xe9,     /* Usage (Volume Up) */
    0x09, 0xea,     /* Usage (Volume Down) */
    0x09, 0xe2,     /* Usage (Mute) */
    0x75, 0x01,     /* Report Size (1) */
    0x95, 0x06,     /* Report Count (6) */
    0x81, 0x02,     /* Input (Data, Var, Abs) */
    0x95, 0x02,     /* Report Count (2) */
    0x81, 0x01,     /* Input (Cnst, Ary, Abs) */
    0xc0            /* End collection */
};
#endif

/* Max packet sizes:
 * Samples per channel. e.g (192000+7999/8000) = 24
 * Must allow 1 sample extra per chan (24 + 1) = 25
 * Multiply by number of channels and bytes      25 * 2 * 4 = 200 bytes
*/
#define MAX_PACKET_SIZE_MULT_OUT_HS ((((MAX_FREQ+7999)/8000)+1) * NUM_USB_CHAN_OUT)
#define MAX_PACKET_SIZE_MULT_OUT_FS ((((MAX_FREQ_FS+999)/1000)+1) * NUM_USB_CHAN_OUT_FS)
#define MAX_PACKET_SIZE_MULT_IN_HS  ((((MAX_FREQ+7999)/8000)+1) * NUM_USB_CHAN_IN)
#define MAX_PACKET_SIZE_MULT_IN_FS  ((((MAX_FREQ_FS+999)/1000)+1) * NUM_USB_CHAN_IN_FS)

#define HS_STREAM_FORMAT_OUTPUT_1_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_HS * HS_STREAM_FORMAT_OUTPUT_1_SUBSLOT_BYTES)
#define HS_STREAM_FORMAT_OUTPUT_2_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_HS * HS_STREAM_FORMAT_OUTPUT_2_SUBSLOT_BYTES)
#define HS_STREAM_FORMAT_OUTPUT_3_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_HS * HS_STREAM_FORMAT_OUTPUT_3_SUBSLOT_BYTES)

#define FS_STREAM_FORMAT_OUTPUT_1_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_FS * FS_STREAM_FORMAT_OUTPUT_1_SUBSLOT_BYTES)
#define FS_STREAM_FORMAT_OUTPUT_2_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_FS * FS_STREAM_FORMAT_OUTPUT_2_SUBSLOT_BYTES)
#define FS_STREAM_FORMAT_OUTPUT_3_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_OUT_FS * FS_STREAM_FORMAT_OUTPUT_3_SUBSLOT_BYTES)

#define HS_STREAM_FORMAT_INPUT_1_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_IN_HS * HS_STREAM_FORMAT_INPUT_1_SUBSLOT_BYTES)
#define FS_STREAM_FORMAT_INPUT_1_MAXPACKETSIZE (MAX_PACKET_SIZE_MULT_IN_FS * FS_STREAM_FORMAT_INPUT_1_SUBSLOT_BYTES)

#if (NUM_CLOCKS == 1)
#define USB_Descriptor_Audio_ClockSelector_t USB_Descriptor_Audio_ClockSelector_1_t
#elif (NUM_CLOCKS == 2)
#define USB_Descriptor_Audio_ClockSelector_t USB_Descriptor_Audio_ClockSelector_2_t
#elif (NUM_CLOCKS == 3)
#define USB_Descriptor_Audio_ClockSelector_t USB_Descriptor_Audio_ClockSelector_3_t
#endif

typedef struct
{
    /* Class Specific Audio Control Interface Header Descriptor */
    UAC_Descriptor_Interface_AC_t               Audio_ClassControlInterface;
    USB_Descriptor_Audio_ClockSource_t          Audio_ClockSource;
#ifdef SPDIF_RX
    USB_Descriptor_Audio_ClockSource_t          Audio_ClockSource_SPDIF;
#endif
#ifdef ADAT_RX
    USB_Descriptor_Audio_ClockSource_t          Audio_ClockSource_ADAT;
#endif
    USB_Descriptor_Audio_ClockSelector_t        Audio_ClockSelector;
#if (NUM_USB_CHAN_OUT > 0)
    /* Output path */
    USB_Descriptor_Audio_InputTerminal_t        Audio_Out_InputTerminal;
#if(OUTPUT_VOLUME_CONTROL == 1)
    USB_Descriptor_Audio_FeatureUnit_Out_t      Audio_Out_FeatureUnit;
#endif
    USB_Descriptor_Audio_OutputTerminal_t       Audio_Out_OutputTerminal;
#endif
#if (NUM_USB_CHAN_IN > 0)
    /* Input path */
    USB_Descriptor_Audio_InputTerminal_t        Audio_In_InputTerminal;
#if(INPUT_VOLUME_CONTROL == 1)
    USB_Descriptor_Audio_FeatureUnit_In_t       Audio_In_FeatureUnit;
#endif
    USB_Descriptor_Audio_OutputTerminal_t       Audio_In_OutputTerminal;
#endif
} __attribute__((packed)) USB_CfgDesc_Audio2_CS_Control_Int;

typedef struct
{
    /* Configuration header */
    USB_Descriptor_Configuration_Header_t       Config;

    /* Audio Control */
    USB_Descriptor_Interface_Association_t      Audio_InterfaceAssociation;
    USB_Descriptor_Interface_t                  Audio_StdControlInterface;       /* Standard Audio Control Interface Header Descriptor */

    USB_CfgDesc_Audio2_CS_Control_Int           Audio_CS_Control_Int;
#if (NUM_USB_CHAN_OUT > 0)
    /* Audio streaming: Output stream */
    USB_Descriptor_Interface_t                  Audio_Out_StreamInterface_Alt0;  /* Zero bandwith alternative */
    USB_Descriptor_Interface_t                  Audio_Out_StreamInterface_Alt1;
    USB_Descriptor_Audio_Interface_AS_t         Audio_Out_ClassStreamInterface;
    USB_Descriptor_Audio_Format_Type1_t         Audio_Out_Format;
    USB_Descriptor_Endpoint_t                   Audio_Out_Endpoint;
    USB_Descriptor_Audio_Class_AS_Endpoint_t    Audio_Out_ClassEndpoint;
    USB_Descriptor_Endpoint_t                   Audio_Out_Fb_Endpoint;
#if (OUTPUT_FORMAT_COUNT > 1)
    USB_Descriptor_Interface_t                  Audio_Out_StreamInterface_Alt2;
    USB_Descriptor_Audio_Interface_AS_t         Audio_Out_ClassStreamInterface_2;
    USB_Descriptor_Audio_Format_Type1_t         Audio_Out_Format_2;
    USB_Descriptor_Endpoint_t                   Audio_Out_Endpoint_2;
    USB_Descriptor_Audio_Class_AS_Endpoint_t    Audio_Out_ClassEndpoint_2;
    USB_Descriptor_Endpoint_t                   Audio_Out_Fb_Endpoint_2;
#endif
#if (OUTPUT_FORMAT_COUNT > 2)
    USB_Descriptor_Interface_t                  Audio_Out_StreamInterface_Alt3;
    USB_Descriptor_Audio_Interface_AS_t         Audio_Out_ClassStreamInterface_3;
    USB_Descriptor_Audio_Format_Type1_t         Audio_Out_Format_3;
    USB_Descriptor_Endpoint_t                   Audio_Out_Endpoint_3;
    USB_Descriptor_Audio_Class_AS_Endpoint_t    Audio_Out_ClassEndpoint_3;
    USB_Descriptor_Endpoint_t                   Audio_Out_Fb_Endpoint_3;
#endif
#endif
#if (NUM_USB_CHAN_IN > 0)
    /* Audio Streaming: Input stream */
    USB_Descriptor_Interface_t                  Audio_In_StreamInterface_Alt0;  /* Zero bandwith alternative */
    USB_Descriptor_Interface_t                  Audio_In_StreamInterface_Alt1;
    USB_Descriptor_Audio_Interface_AS_t         Audio_In_ClassStreamInterface;
    USB_Descriptor_Audio_Format_Type1_t         Audio_In_Format;
    USB_Descriptor_Endpoint_t                   Audio_In_Endpoint;
    USB_Descriptor_Audio_Class_AS_Endpoint_t    Audio_In_ClassEndpoint;
#endif

#ifdef MIDI
    /* MIDI descriptors currently handled as a single block */
    unsigned char configDesc_Midi[MIDI_LENGTH];
#endif

#ifdef DFU
    /* DFU descriptors currently handled as a single block */
    unsigned char configDesc_DFU[DFU_LENGTH];
#endif

#ifdef IAP
    USB_Descriptor_Interface_t                  iAP_Interface;
    USB_Descriptor_Endpoint_t                   iAP_Out_Endpoint;
    USB_Descriptor_Endpoint_t                   iAP_In_Endpoint;
#ifdef IAP_INT_EP
    USB_Descriptor_Endpoint_t                   iAP_Interrupt_Endpoint;
#endif
#endif

#ifdef HID_CONTROLS
    USB_Descriptor_Interface_t                  HID_Interface;
    unsigned char hidDesc[9];                   //TODO ideally we would have a struct for this.
    USB_Descriptor_Endpoint_t                   HID_In_Endpoint;
#endif

}__attribute__((packed)) USB_Config_Descriptor_Audio2_t;

#if 1
USB_Config_Descriptor_Audio2_t cfgDesc_Audio2=
{
    .Config =
    {
        .bLength                    = sizeof(USB_Descriptor_Configuration_Header_t),
        .bDescriptorType            = USB_DESCTYPE_CONFIGURATION,
        .wTotalLength               = sizeof(USB_Config_Descriptor_Audio2_t),
        .bNumInterfaces             = INTERFACE_COUNT,
        .bConfigurationValue        = 0x01,
        .iConfiguration             = 0x00,
#ifdef SELF_POWERED
        .bmAttributes               = 192,
#else
        .bmAttributes               = 128,
#endif
        .bMaxPower                  = BMAX_POWER,
    },

    .Audio_InterfaceAssociation =
    {
        .bLength                    = sizeof(USB_Descriptor_Interface_Association_t),
        .bDescriptorType            = USB_DESCTYPE_INTERFACE_ASSOCIATION,
        .bFirstInterface            = 0x00,
        .bInterfaceCount            = AUDIO_INTERFACE_COUNT,
        .bFunctionClass             = AUDIO_FUNCTION,
        .bFunctionSubClass          = FUNCTION_SUBCLASS_UNDEFINED,
        .bFunctionProtocol          = UAC_FUNC_PROTOCOL_AF_VERSION_02_00,
        .iFunction                  = 0x00,
    },

    /* Standard Audio Control Interface Descriptor (Note: Must be first with lowest interface number)r */
    .Audio_StdControlInterface =
    {
        .bLength                       = sizeof(USB_Descriptor_Interface_t),
        .bDescriptorType               = USB_DESCTYPE_INTERFACE,
        .bInterfaceNumber              = INTERFACE_NUMBER_AUDIO_CONTROL,
        .bAlternateSetting             = 0x00,                     /* Must be 0 */
#if defined(SPDIF_RX) || defined(ADAT_RX)
        .bNumEndpoints                 = 0x01,                    /* 0 or 1 if optional interrupt endpoint is present */
#else
        .bNumEndpoints                 = 0x00,
#endif
        .bInterfaceClass               = USB_CLASS_AUDIO,
        .bInterfaceSubClass            = UAC_INT_SUBCLASS_AUDIOCONTROL,
        .bInterfaceProtocol            = UAC_INT_PROTOCOL_IP_VERSION_02_00,
        .iInterface                    = offsetof(StringDescTable_t, productStr_Audio2)/sizeof(char *),
    },

    .Audio_CS_Control_Int =
    {
         /* Class Specific Audio Control Interface Header Descriptor: */
        .Audio_ClassControlInterface =
        {
            .bLength                   = sizeof(UAC_Descriptor_Interface_AC_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubtype        = UAC_CS_AC_INTERFACE_SUBTYPE_HEADER,
            .bcdADC                    = 0x0200,
            .bCatagory                 = UAC_FUNCTION_IO_BOX,  /*(Primary use of audio function) */
            .wTotalLength              = sizeof(USB_CfgDesc_Audio2_CS_Control_Int),
            .bmControls                = 0x00,                 /* 0:1 Latency Control, 2:7 must be 0 */
        },

        /* Clock Source Descriptor (4.7.2.1) */
        .Audio_ClockSource =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_ClockSource_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubType        = UAC_CS_AC_INTERFACE_SUBTYPE_CLOCK_SOURCE,
            .bClockID                  = ID_CLKSRC_INT,
            .bmAttributes              =  0x03,                   /* D[1:0] :
                                                                        00: External Clock
                                                                        01: Internal Fixed Clock
                                                                        10: Internal Variable Clock
                                                                        11: Internal Progamable Clock
                                                                     D[2]   : Clock synced to SOF
                                                                     D[7:3] : Reserved (0) */
            .bmControls                = 0x07,                    /*
                                                                    D[1:0] : Clock Freq Control
                                                                    D[3:2] : Clock Validity Control
                                                                    D[7:4] : Reserved (0) */
            .bAssocTerminal            = 0x00,
            .iClockSource              = offsetof(StringDescTable_t, internalClockSourceStr)/sizeof(char *),
        },

#ifdef SPDIF_RX
         /* Clock Source Descriptor (4.7.2.1) */
        .Audio_ClockSource_SPDIF =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_ClockSource_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubType        = UAC_CS_AC_INTERFACE_SUBTYPE_CLOCK_SOURCE,
            .bClockID                  = ID_CLKSRC_SPDIF,
            .bmAttributes              =  0x00,                   /* D[1:0] :
                                                                        00: External Clock
                                                                        01: Internal Fixed Clock
                                                                        10: Internal Variable Clock
                                                                        11: Internal Progamable Clock
                                                                     D[2]   : Clock synced to SOF
                                                                     D[7:3] : Reserved (0) */
            .bmControls                = 0x07,                    /*
                                                                    D[1:0] : Clock Freq Control
                                                                    D[3:2] : Clock Validity Control
                                                                    D[7:4] : Reserved (0) */
            .bAssocTerminal            = 0x00,
            .iClockSource              = offsetof(StringDescTable_t, spdifClockSourceStr)/sizeof(char *),
        },
#endif

#ifdef ADAT_RX
         /* Clock Source Descriptor (4.7.2.1) */
        .Audio_ClockSource_ADAT =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_ClockSource_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubType        = UAC_CS_AC_INTERFACE_SUBTYPE_CLOCK_SOURCE,
            .bClockID                  = ID_CLKSRC_ADAT,
            .bmAttributes              =  0x00,                   /* D[1:0] :
                                                                        00: External Clock
                                                                        01: Internal Fixed Clock
                                                                        10: Internal Variable Clock
                                                                        11: Internal Progamable Clock
                                                                     D[2]   : Clock synced to SOF
                                                                     D[7:3] : Reserved (0) */
            .bmControls                = 0x07,                    /*
                                                                    D[1:0] : Clock Freq Control
                                                                    D[3:2] : Clock Validity Control
                                                                    D[7:4] : Reserved (0) */
            .bAssocTerminal            = 0x00,
            .iClockSource              = offsetof(StringDescTable_t, adatClockSourceStr)/sizeof(char *),
        },
#endif


        /* Clock Selector Descriptor (4.7.2.2) */
        .Audio_ClockSelector =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_ClockSelector_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubType        = UAC_CS_AC_INTERFACE_SUBTYPE_CLOCK_SELECTOR,
            .bClockID                  = ID_CLKSEL,
            .bNrPins                   = NUM_CLOCKS,
            .baCSourceId[0]            = ID_CLKSRC_INT,             /* baCSourceID */
#ifdef SPDIF_RX
            ID_CLKSRC_SPDIF,           /* baCSourceID */

#endif
#ifdef ADAT_RX
            ID_CLKSRC_ADAT,            /* baCSourceID */
#endif
            .bmControl                 = 0x03,
            .iClockSelector            = 13, /* TODO Shoudn't be hard-coded */
        },

#if (NUM_USB_CHAN_OUT > 0)
        /* Input Terminal Descriptor (USB Input Terminal) */
        .Audio_Out_InputTerminal =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_InputTerminal_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubtype        = UAC_CS_AC_INTERFACE_SUBTYPE_INPUT_TERMINAL,
            .bTerminalID               = ID_IT_USB,
            .wTerminalType             = USB_TERMTYPE_USB_STREAMING,
            .bAssocTerminal            = 0x00,
            .bCSourceID                = ID_CLKSEL,
            .bNrChannels               = NUM_USB_CHAN_OUT,
            .bmChannelConfig           = 0x00000000,                               /* TODO. Set me! */
            .iChannelNames             = offsetof(StringDescTable_t, outputChanStr_1)/sizeof(char *),
            .bmControls                =  0x0000,
            .iTerminal                 = offsetof(StringDescTable_t, usbInputTermStr_Audio2)/sizeof(char *)
        },

#if(OUTPUT_VOLUME_CONTROL == 1)
        /* Feature Unit Descriptor */
        .Audio_Out_FeatureUnit =
        {
            .bLength                    = sizeof(USB_Descriptor_Audio_FeatureUnit_Out_t),               /* 0  bLength: 6+(ch + 1)*4 */
            0x24,                           /* 1  bDescriptorType: CS_INTERFACE */
            0x06,                           /* 2  bDescriptorSubType: FEATURE_UNIT */
            FU_USBOUT,                      /* 3  bUnitID */
#ifdef AUDIO_PATH_XUS
            ID_XU_OUT,                      /* 4  bSourceID */
#else
            ID_IT_USB,                      /* 4  bSourceID */
#endif
            {
#if (NUM_USB_CHAN_OUT > 0)
                0x0000000F,         /* bmaControls(0) : Mute and Volume host read and writable */
                0x0000000F,         /* bmaControls(1) */
#endif
#if (NUM_USB_CHAN_OUT > 1)
                0x0000000F,         /* bmaControls(2) */
#endif
#if (NUM_USB_CHAN_OUT > 2)
                0x0000000F,         /* bmaControls(3) */
#endif
#if (NUM_USB_CHAN_OUT > 3)
                0x0000000F,         /* bmaControls(4) */
#endif
#if (NUM_USB_CHAN_OUT > 4)
                0x0000000F,         /* bmaControls(5) */
#endif
#if (NUM_USB_CHAN_OUT > 5)
                0x0000000F,         /* bmaControls(6) */
#endif
#if (NUM_USB_CHAN_OUT > 6)
                0x0000000F,         /* bmaControls(7) */
#endif
#if (NUM_USB_CHAN_OUT > 7)
                0x0000000F,         /* bmaControls(8) */
#endif
#if (NUM_USB_CHAN_OUT > 8)
                0x0000000F,         /* bmaControls(9) */
#endif
#if (NUM_USB_CHAN_OUT > 9)
                0x0000000F,         /* bmaControls(10) */
#endif
#if (NUM_USB_CHAN_OUT > 10)
                0x0000000F,         /* bmaControls(11) */
#endif
#if (NUM_USB_CHAN_OUT > 11)
                0x0000000F,         /* bmaControls(12) */
#endif
#if (NUM_USB_CHAN_OUT > 12)
                0x0000000F,         /* bmaControls(13) */
#endif
#if (NUM_USB_CHAN_OUT > 13)
                0x0000000F,         /* bmaControls(14) */
#endif
#if (NUM_USB_CHAN_OUT > 14)
                0x0000000F,         /* bmaControls(15) */
#endif
#if (NUM_USB_CHAN_OUT > 15)
                0x0000000F,         /* bmaControls(16) */
#endif
#if (NUM_USB_CHAN_OUT > 16)
                0x0000000F,         /* bmaControls(17) */
#endif
#if (NUM_USB_CHAN_OUT > 17)
                0x0000000F,         /* bmaControls(18) */
#endif
#if (NUM_USB_CHAN_OUT > 18)
#error NUM_USB_CHAN_OUT > 18
#endif
            },
            0,                              /* 60 iFeature */
        },
#endif

        /* Output Terminal Descriptor (Audio) */
        .Audio_Out_OutputTerminal =
        {
            0x0C,                                        /* 0  bLength */
            UAC_CS_DESCTYPE_INTERFACE,                   /* 1  bDescriptorType: 0x24 */
            UAC_CS_AC_INTERFACE_SUBTYPE_OUTPUT_TERMINAL, /* 2  bDescriptorSubType: OUTPUT_TERMINAL */
            ID_OT_AUD,                                   /* 3  bTerminalID */
            .wTerminalType              = UAC_TT_OUTPUT_TERMTYPE_SPEAKER,
            0x00,                                        /* 6  bAssocTerminal */
#if (OUTPUT_VOLUME_CONTROL == 1)
            FU_USBOUT,                                   /* 7  bSourceID Connect to analog input feature unit*/
#else
            ID_IT_USB,                                   /* 7  bSourceID Connect to analog input feature unit*/
#endif
            ID_CLKSEL,                                   /* 8  bCSourceUD */
            0x0000,                                      /* 9  bmControls */
            0,                                           /* 11 iTerminal */
        },
#endif
#if (NUM_USB_CHAN_IN > 0)
    /* Input Terminal Descriptor (Analog Input Terminal) */
        .Audio_In_InputTerminal =
        {
            .bLength                   = sizeof(USB_Descriptor_Audio_InputTerminal_t),
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubtype        = UAC_CS_AC_INTERFACE_SUBTYPE_INPUT_TERMINAL,
            .bTerminalID               = ID_IT_AUD,
            .wTerminalType             = UAC_TT_INPUT_TERMTYPE_MICROPHONE,
            .bAssocTerminal            = 0x00,
            .bCSourceID                = ID_CLKSEL,
            .bNrChannels               = NUM_USB_CHAN_IN,
            .bmChannelConfig           = 0x00000000,
            .iChannelNames             = offsetof(StringDescTable_t, inputChanStr_1)/sizeof(char *),
            .bmControls                = 0x0000,
            .iTerminal                 = 0,
        },

#if (INPUT_VOLUME_CONTROL == 1)
        .Audio_In_FeatureUnit =
        {
            .bLength                    = sizeof(USB_Descriptor_Audio_FeatureUnit_In_t),
            UAC_CS_DESCTYPE_INTERFACE,                      /* 1  bDescriptorType: CS_INTERFACE */
            UAC_CS_AC_INTERFACE_SUBTYPE_FEATURE_UNIT,       /* 2  bDescriptorSubType: FEATURE_UNIT */
            FU_USBIN,                                       /* 3  bUnitID */
#ifdef AUDIO_PATH_XUS
            ID_XU_IN,                                       /* 4  bSourceID */
#else
            ID_IT_AUD,                                      /* 4  bSourceID */
#endif
            {
#if (NUM_USB_CHAN_IN > 0)
                0x0000000F,         /* bmaControls(0) : Mute and Volume host read and writable */
                0x0000000F,         /* bmaControls(1) */
#endif
#if (NUM_USB_CHAN_IN > 1)
                0x0000000F,         /* bmaControls(2) */
#endif
#if (NUM_USB_CHAN_IN > 2)
                0x0000000F,         /* bmaControls(3) */
#endif
#if (NUM_USB_CHAN_IN > 3)
                0x0000000F,         /* bmaControls(4) */
#endif
#if (NUM_USB_CHAN_IN > 4)
                0x0000000F,         /* bmaControls(5) */
#endif
#if (NUM_USB_CHAN_IN > 5)
                0x0000000F,         /* bmaControls(6) */
#endif
#if (NUM_USB_CHAN_IN > 6)
                0x0000000F,         /* bmaControls(7) */
#endif
#if (NUM_USB_CHAN_IN > 7)
                0x0000000F,         /* bmaControls(8) */
#endif
#if (NUM_USB_CHAN_IN > 8)
                0x0000000F,         /* bmaControls(9) */
#endif
#if (NUM_USB_CHAN_IN > 9)
                0x0000000F,         /* bmaControls(10) */
#endif
#if (NUM_USB_CHAN_IN > 10)
                0x0000000F,         /* bmaControls(11) */
#endif
#if (NUM_USB_CHAN_IN > 11)
                0x0000000F,         /* bmaControls(12) */
#endif
#if (NUM_USB_CHAN_IN > 12)
                0x0000000F,         /* bmaControls(13) */
#endif
#if (NUM_USB_CHAN_IN > 13)
                0x0000000F,         /* bmaControls(14) */
#endif
#if (NUM_USB_CHAN_IN > 14)
                0x0000000F,         /* bmaControls(15) */
#endif
#if (NUM_USB_CHAN_IN > 15)
                0x0000000F,         /* bmaControls(16) */
#endif
#if (NUM_USB_CHAN_IN > 16)
                0x0000000F,         /* bmaControls(17) */
#endif
#if (NUM_USB_CHAN_IN > 17)
                0x0000000F,         /* bmaControls(18) */
#endif
#if (NUM_USB_CHAN_IN > 18)
#error NUM_USB_CHAN_IN > 18
#endif
            },
            0,                             /* 60 iFeature */
        },
#endif

        .Audio_In_OutputTerminal =
        {
            /* Output Terminal Descriptor (USB Streaming) */
            .bLength                   = 0x0C,
            .bDescriptorType           = UAC_CS_DESCTYPE_INTERFACE,
            .bDescriptorSubtype        =  UAC_CS_AC_INTERFACE_SUBTYPE_OUTPUT_TERMINAL,
            .bTerminalID               = ID_OT_USB,
            .wTerminalType             = USB_TERMTYPE_USB_STREAMING,
            .bAssocTerminal            = 0x00,
#if (INPUT_VOLUME_CONTROL == 1)
            .bSourceID                 = FU_USBIN,                   /* 7  bSourceID Connect to analog input feature unit*/
#else

            .bSourceID                 = ID_IT_USB,                  /* 7  bSourceID Connect to analog input term */
#endif
            .bCSourceID                = ID_CLKSEL,
            .bmControls                = 0x0000,
            .iTerminal                 = offsetof(StringDescTable_t, usbOutputTermStr_Audio2)/sizeof(char *)
        },
#endif
    }, /* End of .Audio_CS_Control_Int */

#if (NUM_USB_CHAN_OUT > 0)
    /* Zero bandwith alternative 0 */
    /* Standard AS Interface Descriptor (4.9.1) */
    .Audio_Out_StreamInterface_Alt0 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_OUTPUT,    /* 2  bInterfaceNumber: Number of interface */
        0,                                /* 3  bAlternateSetting */
        0,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        UAC_INT_PROTOCOL_IP_VERSION_02_00,/* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        4,                                /* 8  iInterface: (Sting index) */
    },

    /* Alternative 1 */
    /* Standard AS Interface Descriptor (4.9.1) (Alt) */
    .Audio_Out_StreamInterface_Alt1 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_OUTPUT,    /* 2  bInterfaceNumber: Number of interface */
        1,                                /* 3  bAlternateSetting */
        2,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        UAC_INT_PROTOCOL_IP_VERSION_02_00,/* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        4,                                /* 8  iInterface: (Sting index) */
     },
    /* STREAMING_OUTPUT_ALT1_OFFSET: */
    /* Class Specific AS Interface Descriptor */
    .Audio_Out_ClassStreamInterface =
    {
        0x10,                             /* 0  bLength: 16 */
        UAC_CS_DESCTYPE_INTERFACE,                     /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_AS_GENERAL,                       /* 2  bDescriptorSubType */
        ID_IT_USB,                        /* 3  bTerminalLink (Linked to USB input terminal) */
        0x00,                             /* 4  bmControls */
        UAC_FORMAT_TYPE_I,                /* 5  bFormatType */
        STREAM_FORMAT_OUTPUT_1_DATAFORMAT,/* 6:10  bmFormats (note this is a bitmap) */
        NUM_USB_CHAN_OUT,                 /* 11 bNrChannels */
        0x00000000,                       /* 12:14: bmChannelConfig */
        .iChannelNames                 = offsetof(StringDescTable_t, outputChanStr_1)/sizeof(char *),
    },

    /* Type 1 Format Type Descriptor */
    .Audio_Out_Format =
    {
        0x06,                           /* 0  bLength (in bytes): 6 */
        UAC_CS_DESCTYPE_INTERFACE,                   /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_FORMAT_TYPE,                    /* 2  bDescriptorSubtype: FORMAT_TYPE */
        UAC_FORMAT_TYPE_I,                  /* 3  bFormatType: FORMAT_TYPE_1 */
        .bSubslotSize                  = HS_STREAM_FORMAT_OUTPUT_1_SUBSLOT_BYTES,
        .bBitResolution                = HS_STREAM_FORMAT_OUTPUT_1_RESOLUTION_BITS,
    },

    /* Standard AS Isochronous Audio Data Endpoint Descriptor (4.10.1.1) */
    .Audio_Out_Endpoint =
    {
        .bLength                        = sizeof(USB_Descriptor_Endpoint_t),
        .bDescriptorType                = USB_DESCTYPE_ENDPOINT,
        .bEndpointAddress               = 0x01,     /* (D7: 0:out, 1:in) */
        .bmAttributes                   = 0x05,     /* (bitmap)  */
        .wMaxPacketSize                 = HS_STREAM_FORMAT_OUTPUT_1_MAXPACKETSIZE,
        .bInterval                      = 1,
    },

    /* Class-Specific AS Isochronous Audio Data Endpoint Descriptor (4.10.1.2) */
    .Audio_Out_ClassEndpoint =
    {
        0x08,                             /* 0   bLength */
        UAC_CS_DESCTYPE_ENDPOINT,         /* 1   bDescriptorType */
        0x01,                             /* 2   bDescriptorSubtype */
        0x00,                             /* 3   bmAttributes */
        0x00,                             /* 4   bmControls (Bitmap: Pitch control, over/underun etc) */
        0x02,                             /* 5   bLockDelayUnits: Decoded PCM samples */
        0x0008,                           /* 6:7 bLockDelay */
    },

    .Audio_Out_Fb_Endpoint =
    {
        0x07,                             /* 0  bLength: 7 */
        USB_DESCTYPE_ENDPOINT,            /* 1  bDescriptorType: ENDPOINT */
        0x81,                             /* 2  bEndpointAddress (D7: 0:out, 1:in) */
        17,                               /* 3  bmAttributes (bitmap)  */
        0x0004,                           /* 4  wMaxPacketSize */
        4,                                /* 6  bInterval. Only values <= 1 frame (4) supported by MS */
    },
#if (OUTPUT_FORMAT_COUNT > 1)
    /* Standard AS Interface Descriptor (4.9.1) (Alt) */
    .Audio_Out_StreamInterface_Alt2 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_OUTPUT,    /* 2  bInterfaceNumber: Number of interface */
        2,                                /* 3  bAlternateSetting */
        2,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        UAC_INT_PROTOCOL_IP_VERSION_02_00,/* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        4,                                /* 8  iInterface: (Sting index) */
     },

    /* Class Specific AS Interface Descriptor */
    .Audio_Out_ClassStreamInterface_2 =
    {
        0x10,                             /* 0  bLength: 16 */
        UAC_CS_DESCTYPE_INTERFACE,        /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_AS_GENERAL, /* 2  bDescriptorSubType */
        ID_IT_USB,                        /* 3  bTerminalLink (Linked to USB input terminal) */
        0x00,                             /* 4  bmControls */
        UAC_FORMAT_TYPE_I,                /* 5  bFormatType */
        STREAM_FORMAT_OUTPUT_2_DATAFORMAT,/* 6:10  bmFormats (note this is a bitmap) */
        NUM_USB_CHAN_OUT,                 /* 11 bNrChannels */
        0x00000000,                       /* 12:14: bmChannelConfig */
        .iChannelNames                 = (offsetof(StringDescTable_t, outputChanStr_1)/sizeof(char *)),
    },

    /* Type 1 Format Type Descriptor */
    .Audio_Out_Format_2 =
    {
        0x06,                             /* 0  bLength (in bytes): 6 */
        UAC_CS_DESCTYPE_INTERFACE,        /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_FORMAT_TYPE,/* 2  bDescriptorSubtype: FORMAT_TYPE */
        UAC_FORMAT_TYPE_I,                /* 3  bFormatType: FORMAT_TYPE_1 */
        .bSubslotSize                  = HS_STREAM_FORMAT_OUTPUT_2_SUBSLOT_BYTES,
        .bBitResolution                = HS_STREAM_FORMAT_OUTPUT_2_RESOLUTION_BITS,
    },
    /* Standard AS Isochronous Audio Data Endpoint Descriptor (4.10.1.1) */
    .Audio_Out_Endpoint_2 =
    {
        .bLength                        = sizeof(USB_Descriptor_Endpoint_t),
        .bDescriptorType                = USB_DESCTYPE_ENDPOINT,
        .bEndpointAddress               = 0x01,
        .bmAttributes                   = 0x05,
        .wMaxPacketSize                 = HS_STREAM_FORMAT_OUTPUT_2_MAXPACKETSIZE,
        .bInterval                      = 1,
    },

    /* Class-Specific AS Isochronous Audio Data Endpoint Descriptor (4.10.1.2) */
    .Audio_Out_ClassEndpoint_2 =
    {
        0x08,                             /* 0   bLength */
        UAC_CS_DESCTYPE_ENDPOINT,         /* 1   bDescriptorType */
        0x01,                             /* 2   bDescriptorSubtype */
        0x00,                             /* 3   bmAttributes */
        0x00,                             /* 4   bmControls (Bitmap: Pitch control, over/underun etc) */
        0x02,                             /* 5   bLockDelayUnits: Decoded PCM samples */
        0x0008,                           /* 6:7 bLockDelay */
    },

    .Audio_Out_Fb_Endpoint_2 =
    {
        0x07,                             /* 0  bLength: 7 */
        USB_DESCTYPE_ENDPOINT,            /* 1  bDescriptorType: ENDPOINT */
        0x81,                             /* 2  bEndpointAddress (D7: 0:out, 1:in) */
        17,                               /* 3  bmAttributes (bitmap)  */
        0x0004,                           /* 4  wMaxPacketSize */
        4,                                /* 6  bInterval. Only values <= 1 frame (4) supported by MS */
    },
#endif
#if (OUTPUT_FORMAT_COUNT > 2)
    /* Standard AS Interface Descriptor (4.9.1) (Alt) */
    .Audio_Out_StreamInterface_Alt3 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_OUTPUT,    /* 2  bInterfaceNumber: Number of interface */
        3,                                /* 3  bAlternateSetting */
        2,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        UAC_INT_PROTOCOL_IP_VERSION_02_00,/* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        4,                                /* 8  iInterface: (Sting index) */
     },

    /* Class Specific AS Interface Descriptor */
    .Audio_Out_ClassStreamInterface_3 =
    {
        0x10,                             /* 0  bLength: 16 */
        UAC_CS_DESCTYPE_INTERFACE,        /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_AS_GENERAL, /* 2  bDescriptorSubType */
        ID_IT_USB,                        /* 3  bTerminalLink (Linked to USB input terminal) */
        0x00,                             /* 4  bmControls */
        UAC_FORMAT_TYPE_I,                /* 5  bFormatType */
        STREAM_FORMAT_OUTPUT_3_DATAFORMAT,/* 6:10  bmFormats (note this is a bitmap) */
        NUM_USB_CHAN_OUT,                 /* 11 bNrChannels */
        0x00000000,                       /* 12:14: bmChannelConfig */
        .iChannelNames                 = offsetof(StringDescTable_t, outputChanStr_1)/sizeof(char *),
    },

    /* Type 1 Format Type Descriptor */
    .Audio_Out_Format_3 =
    {
        .bLength                       = 0x06,
        .bDescriptorType               = UAC_CS_DESCTYPE_INTERFACE,
        .bDescriptorSubtype            = UAC_CS_AS_INTERFACE_SUBTYPE_FORMAT_TYPE,
        .bFormatType                   = UAC_FORMAT_TYPE_I,
        .bSubslotSize                  = HS_STREAM_FORMAT_OUTPUT_3_SUBSLOT_BYTES,
        .bBitResolution                = HS_STREAM_FORMAT_OUTPUT_3_RESOLUTION_BITS,
    },

    /* Standard AS Isochronous Audio Data Endpoint Descriptor (4.10.1.1) */
    .Audio_Out_Endpoint_3 =
    {
        .bLength                       = 0x07,
        .bDescriptorType               = USB_DESCTYPE_ENDPOINT,
        .bEndpointAddress              = 0x01,
        .bmAttributes                  = 0x05,
        .wMaxPacketSize                = HS_STREAM_FORMAT_OUTPUT_3_MAXPACKETSIZE,
        .bInterval                     = 1,
    },

    /* Class-Specific AS Isochronous Audio Data Endpoint Descriptor (4.10.1.2) */
    .Audio_Out_ClassEndpoint_3 =
    {
        .bLength                       = 0x08,
        .bDescriptorType               = UAC_CS_DESCTYPE_ENDPOINT,
        .bDescriptorSubtype            = 0x01,
        .bmAttributes                  = 0x00,
        .bmControls                    = 0x00,                       /* (Bitmap: Pitch control, over/underun etc) */
        .bLockDelayUnits               = 0x02,                       /* Decoded PCM samples */
        .wLockDelay                    = 0x0008,
    },

    .Audio_Out_Fb_Endpoint_3 =
    {
        .bLength                       = 0x07,
        .bDescriptorType               = USB_DESCTYPE_ENDPOINT,
        .bEndpointAddress              = 0x81,
        .bmAttributes                  = 17,                      /* (bitmap)  */
        .wMaxPacketSize                = 0x0004,
        .bInterval                     = 4,                       /* Only values <= 1 frame (4) supported by MS */
    },
#endif /* OUTPUT_FORMAT_COUNT > 2 */
#endif /* OUTPUT */
#if (NUM_USB_CHAN_IN > 0)

    /* Zero bandwith alternative 0 */
    /* Standard AS Interface Descriptor (4.9.1) */
    .Audio_In_StreamInterface_Alt0 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_INPUT,     /* 2  bInterfaceNumber: Number of interface */
        0,                                /* 3  bAlternateSetting */
        0,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        0x20,                             /* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        5,                                /* 8  iInterface: (Sting index) */
    },

    /* Alternative 1 */
    /* Standard AS Interface Descriptor (4.9.1) (Alt) */
    .Audio_In_StreamInterface_Alt1 =
    {
        0x09,                             /* 0  bLength: (in bytes, 9) */
        USB_DESCTYPE_INTERFACE,           /* 1  bDescriptorType: INTERFACE */
        INTERFACE_NUMBER_AUDIO_INPUT,     /* 2  bInterfaceNumber: Number of interface */
        1,                                /* 3  bAlternateSetting */
        1,                                /* 4  bNumEndpoints */
        USB_CLASS_AUDIO,                  /* 5  bInterfaceClass: AUDIO */
        UAC_INT_SUBCLASS_AUDIOSTREAMING,  /* 6  bInterfaceSubClass: AUDIO_STREAMING */
        UAC_INT_PROTOCOL_IP_VERSION_02_00,/* 7  bInterfaceProtocol: IP_VERSION_02_00 */
        5,                                /* 8  iInterface: (Sting index) */
    },

    /* Class Specific AS Interface Descriptor */
    .Audio_In_ClassStreamInterface =
    {
        0x10,                             /* 0  bLength: 16 */
        UAC_CS_DESCTYPE_INTERFACE,        /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_AS_GENERAL, /* 2  bDescriptorSubType */
        ID_OT_USB,                        /* 3  bTerminalLink */
        0x00,                             /* 4  bmControls */
        0x01,                             /* 5  bFormatType */
        UAC_FORMAT_TYPEI_PCM,             /* 6:10  bmFormats (note this is a bitmap) */
        NUM_USB_CHAN_IN,                  /* 11 bNrChannels */
        0x00000000,                       /* 12:14: bmChannelConfig */
        .iChannelNames                 = offsetof(StringDescTable_t, inputChanStr_1)/sizeof(char *),
    },

    /* Type 1 Format Type Descriptor */
    .Audio_In_Format =
    {
        0x06,                                   /* 0  bLength (in bytes): 6 */
        UAC_CS_DESCTYPE_INTERFACE,              /* 1  bDescriptorType: 0x24 */
        UAC_CS_AS_INTERFACE_SUBTYPE_FORMAT_TYPE,/* 2  bDescriptorSubtype: FORMAT_TYPE */
        UAC_FORMAT_TYPE_I,                      /* 3  bFormatType: FORMAT_TYPE_1 */
        .bSubslotSize                  = HS_STREAM_FORMAT_INPUT_1_SUBSLOT_BYTES,                /* 4  bSubslotSize (Number of bytes per subslot) */
        .bBitResolution                = HS_STREAM_FORMAT_INPUT_1_RESOLUTION_BITS,
    },

    /* Standard AS Isochronous Audio Data Endpoint Descriptor (4.10.1.1) */
    .Audio_In_Endpoint =
    {
        0x07,                          /* 0  bLength: 7 */
        USB_DESCTYPE_ENDPOINT,         /* 1  bDescriptorType: ENDPOINT */
        0x82,                          /* 2  bEndpointAddress (D7: 0:out, 1:in) */
        5,                             /* 3  bmAttributes (bitmap)  */
        .wMaxPacketSize                = HS_STREAM_FORMAT_INPUT_1_MAXPACKETSIZE,
        .bInterval                     = 0x01,
    },

    /* Class-Specific AS Isochronous Audio Data Endpoint Descriptor (4.10.1.2) */
    .Audio_In_ClassEndpoint =
    {
        .bLength                       = sizeof(USB_Descriptor_Audio_Class_AS_Endpoint_t),
        .bDescriptorType               = UAC_CS_DESCTYPE_ENDPOINT,
        .bDescriptorSubtype            = UAC_CS_ENDPOINT_SUBTYPE_EP_GENERAL,
        .bmAttributes                  = 0x00,
        .bmControls                    = 0x00,
        .bLockDelayUnits               = 0x02,
        .wLockDelay                    = 0x0008,
    },
#endif

#ifdef MIDI

#if 0
    /* MIDI Descriptors */
    /* Table B-3: MIDI Adapter Standard AC Interface Descriptor */
        {0x09,                              /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x04,                              /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
        INTERFACE_NUMBER_MIDI_CONTROL,     /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
        0x00,                              /* 3 bAlternateSetting : Index of this setting. (field size 1 bytes) */
        0x00,                              /* 4 bNumEndpoints : 0 endpoints. (field size 1 bytes) */
        0x01,                              /* 5 bInterfaceClass : AUDIO. (field size 1 bytes) */
        0x01,                              /* 6 bInterfaceSubclass : AUDIO_CONTROL. (field size 1 bytes) */
        0x00,                              /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
        0x00,                              /* 8 iInterface : Unused. (field size 1 bytes) */

    /* Table B-4: MIDI Adapter Class-specific AC Interface Descriptor */
        0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : 0x24. (field size 1 bytes) */
        0x01,                            /* 2 bDescriptorSubtype : HEADER subtype. (field size 1 bytes) */
        0x00,                            /* 3 bcdADC : Revision of class specification - 1.0 (field size 2 bytes) */
        0x01,                            /* 4 bcdADC */
        0x09,                            /* 5 wTotalLength : Total size of class specific descriptors. (field size 2 bytes) */
        0x00,                            /* 6 wTotalLength */
        0x01,                            /* 7 bInCollection : Number of streaming interfaces. (field size 1 bytes) */
        0x01,                            /* 8 baInterfaceNr(1) : MIDIStreaming interface 1 belongs to this AudioControl interface */

    /* Table B-5: MIDI Adapter Standard MS Interface Descriptor */
        0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x04,                            /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
        INTERFACE_NUMBER_MIDI_STREAM,    /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
        0x00,                            /* 3 bAlternateSetting : Index of this alternate setting. (field size 1 bytes) */
        0x02,                            /* 4 bNumEndpoints : 2 endpoints. (field size 1 bytes) */
        0x01,                            /* 5 bInterfaceClass : AUDIO. (field size 1 bytes) */
        0x03,                            /* 6 bInterfaceSubclass : MIDISTREAMING. (field size 1 bytes) */
        0x00,                            /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
        0x00,                            /* 8 iInterface : Unused. (field size 1 bytes) */

    /* Table B-6: MIDI Adapter Class-specific MS Interface Descriptor */
        0x07,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x01,                            /* 2 bDescriptorSubtype : MS_HEADER subtype. (field size 1 bytes) */
        0x00,                            /* 3 BcdADC : Revision of this class specification. (field size 2 bytes) */
        0x01,                            /* 4 BcdADC */
        0x41,                            /* 5 wTotalLength : Total size of class-specific descriptors. (field size 2 bytes) */
        0x00,                            /* 6 wTotalLength */

    /* Table B-7: MIDI Adapter MIDI IN Jack Descriptor (Embedded) */
        0x06,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
        0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
        0x01,                            /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        0x00,                            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-8: MIDI Adapter MIDI IN Jack Descriptor (External) */
        0x06,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
        0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
        0x02,                            /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        offsetof(StringDescTable_t, midiInStr)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-9: MIDI Adapter MIDI OUT Jack Descriptor (Embedded) */
        0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
        0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
        0x03,                            /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
        0x02,                            /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
        0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entityt o which this Input Pin is connected. */
        0x00,                            /* 8 iJack : Unused. (field size 1 bytes) */

    /* Table B-10: MIDI Adapter MIDI OUT Jack Descriptor (External) */
        0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
        0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
        0x04,                            /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
        0x01,                            /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
        0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entity to which this Input Pin is connected. */
        offsetof(StringDescTable_t, midiOutStr)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-11: MIDI Adapter Standard Bulk OUT Endpoint Descriptor */
        0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x05,                            /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
        ENDPOINT_ADDRESS_OUT_MIDI,       /* 2 bEndpointAddress : OUT Endpoint 3. (field size 1 bytes) */
        0x02,                            /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
        0x00,                            /* 4 wMaxPacketSize : 512 bytes per packet. (field size 2 bytes) - has to be 0x200 for compliance*/
        0x02,                            /* 5 wMaxPacketSize */
        0x00,                            /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
        0x00,                            /* 7 bRefresh : Unused. (field size 1 bytes) */
        0x00,                            /* 8 bSynchAddress : Unused. (field size 1 bytes) */

    /* Table B-12: MIDI Adapter Class-specific Bulk OUT Endpoint Descriptor */
        0x05,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x25,                            /* 1 bDescriptorType : CS_ENDPOINT descriptor (field size 1 bytes) */
        0x01,                            /* 2 bDescriptorSubtype : MS_GENERAL subtype. (field size 1 bytes) */
        0x01,                            /* 3 bNumEmbMIDIJack : Number of embedded MIDI IN Jacks. (field size 1 bytes) */
        0x01,                            /* 4 BaAssocJackID(1) : ID of the Embedded MIDI IN Jack. (field size 1 bytes) */

    /* Table B-13: MIDI Adapter Standard Bulk IN Endpoint Descriptor */
        0x09,                              /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x05,                              /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
        ENDPOINT_ADDRESS_IN_MIDI,          /* 2 bEndpointAddress : IN Endpoint 3. (field size 1 bytes) */
        0x02,                              /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
        0x00,                              /* 4 wMaxPacketSize : 512 bytes per packet. (field size 2 bytes) - has to be 0x200 for compliance*/
        0x02,                              /* 5 wMaxPacketSize */
        0x00,                              /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
        0x00,                              /* 7 bRefresh : Unused. (field size 1 bytes) */
        0x00,                              /* 8 bSynchAddress : Unused. (field size 1 bytes) */

    /* Table B-14: MIDI Adapter Class-specific Bulk IN Endpoint Descriptor */
        0x05,                              /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x25,                              /* 1 bDescriptorType : CS_ENDPOINT descriptor (field size 1 bytes) */
        0x01,                              /* 2 bDescriptorSubtype : MS_GENERAL subtype. (field size 1 bytes) */
        0x01,                              /* 3 bNumEmbMIDIJack : Number of embedded MIDI OUT Jacks. (field size 1 bytes) */
        0x03,                              /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
        },

#else


/* MIDI Descriptors */
/* Table B-3: MIDI Adapter Standard AC Interface Descriptor */
    {0x09,                             /*0 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x04,                              /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
    INTERFACE_NUMBER_MIDI_CONTROL,     /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
    0x00,                              /* 3 bAlternateSetting : Index of this setting. (field size 1 bytes) */
    0x00,                              /* 4 bNumEndpoints : 0 endpoints. (field size 1 bytes) */
    0x01,                              /* 5 bInterfaceClass : AUDIO. (field size 1 bytes) */
    0x01,                              /* 6 bInterfaceSubclass : AUDIO_CONTROL. (field size 1 bytes) */
    0x00,                              /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
    0x00,                              /* 8 iInterface : Unused. (field size 1 bytes) */

/* Table B-4: MIDI Adapter Class-specific AC Interface Descriptor */
    0x09,                            /*9 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : 0x24. (field size 1 bytes) */
    0x01,                            /* 2 bDescriptorSubtype : HEADER subtype. (field size 1 bytes) */
    0x00,                            /* 3 bcdADC : Revision of class specification - 1.0 (field size 2 bytes) */
    0x01,                            /* 4 bcdADC */
    0x09,                            /* 5 wTotalLength : Total size of class specific descriptors. (field size 2 bytes) */
    0x00,                            /* 6 wTotalLength */
    0x01,                            /* 7 bInCollection : Number of streaming interfaces. (field size 1 bytes) */
    0x01,                            /* 8 baInterfaceNr(1) : MIDIStreaming interface 1 belongs to this AudioControl interface */

/* Table B-5: MIDI Adapter Standard MS Interface Descriptor */
    0x09,                            /*18 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x04,                            /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
    INTERFACE_NUMBER_MIDI_STREAM,    /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
    0x00,                            /* 3 bAlternateSetting : Index of this alternate setting. (field size 1 bytes) */
    0x02,                            /* 4 bNumEndpoints : 2 endpoints. (field size 1 bytes) */
    0x01,                            /* 5 bInterfaceClass : AUDIO. (field size 1 bytes) */
    0x03,                            /* 6 bInterfaceSubclass : MIDISTREAMING. (field size 1 bytes) */
    0x00,                            /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
    0x00,                            /* 8 iInterface : Unused. (field size 1 bytes) */

/* Table B-6: MIDI Adapter Class-specific MS Interface Descriptor */
    0x07,                            /*27 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
    0x01,                            /* 2 bDescriptorSubtype : MS_HEADER subtype. (field size 1 bytes) */
    0x00,                            /* 3 BcdADC : Revision of this class specification. (field size 2 bytes) */
    0x01,                            /* 4 BcdADC */
    0x41,                            /* 5 wTotalLength : Total size of class-specific descriptors. (field size 2 bytes) */
    0x00,                            /* 6 wTotalLength */


/* Table B-7: MIDI Adapter MIDI IN Jack Descriptor (Embedded) */
    0x06,                            /*34 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
    0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
    0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
    JACK_ID1,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
    offsetof(StringDescTable_t, midiInStr1)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

/* Table B-8: MIDI Adapter MIDI IN Jack Descriptor (External) */
    0x06,                            /*40 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
    0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
    0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
    JACK_ID2,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
    offsetof(StringDescTable_t, midiInStr1)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

/* Table B-9: MIDI Adapter MIDI OUT Jack Descriptor (Embedded) */
    0x09,                            /*46 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
    0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
    0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
    JACK_ID3,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
    0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
    SOURCE_ID2,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
    0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entityt o which this Input Pin is connected. */
    offsetof(StringDescTable_t, midiOutStr1)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

/* Table B-10: MIDI Adapter MIDI OUT Jack Descriptor (External) */
    0x09,                            /*55 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
    0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
    0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
    JACK_ID4,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
    0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
    SOURCE_ID1,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
    0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entity to which this Input Pin is connected. */
    offsetof(StringDescTable_t, midiOutStr1)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

#if NUM_MIDI_JACKS>1
    /* Table B-7: MIDI Adapter MIDI IN Jack Descriptor (Embedded) */
        0x06,                            /*64 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
        0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
        JACK_ID5,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        offsetof(StringDescTable_t, midiInStr2)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-8: MIDI Adapter MIDI IN Jack Descriptor (External) */
        0x06,                            /*70 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
        0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
        JACK_ID6,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        offsetof(StringDescTable_t, midiInStr2)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-9: MIDI Adapter MIDI OUT Jack Descriptor (Embedded) */
        0x09,                            /*76 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
        0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
        JACK_ID7,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
        SOURCE_ID6,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
        0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entityt o which this Input Pin is connected. */
        offsetof(StringDescTable_t, midiOutStr2)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

    /* Table B-10: MIDI Adapter MIDI OUT Jack Descriptor (External) */
        0x09,                            /*85 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
        0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
        0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
        JACK_ID8,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
        0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
        SOURCE_ID5,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
        0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entity to which this Input Pin is connected. */
        offsetof(StringDescTable_t, midiOutStr2)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */
#endif
#if NUM_MIDI_JACKS>2
        /* Table B-7: MIDI Adapter MIDI IN Jack Descriptor (Embedded) */
            0x06,                            /*64 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
            0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
            0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
            0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
            JACK_ID9,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
            offsetof(StringDescTable_t, midiInStr3)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

        /* Table B-8: MIDI Adapter MIDI IN Jack Descriptor (External) */
            0x06,                            /*70 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
            0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
            0x02,                            /* 2 bDescriptorSubtype : MIDI_IN_JACK subtype. (field size 1 bytes) */
            0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
            JACK_ID10,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
            offsetof(StringDescTable_t, midiInStr3)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

        /* Table B-9: MIDI Adapter MIDI OUT Jack Descriptor (Embedded) */
            0x09,                            /*76 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
            0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
            0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
            0x01,                            /* 3 bJackType : EMBEDDED. (field size 1 bytes) */
            JACK_ID11,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
            0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
            SOURCE_ID10,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
            0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entityt o which this Input Pin is connected. */
            offsetof(StringDescTable_t, midiOutStr3)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

        /* Table B-10: MIDI Adapter MIDI OUT Jack Descriptor (External) */
            0x09,                            /*85 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
            0x24,                            /* 1 bDescriptorType : CS_INTERFACE. (field size 1 bytes) */
            0x03,                            /* 2 bDescriptorSubtype : MIDI_OUT_JACK subtype. (field size 1 bytes) */
            0x02,                            /* 3 bJackType : EXTERNAL. (field size 1 bytes) */
            JACK_ID12,                        /* 4 bJackID : ID of this Jack. (field size 1 bytes) */
            0x01,                            /* 5 bNrInputPins : Number of Input Pins of this Jack. (field size 1 bytes) */
            SOURCE_ID9,                        /* 6 BaSourceID(1) : ID of the Entity to which this Pin is connected. (field size 1 bytes) */
            0x01,                            /* 7 BaSourcePin(1) : Output Pin number of the Entity to which this Input Pin is connected. */
            offsetof(StringDescTable_t, midiOutStr3)/sizeof(char *),            /* 5 iJack : Unused. (field size 1 bytes) */

#endif

/* Table B-11: MIDI Adapter Standard Bulk OUT Endpoint Descriptor */
    0x09,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x05,                            /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
    ENDPOINT_ADDRESS_OUT_MIDI,       /* 2 bEndpointAddress : OUT Endpoint 3. (field size 1 bytes) */
    0x02,                            /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
    0x00,                            /* 4 wMaxPacketSize : 512 bytes per packet. (field size 2 bytes) - has to be 0x200 for compliance*/
    0x02,                            /* 5 wMaxPacketSize */
    0x00,                            /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
    0x00,                            /* 7 bRefresh : Unused. (field size 1 bytes) */
    0x00,                            /* 8 bSynchAddress : Unused. (field size 1 bytes) */

/* Table B-12: MIDI Adapter Class-specific Bulk OUT Endpoint Descriptor */
    0x04 + NUM_MIDI_JACKS,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x25,                            /* 1 bDescriptorType : CS_ENDPOINT descriptor (field size 1 bytes) */
    0x01,                            /* 2 bDescriptorSubtype : MS_GENERAL subtype. (field size 1 bytes) */
    NUM_MIDI_JACKS,                  /* 3 bNumEmbMIDIJack : Number of embedded MIDI IN Jacks. (field size 1 bytes) */
    JACK_ID1,                            /* 4 BaAssocJackID(1) : ID of the Embedded MIDI IN Jack. (field size 1 bytes) */
#if NUM_MIDI_JACKS>1
    JACK_ID5,                          /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
#endif
#if NUM_MIDI_JACKS>2
    JACK_ID9,                          /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
#endif

/* Table B-13: MIDI Adapter Standard Bulk IN Endpoint Descriptor */
    0x09,                              /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x05,                              /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
    ENDPOINT_ADDRESS_IN_MIDI,          /* 2 bEndpointAddress : IN Endpoint 3. (field size 1 bytes) */
    0x02,                              /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
    0x00,                              /* 4 wMaxPacketSize : 512 bytes per packet. (field size 2 bytes) - has to be 0x200 for compliance*/
    0x02,                              /* 5 wMaxPacketSize */
    0x00,                              /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
    0x00,                              /* 7 bRefresh : Unused. (field size 1 bytes) */
    0x00,                              /* 8 bSynchAddress : Unused. (field size 1 bytes) */

/* Table B-14: MIDI Adapter Class-specific Bulk IN Endpoint Descriptor */
    0x04 + NUM_MIDI_JACKS,                              /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x25,                              /* 1 bDescriptorType : CS_ENDPOINT descriptor (field size 1 bytes) */
    0x01,                              /* 2 bDescriptorSubtype : MS_GENERAL subtype. (field size 1 bytes) */
    NUM_MIDI_JACKS,                    /* 3 bNumEmbMIDIJack : Number of embedded MIDI OUT Jacks. (field size 1 bytes) */
    JACK_ID3,                          /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
#if NUM_MIDI_JACKS>1
    JACK_ID7,                          /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
#endif
#if NUM_MIDI_JACKS>2
    JACK_ID11,                          /* 4 BaAssocJackID(1) : ID of the Embedded MIDI OUT Jack. (field size 1 bytes) */
#endif




    },
#endif

#endif

#ifdef DFU
    /* Standard DFU class Interface descriptor */
    {0x09,                             /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x04,                              /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
    INTERFACE_NUMBER_DFU,              /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
    0x00,                              /* 3 bAlternateSetting : Index of this setting. (field size 1 bytes) */
    0x00,                              /* 4 bNumEndpoints : 0 endpoints. (field size 1 bytes) */
    0xFE,                              /* 5 bInterfaceClass : DFU. (field size 1 bytes) */
    0x01,                              /* 6 bInterfaceSubclass : (field size 1 bytes) */
    0x01,                              /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
    offsetof(StringDescTable_t, dfuStr)/sizeof(char *), /* 8 iInterface */

#if 0
    /* DFU 1.0 Run-Time DFU Functional Descriptor */
    0x07,
    0x21,
    0x07,
    0xFA,
    0x00,
    0x40,
    0x00
#else
    /* DFU 1.1 Run-Time DFU Functional Descriptor */
    0x09,                           /* 0    Size */
    0x21,                           /* 1    bDescriptorType : DFU FUNCTIONAL */
    0x07,                           /* 2    bmAttributes */
    0xFA,                           /* 3    wDetachTimeOut */
    0x00,                           /* 4    wDetachTimeOut */
    0x40,                           /* 5    wTransferSize */
    0x00,                           /* 6    wTransferSize */
    0x10,                           /* 7    bcdDFUVersion */
    0x01},                          /* 7    bcdDFUVersion */
#endif
#endif

#ifdef IAP
    /* Interface descriptor */
    .iAP_Interface =
    {
        .bLength                       = sizeof(USB_Descriptor_Interface_t),
        .bDescriptorType               = USB_DESCTYPE_INTERFACE,
        .bInterfaceNumber              = INTERFACE_NUMBER_IAP,
        .bAlternateSetting             = 0x00,
#ifdef IAP_INT_EP
        .bNumEndpoints                 = 0x03,
#else
        .bNumEndpoints                 = 0x02,
#endif
        .bInterfaceClass               = USB_CLASS_VENDOR_SPECIFIC,
        .bInterfaceSubClass            = 0xF0,                       /* MFI Accessory (Table 38-1) */
        .bInterfaceProtocol            = 0x00,
        .iInterface                    = offsetof(StringDescTable_t, iAPInterfaceStr)/sizeof(char *),   /* Note, string is important! */
    },

    /* iAP Bulk OUT Endpoint Descriptor */
    .iAP_Out_Endpoint =
    {
        0x07,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x05,                            /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
        ENDPOINT_ADDRESS_OUT_IAP,        /* 2 bEndpointAddress : OUT Endpoint 3. High bit isIn (field size 1 bytes) */
        0x02,                            /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
        0x0200,                          /* 4 wMaxPacketSize : Has to be 0x200 for compliance*/
        0x00,                            /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
    },

    /* iAP Bulk IN Endpoint Descriptor */
    .iAP_In_Endpoint =
    {
        0x07,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x05,                            /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
        ENDPOINT_ADDRESS_IN_IAP,         /* 2 bEndpointAddress : IN Endpoint 5. (field size 1 bytes) */
        0x02,                            /* 3 bmAttributes : Bulk, not shared. (field size 1 bytes) */
        0x0200,                          /* 4 wMaxPacketSize : Has to be 0x200 for compliance*/
        0x00,                            /* 6 bInterval : Ignored for Bulk. Set to zero. (field size 1 bytes) */
    },

#ifdef IAP_INT_EP
    /* iAP Interrupt IN Endpoint Descriptor. Note, its usage is now deprecated */
    .iAP_Interrupt_Endpoint =
    {
        0x07,                            /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
        0x05,                            /* 1 bDescriptorType : ENDPOINT descriptor. (field size 1 bytes) */
        ENDPOINT_ADDRESS_IN_IAP_INT,     /* 2 bEndpointAddress : IN Endpoint 6. (field size 1 bytes) */
        0x03,                            /* 3 bmAttributes : Interrupt, not shared. (field size 1 bytes) */
        0x0040,                          /* 4 wMaxPacketSize : 64 bytes per packet. (field size 2 bytes) - has to be 0x40 for compliance*/
        0x08,                            /* 6 bInterval : (2^(bInterval-1))/8 ms. Must be between 4 and 32ms (field size 1 bytes) */
    },
#endif
#endif /* IAP */

#ifdef HID_CONTROLS
    .HID_Interface =
    {
        9,                             /* 0  bLength : Size of descriptor in Bytes */
        4,                             /* 1  bDescriptorType (Interface: 0x04)*/
        INTERFACE_NUMBER_HID,          /* 2  bInterfaceNumber : Number of interface */
        0,                             /* 3  bAlternateSetting : Value used  alternate interfaces using SetInterface Request */
        1,                             /* 4: bNumEndpoints : Number of endpoitns for this interface (excluding 0) */
        3,                             /* 5: bInterfaceClass */
        0,                             /* 6: bInterfaceSubClass - no boot device */
        0,                             /* 7: bInterfaceProtocol*/
        0,                             /* 8  iInterface */
    },

    {
        9,                             /* 0  bLength : Size of descriptor in Bytes */
        0x21,                          /* 1  bDescriptorType (HID) */
        0x10,                          /* 2  bcdHID */
        0x01,                          /* 3  bcdHID */
        0,                             /* 4  bCountryCode */
        1,                             /* 5  bNumDescriptors */
        0x22,                          /* 6  bDescriptorType[0] (Report) */
        sizeof(hidReportDescriptor) & 0xff,/* 7  wDescriptorLength[0] */
        sizeof(hidReportDescriptor) >> 8,  /* 8  wDescriptorLength[0] */
    },

    .HID_In_Endpoint =
    {
        /* Endpoint descriptor (IN) */
        0x7,                           /* 0  bLength */
        5,                             /* 1  bDescriptorType */
        ENDPOINT_ADDRESS_IN_HID,       /* 2  bEndpointAddress  */
        3,                             /* 3  bmAttributes (INTERRUPT) */
        64,                            /* 4  wMaxPacketSize */
        8,                             /* 6  bInterval */
    }
#endif

};
#endif

#ifdef HID_CONTROLS
unsigned char hidDescriptor[] =
{
    9,                             /* 0  bLength : Size of descriptor in Bytes */
    0x21,                          /* 1  bDescriptorType (HID) */
    0x10,                          /* 2  bcdHID */
    0x01,                          /* 3  bcdHID */
    0,                             /* 4  bCountryCode */
    1,                             /* 5  bNumDescriptors */
    0x22,                          /* 6  bDescriptorType[0] (Report) */
    sizeof(hidReportDescriptor) & 0xff,/* 7  wDescriptorLength[0] */
    sizeof(hidReportDescriptor) >> 8,  /* 8  wDescriptorLength[0] */
};
#endif


/* Configuration Descriptor for Null device */
unsigned char cfgDesc_Null[] =
{
    0x09,                           /* 0  bLength */
    USB_DESCTYPE_CONFIGURATION,              /* 1  bDescriptorType */
    0x12,                           /* 2  wTotalLength */
    0x00,                           /* 3  wTotalLength */
    0x01,                           /* 4  bNumInterface: Number of interfaces*/
    0x01,                           /* 5  bConfigurationValue */
    0x00,                           /* 6  iConfiguration */
#ifdef SELF_POWERED
    192,                            /* 7  bmAttributes */
#else
    128,
#endif
    BMAX_POWER,                     /* 8  bMaxPower */

    0x09,                           /* 0 bLength : Size of this descriptor, in bytes. (field size 1 bytes) */
    0x04,                           /* 1 bDescriptorType : INTERFACE descriptor. (field size 1 bytes) */
    0x00,                           /* 2 bInterfaceNumber : Index of this interface. (field size 1 bytes) */
    0x00,                           /* 3 bAlternateSetting : Index of this setting. (field size 1 bytes) */
    0x00,                           /* 4 bNumEndpoints : 0 endpoints. (field size 1 bytes) */
    0x00,                           /* 5 bInterfaceClass :  */
    0x00,                           /* 6 bInterfaceSubclass */
    0x00,                           /* 7 bInterfaceProtocol : Unused. (field size 1 bytes) */
    0x00,                           /* 8 iInterface : Unused. (field size 1 bytes) */
    0x09,                           /* 0  bLength */
};


#if defined (AUDIO_CLASS_FALLBACK) || (AUDIO_CLASS == 1)
/* Configuration descriptor for Audio v1.0 */
/* Note Audio 1.0 descriptors still a simple array so we need some extra defines regarding lengths.. */
#if (NUM_USB_CHAN_IN > 0)
#define INPUT_INTERFACES_A1         (1)
#else
#define INPUT_INTERFACES_A1         (0)
#endif

#if (NUM_USB_CHAN_OUT > 0)
#define OUTPUT_INTERFACES_A1         (1)
#else
#define OUTPUT_INTERFACES_A1         (0)
#endif

#define AC_LENGTH                   (8 + INPUT_INTERFACES_A1 + OUTPUT_INTERFACES_A1)

#define AC_TOTAL_LENGTH             (AC_LENGTH + (INPUT_INTERFACES_A1 * (19 + NUM_FREQS_A1 * 3)) + (OUTPUT_INTERFACES_A1 * (19 + (NUM_FREQS_A1 *3))))
#define STREAMING_INTERFACES        (INPUT_INTERFACES_A1 + OUTPUT_INTERFACES_A1)

/* Number of interfaces for Audio  1.0 (+1 for control ) */
/* Note, this is different that INTERFACE_COUNT since we dont support items such as MIDI, iAP etc in UAC1 mode */
#define NUM_INTERFACES_A1           (1+INPUT_INTERFACES_A1 + OUTPUT_INTERFACES_A1)

#define CFG_TOTAL_LENGTH_A1         (18 + AC_TOTAL_LENGTH + (INPUT_INTERFACES_A1 * 61) + (OUTPUT_INTERFACES_A1 * 70))

/* In UAC1 supported sample rates are listed in descriptor */
#if (MAX_FREQ_FS == 96000)
#define NUM_FREQS_A1                (4)
#elif (MAX_FREQ_FS == 88200)
#define NUM_FREQS_A1                (3)
#elif (MAX_FREQ_FS == 48000)
#define NUM_FREQS_A1                (2)
#elif (MAX_FREQ_FS == 44100)
#define NUM_FREQS_A1                (1)
#else
#error
#endif

unsigned char cfgDesc_Audio1[] =
{
    /* Configuration descriptor */
    0x09,
    USB_DESCTYPE_CONFIGURATION,
    (CFG_TOTAL_LENGTH_A1 & 0xFF),   /* wTotalLength */
    (CFG_TOTAL_LENGTH_A1 >> 8),     /* wTotalLength */
    NUM_INTERFACES_A1,              /* numInterfaces - we dont support MIDI in audio 1.0 mode*/
    0x01,                           /* ID of this configuration */
    0x00,                           /* Unused */
#ifdef SELF_POWERED
    192,                            /* 7  bmAttributes */
#else
    128,                            /* 7  bmAttributes */
#endif
    BMAX_POWER,                     /* 8  bMaxPower */

    /* Standard AC interface descriptor */
    0x09,
    USB_DESCTYPE_INTERFACE,
    0x00,                           /* Interface No */
    0x00,                           /* Alternate setting*/
    0x00,                           /* Num endpoints */
    USB_CLASS_AUDIO,
    UAC_INT_SUBCLASS_AUDIOCONTROL,
    0x00,                           /* Unused */
    8,                              /* iInterface - re-use iProduct */

    /* CS (Class Specific) AudioControl interface header descriptor (4.3.2) */
    AC_LENGTH,
    UAC_CS_DESCTYPE_INTERFACE,
    0x01,                           /* HEADER */
    0x00, 0x01,                     /* Class spec revision - 1.0 */
    (AC_TOTAL_LENGTH & 0xFF),       /* wTotallength (Combined length of this descriptor and all Unit and Terminal Descriptors) */
    (AC_TOTAL_LENGTH >> 8),         /* wTotalLength */
    STREAMING_INTERFACES,           /* Num streaming interfaces */
#if (NUM_USB_CHAN_OUT > 0)
    0x01,                           /* AudioStreaming interface 1 belongs to AC interface */
#endif
#if (NUM_USB_CHAN_IN > 0)
    (OUTPUT_INTERFACES_A1 + 1),     /* AudioStreaming interface 2 belongs to AC interface */
#endif

#if (NUM_USB_CHAN_OUT > 0)
    /* CS_Interface Input Terminal 1 Descriptor - USB streaming Host to Device */
    0x0C,
    UAC_CS_DESCTYPE_INTERFACE,      /* UAC_CS_DESCTYPE_INTERFACE */
    0x02,                           /* INPUT_TERMINAL */
    0x01,                           /* Terminal ID */
    0x01, 0x01,                     /* Type - streaming */
    0x00,                           /* Associated terminal - unused  */
    NUM_USB_CHAN_OUT_FS,            /* bNrChannels */
    0x03, 0x00,                     /* wChannelConfig */
    offsetof(StringDescTable_t, outputChanStr_1)/sizeof(char *), /* iChannelNames */
    11,                             /* iTerminal */

    /* CS_Interface class specific AC interface feature unit descriptor - mute & volume for dac */
    0x0A,
    UAC_CS_DESCTYPE_INTERFACE,
    UAC_CS_AC_INTERFACE_SUBTYPE_FEATURE_UNIT,                   /* 2  bDescriptorSubType: FEATURE_UNIT */
    0x0A,                           /* unitID */
    0x01,                           /* sourceID - ID of the unit/terminal to which this feature unit is connected */
    0x01,                           /* controlSize - 1 */
    0x00,                           /* bmaControls(0) */
    0x03,                           /* bmaControls(1) */
    0x03,                           /* bmaControls(2) */
    0x00,                           /* String table index */

    /* CS_Interface Output Terminal Descriptor - Analog out to speaker */
    0x09,
    UAC_CS_DESCTYPE_INTERFACE,
    0x03,                           /* OUTPUT_TERMINAL */
    0x06,                           /* Terminal ID */
    0x01, 0x03,                     /* Type - streaming out, speaker */
    0x00,                           /* Associated terminal - unused */
    0x0A,                           /* sourceID  */
    0x00,                           /* Unused */
#endif

#if (NUM_USB_CHAN_IN > 0)
    /* CS_Interface Input Terminal 2 Descriptor - Analog in from line in */
    0x0C,
    UAC_CS_DESCTYPE_INTERFACE,
    0x02,                           /* INPUT_TERMINAL */
    0x02,                           /* Terminal ID */
    0x01, 0x02,                     /* Type - streaming in, mic */
    0x00,                           /* Associated terminal - unused  */
    NUM_USB_CHAN_IN_FS,             /* bNrChannels */
    0x03, 0x00,                     /* wChannelConfigs */
    offsetof(StringDescTable_t, inputChanStr_1)/sizeof(char *), /* iChannelNames */
    12,                             /* iTerminal */

    /* CS_Interface Output Terminal Descriptor - USB Streaming Device to Host*/
    0x09,
    UAC_CS_DESCTYPE_INTERFACE,
    0x03,                           /* OUTPUT_TERMINAL */
    0x07,                           /* Terminal ID */
    0x01, 0x01,                     /* Type - streaming */
    0x01,                           /* Associated terminal - unused */
    0x0B,                           /* sourceID - from selector unit ?? */
    0x00,                           /* Unused */

    /* CS_Interface class specific AC interface feature unit descriptor - mute & volume for adc */
    0x0A,
    UAC_CS_DESCTYPE_INTERFACE,
    UAC_CS_AC_INTERFACE_SUBTYPE_FEATURE_UNIT,                   /* 2  bDescriptorSubType: FEATURE_UNIT */
    0x0B,                           /* unitID */
    0x02,                           /* sourceID - ID of the unit/terminal to which this feature unit is connected */
    0x01,                           /* controlSize - 1 */
    0x00,                           /* bmaControls(0) */
    0x03,                           /* bmaControls(1) */
    0x03,                           /* bmaControls(2) */
    0x00,                           /* String table index */
#endif

#if (NUM_USB_CHAN_OUT > 0)
    /* Standard AS Interface Descriptor (4.5.1) */
    0x09,                           /* bLength */
    0x04,                           /* INTERFACE */
    0x01,                           /* bInterfaceNumber */
    0x00,                           /* bAlternateSetting */
    0x00,                           /* bnumEndpoints */
    0x01,                           /* bInterfaceClass - AUDIO */
    0x02,                           /* bInterfaceSubclass - AUDIO_STREAMING */
    0x00,                           /* bInterfaceProtocol - Not used */
    0x09,                           /* iInterface */

    /* Standard As Interface Descriptor (4.5.1) */
    0x09,
    0x04,                           /* INTERFACE */
    0x01,                           /* Interface no */
    0x01,                           /* AlternateSetting */
    0x02,                           /* num endpoints 2: audio EP and feedback EP */
    0x01,                           /* Interface class - AUDIO */
    0x02,                           /* subclass - AUDIO_STREAMING */
    0x00,                           /* Unused */
    0x04,                           /* String table index  */

    /* Class-Specific AS Interface Descriptor (4.5.2) */
    0x07,
    UAC_CS_DESCTYPE_INTERFACE,                   /* bDescriptorType */
    0x01,                           /* bDescriptorSubtype - GENERAL */
    0x01,                           /* iTerminalLink - linked to Streaming IN terminal */
    0x01,                           /* bDelay */
    0x01, 0x00,                     /* wFormatTag - PCM */

    /* CS_Interface Format Type Descriptor */
    (8 + (NUM_FREQS_A1 * 3)),
    UAC_CS_DESCTYPE_INTERFACE,
    0x02,                           /* Subtype - FORMAT_TYPE */
    0x01,                           /* Format type - FORMAT_TYPE_1 */
    NUM_USB_CHAN_OUT_FS,            /* nrChannels */
    FS_STREAM_FORMAT_OUTPUT_1_SUBSLOT_BYTES,         /* subFrameSize */
    FS_STREAM_FORMAT_OUTPUT_1_RESOLUTION_BITS,       /* bitResolution */

    NUM_FREQS_A1,                   /* SamFreqType - sample freq count */
    0x44, 0xAC, 0x00,               /* sampleFreq - 44.1Khz */
#if (MAX_FREQ_FS > 44100)
    0x80, 0xBB, 0x00,               /* sampleFreq - 48KHz */
#endif
#if (MAX_FREQ_FS > 48000)
    0x88, 0x58, 0x01,               /* sampleFreq - 88.2KHz */
#endif
#if (MAX_FREQ_FS > 88200)
    0x00, 0x77, 0x01,               /* sampleFreq - 96KHz */
#endif

    /* Standard AS Isochronous Audio Data Endpoint Descriptor 4.6.1.1 */
    0x09,
    0x05,                           /* ENDPOINT */
    0x01,                           /* endpointAddress - D7, direction (0 OUT, 1 IN). D6..4 reserved (0). D3..0 endpoint no. */
    0x05,                           /* attributes - isochronous async */
    (FS_STREAM_FORMAT_OUTPUT_1_MAXPACKETSIZE&0xff),        /* 4  wMaxPacketSize (Typically 294 bytes)*/
    (FS_STREAM_FORMAT_OUTPUT_1_MAXPACKETSIZE&0xff00)>>8, /* 5  wMaxPacketSize */
    0x01,                           /* bInterval */
    0x00,                           /* bRefresh */
    0x81,                           /* bSynchAdddress - address of EP used to communicate sync info */

    /* CS_Endpoint Descriptor ?? */
    0x07,
    0x25,                           /* CS_ENDPOINT */
    0x01,                           /* subtype - GENERAL */
    0x01,                           /* attributes. D[0]: sample freq ctrl. */
    0x02,                           /* bLockDelayUnits */
    0x00, 0x00,                     /* bLockDelay */

    /* Feedback EP */
    0x09,
    0x05,                           /* bDescriptorType: ENDPOINT */
    0x81,                           /* bEndpointAddress (D3:0 - EP no. D6:4 - reserved 0. D7 - 0:out, 1:in) */
    0x01,                           /* bmAttributes (bitmap)  */
    0x03,0x0,                       /* wMaxPacketSize */
    0x01,                           /* bInterval - Must be 1 for compliance */
    0x04,                           /* bRefresh 2^x */
    0x0,                            /* bSynchAddress */
#endif

#if (NUM_USB_CHAN_IN > 0)
    /* Standard Interface Descriptor - Audio streaming IN */
    0x09,
    0x04,                           /* INTERFACE */
    (OUTPUT_INTERFACES_A1 + 1),     /* bInterfaceNumber*/
    0x00,                           /* AlternateSetting */
    0x00,                           /* num endpoints */
    0x01,                           /* Interface class - AUDIO */
    0x02,                           /* subclass - AUDIO_STREAMING */
    0x00,                           /* Unused */
    0x05,                           /* String table index */

    /* Standard Interface Descriptor - Audio streaming IN */
    0x09,
    0x04,                           /* INTERFACE */
    (OUTPUT_INTERFACES_A1 + 1),     /* bInterfaceNumber */
    0x01,                           /* AlternateSetting */
    0x01,                           /* num endpoints */
    0x01,                           /* Interface class - AUDIO */
    0x02,                           /* Subclass - AUDIO_STREAMING */
    0x00,                           /* Unused */
    0x0A,                           /* String table index */

    /* CS_Interface AC interface header descriptor */
    0x07,
    UAC_CS_DESCTYPE_INTERFACE,
    0x01,                           /* subtype - GENERAL */
    0x07,                           /* TerminalLink - linked to Streaming OUT terminal */
    0x01,                           /* Interface delay */
    0x01,0x00,                      /* Format - PCM */

    /* CS_Interface Terminal Descriptor */
    (8 + (NUM_FREQS_A1 * 3)),
    UAC_CS_DESCTYPE_INTERFACE,
    0x02,                           /* Subtype - FORMAT_TYPE */
    0x01,                           /* Format type - FORMAT_TYPE_1 */
    NUM_USB_CHAN_IN_FS,             /* bNrChannels - Typically 2 */
    FS_STREAM_FORMAT_INPUT_1_SUBSLOT_BYTES,         /* subFrameSize - Typically 4 bytes per slot */
    FS_STREAM_FORMAT_INPUT_1_RESOLUTION_BITS,       /* bitResolution - Typically 24bit */
    NUM_FREQS_A1,                   /* SamFreqType - sample freq count */
    0x44, 0xAC, 0x00,               /* sampleFreq - 44.1Khz */
#if (MAX_FREQ_FS > 44100)
    0x80, 0xBB, 0x00,               /* sampleFreq - 48KHz */
#endif
#if (MAX_FREQ_FS > 48000)
    0x88, 0x58, 0x01,               /* sampleFreq - 88.2KHz */
#endif
#if (MAX_FREQ_FS > 88200)
    0x00, 0x77, 0x01,               /* sampleFreq - 96KHz */
#endif
    /* Standard Endpoint Descriptor */
    0x09,
    0x05,                           /* ENDPOINT */
    0x82,                           /* EndpointAddress */
    0x05,                           /* Attributes - isochronous async */
    FS_STREAM_FORMAT_INPUT_1_MAXPACKETSIZE&0xff,        /* 4  wMaxPacketSize (Typically 294 bytes)*/
    (FS_STREAM_FORMAT_INPUT_1_MAXPACKETSIZE&0xff00)>>8, /* 5  wMaxPacketSize */
    0x01,                           /* bInterval */
    0x00,                           /* bRefresh */
    0x00,                           /* bSynchAddress */

    /* CS_Endpoint Descriptor */
    0x07,
    0x25,                           /* CS_ENDPOINT */
    0x01,                           /* Subtype - GENERAL */
    0x01,                           /* Attributes. D[0]: sample freq ctrl. */
    0x00,                           /* Unused */
    0x00, 0x00,                     /* Unused */
#endif
};

#endif
#endif
