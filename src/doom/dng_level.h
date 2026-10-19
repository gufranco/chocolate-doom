#ifndef DNG_LEVEL_H
#define DNG_LEVEL_H

#include <stdint.h>

#include "r_defs.h"

typedef struct
{
    char lumpname[9];
    uint8_t episode;
    uint8_t map;
    const uint32_t *numvertexes;
    const vertex_t *vertexes;
    const uint32_t *numnodes;
    const node_t *nodes;
#if defined(DNG_EMBED_GEOMETRY)
    const uint32_t *numlines;
    const line_t *lines;
    const line_mut_t *lines_mut_init;
    const uint32_t *numsegs;
    const seg_t *segs;
    const int16_t *blockmap;
    const uint32_t *numsubsectors;
    const subsector_t *subsectors;
    const sector_static_t *sector_statics;
    const uint32_t *totallines;
    const side_t *sides;
    const int16_t *side_slot_of;
    const uint16_t *slot_side;
    const uint32_t *numsideslots;
    side_t *side_slots;
    sector_t *sectors_storage;
    line_mut_t *lines_mut_storage;
#endif
} dng_level_t;

extern const dng_level_t doomng_level __attribute__((weak));

#endif
