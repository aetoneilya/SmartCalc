#ifndef SRC_CONTROLLER_CONTROLLER_H_
#define SRC_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 private:
    Model* _m;

 public:
    explicit Controller(Model* m) : _m(m) {}
    ~Controller() {}

    bool parseStr(std::string str);
    double getResult();
    double getResultWithX(double x);
    void getPlot(std::vector<double>* x, std::vector<double>* y, double x_min, double x_max);
    bool containsVariable();
    std::vector<double> getAnnuityCredit(double creditSum, double percent, int monthAmount);
    std::vector<double> getDiffCredit(double creditSum, double percent, int monthAmount);
};

}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLER_H_
