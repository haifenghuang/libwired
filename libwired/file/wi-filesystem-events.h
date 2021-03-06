/*
 *  Copyright (c) 2015 Axel Andersson
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef WI_FILESYSTEM_EVENTS_H
#define WI_FILESYSTEM_EVENTS_H 1

#include <wired/wi-base.h>
#include <wired/wi-runtime.h>

typedef void                                wi_filesystem_events_callback_t(wi_filesystem_events_t *, wi_string_t *);


WI_EXPORT wi_runtime_id_t                   wi_filesystem_events_runtime_id(void);

WI_EXPORT wi_filesystem_events_t *          wi_filesystem_events(void);

WI_EXPORT wi_filesystem_events_t *          wi_filesystem_events_alloc(void);
WI_EXPORT wi_filesystem_events_t *          wi_filesystem_events_init(wi_filesystem_events_t *);

WI_EXPORT wi_boolean_t                      wi_filesystem_events_add_path_with_callback(wi_filesystem_events_t *, wi_string_t *, wi_filesystem_events_callback_t *);
WI_EXPORT void                              wi_filesystem_events_remove_path(wi_filesystem_events_t *, wi_string_t *);
WI_EXPORT void                              wi_filesystem_events_remove_all_paths(wi_filesystem_events_t *);

#endif /* WI_FILESYSTEM_EVENTS_H */
