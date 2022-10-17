#include "calculator.h"

namespace s21 {

operand Calculator::getoperand(size_t pos, size_t& offset) {
    operand op = operand::NONE;
    for (size_t i = 0; i < operands_str.size(); i++) {
        size_t operand_len = operands_str[i].length();

        if (_infix.compare(pos, operand_len, operands_str[i]) == 0) {
            op = static_cast<operand>(i);
            offset = operand_len;
            break;
        }
    }

    if (op == operand::MINUS && (pos == 0 || _infix[pos - 1] == operands_str[operand::LEFT_BRACKET][0])) {
        op = operand::UNAR_MINUS;
    } else if (op == operand::PLUS &&
               (pos == 0 || _infix[pos - 1] == operands_str[operand::LEFT_BRACKET][0])) {
        op = operand::UNAR_PLUS;
    }

    return op;
}

std::string Calculator::plusMinus(std::string s) {
    char last_char = ' ';
    size_t last_char_i = -1;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '+' && last_char == '+') {
            s[i] = ' ';
        } else if (s[i] == '+' && last_char == '-') {
            s[i] = ' ';
        } else if (s[i] == '-' && last_char == '+') {
            s[last_char_i] = ' ';
        } else if (s[i] == '-' && last_char == '-') {
            s[last_char_i] = ' ';
            s[i] = '+';
        }
        if (s[i] != ' ') {
            last_char = s[i];
            last_char_i = i;
        }
    }
    return s;
}

void Calculator::setInfix(const std::string& s) {
    _infix = s;
    _infix = plusMinus(_infix);
    _infix.erase(remove_if(_infix.begin(), _infix.end(), isspace), _infix.end());
    std::transform(_infix.begin(), _infix.end(), _infix.begin(), ::tolower);
}

std::string Calculator::getInfix() { return _infix; }

void Calculator::addOperand(std::stack<Exp*>& expression, operand op) {
    if (arity.at(op) == 2) {
        if (expression.size() < 2) {
            expression.top()->release();
            delete expression.top();
            throw std::invalid_argument("Wrong expression");
        }

        Exp* t1 = expression.top();
        expression.pop();
        Exp* t2 = expression.top();
        expression.pop();

        NodeBin* n = new NodeBin(op, t2, t1);

        expression.push(n);

    } else if (arity.at(op) == 1) {
        Exp* t1 = expression.top();
        expression.pop();

        NodeUnar* n = new NodeUnar(op, t1);

        expression.push(n);
    }
}

void Calculator::parseExpTree(const std::string& s) {
    setInfix(s);
    std::stack<Exp*> expression;
    std::stack<operand> operands_s;
    size_t offset = 1;

    for (size_t i = 0; i < _infix.length(); i += offset) {
        if (std::isdigit(_infix[i])) {
            double num = std::stod(&_infix[i], &offset);
            Term* t = new Term(num);
            expression.push(t);
        } else if (_infix[i] == 'x') {
            offset = 1;
            Variable* v = new Variable;
            expression.push(v);
        } else {
            operand op = getoperand(i, offset);

            if (op == operand::NONE) {
                throw std::invalid_argument("Unknown operand");
            }

            if (op == operand::LEFT_BRACKET) {
                operands_s.push(op);
                continue;
            }

            if (op == operand::RIGHT_BRACKET) {
                while (!operands_s.empty() && operands_s.top() != operand::LEFT_BRACKET) {
                    addOperand(expression, operands_s.top());
                    operands_s.pop();
                }

                if (operands_s.empty()) throw std::invalid_argument("Wrong brackets");

                operands_s.pop();

                continue;
            }

            while (!operands_s.empty() && priority.at(operands_s.top()) >= priority.at(op)) {
                addOperand(expression, operands_s.top());
                operands_s.pop();
            }
            operands_s.push(op);
        }
    }

    while (!operands_s.empty()) {
        if (operands_s.top() == operand::LEFT_BRACKET) throw std::invalid_argument("Wrong brackets");

        addOperand(expression, operands_s.top());
        operands_s.pop();
    }

    if (expression.size() != 1) {
        expression.top()->release();
        delete expression.top();
        throw std::invalid_argument("Wrong expression");
    } else {
        _expTree->release();
        delete _expTree;
        _expTree = expression.top();
    }
}

double Calculator::calculate() { return _expTree->calc(); }

}  // namespace s21
