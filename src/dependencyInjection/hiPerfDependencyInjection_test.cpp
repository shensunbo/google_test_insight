#include "gmock/gmock.h"
#include "MockPacketStream.h"
#include "UsePacketStream.h"


using namespace testing;

TEST(HiPerfDependencyInjectionTest, MockPacketStreamTest) {
    MockPacketStream stream;
    std::string mockPackage = "Hello GMock!";
    EXPECT_CALL(stream, AppendPacket(Eq(mockPackage)))
        .Times(1);

    EXPECT_CALL(stream, GetPacket())
        .Times(1);
    
    EXPECT_CALL(stream, NumberOfPackets())
        .Times(1);

    UsePacketStream<MockPacketStream> useStream(stream);
    //TODO:使用mockPackage.stream_，无法满足上述 EXPECT_CALL, 不会调用stream的对应方法
    useStream.AddPacket(mockPackage);
    useStream.CheckPacket(stream);

    //TODO: failed
    // useStream.CheckPacket(useStream.stream_);
}