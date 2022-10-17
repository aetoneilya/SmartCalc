#ifndef SRC_MODEL_MODEL_H_
#define SRC_MODEL_MODEL_H_

#include "calculator.h"

namespace s21 {

class Model {
 private:
    Calculator _parser;
    bool _computable = false;

 public:
    Model() {}

    bool parse(std::string s);
    bool contains_x();
    double calcResult();
    double calcResultX(double x);
    void calcPlot(std::vector<double>* x_v, std::vector<double>* y_v, double x_min, double x_max);
    std::vector<double> countAnnuityCredit(double creditSum, double percent, int monthAmount);
    std::vector<double> countDiffCredit(double creditSum, double percent, int monthAmount);
};

}  // namespace s21

#endif  //  SRC_MODEL_MODEL_H_
