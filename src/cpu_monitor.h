#ifndef CPU_MONITOR_H
#define CPU_MONITOR_H

/* CPU usage percentage in [0, 100], derived from the 1-minute load average
 * divided by the number of online CPU cores. Returns -1.0 on failure. */
double cpu_monitor_get_usage_percent(void);

#endif /* CPU_MONITOR_H */