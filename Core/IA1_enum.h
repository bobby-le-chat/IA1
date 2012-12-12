#ifndef __IA1_ENUM_H__
# define __IA1_ENUM_H__

namespace IA1
{
	enum argumentOrder
	{
		nbControler = 1,
		trainLenght,
		trainClass,
		trainPop,
		cops,
		timeOfDay,
		weekEnd,
		holidays,
		race,
		gender,
		age,
		delay,
		control, 

		
		nullArgumentOrder = 0
	};
	enum valueList
	{
		yes = 1,
		no,

		twoControllers,
		fourControllers,
		sixControllers,
		eightControllers,

		shortTrain,
		middleTrain,
		longTrain,

		firstClass,
		secondClass,

		desertOccupation,
		lowOccupation,
		middleOccupation,
		fullOccupation,
		crowdedOccupation,

		slump,
		prepostRush,
		rush,

		european,
		african,
		arabic,
		asian,

		female,
		male,

		junior,
		teenager,
		adult,
		senior,

		fewDelay,
		someDelay,
		lotOfDelay, 

		
		nullValueList = 0

	};
	enum answer
	{
		controlled,
		notControlled,
		fiftyfifty,
		unknow,

		nullAnswer
	};

}
#endif /* __IA1_ENUM_H__  */