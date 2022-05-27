#pragma once
#ifndef IO_PATH_H
#define IO_PATH_H

#include <string>

#include "../base.h"
#include "../safe/safe.h"

_RUTILS

class Path {
public:

    Path(std::string path) {}

    Path(Nullable<std::string> path) {}

    Path()

};

_RUTILS_END

#endif
