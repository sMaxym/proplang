#ifndef SYNTAX_H
#define SYNTAX_H

#include <vector>
#include <string>
#include <algorithm>

#include "trie.h"

Trie build_syntax(const std::vector<std::string> &keywords);
std::vector<std::string> parse_propositions(const std::string &toparse);
bool is_proposition(const std::string &prop, const std::string &avail);

#endif // SYNTAX_H
