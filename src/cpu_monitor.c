#include "cpu_monitor.h"

#include <stdlib.h>
#include <unistd.h>

double cpu_monitor_get_usage_percent(void)
{
    double loadavg[1];
    if (getloadavg(loadavg, 1) != 1) {
        return -1.0;
    }

    long num_cores = 1;
#ifdef _SC_NPROCESSORS_ONLN
    num_cores = sysconf(_SC_NPROCESSORS_ONLN);
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