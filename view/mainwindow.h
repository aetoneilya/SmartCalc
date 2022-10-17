#ifndef SRC_VIEW_MAINWINDOW_H_
#define SRC_VIEW_MAINWINDOW_H_

#include <QMainWindow>
#include <QVector>

#include "../controller/controller.h"
#include "calcx.h"
#include "graph.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

namespace s21 {
class MainWindow : public QMainWindow {
    Q_OBJECT

 public:
    explicit MainWindow(Controller *c, QWidget *parent = nullptr);
    ~MainWindow();

 private:
    Ui::MainWindow *ui;
    Controller *_c;
    bool _replace = false;
    void clearOldRes();

 private slots:
    void digitPressed();
    void functionPressed();
    void acPressed();
    void clearOnePressed();
    void resPressed();
    void graphPressed();
    void creditCalcPressed();
    void on_pushButton_Pi_released();
    void on_pushButton_e_released();
};

}  // namespace s21

#endif  // SRC_VIEW_MAINWINDOW_H_
