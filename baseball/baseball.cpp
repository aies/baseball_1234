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

        if(guessNumber == question)
            return { true, 3, 0 };

        int strikes_count = 0;
        int balls_count = 0;

        for (char ch : guessNumber) {
            if (guessNumber[ch] == question[ch])
                strikes_count++;
            balls_count++;
        }
        return { (guessNumber == question), strikes_count, balls_count };
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
    bool isDuplicatedNumber(const std::string& guessNumber)
    {
        return guessNumber[0] == guessNumber[1] ||
            guessNumber[0] == guessNumber[2] ||
            guessNumber[2] == guessNumber[1];
    }
private:
    string question;
};