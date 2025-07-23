#include "gmock/gmock.h"
#include "baseball.cpp"

TEST(baseballGame, TryGameTest) {
    Baseball game;

    EXPECT_THROW(game.guss(string("12")), length_error);
}

TEST(baseballGame, ThrowExceptionWhenInvalidChar) {
    Baseball game;

    EXPECT_THROW(game.guss(string("12s")), invalid_argument);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();

}