// 3-4-2026 Chapter 10 Student Quiz Score Validator
#include <iostream>
using namespace std;

class QuizResult
{
private:
	int quiz_score = 0;

public:
	void setscore(int new_score)
	{
		if (new_score < 0 || new_score > 100)
		{
			cout << "Invalid Score!" << endl;
			return;
		}
		else
		{
			quiz_score = new_score;
		}
	}

	int getscore()
	{
		return quiz_score;
	}
};

int main()
{
	QuizResult score_1;
	int user_input;

	cout << "Input student score (0-100): ";
	cin >> user_input;
	
	score_1.setscore(user_input);

	cout << "New score: " << score_1.getscore() << endl;

	return 0;
}