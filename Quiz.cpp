#include "Quiz.h"

Quiz::Quiz(string name)
{
    this->name = name;
}

Question* Quiz::getQuestionAt(int index)
{
    if (index <= ptrQuestion.size() && index >= 0) {
        return ptrQuestion[index].get();
    }
    return nullptr;
}

void Quiz::setName(string name)
{
    this->name = name;
}

string Quiz::getName() const
{
    return this->name;
}

Quiz::Quiz(const Quiz& other)
{
    this->name = other.name;

    for (int i = 0; i < other.ptrQuestion.size(); i++) {
        this->ptrQuestion.push_back(other.ptrQuestion[i]->clone());
    }
}

Quiz& Quiz::operator=(const Quiz& other)
{
    if (this != &other) {

        this->name = other.name;
        this->ptrQuestion.clear();
        for (int i = 0; i < other.ptrQuestion.size(); i++) {
            this->ptrQuestion.push_back(other.ptrQuestion[i]->clone());
        }
    }
    return *this;
}

void Quiz::addSimpleQuestion(string question, string answer)
{
    this->ptrQuestion.push_back(make_unique<SimpleQuestion>(question, answer));
}

void Quiz::addTrueFalseQuestion(string question, bool answer)
{
    this->ptrQuestion.push_back(make_unique<TrueFalseQuestion>(question, answer));
}

int Quiz::getNrOfQuestions()
{
    return this->ptrQuestion.size();
}

string Quiz::listQuestions()
{
    string final = "";
    
    for (int i = 0; i < ptrQuestion.size(); i++) {

        final += ptrQuestion[i]->getQuestion();
    }
    return final;
}

string Quiz::listQuestionsAndCorrectAnswers()
{
    string final = "";

    for (int i = 0; i < ptrQuestion.size(); i++) {
        final += ptrQuestion[i]->getQuestion();
        final += "" + ptrQuestion[i]->getCorrectAnswer();
    }
    return final;
}

string Quiz::listSimpleQuestions()
{
    string final = "";
    for (int i = 0; i < ptrQuestion.size(); i++) {

        if (SimpleQuestion* sq = dynamic_cast<SimpleQuestion*>(ptrQuestion[i].get())) {

            final += sq->getQuestion();
        }
    }
    return final;
}

bool Quiz::moveUp(int questionNr)
{
    if (questionNr <= 0 || questionNr >= ptrQuestion.size()) {
        return false;
    }
    swap(ptrQuestion[questionNr], ptrQuestion[questionNr - 1]);
    return true;
}

bool Quiz::moveDown(int questionNr)
{
    if (questionNr < 0 || questionNr >= ptrQuestion.size() - 1)
        return false;

    swap(ptrQuestion[questionNr], ptrQuestion[questionNr + 1]);
    return true;
}

bool Quiz::removeQuestion(int questionNr)
{
    if (questionNr < 0 || questionNr >= ptrQuestion.size())
        return false;
    ptrQuestion.erase(ptrQuestion.begin() + questionNr);
    return true;
}
