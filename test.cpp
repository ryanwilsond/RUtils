#include <stdio.h>
#include <exception>
#include <string>

class FileNotFound : std::exception {

    std::string path_;

public:

    FileNotFound& operator()(std::string path) {
        path_ = path;
        return *this;
    }

    virtual const char* what() const throw() {
        std::string message = std::string("No such file '") + path_ + "'";
        return message.c_str();
    }

} FileNotFoundException;


int main() {
    throw FileNotFoundException;

    return 0;
}