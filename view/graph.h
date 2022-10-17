#ifndef SRC_VIEW_GRAPH_H_
#define SRC_VIEW_GRAPH_H_

#include <QDialog>

#include "../qcustomplot.h"
#include "mainwindow.h"

namespace Ui {
class Graph;
}  // namespace Ui

namespace s21 {
class Graph : public QDialog {
    Q_OBJECT

 public:
    explicit Graph(QWidget *parent = nullptr);
    explicit Graph(Controller *c, QString str, QWidget *parent = nullptr);
    ~Graph();

 private slots:
    void redrawPressed();

 private:
    Ui::Graph *ui;
    Controller *_c;
};

}  // namespace s21

#endif  // SRC_VIEW_GRAPH_H_
