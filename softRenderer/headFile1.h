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
void vector_clone(vector_t *dest, const vector_t *src);
//1.9 reflect
void vector_reflect(vector_t *r, const vector_t *v, const vector_t *n);
//1.10 normalize
void vector_normalize(vector_t *v);
//1.11 interpolating
void vector_interpolating(vector_t *dest, const vector_t *src1, const vector_t *src2, const vector_t *src3, float a, float b, float c);

//2.matrix
typedef struct {
	float m[4][4];
} matrix_t;

//2.1 add
void matrix_add(matrix_t *c, const matrix_t *a, const matrix_t *b);
//2.2 sub
void matrix_sub(matrix_t *c, const matrix_t *a, const matrix_t *b);
//2.3 mul
void matrix_mul(matrix_t *c, const matrix_t *a, const matrix_t *b);
//2.4 scale
void matrix_scale(matrix_t *m, float k);
//2.5 inverse
void matrix_inverse(matrix_t *m);
//2.6 transpose
void matrix_transpose(matrix_t *m);
//2.7 apply
void matrix_apply(vector_t *y, const vector_t *v, const matrix_t *m);
//2.8 clone
void matrix_clone(matrix_t *dest, const matrix_t *src);
//2.9 set identity
void matrix_set_identity(matrix_t *m);
//2.10 set zero
void matrix_set_zero(matrix_t *m);
//2.11 set translate
void matrix_set_translate(matrix_t *m, float dx, float dy, float dz);
//2.12 set scale
void matrix_set_scale(matrix_t *m, float sx, float sy, float sz);
//2.13 set rotate m, x, y, z, theta
void matrix_set_rotate(matrix_t *m, const vector_t *v, float theta);
void matrix_set_rotate_translate_scale(matrix_t *m, const vector_t *axis, float theta, const point_t *pos, const vector_t *scale);
void matrix_set_axis(matrix_t *m, const vector_t *xaxis, const vector_t	*yaxis, const vector_t *zaxis, const point_t *pos);

//2.14 set lookat m, eye, at, up
//zaxis = normal(at-eye)
//xaxis = normal(cross(Up, zaxis))
//yaxis = cross(zaxis, xaxis)

//xaxis.x			yaxis.x				zaxis.x			0
//xaxis.y			yaxis.y				zaxis.y			0
//xaxis.z			yaxis.z				zaxis.z			0
//-dot(xaxis, eye)	-dot(yaxis, eye)	-dot(zaxis,eye)	1
void matrix_set_lookat(matrix_t *m, const vector_t *eye, const vector_t *at, const vector_t *up);

//2.15 set perspective m, fovy, aspect, zn, zf
//zoom = 1/tan(fov/2)
//zoomy = 1/tan(fovy/2)
//zoomx = zoomy*aspect
//zoomx		0			0				0
//0			zoomy		0				0
//0			0			zf/(zf-zn)		1
//0			0			zn*zf/(zn-zf)	0
void matrix_set_perspective(matrix_t *m, float fovy, float aspect, float zn, float zf);

//2.16 set ortho m, left, right, bottom, top, near, far
//2/(r-1)		0			0			0
//

#endif // !headFile1_h

