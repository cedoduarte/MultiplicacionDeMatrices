#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui
{
class Widget;
}

class QSpinBox;
class QStandardItemModel;

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void on_numeroDeFilasSpinBoxA_valueChanged(int arg1);
    void on_numeroDeColumnasSpinBoxA_valueChanged(int arg1);
    void on_numeroDeFilasSpinBoxB_valueChanged(int arg1);
    void on_numeroDeColumnasSpinBoxB_valueChanged(int arg1);
    void on_multiplicarPushButton_clicked();
    void on_quitarAplicacionPushButton_clicked();
private:
    void createComponents();
    void configureComponents();
    void configureSpinBox(QSpinBox *spinBox) const;
    double getValueAt(QStandardItemModel *model, int fila, int col) const;
    void appendTo(QStandardItemModel *model, double value) const;

    Ui::Widget *ui;
    QStandardItemModel *mModelA;
    QStandardItemModel *mModelB;
    QStandardItemModel *mModelResultado;
};

#endif // WIDGET_H
