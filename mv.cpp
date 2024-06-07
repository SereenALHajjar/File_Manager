#include "mv.hpp"

Move::Move(int argc , char * argv[])
{
    this -> argc = argc;
    for(int i=0 ; i<argc ; i++)
        this -> argv[i] = argv[i] ;
    // define argparser
    argparse::ArgumentParser program("Move Directory And Files");
    // add args
    
    program.add_argument("src");
    program.add_argument("des");


    // run
    run(program);
}

void Move::run(argparse::ArgumentParser & program)
{
    // try parse
    try
    {
        program.parse_args(this->argc, this->argv);
    }
    catch (const std::exception &err)
    {
        // std::cout<<"error here ya sereen \n" ;
        std::cout<<err.what()<<std::endl ;
    }
    // extract args
    this->src = program.get<std::string>("src");
    this->des = program.get<std::string>("des");

    try
    {
        std::filesystem::rename(this->src, this->des);
        std::cout<<"Directory Moved Succefully: "<<this->des<<std::endl;
    }
    catch (const std::exception &err)
    {
        std::cout<<err.what()<<std::endl ;
    }
}