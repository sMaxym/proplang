#include "syntax.h"
#include "str_trim.h"

Trie build_syntax(const std::vector<std::string> &keywords)
{
    Trie syntax_trie;
    for (const auto &keyword: keywords)
    {
        for (const auto &c: keyword)
        {
            if (!syntax_trie.has_edge(c))
            {
                syntax_trie.insert(c);
            }
            syntax_trie.move_cursor(c);
        }
        syntax_trie.reset_cursor();
    }
    return syntax_trie;
}

std::vector<std::string> parse_program(const std::string &prg, Trie &syntax)
{
    std::vector<std::string> parsed;
    std::string prop = "", buffer = "";
    for (const char &c: prg)
    {
        if (syntax.has_edge(c))
        {
            syntax.move_cursor(c);
            if (buffer.empty())
            {
                buffer = prop;
            }
            buffer += c;
        }
        else
        {
            syntax.reset_cursor();
            if (!buffer.empty())
            {
                prop = buffer;
                buffer.clear();
            }
            prop += c;
        }
        if (syntax.is_leaf())
        {
            buffer.clear();
            prop = trim(prop);
            if (!prop.empty())
            {
                parsed.push_back(prop);
                prop.clear();
            }
            parsed.push_back(syntax.cursor_value());
            syntax.reset_cursor();
        }
    }
    prop = trim(prop);
    parsed.push_back(prop);
    return parsed;
}

std::vector<std::string> parse_propositions(const std::string &toparse)
{
    std::string props = trim(toparse);

}

bool is_proposition(const std::string &prop, const std::string &avail)
{
    bool is_prop = true;
    std::for_each(prop.begin(), prop.end(),
                  [avail, &is_prop](const char &c){ is_prop &= (avail.find(c) != std::string::npos); });
    return is_prop;
}
