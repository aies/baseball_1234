#include <stdexcept>

using namespace std;

struct GuessResult {
    bool solved;
    int strikes;
    int balls;
};

class Baseball {
public:
    explicit Baseball(const string& question)
        : question(question) {
    }

    GuessResult guess(const string& guessNumber) {
        assertIllegalArgument(guessNumber);

        GuessResult ret = { isSolved(guessNumber) , 0  , 0 };

        for (char ch : guessNumber) {
            if (guessNumber[ch] == question[ch]) {
                ret.strikes++;
            }
            ret.balls++;
        }
        return ret;
    }

private:
    string question;

    bool isSolved(const std::string& guessNumber)
    {
        return (guessNumber == question);
    }

    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1] ||
            guessNumber[0] == guessNumber[2] ||
            guessNumber[2] == guessNumber[1];
    }

    void assertIllegalArgument(const std::string& guessNumber)
    {
        if (guessNumber.length() != 3) {
            throw length_error("Must be three letters.");
        }
        for (char ch : guessNumber) {
            if (ch < '0' || ch > '9')
                throw invalid_argument("Must be number.");
        }

        if (isDuplicatedNumber(guessNumber)) {
            throw invalid_argument("Must be have the same number");
        }
    }
};