/*
 * Copyright (C) 2006-2010 Vincent Hanquez <vincent@snarc.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef CRYPTOHASH_SKEIN256_H
#define CRYPTOHASH_SKEIN256_H

#include <stdint.h>

struct skein256_ctx
{
	uint32_t hashlen;
	uint32_t bufindex;
	uint8_t  buf[64];
	uint64_t h[8];
	uint64_t t0;
	uint64_t t1;
};

#define SKEIN256_CTX_SIZE		sizeof(struct skein256_ctx)

void skein256_init(struct skein256_ctx *ctx, uint32_t hashlen);
void skein256_update(struct skein256_ctx *ctx, uint8_t *data, uint32_t len);
void skein256_finalize(struct skein256_ctx *ctx, uint8_t *out);

#endif
