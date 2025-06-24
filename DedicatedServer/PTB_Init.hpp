int PORT = 8080;
#include "pugixml.hpp"



const char* SERVER_IP = "127.0.0.1"; // Connect to IP_ADDRESS_WARFACE_DEDICATED

int bomb_state = 0;

void sendMessage(int socket, const std::string& message) {
    send(socket, message.c_str(), message.length(), 0);
    std::cout << "Сообщение отправлено: " << message << std::endl;
}

int socket_c;

bool srv = false;

void InitPtbMode(bool server)
{
    server = srv;
    if (!server)
    {
        WSADATA wsaData;
        SOCKET sock;
        sockaddr_in serverAddr;
        char buffer[1024];

        // Инициализация Winsock
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создание сокета
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == INVALID_SOCKET) {
            std::cerr << "Ошибка создания сокета" << std::endl;
            return;
        }

        // Настройка адреса сервера
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_port = htons(PORT);
        serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");



        // Подключение к серверу
        if (connect(sock, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
            std::cerr << "Ошибка подключения к серверу" << std::endl;
            return;
        }

        // Основной цикл
        while (true) {
            // Получение сообщения от сервера
            memset(buffer, 0, sizeof(buffer));
            int bytesRead = recv(sock, buffer, sizeof(buffer), 0);
            if (bytesRead > 0)
            {
                buffer[bytesRead] = '\0';

                // CLIENT

                pugi::xml_document doc;
                const char* xml = buffer;
                pugi::xml_parse_result result = doc.load_string(xml);
                if (result) {
                    pugi::xml_node load_software = doc.child("receive_entity");

                    if (!load_software.empty()) {
                        const char* offset_x = load_software.attribute("x").value();
                        const char* offset_y = load_software.attribute("y").value();
                        const char* offset_z = load_software.attribute("z").value();

                        printf("offset_y\n");


                    }

                }




            }



            //sendMessage(sock, client_message);
        }
    }
    else {
        WSADATA wsaData;
        SOCKET serverSocket, clientSocket;
        sockaddr_in serverAddr, clientAddr;
        int addrLen = sizeof(clientAddr);
        char buffer[1024];

        // Инициализация Winsock
        WSAStartup(MAKEWORD(2, 2), &wsaData);

        // Создание сокета
        serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (serverSocket == INVALID_SOCKET) {
            std::cerr << "ERROR CREATE SOCKET" << std::endl;
            return;
        }

        // Настройка адреса сервера
        serverAddr.sin_family = AF_INET;
        serverAddr.sin_addr.s_addr = INADDR_ANY;
        serverAddr.sin_port = htons(PORT);

        // Привязка сокета
        bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
        listen(serverSocket, SOMAXCONN);

        std::cout << "WAIT CONNECTIONS" << std::endl;

        // Принятие подключения клиента
        clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &addrLen);

        socket_c = clientSocket;

        std::cout << "CLIENT CONNECTING" << std::endl;

        // Основной цикл
        while (true) {

        }
    }


}

void PrepareInitPtbMode(bool s) 
{
    srv = s;
    CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)InitPtbMode, NULL, 0, NULL);
}