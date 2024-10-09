#include <tap.h>
#include <jsnc/compiler/source_memory.h>

void test_source_memory(void) {
  struct jsnc_source *source;
  char src_[11];

  jsnc_source_memory_create(&source, "<mem_source>", "const a=2;");

  diag("jsnc_source_memory_create()");

  ok(source != NULL, "source is not null");
  ok(source->bytepos == 0, "source bytepos is 0");
  ok(source->charpos == 0, "source charpos is 0");
  is(source->name, "<mem_source>", "source name is <mem_source>");
  cmp_ok(ftell(source->fp), "==", 0, "source file pointer position is at 0");
  fread(src_, sizeof(char), 10, source->fp);
  src_[10] = '\0';
  is(src_, "const a=2;", "source content matches with const a=2;");
}
