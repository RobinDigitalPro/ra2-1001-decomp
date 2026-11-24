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
 *                     $Archive:: /Commando/Library/PKSTRAW.CPP                               $*
 *                                                                                             *
 *                      $Author:: Greg_h                                                      $*
 *                                                                                             *
 *                     $Modtime:: 7/22/97 11:37a                                              $*
 *                                                                                             *
 *                    $Revision:: 1                                                           $*
 *                                                                                             *
 *---------------------------------------------------------------------------------------------*
 * Functions:                                                                                  *
 *   PKStraw::Encrypted_Key_Length -- Fetch the encrypted key length.                          *
 *   PKStraw::Get -- Fetch data and process it accordingly.                                    *
 *   PKStraw::Get_From -- Chains one straw to another.                                         *
 *   PKStraw::Key -- Assign a key to the cipher process straw.                                 *
 *   PKStraw::PKStraw -- Initialize the public key straw object.                               *
 *   PKStraw::Plain_Key_Length -- Returns the number of bytes to encrypt key.                  *
 * - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

#include "always.h"

#include "pkstraw.h"

#include "blwstraw.h"
#include "rndstraw.h"

#include <cstring>


/***********************************************************************************************
 * PKStraw::PKStraw -- Initialize the public key straw object.                                 *
 *                                                                                             *
 *    This constructs the public key straw object. The operation to perform (encrypt or        *
 *    decrypt) as well as a random number generator must be provided.                          *
 *                                                                                             *
 * INPUT:   control  -- What operation to perform on the data. Pass in either ENCRYPT or       *
 *                      DECRYPT.                                                               *
 *                                                                                             *
 *          rnd      -- Reference to a random number straw that is used internally to          *
 *                      generate the sub-key. The final strength of the cipher depends on      *
 *                      quality of this random number generator.                               *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/11/1996 JLB : Created.                                                                 *
 *=============================================================================================*/



/***********************************************************************************************
 * PKStraw::Get_From -- Chains one straw to another.                                           *
 *                                                                                             *
 *    This routine handles the special case of this straw object in that there is an           *
 *    embedded blowfish straw segment. It must be chained on correctly.                        *
 *                                                                                             *
 * INPUT:   straw -- Pointer to the straw segment that this segment is to receive data from.   *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/11/1996 JLB : Created.                                                                 *
 *=============================================================================================*/



/***********************************************************************************************
 * PKStraw::Key -- Assign a key to the cipher process straw.                                   *
 *                                                                                             *
 *    This routine will assign the key (or NULL if the current key is to be removed) to the    *
 *    cipher stream process. When a key has been assigned, encryption or decryption will       *
 *    take place. In the absence (NULL key pointer) of a key, the data passes through          *
 *    unchanged.                                                                               *
 *                                                                                             *
 * INPUT:   key   -- Pointer to the key to assign to the stream. If the key pointer is NULL,   *
 *                   then this causes the cipher stream to stop processing the data and will   *
 *                   pass the data through unchanged.                                          *
 *                                                                                             *
 * OUTPUT:  none                                                                               *
 *                                                                                             *
 * WARNINGS:   Be sure that the key passed to this routine is the opposite key to that used    *
 *             to process the stream originally (when decrypting).                             *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/08/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
void PKStraw::Key(PKey const * key)
{
	CipherKey = key;
	if (key != NULL) {
		IsGettingKey = true;
	}
	Counter = 0;
	BytesLeft = 0;
}


/***********************************************************************************************
 * PKStraw::Get -- Fetch data and process it accordingly.                                      *
 *                                                                                             *
 *    This routine will fetch the number of bytes requested. If a valid key has been assigned  *
 *    to this stream, then the data will be processed as it passes through.                    *
 *                                                                                             *
 * INPUT:   source   -- Pointer to the buffer that will hold the requested data.               *
 *                                                                                             *
 *          length   -- The number of data bytes requested.                                    *
 *                                                                                             *
 * OUTPUT:  Returns with the actual number of data bytes stored to the destination buffer. If  *
 *          this number is less than that requested, then it indicates that the data source    *
 *          has been exhausted.                                                                *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/08/1996 JLB : Created.                                                                 *
 *=============================================================================================*/



/***********************************************************************************************
 * PKStraw::Encrypted_Key_Length -- Fetch the encrypted key length.                            *
 *                                                                                             *
 *    This returns the total number of bytes (after encryption) that the blowfish key will     *
 *    consume. It should be possible to get a block of this size, then pass it to the          *
 *    public key decrypter and the result will be the full blowfish key.                       *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the number of bytes that the encrypted blowfish key required.         *
 *                                                                                             *
 * WARNINGS:   none                                                                            *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/11/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int PKStraw::Encrypted_Key_Length(void) const
{
	if (CipherKey == NULL) return(0);
	return(CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Crypt_Block_Size());
}


/***********************************************************************************************
 * PKStraw::Plain_Key_Length -- Returns the number of bytes to encrypt key.                    *
 *                                                                                             *
 *    This is the number of plain (unencrypted) bytes that the blowfish key will take up. This *
 *    is actually the number of plain blocks minimum that can contain the full blowfish        *
 *    key. The public key cryptography system encrypts in whole blocks only.                   *
 *                                                                                             *
 * INPUT:   none                                                                               *
 *                                                                                             *
 * OUTPUT:  Returns with the total number of bytes that will contain the full blowfish key     *
 *          and still be an even block size for the public key cryptography process.           *
 *                                                                                             *
 * WARNINGS:   This value is probably be larger than the actual blowfish key length.           *
 *                                                                                             *
 * HISTORY:                                                                                    *
 *   07/11/1996 JLB : Created.                                                                 *
 *=============================================================================================*/
int PKStraw::Plain_Key_Length(void) const
{
	if (CipherKey == NULL) return(0);
	return(CipherKey->Block_Count(BLOWFISH_KEY_SIZE) * CipherKey->Plain_Block_Size());
}
