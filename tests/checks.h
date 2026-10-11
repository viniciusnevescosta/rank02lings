#ifndef RANK02LINGS_CHECKS_H
#define RANK02LINGS_CHECKS_H

#include <stdio.h>
#include <string.h>

/* Report from C on stderr; stdout remains the exercise's own output. */
static inline void r02_json_string(const char *s)
{
	const unsigned char *p = (const unsigned char *)s;

	fputc('"', stderr);
	while (*p)
	{
		if (*p == '"' || *p == '\\')
			fprintf(stderr, "\\%c", *p);
		else if (*p < 32 || *p >= 127)
			fprintf(stderr, "\\u%04x", (unsigned int)*p);
		else
			fputc(*p, stderr);
		p++;
	}
	fputc('"', stderr);
}

static inline void r02_begin(const char *kind, const char *expression,
							 const char *file, int line)
{
	fputs("RANK02LINGS_CHECK\t{\"kind\":", stderr);
	r02_json_string(kind);
	fputs(",\"expression\":", stderr);
	r02_json_string(expression);
	fputs(",\"file\":", stderr);
	r02_json_string(file);
	fprintf(stderr, ",\"line\":%d", line);
}

static inline void r02_pending(const char *kind, const char *expression,
							   const char *file, int line)
{
	r02_begin(kind, expression, file, line);
	fputs("}\n", stderr);
	fflush(stderr);
}

static inline int r02_int(const char *expression, long long actual,
						  long long expected, const char *file, int line)
{
	int passed = actual == expected;

	r02_begin("check", expression, file, line);
	fprintf(stderr, ",\"passed\":%s,\"expected\":%lld,\"actual\":%lld}\n",
			passed ? "true" : "false", expected, actual);
	return passed;
}

static inline int r02_bool(const char *expression, int actual, int expected,
						   const char *file, int line)
{
	int passed = !!actual == !!expected;

	r02_begin("check", expression, file, line);
	fprintf(stderr, ",\"passed\":%s,\"expected\":%s,\"actual\":%s}\n",
			passed ? "true" : "false", expected ? "true" : "false",
			actual ? "true" : "false");
	return passed;
}

static inline int r02_string(const char *expression, const char *actual,
							 const char *expected, const char *file, int line)
{
	int passed = actual && expected && strcmp(actual, expected) == 0;

	r02_begin("check", expression, file, line);
	fprintf(stderr, ",\"passed\":%s,\"expected\":", passed ? "true" : "false");
	if (expected)
		r02_json_string(expected);
	else
		fputs("null", stderr);
	fputs(",\"actual\":", stderr);
	if (actual)
		r02_json_string(actual);
	else
		fputs("null", stderr);
	fputs("}\n", stderr);
	return passed;
}

static inline void r02_pointer_value(const void *p)
{
	if (p)
		fprintf(stderr, "\"%p\"", p);
	else
		fputs("\"NULL\"", stderr);
}

static inline int r02_pointer(const char *expression, const void *actual,
							  const void *expected, int nonnull,
							  const char *file, int line)
{
	int passed = nonnull ? actual != NULL : actual == expected;

	r02_begin("check", expression, file, line);
	fprintf(stderr, ",\"passed\":%s,\"expected\":", passed ? "true" : "false");
	if (nonnull)
		fputs("\"non-NULL\"", stderr);
	else
		r02_pointer_value(expected);
	fputs(",\"actual\":", stderr);
	r02_pointer_value(actual);
	fputs("}\n", stderr);
	return passed;
}

/* Arguments are evaluated once, including calls that modify student data. */
#define CASE(label) r02_pending("case", (label), __FILE__, __LINE__)
#define R02_PENDING(actual) r02_pending("pending", #actual, __FILE__, __LINE__)
#define CHECK_INT(actual, expected)                                            \
	do                                                                         \
	{                                                                          \
		R02_PENDING(actual);                                                   \
		if (!r02_int(#actual, (actual), (expected), __FILE__, __LINE__))       \
			return 1;                                                          \
	} while (0)
#define CHECK_BOOL(actual, expected)                                           \
	do                                                                         \
	{                                                                          \
		R02_PENDING(actual);                                                   \
		if (!r02_bool(#actual, !!(actual), !!(expected), __FILE__, __LINE__))  \
			return 1;                                                          \
	} while (0)
#define CHECK_STRING(actual, expected)                                         \
	do                                                                         \
	{                                                                          \
		R02_PENDING(actual);                                                   \
		if (!r02_string(#actual, (actual), (expected), __FILE__, __LINE__))    \
			return 1;                                                          \
	} while (0)
#define CHECK_POINTER(actual, expected)                                        \
	do                                                                         \
	{                                                                          \
		R02_PENDING(actual);                                                   \
		if (!r02_pointer(#actual, (actual), (expected), 0, __FILE__,           \
						 __LINE__))                                            \
			return 1;                                                          \
	} while (0)
#define CHECK_NOT_NULL(actual)                                                 \
	do                                                                         \
	{                                                                          \
		R02_PENDING(actual);                                                   \
		if (!r02_pointer(#actual, (actual), NULL, 1, __FILE__, __LINE__))      \
			return 1;                                                          \
	} while (0)
#define CHECK(expression) CHECK_BOOL(expression, 1)

#endif
