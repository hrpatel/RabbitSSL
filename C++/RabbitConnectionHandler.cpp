// ToDo := Copyright

#include "RabbitConnectionHandler.h"

void RabbitConnectionHandler::onData(AMQP::Connection *connection, const char *data, size_t size)
{
    std::string message(data);
    std::cout << "onData:" << message << std::endl;
}

void RabbitConnectionHandler::onReady(AMQP::Connection *connection)
{
    std::cout << "onReady" << std::endl;
}

void RabbitConnectionHandler::onError(AMQP::Connection *connection, const char *message)
{
    std::cout << "onError" << std::endl;
}

void RabbitConnectionHandler::onClosed(AMQP::Connection *connection)
{
    std::cout << "onClosed" << std::endl;
}
