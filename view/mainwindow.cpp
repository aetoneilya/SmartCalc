#include "mainwindow.h"

#include "./ui_mainwindow.h"

namespace s21 {

MainWindow::MainWindow(Controller *c, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow), _c(c) {
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_plus, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_minus, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_mul, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_div, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_pow, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_dot, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_left_br, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_right_br, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_x, SIGNAL(released()), this, SLOT(digitPressed()));
    connect(ui->pushButton_acos, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_asin, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_atan, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_cos, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_sin, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_tan, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_ln, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_log, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_sqrt, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_mod, SIGNAL(released()), this, SLOT(functionPressed()));
    connect(ui->pushButton_ac, SIGNAL(released()), this, SLOT(acPressed()));
    connect(ui->pushButton_clear_one, SIGNAL(released()), this, SLOT(clearOnePressed()));
    connect(ui->pushButton_eq, SIGNAL(released()), this, SLOT(resPressed()));
    connect(ui->pushButton_graph, SIGNAL(released()), this, SLOT(graphPressed()));
    connect(ui->pushButton_creditCalc, SIGNAL(released()), this, SLOT(creditCalcPressed()));

    ui->radioButton_annuity->setChecked(true);

    ui->tableWidget_credit->setColumnCount(2);

    ui->tableWidget_credit->setHorizontalHeaderLabels(QStringList() << "Date: "
                                                                    << "Payment:");
    ui->tableWidget_credit->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::digitPressed() {
    clearOldRes();
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->insert(button->text());
}

void MainWindow::functionPressed() {
    clearOldRes();
    QPushButton *button = (QPushButton *)sender();
    ui->lineEdit->insert(button->text() + "(");
}

void MainWindow::resPressed() {
    QString qs = ui->lineEdit->text().replace("÷", "/");
    std::string str = qs.toStdString();

    if (_c->parseStr(str)) {
        if (_c->containsVariable()) {
            s21::Calcx window(_c);
            window.setModal(true);
            window.exec();
        } else {
            double res = _c->getResult();
            QString resAsQstr = QString::number(res);
            ui->lineEdit->clear();
            ui->lineEdit->insert(resAsQstr);
        }
    } else {
        ui->lineEdit->clear();
        ui->lineEdit->insert("Error");
        _replace = true;
    }
}

void MainWindow::graphPressed() {
    std::string str = ui->lineEdit->text().toStdString();
    if (_c->parseStr(str)) {
        s21::Graph window(_c, ui->lineEdit->text());
        window.setModal(true);
        window.exec();
    } else {
        ui->lineEdit->clear();
        ui->lineEdit->insert("Error");
        _replace = true;
    }
}

void MainWindow::acPressed() { ui->lineEdit->clear(); }

void MainWindow::clearOnePressed() { ui->lineEdit->backspace(); }

void MainWindow::on_pushButton_Pi_released() {
    clearOldRes();
    ui->lineEdit->insert("3.141592");
}

void MainWindow::on_pushButton_e_released() {
    clearOldRes();
    ui->lineEdit->insert("2.718281");
}

void MainWindow::clearOldRes() {
    if (_replace) {
        ui->lineEdit->clear();
        _replace = false;
    }
}

void MainWindow::creditCalcPressed() {
    std::vector<double> payments;
    double creditSum = ui->spinBox_creditSum->value();
    double percent = ui->doubleSpinBox_percent->value();
    int monthsAmount = ui->spinBox_months->value();
    QDate date = ui->calendarWidget_creditStart->selectedDate();

    if (ui->radioButton_annuity->isChecked()) {
        payments = _c->getAnnuityCredit(creditSum, percent, monthsAmount);
    } else if (ui->radioButton_differentiated->isChecked()) {
        payments = _c->getDiffCredit(creditSum, percent, monthsAmount);
    }

    ui->tableWidget_credit->setRowCount(monthsAmount);
    double paymentsSum = 0;
    for (int i = 0; i < monthsAmount; i++) {
        QTableWidgetItem *itm = new QTableWidgetItem(date.toString("dd.MM.yyyy"));
        QTableWidgetItem *itm2 = new QTableWidgetItem(QString::number(payments[i]));
        ui->tableWidget_credit->setItem(i, 0, itm);
        ui->tableWidget_credit->setItem(i, 1, itm2);
        date = date.addMonths(1);
        paymentsSum += payments[i];
    }
    ui->label_overpayment->setText("Overpayment on credit: " + QString::number(paymentsSum - creditSum));
    ui->label_totalPayment->setText("Total payment:" + QString::number(paymentsSum));
}

}  // namespace s21
