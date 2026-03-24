#pragma once
#include "Question.h"
#include "SimpleQuestion.h"
#include "TrueFalseQuestion.h"

class Quiz
{
private:
	string name;
	vector<unique_ptr<Question>> ptrQuestion;

public:
	Quiz() = default;
	Quiz(string name);
	~Quiz() = default;

	Question* getQuestionAt(int index);
	void setName(string name);
	string getName() const;

	Quiz(const Quiz& other);
	Quiz& operator=(const Quiz& other);

	void addSimpleQuestion(string question, string answer);
	void addTrueFalseQuestion(string question, bool answer);
	int getNrOfQuestions();
	string listQuestions();
	string listQuestionsAndCorrectAnswers();
	string listSimpleQuestions();
	bool moveUp(int questionNr);
	bool moveDown(int questionNr);
	bool removeQuestion(int questionNr);
};

