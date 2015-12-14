//
// Created by ngrande on 12/14/15.
//

#ifndef PIALARM_ITASK_H
#define PIALARM_ITASK_H


class ITask {
public:
    virtual void onTimeExceeded() = 0;
};


#endif //PIALARM_ITASK_H
