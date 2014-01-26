//
//  FHT2.h
//  LIT Headband Simulator
//
//  Created by Daniel Kern on 1/25/14.
//  Copyright (c) 2014 Ryan Tuck. All rights reserved.
//

#ifndef __LIT_Headband_Simulator__FHT2__
#define __LIT_Headband_Simulator__FHT2__

//setup for FHT2
#define LOG_OUT 1 // use the log output function
#define FHT_N 256 // set to 256 point fht

#define STRINGIFY_(a) #a
#define STRINGIFY(a) STRINGIFY_(a)

#ifndef FHT_N // number of samples
#define FHT_N 256
#endif

#ifndef SCALE // scaling factor for lin8 output function
#define SCALE 1
#endif

#ifndef WINDOW // wether using the window function or not
#define WINDOW 1
#endif

#ifndef OCT_NORM // wether using the octave normilization
#define OCT_NORM 1
#endif

#ifndef REORDER // wether using the reorder function or not
#define REORDER 1
#endif

#ifndef LOG_OUT // wether using the log output function or not
#define LOG_OUT 0
#endif

#ifndef LIN_OUT // wether using the linear output function or not
#define LIN_OUT 0
#endif

#ifndef LIN_OUT8 // wether using the linear output function or not
#define LIN_OUT8 0
#endif

#ifndef OCTAVE // wether using the octave output function or not
#define OCTAVE 0
#endif

#if FHT_N == 256
#define LOG_N 8
#define _R_V 8 // reorder value - used for reorder list
#elif  FHT_N == 128
#define LOG_N 7
#define _R_V 8
#elif FHT_N == 64
#define LOG_N 6
#define _R_V 4
#elif FHT_N == 32
#define LOG_N 5
#define _R_V 4
#elif FHT_N == 16
#define LOG_N 4
#define _R_V 2
#else
#error FHT_N value not defined
#endif

#include <avr/pgmspace.h>

class FHT2
{
    
public:
    FHT2(); //constructor
private:
    
    #if (FHT_N ==  256)
        PROGMEM  prog_int16_t _cas_constants[238];
    #elif (FHT_N ==  128)
        PROGMEM  prog_int16_t _cas_constants[112];
    #elif (FHT_N ==  64)
        PROGMEM  prog_int16_t _cas_constants[50];
    #elif (FHT_N ==  32)
        PROGMEM  prog_int16_t _cas_constants[20];
    #elif (FHT_N ==  16)
        PROGMEM  prog_int16_t _cas_constants[6];
    #endif
    
    #if (REORDER == 1)
        #if (FHT_N == 256)
            PROGMEM  prog_uint8_t _reorder_table[240];
        #elif (FHT_N == 128)
            PROGMEM  prog_uint8_t _reorder_table[112];
        #elif (FHT_N == 64)
            PROGMEM  prog_uint8_t _reorder_table[56];
        #elif (FHT_N == 32)
            PROGMEM  prog_uint8_t _reorder_table[24];
        #elif (FHT_N == 16)
            PROGMEM  prog_uint8_t _reorder_table[12];
        #endif
    #endif
    
    #if ((LOG_OUT == 1)||(OCTAVE == 1))
        PROGMEM  prog_uint8_t _log_table[257];
    #endif
    
public:
    #if (LOG_OUT == 1)
        uint8_t fht_log_out[(FHT_N/2)]; // FHT log output magintude buffer
    #endif
    
    #if (LIN_OUT == 1)
        PROGMEM  prog_uint8_t _lin_table[768]
        uint16_t fht_lin_out[(FHT_N/2)]; // FHT linear output magintude buffer
    #endif
    
    #if (LIN_OUT8 == 1)
        PROGMEM  prog_uint8_t _lin_table8[640]
        uint8_t fht_lin_out8[(FHT_N/2)]; // FHT linear output magintude buffer
    #endif
    
    #if (OCTAVE == 1)
        uint8_t fht_oct_out[(LOG_N)]; // FHT octave output magintude buffer
    #endif
    
    #if (WINDOW == 1) // window functions are in 16b signed format
        #if (FHT_N ==  256)
            PROGMEM  prog_int16_t _window_func[256];
        #elif (FHT_N ==  128)
            PROGMEM  prog_int16_t _window_func[128];
        #elif (FHT_N ==  64)
            PROGMEM  prog_int16_t _window_func[64];
        #elif (FHT_N ==  32)
            PROGMEM  prog_int16_t _window_func[32];
        #elif (FHT_N ==  16)
            PROGMEM  prog_int16_t _window_func[16];
        #endif
    #endif
    
    int fht_input[(FHT_N)]; // FHT input data buffer
    
    
public:
    void fht_run(void);
    void fht_reorder(void);
    void fht_mag_log(void);
    void fht_mag_lin(void);
    void fht_mag_lin8(void);
    void fht_window(void);
    void fht_mag_octave(void);
    
    void set_fht_input(int sample, int i);
    
};

#endif /* defined(__LIT_Headband_Simulator__FHT2__) */


