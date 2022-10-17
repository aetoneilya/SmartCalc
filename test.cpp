#include <gtest/gtest.h>

#include "model/model.h"

TEST(s21_calculator, binary_plus) {
    std::string exp1("2+2");
    std::string exp2("1+1+1+1+1+1+1+1+1+1+1");
    std::string exp3("5 + 5 + 5 + 5 + 5 + (5 + 5 + ( 5))");
    std::string exp4("2.5+2.45");
    std::string exp5("100000.1234+100000.1234");
    double res1 = 2 + 2;
    double res2 = 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1 + 1;
    double res3 = 5 + 5 + 5 + 5 + 5 + (5 + 5 + (5));
    double res4 = 2.5 + 2.45;
    double res5 = 100000.1234 + 100000.1234;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
    EXPECT_TRUE(m.parse(exp5));
    EXPECT_DOUBLE_EQ(m.calcResult(), res5);
}

TEST(s21_calculator, binary_minus) {
    std::string exp1("10 - 2");
    std::string exp2("10 - 12 - 5 - 5");
    std::string exp3("10.5 - 12 - 5.5 - 5.5");
    std::string exp4("2.5-2.45");
    std::string exp5("100000.1234-100000.1234");
    double res1 = 10 - 2;
    double res2 = 10 - 12 - 5 - 5;
    double res3 = 10.5 - 12 - 5.5 - 5.5;
    double res4 = 2.5 - 2.45;
    double res5 = 100000.1234 - 100000.1234;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
    EXPECT_TRUE(m.parse(exp5));
    EXPECT_DOUBLE_EQ(m.calcResult(), res5);
}

TEST(s21_calculator, multiply) {
    std::string exp1("10 * 2");
    std::string exp2("10 * 2 * 2");
    std::string exp3("10.5 * 2.5 * 2.1");
    std::string exp4("2.5*2.45");
    std::string exp5("1004*100.3");
    double res1 = 10 * 2;
    double res2 = 10 * 2 * 2;
    double res3 = 10.5 * 2.5 * 2.1;
    double res4 = 2.5 * 2.45;
    double res5 = 1004 * 100.3;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
    EXPECT_TRUE(m.parse(exp5));
    EXPECT_DOUBLE_EQ(m.calcResult(), res5);
}

TEST(s21_calculator, division) {
    std::string exp1("5 / 2");
    std::string exp2("5 / 2 / 5");
    std::string exp3("5.6 / 2.8 / 0.1");
    std::string exp4("2.5/2.45");
    std::string exp5("1004/100.3");
    double res1 = 5. / 2;
    double res2 = 5. / 2 / 5;
    double res3 = 5.6 / 2.8 / 0.1;
    double res4 = 2.5 / 2.45;
    double res5 = 1004 / 100.3;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
    EXPECT_TRUE(m.parse(exp5));
    EXPECT_DOUBLE_EQ(m.calcResult(), res5);
}

TEST(s21_calculator, mod) {
    std::string exp1("5 mod 2");
    std::string exp2("5 mod 2 mod 3 mod 4");
    std::string exp3("5.5 mod 2");

    double res1 = 1;
    double res2 = 1;
    double res3 = 1.5;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
}

TEST(s21_calculator, pow) {
    std::string exp1("5 ^ 2");
    std::string exp2("2 ^ 2 ^ 2");
    std::string exp3("4 ^ 0.5");

    double res1 = 25;
    double res2 = 16;
    double res3 = 2;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
}

TEST(s21_calculator, unar_plus_minus) {
    std::string exp1("+5");
    std::string exp2("+(+5)");
    std::string exp3("-5");
    std::string exp4("(-5)");
    std::string exp5("-(-5)");
    std::string exp6("--5");
    std::string exp7("--++--+5");

    double res1 = 5;
    double res2 = 5;
    double res3 = -5;
    double res4 = -5;
    double res5 = 5;
    double res6 = 5;
    double res7 = 5;

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
    EXPECT_TRUE(m.parse(exp5));
    EXPECT_DOUBLE_EQ(m.calcResult(), res5);
    EXPECT_TRUE(m.parse(exp6));
    EXPECT_DOUBLE_EQ(m.calcResult(), res6);
    EXPECT_TRUE(m.parse(exp7));
    EXPECT_DOUBLE_EQ(m.calcResult(), res7);
}

TEST(s21_calculator, cos) {
    std::string exp1("cos(3)");
    std::string exp2("cos(3.141592)");
    std::string exp3("cos(0)");
    std::string exp4("cos(1)");

    double res1 = cos(3);
    double res2 = cos(3.141592);
    double res3 = cos(0);
    double res4 = cos(1);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, sin) {
    std::string exp1("sin(0)");
    std::string exp2("sin(1)");
    std::string exp3("sin(3.141592)");
    std::string exp4("sin(3.141592/2)");

    double res1 = sin(0);
    double res2 = sin(1);
    double res3 = sin(3.141592);
    double res4 = sin(3.141592 / 2);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, tan) {
    std::string exp1("tan(3)");
    std::string exp2("tan(2)");
    std::string exp3("tan(0)");
    std::string exp4("tan(1)");

    double res1 = tan(3);
    double res2 = tan(2);
    double res3 = tan(0);
    double res4 = tan(1);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, acos) {
    std::string exp1("acos(-0.5)");
    std::string exp2("acos(0)");
    std::string exp3("acos(0.1)");
    std::string exp4("acos(0.2)");

    double res1 = acos(-0.5);
    double res2 = acos(0);
    double res3 = acos(0.1);
    double res4 = acos(0.2);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, asin) {
    std::string exp1("asin(0.5)");
    std::string exp2("asin(0.1)");
    std::string exp3("asin(0.2)");
    std::string exp4("asin(0)");

    double res1 = asin(0.5);
    double res2 = asin(0.1);
    double res3 = asin(0.2);
    double res4 = asin(0);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, atan) {
    std::string exp1("atan(-23)");
    std::string exp2("atan(0)");
    std::string exp3("atan(1)");
    std::string exp4("atan(2)");

    double res1 = atan(-23);
    double res2 = atan(0);
    double res3 = atan(1);
    double res4 = atan(2);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, sqrt) {
    std::string exp1("sqrt(4)");
    std::string exp2("sqrt(1525125)");
    std::string exp3("sqrt(0.5)");
    std::string exp4("sqrt(23)");

    double res1 = sqrt(4);
    double res2 = sqrt(1525125);
    double res3 = sqrt(0.5);
    double res4 = sqrt(23);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, log) {
    std::string exp1("log(15)");
    std::string exp2("log(1)");
    std::string exp3("log(23)");
    std::string exp4("log(44)");

    double res1 = log10(15);
    double res2 = log10(1);
    double res3 = log10(23);
    double res4 = log10(44);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, ln) {
    std::string exp1("ln(15)");
    std::string exp2("ln(23)");
    std::string exp3("ln(1)");
    std::string exp4("ln(44)");

    double res1 = log(15);
    double res2 = log(23);
    double res3 = log(1);
    double res4 = log(44);

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, complex) {
    std::string exp1("ocos(x)");
    std::string exp2("5*()");
    std::string exp3("5*((1)+(2))");
    std::string exp4("5*((1)+(((-(2)))))");

    double res1 = 0;
    double res2 = 0;
    double res3 = 15;
    double res4 = -5;

    s21::Model m;

    EXPECT_FALSE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResult(), res1);
    EXPECT_FALSE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResult(), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResult(), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResult(), res4);
}

TEST(s21_calculator, calcResWithX) {
    std::string exp1("cos(x)");
    std::string exp2("5 + x * 3 ^ X");
    std::string exp3("x*((1)+(x))");
    std::string exp4("x*((1)+(((-(x)))))");

    double x1 = 0.5;
    double x2 = 23;
    double x3 = 223232;
    double x4 = 2.2322;

    double res1 = cos(x1);
    double res2 = 5 + x2 * pow(3, x2);
    double res3 = x3 * ((1) + (x3));
    double res4 = x4 * ((1) + (((-(x4)))));

    s21::Model m;

    EXPECT_TRUE(m.parse(exp1));
    EXPECT_DOUBLE_EQ(m.calcResultX(x1), res1);
    EXPECT_TRUE(m.parse(exp2));
    EXPECT_DOUBLE_EQ(m.calcResultX(x2), res2);
    EXPECT_TRUE(m.parse(exp3));
    EXPECT_DOUBLE_EQ(m.calcResultX(x3), res3);
    EXPECT_TRUE(m.parse(exp4));
    EXPECT_DOUBLE_EQ(m.calcResultX(x4), res4);
}

TEST(s21_calculator, containsX) {
    s21::Model m;

    std::string exp1("cos(x)");
    std::string exp2("5 + x * 3 ^ X");
    std::string exp3("x*((1)+(x))");
    std::string exp4("x*((1)+(((-(x)))))");
    std::string exp5("ocos(sdszy");
    std::string exp6("5*()");
    std::string exp7("5*((1)+(2))");
    std::string exp8("5*((1)+(((-(2)))))");

    m.parse(exp1);
    EXPECT_TRUE(m.contains_x());
    m.parse(exp2);
    EXPECT_TRUE(m.contains_x());
    m.parse(exp3);
    EXPECT_TRUE(m.contains_x());
    m.parse(exp4);
    EXPECT_TRUE(m.contains_x());
    m.parse(exp5);
    EXPECT_FALSE(m.contains_x());
    m.parse(exp6);
    EXPECT_FALSE(m.contains_x());
    m.parse(exp7);
    EXPECT_FALSE(m.contains_x());
    m.parse(exp8);
    EXPECT_FALSE(m.contains_x());
}

TEST(s21_calculator, calcPlot) {
    s21::Model m;

    std::string exp1("x");
    m.parse(exp1);

    std::vector<double> x_v;
    std::vector<double> y_v;

    m.calcPlot(&x_v, &y_v, 0, 10);

    for (size_t i = 0; i < x_v.size() && i < y_v.size(); i++) {
        EXPECT_DOUBLE_EQ(x_v[i], y_v[i]);
    }
}

TEST(s21_credit, annuity) {
    s21::Model m;

    std::vector<double> payments = m.countAnnuityCredit(1000000, 12, 12);
    double r_pay = 88848.79;
    for (auto pay : payments) {
        EXPECT_NEAR(pay, r_pay, 0.1);
    }
}

TEST(s21_credit, diff) {
    s21::Model m;

    std::vector<double> payments = m.countDiffCredit(1000000, 12, 12);
    std::vector<double> r_payments = {93333.33, 92500.00, 91666.67, 90833.33, 90000.00, 89166.67,
                                      88333.33, 87500.00, 86666.67, 85833.33, 85000.00, 84166.67};
    EXPECT_EQ(payments.size(), r_payments.size());

    for (size_t i = 0; i < payments.size() && r_payments.size(); i++) {
        EXPECT_NEAR(payments[i], r_payments[i], 0.1);
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
