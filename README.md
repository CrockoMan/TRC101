# TRC101
Библиотека для работы с трансивером TRC101
### Технологии:
C, WinAVR, CodeVisionAVR </br></br>
TRC_RCV пример работы как ресивер</br>
TRC_SND пример работы как передатчик</br>
TRC работа в режиме трансивера</br></br>
TrcPortInit() инициализация портов</br>
TrcInitSnd() инициализация режима передатчика</br>
writeCmd() запись коммандного буфера</br>
TrcInitRcv() инициализация режима приёмника</br>
FIFOReset() сброс FIFO буфера</br>
TrcSendByte() отправка одного байта</br>
TRCSpiSend() Отправка SPI</br>
SpiRead() Чтение SPI</br>
GetTRCPoket(unsigned char *, unsigned char) получение пакета из TRC101</br>
TrcSendPocket(unsigned char *, unsigned char) запись пакета TRC101</br></br>
Автор: [К.Гурашкин](<https://github.com/CrockoMan>) 
