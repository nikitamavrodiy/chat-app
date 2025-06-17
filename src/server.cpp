#include <iostream>
#include <cstring> 
#include <sys/socket.h> 
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    std::cout << "Socket created! FD = " << server_fd << "\n";
    return 0;
}