/*******************************************************************************
 *                                O P E N  T S
 *******************************************************************************
 * SPDX-License-Identifier: GPL-3.0-or-later
 * Copyright 2025 Electronic Arts Inc.
 * Copyright 2026 OpenTS contributors
 *
 * Contains material derived from Electronic Arts source code.
 * Modified by OpenTS contributors, 2026.
 * EA's GPLv3 Section 7 additional terms and supplemental warranty
 * disclaimers apply; see LICENSE.md.
 ******************************************************************************/

/***********************************************************************************************
 ***              C O N F I D E N T I A L  ---  W E S T W O O D  S T U D I O S               ***
 ***********************************************************************************************
 *                                                                                             *
 *                 Project Name : Command & Conquer                                            *
 *                                                                                             *
 *                     $Archive:: /VSS_Sync/wwlib/mpmath.cpp                                  $*
 *                                                                                             *
 *                      $Author:: Vss_sync                                                    $*
 *                                                                                             *
 *                     $Modtime:: 3/21/01 12:01p                                              $*
 *                                                                                             *
 *                    $Revision:: 2                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   _Byte_Precision -- Determines the number of bytes significant in long integer.            *
 *   memrev -- Reverse the byte order of the buffer specified.                                 *
 *   XMP_Abs -- Perform an absolute value on the specified MP number.                          *
 *   XMP_Add -- Add two MP numbers with a carry option.                                        *
 *   XMP_Add_Int -- Add an integer to an MP number (with carry).                               *
 *   XMP_Compare -- Compare one MP number with another.                                        *
 *   XMP_Count_Bits -- Count the total number of bits (precision) in MP number.                *
 *   XMP_Count_Bytes -- Counts the number of precision bytes in MP number.                     *
 *   XMP_Dec -- Decrement the MP number by one.                                                *
 *   XMP_Decode_ASCII -- Convert ASCII into an MP number.                                      *
 *   XMP_DER_Decode -- Decode a DER number into an MP number.                                  *
 *   XMP_DER_Encode -- Encode a number into a buffer using DER.                                *
 *   XMP_DER_Length_Encode -- Output the length of a DER block.                                *
 *   XMP_Double_Mul -- Double precision MP multiply.                                           *
 *   XMP_Encode -- Encode MP number into buffer as compactly as possible.                      *
 *   XMP_Fermat_Test -- Performs Fermat's Little Theorem on an MP number.                      *
 *   XMP_Hybrid_Mul -- Special hybrid short multiply (with carry).                             *
 *   XMP_Inc -- Increment an MP number by one.                                                 *
 *   XMP_Init -- Initialize an MP number to a starting value.                                  *
 *   XMP_Inverse_A_Mod_B -- Inverts and performs modulus on an MP number.                      *
 *   XMP_Is_Prime -- Determine if the specified MP number is prime.                            *
 *   XMP_Is_Small_Prime -- Determine if MP number is a small prime.                            *
 *   XMP_Mod_Mult -- Perform a multiply - modulus operation.                                   *
 *   XMP_Mod_Mult_Clear -- Remove temporary values from memory.                                *
 *   XMP_Move -- Assign one MP number to another.                                              *
 *   XMP_Neg -- Negate the specified MP number.                                                *
 *   XMP_Not -- Perform bitwise NOT operation on MP number.                                    *
 *   XMP_Prepare_Modulus -- Prepare globals for modulus operation.                             *
 *   XMP_Rabin_Miller_Test -- Performs the Rabin Miller test for primality.                    *
 *   XMP_Randomize -- Generate a random MP number between the boundaries specified.            *
 *   XMP_Randomize -- Generate a random MP number.                                             *
 *   XMP_Reciprocal -- Compute the reciprocal (inverse) of the MP number.                      *
 *   XMP_Rotate_Left -- Rotate specified MP number leftward.                                   *
 *   XMP_Shift_Left_Bits -- Shifts the MP number left by the specified bit count.              *
 *   XMP_Shift_Right_Bits -- Shift the MP number right by specified bit count.                 *
 *   XMP_Signed_Decode -- Decode a number as if it were signed.                                *
 *   XMP_Signed_Div -- Signed divide of one MP number into another.                            *
 *   XMP_Signed_Mult -- A signed multiply between two MP numbers.                              *
 *   XMP_Signed_Mult_Int -- Multiply an MP number by a signed simple integer.                  *
 *   XMP_Significance -- Fetch the precision (bytes) of the MP number.                         *
 *   XMP_Small_Divisors_Test -- Perform the small divisors test on an MP number.               *
 *   XMP_Sub -- Subtract one MP number from another (with borrow).                             *
 *   XMP_Sub_Int -- Subtract an integer from an MP number (with borrow).                       *
 *   XMP_Unsigned_Decode -- Decode a number as if it were unsigned.                            *
 *   XMP_Unsigned_Div -- Unsigned divide of one MP number into another.                        *
 *   XMP_Unsigned_Div_Int -- Perform a short integer divide into an MP number.                 *
 *   XMP_Unsigned_Mult -- Multiply two unsigned MP numbers together.                           *
 *   XMP_Unsigned_Mult_Int -- Multiply an MP number by a simple integer.                       *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "mpmath.h"

#include "assert.h"
#include "bsearch.h"

#include <cctype>
#include <climits>
#include <cstdlib>
#include <cstring>


extern unsigned short primeTable[3511];


#define	UPPER_MOST_BIT			0x80000000L
#define	SEMI_UPPER_MOST_BIT	0x8000
#define	SEMI_MASK				((unsigned short)~0)

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a)	(sizeof(a)/sizeof(a[0]))
#endif

#define	MIN(a, b)	(((a) < (b)) ? (a) : (b))
#define	_USERENTRY


// Misc functions.
void memrev(char * buffer, size_t length);
unsigned short mp_quo_digit(unsigned short * dividend);


/// <summary>
/// Fetches the table of small prime numbers.
/// This routine gives the primality tests access to the shared table of small primes.
/// </summary>
/// <returns>Returns with a pointer to the small prime table.</returns>
unsigned short const * XMP_Fetch_Prime_Table(void)
{
	return(primeTable);
}





/// <summary>
/// Determines if the MP number is equal to the integer specified.
/// </summary>
/// <param name="i">The integer value to compare the MP number against.</param>
/// <returns>bool; Does the MP number equal the integer?</returns>
bool XMP_Test_Eq_Int(digit const * r, int i, int p)
{
	return( (*r == (digit)i ) && XMP_Significance(r,p) <= 1 );
}


/***********************************************************************************************
 * _Byte_Precision -- Determines the number of bytes significant in long integer.              *
 *                                                                                             *
 *    This utility routine will determine the number of precision bytes exist in the long      *
 *    integer specified. There are some optimizations that can occur if the byte precision     *
 *    is known.                                                                                *
 *                                                                                             *
 * INPUT:   value -- The value of the long integer that the byte precision will be calculated  *
 *                   for.                                                                      *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes that the long integer requires (at a minimum)     *
 *          to cover the precision of the integer. The minimum value will be 1, the maximum    *
 *          will be 4.                                                                         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
static int _Byte_Precision(unsigned int value)
{
	int byte_count;
	for (byte_count = sizeof(value); byte_count; byte_count--) {
		if (value >> ((byte_count-1)*8)) break;
	}
	return(byte_count);
}


/***********************************************************************************************
 * XMP_DER_Length_Encode -- Output the length of a DER block.                                  *
 *                                                                                             *
 *    This routine will output the length of the block using Distinguished Encoding Rules.     *
 *    The rest of the block must be filled in as appropriate. For data blocks that are less    *
 *    than 128 bytes long, the header consists of only one byte. Longer buffers lengths        *
 *    can consume up to 5 bytes (depends on magnitude of the length value).                    *
 *                                                                                             *
 * INPUT:   length   -- The length of the data block to be output.                             *
 *                                                                                             *
 *          output   -- Pointer to the memory block that will be set up.                       *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes (header) that was used to store the length        *
 *          value. Subsequent data must be placed after the header.                            *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_DER_Length_Encode(unsigned int length, unsigned char * output)
{
	assert(output != NULL);

	int header_length = 0;

	if (length <= SCHAR_MAX) {
		output[header_length++] = (unsigned char)length;
	} else {
		output[header_length++] = (unsigned char)(_Byte_Precision(length) | 0x80);
		for (int byte_counter = _Byte_Precision(length); byte_counter; --byte_counter) {
			output[header_length++] = (unsigned char)(length >> ((byte_counter-1)*8));
		}
	}
	return(header_length);
}


/***********************************************************************************************
 * XMP_DER_Encode -- Encode a number into a buffer using DER.                                  *
 *                                                                                             *
 *    This routine is used to encode a number into a buffer using Distinguished Encoding       *
 *    Rules. The number of bytes used will be, typically, two bytes more than the number of    *
 *    precision bytes in the number.                                                           *
 *                                                                                             *
 * INPUT:   from     -- Pointer to the multi-precision number.                                 *
 *                                                                                             *
 *          output   -- Pointer to the buffer that will hold the DER encoded number.           *
 *                                                                                             *
 *          precision-- The precision of the multi-precision number.                           *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes used in the output buffer.                        *
 *                                                                                             *
 * WARNINGS:   Make sure the buffer is big enough to hold the DER encoded number. For safety   *
 *             make sure it is precision+6 bytes long.                                         *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_DER_Encode(digit const * from, unsigned char * output, int precision)
{
	assert(from != NULL);
	assert(output != NULL);
	assert(precision > 0);

	unsigned char buffer[MAX_UNIT_PRECISION*sizeof(digit)+1];
	int header_count = 0;

	unsigned number_count = XMP_Encode(buffer, from, precision);

	output[header_count++] = 0x02;
	header_count += XMP_DER_Length_Encode(number_count, &output[header_count]);
	memcpy(&output[header_count], buffer, number_count);

	return(header_count+number_count);
}


/***********************************************************************************************
 * XMP_DER_Decode -- Decode a DER number into an MP number.                                    *
 *                                                                                             *
 *    Use this routine to decode a Distinguished Encoding Rules number into a multi-precision  *
 *    number. This is the counterpart function to the XMP_DER_Encode() function.               *
 *                                                                                             *
 * INPUT:   result      -- The buffer the hold the result MP number.                           *
 *                                                                                             *
 *          input       -- Pointer to the DER encoded number.                                  *
 *                                                                                             *
 *          precision   -- The precision of the MP number. This is the maximum precision the   *
 *                         DER number can be.                                                  *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_DER_Decode(digit * result, unsigned char const * input, int precision)
{
	assert(result != NULL);
	assert(input != NULL);
	assert(precision > 0);

	if (*input++ == 0x02) {
		unsigned byte_count;

		if ((*input & 0x80) == 0) {
			byte_count = *input++;
		} else {
			int length = *input++ & 0x7f;
			if (length > 2) return;
			byte_count = *input++;
			if (length > 1) byte_count = (byte_count << 8) | *input++;
		}
		if (byte_count <= (precision * sizeof(digit))) {
			XMP_Signed_Decode(result, input, byte_count, precision);
		}
	}
}


/***********************************************************************************************
 * XMP_Encode -- Encode MP number into buffer.                                                 *
 *                                                                                             *
 *    This routine will encode an multi-precision number into a buffer of specified length.    *
 *    The number of stored in "big endian" format with appropriate sign extension.             *
 *                                                                                             *
 * INPUT:   to       -- Pointer to the buffer to place the number.                             *
 *                                                                                             *
 *          tobytes  -- The number of bytes to use in the destination buffer.                  *
 *                                                                                             *
 *          from     -- Pointer to the MP number to be encoded.                                *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes placed into the destination buffer.               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned XMP_Encode(unsigned char * to, unsigned tobytes, digit const * from, int precision)
{
	assert(to != NULL);
	assert(from != NULL);
	assert(tobytes > 0);
	assert(precision > 0);

	unsigned frombytes = precision * sizeof(digit);
	unsigned char filler = (unsigned char)(XMP_Is_Negative(from, precision) ? 0xff : 0);

	unsigned index;
	for (index = 0; index < (tobytes-frombytes); index++) {
		*to++ = filler;
	}

	const unsigned char * fptr = ((const unsigned char *)from) + MIN(tobytes, frombytes);
	for (index = 0; index < MIN(tobytes, frombytes); index++) {
		*to++ = *--fptr;
	}

	return(tobytes);
}


/***********************************************************************************************
 * XMP_Encode -- Encode MP number into buffer as compactly as possible.                        *
 *                                                                                             *
 *    This routine will encode the MP number into the specified buffer. The number will be     *
 *    encoded using the least number of bytes possible.                                        *
 *                                                                                             *
 * INPUT:   to       -- The buffer to encode the MP number into.                               *
 *                                                                                             *
 *          from     -- Pointer to the MP number to be encoded.                                *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes used in the destination buffer to hold the        *
 *          encoded number.                                                                    *
 *                                                                                             *
 * WARNINGS:   Be sure the destination buffer is big enough to hold the encoded MP number.     *
 *             A safe size would be the precision plus one.                                    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned XMP_Encode(unsigned char * to, digit const * from, int precision)
{
	assert(to != NULL);
	assert(from != NULL);
	assert(precision > 0);

	bool is_negative = XMP_Is_Negative(from, precision);
	unsigned char filler = (unsigned char)(is_negative ? 0xff : 0);
	unsigned char * number_ptr;

	unsigned char * const end = (unsigned char *)from;
	for (number_ptr = (unsigned char *)end + precision - 1; number_ptr > (unsigned char *)end; number_ptr--) {
		if (*number_ptr != filler) break;
	}

	unsigned index = 0;
	if (((*number_ptr & 0x80) && !is_negative) || (!(*number_ptr & 0x80) && is_negative)) {
		to[index++] = filler;
	}

	to[index++] = *number_ptr;

	while (number_ptr != end) {
		to[index++] = *--number_ptr;
	}
	return(index);
}


/***********************************************************************************************
 * XMP_Signed_Decode -- Decode a number as if it were signed.                                  *
 *                                                                                             *
 *    Use this routine to convert a coded number back into an MP number. The coded number      *
 *    is presumed to be signed.                                                                *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the buffer that will hold the decoded MP number.            *
 *                                                                                             *
 *          from     -- Pointer to the encoded MP number.                                      *
 *                                                                                             *
 *          frombytes-- The number of bytes consumed by the encoded MP number.                 *
 *                                                                                             *
 *          precision -- The precision of the MP number (maximum) of the result.               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Be sure that the precision is sufficient to hold the decoded MP number.         *
 *             Otherwise, the result is undefined.                                             *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Signed_Decode(digit * result, const unsigned char * from, int frombytes, int precision)
{
	assert(result != NULL);
	assert(from != NULL);
	assert(frombytes > 0);
	assert(precision > 0);

	unsigned char filler = (unsigned char)((*from & 0x80) ? 0xff : 0);

	int fillcount = precision * sizeof(digit) - frombytes;
	unsigned char * dest = (unsigned char *)&result[precision];

	/*
	**	Fill in any excess significant bytes.
	*/
	int index;
	for (index = 0; index < fillcount; index++) {
		*--dest = filler;
	}

	/*
	**	Move in the remaining bytes.
	*/
	for (index = 0; index < frombytes; index++) {
		*--dest = *from++;
	}
}


/***********************************************************************************************
 * XMP_Unsigned_Decode -- Decode a number as if it were unsigned.                              *
 *                                                                                             *
 *    Use this routine to decode a MP number and treat it as if it were unsigned.              *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the buffer to hold the result MP number.                    *
 *                                                                                             *
 *          from     -- Pointer to the encoded MP number.                                      *
 *                                                                                             *
 *          frombytes-- The number of bytes in the encoded number.                             *
 *                                                                                             *
 *          precision-- The precision of the result MP number -- maximum precision.            *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Be sure the result MP precision is sufficient to hold the decoded number or     *
 *             else the result is undefined.                                                   *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Unsigned_Decode(digit * result, const unsigned char * from, int frombytes, int precision)
{
	assert(result != NULL);
	assert(from != NULL);
	assert(frombytes > 0);
	assert(precision > 0);

	int fillcount = precision * sizeof(digit) - frombytes;
	unsigned char * dest = (unsigned char *)&result[precision];

	/*
	**	Fill in any excess significant bytes.
	*/
	int index;
	for (index = 0; index < fillcount; index++) {
		*--dest = '\0';
	}

	/*
	**	Move in the remaining bytes.
	*/
	for (index = 0; index < frombytes; index++) {
		*--dest = *from++;
	}
}


/***********************************************************************************************
 * XMP_Significance -- Fetch the precision (bytes) of the MP number.                           *
 *                                                                                             *
 *    This routine will return with the precision of the MP number expressed as bytes. The     *
 *    MP number is presumed unsigned.                                                          *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to examine.                                   *
 *                                                                                             *
 *          precision-- The precision of the MP number to examine.                             *
 *                                                                                             *
 * OUTPUT:  Returns with the minimum number of bytes consumed by this MP number.               *
 *                                                                                             *
 * WARNINGS:   Passing a signed MP number to this routine will return an artificially greater  *
 *             precision than it really is.                                                    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Significance(const digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	number += precision;
	do {
		number--;
		if (*number) break;
		precision--;
	} while (precision);
	return(precision);
}


/***********************************************************************************************
 * XMP_Inc -- Increment an MP number by one.                                                   *
 *                                                                                             *
 *    This will increment the MP number by one.                                                *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to increment.                                 *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   If the number wraps around the maximum precision, the results are undefined.    *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Inc(digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	do {
		*number = (*number) + 1;
		if (*number != 0) break;
		number++;
		precision --;
	} while (precision);
}


/***********************************************************************************************
 * XMP_Dec -- Decrement the MP number by one.                                                  *
 *                                                                                             *
 *    Use this routine to decrement the specified MP number by one.                            *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to decrement.                                 *
 *                                                                                             *
 *          precision-- The precision of the MP number to decrement.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   If the number wraps below zero, the results are undefined.                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Dec(digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	do {
		*number -= 1;
		if ((*number) != ~(digit)0) break;
		number++;
		precision--;
	} while (precision);
}


/***********************************************************************************************
 * XMP_Neg -- Negate the specified MP number.                                                  *
 *                                                                                             *
 *    This routine will negate (reverse sign) of the specified MP number.                      *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to negate.                                    *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Neg(digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	XMP_Not(number, precision);
	XMP_Inc(number, precision);
}


/***********************************************************************************************
 * XMP_Abs -- Perform an absolute value on the specified MP number.                            *
 *                                                                                             *
 *    This will perform the absolute value function on the specified MP number. That is, if    *
 *    the MP number is negative, it will be transformed into a positive number. If the number  *
 *    is already positive, then it will be left alone.                                         *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to ABS.                                       *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Abs(digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	if (XMP_Is_Negative(number, precision)) {
		XMP_Neg(number, precision);
	}
}


/***********************************************************************************************
 * XMP_Shift_Right_Bits -- Shift the MP number right by specified bit count.                   *
 *                                                                                             *
 *    Use this routine to perform a right shift of the MP number by the number of bits         *
 *    specified.                                                                               *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to perform the shift upon.                    *
 *                                                                                             *
 *          bits     -- The number of bits to shift.                                           *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This is an unsigned shift.                                                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Shift_Right_Bits(digit * number, int bits, int precision)
{
	assert(number != NULL);
	assert(bits >= 0);
	assert(precision > 0);

	if (bits == 0) return;			/* shift zero bits is a no-op */

	/*
	**	If the shift is by whole bytes, then the shift operation can
	**	be performed very quickly.
	*/
	if (bits == UNITSIZE) {
		number += precision;
		digit carry = 0;
		while (precision--) {
			number--;
			digit temp = *number;
		  	*number = carry;
			carry = temp;
		}
		return;
	}

	/*
	**	If the number of bits to shift is less than one byte, then the
	**	shift operation is a relatively simple "ripple" effect through
	**	the MP number buffer.
	*/
	if (bits < UNITSIZE) {
		number += precision;
		digit carry = 0;
		digit bitmask = (1L << bits) - 1;
		int unbits = UNITSIZE - bits;

		while (precision--) {
			number--;
			digit temp = *number & bitmask;
			*number >>= bits;
			*number |= carry << unbits;
			carry = temp;
		}
		return;
	}

	/*
	**	General purpose slow right.
	*/
	int digits_to_shift = bits / UNITSIZE;
	int bits_to_shift = bits % UNITSIZE;

	int index;
	for (index = digits_to_shift; index < (precision-1); index++) {
		*number = (*(number + digits_to_shift) >> bits_to_shift) | (*(number + (digits_to_shift + 1)) << (UNITSIZE - bits_to_shift));
		number++;
	}

	if (digits_to_shift < precision) {
		*number = (*(number + digits_to_shift) >> bits_to_shift);
		number++;
	}

	for (index= 0; index < MIN(digits_to_shift, precision); index++) {
		*number++ = 0;
	}
}


/***********************************************************************************************
 * XMP_Shift_Left_Bits -- Shifts the MP number left by the specified bit count.                *
 *                                                                                             *
 *    Use this routine to perform a left shift of the specified MP number.                     *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to perform the shift operation on.            *
 *                                                                                             *
 *          bits     -- The number of bits to shift the MP number leftward.                    *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Shift_Left_Bits(digit * number, int bits, int precision)
{
	assert(number != NULL);
	assert(bits >= 0);
	assert(precision > 0);

	if (bits == 0) return;			/* shift zero bits is a no-op */

	/*
	**	If the shift is by whole bytes, then the shift operation can
	**	be performed very quickly.
	*/
	if (bits == UNITSIZE) {
		digit carry = 0;
		while (precision--) {
			digit temp = *number;
			*number = carry;
			carry = temp;
			number++;
		}
		return;
	}

	/*
	**	If the number of bits to shift is less than one byte, then the
	**	shift operation is a relatively simple "ripple" effect through
	**	the MP number buffer.
	*/
	if (bits < UNITSIZE) {
		digit carry = 0;
		digit bitmask = ~(((digit)-1) >> bits);
		int unbits = UNITSIZE - bits;	/* shift bits must be <= UNITSIZE */

		while (precision--) {
			digit temp = *number & bitmask;
			*number = (*number << bits) | (carry >> unbits);
			carry = temp;
			number++;
		}
		return;
	}

	/*
	**	General purpose slow left;
	*/
	int digits_to_shift = bits / UNITSIZE;
	int bits_to_shift = bits % UNITSIZE;

	int index;
	number += precision-1;
	for (index = digits_to_shift; index < (precision-1); index++) {
		*number = (*(number - digits_to_shift) << bits_to_shift) | (*(number - (digits_to_shift + 1)) >> (UNITSIZE - bits_to_shift));
		number--;
	}

	if (digits_to_shift < precision) {
		*number = (*(number - digits_to_shift) << bits_to_shift);
		number--;
	}

	for (index = 0; index < MIN(digits_to_shift, precision); index++) {
		*number-- = 0;
	}
}


/***********************************************************************************************
 * XMP_Rotate_Left -- Rotate specified MP number leftward.                                     *
 *                                                                                             *
 *    This routine will rotate the MP number to the left by one bit. The rotation passes bits  *
 *    through a "carry" bit position. The initial value of this "carry" bit is passed to the   *
 *    routine and the final value is returned as the result.                                   *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to perform the left rotate upon.              *
 *                                                                                             *
 *          carry    -- The initial value of the "carry" bit.                                  *
 *                                                                                             *
 *          precision-- The precision of the MP number specified.                              *
 *                                                                                             *
 * OUTPUT:  Returns with the final value of the carry bit. This is the the bit value of the    *
 *          upper most bit of the MP number prior to the rotate operation.                     *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Rotate_Left(digit * number, bool carry, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	while (precision--) {
		bool temp = ((*number & UPPER_MOST_BIT) != 0);
		*number = (*number << 1);
		if (carry) *number = *number + 1;
		carry = temp;
		number++;
	}
	return(carry);
}


/***********************************************************************************************
 * XMP_Not -- Perform bitwise NOT operation on MP number.                                      *
 *                                                                                             *
 *    Perform a bitwise NOT operation.                                                         *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to operate on.                                *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Not(digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	for (int index = 0; index < precision; index++) {
		*number = ~(*number);
		number++;
	}
}


/***********************************************************************************************
 * XMP_Init -- Initialize an MP number to a starting value.                                    *
 *                                                                                             *
 *    This will initialize (assign) a number to an MP number. The initial value is limited     *
 *    to the precision allowed by a DIGIT type.                                                *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to initialize.                                *
 *                                                                                             *
 *          value    -- Initial integer value to assign to the MP number.                      *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Init(digit * number, digit value, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	memset(number, '\0', precision * sizeof(digit));
	*number = value;
}


/***********************************************************************************************
 * XMP_Count_Bits -- Count the total number of bits (precision) in MP number.                  *
 *                                                                                             *
 *    This routine will count the maximum number of bits used by this MP number. The result    *
 *    could be referred to as the "bit precision" of the MP number.                            *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to examine.                                   *
 *                                                                                             *
 *          precision-- The (digit) precision of the MP number.                                *
 *                                                                                             *
 * OUTPUT:  Returns with the number of significant bits in the MP number.                      *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned XMP_Count_Bits(const digit * number, int precision)
{
	assert(number != NULL);
	assert(precision > 0);

	int sub_precision = XMP_Significance(number, precision);
	if (!sub_precision) return(0);
	int total_bit_count = XMP_Digits_To_Bits(sub_precision);
	number += sub_precision-1;
	digit high_bit_mask = UPPER_MOST_BIT;

	while (!((*number) & high_bit_mask)) {
		high_bit_mask >>= 1;
		total_bit_count--;
	}

	return(total_bit_count);
}


/***********************************************************************************************
 * XMP_Count_Bytes -- Counts the number of precision bytes in MP number.                       *
 *                                                                                             *
 *    This routine will scan the MP number and determine the number of bytes needed to         *
 *    represent the MP number. Consider the result the "byte precision" of the number.         *
 *                                                                                             *
 * INPUT:   number   -- Pointer to the MP number to examine.                                   *
 *                                                                                             *
 *          precision-- Precision of the MP number.                                            *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes required to represent the precision of the number.*
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Count_Bytes(const digit * number, int precision)
{
	unsigned char * ptr = (unsigned char *)number;
	int count = 0;
	for (unsigned index = 0; index < precision*sizeof(digit); index++) {
		if (!*ptr) break;
		count++;
		ptr++;
	}
	return(count);
}


/***********************************************************************************************
 * XMP_Move -- Assign one MP number to another.                                                *
 *                                                                                             *
 *    This will move one MP number over the top of another.                                    *
 *                                                                                             *
 * INPUT:   dest     -- Destination MP number (will get clobbered).                            *
 *                                                                                             *
 *          source   -- Source MP number.                                                      *
 *                                                                                             *
 *          precision-- Precision of both MP numbers.                                          *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Both MP numbers must have the same precision.                                   *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Move(digit * dest, digit const * source, int precision)
{
	memcpy(dest, source, precision * sizeof(digit));
}


/***********************************************************************************************
 * XMP_Compare -- Compare one MP number with another.                                          *
 *                                                                                             *
 *    This routine will compare two MP numbers. It will return a value indicating which MP     *
 *    number is greater or if they are equal.                                                  *
 *                                                                                             *
 * INPUT:   left_number -- The left hand MP number.                                            *
 *                                                                                             *
 *          right_number-- The right hand MP number.                                           *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers.                                    *
 *                                                                                             *
 * OUTPUT:  Returns -1 if the left_number is less than the right_number.                       *
 *          Returns 1 if the left_number is greater than the right number.                     *
 *          Returns 0 if both numbers are identical.                                           *
 *                                                                                             *
 * WARNINGS:   Both numbers must have the same precision.                                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Compare(const digit * left_number, const digit * right_number, int precision)
{
	left_number += precision-1;
	right_number += precision-1;
	do {
		if (*left_number < *right_number) return(-1);
		if (*left_number > *right_number) return(1);
		left_number--;
		right_number--;
		precision--;
	} while (precision);
	return(0);
}


/***********************************************************************************************
 * XMP_Add -- Add two MP numbers with a carry option.                                          *
 *                                                                                             *
 *    Use this routine to add one MP number to another. There is an optional "carry" value     *
 *    that (when true) will add an additional 1 to the result.                                 *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the MP buffer that will hold the result. This can be the    *
 *                      same value as the left_number or right_number pointers.                *
 *                                                                                             *
 *          left_number -- The left hand MP number.                                            *
 *                                                                                             *
 *          right_number-- The right hand MP number.                                           *
 *                                                                                             *
 *          carry       -- Optional carry flag (typically this will be false).                 *
 *                                                                                             *
 *          precision   -- The precision of the numbers involved.                              *
 *                                                                                             *
 * OUTPUT:  Returns with the carry flag after the addition. If the value is true then an       *
 *          overflow occurred.                                                                 *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Add(digit * result, const digit * left_number, const digit * right_number, bool carry, int precision)
{
	while (precision--) {
		digit term = *left_number + *right_number;
		digit final = term + carry;
		carry = (term < *left_number || (carry && final == 0));

		right_number++;
		left_number++;
		*result++ = final;
	}
	return(carry);
}


/***********************************************************************************************
 * XMP_Add_Int -- Add an integer to an MP number (with carry).                                 *
 *                                                                                             *
 *    This routine will add an integer number to an MP number. There is an optional carry      *
 *    parameter. If the carry flag is true, and additional 1 will be added to the result.      *
 *    This routine is much faster than adding two MP numbers together.                         *
 *                                                                                             *
 * INPUT:   result      -- Pointer to the result MP number. This pointer can be the same as    *
 *                         the left_number parameter.                                          *
 *                                                                                             *
 *          left_number -- Pointer to the left hand MP number.                                 *
 *                                                                                             *
 *          right_number-- The integer number to add to the left hand number.                  *
 *                                                                                             *
 *          carry       -- Input carry flag. If this is true, then an additional one will be   *
 *                         added to the result.                                                *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers.                                    *
 *                                                                                             *
 * OUTPUT:  Returns with the result carry flag. A true value means the addition overflowed.    *
 *                                                                                             *
 * WARNINGS:   All MP numbers must share the same precision. Negative numbers are not          *
 *             supported.                                                                      *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Add_Int(digit * result, const digit * left_number, digit right_number, bool carry, int precision)
{
	while (precision--) {
		digit term = *left_number + right_number;
		digit final = term + carry;
		carry = (term < *left_number || (carry && final == 0));

		right_number = 0;
		left_number++;
		*result++ = final;
	}
	return(carry);
}


/***********************************************************************************************
 * XMP_Sub -- Subtract one MP number from another (with borrow).                               *
 *                                                                                             *
 *    This routine will subtract one MP number from another. There is an optional borrow       *
 *    flag that can be specified.                                                              *
 *                                                                                             *
 * INPUT:   result      -- Pointer to the MP number that will hold the result. This pointer    *
 *                         can be the same as the left_number or right_number parameters.      *
 *                                                                                             *
 *          left_number -- The left hand number (value will be subtracted from this).          *
 *                                                                                             *
 *          right_number-- The right hand number (the value to subtract from the left number)  *
 *                                                                                             *
 *          borrow      -- The optional borrow flag. If this flag is true, the an extra one    *
 *                         will be subtracted from the result.                                 *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  Returns with the borrow result flag. If the value is true, then an underflow       *
 *          occurred during subtraction.                                                       *
 *                                                                                             *
 * WARNINGS:   All MP numbers must share the same precision.                                   *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Sub(digit * result, const digit * left_number, const digit * right_number, bool borrow, int precision)
{
	const unsigned short * left_number_ptr = (const unsigned short *)left_number;
	const unsigned short * right_number_ptr = (const unsigned short *)right_number;
	unsigned short * result_ptr = (unsigned short *)result;

	precision *= 2;
	while (precision--) {
		digit x = (digit) *left_number_ptr - (digit) *right_number_ptr - (digit) borrow;
		right_number_ptr++;
		left_number_ptr++;
		*result_ptr++ = (unsigned short)x;
		borrow = (((1L << 16) & x) != 0L);
	}
	return(borrow);
}


/***********************************************************************************************
 * XMP_Sub_Int -- Subtract an integer from an MP number (with borrow).                         *
 *                                                                                             *
 *    This will subtract an integer from the specified MP number. There is an optional borrow  *
 *    flag available.                                                                          *
 *                                                                                             *
 * INPUT:   result      -- Pointer to the MP buffer that will hold the result.                 *
 *                                                                                             *
 *          left_number -- Pointer to the MP number that will be subtracted FROM.              *
 *                                                                                             *
 *          right_number-- The integer to subtract from the left hand number.                  *
 *                                                                                             *
 *          borrow      -- The optional borrow flag. If this value is true, then an extra one  *
 *                         will be subtracted from the result.                                 *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  Returns with the borrow flag of the result. If this value is true, then an         *
 *          underflow occurred during subtraction.                                             *
 *                                                                                             *
 * WARNINGS:   The precision must be identical between the MP numbers involved.                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Sub_Int(digit * result, const digit * left_number, unsigned short right_number, bool borrow, int precision)
{
	const unsigned short * left_number_ptr = (const unsigned short *)left_number;
	unsigned short * result_ptr = (unsigned short *)result;

	precision *= 2;
	while (precision--) {
		digit x = (digit) *left_number_ptr - right_number - borrow;
		left_number_ptr++;
		*result_ptr++ = (unsigned short)x;
		borrow = (((1L << 16) & x) != 0L);

		right_number = 0;
	}
	return(borrow);
}


/***********************************************************************************************
 * XMP_Unsigned_Mult -- Multiply two unsigned MP numbers together.                             *
 *                                                                                             *
 *    This routine will multiply two MP numbers together. The result will have the sum of the  *
 *    significance of the two.                                                                 *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the product MP buffer that will hold the result.         *
 *                                                                                             *
 *          multiplicand-- Pointer to the multiplicand MP number.                              *
 *                                                                                             *
 *          multiplier  -- Pointer to the multiplier MP number.                                *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers.                                    *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Be sure the product will fit within the precision of the result.                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/01/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Unsigned_Mult(digit * prod, const digit * multiplicand, const digit * multiplier, int precision)
{
	XMP_Init(prod, 0, precision);

	/*
	**	Multiplying by zero is always a zero product.
	*/
	if (XMP_Test_Eq_Int(multiplicand, 0, precision) || XMP_Test_Eq_Int(multiplier, 0, precision)) {
		return(0);
	}

	int total_bit_count = XMP_Count_Bits(multiplier, precision);
	digit high_bit_mask = XMP_Bits_To_Mask(total_bit_count);
	int sub_precision = XMP_Bits_To_Digits(total_bit_count);
	if (!sub_precision) return(0);
	multiplier += sub_precision;

	while (total_bit_count--) {
		XMP_Shift_Left_Bits(prod, 1, precision);

		if ((*(multiplier-1)) & high_bit_mask) {
			XMP_Add(prod, prod, multiplicand, 0, precision);
		}

		high_bit_mask >>= 1;
		if (!high_bit_mask) {
			high_bit_mask = UPPER_MOST_BIT;
			multiplier--;
		}

	}
	return(0);
}


/***********************************************************************************************
 * XMP_Unsigned_Mult_Int -- Multiply an MP number by a simple integer.                         *
 *                                                                                             *
 *    This is a very fast multiply since the multiplier is just an integer integral.           *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the product MP number.                                   *
 *                                                                                             *
 *          multiplicand-- Pointer to the MP number that is the multiplicand.                  *
 *                                                                                             *
 *          multiplier  -- The integral integer that is the multiplier.                        *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers.                                    *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The multiplier must fit in a signed integer (although it isn't a signed value). *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Unsigned_Mult_Int(digit * prod, const digit * multiplicand, short multiplier, int precision)
{
	const unsigned short * m2 = (const unsigned short *)multiplicand;
	unsigned short * pr = (unsigned short *)prod;
	unsigned int carry = 0;
	for (int i = 0; i < precision*2; ++i) {
		unsigned int p = (((unsigned int)multiplier) * *m2) + carry;;
		*pr = (unsigned short) p;
		carry = p >> 16;
		m2++;
		pr++;
	}

	/* Add carry to the next higher word of product / dividend */
//	*pr += (unsigned short)carry;
	return(0);
}


/***********************************************************************************************
 * XMP_Signed_Mult_Int -- Multiply an MP number by a signed simple integer.                    *
 *                                                                                             *
 *    This will multiply the specified integer with the MP number. It is a much faster         *
 *    multiply than when multiplying two MP numbers.                                           *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the product MP number.                                   *
 *                                                                                             *
 *          multiplicand-- Pointer to the MP number that serves as the multiplicand.           *
 *                                                                                             *
 *          multiplier  -- The simple integral integer used as the multiplier.                 *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The multiplier must fist within a signed short integer.                         *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Signed_Mult_Int(digit * prod, const digit * multiplicand, signed short multiplier, int precision)
{
	if (XMP_Is_Negative(multiplicand, precision)) {
		digit abs_multiplicand[MAX_UNIT_PRECISION];
		XMP_Move(abs_multiplicand, multiplicand, precision);
		XMP_Neg(abs_multiplicand, precision);

		if (multiplier < 0) {
			multiplier = (signed short)-multiplier;

			XMP_Unsigned_Mult_Int(prod, abs_multiplicand, multiplier, precision);
		} else {
			XMP_Unsigned_Mult_Int(prod, abs_multiplicand, multiplier, precision);
			XMP_Neg(prod, precision);
		}
	} else {
		if (multiplier < 0) {
			multiplier = (signed short)-multiplier;

			XMP_Unsigned_Mult_Int(prod, multiplicand, multiplier, precision);
			XMP_Neg(prod, precision);
		} else {
			XMP_Unsigned_Mult_Int(prod, multiplicand, multiplier, precision);
		}
	}
	return(0);
}


/***********************************************************************************************
 * XMP_Signed_Mult -- A signed multiply between two MP numbers.                                *
 *                                                                                             *
 *    This routine will perform a multiply between two signed MP numbers.                      *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the product MP number buffer.                            *
 *                                                                                             *
 *          multiplicand-- Pointer to the multiplicand MP number.                              *
 *                                                                                             *
 *          multiplier  -- Pointer to the multiplier MP number.                                *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This is not a very fast routine.                                                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Signed_Mult(digit * prod, const digit * multiplicand, const digit * multiplier, int precision)
{
	if (XMP_Is_Negative(multiplicand, precision)) {
		digit abs_multiplicand[MAX_UNIT_PRECISION];
		XMP_Move(abs_multiplicand, multiplicand, precision);
		XMP_Neg(abs_multiplicand, precision);

		if (XMP_Is_Negative(multiplier, precision)) {
			digit abs_multiplier[MAX_UNIT_PRECISION];
			XMP_Move(abs_multiplier, multiplier, precision);
			XMP_Neg(abs_multiplier, precision);

			XMP_Unsigned_Mult(prod, abs_multiplicand, abs_multiplier, precision);
		} else {
			XMP_Unsigned_Mult(prod, abs_multiplicand, multiplier, precision);
			XMP_Neg(prod, precision);
		}
	} else {
		if (XMP_Is_Negative(multiplier, precision)) {
			digit abs_multiplier[MAX_UNIT_PRECISION];
			XMP_Move(abs_multiplier, multiplier, precision);
			XMP_Neg(abs_multiplier, precision);

			XMP_Unsigned_Mult(prod, multiplicand, abs_multiplier, precision);
			XMP_Neg(prod, precision);
		} else {
			XMP_Unsigned_Mult(prod, multiplicand, multiplier, precision);
		}
	}
	return(0);
}


/***********************************************************************************************
 * XMP_Unsigned_Div_Int -- Perform a short integer divide into an MP number.                   *
 *                                                                                             *
 *    This routine performs a fast divide of the specified MP dividend by a simple             *
 *    short integer. The division is an UNSIGNED division however.                             *
 *                                                                                             *
 * INPUT:   quotient    -- Pointer to the MP number buffer where the quotient will go.         *
 *                                                                                             *
 *          dividend    -- Pointer to the MP number that serves as the dividend.               *
 *                                                                                             *
 *          divisor     -- The simple signed short integer that serves as the divisor.         *
 *                                                                                             *
 *          precision   -- The precision that is used by the MP numbers involved.              *
 *                                                                                             *
 * OUTPUT:  Returns with the remainder of the division.                                        *
 *                                                                                             *
 * WARNINGS:   This is an UNSIGNED divide even.                                                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
unsigned short XMP_Unsigned_Div_Int(digit * quotient, digit const * dividend, unsigned short divisor, int precision)
{
	if (!divisor) return(0);		/* zero divisor means divide error */

	unsigned short remainder = 0;

	XMP_Init(quotient, 0, precision);

	int total_bit_count = XMP_Count_Bits(dividend, precision);
	int digit_precision = XMP_Bits_To_Digits(total_bit_count);
	digit const * dividend_ptr = dividend + (digit_precision-1);

	if (!digit_precision) return(0);

	digit high_bit_mask = XMP_Bits_To_Mask(total_bit_count);
	digit * quotient_ptr = quotient + (digit_precision-1);

	while (total_bit_count--) {
		remainder <<= 1;

		if ((*dividend_ptr) & high_bit_mask) remainder++;

		if (remainder >= divisor) {
			remainder -= divisor;
			*quotient_ptr |= high_bit_mask;
		}

		high_bit_mask >>= 1;
		if (!high_bit_mask) {
			high_bit_mask = UPPER_MOST_BIT;
			--dividend_ptr;
			--quotient_ptr;
		}
	}

	return(remainder);
}


/***********************************************************************************************
 * XMP_Unsigned_Div -- Unsigned divide of one MP number into another.                          *
 *                                                                                             *
 *    This will perform the (dog slow) divide of one MP number into another. Because of the    *
 *    slowness of this routine, both the quotient and the remainder are available as a         *
 *    result of the operation.                                                                 *
 *                                                                                             *
 * INPUT:   remainder   -- Pointer to the MP buffer that will hold the remainder of the divide.*
 *                                                                                             *
 *          quotient    -- Pointer to the MP buffer that will hold the quotient of the divide. *
 *                                                                                             *
 *          dividend    -- The MP dividend (numerator) number.                                 *
 *                                                                                             *
 *          divisor     -- The MP divisor (denominator) number.                                *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This is very slow.                                                              *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Unsigned_Div(digit * remainder, digit * quotient, digit const * dividend, digit const * divisor, int precision)
{
	// check for divide by zero.
	if (XMP_Test_Eq_Int(divisor, 0, precision)) return(-1);

	XMP_Init(remainder, 0, precision);
	XMP_Init(quotient, 0, precision);

	int total_bit_count = XMP_Count_Bits(dividend, precision);
	int digit_precision = XMP_Bits_To_Digits(total_bit_count);
	if (!digit_precision) return(0);

	digit const * dividend_ptr = dividend + (digit_precision-1);
	digit * quotient_ptr = quotient + (digit_precision-1);

	digit high_bit_mask = XMP_Bits_To_Mask(total_bit_count);
	while (total_bit_count--) {
		XMP_Shift_Left_Bits(remainder, 1, precision);

		if (((*dividend_ptr) & high_bit_mask) != 0) {
			XMP_Inc(remainder, precision);
		}

		if (XMP_Compare(remainder, divisor, precision) >= 0) {
			XMP_Sub(remainder, remainder, divisor, 0, precision);
			*quotient_ptr |= high_bit_mask;
		}

		high_bit_mask >>= 1;
		if (!high_bit_mask) {
			high_bit_mask = UPPER_MOST_BIT;
			dividend_ptr--;
			quotient_ptr--;
		}

	}
	return(0);
}


/***********************************************************************************************
 * XMP_Signed_Div -- Signed divide of one MP number into another.                              *
 *                                                                                             *
 *    This will perform a signed divide (very very slow) of one MP number into another.        *
 *    Because of the slow nature of this routine, both the quotient and the remainder are      *
 *    available as results.                                                                    *
 *                                                                                             *
 * INPUT:   remainder   -- Pointer to the buffer that will hold the remainder of the divide.   *
 *                                                                                             *
 *          quotient    -- Pointer to the buffer that will hold the quotient of the divide.    *
 *                                                                                             *
 *          dividend    -- The dividend (numerator) MP number.                                 *
 *                                                                                             *
 *          divisor     -- The divisor (denominator) MP number.                                *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   This is very very slow.                                                         *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Signed_Div(digit * remainder, digit * quotient, digit const * dividend, digit const * divisor, int precision)
{
	bool negative = false;

	digit scratch_dividend[MAX_UNIT_PRECISION];
	XMP_Move(scratch_dividend, dividend, precision);

	digit scratch_divisor[MAX_UNIT_PRECISION];
	XMP_Move(scratch_divisor, divisor, precision);

	if (XMP_Is_Negative(scratch_dividend, precision)) {
		XMP_Neg(scratch_dividend, precision);
		negative = !negative;
	}

	if (XMP_Is_Negative(scratch_divisor, precision)) {
		XMP_Neg(scratch_divisor, precision);
		negative = !negative;
	}

	XMP_Unsigned_Div(remainder, quotient, scratch_dividend, scratch_divisor, precision);

	if (negative) {
		XMP_Neg(quotient, precision);
		if (!XMP_Test_Eq_Int(remainder, 0, precision)) {
			XMP_Dec(quotient, precision);
			XMP_Neg(remainder, precision);
			XMP_Add(remainder, remainder, scratch_divisor, 0, precision);
		}
	}
}


/***********************************************************************************************
 * XMP_Inverse_A_Mod_B -- Inverts and performs modulus on an MP number.                        *
 *                                                                                             *
 *    This is a utility routine that will perform an inverse on the MP number and then         *
 *    perform a modulus of that number by another MP number. There are some algorithms that    *
 *    require this process.                                                                    *
 *                                                                                             *
 * INPUT:   result      -- Pointer to the MP buffer that will hold the result.                 *
 *                                                                                             *
 *          number      -- The MP number that will be inverted then modulo-ized.               *
 *                                                                                             *
 *          modulus     -- The MP number to modulus the first number by.                       *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Inverse_A_Mod_B(digit * result, digit const * number, digit const * modulus, int precision)
{
	digit g[3][MAX_UNIT_PRECISION];
	XMP_Move(g[0], modulus, precision);
	XMP_Move(g[1], number, precision);

	digit v[3][MAX_UNIT_PRECISION];
	XMP_Init(v[0], 0, precision);
	XMP_Init(v[1], 1, precision);

	digit y[MAX_UNIT_PRECISION];

	int i;
	for (i = 1; !XMP_Test_Eq_Int(g[i%3], 0, precision); i++) {
		XMP_Unsigned_Div(g[(i+1)%3], y, g[(i-1)%3], g[i%3], precision);

		XMP_Unsigned_Mult(result, v[i%3], y, precision);
		XMP_Sub(v[(i+1)%3], v[(i-1)%3], result, 0, precision);
	}

	if (XMP_Is_Negative(v[(i-1)%3], precision)) {
		XMP_Add(v[(i-1)%3], v[(i-1)%3], modulus, 0, precision);
	}

	XMP_Move(result, v[(i-1)%3], precision);
}


/***********************************************************************************************
 * XMP_Reciprocal -- Compute the reciprocal (inverse) of the MP number.                        *
 *                                                                                             *
 *    Use this routine to determine the inverse of the specified MP number. The inverse is     *
 *    defined as 1/number.                                                                     *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the result MP number buffer.                                *
 *                                                                                             *
 *          number   -- The number to be inverted.                                             *
 *                                                                                             *
 *          precision-- The precision of the MP number.                                        *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Reciprocal(digit * quotient, const digit * divisor, int precision)
{
	digit remainder[MAX_UNIT_PRECISION];

	if (XMP_Test_Eq_Int(divisor, 0, precision)) return(-1);		/* zero divisor means divide error */

	XMP_Init(remainder, 0, precision);
	XMP_Init(quotient, 0, precision);

	/* normalize and compute number of bits in quotient first */
	unsigned total_bit_count = XMP_Count_Bits(divisor, precision);
	digit high_bit_mask = XMP_Bits_To_Mask(total_bit_count + 1);	/* bitmask within a single digit */
	int sub_precision = XMP_Bits_To_Digits(total_bit_count + 1);

	XMP_Set_Bit(remainder, total_bit_count - 1);

	/* rescale quotient to precision of divisor bits */
	quotient += sub_precision-1;

	while (total_bit_count--) {
		XMP_Shift_Left_Bits(remainder, 1, precision);
		if (XMP_Compare(remainder, divisor, precision) >= 0) {
			XMP_Sub(remainder, remainder, divisor, 0, precision);
			*quotient |= high_bit_mask;
		}

		high_bit_mask >>= 1;
		if (!high_bit_mask) {
			high_bit_mask = UPPER_MOST_BIT;
			quotient--;
		}
	}

	XMP_Init(remainder, 0, precision);
	return(0);
}


/***********************************************************************************************
 * XMP_Decode_ASCII -- Convert ASCII into an MP number.                                        *
 *                                                                                             *
 *    This routine will convert a supplied ASCII string into an MP number.                     *
 *                                                                                             *
 * INPUT:   str      -- Pointer to the ASCII string that will be converted.                    *
 *                                                                                             *
 *          mpn      -- Pointer to the MP number buffer that will be initialized.              *
 *                                                                                             *
 *          precision -- The precision of the MP number.                                       *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Decode_ASCII(char const * str, digit * mpn, int precision)
{
	/*
	**	Initialize the multiprecision number to zero. From this point
	**	onward, this object can be manipulated as a regular number.
	**	This is, in fact, what is done as the ascii string is parsed
	**	into a working number.
	*/
	XMP_Init(mpn, 0, precision);

	/*
	**	No string or zero length is considered '0'.
	*/
	if (!str) return;
	int i = strlen(str);
	if (i == 0) return;

	unsigned short radix;		/* base 2-16 */
	switch (toupper(str[i-1])) {		/* classify radix select suffix character */
		case '.':
			radix = 10;
			break;

		case 'H':
			radix = 16;
			break;

		case 'O':
			radix = 8;
			break;

		case 'B':			/* caution! 'b' is a hex digit! */
			radix = 2;
			break;

		default:
			radix = 10;
			break;
	}

	bool minus = (*str == '-');
	if (minus) str++;

	digit c;
	while ((c = (unsigned char)*str++) != 0) {
		if (c == ',') continue;		/* allow commas in number */

		/*
		**	If not a hexadecimal (highest base) digit then it is
		**	clearly the end of the processable string. Bail out
		**	of the scan loop.
		*/
		if (!isxdigit((char)c)) break;

		/*
		**	Convert the character into an integer number 0 through 15.
		*/
		if (isdigit((char)c)) {
			c -= '0';
		} else {
			c = (unsigned char)(toupper((char)c) - 'A') + 10;
		}

		/*
		**	If the integer digit is greater than the radix, then we
		**	know that further processing should stop. This is the
		**	end of the number string.
		*/
		if (c >= radix) break;		/* scan terminated by any non-digit */


		XMP_Unsigned_Mult_Int(mpn, mpn, radix, precision);
		XMP_Add_Int(mpn, mpn, c, 0, precision);
	}
	if (minus) {
		XMP_Neg(mpn, precision);
	}
}


/***********************************************************************************************
 * XMP_Hybrid_Mul -- Special hybrid short multiply (with carry).                               *
 *                                                                                             *
 *    Multiply the single-word multiplier times the multiprecision integer                     *
 *    in multiplicand, accumulating result in prod.  The resulting                             *
 *    multiprecision prod will be 1 word longer than the multiplicand.                         *
 *    multiplicand is double precision words long.  We add into prod, so caller                *
 *    should zero it out first.  For best results, this time-critical                          *
 *    function should be implemented in assembly.                                              *
 *    NOTE:  Unlike other functions in the multiprecision arithmetic                           *
 *    library, both multiplicand and prod are pointing at the LSB,                             *
 *    regardless of byte order of the machine.  On an 80x86, this makes                        *
 *    no difference.  But if this assembly function is implemented                             *
 *    on a 680x0, it becomes important.                                                        *
 *                                                                                             *
 *    Note that this has been modified from the previous version to allow                      *
 *    better support for Smith's modmult:                                                      *
 *         The final carry bit is added to the existing product                                *
 *         array, rather than simply stored.                                                   *
 *                                                                                             *
 * INPUT:   prod     -- Pointer to the product MP number buffer.                               *
 *                                                                                             *
 *          multiplicand   -- Pointer to the multiplicand MP number.                           *
 *                                                                                             *
 *          multiplier  -- The short integer used as the multiplier.                           *
 *                                                                                             *
 *          precision   -- The precision of the MP number used.                                *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The carry (if any) is added into the integer one beyond the end of the          *
 *             product buffer.                                                                 *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Hybrid_Mul(unsigned short * prod, unsigned short * multiplicand, unsigned short multiplier, int precision)
{
	unsigned int carry = 0;
	for (int i = 0; i < precision; ++i) {
		unsigned int p = (unsigned int)multiplier * *multiplicand++;
		p += *prod + carry;
		*prod++ = (unsigned short) p;
		carry = p >> 16;
	}

	/* Add carry to the next higher word of product / dividend */
	*prod += (unsigned short) carry;
}


/***********************************************************************************************
 * XMP_Double_Mul -- Double precision MP multiply.                                             *
 *                                                                                             *
 *    This will perform a double precision multiply of MP numbers. This means that the product *
 *    will be twice the precision of the components.                                           *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the result buffer. This buffer must be able to hold      *
 *                         double the precision specified.                                     *
 *                                                                                             *
 *          multiplicand-- Pointer to the multiplicand MP number.                              *
 *                                                                                             *
 *          multiplier  -- Pointer to the multiplier number.                                   *
 *                                                                                             *
 *          precision   -- The precision of the two component MP numbers.                      *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Be sure the product buffer can hold a double precision number.                  *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Double_Mul(digit * prod, const digit * multiplicand, const digit * multiplier, int precision)
{
	/*
	**	Clear out the double precision product buffer.
	*/
	XMP_Init(prod, 0, precision*2);

	const unsigned short * multiplier_ptr = (const unsigned short *) multiplier;
	unsigned short * product_ptr = (unsigned short *) prod;

	// Multiply multiplicand by each word in multiplier, accumulating prod.
	for (int i = 0; i < precision*2; ++i) {
		XMP_Hybrid_Mul(product_ptr++, (unsigned short *)multiplicand, *multiplier_ptr++, precision*2);
	}
}



static int _modulus_shift;                      // number of bits for recip scaling
static unsigned short _reciprical_high_digit;   // MSdigit of scaled recip
static unsigned short _reciprical_low_digit;    // LSdigit of scaled recip

static int _modulus_sub_precision;                  // length of modulus in MULTUNITs
static int _modulus_bit_count;                      // number of modulus significant bits
static digit _scratch_modulus[MAX_UNIT_PRECISION];  // modulus

// The double precision modulus staging buffer.
static digit _double_staging_number[MAX_UNIT_PRECISION * 2 + 2];

// most significant digits of modulus.
static digit _mod_quotient[4];
static digit _mod_divisor[4];


/***********************************************************************************************
 * XMP_Prepare_Modulus -- Prepare globals for modulus operation.                               *
 *                                                                                             *
 *    Calculate the reciprocal of modulus with a precision of two MULTUNITs.                   *
 *    Assumes that precision has already been adjusted to the                                  *
 *    size of the modulus, plus SLOP_BITS.                                                     *
 *                                                                                             *
 *    Note: This routine was designed to work with large values and                            *
 *    doesn't have the necessary testing or handling to work with a                            *
 *    modulus having less than three significant digits.  For such cases,                      *
 *    the separate multiply and modulus routines can be used.                                  *
 *                                                                                             *
 * INPUT:   modulus  -- Pointer to the modulus number.                                         *
 *                                                                                             *
 *          precision-- The precision of the modulus number.                                   *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Prepare_Modulus(const digit * n_modulus, int precision)
{
	XMP_Move(_scratch_modulus, n_modulus, precision);

	_modulus_bit_count = XMP_Count_Bits(_scratch_modulus, precision);
	_modulus_sub_precision = (_modulus_bit_count + 16 - 1) / 16;

	/*
	**	Keep 2*16 bits in _mod_divisor.
	**	This will (normally) result in a reciprocal of 2*16+1 bits.
	*/
	int sub_precision = XMP_Significance(_scratch_modulus, precision);	// significant digits in modulus
	XMP_Move(_mod_divisor, &_scratch_modulus[sub_precision-2], 2);
	_modulus_shift = XMP_Count_Bits(_mod_divisor, 2) - 2 * 16;
	XMP_Shift_Right_Bits(_mod_divisor, _modulus_shift, 2);

	XMP_Reciprocal(_mod_quotient, _mod_divisor, 2);
	XMP_Shift_Right_Bits(_mod_quotient, 1, 2);

	/* Reduce to:   0 < _modulus_shift <= 16 */
	_modulus_shift = ((_modulus_shift + (16 - 1)) % 16) + 1;

	/* round up */
	XMP_Inc(_mod_quotient, 2);
	if (XMP_Count_Bits(_mod_quotient, 2) > 2 * 16) {
		XMP_Shift_Right_Bits(_mod_quotient, 1, 2);
		_modulus_shift--;		/* now  0 <= _modulus_shift <= 16 */
	}
	unsigned short * mpm = (unsigned short *) _mod_quotient;
	_reciprical_low_digit = *mpm++;
	_reciprical_high_digit = *mpm;

	return(0);
}


/***********************************************************************************************
 * XMP_Mod_Mult -- Perform a multiply - modulus operation.                                     *
 *                                                                                             *
 *    This routine will combine a multiply and a modulus operation. This takes advantage of    *
 *    a tremendous speed advantage possible if these two processes are combined rather than    *
 *    being performed separately.                                                              *
 *                                                                                             *
 * INPUT:   prod        -- Pointer to the MP buffer that will hold the result.                 *
 *                                                                                             *
 *          multiplicand-- The number to multiply.                                             *
 *                                                                                             *
 *          multiplier  -- The number to multiply by.                                          *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   The modulus must already have been prepared by the routine XMP_Prepare_Modulus. *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int XMP_Mod_Mult(digit * prod, const digit * multiplicand, const digit * multiplier, int precision)
{
	XMP_Double_Mul(_double_staging_number, multiplicand, multiplier, precision);

	int double_precision = precision * 2 + 1;

	_double_staging_number[double_precision - 1] = 0;	/* leading 0 digit */

	/*
	**	We now start working with MULTUNITs.
	**	Determine the most significant MULTUNIT of the product so we don't
	**	have to process leading zeros in our divide loop.
	*/
	int dmi = XMP_Significance(_double_staging_number, double_precision) * 2;	// number of significant MULTUNITs in product

	if (dmi >= _modulus_sub_precision) {

		/* Make dividend negative.  This allows the use of mp_single_mul to
		** "subtract" the product of the modulus and the trial divisor
		**	by actually adding to a negative dividend.
		**	The one's complement of the dividend is used, since it causes
		**	a zero value to be represented as all ones.  This facilitates
		**	testing the result for possible overflow, since a sign bit
		**	indicates that no adjustment is necessary, and we should not
		**	attempt to adjust if the result of the addition is zero.
		*/
		XMP_Inc(_double_staging_number, double_precision);
		XMP_Neg(_double_staging_number, double_precision);

		int nqd = dmi + 1 - _modulus_sub_precision; 	// number of quotient digits remaining to be generated

		/* Set msb, lsb, and normal ptrs of dividend */
		unsigned short * dmph = ((unsigned short *)_double_staging_number) + dmi + 1;	// points to one higher than precision would indicate
		unsigned short * dmpl = dmph - _modulus_sub_precision;

		/*
		**	Divide loop.
		**	Each iteration computes the next quotient MULTUNIT digit, then
		**	multiplies the divisor (modulus) by the quotient digit and adds
		**	it to the one's complement of the dividend (equivalent to
		**	subtracting).  If the product was greater than the remaining dividend,
		**	we get a non-negative result, in which case we subtract off the
		**	modulus to get the proper negative remainder.
		*/
		for (; nqd; nqd--) {
			--dmph;
			--dmpl;

			unsigned short q = mp_quo_digit(dmph);	// trial quotient digit
			if (q > 0) {
				XMP_Hybrid_Mul(dmpl, (unsigned short *)_scratch_modulus, q, precision*2);

				/* Perform correction if q too large.
				**	This rarely occurs.
				*/
				if (!(*dmph & SEMI_UPPER_MOST_BIT)) {
					unsigned short * dmp = dmpl;
					if (XMP_Sub((unsigned int *)dmp, (unsigned int *)dmp, _scratch_modulus, false, precision)) {
						(*dmph)--;
					}
				}
			}
		}

		/* d contains the one's complement of the remainder. */
		XMP_Neg(_double_staging_number, precision);
		XMP_Dec(_double_staging_number, precision);
	}

	XMP_Move(prod, _double_staging_number, precision);
	return(0);
}


/***********************************************************************************************
 * XMP_Mod_Mult_Clear -- Remove temporary values from memory.                                  *
 *                                                                                             *
 *    Smith's mp_modmult function leaves some internal arrays in memory,                       *
 *    so we have to call modmult_burn() at the end of mp_exponent_mod.                         *
 *    This is so that no cryptographically sensitive data is left in memory                    *
 *    after the program exits.                                                                 *
 *                                                                                             *
 * INPUT:   precision   -- The precision of the numbers involved.                              *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
// level-2 1.001: defined in src/ra2/unnamed/TU_5A4120.cpp (one definition per function)
void XMP_Mod_Mult_Clear(int precision);


/*
**	The function mp_quo_digit is the heart of Smith's modulo reduction,
**	which uses a form of long division.  It computes a trial quotient
**	"digit" (MULTUNIT-sized digit) by multiplying the three most
**	significant MULTUNITs of the dividend by the two most significant
**	MULTUNITs of the reciprocal of the modulus.  Note that this function
**	requires that 16 * 2 <= sizeof(unsigned long).
**
**	An important part of this technique is that the quotient never be
**	too small, although it may occasionally be too large.  This was
**	done to eliminate the need to check and correct for a remainder
**	exceeding the divisor.       It is easier to check for a negative
**	remainder.  The following technique rarely needs correction for
**	MULTUNITs of at least 16 bits.
**
**	The following routine has two implementations:
**
**	Parameter: dividend - points to the most significant MULTUNIT
**      of the dividend.  Note that dividend actually contains the
**      one's complement of the actual dividend value (see comments for
**      XMP_Mod_Mult).
**
**	Return: the trial quotient digit resulting from dividing the first
**      three MULTUNITs at dividend by the upper two MULTUNITs of the
**      modulus.
*/

/// <summary>
/// Computes a trial quotient digit for the modulo reduction.
/// </summary>
/// <param name="dividend">Pointer to the most significant unit of the dividend.</param>
/// <returns>Returns with the trial quotient digit.</returns>
unsigned short mp_quo_digit(unsigned short * dividend)
{
	unsigned int q, q0, q1, q2;

	/*
	** Compute the least significant product group.
	** The last terms of q1 and q2 perform upward rounding, which is
	** needed to guarantee that the result not be too small.
	*/
	q1 = (dividend[-2] ^ SEMI_MASK) * (unsigned int) _reciprical_high_digit + _reciprical_high_digit;
	q2 = (dividend[-1] ^ SEMI_MASK) * (unsigned int) _reciprical_low_digit + (1L << 16);
	q0 = (q1 >> 1) + (q2 >> 1) + 1;

	/*      Compute the middle significant product group.   */
	q1 = (dividend[-1] ^ SEMI_MASK) * (unsigned int) _reciprical_high_digit;
	q2 = (dividend[0] ^ SEMI_MASK) * (unsigned int) _reciprical_low_digit;
	q = (q0 >> 16) + (q1 >> 1) + (q2 >> 1) + 1;

	/*      Compute the most significant term and add in the others */
	q = (q >> (16 - 2)) + (((dividend[0] ^ SEMI_MASK) * (unsigned int) _reciprical_high_digit) << 1);
	q >>= _modulus_shift;

	/*      Prevent overflow and then wipe out the intermediate results. */
	return((unsigned short) MIN(q, (unsigned int)(1L << 16) - 1));
}


/*
**	Russian peasant combined exponentiation/modulo algorithm.
**	Calls modmult instead of mult.
**	Computes:  expout = (expin**exponent) mod modulus
**	WARNING: All the arguments must be less than the modulus!
*/

/// <summary>
/// Raises an MP number to a power, modulo another MP number.
/// This routine is the workhorse behind the public key encoding and decoding operations.
/// </summary>
/// <returns>Returns with zero if the result was computed. Otherwise, a negative error code
/// is returned to describe which argument was unusable.</returns>
int xmp_exponent_mod(digit * expout, const digit * expin, const digit * exponent_ptr, const digit * modulus, int precision)
{
	digit product[MAX_UNIT_PRECISION];

	XMP_Init(expout, 1, precision);
	if (XMP_Test_Eq_Int(exponent_ptr, 0, precision)) {
		if (XMP_Test_Eq_Int(expin, 0, precision)) {
			return(-1);		/* 0 to the 0th power means return error */
		}
		return(0);		/* otherwise, zero exponent means expout is 1 */
	}

	if (XMP_Test_Eq_Int(modulus, 0, precision)) {
		return(-2);		/* zero modulus means error */
	}

	if (XMP_Compare(expin, modulus, precision) >= 0) {
		return(-3);		/* if expin >= modulus, return error */
	}

	if (XMP_Compare(exponent_ptr, modulus, precision) >= 0) {
		return(-4);		/* if exponent >= modulus, return error */
	}

	/* set smallest optimum precision for this modulus */
	int limited_precision = XMP_Significance(modulus, precision);

	if (XMP_Prepare_Modulus(modulus, limited_precision)) {
		return(-5);		/* unstageable modulus (STEWART algorithm) */
	}

	/* normalize and compute number of bits in exponent first */
//	int exp_precision = XMP_Significance(exponent_ptr, limited_precision);
//	if (!exp_precision) return(0);
//	int bits = XMP_Digits_To_Bits(exp_precision);
//	exponent_ptr += (exp_precision-1);
//	digit high_bit_mask = UPPER_MOST_BIT;
//	while (! ((*exponent_ptr) & high_bit_mask)) {
//		high_bit_mask >>= 1;
//		bits--;
//	}

	int total_bit_count = XMP_Count_Bits(exponent_ptr, limited_precision);
	int sub_precision = XMP_Bits_To_Digits(total_bit_count);
	if (!sub_precision) return(0);
	digit high_bit_mask = XMP_Bits_To_Mask(total_bit_count);
	exponent_ptr += (sub_precision-1);

	/* We can "optimize out" the first modsquare and modmult: */
	total_bit_count--;			/* We know for sure at this point that bits>0 */

	XMP_Move(expout, expin, limited_precision);

	high_bit_mask >>= 1;
	if (!high_bit_mask) {
		high_bit_mask = UPPER_MOST_BIT;
		exponent_ptr--;
	}

	while (total_bit_count--) {
		XMP_Mod_Mult(product, expout, expout, limited_precision);

		if (((*exponent_ptr) & high_bit_mask)) {
			XMP_Mod_Mult(expout, product, expin, limited_precision);
		} else {
			XMP_Move(expout, product, limited_precision);
		}

		high_bit_mask >>= 1;
		if (!high_bit_mask) {
			high_bit_mask = UPPER_MOST_BIT;
			exponent_ptr--;
		}

	}

	XMP_Init(product, 0, limited_precision);
	XMP_Mod_Mult_Clear(limited_precision);		/* ask mp_modmult to also burn its own evidence */

	return(0);
}


/***********************************************************************************************
 * memrev -- Reverse the byte order of the buffer specified.                                   *
 *                                                                                             *
 *    This routine will reverse the byte order in the buffer specified.                        *
 *                                                                                             *
 * INPUT:   buffer   -- Pointer to the buffer that will be reversed.                           *
 *                                                                                             *
 *          length   -- The length of the buffer.                                              *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
// level-2 1.001: defined in src/ra2/unnamed/TU_5A4120.cpp (one definition per function)
void memrev(char * buffer, size_t length);





/***********************************************************************************************
 * XMP_Is_Small_Prime -- Determine if MP number is a small prime.                              *
 *                                                                                             *
 *    This routine will compare the MP number against all known small prime numbers. It will   *
 *    return true if a match was found.                                                        *
 *                                                                                             *
 * INPUT:   candidate   -- Pointer to MP number that is to be tested.                          *
 *                                                                                             *
 *          precision   -- The precision of the MP number specified.                           *
 *                                                                                             *
 * OUTPUT:  bool; Was the MP number a member of the small prime community?                     *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Is_Small_Prime(const digit * candidate, int precision)
{
	/*
	**	If the number is too large for comparison to the known small primes table, then
	**	bail immediately.
	*/
	if (XMP_Significance(candidate, precision) > 1) return(false);
	if (*candidate > primeTable[ARRAY_SIZE(primeTable)-1]) return(false);

	unsigned short * ptr = Binary_Search(&primeTable[0], ARRAY_SIZE(primeTable), (unsigned short)*candidate);
	return(ptr != NULL);
}


/***********************************************************************************************
 * XMP_Small_Divisors_Test -- Perform the small divisors test on an MP number.                 *
 *                                                                                             *
 *    This test for primality will divide an MP number by the set of small primes. If any of   *
 *    these numbers divides evenly into the candidate number, then it is known that the        *
 *    candidate is NOT prime.                                                                  *
 *                                                                                             *
 * INPUT:   candidate   -- Pointer to the MP number that is to be tested.                      *
 *                                                                                             *
 *          precision   -- The precision of the MP number/                                     *
 *                                                                                             *
 * OUTPUT:  bool; Did the MP number pass the small divisors test?                              *
 *                                                                                             *
 * WARNINGS:   If the MP number passes, it doesn't mean that it is prime, just that is hasn't  *
 *             yet been proven to be not prime.                                                *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Small_Divisors_Test(const digit * candidate, int precision)
{
	digit quotient[MAX_UNIT_PRECISION];

	for (const unsigned short * ptr = primeTable; ptr < &primeTable[ARRAY_SIZE(primeTable)]; ptr++) {	// RA2
		if (XMP_Unsigned_Div_Int(quotient, candidate, *ptr, precision) == 0) return(false);
	}
	return(true);
}


/***********************************************************************************************
 * XMP_Fermat_Test -- Performs Fermat's Little Theorem on an MP number.                        *
 *                                                                                             *
 *    This is a more expensive but thorough test for primality. The aggressiveness of this     *
 *    test can be controlled by the number of rounds specified. Four rounds is usually         *
 *    sufficient.                                                                              *
 *                                                                                             *
 * INPUT:   candidate   -- Pointer to the candidate MP number that is to be tested.            *
 *                                                                                             *
 *          rounds      -- The number of rounds to test the MP number (keep it small).         *
 *                                                                                             *
 *          precision   -- The precision of the MP number.                                     *
 *                                                                                             *
 * OUTPUT:  bool; Was the number not proven to be not prime. A FALSE means that it is not      *
 *                prime. A TRUE means that it might be prime.                                  *
 *                                                                                             *
 * WARNINGS:   This takes a bit of time. The time it takes is directly controlled by the       *
 *             number of rounds specified. Keep the number of rounds as small as possible.     *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
// RA2: XMP_Is_Prime runs the Fermat witnesses over a range of the prime table.
static inline bool Fermat_Test(const digit * candidate_prime, const unsigned short * first, const unsigned short * last, int precision)
{
	digit term[MAX_UNIT_PRECISION];
	XMP_Move(term, candidate_prime, precision);
	XMP_Dec(term, precision);

	for (const unsigned short * ptr = first; ptr < last; ptr++) {
		// if ((x**(p-1)) mod p) != 1, then p is not prime
		digit result[MAX_UNIT_PRECISION];

		digit small_prime[MAX_UNIT_PRECISION];
		XMP_Init(small_prime, *ptr, precision);

		xmp_exponent_mod(result, small_prime, term, candidate_prime, precision);

		if (!XMP_Test_Eq_Int(result, 1, precision)) return(false);
	}
	return(true);
}

bool XMP_Fermat_Test(const digit * candidate_prime, unsigned rounds, int precision)
{
	assert(rounds < ARRAY_SIZE(primeTable));

	digit term[MAX_UNIT_PRECISION];
	XMP_Move(term, candidate_prime, precision);
	XMP_Dec(term, precision);

	for (unsigned i = 0; i < rounds; i++) {
		// if ((x**(p-1)) mod p) != 1, then p is not prime
		digit result[MAX_UNIT_PRECISION];

		digit small_prime[MAX_UNIT_PRECISION];
		XMP_Init(small_prime, primeTable[i], precision);

		xmp_exponent_mod(result, small_prime, term, candidate_prime, precision);

		if (!XMP_Test_Eq_Int(result, 1, precision)) return(false);
	}
	return(true);
}


/***********************************************************************************************
 * XMP_Rabin_Miller_Test -- Performs the Rabin Miller test for primality.                      *
 *                                                                                             *
 *    This test for primality is even more expensive the Fermat's Little Theorem. It doesn't   *
 *    prove that a number is prime, but it can prove that it is not prime.                     *
 *                                                                                             *
 * INPUT:   rng      -- Reference to to a random number generator.                             *
 *                                                                                             *
 *          candidate-- Pointer to the candidate MP number that is to be tested.               *
 *                                                                                             *
 *          rounds   -- The number of test rounds to perform.                                  *
 *                                                                                             *
 *          precision-- The precision of the MP number specified.                              *
 *                                                                                             *
 * OUTPUT:  bool; Was the number not proven to be not prime? A FALSE means that the number is  *
 *          not prime. A TRUE means that it might be.                                          *
 *                                                                                             *
 * WARNINGS:   This routine takes a long time. Use as few rounds as possible.                  *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Rabin_Miller_Test(Straw & rng, digit const * w, int rounds, int precision)
{
	digit wminus1[MAX_UNIT_PRECISION];
	XMP_Sub_Int(wminus1, w, 1, 0, precision);

	unsigned maxbitprecision = precision * sizeof(digit) * 8;
	unsigned a;
	for (a = 0; a < maxbitprecision; a++) {
		if (XMP_Test_Bit(wminus1, a)) {
			break;
		}
	}

	digit m[MAX_UNIT_PRECISION];
	XMP_Move(m, wminus1, precision);
	XMP_Shift_Right_Bits(wminus1, a, precision);

	for (int i = 0; i < rounds; i++) {
		digit b[MAX_UNIT_PRECISION];
		digit temp[MAX_UNIT_PRECISION];
		XMP_Init(temp, 2, precision);
		XMP_Randomize(b, rng, temp, wminus1, precision);

		digit z[MAX_UNIT_PRECISION];
		xmp_exponent_mod(z, b, m, w, precision);

		if (XMP_Test_Eq_Int(z, 1, precision) || XMP_Compare(z, wminus1, precision) == 0) {
			continue;   // passes this round
		}

		unsigned j;
		for (j = 1; j < a; j++) {
			digit t2[MAX_UNIT_PRECISION];
			xmp_exponent_mod(t2, z, temp, w, precision);

			if (XMP_Compare(t2, wminus1, precision) == 0) {
				break;  // passed this round
			}
			if (XMP_Test_Eq_Int(z, 1, precision)) {
				return(false);
			}
		}
		if (j == a) {
			return(false);
		}
	}
	return(true);
}


/***********************************************************************************************
 * XMP_Randomize -- Generate a random MP number.                                               *
 *                                                                                             *
 *    This routine will generate a random MP number with the number of bits precision          *
 *    specified. This is the starting point for generating large random prime numbers. It is   *
 *    very important that the random number generated is truly random.                         *
 *                                                                                             *
 * INPUT:   result   -- Pointer to the buffer that will hold the MP number.                    *
 *                                                                                             *
 *          rng      -- Reference to a random number generator.                                *
 *                                                                                             *
 *          total_bits-- The number of bits precision that the MP number must have.            *
 *                                                                                             *
 *          precision-- The precision of the MP number to be generated (maximum)               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Randomize(digit * result, Straw & rng, int total_bits, int precision)
{
	assert(XMP_Bits_To_Digits(total_bits) <= MAX_UNIT_PRECISION);

	total_bits = MIN(total_bits, precision * 32);

	unsigned nbytes = total_bits/8 + 1;

	XMP_Init(result, 0, precision);
	rng.Get(result, nbytes);

	((unsigned char *)result)[nbytes-1] &= (unsigned char)(~((~0) << (total_bits % 8)));
}


/***********************************************************************************************
 * XMP_Randomize -- Generate a random MP number between the boundaries specified.              *
 *                                                                                             *
 *    This routine will generate a random MP number but it will be bounded by the minimum      *
 *    and maximum MP numbers specified.                                                        *
 *                                                                                             *
 * INPUT:   result      -- Pointer to the MP buffer that will hold the result.                 *
 *                                                                                             *
 *          rng         -- Reference to a random number generator to use.                      *
 *                                                                                             *
 *          minval      -- Minimum value allowed.                                              *
 *                                                                                             *
 *          maxval      -- Maximum value allowed.                                              *
 *                                                                                             *
 *          precision   -- The precision of the MP numbers involved.                           *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void XMP_Randomize(digit * result, Straw & rng, digit const * minval, digit const * maxval, int precision)
{
	digit range[MAX_UNIT_PRECISION];
	XMP_Sub(range, maxval, minval, 0, precision);
	unsigned int bit_count = XMP_Count_Bits(range, precision);
	do	{
		XMP_Randomize(result, rng, bit_count, precision);
	} while (XMP_Compare(result, range, precision) > 0);

	XMP_Add(result, result, minval, 0, precision);
}


/***********************************************************************************************
 * XMP_Is_Prime -- Determine if the specified MP number is prime.                              *
 *                                                                                             *
 *    This routine will perform some checks to try and determine if the specified MP number    *
 *    is a prime number. The result of this test is not 100% conclusive, but it is pretty      *
 *    darn close.                                                                              *
 *                                                                                             *
 * INPUT:   prime    -- Pointer to a candidate number to test for primality.                   *
 *                                                                                             *
 *          precision-- The precision of the MP number specified.                              *
 *                                                                                             *
 * OUTPUT:  bool; Was the number not proven to be not prime? If FALSE, then the number is      *
 *          not prime. If TRUE, then it might be.                                              *
 *                                                                                             *
 * WARNINGS:   This can take a very very very very very long time. Especially for the larger   *
 *             numbers.                                                                        *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/02/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
bool XMP_Is_Prime(digit const * prime, int precision)
{
	/*
	**	Even numbers are ALWAYS not prime.
	*/
	if (!(*prime & 0x01)) return(false);

	/*
	**	Compare the prime number against the exhaustive list of prime
	**	numbers below 14 bits in size. If it finds a match, then
	**	the number is a known prime.
	*/
	if (XMP_Is_Small_Prime(prime, precision)) return(true);

	/*
	**	Perform the small divisors test. This is not exhaustive, but
	**	will weed out a large percentage of non-prime numbers.
	*/
	if (!XMP_Small_Divisors_Test(prime, precision)) return(false);

	/*
	**	Perform Fermat's Little Theorum on the candidate prime. Run
	**	the theorum for several rounds to ensure a high degree of
	**	confidence.
	*/
	if (!Fermat_Test(prime, primeTable, &primeTable[2], precision)) return(false);	// RA2

	/*
	**	If all of the above tests have not confirmed primality nor
	**	confirmed non-primality, presume that the number must be prime.
	*/
	return(true);
}


/*
**	Complete list of all prime numbers that are less than 32719 (inclusive).
*/
// level-2 1.001: defined in src/ra2/unnamed/TU_5A4120.cpp (one definition per function)
