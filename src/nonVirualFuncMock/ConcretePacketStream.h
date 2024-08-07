#pragma once
#include <string>
#include <iostream>

// A simple packet stream class.  None of its members is virtual.
class ConcretePacketStream {
 public:
  void AppendPacket(std::string& new_packet){
    std::cout << new_packet << std::endl;
  }

  std::string GetPacket() const{
    return "Hello World!";
  };
  unsigned int NumberOfPackets() const{
    return 666;
  }
};