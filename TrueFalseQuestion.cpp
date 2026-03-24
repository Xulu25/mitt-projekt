#include "TrueFalseQuestion.h"

TrueFalseQuestion::TrueFalseQuestion()
{
    this->correctAnswer = true;
    this->givenAnswer = false;
    this->answered = false;
}

TrueFalseQuestion::TrueFalseQuestion(string question, bool correctAnswer)
{
    this->setQuestion(question);
    this->correctAnswer = correctAnswer;
    this->givenAnswer = false;
    this->answered = false;
}

TrueFalseQuestion::~TrueFalseQuestion()
{
}

bool TrueFalseQuestion::setCorrectAnswer(bool answer)
{
    return this->correctAnswer = answer;
}

bool TrueFalseQuestion::setGivenAnswer(bool answer)
{
    this->answered = true;
    this->givenAnswer = answer;
    return this->givenAnswer;
}

string TrueFalseQuestion::getCorrectAnswer()
{
    if (this->correctAnswer) {
        return "True";
    }
    else {
        return "False";
    }
}

string TrueFalseQuestion::getGivenAnswer()
{
    if (!this->answered) {
        return "";
    }

    if (this->givenAnswer) {
        return "True";
    }
    else {
        return "False";
    }
}

bool TrueFalseQuestion::isAnswered()
{
    return this->answered;
}

bool TrueFalseQuestion::isCorrect()
{
    return this->isAnswered() && (this->givenAnswer == correctAnswer);
}

unique_ptr<Question> TrueFalseQuestion::clone()
{
    return make_unique<TrueFalseQuestion>(*this);
}
