#ifndef headFile1_h
#define headFile1_h


//module:
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
//2/(r-l)		0			0			0
//0				2/(t-b)		0			0
//0				0			1/(zf-zn)	0
//(l+r)/(l-r)	(t+b)/(t-b)	zn/(zn-zf)	1
void matrix_set_ortho(matrix_t *m, float l, float r, float b, float t, float zn, float zf);

//证明资料https://www.cnblogs.com/hisiqi/p/3155813.html

//data structure
//3. transform_t
typedef struct {
	matrix_t model;
	matrix_t view;
	matrix_t view_r;
	matrix_t projection;
	matrix_t vp;		//view*projection
	matrix_t mv;		//model*view
	matrix_t mvp;		//model*view*projection
} transform_t;

//3.1 transform update(world * view * projection)
void transform_update(transform_t *ts);
//3.2 transform_apply
void transform_apply(const transform_t *ts, vector_t *y, const vector_t *x);
//3.3 transform check cvv(v)
int transform_check_cvv(const vector_t *v);
//3.4 transform_homogenize(ts, y, x)
void transform_homogenize(vector_t *y, const vector_t *x, float width, float height);
//3.5 transform_homogenize(ts, y, x)
void transform_homogenize(vector_t *y, const vector_t *x, float w, float width, float height);

//4. geometry calculation(vertex, scanline, border, check, rect, ...)
typedef struct {
	float r, g, b, a;
} color_t; 
void color_init(color_t *c);
void color_product(color_t *c, const color_t *a, const color_t *b);
void color_scale(color_t *c, float k);
void color_add(color_t *c, const color_t *a, const color_t *b);
void color_sub(color_t *c, const color_t *a, const color_t *b);
void color_interpolating(color_t *dest, const color_t *src1, const color_t *src2, const color_t *src3, float a, float b, float c);

typedef struct {
	char *name;

	color_t ambient;
	color_t diffuse;
	color_t specular;
	color_t transmittance;
	color_t emission;

	float shininess;
	float ior;		//index of refraction折射
	float dissolve;
	int illum;

	int pad0;
	char *ambient_texname;
	int ambient_tex_id;
	char *diffuse_texname;
	int diffuse_tex_id;
	char *specular_texname;
	int specular_tex_id;
	char *specular_highlight_texname;
	int specular_highlight_tex_id;
	char *bump_texname;
	int bump_tex_id;
	char *displacement_texname;
	int displacement_tex_id;
	char *alpha_texname;
	int alpha_tex_id;
} material_t;
#define NUM_MATERIAL 100
extern material_t materials[NUM_MATERIAL];
extern int material_cnt;

void free_material(material_t *material);

typedef struct {
	point_t pos;
	float constant;
	float linear;
	float quadratic;
	color_t ambi;
	color_t diff;
	color_t spec;
	bool shadow;
} pointlight_t;
#define NR_POINT_LIGHTS 100
extern pointlight_t pointLights[NR_POINT_LIGHTS];
extern int pointlight_cnt;

typedef struct {
	vector_t dir;
	color_t ambi;
	color_t diff;
	color_t spec;
	bool shadow;
} dirlight_t;
extern dirlight_t dirLight;

typedef enum {
	perspective, 
	orthographic
} PROJECTION;
typedef struct {
	//public 
	vector_t pos;
	vector_t front;
	vector_t worldup;
	matrix_t view_matrix;
	matrix_t projection_matrix;
	matrix_t view_matrix_r;
	int width;
	int height;
	float fovy;
	float zn;
	float zf;

	float left;
	float right;
	float bottom;
	float top;

	bool dirty;
	PROJECTION projection;
	bool main;

	//private
	float aspect;
} camera_t;
#define MAX_NUM_CAMERA 10
extern camera_t cameras[MAX_NUM_CAMERA];
extern int camera_count;
#endif // !headFile1_h

