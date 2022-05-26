#pragma once
#ifndef SAFE_NULLABLE_H
#define SAFE_NULLABLE_H

#include "../base.h"
#include "exceptions.h"

_RUTILS

class Null { } null;

template<typename T> class Nullable {
private:

    T value_;

public:

    bool IsNull = false;

    Nullable() {
        IsNull = true;
    }

    Nullable(Null) {
        IsNull = true;
    }

    Nullable(T value) {
        value_ = value;
    }

    Nullable(const Nullable& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();
    }

    /// Gets value if not null
    /// @returns value
    /// @throws NullReferenceException
    T Value() const {
        if (IsNull)
            throw NullReferenceException;

        return value_;
    }

    Nullable& operator=(T value) {
        IsNull = false;
        value_ = value;
        return *this;
    }

    Nullable& operator=(const Nullable& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();

        return *this;
    }

    Nullable& operator=(Null) {
        IsNull = true;
        return *this;
    }

};

_RUTILS_END

#endif
