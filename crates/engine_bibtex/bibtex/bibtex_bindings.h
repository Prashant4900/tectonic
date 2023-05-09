#ifndef BIBTEX_BINDINGS_H
#define BIBTEX_BINDINGS_H

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
  HISTORY_SPOTLESS = 0,
  HISTORY_WARNING_ISSUED = 1,
  HISTORY_ERROR_ISSUED = 2,
  HISTORY_FATAL_ERROR = 3,
  HISTORY_ABORTED = 4,
} History;

typedef uint8_t ASCIICode;

typedef int32_t PoolPointer;

typedef int32_t StrNumber;

typedef ASCIICode *BufType;

typedef int32_t BufPointer;

typedef int32_t CiteNumber;

typedef struct {
  int min_crossrefs;
} BibtexConfig;

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

bool str_ends_with(ASCIICode *str_pool, PoolPointer *str_start, StrNumber s, StrNumber ext);

bool bib_str_eq_buf(ASCIICode *str_pool,
                    PoolPointer *str_start,
                    StrNumber s,
                    BufType buf,
                    BufPointer bf_ptr,
                    BufPointer len);

bool bib_str_eq_str(ASCIICode *str_pool, PoolPointer *str_start, StrNumber s1, StrNumber s2);

void lower_case(BufType buf, BufPointer bf_ptr, BufPointer len);

void upper_case(BufType buf, BufPointer bf_ptr, BufPointer len);

/**
 * # Safety
 *
 * Passed pointer must point to a valid array that we have exclusive access to for the duration
 * of this call, that is at least as long as `right_end`, and initialized for the range
 * `ptr[left_end..right_end]`
 */
void quick_sort(StrNumber *cite_info, CiteNumber left_end, CiteNumber right_end);

extern History tt_engine_bibtex_main(ttbc_state_t *api,
                                     const BibtexConfig *cfg,
                                     const char *aux_name);

extern void *xrealloc(void *ptr, size_t size);

#ifdef __cplusplus
} // extern "C"
#endif // __cplusplus

#endif /* BIBTEX_BINDINGS_H */
