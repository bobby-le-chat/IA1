
#include <map>

#include "IA1_enum.h"
#include "IA1_Answer.h"

namespace IA1
{
	Answer::Answer()
		: _nbLoop(0)
	{}
	IA1::argumentOrder Answer::getChoise(int nbLoop) const
	{
		if (nbLoop == -1)
			return (*this->_choises.rbegin()).second;
		std::map<int, IA1::argumentOrder>::const_iterator resIt = this->_choises.find(nbLoop);
		if (resIt == this->_choises.end())
			return IA1::nullArgumentOrder;
		return (*resIt).second;
	}
	void Answer::addChoise(IA1::argumentOrder choise)
	{
		this->_choises[this->_nbLoop] = choise;
	}

	IA1::answer Answer::getResult(int nbLoop) const
	{
		if (nbLoop == -1)
			return (*this->_results.rbegin()).second.first;
		std::map<int, std::pair<IA1::answer, double>>::const_iterator resIt = this->_results.find(nbLoop);
		if (resIt == this->_results.end())
			return IA1::nullAnswer;
		return (*resIt).second.first;
	}
	double Answer::getProba(int nbLoop) const
	{
		if (nbLoop == -1)
			return (*this->_results.rbegin()).second.second;
		std::map<int, std::pair<IA1::answer, double>>::const_iterator resIt = this->_results.find(nbLoop);
		if (resIt == this->_results.end())
			return -1;
		return (*resIt).second.second;
	}
	void Answer::addResult(IA1::answer result, double proba)
	{
		this->_results.insert(std::pair<int, std::pair<IA1::answer, double>>(this->_nbLoop, std::pair<IA1::answer, double>(result, proba)));
	}

	void	Answer::increaseLoop(int nb)
	{
		this->_nbLoop += nb;
	}
	int	Answer::getNbLoop() const
	{
		return this->_nbLoop;
	}

}
