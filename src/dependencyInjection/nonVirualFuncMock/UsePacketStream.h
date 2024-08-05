#pragma once
// #include "ConcretePacketStream.h"
#include <string>
#include <iostream>

template <typename T>
class UsePacketStream{
public:
    void AddPacket(std::string& new_packet){
      stream_.AppendPacket(new_packet);
    }

    void CheckPacket(T& _stream){
      std::cout <<_stream.GetPacket() << std::endl;
      std::cout <<_stream.NumberOfPackets() << std::endl;
    }

    T stream_;
};
