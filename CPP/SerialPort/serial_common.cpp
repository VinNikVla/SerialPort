#include "serial_common.h"

QString toString(const PropertySerialPort &prop)
{
    return QString("Name: " + prop.name + "\n" +
                   "Baud Rate: " + prop.stringBaudRate + "\n" +
                   "Data Bits: " + prop.stringDataBits + "\n" +
                   "Parity: " + prop.stringParity + "\n" +
                   "Stop Bits: " + prop.stringStopBits + "\n" +
                   "Flow Control: " + prop.stringFlowControl);
}
