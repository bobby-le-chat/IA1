#ifndef __IA1_ANSWER_H__
# define __IA1_ANSWER_H__

#include <string>
#include <map>

#include "IA1_enum.h"

namespace IA1
{
	class Answer
	{
	private:
		int	_nbLoop;
		std::map<int, IA1::argumentOrder> _choises;
		std::map<int, std::pair<IA1::answer, double>> _results; 
	protected:
	public:
		Answer();

		void increaseLoop(int nb = 1);

		IA1::argumentOrder getChoise(int nbLoop = -1) const;
		void addChoise(IA1::argumentOrder choise);

		IA1::answer getResult(int nbLoop = -1) const;
		double getProba(int nbLoop = -1) const;
		void addResult(IA1::answer result, double proba = 0);

		int getNbLoop() const;

	};
}

#endif /* __IA1_ANSWER_H__ */