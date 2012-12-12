#include <iostream>
#include "CsvGenerator.h"
#include "CategoryFactory.h"

int main(int argc, char **argv) {
  
  
    CsvGenerator	csv;
    
    csv.addCategory(CategoryFactory::nbControler());
    csv.addCategory(CategoryFactory::trainLength());
    csv.addCategory(CategoryFactory::trainClass());
    csv.addCategory(CategoryFactory::trainPop());
    csv.addCategory(CategoryFactory::cops());
    csv.addCategory(CategoryFactory::timeOfDay());
    csv.addCategory(CategoryFactory::weekEnd());
    csv.addCategory(CategoryFactory::hollidays());
    csv.addCategory(CategoryFactory::race());
    csv.addCategory(CategoryFactory::gender());
    csv.addCategory(CategoryFactory::age());
    csv.addCategory(CategoryFactory::delay());
    csv.generateAndExport("resultCsv.csv", 10000);
    
    return 0;
}
