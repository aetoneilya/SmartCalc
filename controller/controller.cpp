#include "controller.h"

namespace s21 {

bool Controller::parseStr(std::string str) { return _m->parse(str); }

double Controller::getResult() { return _m->calcResult(); }

double Controller::getResultWithX(double x) { return _m->calcResultX(x); }

bool Controller::containsVariable() { return _m->contains_x(); }

void Controller::getPlot(std::vector<double>* x, std::vector<double>* y, double x_min, double x_max) {
    return _m->calcPlot(x, y, x_min, x_max);
}

std::vector<double> Controller::getAnnuityCredit(double creditSum, double percent, int monthAmount) {
    return _m->countAnnuityCredit(creditSum, percent, monthAmount);
}
std::vector<double> Controller::getDiffCredit(double creditSum, double percent, int monthAmount) {
    return _m->countDiffCredit(creditSum, percent, monthAmount);
}

}  // namespace s21
