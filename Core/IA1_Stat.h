#ifndef __IA1_STAT_H__
# define __IA1_STAT_H__

#include "IA1_enum.h"

namespace IA1
{
	class Parameter;
	class Stat
	{
	protected:
		 int	_yes;
		 int	_no;
		 bool	_changedProba;
		 bool	_changedEntropy;
		 double	_probaYes;
		 double	_probaNo;
		 double	_entropy;
		 double	_gain;

		 void changed();
		 double myLog(double income, int base = 2);
	public:
		 Stat();
		 int getYes() const;
		 void addYes();
		 void setYes(int yes);
		 void addNo();
		 void setNo(int no);
		 int getNo() const;
		 double getProba(IA1::valueList order = IA1::yes);
		 double getEntropy();
		 double getGain(Parameter& parameter);
	};

}

#endif /* __IA1_STAT_H__ */