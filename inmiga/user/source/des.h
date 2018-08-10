#ifndef _DES_H_
#define _DES_H_

#include "typedef.h"

extern unsigned char Mout[8];

unsigned char TripleMAC(unsigned char *initdata,unsigned char *insdata,unsigned char datalen,unsigned char *key);
void SDES( unsigned char MsgIn[], unsigned char Key[], unsigned char Mode);
void TDES( unsigned char MsgIn[], unsigned char Key[], unsigned char Mode);

#endif
