#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <stdexcept>

#include "str_trim.h"
#include "syntax.h"

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cout << "Proper *.prop file is required as input" << std::endl;
        return 1;
    }

    std::ifstream file_in(argv[1], std::fstream::in);
    std::string prg( (std::istreambuf_iterator<char>(file_in)), (std::istreambuf_iterator<char>()) );
    file_in.close();

    const std::string avail = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890_";

    std::vector<std::string> keyw, parsed;
    keyw.push_back("<=>");
    keyw.push_back("in");
    keyw.push_back("=>");
    keyw.push_back(":=");
    keyw.push_back("<>");
    keyw.push_back("out");
    keyw.push_back(",");
    keyw.push_back("(");
    keyw.push_back(")");
    keyw.push_back("~");
    keyw.push_back("+");
    keyw.push_back("^");
    Trie t = build_syntax(keyw);


    parsed = parse_program(prg, t);

    for (const std::string &word: parsed)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
