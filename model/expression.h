#ifndef SRC_MODEL_EXPRESSION_H_
#define SRC_MODEL_EXPRESSION_H_

#include <cmath>

namespace s21 {

enum operand {
    PLUS = 0,
    MINUS,
    MUL,
    DIV,
    POW,
    MOD,
    SIN,
    COS,
    TAN,
    ACOS,
    ASIN,
    ATAN,
    SQRT,
    LN,
    LOG,
    LEFT_BRACKET,
    RIGHT_BRACKET,
    UNAR_MINUS,
    UNAR_PLUS,
    NONE
};

class Exp {
 public:
    virtual double calc() { return 0; }
    virtual void release() {}
    virtual ~Exp() = default;
};

class Term : public Exp {
 private:
    double val;

 public:
    explicit Term(double v) : val(v) {}
    double calc() override { return val; }
};

class Variable : public Exp {
 public:
    inline static double value = 0;
    Variable() {}

    static void setValue(double x) { value = x; }
    double calc() override { return value; }
};

class NodeUnar : public Exp {
    Exp* _exp;
    operand _op;

 public:
    NodeUnar(operand op, Exp* e) : _exp(e), _op(op) {}

    double calc() override;
    void release() override {
        _exp->release();
        delete _exp;
    }
};

class NodeBin : public Exp {
    Exp* l_exp;
    Exp* r_exp;
    operand _op;

 public:
    NodeBin(operand op, Exp* left, Exp* right) : l_exp(left), r_exp(right), _op(op) {}

    double calc() override;
    void release() override {
        l_exp->release();
        r_exp->release();
        delete l_exp;
        delete r_exp;
    }
};

}  // namespace s21

#endif  //  SRC_MODEL_EXPRESSION_H_
