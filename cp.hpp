#include<iostream>
#include<string>
#include "argparse.hpp"
#include<filesystem>
class Copy
{
    public:
    std::string src ; 
    std::string des ;
    int argc ;
    char * argv[] ;
    Copy(int argc , char * argv[]);
    void run(argparse::ArgumentParser & program); 
};