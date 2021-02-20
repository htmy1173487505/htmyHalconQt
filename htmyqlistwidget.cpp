#include "htmyqlistwidget.h"
#include <QWidget>

HtmyQListWidget::HtmyQListWidget(QWidget *parent)
{
    this->setAcceptDrops(true);
    this->setDragEnabled(true);
}

HtmyQListWidget::~HtmyQListWidget()
{

}

void HtmyQListWidget::dropEvent(QDropEvent *event)
{
    QListWidget::dropEvent(event);
    performDrag();
}

void HtmyQListWidget::performDrag()
{
    QListWidgetItem * item = this->takeItem(this->currentRow());
    delete item;
}

void HtmyQListWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu* popMenu = new QMenu(this);
    if(this->itemAt(mapFromGlobal(QCursor::pos())) != NULL) //如果有item则添加"修改"菜单 [1]*
    {
        QAction* action = new QAction("删除", this);
        popMenu->addAction(action);
        //action绑定事件
        //action是所要绑定的对象
        //SIGNAL（triggered()）事件触发
        //SLOT（deleteItem()）绑定响应的函数
         connect(action,SIGNAL(triggered()),this,SLOT(deleteItem()));
    }
    popMenu->exec(QCursor::pos()); // 菜单出现的位置为当前鼠标的位置
}

void HtmyQListWidget::deleteItem()
{
    foreach(QModelIndex index,this->selectionModel()->selectedIndexes()){
            this->takeItem(index.row());
    }
}


