/*  This program is free software; you can redistribute it and/or modify
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
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include "configdb.h"

#include <stdlib.h>
#include <string.h>

#include <libmcs/mcs.h>


#define RCFILE_DEFAULT_SECTION_NAME "conspire"

static gboolean mcs_initted = FALSE;

struct _ConfigDb
{
    mcs_handle_t *handle;
};

ConfigDb *config;

ConfigDb *
settings_open()
{
    ConfigDb *db;

    db = g_new(ConfigDb, 1);

    if (!mcs_initted)
    {
	mcs_init();
        mcs_initted = TRUE;
    }

    db->handle = mcs_new(RCFILE_DEFAULT_SECTION_NAME);

    return db;
}

void
settings_close(ConfigDb * db)
{
    mcs_destroy(db->handle);
    g_free(db);
}

gboolean
settings_get_string(ConfigDb * db,
                      const gchar * section,
                      const gchar * key,
                      gchar ** value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    return mcs_get_string(db->handle, section, key, value);
}

gboolean
settings_get_int(ConfigDb * db,
                   const gchar * section, const gchar * key, gint * value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    return mcs_get_int(db->handle, section, key, value);
}

gboolean
settings_get_bool(ConfigDb * db,
                    const gchar * section,
                    const gchar * key,
                    gboolean * value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    return mcs_get_bool(db->handle, section, key, value);
}

gboolean
settings_get_float(ConfigDb * db,
                     const gchar * section,
                     const gchar * key,
                     gfloat * value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    return mcs_get_float(db->handle, section, key, value);
}

gboolean
settings_get_double(ConfigDb * db,
                      const gchar * section,
                      const gchar * key,
                      gdouble * value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    return mcs_get_double(db->handle, section, key, value);
}

void
settings_set_string(ConfigDb * db,
                      const gchar * section,
                      const gchar * key,
                      const gchar * value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_set_string(db->handle, section, key, value);
}

void
settings_set_int(ConfigDb * db,
                   const gchar * section,
                   const gchar * key,
                   gint value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_set_int(db->handle, section, key, value);
}

void
settings_set_bool(ConfigDb * db,
                    const gchar * section,
                    const gchar * key,
                    gboolean value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_set_bool(db->handle, section, key, value);
}

void
settings_set_float(ConfigDb * db,
                     const gchar * section,
                     const gchar * key,
                     gfloat value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_set_float(db->handle, section, key, value);
}

void
settings_set_double(ConfigDb * db,
                      const gchar * section,
                      const gchar * key,
                      gdouble value)
{
    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_set_double(db->handle, section, key, value);
}

void
settings_unset_key(ConfigDb * db,
                     const gchar * section,
                     const gchar * key)
{
    g_return_if_fail(db != NULL);
    g_return_if_fail(key != NULL);

    if (!section)
        section = RCFILE_DEFAULT_SECTION_NAME;

    mcs_unset_key(db->handle, section, key);
}
