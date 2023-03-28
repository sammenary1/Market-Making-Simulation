#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

struct Question {
    std::string text;
    double true_value;
};

std::vector<Question> questions = {
    {"How heavy is an elephant in kilograms?", 6000.0},
    {"What is the average weight of an adult male giraffe in kilograms?", 1200.0},
{"What is the height of Mount Everest in meters?", 8848.0},
{"What is the boiling point of water in degrees Celsius at sea level?", 100.0},
{"How many grams are there in a pound?", 453.592},
{"Approximately how many minutes does it take for light from the Sun to reach Earth?", 8.3},
{"What is the approximate radius of Earth in kilometers?", 6371.0},
{"What is the acceleration due to gravity on Earth's surface in meters per second squared?", 9.81},
{"How many days does it take for the Moon to orbit the Earth?", 27.3},
{"What is the average adult human body temperature in degrees Celsius?", 37.0},
{"How many bones are there in an adult human body?", 206.0},
{"What is the freezing point of water in degrees Fahrenheit?", 32.0},
{"What is the normal atmospheric pressure at sea level in millibars?", 1013.0},
{"How many countries are there in the world?", 195.0},
{"What is the total number of squares on a chessboard?", 204.0},
{"How many keys are there on a standard piano?", 88.0},
{"How many grams are there in one ounce?", 28.35},
{"What is the atomic number of gold?", 79.0},
{"How many permanent members are there in the United Nations Security Council?", 5.0},
{"How many teeth does an adult human typically have?", 32.0},
{"How many chemical elements are there in the periodic table?", 118.0},
{"Approximately how many languages are spoken around the world?", 7100.0},
{"How many protons does the heaviest naturally occurring element, uranium, have?", 92.0},
{"How old is Donald Trump?", 76.0},
{"What is the average height of an adult male gorilla in meters?", 1.7},
{"What is the average weight of an adult female polar bear in kilograms?", 300.0},
{"What is the average height of an adult male emperor penguin in meters?", 1.2},
{"What is the average weight of an adult female African lion in kilograms?", 130.0},
{"What is the average height of an adult male Bengal tiger in meters (measured at the shoulder)?", 1.1},
{"What is the average weight of an adult male grizzly bear in kilograms?", 320.0},
{"What is the average weight of an adult male hippopotamus in kilograms?", 1500.0},
{"What is the average weight of an adult female blue whale in metric tons?", 140.0},
{"What is the average weight of an adult male orangutan in kilograms?", 75.0},

};

Question pick_random_question() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, questions.size() - 1);

    return questions[dist(gen)];
}

int main() {
    srand(time(nullptr));

    int position = 0;
    double profit_loss = 0.0;

    Question question = pick_random_question();
    std::cout << question.text << std::endl;

    for (int trade = 1; trade <= 5; ++trade) {
        double bid, ask;
        std::cout << "Trade " << trade << ": Enter your bid and ask offers (one at a time): ";
        std::cin >> bid >> ask;

        if (bid > question.true_value) {
            std::cout << "Sell to you." << std::endl;
            position++;
            profit_loss += question.true_value - bid;
        }
        else if (ask < question.true_value) {
            std::cout << "Buy from you." << std::endl;
            position--;
            profit_loss += ask - question.true_value;
        }
        else {
            std::cout << "Make a tighter market." << std::endl;
        }
    }

    std::cout << "The true value is: " << question.true_value << std::endl;

    int user_position;
    double user_profit_loss;
    std::cout << "Enter your cumulative position and profit/loss (one at a time: ";
    std::cin >> user_position >> user_profit_loss;

    if (user_position == position) {
        std::cout << "Correct position!" << std::endl;
    }
    else {
        std::cout << "Incorrect position. You were off by " << abs(user_position - position) << "." << std::endl;
    }

    if (fabs(user_profit_loss - profit_loss) < 1e-6) {
        std::cout << "Correct profit/loss!" << std::endl;
    }
    else {
        std::cout << "Incorrect profit/loss. You were off by " << fabs(user_profit_loss - profit_loss) << "." << std::endl;
    }

    return 0;
}
