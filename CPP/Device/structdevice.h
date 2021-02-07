#pragma once

#include <QString>
#include <QObject>
#include <QDebug>
#include <QDataStream>

namespace DeviceCommand {

const quint8 PREFIX = 0x40;

}

void SetSingleRulesForDS(QDataStream &ds);


enum class DeviceState: quint8 {
    Green,      ///< Зеленый - значит все отлично
    Yellow,     ///< Желтый - есть небольшие проблемы, но работоспособность не утрачена
    Red,        ///< Красный - все плохо!! Обрати на меня внимание!
    Unknown     ///< Состояние не определено. Блок еще не опрошен, или внешняя система (внешние системы диагностике не подлежат).
};

struct StructDevice
{

    float x;
    float y;
    float z;
    float w;

    friend QDataStream& operator << (QDataStream& ds, StructDevice& data);
    friend QDataStream& operator >> (QDataStream& ds, StructDevice& data);

    friend QDebug operator << (QDebug debug, const StructDevice& data);

};
