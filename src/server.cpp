#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_fd < 0)
    { 
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    std::cout << "Socket created! FD = " << server_fd << "\n";

    sockaddr_in address{}; // Initialize the address structure
    address.sin_family = AF_INET; // IPv4
    address.sin_addr.s_addr = INADDR_ANY; // Accept connections from any IP address
    address.sin_port = htons(8080); // Port 8080

    if (bind(server_fd, reinterpret_cast<struct sockaddr*>(&address), sizeof(address)) < 0)
    {
        std::cerr << "Bind failed\n";
        close(server_fd);
        return 1;
    }
    
    std::cout << "Socket bound to port 8080\n";

    return 0;
}