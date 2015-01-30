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

#ifndef WI_SOCKET_TLS_H
#define WI_SOCKET_TLS_H 1

#include <wired/wi-base.h>
#include <wired/wi-runtime.h>

enum _wi_socket_tls_type {
    WI_SOCKET_TLS_CLIENT,
    WI_SOCKET_TLS_SERVER,
};
typedef enum _wi_socket_tls_type        wi_socket_tls_type_t;


WI_EXPORT wi_runtime_id_t               wi_socket_tls_runtime_id(void);

WI_EXPORT wi_socket_tls_t *             wi_socket_tls_alloc(void);
WI_EXPORT wi_socket_tls_t *             wi_socket_tls_init_with_type(wi_socket_tls_t *, wi_socket_tls_type_t);

WI_EXPORT void *                        wi_socket_tls_ssl_context(wi_socket_tls_t *);

WI_EXPORT wi_boolean_t                  wi_socket_tls_set_certificate(wi_socket_tls_t *, wi_x509_t *);
WI_EXPORT wi_x509_t *                   wi_socket_tls_certificate(wi_socket_tls_t *);
WI_EXPORT wi_boolean_t                  wi_socket_tls_set_private_key(wi_socket_tls_t *, wi_rsa_t *);
WI_EXPORT wi_rsa_t *                    wi_socket_tls_private_key(wi_socket_tls_t *);
WI_EXPORT void                          wi_socket_tls_set_dh(wi_socket_tls_t *, wi_dh_t *);
WI_EXPORT wi_dh_t *                     wi_socket_tls_dh(wi_socket_tls_t *);
WI_EXPORT wi_boolean_t                  wi_socket_tls_set_ciphers(wi_socket_tls_t *, wi_string_t *);
WI_EXPORT wi_string_t *                 wi_socket_tls_ciphers(wi_socket_tls_t *);

#endif /* WI_SOCKET_TLS_H */