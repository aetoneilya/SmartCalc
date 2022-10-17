#include "expression.h"

namespace s21 {

double NodeBin::calc() {
    double res = 0;

    double arg_right = r_exp->calc();
    double arg_left = l_exp->calc();

    if (_op == operand::PLUS)
        res = arg_left + arg_right;
    else if (_op == operand::MINUS)
        res = arg_left - arg_right;
    else if (_op == operand::DIV)
        res = arg_left / arg_right;
    else if (_op == operand::MUL)
        res = arg_left * arg_right;
    else if (_op == operand::MOD)
        res = fmod(arg_left, arg_right);
    else if (_op == operand::POW)
        res = pow(arg_left, arg_right);

    return res;
}

double NodeUnar::calc() {
    double res = 0;
    double arg = _exp->calc();

    if (_op == operand::ATAN)
        res = atan(arg);
    else if (_op == operand::ASIN)
        res = asin(arg);
    else if (_op == operand::ACOS)
        res = acos(arg);
    else if (_op == operand::LOG)
        res = log10(arg);
    else if (_op == operand::LN)
        res = log(arg);
    else if (_op == operand::SQRT)
        res = sqrt(arg);
    else if (_op == operand::TAN)
        res = tan(arg);
    else if (_op == operand::COS)
        res = cos(arg);
    else if (_op == operand::SIN)
        res = sin(arg);
    else if (_op == operand::UNAR_MINUS)
        res = -arg;
    else if (_op == operand::UNAR_PLUS)
        res = arg;

    return res;
}

}  // namespace s21
