#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>
#include <string.h>

#define ONE_SEC 1

void to_log(const char *msg);

int main()
{
    while(true) {
        to_log("I'am still alive");
        sleep(ONE_SEC);
    }

    return 0;
}

void to_log(const char *msg)
{
    time_t t = time(NULL);
    char buf_t[21] = "";
    strftime(buf_t, sizeof(buf_t), "%Y-%m-%d, %H:%M:%S", localtime(&t));

    char buf[255] = "";
    sprintf(buf, "[%s]: %s\n", buf_t, msg);

    FILE *fp = fopen("/tmp/log", "a");
    if (!fp) {
        assert("error: fopen");
    }
    fwrite(buf, sizeof(buf[0]), strlen(buf), fp);
    fclose(fp);
}
