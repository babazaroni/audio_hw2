
#include "AK4612.h"


i2c_block_entry init_ak4612_48k_vals [] = {
        {REG_CONTROL_1,{TDM_MODE_1_TDM512 | MODE_23 | DIGITAL_ATTENUATOR_TRANSITION_4096 | SOFT_MUTE_DAC_FALSE}},
        {REG_CONTROL_2,{MCKO_ENABLE_TRUE | CK_512_256_128 | SAMPLE_NORMAL_SPEED_MODE | ACKS_DISABLE | DIV_2}}
//        {0x0B,{0}},
//        {0x0C,{0}},
//        {0x0D,{0}},
//        {0x0E,{0}},
//        {0x0F,{0}},
//        {0x10,{0}},
//        {0x11,{0}},
//        {0x12,{0}}
};

i2c_block_entry init_ak4612_48k_tdm512_vals [] = {
        {REG_CONTROL_1,{TDM_MODE_1_TDM512 | MODE_23 | DIGITAL_ATTENUATOR_TRANSITION_4096 | SOFT_MUTE_DAC_FALSE}},
        {REG_CONTROL_2,{MCKO_ENABLE_TRUE | CK_512_256_128 | SAMPLE_NORMAL_SPEED_MODE | ACKS_DISABLE | DIV_1}}
//        {0x0B,{0}},
//        {0x0C,{0}},
//        {0x0D,{0}},
//        {0x0E,{0}},
//        {0x0F,{0}},
//        {0x10,{0}},
//        {0x11,{0}},
//        {0x12,{0}}
};


i2c_block_entry init_ak4612_96k_vals [] = {
        {REG_CONTROL_1,{TDM_MODE_2_TDM256 | MODE_23 | DIGITAL_ATTENUATOR_TRANSITION_4096 | SOFT_MUTE_DAC_FALSE}},
        {REG_CONTROL_2,{MCKO_ENABLE_TRUE | CK_512_256_128 | SAMPLE_DOUBLE_SPEED_MODE | ACKS_DISABLE | DIV_1}}
//        {0x0B,{0}},
//        {0x0C,{0}},
//        {0x0D,{0}},
//        {0x0E,{0}},
//        {0x0F,{0}},
//        {0x10,{0}},
//        {0x11,{0}},
//        {0x12,{0}}
};

#ifdef UNUSED

MODE_23 = TDM_MODE_2_TDM256 = TDM1,TDM0 = 10h


CK_512_256_128 = CKS0,CKS1 = 10h
SAMPLE_NORMAL_SPEED_MODE = 0h


TDM1  TDM0  DIF2  DIF1  DIF0  ATS1  ATS0  SMUTE
  1     0     1     0     0     0     0    0


0     MCKO  CKS1  CKS0  DFS1  DFS0  ACKS  DIV
0       1     1     0     0     0    0    0
                D7      D6      D5      D4      D3      D2      D1      D0
                TDM1    TDM0    DIF2    DIF1    DIF0    ATS1    ATS0    SMUTE
03 98           1       0       0       1       1       0       0       0
                0       MCKO    CKS1    CKS0    DFS1    DFS0    ACKS    DIV
04 64           0       1       1       0       0       1       0       0

Sustainer

                TDM1    TDM0    DIF2    DIF1    DIF0    ATS1    ATS0    SMUTE
03 58           0       1       0       1       1       0       0       0
                0       MCKO    CKS1    CKS0    DFS1    DFS0    ACKS    DIV
04 30           0       0       1       1       0       0       0       0

#endif
