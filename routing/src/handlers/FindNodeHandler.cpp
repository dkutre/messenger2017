#include "handlers/FindNodeHandler.h"

namespace m2 {
namespace routing {

FindNodeHandler::FindNodeHandler(Node& node):node(node)
{
}

FindNodeHandler::~FindNodeHandler()
{
}

Message* FindNodeHandler::handleMessage(Message message)
{
    //Guid guid = message.getGuid();
    //std::list<NodeInfo> neighbours = node->kbucket_manager.getNeighbours(guid);
    //Message* reply = new Message(/*parameters*/);
    ////initialize reply with data
    //return reply;
    return NULL;
}

} // namespace routing
} // namespace m2
