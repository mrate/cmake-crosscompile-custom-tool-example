#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Invalid args\n";
        return -1;
    }

    const auto source { argv[1] };
    const auto target { argv[2] };
    const auto platform { argv[3] };
 
    std::cout << "Hello, I'm a complete tool!\n";
    std::cout << "Tooling " << source << " => " << target << "\n";
 
    std::ofstream out { target };
    out << "#pragma once\n";
    out << "// target-platform=" << platform << "\n";

    return 0;
}