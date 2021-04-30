#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QVariantList>


class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = nullptr);

    Q_INVOKABLE QString entropy(int length);
    Q_INVOKABLE QVariantList getRandomValues(int length);
    Q_INVOKABLE void setItem(QString key, QString value);
    Q_INVOKABLE QString getItem(QString key);
    Q_INVOKABLE void removeItem(QString key);
    Q_INVOKABLE bool itemExists(QString key);
};

#endif // UTILS_H
