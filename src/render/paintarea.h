#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include "document.h"

class PaintArea : public QWidget
{
    Q_OBJECT
public:
    explicit PaintArea(QWidget *parent = 0);
    ~PaintArea();

signals:

public slots:
};

#endif // PAINTAREA_H
