#ifndef _TOKEN_CON_H_
#define _TOKEN_CON_H_

extern uint8_t sciRxBuf[64];
extern uint8_t sciRxOffset;

void tokenIOInit(void);
void tokenPowerOn(void);
void tokenPowerOff(void);
void tokenEnableTrx(void);
void tokenDisableTrx(void);

void tokenConfig(void);
void tokenControl(uint8_t conlen,uint8_t* conContent);
void tokenRead(uint8_t recordNum);

#endif