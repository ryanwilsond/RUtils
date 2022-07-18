#include "Utils.hpp"

#include "Program.cpp"

int main(int argc, char **argv) {
    vector<string> args;

    for (int i=0; i<argc; i++) {
        args.push_back(argv[i]);
    }

    return IPHelper::Program::Main(args);
}
