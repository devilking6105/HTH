#include "treewidgetbutton.h"
#include "treewidgetbutton.ui"
#include <QPushButton>
#include <QTreeWidgetItem>
#include <QDebug>
#include <QList>
#include <QLabel>

TreeWidgetButton::TreeWidgetButton(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TreeWidgetButton)
{
    ui->setupUi(this);


    // Push buttons to be added
    QPushButton *topLevelButton = new QPushButton("Top Level Button");
    QPushButton *childButton1 = new QPushButton("Child Button 1");
    QPushButton *childButton = new QPushButton("Child Button 0");
    QPushButton *nestedChildButton = new QPushButton("Nested Child");

//    // Connecting the button signals with corresponding slots
    connect(childButton1, SIGNAL(clicked(bool)), this, SLOT(onchildButton1Clicked(bool)));
    connect(topLevelButton, SIGNAL(clicked(bool)), this, SLOT(onTopLevelButtonClicked(bool)));


    QTreeWidgetItem *topLevelItem = new QTreeWidgetItem();
    QTreeWidgetItem *childItem1 = new QTreeWidgetItem();
    QTreeWidgetItem *childItem = new QTreeWidgetItem();
    QTreeWidgetItem *nestedChildItem = new QTreeWidgetItem();

    ui->treeWidget->addTopLevelItem(topLevelItem);

    // Adding children to the topLevelItem
    topLevelItem->addChild(childItem);
    topLevelItem->addChild(childItem1);

    // Adding a child node to a child [Nested Child]
    childItem->addChild(nestedChildItem);

    ui->treeWidget->setItemWidget(topLevelItem, 0, topLevelButton);
    ui->treeWidget->setItemWidget(childItem, 0, childButton);
    ui->treeWidget->setItemWidget(childItem1, 0, childButton1);
    ui->treeWidget->setItemWidget(nestedChildItem, 0, nestedChildButton);

}

void TreeWidgetButton::onTopLevelButtonClicked(bool clicked)
{
    ui->label->setText("Top Level Button was Clicked");
}

void TreeWidgetButton::onchildButton1Clicked(bool clicked)
{
    ui->label->setText("Child Button 1 was Clicked");
}

TreeWidgetButton::~TreeWidgetButton()
{
    delete ui;
}
