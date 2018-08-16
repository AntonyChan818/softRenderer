#ifndef headFile1_h
#define headFile1_h


//module1:
//math lib
//1.vector
typedef struct {
	float x, y, z, w;
} vector_t;
typedef vector_t point_t;

//1.1 length: |v|
float vector_length(const vector_t *v);
//1.2 add: c=a+b
void vector_add(vector_t *c, const vector_t *a, const vector_t *b);
//1.3 sub: c=a-b
void vector_sub(vector_t *c, const vector_t *a, const vector_t *b);
//1.4 scale: v = v*k
void vector_scale(vector_t *v, float k);
//1.5 inverse
void vector_inverse(vector_t *v);
//1.6 dotproduct
float vector_dotproduct(const vector_t *a, const vector_t *b);
//1.7 crossproduct
void vector_crossproduct(vector_t *c, const vector_t *a, const vector_t *b);
//1.8 interp [0,1]
void vector_interp(vector_t *c, const vector_t *a, const vector_t *b, float t);
void vector_clone(vector_t *dest, const vector_t *source);
//1.9 reflect
void vector_reflect(vector_t *r, const vector_t *v, const vector_t *n);
//1.10 normalize
void vector_normalize(vector_t *v);
//1.11 interpolating
void vector_interpolating(vector_t *dest, const vector_t *src1, const vector_t *src2, const vector_t *src3, float a, float b, float c);

#endif // !headFile1_h

