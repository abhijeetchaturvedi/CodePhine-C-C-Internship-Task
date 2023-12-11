
#include <iostream>
#include <string>

using namespace std;

struct Question {
    string questionText;
    string options[4];
    int correctOption;
};

int score = 0;

void displayQuestion(const Question& q) {
    cout << q.questionText << endl;
    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << ". " << q.options[i] << endl;
    }
    cout << "Your answer: ";
}

bool isCorrect(const Question& q, int userAnswer) {
    return userAnswer == q.correctOption;
}

void askQuestion(const Question& q) {
    displayQuestion(q);
    
    int userAnswer;
    cin >> userAnswer;

    if (isCorrect(q, userAnswer)) {
        cout << "Correct!\n";
        score++;
    } else {
        cout << "Wrong! The correct answer is: " << q.correctOption << ". " << q.options[q.correctOption - 1] << endl;
    }

    cout << "-----------------------------\n";
}

int main() {
    Question questions[] = {
        {"What is the capital of India?", {"Berlin", "Delhi", "Madrid", "Rome"}, 2},
        {"Which planet is known as the Master Blaster?", {"Sachin Tendulkar", "Virendra Sehwag", "Brian Lara", "Viv richards"}, 1},
        {"Who is king of jungle?", {"Elephant", "Lion", "Giraffe", "Hippopotamus"}, 2},
        {"Which is programming language'?", {"Hindi", "python", "Chinese", "english"}, 2},
        {"Who is PM of India?", {"Narendra modi", "Justin Trudeau", "Rahul Gandhi", "Yogi Adityanath"}, 1},
        {"What is capital of USA'?", {"Paris", "Delhi", "Washington", "Ottawa"}, 3},
        {"How many colors are there in Rainbow'?", {"4", "3", "2", "7"}, 4},
        {"From which direction Sun rises'?", {"west", "south", "west", "East"}, 4},
        {"What is national bird of India'?", {"Hen", "Peacock", "Sparrow", "Ostrich"}, 2},
        {"Founder of SpaceX'?", {"Brian Acton", "Marc Zuckerberg", "Elon Musk", "Jon Koum "}, 3},
        
        
        // Add more questions as needed
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);

    for (int i = 0; i < numQuestions; ++i) {
        askQuestion(questions[i]);
    }

    cout << "Quiz completed! Your final score is: " << score << " out of " << numQuestions << endl;

    return 0;
}

