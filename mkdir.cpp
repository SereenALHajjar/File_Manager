#include "mkdir.hpp"

MakeDirectory::MakeDirectory(int argc, char *argv[])
{
    this->argc = argc;
    for (int i = 0; i < argc; i++)
        this->argv[i] = argv[i];
    // define argparser
    argparse::ArgumentParser program("Make Directory");
    // add args
    // program.add_argument("command");
    program.add_argument("path");

    // run
    run(program);
}

void MakeDirectory::run(argparse::ArgumentParser &program)
{
    // try parse
    try
    {
        program.parse_args(this->argc, this->argv);
    }
    catch (const std::exception &err)
    {
        // std::cout<<"error here ya sereen \n" ;
        std::cout << err.what() << std::endl;
    }
    // extract args
    this->path = program.get<std::string>("path");
    try
    {
        bool ok = std::filesystem::create_directory(this->path);
        std::cout << "Directory created successfully: " << (this->path)<<" "<<ok << std::endl;
    }
    catch (const std::exception &err)
    {
        std::cerr << "Error creating directory: " << err.what() << std::endl;
    }
}