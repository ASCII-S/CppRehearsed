#include <iostream>

const std::string VERSION = "1.0.0";
bool debug_mode = true;

namespace Config
{
    int max_connections = 100;
}

void print_connections()
{
    std::cout << "max_connections: " << Config::max_connections << std::endl;
    std::cout << "debug_mode: " << debug_mode << std::endl;
    std::cout << "VERSION: " << VERSION << std::endl;
}