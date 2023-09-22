#ifndef PSYX_CONFIG_H
#define PSYX_CONFIG_H


// Required. Uses 32 bit pointers on P_TAG and other primitives
#define USE_EXTENDED_PRIM_POINTERS

#if !defined(__vita__) // disabled for perf
// PGXP-Z: Precise GTE transform pipeline with Z-depth and widescreen fixes. Recommended
#define USE_PGXP
#endif

#endif // PSYX_CONFIG_H
