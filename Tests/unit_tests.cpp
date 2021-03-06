#include "gtest/gtest.h"

#include "DueDateTests.hpp"
#include "PriorityTests.hpp"
#include "TaskTypeTests.hpp"
#include "Task_Test.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
};
