#include <iostream>
#include <boost/asio.hpp>
#include "server.h"

int main() {
  std::cerr << "HELLO! (server)" << std::endl;
  try {
    boost::asio::io_service io_service;
    Server server(io_service, 2345);

    io_service.run();

  } catch (const std::exception& ex) {
    std::cerr << ex.what() << std::endl;
  }

  return 0;
}
