/**
  ******************************************************************************
  * @file    usb_regs.h
  * @author  MCD Application Team
  * @version V4.0.0
  * @date    28-August-2012
  * @brief   Interface prototype functions to USB cell registers
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; COPYRIGHT 2012 STMicroelectronics</center></h2>
  *
  * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
  * You may not use this file except in compliance with the License.
  * You may obtain a copy of the License at:
  *
  *        http://www.st.com/software_license_agreement_liberty_v2
  *
  * Unless required by applicable law or agreed to in writing, software 
  * distributed under the License is distributed on an "AS IS" BASIS, 
  * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  * See the License for the specific language governing permissions and
  * limitations under the License.
  *
  ******************************************************************************
  */


// Define to prevent recursive inclusion
#ifndef __USB_REGS_H
#define __USB_REGS_H


// Exported types

// double buffered endpoint direction
typedef enum _EP_DBUF_DIR {
	EP_DBUF_ERR,
	EP_DBUF_OUT,
	EP_DBUF_IN
} EP_DBUF_DIR;

// endpoint buffer number
enum EP_BUF_NUM {
	EP_NOBUF,
	EP_BUF0,
	EP_BUF1
};


// Exported constants
#define RegBase     (0x40005C00L)  // USB_IP Peripheral Registers base address
#define PMAAddr     (0x40006000L)  // USB_IP Packet Memory Area base address

// General USB registers
#define CNTR        ((__IO unsigned *)(RegBase + 0x40))     // Control register
#define ISTR        ((__IO unsigned *)(RegBase + 0x44))     // Interrupt status register
#define FNR         ((__IO unsigned *)(RegBase + 0x48))     // Frame number register
#define DADDR       ((__IO unsigned *)(RegBase + 0x4C))     // Device address register
#define BTABLE      ((__IO unsigned *)(RegBase + 0x50))     // Buffer table address register

// Endpoint registers
#define EP0REG      ((__IO unsigned *)(RegBase)) // endpoint 0 register address

// Endpoint Addresses (w/direction)
#define EP0_OUT     ((uint8_t)0x00)  
#define EP0_IN      ((uint8_t)0x80) 
#define EP1_OUT     ((uint8_t)0x01)  
#define EP1_IN      ((uint8_t)0x81)  
#define EP2_OUT     ((uint8_t)0x02)  
#define EP2_IN      ((uint8_t)0x82)  
#define EP3_OUT     ((uint8_t)0x03)  
#define EP3_IN      ((uint8_t)0x83) 
#define EP4_OUT     ((uint8_t)0x04)  
#define EP4_IN      ((uint8_t)0x84)
#define EP5_OUT     ((uint8_t)0x05)  
#define EP5_IN      ((uint8_t)0x85)
#define EP6_OUT     ((uint8_t)0x06)  
#define EP6_IN      ((uint8_t)0x86)
#define EP7_OUT     ((uint8_t)0x07)  
#define EP7_IN      ((uint8_t)0x87)

// endpoints enumeration
#define ENDP0       ((uint8_t)0)
#define ENDP1       ((uint8_t)1)
#define ENDP2       ((uint8_t)2)
#define ENDP3       ((uint8_t)3)
#define ENDP4       ((uint8_t)4)
#define ENDP5       ((uint8_t)5)
#define ENDP6       ((uint8_t)6)
#define ENDP7       ((uint8_t)7)

// ISTR interrupt events
#define ISTR_CTR    (0x8000) // Correct TRansfer (clear-only bit)
#define ISTR_DOVR   (0x4000) // DMA OVeR/underrun (clear-only bit)
#define ISTR_ERR    (0x2000) // ERRor (clear-only bit)
#define ISTR_WKUP   (0x1000) // WaKe UP (clear-only bit)
#define ISTR_SUSP   (0x0800) // SUSPend (clear-only bit)
#define ISTR_RESET  (0x0400) // RESET (clear-only bit)
#define ISTR_SOF    (0x0200) // Start Of Frame (clear-only bit)
#define ISTR_ESOF   (0x0100) // Expected Start Of Frame (clear-only bit)

#define ISTR_DIR    (0x0010)  // DIRection of transaction (read-only bit)
#define ISTR_EP_ID  (0x000F)  // EndPoint IDentifier (read-only bit)

#define CLR_CTR     (~ISTR_CTR)   // clear Correct TRansfer bit
#define CLR_DOVR    (~ISTR_DOVR)  // clear DMA OVeR/underrun bit
#define CLR_ERR     (~ISTR_ERR)   // clear ERRor bit
#define CLR_WKUP    (~ISTR_WKUP)  // clear WaKe UP bit
#define CLR_SUSP    (~ISTR_SUSP)  // clear SUSPend bit
#define CLR_RESET   (~ISTR_RESET) // clear RESET bit
#define CLR_SOF     (~ISTR_SOF)   // clear Start Of Frame bit
#define CLR_ESOF    (~ISTR_ESOF)  // clear Expected Start Of Frame bit

// CNTR control register bits definitions
#define CNTR_CTRM   (0x8000) // Correct TRansfer Mask
#define CNTR_DOVRM  (0x4000) // DMA OVeR/underrun Mask
#define CNTR_ERRM   (0x2000) // ERRor Mask
#define CNTR_WKUPM  (0x1000) // WaKe UP Mask
#define CNTR_SUSPM  (0x0800) // SUSPend Mask
#define CNTR_RESETM (0x0400) // RESET Mask
#define CNTR_SOFM   (0x0200) // Start Of Frame Mask
#define CNTR_ESOFM  (0x0100) // Expected Start Of Frame Mask
#define CNTR_RESUME (0x0010) // RESUME request
#define CNTR_FSUSP  (0x0008) // Force SUSPend
#define CNTR_LPMODE (0x0004) // Low-power MODE
#define CNTR_PDWN   (0x0002) // Power DoWN
#define CNTR_FRES   (0x0001) // Force USB RESet

// FNR Frame Number Register bit definitions
#define FNR_RXDP    (0x8000) // status of D+ data line
#define FNR_RXDM    (0x4000) // status of D- data line
#define FNR_LCK     (0x2000) // LoCKed
#define FNR_LSOF    (0x1800) // Lost SOF
#define FNR_FN      (0x07FF) // Frame Number

// DADDR Device ADDRess bit definitions
#define DADDR_EF    (0x80)
#define DADDR_ADD   (0x7F)

// Endpoint register
// bit positions
#define EP_CTR_RX      (0x8000) // EndPoint Correct TRansfer RX
#define EP_DTOG_RX     (0x4000) // EndPoint Data TOGGLE RX
#define EPRX_STAT      (0x3000) // EndPoint RX STATus bit field
#define EP_SETUP       (0x0800) // EndPoint SETUP
#define EP_T_FIELD     (0x0600) // EndPoint TYPE
#define EP_KIND        (0x0100) // EndPoint KIND
#define EP_CTR_TX      (0x0080) // EndPoint Correct TRansfer TX
#define EP_DTOG_TX     (0x0040) // EndPoint Data TOGGLE TX
#define EPTX_STAT      (0x0030) // EndPoint TX STATus bit field
#define EPADDR_FIELD   (0x000F) // EndPoint ADDRess FIELD

// EndPoint REGister MASK (no toggle fields)
#define EPREG_MASK     (EP_CTR_RX|EP_SETUP|EP_T_FIELD|EP_KIND|EP_CTR_TX|EPADDR_FIELD)

// EP_TYPE[1:0] EndPoint TYPE
#define EP_TYPE_MASK   (0x0600) // EndPoint TYPE Mask
#define EP_BULK        (0x0000) // EndPoint BULK
#define EP_CONTROL     (0x0200) // EndPoint CONTROL
#define EP_ISOCHRONOUS (0x0400) // EndPoint ISOCHRONOUS
#define EP_INTERRUPT   (0x0600) // EndPoint INTERRUPT
#define EP_T_MASK      (~EP_T_FIELD & EPREG_MASK)

// EP_KIND EndPoint KIND
#define EPKIND_MASK    (~EP_KIND & EPREG_MASK)

// STAT_TX[1:0] STATus for TX transfer
#define EP_TX_DIS      (0x0000) // EndPoint TX DISabled
#define EP_TX_STALL    (0x0010) // EndPoint TX STALLed
#define EP_TX_NAK      (0x0020) // EndPoint TX NAKed
#define EP_TX_VALID    (0x0030) // EndPoint TX VALID
#define EPTX_DTOG1     (0x0010) // EndPoint TX Data TOGgle bit1
#define EPTX_DTOG2     (0x0020) // EndPoint TX Data TOGgle bit2
#define EPTX_DTOGMASK  (EPTX_STAT|EPREG_MASK)

// STAT_RX[1:0] STATus for RX transfer
#define EP_RX_DIS      (0x0000) // EndPoint RX DISabled
#define EP_RX_STALL    (0x1000) // EndPoint RX STALLed
#define EP_RX_NAK      (0x2000) // EndPoint RX NAKed
#define EP_RX_VALID    (0x3000) // EndPoint RX VALID
#define EPRX_DTOG1     (0x1000) // EndPoint RX Data TOGgle bit1
#define EPRX_DTOG2     (0x2000) // EndPoint RX Data TOGgle bit1
#define EPRX_DTOGMASK  (EPRX_STAT|EPREG_MASK)


// Exported macros
#define _SetENDPOINT(bEpNum,wRegValue) (*(EP0REG + bEpNum)= (uint16_t)wRegValue)
#define _GetENDPOINT(bEpNum)           ((uint16_t)(*(EP0REG + bEpNum)))
#define _pEPTxAddr(bEpNum)  ((uint32_t *)((*BTABLE+bEpNum * 8  ) * 2 + PMAAddr))
#define _pEPTxCount(bEpNum) ((uint32_t *)((*BTABLE+bEpNum * 8 + 2) * 2 + PMAAddr))
#define _pEPRxAddr(bEpNum)  ((uint32_t *)((*BTABLE+bEpNum * 8 + 4) * 2 + PMAAddr))
#define _pEPRxCount(bEpNum) ((uint32_t *)((*BTABLE+bEpNum * 8 + 6) * 2 + PMAAddr))


// External variables
extern __IO uint16_t wIstr;  // ISTR register last read value


// Function prototypes
void SetEPType(uint8_t /*bEpNum*/, uint16_t /*wType*/);
void SetEPTxStatus(uint8_t /*bEpNum*/, uint16_t /*wState*/);
void SetEPRxStatus(uint8_t /*bEpNum*/, uint16_t /*wState*/);
void SetDouBleBuffEPStall(uint8_t /*bEpNum*/, uint8_t bDir);
uint16_t GetEPTxStatus(uint8_t /*bEpNum*/);
uint16_t GetEPRxStatus(uint8_t /*bEpNum*/);
void SetEPRxTxStatus(uint8_t bEpNum, uint16_t wStateRx, uint16_t wStateTx);
void SetEPTxValid(uint8_t /*bEpNum*/);
void SetEPRxValid(uint8_t /*bEpNum*/);
uint16_t GetTxStallStatus(uint8_t /*bEpNum*/);
uint16_t GetRxStallStatus(uint8_t /*bEpNum*/);
void SetEP_KIND(uint8_t /*bEpNum*/);
void ClearEP_KIND(uint8_t /*bEpNum*/);
void Set_Status_Out(uint8_t /*bEpNum*/);
void Clear_Status_Out(uint8_t /*bEpNum*/);
void SetEPDoubleBuff(uint8_t /*bEpNum*/);
void ClearEPDoubleBuff(uint8_t /*bEpNum*/);
void ClearEP_CTR_RX(uint8_t /*bEpNum*/);
void ClearEP_CTR_TX(uint8_t /*bEpNum*/);
void ToggleDTOG_RX(uint8_t /*bEpNum*/);
void ToggleDTOG_TX(uint8_t /*bEpNum*/);
void ClearDTOG_RX(uint8_t /*bEpNum*/);
void ClearDTOG_TX(uint8_t /*bEpNum*/);
void SetEPAddress(uint8_t /*bEpNum*/, uint8_t /*bAddr*/);
uint8_t GetEPAddress(uint8_t /*bEpNum*/);
void SetEPTxAddr(uint8_t /*bEpNum*/, uint16_t /*wAddr*/);
void SetEPRxAddr(uint8_t /*bEpNum*/, uint16_t /*wAddr*/);
uint16_t GetEPTxAddr(uint8_t /*bEpNum*/);
uint16_t GetEPRxAddr(uint8_t /*bEpNum*/);
void SetEPTxCount(uint8_t /*bEpNum*/, uint16_t /*wCount*/);
void SetEPRxCount(uint8_t /*bEpNum*/, uint16_t /*wCount*/);
uint16_t GetEPTxCount(uint8_t /*bEpNum*/);
uint16_t GetEPRxCount(uint8_t /*bEpNum*/);
void SetEPDblBuf0Addr(uint8_t /*bEpNum*/, uint16_t /*wBuf0Addr*/);
void SetEPDblBuf1Addr(uint8_t /*bEpNum*/, uint16_t /*wBuf1Addr*/);
void SetEPDblBuffAddr(uint8_t /*bEpNum*/, uint16_t /*wBuf0Addr*/, uint16_t /*wBuf1Addr*/);
uint16_t GetEPDblBuf0Addr(uint8_t /*bEpNum*/);
uint16_t GetEPDblBuf1Addr(uint8_t /*bEpNum*/);
void SetEPDblBuf0Count(uint8_t /*bEpNum*/, uint8_t /*bDir*/, uint16_t /*wCount*/);
void SetEPDblBuf1Count(uint8_t /*bEpNum*/, uint8_t /*bDir*/, uint16_t /*wCount*/);
void SetEPDblBuffCount(uint8_t /*bEpNum*/, uint8_t /*bDir*/, uint16_t /*wCount*/);
uint16_t GetEPDblBuf0Count(uint8_t /*bEpNum*/);
uint16_t GetEPDblBuf1Count(uint8_t /*bEpNum*/);
EP_DBUF_DIR GetEPDblBufDir(uint8_t /*bEpNum*/);
void FreeUserBuffer(uint8_t bEpNum/*bEpNum*/, uint8_t bDir);
uint16_t ByteSwap(uint16_t);

#endif // __USB_REGS_H
