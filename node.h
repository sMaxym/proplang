#ifndef NODE_H
#define NODE_H

#include <map>
#include <string>

class Node_
{
private:
    std::map<char, Node_> edges_;
    std::string value_;
public:
    Node_() = default;
    Node_(const std::string& value);
    Node_(std::string &&value);

    inline std::string value() { return value_; }
    inline bool has_edge(const char &mark) { return edges_.find(mark) != edges_.end(); }
    inline bool is_leaf() { return edges_.empty(); }

    Node_* edge(const char& mark);
    void add_edge(const char& mark);
};

#endif // NODE_H
