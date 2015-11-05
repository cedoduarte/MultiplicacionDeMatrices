#ifndef NUMEROREALSPINBOXDELEGATE_H
#define NUMEROREALSPINBOXDELEGATE_H

#include <QItemDelegate>

class NumeroRealSpinBoxDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    explicit NumeroRealSpinBoxDelegate(QObject *parent = nullptr);
protected:
     QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const override;
     void setEditorData(QWidget *editor,
                        const QModelIndex &index) const override;
     void setModelData(QWidget *editor, QAbstractItemModel *model,
                       const QModelIndex &index) const override;
     void updateEditorGeometry(QWidget *editor,
                               const QStyleOptionViewItem &option,
                               const QModelIndex &index) const override;
};

#endif // NUMEROREALSPINBOXDELEGATE_H
