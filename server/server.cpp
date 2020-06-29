#include "server.h"
#include "session.h"

Server::Server(boost::asio::io_service& io_service, int port)
    : acceptor_(io_service, tcp::endpoint(tcp::v4(), port))
    , socket_(io_service) {
  Accept();
}

Server::Accept() {
  acceptor_.async_accept(socket_, [this](boost::system::error_code ec) {
    if (!ec) {
      std::make_shared<Session>(std::move(socket_))->Start();
    }

    Accept();
  });
}
