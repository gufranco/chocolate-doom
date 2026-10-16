//
// Copyright(C) 1993-1996 Id Software, Inc.
// Copyright(C) 2005-2014 Simon Howard
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// DESCRIPTION:
//	Refresh/render internal state variables (global).
//


#ifndef __R_STATE__
#define __R_STATE__

// Need data structure definitions.
#include "d_player.h"
#include "r_data.h"






//
// Refresh internal data structures,
//  for rendering.
//

// needed for texture pegging
extern fixed_t*		textureheight;

// needed for pre rendering (fracs)
extern fixed_t*		spritewidth;

extern fixed_t*		spriteoffset;
extern fixed_t*		spritetopoffset;

extern lighttable_t*	colormaps;

extern int		viewwidth;
extern int		scaledviewwidth;
extern int		viewheight;

extern int		firstflat;

// for global animation
extern int*		flattranslation;	
extern int*		texturetranslation;	


// Sprite....
extern int		firstspritelump;
extern int		lastspritelump;
extern int		numspritelumps;



//
// Lookup tables for map data.
//
extern int		numsprites;
extern spritedef_t*	sprites;

extern int		numvertexes;
extern vertex_t*	vertexes;

extern int		numsegs;
extern seg_t*		segs;

extern int		numsectors;
extern sector_t*	sectors;

extern int		numsubsectors;
extern subsector_t*	subsectors;

extern int		numnodes;
extern node_t*		nodes;

extern int		numlines;
extern line_t*		lines;

extern line_mut_t*	lines_mut;

extern int		numsides;
extern side_t*		sides;

#if defined(DNG_EMBED_GEOMETRY)
extern const side_t*	sides_rom;
extern side_t*		side_slots;
extern const int16_t*	side_slot_of;
extern const uint16_t*	slot_side;

side_t *P_SideMut(int i);

static inline const side_t *P_SideAt(int i)
{
    const int slot = side_slot_of[i];
    return slot < 0 ? &sides_rom[i] : &side_slots[slot];
}

static inline int P_SideIndex(const side_t *sd)
{
    const uintptr_t at = (uintptr_t) sd;
    const uintptr_t rom = (uintptr_t) sides_rom;
    if (at >= rom && at < rom + (uintptr_t) numsides * sizeof(side_t))
    {
        return (int) (sd - sides_rom);
    }
    return slot_side[sd - side_slots];
}

#define SIDE_AT(i)	P_SideAt(i)
#define SIDE_MUT(i)	P_SideMut(i)
#define SIDE_INDEX(sd)	P_SideIndex(sd)
#else
#define SIDE_AT(i)	((const side_t *) &sides[(i)])
#define SIDE_MUT(i)	(&sides[(i)])
#define SIDE_INDEX(sd)	((int) ((sd) - sides))
#endif


//
// POV data.
//
extern fixed_t		viewx;
extern fixed_t		viewy;
extern fixed_t		viewz;

extern angle_t		viewangle;
extern player_t*	viewplayer;


// ?
extern angle_t		clipangle;

extern int             *viewangletox;
extern angle_t		xtoviewangle[SCREENWIDTH+1];
//extern fixed_t		finetangent[FINEANGLES/2];

extern fixed_t		rw_distance;
extern angle_t		rw_normalangle;



// angle to line origin
extern int		rw_angle1;

// Segs count?
extern int		sscount;

extern visplane_t*	floorplane;
extern visplane_t*	ceilingplane;


#endif
