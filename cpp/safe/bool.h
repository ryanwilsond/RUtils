#pragma once
#ifndef SAFE_BOOL_H
#define SAFE_BOOL_H

#include "../base.h"
#include "nullable.h"

_RUTILS

class Bool {
private:

    bool value_ = false;

public:

    bool IsNull = false;

    Bool() {
        IsNull = true;
    }

    Bool(Null) {
        IsNull = true;
    }

    Bool(bool value) {
        value_ = value;
    }

    Bool(const Bool& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();
    }

    /// Gets value if not null
    /// @returns value
    /// @throws NullReferenceException
    bool Value() const {
        if (IsNull)
            throw NullReferenceException;

        return value_;
    }

    Bool& operator=(bool value) {
        IsNull = false;
        value_ = value;
        return *this;
    }

    Bool& operator=(const Bool& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();

        return *this;
    }

    Bool& operator=(Null) {
        IsNull = true;
        return *this;
    }

    bool operator==(const Bool& value) {
        if (IsNull && value.IsNull)
            return true;

        return Value() == value.Value();
    }

    bool operator!=(const Bool& value) {
        if (IsNull != value.IsNull)
            return true;

        if (IsNull && value.IsNull)
            return false;

        return Value() != value.Value();
    }

    Bool operator&(const Bool& value) {
        if (IsNull || value.IsNull)
            return null;

        return Bool(Value() & value.Value());
    }

    Bool operator|(const Bool& value) {
        if (IsNull || value.IsNull)
            return null;

        return Bool(Value() | value.Value());
    }

    Bool operator!() {
        if (IsNull)
            return null;

        return Bool(Value());
    }

    Bool& operator&=(const Bool& value) {
        if (IsNull || value.IsNull) {
            IsNull = true;
            return *this;
        }

        value_ = Value() & value.Value();
        return *this;
    }

    Bool& operator|=(const Bool& value) {
        if (IsNull || value.IsNull) {
            IsNull = true;
            return *this;
        }

        value_ = Value() | value.Value();
        return *this;
    }

};

_RUTILS_END

#endif
