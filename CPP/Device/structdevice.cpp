#include "structdevice.h"

QDataStream &operator <<(QDataStream &ds, StructDevice &data)
{
    SetSingleRulesForDS(ds);

    ds << data.x
       << data.y
       << data.z
       << data.w;

    return ds;
}

QDataStream &operator >>(QDataStream &ds, StructDevice &data)
{
    SetSingleRulesForDS(ds);

    ds >> data.x
       >> data.y
       >> data.z
       >> data.w;

    return ds;
}

QDebug operator <<(QDebug debug, const StructDevice &data)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "x: " << data.x << "\n";
    debug.nospace() << "y: " << data.y << "\n";
    debug.nospace() << "z: " << data.z << "\n";
    debug.nospace() << "w: " << data.w << "\n";


    return debug;
}

void SetSingleRulesForDS(QDataStream &ds)
{
    ds.setVersion(QDataStream::Qt_5_11);
    ds.setByteOrder(QDataStream::LittleEndian);
    ds.setFloatingPointPrecision(QDataStream::SinglePrecision);
}
