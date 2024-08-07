#pragma once
#include "gmock/gmock.h"
#include <string>
// A mock packet stream class.  It inherits from no other, but defines
// GetPacket() and NumberOfPackets().
class MockPacketStream {
 public:
    MOCK_METHOD(void, AppendPacket, (std::string& new_packet), ());
    MOCK_METHOD(std::string, GetPacket, (), (const));
    MOCK_METHOD(unsigned int, NumberOfPackets, (), (const));
};