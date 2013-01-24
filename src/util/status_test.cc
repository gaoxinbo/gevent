#include "util/status.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;
using namespace gevent::util;

TEST(test_status,OK){
  Status s;
  EXPECT_EQ(s.OK(), true);
  s= Status::IOError("ioerror","test");
  EXPECT_EQ(s.OK(), false);
  EXPECT_EQ("IOError ioerror :test",s.ToString());
  
}

int main(int argc, char **argv){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


