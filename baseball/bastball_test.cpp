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

TEST_F(BaseballFixture, ThrowExceptionWhenInvalidCase) {
    assertIllegalArgment("12");
    assertIllegalArgment("12s");
    assertIllegalArgment("121");
}

int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();

}