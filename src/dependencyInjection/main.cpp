#include "BeTested.h"
#include "RealDep.h"

#include "ConcretePacketStream.h"
#include "UsePacketStream.h"

#include <memory>

int main() {
    BeTested tested(std::make_shared<RealDep>());
    tested.funcWithDep(8);

    ConcretePacketStream stream;

    //before, non virual func mock
    // UsePacketStream useStream;
    
    //after, non virtual func mock
    UsePacketStream<ConcretePacketStream> useStream;
    std::string new_packet = "Hello World!";
    useStream.AddPacket(new_packet);
    useStream.CheckPacket(stream);
    return 0;
}