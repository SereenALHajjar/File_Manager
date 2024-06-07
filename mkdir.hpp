#include<iostream>
#include<string>
#include "argparse.hpp"
#include <filesystem>

class MakeDirectory
{
    public:
        std::string path ; 
        int argc ; 
        char * argv[] ;
        MakeDirectory(int argc , char * argv []);
        void run(argparse::ArgumentParser & program);
};