#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
    Baseball game;

    void assertIllegalArgment(string gussNumber) {
        try {
            game.guss(string("12s"));
            FAIL();
        }
        catch (exception e) {
            //PASS
        }
    }
};

TEST(baseballGame, TryGameTest) {
    Baseball game;

    EXPECT_THROW(game.guss(string("12")), length_error);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();

}