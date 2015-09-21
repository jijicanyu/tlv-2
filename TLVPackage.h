#ifndef __TLVPACKAGE_H__
#define __TLVPACKAGE_H__

#include "TLVEntity.h"

class TLVPackage
{
public:
        TLVPackage();
        virtual ~TLVPackage();

	/* Construct the data into TLVEntity,the data would contain one or more TLVEntity Object */
        static int Construct(const uint8_t *data, uint32_t dataSize, TLVEntity *tlvEntity, uint32_t &entitySize);

	/* Paser TLVEntitys into data stream */
        static int Parse(TLVEntity *tlvEntity,uint32_t entitySize, uint8_t *buffer, uint32_t &bufferLength);

	static uint32_t GetLength(const uint8_t *data);

	static uint8_t* SetLength(uint32_t length, uint8_t *buffer);
private:
	// helper function to scan the tag ID + length field and then
	// return a pointer to the beginning of value data
	// only parse the first TLVEntity in buffer
	static const uint8_t* ParseTlvHeader(const uint8_t* buffer, uint32_t bufferLength, Tlv_t *tlv);

};

#endif  //__TLVPACKAGE_H__