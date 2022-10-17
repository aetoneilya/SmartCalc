#ifndef SRC_MODEL_CALCULATOR_H_
#define SRC_MODEL_CALCULATOR_H_

#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <stdexcept>
#include <string>

#include "expression.h"

namespace s21 {

class Calculator {
 private:
    const std::vector<std::string> operands_str = {
        {"+"},    {"-"},    {"*"},    {"/"},  {"^"},   {"mod"}, {"sin"}, {"cos"}, {"tan"}, {"acos"},
        {"asin"}, {"atan"}, {"sqrt"}, {"ln"}, {"log"}, {"("},   {")"},   {"~"},   {"#"}};

    const std::map<operand, int> priority = {
        {LEFT_BRACKET, 0}, {RIGHT_BRACKET, 0}, {PLUS, 1}, {MINUS, 1},      {MUL, 2},      {DIV, 2}, {MOD, 2},
        {POW, 3},          {ATAN, 3},          {ACOS, 3}, {ASIN, 3},       {LOG, 3},      {LN, 3},  {SQRT, 3},
        {TAN, 3},          {COS, 3},           {SIN, 3},  {UNAR_MINUS, 4}, {UNAR_PLUS, 4}};

    const std::map<operand, int> arity = {
        {LEFT_BRACKET, 0}, {RIGHT_BRACKET, 0}, {PLUS, 2}, {MINUS, 2},      {MUL, 2},      {DIV, 2}, {MOD, 2},
        {POW, 2},          {ATAN, 1},          {ACOS, 1}, {ASIN, 1},       {LOG, 1},      {LN, 1},  {SQRT, 1},
        {TAN, 1},          {COS, 1},           {SIN, 1},  {UNAR_MINUS, 1}, {UNAR_PLUS, 1}};

    std::string _infix;
    Exp* _expTree;

    void calcOperand(std::stack<double>& numbers, operand op);
    operand getoperand(size_t pos, size_t& offset);
    void addOperand(std::stack<Exp*>& expression, operand op);
    std::string plusMinus(std::string s);
    void setInfix(const std::string& s);

 public:
    Calculator() { _expTree = new Exp; }
    ~Calculator() {
        _expTree->release();
        delete _expTree;
    }
    std::string getInfix();
    void parseExpTree(const std::string& s);
    double calculate();
};

}  // namespace s21

#endif  // SRC_MODEL_CALCULATOR_H_
