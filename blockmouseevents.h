#ifndef BLOCKMOUSEEVENTS_H
#define BLOCKMOUSEEVENTS_H

#include <QObject>
#include <QEvent>

class BlockMouseEvents : public QObject
{
    Q_OBJECT

public:
    explicit BlockMouseEvents(QObject *parent = nullptr);

protected:
    bool eventFilter(QObject *watched, QEvent *event) override;
};

#endif // BLOCKMOUSEEVENTS_H
