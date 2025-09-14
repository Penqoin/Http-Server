#include "Socket.hpp"
#include <iostream>

int main (int argc, char *argv[]) {
    

    std::string t;
    Socket c;
    while (true) 
    {
        std::cout << "Do you want to be server or socket(c/s): " << std::endl;
        std:: cin >> t;

        if (t == "c")
        {
            c.connect();
            std::string m;
            while (true)
            {
                std::cout << "Please send a message" << std::endl;
                std::cin >> m;
                c.send(m.c_str());
            }
        }
        else if (t == "s")
        {
            c.bind();
            c.listen();
        }
    }

    return 0;
}
