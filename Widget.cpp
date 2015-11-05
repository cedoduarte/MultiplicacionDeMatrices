#include "Widget.h"
#include "ui_Widget.h"
#include "NumeroRealSpinBoxDelegate.h"
#include <QStandardItemModel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    createComponents();
    configureComponents();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_numeroDeFilasSpinBoxA_valueChanged(int arg1)
{
    mModelA->setRowCount(arg1);
    mModelResultado->setRowCount(arg1);
}

void Widget::on_numeroDeColumnasSpinBoxA_valueChanged(int arg1)
{
    ui->numeroDeFilasSpinBoxB->setValue(arg1);
    mModelA->setColumnCount(arg1);
}

void Widget::on_numeroDeFilasSpinBoxB_valueChanged(int arg1)
{
    ui->numeroDeColumnasSpinBoxA->setValue(arg1);
    mModelB->setRowCount(arg1);
}

void Widget::on_numeroDeColumnasSpinBoxB_valueChanged(int arg1)
{
    mModelB->setColumnCount(arg1);
    mModelResultado->setColumnCount(arg1);
}

void Widget::on_multiplicarPushButton_clicked()
{
    const int rowCountA = mModelA->rowCount();
    const int rowCountB = mModelB->rowCount();
    const int colCountB = mModelB->columnCount();
    double suma;
    for (int ix = 0; ix < rowCountA; ++ix) {
        for (int jx = 0; jx < colCountB; ++jx) {
            suma = 0;
            for (int kx = 0; kx < rowCountB; ++kx) {
                const double aij = getValueAt(mModelA, ix, kx);
                const double bij = getValueAt(mModelB, kx, jx);
                const double ab = aij * bij;
                suma += ab;
            }
            appendTo(mModelResultado, suma);
        }
    }
}

void Widget::on_quitarAplicacionPushButton_clicked()
{
    close();
}

void Widget::createComponents()
{
    mModelA = new QStandardItemModel(this);
    mModelB = new QStandardItemModel(this);
    mModelResultado = new QStandardItemModel(this);
}

void Widget::configureComponents()
{
    setWindowTitle("Multiplicar matrices");
    configureSpinBox(ui->numeroDeColumnasSpinBoxA);
    configureSpinBox(ui->numeroDeColumnasSpinBoxB);
    configureSpinBox(ui->numeroDeFilasSpinBoxA);
    configureSpinBox(ui->numeroDeFilasSpinBoxB);
    ui->tableViewA->setModel(mModelA);
    ui->tableViewB->setModel(mModelB);
    ui->tableViewResultado->setModel(mModelResultado);
    ui->tableViewA->setItemDelegate(new NumeroRealSpinBoxDelegate(this));
    ui->tableViewB->setItemDelegate(new NumeroRealSpinBoxDelegate(this));
}

void Widget::configureSpinBox(QSpinBox *spinBox) const
{
    spinBox->setMinimum(0);
    spinBox->setMaximum(INT_MAX);
}

double Widget::getValueAt(QStandardItemModel *model, int fila, int col) const
{
    auto item = model->item(fila, col);
    if (!item) {
        return 0.0;
    }
    return item->text().toDouble();
}

void Widget::appendTo(QStandardItemModel *model, double value) const
{
    const int rowCount = model->rowCount();
    const int colCount = model->columnCount();
    for (int ix = 0; ix < rowCount; ++ix) {
        for (int jx = 0; jx < colCount; ++jx) {
            if (!model->item(ix, jx)) {
                model->setItem(ix, jx,
                    new QStandardItem(QString::number(value)));
                return;
            }
        }
    }
}
