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
//	WAD I/O functions.
//

#include <stdio.h>
#include <string.h>

#include "m_misc.h"
#include "w_file.h"
#include "z_zone.h"

#include "wadfile.h"





extern wad_file_class_t nw_wad_file;

static wad_file_t *W_Nw_OpenFile(char *path)
{


    wad_file_t *result;

    result = Z_Malloc(sizeof(wad_file_t), PU_STATIC, 0);
    result->file_class = &nw_wad_file;
    result->mapped = NULL;
    result->length = WAD_DATA_LEN;
    
    return result;
}

static void W_Nw_CloseFile(wad_file_t *wad)
{
    Z_Free(wad);
}

// Read data from the specified position in the file into the 
// provided buffer.  Returns the number of bytes read.

size_t W_Nw_Read(wad_file_t *wad, unsigned int offset,
                   void *buffer, size_t buffer_len)
{

    // Read into the buffer.
    
    memcpy(buffer, WAD_DATA+offset, buffer_len);

    return buffer_len;
}


wad_file_class_t nw_wad_file = 
{
    W_Nw_OpenFile,
    W_Nw_CloseFile,
    W_Nw_Read,
};

