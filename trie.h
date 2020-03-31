#ifndef TRIE_H
#define TRIE_H

#include "node.h"

class Trie
{
private:
    Node_ *cursor_, *root_;
public:
    Trie();

    inline std::string cursor_value() { return cursor_->value(); }
    inline bool has_edge(const char &mark) { return cursor_->has_edge(mark); }
    inline bool is_leaf() { return cursor_->is_leaf(); }
    inline void reset_cursor() { cursor_ = root_; }

    void insert(const char &mark);
    void move_cursor(const char &mark);


    //destructors
};

#endif // TRIE_H
