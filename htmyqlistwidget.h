#ifndef HTMYQLISTWIDGET_H
#define HTMYQLISTWIDGET_H

#include <QListWidget>
#include <QMouseEvent>
#include <QMenu>
# pragma execution_character_set("utf-8")

class HtmyQListWidget : public QListWidget
{
    Q_OBJECT
public:
    explicit HtmyQListWidget(QWidget *parent = nullptr);
    ~HtmyQListWidget();
    void dropEvent(QDropEvent * event);
    void performDrag();
signals:
public slots:
    void contextMenuEvent ( QContextMenuEvent * event );
    void deleteItem();
};

#endif // HTMYQLISTWIDGET_H
