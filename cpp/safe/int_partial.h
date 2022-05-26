#pragma once
#ifndef SAFE_INT_PARTIAL_H
#define SAFE_INT_PARTIAL_H

#include "../base.h"
#include "int.h"
#include "float.h"

_RUTILS

Int::Int(const Float& value) {
    IsNull = value.IsNull;

    if (!IsNull)
        value_ = (int)value.Value();
}

_RUTILS_END

#endif
