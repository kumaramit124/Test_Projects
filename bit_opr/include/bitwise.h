#define isBitSet(byte, bit) ((byte) & (1 << (bit)))

#define setBit(byte, bit) ((byte) |= (1 << (bit)))
#define clearBit(byte, bit) ((byte) &= ~(1 << (bit)))
#define toggleBit(byte, bit) ((byte) ^= (1 << (bit)))

#define setBitTo(byte, bit, value) ((value) ? setBit(byte, bit) : clearBit(byte, bit))
