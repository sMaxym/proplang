#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include <stdexcept>

#include "trie.h"

const std::string WHITESPACE = " \n\r\t\f\v";

// https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);

// parsing => handling / in different function
    // output expressions should be without triling whitespaces in proper form
void expressions(const std::string &program, std::vector<std::string> &exps);
template<typename Key, typename Value>
int execute_expression(const std::string &expression, std::map<Key, Value> &props);

std::string proposition(std::string toparse);
template<typename Key, typename Value>
void read_proposition(const std::string &proposition, std::map<Key, Value> &props);

std::vector<std::string> formula(std::string toparse);
std::vector<std::string> formula2RPN(const std::vector<std::string> &formula);


std::vector<std::string> parse_words(const std::string& program);
bool consist(const std::string &word, const std::string &sub_str);



int main(int argc, char** argv)
{
//    if (argc != 2)
//    {
//        std::cout << "Proper *.prop file is required as input" << std::endl;
//        return 1;
//    }

//    std::ifstream file_in(argv[1], std::fstream::in);
//    std::string prg( (std::istreambuf_iterator<char>(file_in)), (std::istreambuf_iterator<char>()) );
//    file_in.close();

//    Trie t;
//    std::cout << t.cursor_value() << std::endl;
//    t.insert(':');
//    t.insert('(');
//    t.move_cursor(':');
//    std::cout << t.cursor_value() << std::endl;
//    t.insert('=');
//    t.move_cursor('=');
//    std::cout << t.cursor_value() << std::endl;


//    Node n("value");


    return 0;
}

bool consist(const std::string &word, const std::string &sub_word)
{
    return word.find(sub_word) != std::string::npos;
}

std::vector<std::string> parse_words(const std::string& program)
{
    std::vector<std::string> words;
    std::string buffer = "";
    return     std::vector<std::string>();
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






void expressions(const std::string &program, std::vector<std::string> &exps)
{
    std::string exp_buffer = "";
    for (const char &c: program)
    {
        if (c == ',')
        {
            exps.push_back(ltrim(exp_buffer));
            exp_buffer.clear();
            continue;
        }
        exp_buffer += c;
    }
    exps.push_back(trim(exp_buffer));
}

std::string proposition(std::string toparse)
{
    std::string PROP_SYMB = "_0987654321abcdefghijklmnopqrstvuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string prop = "";
    toparse = trim(toparse);
    for (const auto &c: toparse)
    {
        if (PROP_SYMB.find(c) == std::string::npos)
        {
            std::cout << c << std::endl;
            throw std::invalid_argument("Wrong proposition name");
        }
        prop += c;
    }
    return prop;
}

template<typename Key, typename Value>
void read_proposition(const std::string &proposition, std::map<Key, Value> &props)
{
    std::string val_true[] = {"1", "T", "true"}, val_false[] = {"0", "F", "false"};
    std::string in_val;
    std::cin >> in_val;
    for (size_t i = 0; i < 3; i++)
    {
        if (in_val == val_true[i])
        {
            props[proposition] = 1;
            return;
        }
        if (in_val == val_false[i])
        {
            props[proposition] = 0;
            return;
        }
    }
    throw std::invalid_argument("Invalid proposition value");
}

//std::vector<std::string> formula(std::string toparse)
//{
//    std::string PROP_SYMB = "_0987654321abcdefghijklmnopqrstvuwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
//    std::vector<std::string> formula;
//    std::string buffer = "";
//    toparse = trim(toparse);
//    for (const char &c: toparse)
//    {
//        if (PROP_SYMB.find(c) == std::string::npos)
//        {

//        }
//    }
//}

// todo: instread of int call exception
template<typename Key, typename Value>
int execute_expression(const std::string &expression, std::map<Key, Value> &props)
{
    std::string buffer = "", operand_a = "", operand_b = "", toparse;
    std::vector<std::string> formula_infix, RPN;
    size_t keyword_index = 0;

    // IN
    keyword_index = expression.find("in");
    if (keyword_index != std::string::npos)
    {
        toparse = expression.substr(keyword_index + 2, expression.size() - 2);
        // parsing
        operand_a = proposition(toparse);
        // handling
        read_proposition(operand_a, props);
    }

    // OUT
    keyword_index = expression.find("out");
    if (keyword_index != std::string::npos)
    {
        toparse = expression.substr(keyword_index + 3, expression.size() - 3);
        // parsing
        formula_infix = formula(toparse);
        // handling
        RPN = formula2RPN(formula_infix);
    }


    return 0;
}


