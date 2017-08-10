#include "data_structures/messages/Message.h"

namespace m2 {
namespace routing {

Message::Message(const NodeInfo &node_info, const MessageType message_type)
    : node_info(node_info), message_type(message_type) {}

Message::~Message() {}

PingRequestMessage::PingRequestMessage(const NodeInfo &node_info)
   : Message(node_info, MessageType::PingRequest) {}

StoreRequestMessage::StoreRequestMessage(const NodeInfo &node_info, const NodeInfo &store_node_info)
   : Message(node_info, MessageType::StoreRequest), store_node_info(store_node_info) {}

FindNodeRequestMessage::FindNodeRequestMessage(const NodeInfo &node_info, const uuid guid)
   : Message(node_info, MessageType::FindNodeRequest), guid(guid) {}

FindDataRequestMessage::FindDataRequestMessage(const NodeInfo &node_info, const uuid guid)
   : Message(node_info, MessageType::FindDataRequest), guid(guid) {}

PingResponseMessage::PingResponseMessage(const NodeInfo &node_info)
   : Message(node_info, MessageType::PingResponse) {}

StoreResponseMessage::StoreResponseMessage(const NodeInfo &node_info)
   : Message(node_info, MessageType::StoreResponse) {}

FindNodeResponseMessage::FindNodeResponseMessage(const NodeInfo &node_info, const std::vector<NodeInfo> &found_nodes_info)
   : Message(node_info, MessageType::FindNodeResponse), found_nodes_info(found_nodes_info) {}

FindDataResponseMessage::FindDataResponseMessage(const NodeInfo &node_info, const std::string domain)
   : Message(node_info, MessageType::FindDataResponse), domain(domain) {}

} // namespace routing
} // namespace m2
