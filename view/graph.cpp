#include "graph.h"

#include "ui_graph.h"

namespace s21 {

Graph::Graph(QWidget *parent) : QDialog(parent), ui(new Ui::Graph) { ui->setupUi(this); }
Graph::Graph(Controller *c, QString str, QWidget *parent) : QDialog(parent), ui(new Ui::Graph), _c(c) {
    ui->setupUi(this);

    ui->label_func->setText("y(x) = " + str);

    ui->doubleSpinBox_xmax->setValue(10);
    ui->doubleSpinBox_xmin->setValue(-10);
    ui->doubleSpinBox_ymax->setValue(10);
    ui->doubleSpinBox_ymin->setValue(-10);

    ui->graphWidget->addGraph();
    ui->graphWidget->setInteraction(QCP::iRangeZoom, true);
    ui->graphWidget->setInteraction(QCP::iRangeDrag, true);

    redrawPressed();

    connect(ui->pushButton_redraw, SIGNAL(released()), this, SLOT(redrawPressed()));
}
Graph::~Graph() { delete ui; }

void Graph::redrawPressed() {
    std::vector<double> x, y;
    double xmin = ui->doubleSpinBox_xmin->value();
    double xmax = ui->doubleSpinBox_xmax->value();
    double ymin = ui->doubleSpinBox_ymin->value();
    double ymax = ui->doubleSpinBox_ymax->value();
    _c->getPlot(&x, &y, xmin, xmax);
    QVector<double> x_final = QVector<double>(x.begin(), x.end());
    QVector<double> y_final = QVector<double>(y.begin(), y.end());

    ui->graphWidget->xAxis->setRange(xmin, xmax);
    ui->graphWidget->yAxis->setRange(ymin, ymax);

    ui->graphWidget->graph(0)->addData(x_final, y_final);
    ui->graphWidget->replot();
}

}  // namespace s21
