// ToDo := Copyright

#include "Define.h"  //NOMINMAX FIX
#include "RabbitConnectionHandler.h"

#include <amqpcpp.h>
#include <chrono>
#include <thread>

int main(int argc, char* argv[])
{

    RabbitConnectionHandler handler;

    AMQP::Connection connection(&handler, AMQP::Login("guest", "guest"), "/");

    AMQP::Channel channel(&connection);

    // use the channel object to call the AMQP method you like
    channel.declareExchange("my-exchange", AMQP::fanout);
    channel.declareQueue("my-queue");
    channel.bindQueue("my-exchange", "my-queue", "my-routing-key");

    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

	return 0;
}