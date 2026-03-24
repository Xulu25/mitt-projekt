#pragma once
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Question
{
private:
	string question;

public:
	Question();
	Question(string question);
	virtual ~Question();

	void setQuestion(string question);
	string getQuestion() const;

	virtual string getCorrectAnswer() = 0;
	virtual string getGivenAnswer() = 0;
	virtual bool isAnswered() = 0;
	virtual bool isCorrect() = 0;
	virtual unique_ptr<Question> clone() = 0;
};

