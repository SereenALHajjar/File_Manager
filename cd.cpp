#include "cd.hpp"

ChangeDirectory::ChangeDirectory(int argc, char *argv[])
{
    this -> argc = argc;
    for(int i=0 ; i<argc ; i++)
        this -> argv[i] = argv[i] ;
    // define argparser
    argparse::ArgumentParser program("change directory");
    // add args
    // program.add_argument("command") ;
    program.add_argument("path");

    // run
    run(program);

}
void ChangeDirectory::run(argparse::ArgumentParser &program)
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
    this->path = program.get<std::string>("path");

    // change dir
    try
    {
        std::filesystem::current_path(path);
        std::cout<<"your current path now is :"<<std::filesystem::current_path()<<std::endl ;
    }
    catch (const std::exception &err)
    {
        std::cout<<err.what()<<std::endl ;
    }
}
