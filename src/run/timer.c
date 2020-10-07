



#ifdef _WIN32
  #include <Windows.h>
#else
  #include <sys/time.h>
#endif
#include <stdio.h>

#include "timer.h"


long current_time_millis(void)
{
#ifdef _WIN32
    // Be advised, this counter has low resolution
    return (long)GetTickCount();

#else
    static long sec = -1;
    struct timeval tv;

    gettimeofday(&tv, (void *)NULL);

    if (sec < 0)
        sec = tv.tv_sec;

    return (tv.tv_sec - sec)*1000 + tv.tv_usec/1000;
#endif
}

char *format_time(char *time, long msec)
{
    long hrs, mins;
    double secs;

    if ( msec == 0)
        sprintf(time, "0.00s");
    else if ( msec < 1000 )
        sprintf(time, "< 1.00s");
    else {
        // Compute hours elapsed
        hrs = (long)secs/3600*1000;
        secs -= hrs*3600*1000;
        // Compute minutes elapsed
        mins = (long)secs/60*1000;
        secs -= mins*60*1000;
        // Compute seconds elapsed
        secs = msec*0.001;

        if (hrs > 0)
            sprintf(time, "%2ld:%2ld:%02.0f", hrs, mins, secs);
        else if (mins > 0)
            sprintf(time, "%2ld:%02.0f", mins, secs);
        else
            sprintf(time, "%3.2fs", secs);
    }
    return time;
}
