/* ====================================================================
 * Copyright (c) 1995-2000 Carnegie Mellon University.  All rights 
 * reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer. 
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * This work was supported in part by funding from the Defense Advanced 
 * Research Projects Agency and the National Science Foundation of the 
 * United States of America, and the CMU Sphinx Speech Consortium.
 *
 * THIS SOFTWARE IS PROVIDED BY CARNEGIE MELLON UNIVERSITY ``AS IS'' AND 
 * ANY EXPRESSED OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, 
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL CARNEGIE MELLON UNIVERSITY
 * NOR ITS EMPLOYEES BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, 
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY 
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ====================================================================
 *
 */
/*********************************************************************
 *
 * File: lexicon.h
 * 
 * Traceability: 
 * 
 * Description: 
 * 
 * Author: 
 * 	$Author$
 *********************************************************************/

#ifndef LEXICON_H
#define LEXICON_H
#ifdef __cplusplus
extern "C" {
#endif
#if 0
}
#endif

#include <s3/acmod_set.h>
#include <s3/hash.h>
#include <s3/prim_type.h>
#include <s3/lts.h>

typedef uint32 word_id_t;
#define WORD_NO_ID	(0xffffffff)

typedef struct lex_entry_str {
    char *ortho;
    word_id_t word_id;
    char **phone;
    acmod_id_t *ci_acmod_id;
    uint32  phone_cnt;

    struct lex_entry_str *next;
} lex_entry_t;

typedef struct lexicon_s {
/*    lex_entry_t *entry; */

    lex_entry_t *head;
    lex_entry_t *tail;

    uint32 entry_cnt;
    hash_t ht;
    lts_t *lts_rules;
    acmod_set_t *phone_set;
} lexicon_t;

lexicon_t *lexicon_new(void);

lexicon_t *
lexicon_read(lexicon_t *prior_lex,
	     const char *lex_file_name,
	     acmod_set_t *phone_set);

lex_entry_t *
lexicon_lookup(lexicon_t *lexicon,
	       char *word);

#ifdef __cplusplus
}
#endif
#endif /* LEXICON_H */ 


/*
 * Log record.  Maintained by RCS.
 *
 * $Log$
 * Revision 1.5  2005/09/15  19:36:01  dhdfu
 * Add (as yet untested) support for letter-to-sound rules (from CMU
 * Flite) when constructing sentence HMMs in Baum-Welch.  Currently only
 * rules for CMUdict exist.  Of course this is not a substitute for
 * actually checking pronunciations...
 * 
 * Revision 1.4  2004/07/21 17:46:09  egouvea
 * Changed the license terms to make it the same as sphinx2 and sphinx3.
 *
 * Revision 1.3  2001/04/05 20:02:30  awb
 * *** empty log message ***
 *
 * Revision 1.2  2000/09/29 22:35:12  awb
 * *** empty log message ***
 *
 * Revision 1.1  2000/09/24 21:38:30  awb
 * *** empty log message ***
 *
 * Revision 1.4  1996/07/29  16:40:50  eht
 * make a name more consise
 *
 * Revision 1.3  1995/10/09  20:55:35  eht
 * Changes needed for prim_type.h
 *
 * Revision 1.2  1995/09/08  19:13:52  eht
 * Updated to remove references to pset module and add references
 * to acmod_set module
 *
 * Revision 1.1  1995/08/15  13:44:14  eht
 * Initial revision
 *
 *
 */
