#pragma once
#include "Question.h"


class SimpleQuestion : public Question
{
private:
	string correctAnswer;
	string givenAnswer;

public:
	SimpleQuestion();
	SimpleQuestion(string question, string correctAnswer);
	~SimpleQuestion();

	void setCorrectAnswer(string answer);
	void setGivenAnswer(string answer);

	string getCorrectAnswer() override;
	string getGivenAnswer() override;
	bool isAnswered() override;
	bool isCorrect() override;

	unique_ptr<Question> clone() override;
};

