#ifndef STR_TRIM_H
#define STR_TRIM_H

#include <string>
#include <vector>

const std::string WHITESPACE = " \n\r\t\f\v";

// https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
std::string ltrim(const std::string& s);
std::string rtrim(const std::string& s);
std::string trim(const std::string& s);

std::vector<std::string> split(const std::string &delim);

#endif // STR_TRIM_H
