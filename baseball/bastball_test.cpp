#include "gmock/gmock.h"
#include "baseball.cpp"

class BaseballFixture : public testing::Test {
public:
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

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidLength) {
    assertIllegalArgment("12");
}

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidChar) {
    assertIllegalArgment("12s");
}
int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();

}