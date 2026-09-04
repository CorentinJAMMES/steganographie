#ifndef STEGANO_H
#define STEGANO_H

#include <stdio.h>

int cacher_texte_bmp(const char *input_path, const char *output_path, const char *secret);
int extraire_texte_bmp(const char *input_path);

#endif