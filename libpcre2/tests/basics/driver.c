#include <pcre2.h>

#if PCRE2_CODE_UNIT_WIDTH == 8

static PCRE2_SPTR patt = (PCRE2_SPTR)"^foo.+";
static PCRE2_SPTR text = (PCRE2_SPTR)"foobar";

#elif PCRE2_CODE_UNIT_WIDTH == 16

static PCRE2_SPTR patt = (PCRE2_SPTR)u"^foo.+";
static PCRE2_SPTR text = (PCRE2_SPTR)u"foobar";

#elif PCRE2_CODE_UNIT_WIDTH == 32

static PCRE2_SPTR patt = (PCRE2_SPTR)U"^foo.+";
static PCRE2_SPTR text = (PCRE2_SPTR)U"foobar";

#endif

int
main ()
{
  PCRE2_SIZE eo; // Error offset.
  int en;        // Error number.
  pcre2_code* re =
      pcre2_compile (patt, PCRE2_ZERO_TERMINATED, 0, &en, &eo, NULL);
  pcre2_match_data* md = pcre2_match_data_create_from_pattern (re, NULL);

  int r = pcre2_match (re, text, PCRE2_ZERO_TERMINATED, 0, 0, md, NULL);

  return r == 1 ? 0 : r;
}
