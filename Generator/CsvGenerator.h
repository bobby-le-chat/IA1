#ifndef CSVGENERATOR_H
#define CSVGENERATOR_H


#include "Category.h"
#include "Row.h"

class CsvGenerator
{
  std::vector<Category>	_categories;
  std::vector<Row>		_rows;
  


private :

  float 						getMaxWeightCategory() const;
  const std::vector<Category>   normalizeCategories();


public:
  CsvGenerator();
  void				addCategory(const Category&);
  const std::vector<Row>&	generate(int nbRowGenerate);
  void				exportToFile(const std::string& filepath, bool withCategory = true);
  void				generateAndExport(const std::string& filepath, int nbRowGenerate, bool withCategory = true);
  bool				isControlate(const std::vector<std::string>&);
  static 			CsvGenerator defaultCsv();
};

#endif // CSVGENERATOR_H
