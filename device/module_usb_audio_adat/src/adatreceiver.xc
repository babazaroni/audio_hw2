// GENERATED CODE - DO NOT EDIT
// Comments are in the generator
#include <xs1.h>
#include <stdio.h>
#pragma unsafe arrays
void adatReceiver48000(buffered in port:32 p, chanend oChan) {
    const unsigned int mask = 0x80808080;
    unsigned compressed;
    unsigned nibble, word = 1, fourBits, data;
    int old, violation;
    unsigned int lookupCrcF[16] = {8, 9, 12, 13, 7, 6, 3, 2, 10, 11, 14, 15, 5, 4, 1, 0};
    unsigned int lookupNRTZ[32] = {0, 8, 12, 4, 6, 14, 10, 2, 3, 11, 15, 7, 5, 13, 9, 1,
                          1, 9, 13, 5, 7, 15, 11, 3, 2, 10, 14, 6, 4, 12, 8, 0};
    for(int i =  0; i < 32; i++) { lookupNRTZ[i] <<= 4; }
    do {
        old = word; p :> word;
    } while (word != old || (word != 0 && word+1 != 0));
    while(1) {
        violation = word;
        p when pinsneq(violation) :> int _;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        outuint(oChan, nibble << 4 | 1);
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = old | compressed << 1;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        if (word != 0 && word+1 != 0) return;
    }
}

// GENERATED CODE - DO NOT EDIT
// Comments are in the generator
#include <xs1.h>
#include <stdio.h>
#pragma unsafe arrays
void adatReceiver44100(buffered in port:32 p, chanend oChan) {
    const unsigned int mask = 0x80402010;
    unsigned compressed;
    unsigned nibble, word = 1, fourBits, data;
    int old, violation;
    unsigned int lookupCrcF[16] = {8, 12, 10, 14, 9, 13, 11, 15, 7, 3, 5, 1, 6, 2, 4, 0};
    unsigned int lookupNRTZ[32] = {0, 8, 12, 4, 6, 14, 10, 2, 3, 11, 15, 7, 5, 13, 9, 1,
                          1, 9, 13, 5, 7, 15, 11, 3, 2, 10, 14, 6, 4, 12, 8, 0};
    for(int i =  0; i < 32; i++) { lookupNRTZ[i] <<= 4; }
    do {
        old = word; p :> word;
    } while (word != old || (word != 0 && word+1 != 0));
    while(1) {
        violation = word;
        p when pinsneq(violation) :> int _;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        outuint(oChan, nibble << 4 | 1);
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = old | compressed << 1;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = old | compressed << 1;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = old | compressed << 1;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 7) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 1) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = compressed;
        p :> word;
        fourBits = (word << 3) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = nibble << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        old = old | compressed << 1;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 6) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 3)) & 31];
        old = compressed >> 2;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 4) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 1)) & 31];
        old = compressed >> 4;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 0) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        old = compressed;
        p :> word;
        fourBits = (word << 5) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        compressed = compressed >> 1;
        nibble = lookupNRTZ[(old | (compressed << 4)) & 31];
        old = compressed >> 1;
        data = (data | nibble) << 4;
        p :> word;
        fourBits = (word << 2) & mask;
        crc32(fourBits, 0xf, 0xf);
        compressed = lookupCrcF[fourBits];
        nibble = lookupNRTZ[(old | (compressed << 2)) & 31];
        old = compressed >> 3;
        data = (data | nibble) << 4;
        outuint(oChan, data);
        p :> word;
        if (word != 0 && word+1 != 0) return;
    }
}

