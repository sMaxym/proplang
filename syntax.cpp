#include "syntax.h"

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
