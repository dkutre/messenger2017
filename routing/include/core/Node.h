#pragma once
#include <string>
#include <unordered_map>
#include <memory>

#include "boost/asio.hpp"
#include "boost/uuid/uuid.hpp"
#include "boost/uuid/uuid_generators.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

#include "easyloggingpp_v9.95.0/easylogging++.h"
#include "utils/MessageBuilder.h"
#include "dispatchers/MessageDispatcher.h"
#include "data_structures/Message.h"
#include "NetworkConnector/NetworkConnector.h"
#include "kbuckets/KBucketsManager.h"
#include "DHT/DHT.h"

using std::string;
using namespace std::placeholders;
using boost::uuids::uuid;

namespace m2 {
namespace routing {

class Node
{
public:
    Node(string port);
    Node()      = delete;
    Node(Node&) = delete;
    ~Node();


    void start(uuid bootstrap_guid, string ip_address, string port);
    //void ping()
    void stop();
private:
    void onMessageReceive(vector<char> buff);
    void onRequestReceive(vector<char> buff);
    void startAsyncUpdateKBuckets();
    void startAsyncRestoreData();

    DHT dht;
    NodeInfo self_info;
    NetworkConnector network_connector;
    KBucketsManager kbuckets_manager;
    MessageBuilder message_builder;
    MessageDispatcher message_dispatcher;
    boost::asio::io_service io_service;

    friend class PingProcessor;
    friend class StoreProcessor;
    friend class FindNodeProcessor;
    friend class FindDataProcessor;
    friend class FindProcessor;

    friend class PingHandler;
    friend class StoreHandler;
    friend class FindNodeHandler;
    friend class FindDataHandler;
};

} // namespace routing
} // namespace m2
