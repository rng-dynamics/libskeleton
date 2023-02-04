#include <gtest/gtest.h>

#include <libskeleton/core/hello.hpp>

namespace skeleton::core {

class TestSkeletonCoreHello : public ::testing::Test {};

TEST_F(TestSkeletonCoreHello, GetHelloUnitTest) {
  ASSERT_EQ("hello", GetHello());
}

} // namespace skeleton::core
