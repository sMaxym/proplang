#include "trie.h"

Trie::Trie()
{
    root_ = new Node_("");
    cursor_ = root_;
}

void Trie::insert(const char &mark)
{
    root_->add_edge(mark);
}

void Trie::move_cursor(const char &mark)
{
    cursor_ = cursor_->edge(mark);
}
