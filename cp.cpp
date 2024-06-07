#include "cp.hpp"

Copy::Copy(int argc, char *argv[])
{
    this->argc = argc;
    for (int i = 0; i < argc; i++)
        this->argv[i] = argv[i];
    // define argparser
    argparse::ArgumentParser program("change directory");
    // add args
    // program.add_argument("command");
    program.add_argument("src").default_value(".");
    program.add_argument("des");

    // run
    run(program);
}

void Copy::run(argparse::ArgumentParser &program)
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
    this->src = program.get<std::string>("src");
    this->des = program.get<std::string>("des");

    // copy
    try
    {
        std::filesystem::copy(src, des, std::filesystem::copy_options::recursive | std::filesystem::copy_options::overwrite_existing);
        std::cout << "File copied successfully." << std::endl;
    }
    catch (const std::exception &err)
    {
        std::cerr << "Error: " << err.what() << std::endl;
    }
}