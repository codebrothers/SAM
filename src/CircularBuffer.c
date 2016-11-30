/*
 * CircularBuffer.c
 *
 * Created: 28/11/2016 10:14:36 PM
 *  Author: Chris
 */ 

 #include "CircularBuffer.h"
 #include <stdlib.h>

 CircularBuffer* circularBuffer_create( uint16_t byteCount )
 {
	uint8_t* bytes = calloc( (size_t)byteCount, sizeof(uint8_t) );
	CircularBuffer* buffer = malloc(sizeof(CircularBuffer));
	buffer->bytes = bytes;
	buffer->size = byteCount;
	buffer->writeOffset = 0;
	buffer->readOffset = 0;
	buffer->isFull = false;
	return buffer;
 }

 inline bool circularBuffer_isEmpty( CircularBuffer* buffer )
 {
	return (buffer->writeOffset == buffer->readOffset) && !(buffer->isFull);
 }

 bool circularBuffer_readByte( CircularBuffer* buffer, uint8_t* byteOut )
 {
	if( circularBuffer_isEmpty( buffer ) ) return false;
	
	*byteOut = (buffer->bytes)[buffer->readOffset];
	++(buffer->readOffset);
	if(buffer->readOffset == buffer->size) buffer->readOffset = 0;

	buffer->isFull = false;

	return true;
 }

 bool circularBuffer_writeByte( CircularBuffer* buffer, uint8_t byte )
 {
	if(buffer->isFull) return false;

	(buffer->bytes)[buffer->writeOffset] = byte;
	++(buffer->writeOffset);
	if(buffer->writeOffset == buffer->size) buffer->writeOffset = 0;

	if(buffer->writeOffset == buffer->readOffset) buffer->isFull = true;

	return byte;
 }

 void circularBuffer_destroy( CircularBuffer* buffer )
 {
	free(buffer->bytes);
	free(buffer);
 }



