/*
 * CircularBuffer.h
 *
 * A simple Circular Buffer
 *
 * Created: 28/11/2016 10:15:48 PM
 *  Author: Chris
 */ 

#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdint.h>
#include <stdbool.h>

 typedef struct CircularBuffer
 {
	 uint8_t* bytes;
	 uint16_t size;
	 uint16_t writeOffset;
	 uint16_t readOffset;
	 bool isFull;
 }
 CircularBuffer;

 /* Creates a buffer with a capacity of byteCount bytes. */
 CircularBuffer* circularBuffer_create( uint16_t byteCount );

 /* Adds a byte to the buffer, returns true if the byte was written or false if the buffer is full. */
 bool circularBuffer_writeByte( CircularBuffer *buffer, uint8_t byte );

 /* Returns true if the buffer is empty, false if the buffer holds some bytes. */
 bool circularBuffer_isEmpty( CircularBuffer *buffer );

 /* Reads a byte from the buffer to the specified location, byteOut. Returns true if the byte was read, false if there were no bytes to read (in this case byteOut is not modified). */
 bool circularBuffer_readByte( CircularBuffer *buffer, uint8_t *byteOut );

 /* Free's the memory allocated by circularBuffer_create(...). */
 void circularBuffer_destroy( CircularBuffer *buffer );

#endif /* CIRCULARBUFFER_H_ */