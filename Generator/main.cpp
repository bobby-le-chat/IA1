#include <iostream>
#include "CsvGenerator.h"


int main(int argc, char **argv) {
  
  
    CsvGenerator	csv = CsvGenerator::defaultCsv();
    csv.generateAndExport("resultCsv.csv", 10);
    std::cout << "Test de la ligne : eightControllers	longTrain	firstClass	lowOccupation	yes	rush	no	yes	asian	female	teenager	fewDelay" << std::endl;
    std::vector<std::string> row_manual;
    row_manual.push_back("eightControllers");
    row_manual.push_back("longTrain");
    row_manual.push_back("firstClass");
    row_manual.push_back("lowOccupation");
    row_manual.push_back("yes");
    row_manual.push_back("rush");
    row_manual.push_back("no");
    row_manual.push_back("yes");
    row_manual.push_back("asian");
    row_manual.push_back("female");
    row_manual.push_back("adult");
    row_manual.push_back("fewDelay");
    std::cout <<  std::boolalpha <<  csv.isControlate(row_manual) << std::endl;
    std::cout << "endl" << std::endl;
    return 0;
}
