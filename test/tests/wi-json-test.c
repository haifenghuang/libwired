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

#include <wired/wired.h>
#include "test.h"

WI_TEST_EXPORT void                     wi_test_json(void);


void wi_test_json(void) {
    wi_string_t         *string1, *string2;
    wi_dictionary_t     *dictionary1, *dictionary2;
    
    string1 = wi_string_with_utf8_contents_of_file(wi_string_by_appending_path_component(wi_test_fixture_path, WI_STR("wi-json-tests-1.json")));

    dictionary1 = wi_json_instance_for_string(string1);
    
    WI_TEST_ASSERT_NOT_NULL(dictionary1, "%m");
    
    dictionary2 = wi_dictionary_with_data_and_keys(
        WI_STR("\"hello world\""),
            WI_STR("string"),
        wi_number_with_bool(true),
            WI_STR("true"),
        wi_number_with_bool(false),
            WI_STR("false"),
        wi_number_with_integer(42),
            WI_STR("integer"),
        wi_number_with_double(3.14),
            WI_STR("real"),
        wi_null(),
            WI_STR("null"),
        wi_dictionary_with_data_and_keys(WI_STR("value1"), WI_STR("key1"), WI_STR("value2"), WI_STR("key2"), NULL),
            WI_STR("dict"),
        wi_array_with_data(WI_STR("value1"), WI_STR("value2"), NULL),
            WI_STR("array"),
        NULL);
    
    WI_TEST_ASSERT_EQUAL_INSTANCES(dictionary1, dictionary2, "");
    
    string2 = wi_json_string_for_instance(dictionary2);
    
    WI_TEST_ASSERT_EQUAL_INSTANCES(string1, string2, "");
}
