#include<iostream>
#include<string>
#include "argparse.hpp"
#include<filesystem>

class ListFiles
{
    public :
    std::string path ; 
    int argc ;
    char * argv [] ;
    ListFiles(int argc , char * argv[]) ;
    void run(argparse::ArgumentParser & program) ;
};