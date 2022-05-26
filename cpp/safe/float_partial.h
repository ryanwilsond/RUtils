#pragma once
#ifndef SAFE_FLOAT_PARTIAL_H
#define SAFE_FLOAT_PARTIAL_H

#include "../base.h"
#include "float.h"
#include "int.h"

_RUTILS

Float::Float(const Int& value) {
    IsNull = value.IsNull;

    if (!IsNull)
        value_ = value.Value();
}

_RUTILS_END

#endif
