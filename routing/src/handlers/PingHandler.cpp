#include "handlers/PingHandler.h"

namespace m2 {
namespace routing {

PingHandler::PingHandler(Node& node) : CommandHandler(node), NodeContainingObject(node)
{
}


PingHandler::~PingHandler()
{
}

void PingHandler::handleMessage(Message & message)
{
}

}
}