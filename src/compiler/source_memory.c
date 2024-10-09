#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include <jsnc/compiler/source_memory.h>

void jsnc_source_memory_create(struct jsnc_source **dest_source, \
    const char *source_name, const char *source) {
  struct jsnc_source *source_;
  FILE *fp_;

  source_ = (struct jsnc_source*)malloc(sizeof(struct jsnc_source));
  assert(source_ != NULL && "unable to allocate memory for memory source");

  fp_ = fmemopen((void*)source, strlen(source), "rb");
  assert(fp_ != NULL && "unable to open memory file");

  /* initialize the source */
  source_->bytepos = 0;
  source_->charpos = 0;
  source_->name = source_name;
  source_->fp = fp_;

  *dest_source = source_;
}
