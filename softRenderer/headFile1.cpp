#include "headFile1.h"
#include<math.h>

float vector_length(const vector_t *v) {
	return sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
}