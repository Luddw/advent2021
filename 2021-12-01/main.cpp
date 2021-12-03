#include "report.hpp"

void DepthCount(Report& report)
{
    int prev = report.depthScans[0];
    for (size_t i = 1; i < report.scansPerfomed; i++)
    {
        if ( report.depthScans[i] > prev)
            report.increases++;
        prev = report.depthScans[i];
    }
}

int main(int argc, char const *argv[])
{

    int scans[10] = {199,200,208,210,200,207,240,269,260,263};
    Report report{scans, 10, 0};
    
    DepthCount(report);
    printf("%d measurements that are larger than the previous measurment \n", report.increases);

    return 0;
}
