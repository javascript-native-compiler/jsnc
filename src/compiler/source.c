#include <stdio.h>
#include <jsnc/compiler/source.h>

void jsnc_source_close(struct jsnc_source *source) {
  assert(source != NULL, "unable to close source, source is not initialized");

  fclose(source->fp);
}
