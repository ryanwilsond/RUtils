#pragma once
#ifndef SAFE_INT_H
#define SAFE_INT_H

#include "../base.h"
#include "nullable.h"

_RUTILS

class Float;

class Int {
private:

    int value_ = 0;

public:

    bool IsNull = false;

    Int() {
        IsNull = true;
    }

    Int(Null) {
        IsNull = true;
    }

    Int(int value) {
        value_ = value;
    }

    Int(const Int& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();
    }

    explicit Int(float value) {
        value_ = (int)value;
    }

    explicit Int(const Float& value);

    /// Gets value if not null
    /// @returns value
    /// @throws NullReferenceException
    int Value() const {
        if (IsNull)
            throw NullReferenceException;

        return value_;
    }

    Int& operator=(int value) {
        IsNull = false;
        value_ = value;
        return *this;
    }

    Int& operator=(const Int& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();

        return *this;
    }

    Int& operator=(Null) {
        IsNull = true;
        return *this;
    }

    bool operator==(const Int& value) {
        if (IsNull && value.IsNull)
            return true;

        return Value() == value.Value();
    }

    bool operator!=(const Int& value) {
        if (IsNull != value.IsNull)
            return true;

        if (IsNull && value.IsNull)
            return false;

        return Value() != value.Value();
    }

    Int operator+(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() + value.Value();
    }

    Int operator-(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() - value.Value();
    }

    Int operator*(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() * value.Value();
    }

    Int operator/(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() / value.Value();
    }

    Int operator%(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() % value.Value();
    }

    Int operator^(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() ^ value.Value();
    }

    Int operator&(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() & value.Value();
    }

    Int operator|(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() | value.Value();
    }

    Int operator<<(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() << value.Value();
    }

    Int operator>>(const Int& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() >> value.Value();
    }

    Int operator~() {
        if (IsNull)
            return null;

        return ~Value();
    }

    Int& operator++() {
        if (!IsNull)
            value_++;

        return *this;
    }

    Int& operator--() {
        if (!IsNull)
            value_--;

        return *this;
    }

    Int operator+() {
        if (IsNull)
            return null;

        return Value();
    }

    Int operator-() {
        if (IsNull)
            return null;

        return -Value();
    }

    bool operator<(const Int& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() < value.Value();
    }

    bool operator>(const Int& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() > value.Value();
    }

    bool operator<=(const Int& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() <= value.Value();
    }

    bool operator>=(const Int& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() >= value.Value();
    }

    Int& operator+=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ += value.Value();

        return *this;
    }

    Int& operator-=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ -= value.Value();

        return *this;
    }

    Int& operator*=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ *= value.Value();

        return *this;
    }

    Int& operator/=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ /= value.Value();

        return *this;
    }

    Int& operator%=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ %= value.Value();

        return *this;
    }

    Int& operator^=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ ^= value.Value();

        return *this;
    }

    Int& operator&=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ &= value.Value();

        return *this;
    }

    Int& operator|=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ |= value.Value();

        return *this;
    }

    Int& operator<<=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ <<= value.Value();

        return *this;
    }

    Int& operator>>=(const Int& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ >>= value.Value();

        return *this;
    }

};

_RUTILS_END

#endif
