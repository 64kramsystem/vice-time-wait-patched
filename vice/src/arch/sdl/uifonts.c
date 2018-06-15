/*
 * uifonts.c - common fonts related stuff
 *
 * Written by
 *  groepaz <groepaz@gmx.net>
 *
 * This file is part of VICE, the Versatile Commodore Emulator.
 * See README for copyright notice.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
 *  02111-1307  USA.
 *
 */

#include <string.h>
#include <stdint.h>

#include "uifonts.h"

#define MENUCHARSNUM    14
static const unsigned char uichars[8 * MENUCHARSNUM] = {
    0x3f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x3f, /* 01 header left */
    0xfc, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfc, /* 02 header right */
    0x00, 0x00, 0x3f, 0x1f, 0x3f, 0x00, 0x00, 0x00, /* 03 submenu arrow left */
    0x80, 0xc0, 0xe0, 0xf0, 0xe0, 0xc0, 0x80, 0x00, /* 04 submenu arrow right */
    0x00, 0x38, 0x44, 0x82, 0x44, 0x38, 0x00, 0x00, /* 05 radio button inactive */
    0x00, 0x38, 0x7c, 0xfe, 0x7c, 0x38, 0x00, 0x00, /* 06 radio button active */
    0x00, 0x00, 0x3f, 0x20, 0x20, 0x25, 0x24, 0x24, /* 07 top-left edge */
    0x00, 0x00, 0xfc, 0x04, 0x04, 0xe4, 0x24, 0x24, /* 08 top-right edge */
    0x24, 0x24, 0x27, 0x20, 0x20, 0x3f, 0x00, 0x00, /* 0a bottom-leftt edge */
    0x24, 0x24, 0xe4, 0x04, 0x04, 0xfc, 0x00, 0x00, /* 09 bottom-rightedge*/
    0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x24, /* 0b vertikal */
    0x00, 0x00, 0xff, 0x00, 0x00, 0xff, 0x00, 0x00, /* 0c horizontal */
    0x24, 0x24, 0x27, 0x20, 0x20, 0x27, 0x24, 0x24, /* 0d right tee */
    0x24, 0x24, 0xe4, 0x04, 0x04, 0xe4, 0x24, 0x24, /* 0e left tee */
};

void sdl_ui_copy_ui_font(uint8_t *dest)
{
    memcpy(dest, uichars, 8 * MENUCHARSNUM);
}
