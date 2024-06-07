#include <string>
#include "argparse.hpp"
#include <filesystem>

class Move
{
    public:
    std::string src;
    std::string des;
    int argc;
    char *argv[];
    Move(int argc, char *argv[]);
    void run(argparse::ArgumentParser &program);
};