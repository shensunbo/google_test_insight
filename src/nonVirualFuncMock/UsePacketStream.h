#pragma once
// #include "ConcretePacketStream.h"
#include <string>
#include <iostream>

template <typename T>
class UsePacketStream{
public:
    UsePacketStream() = delete;
    UsePacketStream(T& _stream):stream_(_stream) {

    }
    
    void AddPacket(std::string& new_packet){
      stream_.AppendPacket(new_packet);
    }

    void CheckPacket(T& _stream){
      std::cout <<_stream.GetPacket() << std::endl;
      std::cout <<_stream.NumberOfPackets() << std::endl;
    }

    //必须使用引用或者指针，不能直接实例化，不然mock不起作用
    T& stream_;
};
