#pragma once
#ifndef SAFE_FLOAT_H
#define SAFE_FLOAT_H

#include "../base.h"
#include "nullable.h"

_RUTILS

class Int;

class Float {
private:

    float value_ = 0;

public:

    bool IsNull = false;

    Float() {
        IsNull = true;
    }

    Float(Null) {
        IsNull = true;
    }

    Float(float value) {
        value_ = value;
    }

    Float(const Int& value);

    Float(const Float& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();
    }

    /// Gets value if not null
    /// @returns value
    /// @throws NullReferenceException
    float Value() const {
        if (IsNull)
            throw NullReferenceException;

        return value_;
    }

    Float& operator=(float value) {
        IsNull = false;
        value_ = value;
        return *this;
    }

    Float& operator=(const Float& value) {
        IsNull = value.IsNull;

        if (!IsNull)
            value_ = value.Value();

        return *this;
    }

    Float& operator=(Null) {
        IsNull = true;
        return *this;
    }

    bool operator==(const Float& value) {
        if (IsNull && value.IsNull)
            return true;

        return Value() == value.Value();
    }

    bool operator!=(const Float& value) {
        if (IsNull != value.IsNull)
            return true;

        if (IsNull && value.IsNull)
            return false;

        return Value() != value.Value();
    }

    Float operator+(const Float& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() + value.Value();
    }

    Float operator-(const Float& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() - value.Value();
    }

    Float operator*(const Float& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() * value.Value();
    }

    Float operator/(const Float& value) {
        if (IsNull || value.IsNull)
            return null;

        return Value() / value.Value();
    }

    Float& operator++() {
        if (!IsNull)
            value_++;

        return *this;
    }

    Float& operator--() {
        if (!IsNull)
            value_--;

        return *this;
    }

    Float operator+() {
        if (IsNull)
            return null;

        return Value();
    }

    Float operator-() {
        if (IsNull)
            return null;

        return -Value();
    }

    bool operator<(const Float& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() < value.Value();
    }

    bool operator>(const Float& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() > value.Value();
    }

    bool operator<=(const Float& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() <= value.Value();
    }

    bool operator>=(const Float& value) {
        if (IsNull || value.IsNull)
            return false;

        return Value() >= value.Value();
    }

    Float& operator+=(const Float& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ += value.Value();

        return *this;
    }

    Float& operator-=(const Float& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ -= value.Value();

        return *this;
    }

    Float& operator*=(const Float& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ *= value.Value();

        return *this;
    }

    Float& operator/=(const Float& value) {
        if (IsNull || value.IsNull)
            IsNull = true;
        else
            value_ /= value.Value();

        return *this;
    }

};

_RUTILS_END

#endif
