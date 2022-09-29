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

#ifndef __GIMP_GUIDE_TOOL_H__
#define __GIMP_GUIDE_TOOL_H__


#include "gimpdrawtool.h"


#define GIMP_TYPE_GUIDE_TOOL            (gimp_guide_tool_get_type ())
#define GIMP_GUIDE_TOOL(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GIMP_TYPE_GUIDE_TOOL, GimpGuideTool))
#define GIMP_GUIDE_TOOL_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass), GIMP_TYPE_GUIDE_TOOL, GimpGuideToolClass))
#define GIMP_IS_GUIDE_TOOL(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GIMP_TYPE_GUIDE_TOOL))
#define GIMP_IS_GUIDE_TOOL_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass), GIMP_TYPE_GUIDE_TOOL))
#define GIMP_GUIDE_TOOL_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj), GIMP_TYPE_GUIDE_TOOL, GimpGuideToolClass))


typedef struct _GimpGuideToolGuide GimpGuideToolGuide;
typedef struct _GimpGuideTool      GimpGuideTool;
typedef struct _GimpGuideToolClass GimpGuideToolClass;

struct _GimpGuideToolGuide
{
  GimpGuide           *guide;

  gint                 old_position;
  gint                 position;
  GimpOrientationType  orientation;
  gboolean             custom;
};

struct _GimpGuideTool
{
  GimpDrawTool        parent_instance;

  GimpGuideToolGuide *guides;
  gint                n_guides;
};

struct _GimpGuideToolClass
{
  GimpDrawToolClass  parent_class;
};


GType   gimp_guide_tool_get_type        (void) G_GNUC_CONST;

void    gimp_guide_tool_start_new       (GimpTool            *parent_tool,
                                         GimpDisplay         *display,
                                         GimpOrientationType  orientation);
void    gimp_guide_tool_start_edit      (GimpTool            *parent_tool,
                                         GimpDisplay         *display,
                                         GimpGuide           *guide);
void    gimp_guide_tool_start_edit_many (GimpTool            *parent_tool,
                                         GimpDisplay         *display,
                                         GList               *guides);


#endif  /*  __GIMP_GUIDE_TOOL_H__  */
