#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <jsnc/compiler/source_memory.h>

void jsnc_source_memory_create(struct jsnc_source *dest_source, \
    const char *source_name, const char *source) {
  FILE *fp_;

  fp_ = fmemopen((void*)source, strlen(source), "rb");
  assert(fp_ != NULL && "unable to open memory file");

  /* initialize the source */
  dest_source->bytepos = 0;
  dest_source->charpos = 0;
  dest_source->name = source_name;
  dest_source->fp = fp_;
}
