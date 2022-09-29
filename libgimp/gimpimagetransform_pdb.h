/* LIBGIMP - The GIMP Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpimagetransform_pdb.h
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#if !defined (__GIMP_H_INSIDE__) && !defined (GIMP_COMPILATION)
#error "Only <libgimp/gimp.h> can be included directly."
#endif

#ifndef __GIMP_IMAGE_TRANSFORM_PDB_H__
#define __GIMP_IMAGE_TRANSFORM_PDB_H__

G_BEGIN_DECLS

/* For information look into the C source or the html documentation */


gboolean gimp_image_resize           (gint32                image_ID,
                                      gint                  new_width,
                                      gint                  new_height,
                                      gint                  offx,
                                      gint                  offy);
gboolean gimp_image_resize_to_layers (gint32                image_ID);
gboolean gimp_image_scale            (gint32                image_ID,
                                      gint                  new_width,
                                      gint                  new_height);
GIMP_DEPRECATED_FOR(gimp_image_scale)
gboolean gimp_image_scale_full       (gint32                image_ID,
                                      gint                  new_width,
                                      gint                  new_height,
                                      GimpInterpolationType interpolation);
gboolean gimp_image_crop             (gint32                image_ID,
                                      gint                  new_width,
                                      gint                  new_height,
                                      gint                  offx,
                                      gint                  offy);
gboolean gimp_image_flip             (gint32                image_ID,
                                      GimpOrientationType   flip_type);
gboolean gimp_image_rotate           (gint32                image_ID,
                                      GimpRotationType      rotate_type);


G_END_DECLS

#endif /* __GIMP_IMAGE_TRANSFORM_PDB_H__ */
