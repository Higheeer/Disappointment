//
// Created by Eryk on 22.10.2020.
//

#ifndef SIMPLERPG_SRC_CONSTANTS_H_
#define SIMPLERPG_SRC_CONSTANTS_H_

float constexpr CHUNK_SIZE = 256;
float constexpr BLOCK_SIZE = 32;

int constexpr BLOCKS_PER_CHUNK = (CHUNK_SIZE / BLOCK_SIZE) * (CHUNK_SIZE / BLOCK_SIZE);

#endif //SIMPLERPG_SRC_CONSTANTS_H_
