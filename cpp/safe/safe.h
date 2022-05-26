#pragma once
#ifndef SAFE_SAFE_H
#define SAFE_SAFE_H

#include "../base.h"
#include "bool.h"
#include "nullable.h"
#include "int.h"
#include "int_partial.h"
#include "float.h"
#include "float_partial.h"
#include "exceptions.h"

_RUTILS

template<typename T> class Safe : public T {
public:

    bool IsNull = false;

    Safe() {
        IsNull = true;
    }

    Safe(Null) {
        IsNull = true;
    }

    Safe(T value) {
        *this = value;
    }

    Safe(const Safe& value) {
        IsNull = value.IsNull;
        *this = value;
    }

    T& operator=(const T& value) {
        *this = value;
        return *this;
    }

    /// Throws if this was not initialized
    /// @throws UndefinedReferenceException
    void NullCheck() const {
        if (IsNull)
            throw UndefinedReferenceException;
    }

    T const *operator->() const {
        NullCheck();
        return this;
    }

    T *operator->() {
        NullCheck();
        return this;
    }

};

_RUTILS_END

#endif
