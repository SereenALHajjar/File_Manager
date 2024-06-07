#include "ls.hpp"

ListFiles::ListFiles(int argc, char *argv[])
{
    this->argc = argc;
    for (int i = 0; i < argc; i++)
    {
        this->argv[i] = argv[i];
    }
    // define argparser
    argparse::ArgumentParser program("list files");
    // add args
    // program.add_argument("command");
    program.add_argument("path").help("path to list").default_value(".");

    // run
    run(program);
}

void ListFiles::run(argparse::ArgumentParser &program)
{
    // try parse
    try
    {
        program.parse_args(this->argc, this->argv);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->path = program.get<std::string>("path");
    // extract argument
    try
    {
        for (const auto &entry : std::filesystem::directory_iterator(path))
        {
            std::cout << entry.path().string();
            if (std::filesystem::is_directory(entry.path()))
            {
                std::cout << " [directory]";
            }
            else if (std::filesystem::is_regular_file(entry.path()))
            {
                std::cout << " [file]";
            }
            std::cout << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}