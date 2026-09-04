#include "cpu_monitor.h"

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

double cpu_monitor_get_usage_percent(void)
{
    double loadavg[1];
    if (getloadavg(loadavg, 1) != 1) {
        return -1.0;
    }

#ifdef _WIN32
    SYSTEM_INFO system_info;
    GetSystemInfo(&system_info);
    long num_cores = (long)system_info.dwNumberOfProcessors;
#else
    long num_cores = sysconf(_SC_NPROCESSORS_ONLN);
#endif
    if (num_cores < 1) {
        num_cores = 1;
    }

    double usage = (loadavg[0] / (double)num_cores) * 100.0;

    if (usage < 0.0) {
        usage = 0.0;
    } else if (usage > 100.0) {
        usage = 100.0;
    }

    return usage;
}