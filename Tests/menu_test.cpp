#include "gtest/gtest.h"
#include "TaskMenu.hpp"

//Testing for invalid user inputs
TEST(MenuTest, InvalidSheduleAction) {
    Schedule *currSched = new Schedule("Schedule Name");
    Menu *menu = new Menu(currSched);

    ASSERT_FALSE(menu->checkChoice(8));
}