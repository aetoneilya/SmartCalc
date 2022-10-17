#include "calcx.h"

#include "ui_dialog_calcx.h"

namespace s21 {

Calcx::Calcx(QWidget *parent) : QDialog(parent), ui(new Ui::Calcx) { ui->setupUi(this); }
Calcx::Calcx(Controller *c, QWidget *parent) : QDialog(parent), ui(new Ui::Calcx), _c(c) {
    ui->setupUi(this);

    connect(ui->pushButton_find, SIGNAL(released()), this, SLOT(findPressed()));
}
Calcx::~Calcx() { delete ui; }

void Calcx::findPressed() {
    double x = ui->doubleSpinBox_x->value();
    double res = _c->getResultWithX(x);
    QString resAsQstr = QString::number(res);
    ui->lineEdit_result->clear();
    ui->lineEdit_result->insert(resAsQstr);
}

}  // namespace s21
