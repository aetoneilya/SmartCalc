#ifndef SRC_VIEW_CALCX_H_
#define SRC_VIEW_CALCX_H_

#include <QDialog>

#include "mainwindow.h"

namespace Ui {
class Calcx;
}  // namespace Ui

namespace s21 {
class Calcx : public QDialog {
    Q_OBJECT

 public:
    explicit Calcx(QWidget *parent = nullptr);
    explicit Calcx(Controller *c, QWidget *parent = nullptr);
    ~Calcx();

 private slots:
    void findPressed();

 private:
    Ui::Calcx *ui;
    Controller *_c;
};

}  // namespace s21

#endif  // SRC_VIEW_CALCX_H_
