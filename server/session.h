#pragma once

#include <boost/asio.hpp>
#include <utility>

using boost::asio::ip::tcp;

class Session : public std::enable_shared_from_this<Session> {
public:
  Session(tcp::socket&& socket);

  void Start();

  void Read();
  void Write();

private:
  void HandleRead();

private:
  tcp::socket socket_;

  std::array<char, 1024> data_;
  size_t count_;
};
