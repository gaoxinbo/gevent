#include "net/databuffer.h"
#include "gtest/gtest.h"

using namespace gevent::net;
using namespace std;

TEST(test_buffer, integer){
  DataBuffer buffer;

  int8_t i8 = 10;
  buffer.AppendInt8(i8);
  int8_t r8 = buffer.ReadInt8();
  EXPECT_EQ(r8, i8);

  int16_t i16 = 62524;
  buffer.AppendInt16(i16);
  int16_t r16 = buffer.ReadInt16();;
  EXPECT_EQ(r16, i16);

  int32_t i32 = 100000000;
  buffer.AppendInt32(i32);
  int32_t r32 = buffer.ReadInt32();;
  EXPECT_EQ(r32, i32);

}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
