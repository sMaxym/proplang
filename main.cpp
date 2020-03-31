#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <stdexcept>

#include "syntax.h"

const std::string WHITESPACE = " \n\r\t\f\v";

// https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);

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

    std::vector<std::string> keyw;
    keyw.push_back("<=>");
    keyw.push_back("in");
    keyw.push_back("=>");
    keyw.push_back(":=");
    keyw.push_back("<>");
    keyw.push_back("out");
    keyw.push_back(",");
    Trie t = build_syntax(keyw);

    std::cout << t.cursor_value() << std::endl;

    return 0;
}

std::string ltrim(const std::string& s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s)
{
    return rtrim(ltrim(s));
}
