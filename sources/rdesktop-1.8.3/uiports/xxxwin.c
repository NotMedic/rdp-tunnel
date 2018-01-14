/* -*- c-basic-offset: 8 -*-
   rdesktop: A Remote Desktop Protocol client.
   User interface services - Generic
   Copyright (C) Jay Sorg 2004-2007

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "../rdesktop.h"

extern int g_tcp_port_rdp; /* in tcp.c */
RD_BOOL g_use_rdp5 = False;
char g_hostname[16];
char g_username[64];
int g_height = 600;
int g_width = 800;
int g_server_depth = 8;
RD_BOOL g_encryption = True;
RD_BOOL g_desktop_save = True;
RD_BOOL g_polygon_ellipse_orders = False;
RD_BOOL g_bitmap_cache = True;
RD_BOOL g_bitmap_cache_persist_enable = False;
RD_BOOL g_bitmap_cache_precache = True;
RD_BOOL g_bitmap_compression = True;
uint32 g_rdp5_performanceflags = 0;
RD_BOOL g_console_session = False;
uint32 g_keylayout = 0x409; /* Defaults to US keyboard layout */
int g_keyboard_type = 0x4; /* Defaults to US keyboard layout */
int g_keyboard_subtype = 0x0; /* Defaults to US keyboard layout */
int g_keyboard_functionkeys = 0xc; /* Defaults to US keyboard layout */
/* Session Directory redirection */
RD_BOOL g_redirect = False;
RD_BOOL g_numlock_sync = False;
char g_redirect_server[64];
char g_redirect_domain[16];
char g_redirect_password[64];
char g_redirect_username[64];
char g_redirect_cookie[128];
uint32 g_redirect_flags = 0;
char g_codepage[16] = "";

/*****************************************************************************/
void ui_bell(void)
{
}

/*****************************************************************************/
int ui_select(int in)
{
  return 1;
}

/*****************************************************************************/
void ui_destroy_cursor(void* cursor)
{
}

/*****************************************************************************/
void* ui_create_glyph(int width, int height, uint8* data)
{
  return 0;
}

/*****************************************************************************/
void ui_destroy_glyph(void* glyph)
{
}

/*****************************************************************************/
void ui_destroy_bitmap(void* bmp)
{
}

/*****************************************************************************/
void ui_reset_clip(void)
{
}

/*****************************************************************************/
void ui_set_clip(int x, int y, int cx, int cy)
{
}

/*****************************************************************************/
void* ui_create_colourmap(COLOURMAP * colours)
{
  return 0;
}

/*****************************************************************************/
void ui_set_colourmap(void* map)
{
}

/*****************************************************************************/
RD_HBITMAP ui_create_bitmap(int width, int height, uint8* data)
{
  return 0;
}

/*****************************************************************************/
void ui_draw_text(uint8 font, uint8 flags, uint8 opcode, int mixmode,
                  int x, int y,
                  int clipx, int clipy, int clipcx, int clipcy,
                  int boxx, int boxy, int boxcx, int boxcy, BRUSH * brush,
                  int bgcolour, int fgcolour, uint8* text, uint8 length)
{
}

/*****************************************************************************/
void ui_line(uint8 opcode, int startx, int starty, int endx, int endy,
             PEN * pen)
{
}

/*****************************************************************************/
void ui_triblt(uint8 opcode, int x, int y, int cx, int cy,
               RD_HBITMAP src, int srcx, int srcy,
               BRUSH* brush, int bgcolour, int fgcolour)
{
}

/*****************************************************************************/
void ui_memblt(uint8 opcode, int x, int y, int cx, int cy,
               RD_HBITMAP src, int srcx, int srcy)
{
}

/*****************************************************************************/
void ui_desktop_restore(uint32 offset, int x, int y, int cx, int cy)
{
}

/*****************************************************************************/
void ui_desktop_save(uint32 offset, int x, int y, int cx, int cy)
{
}

/*****************************************************************************/
void ui_rect(int x, int y, int cx, int cy, int colour)
{
}

/*****************************************************************************/
void ui_screenblt(uint8 opcode, int x, int y, int cx, int cy,
                  int srcx, int srcy)
{
}

/*****************************************************************************/
void ui_patblt(uint8 opcode, int x, int y, int cx, int cy,
               BRUSH * brush, int bgcolour, int fgcolour)
{
}

/*****************************************************************************/
void ui_destblt(uint8 opcode, int x, int y, int cx, int cy)
{
}

/*****************************************************************************/
void ui_move_pointer(int x, int y)
{
}

/*****************************************************************************/
void ui_set_null_cursor(void)
{
}

/*****************************************************************************/
void ui_paint_bitmap(int x, int y, int cx, int cy,
                     int width, int height, uint8* data)
{
}

/*****************************************************************************/
void ui_set_cursor(RD_HCURSOR cursor)
{
}

/*****************************************************************************/
RD_HCURSOR ui_create_cursor(unsigned int x, unsigned int y,
                            int width, int height,
                            uint8* andmask, uint8* xormask)
{
  return 0;
}

/*****************************************************************************/
uint16 ui_get_numlock_state(unsigned int state)
{
  return 0;
}

/*****************************************************************************/
unsigned int read_keyboard_state(void)
{
  return 0;
}

/*****************************************************************************/
void ui_resize_window(void)
{
}

/*****************************************************************************/
void ui_begin_update(void)
{
}

/*****************************************************************************/
void ui_end_update(void)
{
}

/*****************************************************************************/
void ui_polygon(uint8 opcode, uint8 fillmode, RD_POINT * point, int npoints,
                BRUSH * brush, int bgcolour, int fgcolour)
{
}

/*****************************************************************************/
/* todo, use qt function for this (QPainter::drawPolyline) */
void ui_polyline(uint8 opcode, RD_POINT * points, int npoints, PEN * pen)
{
  int i, x, y, dx, dy;
  if (npoints > 0)
  {
    x = points[0].x;
    y = points[0].y;
    for (i = 1; i < npoints; i++)
    {
      dx = points[i].x;
      dy = points[i].y;
      ui_line(opcode, x, y, x + dx, y + dy, pen);
      x = x + dx;
      y = y + dy;
    }
  }
}

/*****************************************************************************/
void ui_ellipse(uint8 opcode, uint8 fillmode,
                int x, int y, int cx, int cy,
                BRUSH * brush, int bgcolour, int fgcolour)
{
}

/*****************************************************************************/
void generate_random(uint8* random)
{
}

/*****************************************************************************/
void save_licence(uint8* data, int length)
{
}

/*****************************************************************************/
int load_licence(uint8** data)
{
  return 0;
}

/*****************************************************************************/
void* xrealloc(void* in, int size)
{
  return 0;
}

/*****************************************************************************/
void* xmalloc(int size)
{
  return 0;
}

/*****************************************************************************/
void xfree(void* in)
{
}

/*****************************************************************************/
char * xstrdup(const char * s)
{
  char * mem = strdup(s);
  if (mem == NULL)
  {
    perror("strdup");
    exit(1);
  }
  return mem;
}
/*****************************************************************************/
void warning(char* format, ...)
{
}

/*****************************************************************************/
void unimpl(char* format, ...)
{
}

/*****************************************************************************/
void error(char* format, ...)
{
}

/*****************************************************************************/
RD_BOOL rd_pstcache_mkdir(void)
{
  return 0;
}

/*****************************************************************************/
int rd_open_file(char *filename)
{
  return 0;
}

/*****************************************************************************/
void rd_close_file(int fd)
{
  return;
}

/*****************************************************************************/
int rd_read_file(int fd, void *ptr, int len)
{
  return 0;
}

/*****************************************************************************/
int rd_write_file(int fd, void* ptr, int len)
{
  return 0;
}

/*****************************************************************************/
int rd_lseek_file(int fd, int offset)
{
  return 0;
}

/*****************************************************************************/
RD_BOOL rd_lock_file(int fd, int start, int len)
{
  return False;
}

/*****************************************************************************/
int main(int c, char** p)
{
  return 0;
}
