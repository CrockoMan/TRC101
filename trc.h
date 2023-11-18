#define TRCPORT PORTB
#define TRCDDR  DDRB
#define TRCPIN  PINB
#define FINTPIN PIND
#define SDI     0 // SDI SPI Data input (RFM12B side)
#define SCK     1 // SCK SPI clock
#define CS      2 // nCS SPI SS (chip select)
#define SDO     3 // SDO SPI Data output (RFM12B side)
#define NFSEL   4 // DATA/nFSEL
#define FINT    5 // CR/FINT (PORTD)

#define HI(x) TRCPORT |=  (1<<(x))
#define LO(x) TRCPORT &= ~(1<<(x))
#define WAIT_SDO_LOW() TRCPIN&(1<<SDO)
#define WAIT_SDO_HI() ~TRCPIN&(1<<SDO)
#define WAIT_FINT_HI() ~FINTPIN&(1<<FINT)

#pragma used+
void TrcPortInit(); 
void TrcInitSnd(); 
unsigned int writeCmd(unsigned int);
void TrcInitRcv();
void FIFOReset();
void TrcSendByte(unsigned char );
void TRCSpiSend(unsigned char, unsigned char );
unsigned char SpiRead();
void GetTRCPoket(unsigned char *, unsigned char);
void TrcSendPocket(unsigned char *, unsigned char);
#pragma used-