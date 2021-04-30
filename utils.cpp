#include "utils.h"
#include <QRandomGenerator>
#include <QDebug>
#include <QFile>


Utils::Utils(QObject *parent) : QObject(parent)
{

}

QString Utils::entropy(int length)
{
    quint32 chain[length];
    QRandomGenerator::global()->fillRange(chain, length);
    return QString(QByteArray((const char*)&chain, length));
}

QVariantList Utils::getRandomValues(int length)
{
    QVector<quint8> values(length, '0');
    QRandomGenerator::global()->generate(values.begin(), values.end());
    return QVariantList(values.begin(), values.end());
}

void Utils::setItem(QString key, QString value)
{
    QFile item(key);
    item.open(QIODevice::Truncate | QIODevice::WriteOnly);
    item.write(value.toUtf8());
    item.close();
}

QString Utils::getItem(QString key)
{
    if (QFile::exists(key)) {
        QFile item(key);
        item.open(QIODevice::ReadOnly);
        return QString::fromUtf8(item.readAll());
    }
    return "";
}

void Utils::removeItem(QString key)
{
    QFile::remove(key);
}

bool Utils::itemExists(QString key)
{
    return QFile::exists(key);
}
