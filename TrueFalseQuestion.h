#pragma once
#include "Question.h"


class TrueFalseQuestion : public Question
{
private:
	bool correctAnswer;
	bool givenAnswer;
	bool answered;

public:
	TrueFalseQuestion();
	TrueFalseQuestion(string question, bool correctAnswer);
	~TrueFalseQuestion();

	bool setCorrectAnswer(bool answer);
	bool setGivenAnswer(bool answer);

	string getCorrectAnswer() override;
	string getGivenAnswer() override;
	bool isAnswered() override;
	bool isCorrect() override;

	unique_ptr<Question> clone() override;
};

