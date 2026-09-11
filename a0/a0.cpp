#include <iostream>
using namespace std;
auto main() -> int {
    std::string subject, name, number, email, repo;
    std::cout << "### Assignment Zero ###" << std::endl
        << "Subject and Section:" << std::endl;
    std::cin >> subject;
    std::cout << subject << std::endl
        << "Name:" << std::endl;
    std::cin >> name;
    std::cout << name << std::endl
        << "Student Number:" << std::endl;
    std::cin >> number;
    std::cout << number << std::endl
        << "Email:" << std::endl;
    std::cin >> email;
    std::cout << email << std::endl
        << "Github repository:" << std::endl;
    std::cin >> repo;
    std::cout << repo << std::endl;
    return 0;
}