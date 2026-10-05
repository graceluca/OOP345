#include <iostream>
using namespace std;
auto main() -> int {
    std::string subject, name, number, email, repo;
    std::cout << "#### Assignment Zero ####" << std::endl
        << "Subject and Section:" << std::endl;
    std::cin >> subject;
    std::cout
        << "Name:" << std::endl;
    std::cin >> name;
    std::cout
        << "Student Number:" << std::endl;
    std::cin >> number;
    std::cout
        << "Email:" << std::endl;
    std::cin >> email;
    std::cout
        << "Github repository:" << std::endl;
    std::cin >> repo;
    return 0;
}