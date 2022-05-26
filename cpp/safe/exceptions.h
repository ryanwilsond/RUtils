#pragma once
#ifndef SAFE_EXCEPTIONS_H
#define SAFE_EXCEPTIONS_H

#include <exception>

#include "../base.h"

_RUTILS

class NullReference : public std::exception {

    virtual const char* what() const throw() {
        return "Nullable object must have a value.";
    }

} NullReferenceException;

class UndefinedReference : public std::exception {

    virtual const char* what() const throw() {
        return "Object must have a value.";
    }

} UndefinedReferenceException;

_RUTILS_END

#endif
