#ifndef __CGSLOG_H__
#define __CGSLOG_H__

#include <stdio.h>
#define CGSLOGOPEN() { FILE* cgslog = fopen("/tmp/cgslog.txt", "a"); fprintf(cgslog, "\n%s %d\n", __FILE__, __LINE__);
#define CGSLOGCLOSE() if (cgslog) fclose(cgslog); }
#define CGSLOG(s, ...) fprintf(cgslog, s, ##__VA_ARGS__);

#endif /* __CGSLOG_H__ */
