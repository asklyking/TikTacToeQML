#ifndef MINIMAXALGORITHM_H
#define MINIMAXALGORITHM_H

#include <QObject>

class MinimaxAlgorithm : public QObject
{
        Q_OBJECT
    public:
        explicit MinimaxAlgorithm(QObject *parent = nullptr);

    signals:

    public slots:
};

#endif // MINIMAXALGORITHM_H