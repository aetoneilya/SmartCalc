#include "model.h"

namespace s21 {

bool Model::parse(std::string s) {
    try {
        _parser.parseExpTree(s);
        _computable = true;
    } catch (const std::exception& e) {
        _computable = false;
    }

    return _computable;
}

double Model::calcResult() {
    Variable::setValue(0);
    if (_computable) {
        return _parser.calculate();
    } else {
        return 0;
    }
}

double Model::calcResultX(double x) {
    Variable::setValue(x);
    if (_computable) {
        return _parser.calculate();
    } else {
        return 0;
    }
}

bool Model::contains_x() {
    std::string s = _parser.getInfix();
    return (s.find('x') != std::string::npos);
}

void Model::calcPlot(std::vector<double>* x_v, std::vector<double>* y_v, double x_min, double x_max) {
    if (_computable) {
        double step = fabs((x_max - x_min) / 100000);
        for (double x = x_min; x < x_max; x += step) {
            x_v->push_back(x);
            y_v->push_back(calcResultX(x));
        }
    }
}

std::vector<double> Model::countAnnuityCredit(double creditSum, double percent, int monthAmount) {
    double P = percent / 1200;
    double res = creditSum * (P + P / (pow(1 + P, monthAmount) - 1));
    std::vector<double> payments;
    for (int i = 0; i < monthAmount; i++) {
        payments.push_back(res);
    }
    return payments;
}

std::vector<double> Model::countDiffCredit(double creditSum, double percent, int monthAmount) {
    double b = creditSum / monthAmount;
    double P = percent / 1200;
    std::vector<double> payments;
    for (double Sn = creditSum; Sn > 0; Sn = Sn - b) {
        double month_pay = b + Sn * P;
        payments.push_back(month_pay);
    }
    return payments;
}

}  // namespace s21
