/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995 Spencer Kimball and Peter Mattis
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef __GIMP_BUFFER_H__
#define __GIMP_BUFFER_H__


#include "gimpviewable.h"


#define GIMP_TYPE_BUFFER            (gimp_buffer_get_type ())
#define GIMP_BUFFER(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_BUFFER, GimpBuffer))
#define GIMP_BUFFER_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_BUFFER, GimpBufferClass))
#define GIMP_IS_BUFFER(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_BUFFER))
#define GIMP_IS_BUFFER_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_BUFFER))
#define GIMP_BUFFER_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIMP_TYPE_BUFFER, GimpBufferClass))


typedef struct _GimpBufferClass GimpBufferClass;

struct _GimpBuffer
{
  GimpViewable      parent_instance;

  GeglBuffer       *buffer;
  gint              offset_x;
  gint              offset_y;

  gdouble           resolution_x;
  gdouble           resolution_y;
  GimpUnit          unit;

  GimpColorProfile *color_profile;
};

struct _GimpBufferClass
{
  GimpViewableClass  parent_class;
};


GType              gimp_buffer_get_type          (void) G_GNUC_CONST;

GimpBuffer       * gimp_buffer_new               (GeglBuffer       *buffer,
                                                  const gchar      *name,
                                                  gint              offset_x,
                                                  gint              offset_y,
                                                  gboolean          copy_pixels);
GimpBuffer       * gimp_buffer_new_from_pixbuf   (GdkPixbuf        *pixbuf,
                                                  const gchar      *name,
                                                  gint              offset_x,
                                                  gint              offset_y);

gint               gimp_buffer_get_width         (GimpBuffer       *buffer);
gint               gimp_buffer_get_height        (GimpBuffer       *buffer);
const Babl       * gimp_buffer_get_format        (GimpBuffer       *buffer);

GeglBuffer       * gimp_buffer_get_buffer        (GimpBuffer       *buffer);

void               gimp_buffer_set_resolution    (GimpBuffer       *buffer,
                                                  gdouble           resolution_x,
                                                  gdouble           resolution_y);
gboolean           gimp_buffer_get_resolution    (GimpBuffer       *buffer,
                                                  gdouble          *resolution_x,
                                                  gdouble          *resolution_y);

void               gimp_buffer_set_unit          (GimpBuffer       *buffer,
                                                  GimpUnit          unit);
GimpUnit           gimp_buffer_get_unit          (GimpBuffer       *buffer);

void               gimp_buffer_set_color_profile (GimpBuffer       *buffer,
                                                  GimpColorProfile *profile);
GimpColorProfile * gimp_buffer_get_color_profile (GimpBuffer       *buffer);


#endif /* __GIMP_BUFFER_H__ */
