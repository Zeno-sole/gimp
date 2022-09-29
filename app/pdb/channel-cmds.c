/* GIMP - The GNU Image Manipulation Program
 * Copyright (C) 1995-2003 Spencer Kimball and Peter Mattis
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

/* NOTE: This file is auto-generated by pdbgen.pl. */

#include "config.h"

#include <cairo.h>

#include <gegl.h>

#include <gdk-pixbuf/gdk-pixbuf.h>

#include "libgimpbase/gimpbase.h"
#include "libgimpcolor/gimpcolor.h"

#include "libgimpbase/gimpbase.h"

#include "pdb-types.h"

#include "core/gimpchannel-combine.h"
#include "core/gimpchannel.h"
#include "core/gimpimage.h"
#include "core/gimpparamspecs.h"

#include "gimppdb.h"
#include "gimpprocedure.h"
#include "internal-procs.h"

#include "gimp-intl.h"


static GimpValueArray *
channel_new_invoker (GimpProcedure         *procedure,
                     Gimp                  *gimp,
                     GimpContext           *context,
                     GimpProgress          *progress,
                     const GimpValueArray  *args,
                     GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  gint32 width;
  gint32 height;
  const gchar *name;
  gdouble opacity;
  GimpRGB color;
  GimpChannel *channel = NULL;

  image = gimp_value_get_image (gimp_value_array_index (args, 0), gimp);
  width = g_value_get_int (gimp_value_array_index (args, 1));
  height = g_value_get_int (gimp_value_array_index (args, 2));
  name = g_value_get_string (gimp_value_array_index (args, 3));
  opacity = g_value_get_double (gimp_value_array_index (args, 4));
  gimp_value_get_rgb (gimp_value_array_index (args, 5), &color);

  if (success)
    {
      GimpRGB rgb_color = color;

      rgb_color.a = opacity / 100.0;
      channel = gimp_channel_new (image, width, height, name, &rgb_color);

      if (! channel)
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    gimp_value_set_channel (gimp_value_array_index (return_vals, 1), channel);

  return return_vals;
}

static GimpValueArray *
channel_new_from_component_invoker (GimpProcedure         *procedure,
                                    Gimp                  *gimp,
                                    GimpContext           *context,
                                    GimpProgress          *progress,
                                    const GimpValueArray  *args,
                                    GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpImage *image;
  gint32 component;
  const gchar *name;
  GimpChannel *channel = NULL;

  image = gimp_value_get_image (gimp_value_array_index (args, 0), gimp);
  component = g_value_get_enum (gimp_value_array_index (args, 1));
  name = g_value_get_string (gimp_value_array_index (args, 2));

  if (success)
    {
      if (gimp_image_get_component_format (image, component) != NULL)
        channel = gimp_channel_new_from_component (image,
                                                   component, name, NULL);

      if (channel)
        gimp_item_set_visible (GIMP_ITEM (channel), FALSE, FALSE);
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    gimp_value_set_channel (gimp_value_array_index (return_vals, 1), channel);

  return return_vals;
}

static GimpValueArray *
channel_copy_invoker (GimpProcedure         *procedure,
                      Gimp                  *gimp,
                      GimpContext           *context,
                      GimpProgress          *progress,
                      const GimpValueArray  *args,
                      GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpChannel *channel;
  GimpChannel *channel_copy = NULL;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);

  if (success)
    {
      GimpImage *image  = gimp_item_get_image (GIMP_ITEM (channel));
      gint       width  = gimp_image_get_width  (image);
      gint       height = gimp_image_get_height (image);

      if (gimp_item_get_width  (GIMP_ITEM (channel)) == width &&
          gimp_item_get_height (GIMP_ITEM (channel)) == height)
        {
          channel_copy = GIMP_CHANNEL (gimp_item_duplicate (GIMP_ITEM (channel),
                                                            GIMP_TYPE_CHANNEL));

          if (! channel_copy)
            success = FALSE;
        }
      else
        success = FALSE;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    gimp_value_set_channel (gimp_value_array_index (return_vals, 1), channel_copy);

  return return_vals;
}

static GimpValueArray *
channel_combine_masks_invoker (GimpProcedure         *procedure,
                               Gimp                  *gimp,
                               GimpContext           *context,
                               GimpProgress          *progress,
                               const GimpValueArray  *args,
                               GError               **error)
{
  gboolean success = TRUE;
  GimpChannel *channel1;
  GimpChannel *channel2;
  gint32 operation;
  gint32 offx;
  gint32 offy;

  channel1 = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);
  channel2 = gimp_value_get_channel (gimp_value_array_index (args, 1), gimp);
  operation = g_value_get_enum (gimp_value_array_index (args, 2));
  offx = g_value_get_int (gimp_value_array_index (args, 3));
  offy = g_value_get_int (gimp_value_array_index (args, 4));

  if (success)
    {
      if (gimp_item_is_attached (GIMP_ITEM (channel1)))
        gimp_channel_push_undo (channel1, _("Combine Masks"));

      gimp_channel_combine_mask (channel1, channel2, operation, offx, offy);
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

static GimpValueArray *
channel_get_show_masked_invoker (GimpProcedure         *procedure,
                                 Gimp                  *gimp,
                                 GimpContext           *context,
                                 GimpProgress          *progress,
                                 const GimpValueArray  *args,
                                 GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpChannel *channel;
  gboolean show_masked = FALSE;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);

  if (success)
    {
      show_masked = gimp_channel_get_show_masked (channel);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_boolean (gimp_value_array_index (return_vals, 1), show_masked);

  return return_vals;
}

static GimpValueArray *
channel_set_show_masked_invoker (GimpProcedure         *procedure,
                                 Gimp                  *gimp,
                                 GimpContext           *context,
                                 GimpProgress          *progress,
                                 const GimpValueArray  *args,
                                 GError               **error)
{
  gboolean success = TRUE;
  GimpChannel *channel;
  gboolean show_masked;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);
  show_masked = g_value_get_boolean (gimp_value_array_index (args, 1));

  if (success)
    {
      gimp_channel_set_show_masked (channel, show_masked);
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

static GimpValueArray *
channel_get_opacity_invoker (GimpProcedure         *procedure,
                             Gimp                  *gimp,
                             GimpContext           *context,
                             GimpProgress          *progress,
                             const GimpValueArray  *args,
                             GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpChannel *channel;
  gdouble opacity = 0.0;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);

  if (success)
    {
      opacity = gimp_channel_get_opacity (channel) * 100;
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    g_value_set_double (gimp_value_array_index (return_vals, 1), opacity);

  return return_vals;
}

static GimpValueArray *
channel_set_opacity_invoker (GimpProcedure         *procedure,
                             Gimp                  *gimp,
                             GimpContext           *context,
                             GimpProgress          *progress,
                             const GimpValueArray  *args,
                             GError               **error)
{
  gboolean success = TRUE;
  GimpChannel *channel;
  gdouble opacity;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);
  opacity = g_value_get_double (gimp_value_array_index (args, 1));

  if (success)
    {
      gimp_channel_set_opacity (channel, opacity / 100.0, TRUE);
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

static GimpValueArray *
channel_get_color_invoker (GimpProcedure         *procedure,
                           Gimp                  *gimp,
                           GimpContext           *context,
                           GimpProgress          *progress,
                           const GimpValueArray  *args,
                           GError               **error)
{
  gboolean success = TRUE;
  GimpValueArray *return_vals;
  GimpChannel *channel;
  GimpRGB color = { 0.0, 0.0, 0.0, 1.0 };

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);

  if (success)
    {
      gimp_channel_get_color (channel, &color);
      gimp_rgb_set_alpha (&color, 1.0);
    }

  return_vals = gimp_procedure_get_return_values (procedure, success,
                                                  error ? *error : NULL);

  if (success)
    gimp_value_set_rgb (gimp_value_array_index (return_vals, 1), &color);

  return return_vals;
}

static GimpValueArray *
channel_set_color_invoker (GimpProcedure         *procedure,
                           Gimp                  *gimp,
                           GimpContext           *context,
                           GimpProgress          *progress,
                           const GimpValueArray  *args,
                           GError               **error)
{
  gboolean success = TRUE;
  GimpChannel *channel;
  GimpRGB color;

  channel = gimp_value_get_channel (gimp_value_array_index (args, 0), gimp);
  gimp_value_get_rgb (gimp_value_array_index (args, 1), &color);

  if (success)
    {
      GimpRGB rgb_color = color;

      rgb_color.a = channel->color.a;
      gimp_channel_set_color (channel, &rgb_color, TRUE);
    }

  return gimp_procedure_get_return_values (procedure, success,
                                           error ? *error : NULL);
}

void
register_channel_procs (GimpPDB *pdb)
{
  GimpProcedure *procedure;

  /*
   * gimp-channel-new
   */
  procedure = gimp_procedure_new (channel_new_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-new");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-new",
                                     "Create a new channel.",
                                     "This procedure creates a new channel with the specified width, height, name, opacity and color.\n"
                                     "The new channel still needs to be added to the image, as this is not automatic. Add the new channel with 'gimp-image-insert-channel'. Other attributes, such as channel visibility, should be set with explicit procedure calls.\n"
                                     "The channel's contents are undefined initially.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image_id ("image",
                                                         "image",
                                                         "The image to which to add the channel",
                                                         pdb->gimp, FALSE,
                                                         GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_int32 ("width",
                                                      "width",
                                                      "The channel width",
                                                      1, GIMP_MAX_IMAGE_SIZE, 1,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_int32 ("height",
                                                      "height",
                                                      "The channel height",
                                                      1, GIMP_MAX_IMAGE_SIZE, 1,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("name",
                                                       "name",
                                                       "The channel name",
                                                       FALSE, FALSE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("opacity",
                                                    "opacity",
                                                    "The channel opacity",
                                                    0, 100, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_rgb ("color",
                                                    "color",
                                                    "The channel compositing color",
                                                    FALSE,
                                                    NULL,
                                                    GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_channel_id ("channel",
                                                               "channel",
                                                               "The newly created channel",
                                                               pdb->gimp, FALSE,
                                                               GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-new-from-component
   */
  procedure = gimp_procedure_new (channel_new_from_component_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-new-from-component");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-new-from-component",
                                     "Create a new channel from a color component",
                                     "This procedure creates a new channel from a color component.\n"
                                     "The new channel still needs to be added to the image, as this is not automatic. Add the new channel with 'gimp-image-insert-channel'. Other attributes, such as channel visibility, should be set with explicit procedure calls.",
                                     "Shlomi Fish <shlomif@iglu.org.il>",
                                     "Shlomi Fish",
                                     "2005",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_image_id ("image",
                                                         "image",
                                                         "The image to which to add the channel",
                                                         pdb->gimp, FALSE,
                                                         GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_enum ("component",
                                                  "component",
                                                  "The image component",
                                                  GIMP_TYPE_CHANNEL_TYPE,
                                                  GIMP_CHANNEL_RED,
                                                  GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_string ("name",
                                                       "name",
                                                       "The channel name",
                                                       FALSE, FALSE, FALSE,
                                                       NULL,
                                                       GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_channel_id ("channel",
                                                               "channel",
                                                               "The newly created channel",
                                                               pdb->gimp, FALSE,
                                                               GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-copy
   */
  procedure = gimp_procedure_new (channel_copy_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-copy");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-copy",
                                     "Copy a channel.",
                                     "This procedure copies the specified channel and returns the copy.\n"
                                     "The new channel still needs to be added to the image, as this is not automatic. Add the new channel with 'gimp-image-insert-channel'.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel to copy",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_channel_id ("channel-copy",
                                                               "channel copy",
                                                               "The newly copied channel",
                                                               pdb->gimp, FALSE,
                                                               GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-combine-masks
   */
  procedure = gimp_procedure_new (channel_combine_masks_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-combine-masks");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-combine-masks",
                                     "Combine two channel masks.",
                                     "This procedure combines two channel masks. The result is stored in the first channel.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel1",
                                                           "channel1",
                                                           "The channel1",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel2",
                                                           "channel2",
                                                           "The channel2",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_enum ("operation",
                                                  "operation",
                                                  "The selection operation",
                                                  GIMP_TYPE_CHANNEL_OPS,
                                                  GIMP_CHANNEL_OP_ADD,
                                                  GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_int32 ("offx",
                                                      "offx",
                                                      "x offset between upper left corner of channels: (second - first)",
                                                      G_MININT32, G_MAXINT32, 0,
                                                      GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_int32 ("offy",
                                                      "offy",
                                                      "y offset between upper left corner of channels: (second - first)",
                                                      G_MININT32, G_MAXINT32, 0,
                                                      GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-get-show-masked
   */
  procedure = gimp_procedure_new (channel_get_show_masked_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-get-show-masked");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-get-show-masked",
                                     "Get the composite method of the specified channel.",
                                     "This procedure returns the specified channel's composite method. If it is TRUE, then the channel is composited with the image so that masked regions are shown. Otherwise, selected regions are shown.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_boolean ("show-masked",
                                                         "show masked",
                                                         "The channel composite method",
                                                         FALSE,
                                                         GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-set-show-masked
   */
  procedure = gimp_procedure_new (channel_set_show_masked_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-set-show-masked");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-set-show-masked",
                                     "Set the composite method of the specified channel.",
                                     "This procedure sets the specified channel's composite method. If it is TRUE, then the channel is composited with the image so that masked regions are shown. Otherwise, selected regions are shown.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_boolean ("show-masked",
                                                     "show masked",
                                                     "The new channel composite method",
                                                     FALSE,
                                                     GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-get-opacity
   */
  procedure = gimp_procedure_new (channel_get_opacity_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-get-opacity");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-get-opacity",
                                     "Get the opacity of the specified channel.",
                                     "This procedure returns the specified channel's opacity.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   g_param_spec_double ("opacity",
                                                        "opacity",
                                                        "The channel opacity",
                                                        0, 100, 0,
                                                        GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-set-opacity
   */
  procedure = gimp_procedure_new (channel_set_opacity_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-set-opacity");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-set-opacity",
                                     "Set the opacity of the specified channel.",
                                     "This procedure sets the specified channel's opacity.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               g_param_spec_double ("opacity",
                                                    "opacity",
                                                    "The new channel opacity",
                                                    0, 100, 0,
                                                    GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-get-color
   */
  procedure = gimp_procedure_new (channel_get_color_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-get-color");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-get-color",
                                     "Get the compositing color of the specified channel.",
                                     "This procedure returns the specified channel's compositing color.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_return_value (procedure,
                                   gimp_param_spec_rgb ("color",
                                                        "color",
                                                        "The channel compositing color",
                                                        FALSE,
                                                        NULL,
                                                        GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);

  /*
   * gimp-channel-set-color
   */
  procedure = gimp_procedure_new (channel_set_color_invoker);
  gimp_object_set_static_name (GIMP_OBJECT (procedure),
                               "gimp-channel-set-color");
  gimp_procedure_set_static_strings (procedure,
                                     "gimp-channel-set-color",
                                     "Set the compositing color of the specified channel.",
                                     "This procedure sets the specified channel's compositing color.",
                                     "Spencer Kimball & Peter Mattis",
                                     "Spencer Kimball & Peter Mattis",
                                     "1995-1996",
                                     NULL);
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_channel_id ("channel",
                                                           "channel",
                                                           "The channel",
                                                           pdb->gimp, FALSE,
                                                           GIMP_PARAM_READWRITE));
  gimp_procedure_add_argument (procedure,
                               gimp_param_spec_rgb ("color",
                                                    "color",
                                                    "The new channel compositing color",
                                                    FALSE,
                                                    NULL,
                                                    GIMP_PARAM_READWRITE));
  gimp_pdb_register_procedure (pdb, procedure);
  g_object_unref (procedure);
}
