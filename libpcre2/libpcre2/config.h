// See ../../upstream/src/config.h.in.generic for more information and a list
// of macros we're leaving at their default values (by not setting them
// explicitly here).
//

// Boolean macros such as HAVE_STDLIB_H and SUPPORT_PCRE2_8 should either be
// defined (conventionally to 1) for TRUE, and not defined at all for
// FALSE. All such macros are listed as a commented #undef in
// config.h.generic. Macros such as MATCH_LIMIT, whose actual value is
// relevant, have defaults defined, but are surrounded by #ifndef/#endif lines
// so that the value can be overridden by -D.

// Define to any value to enable support for Just-In-Time compiling.
//
#define SUPPORT_JIT 1

// Define to any value to enable support for Unicode and UTF encoding. This
// will work even in an EBCDIC environment, but it is incompatible with the
// EBCDIC macro. That is, PCRE2 can support *either* EBCDIC code *or*
// ASCII/Unicode, but not both at once.
//
#define SUPPORT_UNICODE 1

// Define to 1 if you have the `memmove' function.
//
#define HAVE_MEMMOVE 1

// Define to 1 if you have the `memfd_create' function.
//
#if defined(__linux__) || defined(__FreeBSD__)
#define HAVE_MEMFD_CREATE 1
#endif

// This limits the amount of memory that may be used while matching a pattern.
// It applies to both pcre2_match() and pcre2_dfa_match(). It does not apply
// to JIT matching. The value is in kibibytes (units of 1024 bytes).
//
#ifndef HEAP_LIMIT
#define HEAP_LIMIT 20000000
#endif

// The value of LINK_SIZE determines the number of bytes used to store links
// as offsets within the compiled regex. The default is 2, which allows for
// compiled patterns up to 65535 code units long. This covers the vast
// majority of cases. However, PCRE2 can also be compiled to use 3 or 4 bytes
// instead. This allows for longer patterns in extreme cases.
//
#ifndef LINK_SIZE
#define LINK_SIZE 2
#endif

// The value of MATCH_LIMIT determines the default number of times the
// pcre2_match() function can record a backtrack position during a single
// matching attempt. The value is also used to limit a loop counter in
// pcre2_dfa_match(). There is a runtime interface for setting a different
// limit. The limit exists in order to catch runaway regular expressions that
// take for ever to determine that they do not match. The default is set very
// large so that it does not accidentally catch legitimate cases.
//
#ifndef MATCH_LIMIT
#define MATCH_LIMIT 10000000
#endif

// The above limit applies to all backtracks, whether or not they are nested.
// In some environments it is desirable to limit the nesting of backtracking
// (that is, the depth of tree that is searched) more strictly, in order to
// restrict the maximum amount of heap memory that is used. The value of
// MATCH_LIMIT_DEPTH provides this facility. To have any useful effect, it
// must be less than the value of MATCH_LIMIT. The default is to use the same
// value as MATCH_LIMIT. There is a runtime method for setting a different
// limit. In the case of pcre2_dfa_match(), this limit controls the depth of
// the internal nested function calls that are used for pattern recursions,
// lookarounds, and atomic groups.
//
#ifndef MATCH_LIMIT_DEPTH
#define MATCH_LIMIT_DEPTH MATCH_LIMIT
#endif

// This limit is parameterized just in case anybody ever wants to change it.
// Care must be taken if it is increased, because it guards against integer
// overflow caused by enormously large patterns.
//
#ifndef MAX_NAME_COUNT
#define MAX_NAME_COUNT 10000
#endif

// This limit is parameterized just in case anybody ever wants to change it.
// Care must be taken if it is increased, because it guards against integer
// overflow caused by enormously large patterns.
//
#ifndef MAX_NAME_SIZE
#define MAX_NAME_SIZE 32
#endif

// The value of NEWLINE_DEFAULT determines the default newline character
// sequence. PCRE2 client programs can override this by selecting other values
// at run time. The valid values are 1 (CR), 2 (LF), 3 (CRLF), 4 (ANY), 5
// (ANYCRLF), and 6 (NUL).
//
#ifndef NEWLINE_DEFAULT
#define NEWLINE_DEFAULT 2
#endif

// The value of PARENS_NEST_LIMIT specifies the maximum depth of nested
// parentheses (of any kind) in a pattern. This limits the amount of system
// stack that is used while compiling a pattern.
//
#ifndef PARENS_NEST_LIMIT
#define PARENS_NEST_LIMIT 250
#endif

// The value of PCRE2GREP_BUFSIZE is the starting size of the buffer used by
// pcre2grep to hold parts of the file it is searching. The buffer will be
// expanded up to PCRE2GREP_MAX_BUFSIZE if necessary, for files containing
// very long lines. The actual amount of memory used by pcre2grep is three
// times this number, because it allows for the buffering of "before" and
// "after" lines.
//
#ifndef PCRE2GREP_BUFSIZE
#define PCRE2GREP_BUFSIZE 20480
#endif

// The value of PCRE2GREP_MAX_BUFSIZE specifies the maximum size of the buffer
// used by pcre2grep to hold parts of the file it is searching. The actual
// amount of memory used by pcre2grep is three times this number, because it
// allows for the buffering of "before" and "after" lines.
//
#ifndef PCRE2GREP_MAX_BUFSIZE
#define PCRE2GREP_MAX_BUFSIZE 1048576
#endif
