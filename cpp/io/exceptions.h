#pragma once
#ifndef IO_EXCEPTIONS_H
#define IO_EXCEPTIONS_H

#include <exception>

#include "../base.h"

_RUTILS

class FileNotFound : public std::exception {

    virtual const char* what() const throw() {
        return "No such file";
    }

} NullReferenceException;

class UndefinedReference : public std::exception {

    virtual const char* what() const throw() {
        return "Object must have a value.";
    }

} UndefinedReferenceException;

_RUTILS_END

#endif
