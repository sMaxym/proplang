#include "node.h"

Node_::Node_(const std::string& value) : value_(value)
{}

Node_::Node_(std::string &&value)
{
    value_ = std::move(value);
}

void Node_::add_edge(const char& mark)
{
    edges_[mark] = Node_(value_ + mark);
}

Node_* Node_::edge(const char& mark)
{
    return &(edges_[mark]);
}
