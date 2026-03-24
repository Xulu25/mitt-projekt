#include "Question.h"

Question::Question()
{
	this->question = "";
}

Question::Question(string question)
{
	this->question = question;
}

Question::~Question()
{
}

void Question::setQuestion(string question)
{
	this->question = question;
}

string Question::getQuestion() const
{
	return this->question;
}
