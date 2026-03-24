#include "SimpleQuestion.h"

SimpleQuestion::SimpleQuestion()
{
    this->correctAnswer = "";
    this->givenAnswer = "";
}

SimpleQuestion::SimpleQuestion(string question, string correctAnswer)
{
    this->setQuestion(question);
    this->correctAnswer = correctAnswer;
    this->givenAnswer = "";
}

SimpleQuestion::~SimpleQuestion()
{
}

void SimpleQuestion::setCorrectAnswer(string answer)
{
    this->correctAnswer = answer;
}

void SimpleQuestion::setGivenAnswer(string answer)
{
    this->givenAnswer = answer;
}

string SimpleQuestion::getCorrectAnswer()
{
    return this->correctAnswer;
}

string SimpleQuestion::getGivenAnswer()
{
    return this->givenAnswer;
}

bool SimpleQuestion::isAnswered()
{
    return !this->givenAnswer.empty();
}

bool SimpleQuestion::isCorrect()
{
    return this->isAnswered() && (givenAnswer == correctAnswer);
}

unique_ptr<Question> SimpleQuestion::clone()
{
    return make_unique<SimpleQuestion>(*this);
}
