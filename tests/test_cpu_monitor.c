#include <assert.h>
#include "cpu_monitor.h"

void setUp(void) {}
void tearDown(void) {}

static void test_usage_within_bounds(void)
{
    double usage = cpu_monitor_get_usage_percent();
    assert(usage >= 0.0 && usage <= 100.0);
}

static void test_usage_repeated_calls_stay_within_bounds(void)
{
    for (int i = 0; i < 5; i++) {
        double usage = cpu_monitor_get_usage_percent();
        assert(usage >= 0.0 && usage <= 100.0);
    }
}

int main(void)
{
    test_usage_within_bounds();
    test_usage_repeated_calls_stay_within_bounds();
    return 0;
}
