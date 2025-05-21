#include "BlockMouseEvents.h"
#include <QMouseEvent>
#include <QContextMenuEvent>
#include <QWheelEvent>

BlockMouseEvents::BlockMouseEvents(QObject *parent)
    : QObject(parent)
{
}

bool BlockMouseEvents::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress ||
        event->type() == QEvent::MouseButtonRelease ||
        event->type() == QEvent::MouseMove ||
        event->type() == QEvent::ContextMenu ||
        event->type() == QEvent::Wheel)
    {
        return true;  // 이벤트 차단
    }

    return QObject::eventFilter(watched, event);
}
