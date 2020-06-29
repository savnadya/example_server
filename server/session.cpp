#include "session.h"

Session::Session(tcp::socket&& socket)
    : socket_(std::move(socket)) {
}

void Session::Start() {
  Read();
}

void Session::Read() {
  auto self = shared_from_this();
  
  boost::asio::async_read(socket_, boost::asio::buffer(data_.data(), data_.size()),
      [this, self](std::error_code error, size_t count) {
    count_ = count;
    if (!error) {
      HandleRead();
    }
  });
}

void Session::Write() {
  auto self = shared_from_this();

}

void Session::HandleRead() {
  
}
