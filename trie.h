#ifndef TRIE_H
#define TRIE_H

#include "node.h"

class Trie
{
private:
    Node_ *cursor_, *root_;
public:
    Trie();
    ~Trie();

    inline std::string cursor_value() { return cursor_->value(); }

    void insert(const char &mark);
    void move_cursor(const char &mark);
};

#endif // TRIE_H
