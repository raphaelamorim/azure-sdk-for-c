// Copyright (c) Microsoft Corporation. All rights reserved.
// SPDX-License-Identifier: MIT

#ifndef AZ_JSON_VALUE_H
#define AZ_JSON_VALUE_H

#include <az_span.h>

#include <stdbool.h>

#include <_az_cfg_prefix.h>

typedef enum {
  AZ_JSON_VALUE_NONE = 0,
  AZ_JSON_VALUE_NULL = 1,
  AZ_JSON_VALUE_BOOLEAN = 2,
  AZ_JSON_VALUE_NUMBER = 3,
  AZ_JSON_VALUE_STRING = 4,
  AZ_JSON_VALUE_OBJECT = 5,
  AZ_JSON_VALUE_ARRAY = 6,
} az_json_value_kind;

typedef struct {
  az_json_value_kind kind;
  union {
    bool boolean;
    az_span string;
    double number;
  } data;
} az_json_value;

AZ_NODISCARD AZ_INLINE az_json_value az_json_value_create_boolean(bool const value) {
  return (az_json_value){
    .kind = AZ_JSON_VALUE_BOOLEAN,
    .data.boolean = value,
  };
}

AZ_NODISCARD AZ_INLINE az_json_value az_json_value_create_string(az_span const value) {
  return (az_json_value){
    .kind = AZ_JSON_VALUE_STRING,
    .data.string = value,
  };
}

AZ_NODISCARD AZ_INLINE az_json_value az_json_value_create_number(double const value) {
  return (az_json_value){
    .kind = AZ_JSON_VALUE_NUMBER,
    .data.number = value,
  };
}

/**
 * Copies a boolean value to @out from the given JSON value.
 *
 * If the JSON value is not a boolean then the function returns an error.
 */
AZ_NODISCARD az_result
az_json_value_get_boolean(az_json_value const * const self, bool * const out);

/**
 * Copies a string span to @out from the given JSON value.
 *
 * If the JSON value is not a string then the function returns an error.
 */
AZ_NODISCARD az_result
az_json_value_get_string(az_json_value const * const self, az_span * const out);

/**
 * Copies a number to @out from the given JSON value.
 *
 * If the JSON value is not a number then the function returns an error.
 */
AZ_NODISCARD az_result
az_json_value_get_number(az_json_value const * const self, double * const out);

#include <_az_cfg_suffix.h>

#endif
