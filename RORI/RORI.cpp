#include <iostream>
#include <string>

#include "RORI.h"


RORI::RORI()
{
    welcomeMessage();
    startServer();
}

/**
 * @brief RORI::welcomeMessage say hello :)
 */
void RORI::welcomeMessage()
{
    QTextStream qout(stdout);
    qout << "8888888b.       .d88888b.      8888888b.      8888888     \n"
            "888   Y88b     d88P\" \"Y88b     888   Y88b       888       \n"
            "888    888     888     888     888    888       888       \n"
            "888   d88P     888     888     888   d88P       888       \n"
            "8888888P\"      888     888     8888888P\"        888       \n"
            "888 T88b       888     888     888 T88b         888       \n"
            "888  T88b  d8b Y88b. .d88P d8b 888  T88b  d8b   888   d8b \n"
            "888   T88b Y8P  \"Y88888P\"  Y8P 888   T88b Y8P 8888888 Y8P\n"
            "\n"
            "=========================================================\n"
            "RORI v2.0.1 by AmarOk1412 (http://enconn.fr/)\n"
            "A free, flexible & open-source chatterbot\n"
            "wtfpl : http://www.wtfpl.net/\n"
            "<3 making free projects\n"
            "=========================================================\n\n"
            "RORI is starting...\n";
}


/**
 * @brief RORI::startServer begin the server.
 */
void RORI::startServer()
{
    server = new QTcpServer(0);
    bool fail = false;
    if (!server->listen(QHostAddress::Any, 1412))
    {
        QTextStream qout(stdout);
        qout << "Server can't run\nExit\n";
        fail = true;
    }
    else
    {
        QTextStream qout(stdout);
        qout << "Server is running\n";
        //connect(server, SIGNAL(newConnection()), this, SLOT(newConnection()));
    }

    if(fail)
        exit(0);
}
