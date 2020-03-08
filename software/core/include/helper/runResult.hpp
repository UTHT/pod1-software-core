#ifndef RUNRESULT_H
#define RUNRESULT_H

struct runResult {
    double output = 0.0;
    bool status = false;

    runResult() = default;
    runResult(double _output, bool _status):
            
            output(_output), status(_status) {}
};

#endif
