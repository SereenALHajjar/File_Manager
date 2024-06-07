#include <iostream>
#include "cd.hpp"
#include "ls.hpp"
#include "cp.hpp"
#include <cstring>
#include "mkdir.hpp"
#include "mv.hpp"
using namespace std;
// cd , ls , mkdir , cp , mv

// cd path

// ls

// mkdir path
// cp src dest
// mv src dest

std::vector<std::string> split(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void convertVectorToCharArray(const std::vector<std::string> &vec, char *arr[])
{
    for (int i = 0; i < vec.size(); ++i)
    {
        arr[i] = new char[vec[i].size() + 1];
        std::strcpy(arr[i], vec[i].c_str());
    }
}

void freeCharArray(char *arr[], size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        delete[] arr[i]; 
    }
}

int main()
{
    string input = "";
    std::cout << "your current path is :" << std::filesystem::current_path() << std::endl;
    while (true)
    {
        std::cout << "> ";
        if (!std::getline(std::cin, input))
        {
            cout<<"from getline"<<endl ;
            break;
        }
        std::vector<std::string> tokens = split(input, ' ');
        if (tokens.empty())
        {
            continue;
        }
        char *argv[tokens.size()];
        int argc = tokens.size();
        convertVectorToCharArray(tokens, argv);
        try
        {

            if (tokens[0] == "cd")
            {
                ChangeDirectory cd(argc, argv);
                cout<<"hello from cd"<<endl ;
            }
            else if (tokens[0] == "ls")
            {
                ListFiles ls(argc, argv);
            }
            else if (tokens[0] == "cp")
            {
                Copy copy(argc, argv);
            }
            else if (tokens[0] == "mkdir")
            {
                MakeDirectory mkdir(argc, argv);
            }
            else if (tokens[0] == "mv")
            {
                Move move(argc, argv);
            }
            else if (tokens[0] == "dir")
            {
                std::cout << "your current path is :" << std::filesystem::current_path() << std::endl;
            }
        }
        catch (const std::exception &e)
        {
            std::cout << "hi from main" << std::endl;
        }
        freeCharArray(argv, argc);
    }
}