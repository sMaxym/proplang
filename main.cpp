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


    std::string prop = "", buffer = "";
    for (const char &c: prg)
    {
        if (t.has_edge(c))
        {
            t.move_cursor(c);
            if (buffer.empty())
            {
                buffer = prop;
            }
            buffer += c;
        }
        else
        {
            t.reset_cursor();
            if (!buffer.empty())
            {
                prop = buffer;
                buffer.clear();
            }
            prop += c;
        }
        if (t.is_leaf())
        {
            buffer.clear();
            prop = trim(prop);
            if (!prop.empty())
            {
                parsed.push_back(prop);
                prop.clear();
            }
            parsed.push_back(t.cursor_value());
            t.reset_cursor();
        }
    }
    prop = trim(prop);
    parsed.push_back(prop);

    for (const std::string &word: parsed)
    {
        std::cout << word << std::endl;
    }

    return 0;
}
