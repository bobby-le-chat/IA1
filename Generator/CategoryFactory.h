#ifndef CATEGORYFACTORY_H
#define CATEGORYFACTORY_H
#include "Category.h"

class CategoryFactory
{
public :
  static Category nbControler();
  static Category trainLength();
  static Category trainClass();
  static Category trainPop();
  static Category cops();
  static Category timeOfDay();
  static Category weekEnd();
  static Category hollidays();
  static Category race();
  static Category gender();
  static Category age();
  static Category delay();
  static Category control();
};

#endif // CATEGORYFACTORY_H
