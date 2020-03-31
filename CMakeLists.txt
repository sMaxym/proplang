cmake_minimum_required(VERSION 3.5)

project(PropLang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(PropLang main.cpp trie.cpp trie.h node.cpp node.h syntax.cpp syntax.h str_trim.h str_trim.cpp)
