#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
    Baseball game{"123"};

    void assertIllegalArgment(string gussNumber) {
        try {
            game.guess(gussNumber);
            FAIL();
        }
        catch (exception e) {
            //PASS
        }
    }
};

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgment("12");
    assertIllegalArgment("12s");
    assertIllegalArgment("121");
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber) {
    GuessResult result = game.guess("123");

    EXPECT_TRUE(result.solved);
    EXPECT_EQ(3, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber1) {
    GuessResult result = game.guess("129");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(2, result.strikes);
    EXPECT_EQ(0, result.balls);
}

TEST_F(BaseballFixture, ReturnSolvedResultIfMatchedNumber2) {
    GuessResult result = game.guess("321");

    EXPECT_FALSE(result.solved);
    EXPECT_EQ(1, result.strikes);
    EXPECT_EQ(2, result.balls);
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();

}