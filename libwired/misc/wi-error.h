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

#ifndef WI_ERROR_H
#define WI_ERROR_H 1

#include <errno.h>
#include <wired/wi-base.h>
#include <wired/wi-runtime.h>
 
enum _wi_error_domain {
    WI_ERROR_DOMAIN_NONE                    = 0,
    WI_ERROR_DOMAIN_ERRNO,
    WI_ERROR_DOMAIN_GAI,
    WI_ERROR_DOMAIN_REGEX,
    WI_ERROR_DOMAIN_OPENSSL,
    WI_ERROR_DOMAIN_OPENSSL_SSL,
    WI_ERROR_DOMAIN_COMMONCRYPTO,
    WI_ERROR_DOMAIN_LIBXML2,
    WI_ERROR_DOMAIN_LIBWIRED
};
typedef enum _wi_error_domain               wi_error_domain_t;


enum _wi_error_code {
    WI_ERROR_NONE                           = 0,

    WI_ERROR_ADDRESS_INVALIDADDRESS,
    
    WI_ERROR_CIPHER_CIPHERNOTSUPPORTED,
    
    WI_ERROR_HOST_NOAVAILABLEADDRESSES,
    
    WI_ERROR_LOG_NOSUCHFACILITY,
    
    WI_ERROR_PLIST_READFAILED,
    WI_ERROR_PLIST_WRITEFAILED,
    
    WI_ERROR_JSON_READFAILED,
    WI_ERROR_JSON_WRITEFAILED,

    WI_ERROR_SOCKET_NOVALIDCIPHER,
    WI_ERROR_SOCKET_EOF,
    
    WI_ERROR_SSL_ERROR_NONE,
    WI_ERROR_SSL_ERROR_ZERO_RETURN,
    WI_ERROR_SSL_ERROR_WANT_READ,
    WI_ERROR_SSL_ERROR_WANT_WRITE,
    WI_ERROR_SSL_ERROR_WANT_CONNECT,
    WI_ERROR_SSL_ERROR_WANT_ACCEPT,
    WI_ERROR_SSL_ERROR_WANT_X509_LOOKUP
};


WI_EXPORT wi_string_t *                     wi_error_string(void);
WI_EXPORT wi_integer_t                      wi_error_code(void);
WI_EXPORT wi_error_domain_t                 wi_error_domain(void);

#endif /* WI_ERROR_H */
