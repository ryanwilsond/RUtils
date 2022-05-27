#pragma once
#ifndef IO_EXCEPTIONS_H
#define IO_EXCEPTIONS_H

#include <exception>

#include "../base.h"

_RUTILS

class FileNotFound : std::exception {

    std::string path_ = "";

public:

    FileNotFound& operator()(std::string path) {
        path_ = path;
        return *this;
    }

    virtual const char* what() const throw() {
        std::string message;

        if (path_.empty())
            message = "No such file";
        else
            message = std::string("No such file '") + path_ + "'";

        return message.c_str();
    }

} FileNotFoundException;

_RUTILS_END

#endif
