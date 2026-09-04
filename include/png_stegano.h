#ifndef PNGSTEGANO_H
#define PNGSTEGANO_H

int cacher_texte_png(const char *input_path, const char *output_path, const char *secret);
int extraire_texte_png(const char *input_path);

#endif