#ifndef TREEWIDGETBUTTON_H
#define TREEWIDGETBUTTON_H

#include <QDialog>

namespace Ui {
class TreeWidgetButton;
}

class TreeWidgetButton : public QDialog
{
    Q_OBJECT

public:
    explicit TreeWidgetButton(QWidget *parent = 0);
    ~TreeWidgetButton();

protected slots:
    void onTopLevelButtonClicked(bool clicked);
    void onchildButton1Clicked(bool clicked);

private:
    Ui::TreeWidgetButton *ui;
};

#endif // TREEWIDGETBUTTON_H
