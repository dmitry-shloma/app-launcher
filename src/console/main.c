#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>

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
    char buf[21] = "";
    strftime(buf, sizeof(buf), "%Y-%m-%d, %H:%M:%S", localtime(&t));
    printf("[%s]: %s\n", buf, msg);
}
