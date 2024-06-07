#include <string>
#include "argparse.hpp"
#include <filesystem>

class ChangeDirectory
{
    public:
    std::string path ; 
    int argc ;
    char *argv[] ;
    ChangeDirectory(int argc , char * argv[]);
    void run(argparse::ArgumentParser & program) ;

};