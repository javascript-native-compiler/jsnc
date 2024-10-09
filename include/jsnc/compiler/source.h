#ifndef JSNC_SOURCE_H
#define JSNC_SOURCE_H
#include <stdint.h>

struct jsnc_source {
  /* source name */
  const char *name;
  /* holds byte position */
  uint64_t bytepos;
  /* holds char position */
  uint64_t charpos;
  /* holds file pointer */
  FILE *fp;
};

void jsnc_source_close(struct jsnc_source *source);

#endif
