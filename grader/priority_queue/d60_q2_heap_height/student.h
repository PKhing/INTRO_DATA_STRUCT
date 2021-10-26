#ifndef __STUDENT_H_
#define __STUDENT_H_

#include <stdio.h>
#include "priority_queue.h"
#include <iostream>
#include <math.h>

template <typename T, typename Comp>
int CP::priority_queue<T, Comp>::height() const {
  return ceil(log2(mSize + 1)) - 1;
}

#endif
