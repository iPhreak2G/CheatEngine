#pragma once
BYTE MyTeam;
#define ENTITIESMAX 12
BOOL bInit = false;
#define M_PI       3.14159265358979323846
#define GET_ORIGIN(VecOut,pMatrix) {VecOut.x = pMatrix._41;VecOut.y = pMatrix._42;VecOut.z = pMatrix._43;};
#define GET_X(VecOut,pMatrix) {D3DXVec3Normalize(&VecOut,&Vector3(pMatrix._11,pMatrix._12,pMatrix._13));};
#define GET_Y(VecOut,pMatrix) {D3DXVec3Normalize(&VecOut,&Vector3(pMatrix._21,pMatrix._22,pMatrix._23));};
#define GET_Z(VecOut,pMatrix) {D3DXVec3Normalize(&VecOut,&Vector3(pMatrix._31,pMatrix._32,pMatrix._33));};
#define DotProduct(x,y)			((x)[0]*(y)[0]+(x)[1]*(y)[1]+(x)[2]*(y)[2])
#define VectorSubtract(a,b,c)	((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)		((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)			((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])
#define VectorCopy4(a,b)		((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2],(b)[3]=(a)[3])
#define	VectorScale(v, s, o)	((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define	VectorMA(v, s, b, o)	((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define VectorCmp(a,b)			(((a)[0]==(b)[0])&&((a)[1]==(b)[1])&&((a)[2]==(b)[2]))
#define POW(x)					((x) * (x))
#define ScreenDistance(a,b)		(sqrt(POW(a[0]-b[0]) + POW(a[1]-b[1])))
#define DistanceBox(a,b,c)		((c*((float)(*(INT*)0x2A81000))/pRefDef->flFOV) * 18.0f / (VectorDistance(a,b)/55.0f))
#define VALID( x ) ( x != NULL && HIWORD( x ) )
#define ANGLE2SHORT(x) ((INT)((x)*65536/360) & 65535)
#define GetPointer(X) *(DWORD*)(X);
#define GetPointer(X) *(DWORD*)(X);
#define M_1PI 3.14159265359f
#define M_2PI 6.28318530718f
#define AngleToShort(X) ((INT)((X) * 65536 / 360) & 65535)
#define	ShortToAngle(X) ((X) * (360 / 65536))
BOOL GotVisible = false;
BOOL updateOffset = false;
BOOL LastFrameAimKey = false;
typedef float vec_t;

INT GetDec(char Hex) {
	if ((Hex >= '0') && (Hex <= '9')) return Hex - '0';
	if ((Hex >= 'A') && (Hex <= 'F')) return Hex - 'A' + 10;
	if ((Hex >= 'a') && (Hex <= 'f')) return Hex - 'a' + 10;

	return -1;
}
__declspec(naked) INT SaveStubPacket(INT a1)
{
	__asm
	{
		nop
		nop
		nop
		nop
		nop
		nop
		nop
	}
}
class Vector
{
public:
	// Construction/destruction
	inline Vector(VOID) { }
	inline Vector(float X, float Y, float Z) { x = X; y = Y; z = Z; }
	inline Vector(double X, double Y, double Z) { x = (float)X; y = (float)Y; z = (float)Z; }
	inline Vector(INT X, INT Y, INT Z) { x = (float)X; y = (float)Y; z = (float)Z; }
	inline Vector(CONST Vector& v) { x = v.x; y = v.y; z = v.z; }
	inline Vector(float rgfl[3]) { x = rgfl[0]; y = rgfl[1]; z = rgfl[2]; }

	// Operators
	inline Vector operator-(VOID) CONST { return Vector(-x, -y, -z); }
	inline INT operator==(CONST Vector& v) CONST { return x == v.x && y == v.y && z == v.z; }
	inline INT operator!=(CONST Vector& v) CONST { return !(*this == v); }
	inline Vector operator+(CONST Vector& v) CONST { return Vector(x + v.x, y + v.y, z + v.z); }
	inline Vector operator-(CONST Vector& v) CONST { return Vector(x - v.x, y - v.y, z - v.z); }
	inline Vector operator*(float fl) CONST { return Vector(x*fl, y*fl, z*fl); }
	inline Vector operator/(float fl) CONST { return Vector(x / fl, y / fl, z / fl); }

	// Methods
	inline VOID CopyToArray(float* rgfl) CONST { rgfl[0] = x, rgfl[1] = y, rgfl[2] = z; }
	inline float Length(VOID) CONST { return (float)sqrt(x*x + y*y + z*z); }
	operator float *() { return &x; } // Vectors will now automatically convert to float * when needed
	operator CONST float *() CONST { return &x; } // Vectors will now automatically convert to float * when needed
	inline Vector Normalize(VOID) CONST
	{
		float flLen = Length();
		if (flLen == 0) return Vector(0, 0, 1); // ????
		flLen = 1 / flLen;
		return Vector(x * flLen, y * flLen, z * flLen);
	}

	inline float Length2D(VOID) CONST { return (float)sqrt(x*x + y*y); }

	// Members
	vec_t x, y, z;
};
inline Vector operator*(float fl, CONST Vector& v) { return v * fl; }
class vec2
{
public:
	union {
		struct { float x, y; };
		struct { float s, t; };
		struct { float r, g; };
	};
	vec2() : x(0.0f), y(0.0f) {}
	~vec2() {}
	vec2(float num) : x(num), y(num) {}
	vec2(float x, float y) : x(x), y(y) {}
	vec2(CONST vec2 &u) : x(u.x), y(u.y) {}
	vec2& operator = (CONST vec2 &u) { x = u.x; y = u.y; return *this; }
	vec2 operator - () { return vec2(-x, -y); }
	float* operator & () { return (float*)this; };
	vec2& operator += (float num) { x += num; y += num; return *this; }
	vec2& operator += (CONST vec2 &u) { x += u.x; y += u.y; return *this; }
	vec2& operator -= (float num) { x -= num; y -= num; return *this; }
	vec2& operator -= (CONST vec2 &u) { x -= u.x; y -= u.y; return *this; }
	vec2& operator *= (float num) { x *= num; y *= num; return *this; }
	vec2& operator *= (CONST vec2 &u) { x *= u.x; y *= u.y; return *this; }
	vec2& operator /= (float num) { x /= num; y /= num; return *this; }
	vec2& operator /= (CONST vec2 &u) { x /= u.x; y /= u.y; return *this; }
	friend vec2 operator + (CONST vec2 &u, float num) { return vec2(u.x + num, u.y + num); }
	friend vec2 operator + (float num, CONST vec2 &u) { return vec2(num + u.x, num + u.y); }
	friend vec2 operator + (CONST vec2 &u, CONST vec2 &v) { return vec2(u.x + v.x, u.y + v.y); }
	friend vec2 operator - (CONST vec2 &u, float num) { return vec2(u.x - num, u.y - num); }
	friend vec2 operator - (float num, CONST vec2 &u) { return vec2(num - u.x, num - u.y); }
	friend vec2 operator - (CONST vec2 &u, CONST vec2 &v) { return vec2(u.x - v.x, u.y - v.y); }
	friend vec2 operator * (CONST vec2 &u, float num) { return vec2(u.x * num, u.y * num); }
	friend vec2 operator * (float num, CONST vec2 &u) { return vec2(num * u.x, num * u.y); }
	friend vec2 operator * (CONST vec2 &u, CONST vec2 &v) { return vec2(u.x * v.x, u.y * v.y); }
	friend vec2 operator / (CONST vec2 &u, float num) { return vec2(u.x / num, u.y / num); }
	friend vec2 operator / (float num, CONST vec2 &u) { return vec2(num / u.x, num / u.y); }
	friend vec2 operator / (CONST vec2 &u, CONST vec2 &v) { return vec2(u.x / v.x, u.y / v.y); }
};
short angle2short(float x) {
	return ((INT)((x) * 65536 / 360) & 65535);
}
INT short2angle(short x) {
	return ((x)*(360.0 / 65536));
}
struct Vec3
{
	float x, y, z;
};
float angles[3];
Vec3 Difference;
Vector vectoangles(Vec3 Angles)
{
	float forward;
	float yaw, pitch;
	float PI = 3.1415926535897931;
	if (Angles.x == 0 && Angles.y == 0)
	{
		yaw = 0;
		if (Angles.z > 0) pitch = 90.00;
		else pitch = 270.00;
	}
	else
	{
		if (Angles.x != -1) yaw = (float)(atan2((double)Angles.y, (double)Angles.x) * 180.00 / PI);
		else if (Angles.y > 0) yaw = 90.00;
		else yaw = 270;
		if (yaw < 0) yaw += 360.00;

		forward = (float)sqrt((double)(Angles.x * Angles.x + Angles.y * Angles.y));
		pitch = (float)(atan2((double)Angles.z, (double)forward) * 180.00 / PI);
		if (pitch < 0) pitch += 360.00;
	}
	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;

	return angles;
}
Vec3 GetVec(D3DXVECTOR3 Attacker, D3DXVECTOR3 Target)
{
	Difference.x = (Target.x - Attacker.x);
	Difference.y = (Target.y - Attacker.y);
	Difference.z = (Target.z - Attacker.z);
	return Difference;
}
vec2 normalize(CONST vec2 &u)
{
	return u / sqrt(u.x * u.x + u.y * u.y);
}
VOID VectorAngles(CONST float* forward, float* angles)
{
	float tmp, yaw, pitch;

	if (forward[2] == 0 && forward[0] == 0)
	{
		yaw = 0;

		if (forward[2] > 0)
			pitch = 90;
		else
			pitch = 270;
	}
	else
	{
		yaw = (atan2(forward[2], -forward[0]) * 180 / M_PI) - 90;

		if (yaw < 0)
			yaw += 360;

		tmp = sqrt(forward[0] * forward[0] + forward[2] * forward[2]);
		pitch = (atan2(forward[1], tmp) * 180 / M_PI);

		if (pitch < 0)
			pitch += 360;
	}

	angles[0] = -pitch;
	angles[1] = yaw;
	angles[2] = 0;
}
struct Vector2 {
	float x, y;

	Vector2() {
		x = y = 0.0f;
	}

	Vector2(float x, float y) {
		this->x = x;
		this->y = y;
	}

	float distance(Vector2 &Vector) {
		return sqrt(distanceEx(Vector));
	}

	float distanceEx(Vector2 &Vector) {
		float _x = this->x - Vector.x, _y = this->y - Vector.y;
		return ((_x * _x) + (_y * _y));
	}
};
struct Vector3 {
	float x, y, z;

	Vector3() {
		x = y = z = 0.0f;
	}

	Vector3(float x, float y, float z) {
		this->x = x; this->y = y; this->z = z;
	}

	BOOL operator==(Vector3 &Vector) {
		return (this->x == Vector.x && this->y == Vector.y && this->z == Vector.z);
	}

	Vector3& operator+(Vector3 &Vector) {
		return Vector3(this->x + Vector.x, this->y + Vector.y, this->z + Vector.z);
	}

	Vector3& operator-(Vector3 &Vector) {
		return Vector3(this->x - Vector.x, this->y - Vector.y, this->z - Vector.z);
	}

	float distance(Vector3 &Vector) {
		return sqrt(distanceEx(Vector));
	}

	float distanceEx(Vector3 &Vector) {
		float _x = this->x - Vector.x, _y = this->y - Vector.y, _z = this->z - Vector.z;
		return ((_x * _x) + (_y * _y) + (_z * _z));
	}

	float dotProduct(Vector3 &Vector) {
		return (this->x * Vector.x) + (this->y * Vector.y) + (this->z * Vector.z);
	}
};
Vector3 SilentAngles;
struct Vector4 {
	float a, b, c, d;

	Vector4() {
		a = b = c = d = 0.0f;
	}

	Vector4(float a, float b, float c, float d) {
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
	}

	PFLOAT Tofloat() {
		FLOAT Vector[4] = { this->a, this->b, this->c, this->d };
		return Vector;
	}

};
Vector4 Float2Vector(CONST float *color) {
	return Vector4(color[0], color[1], color[2], color[3]);
}
Vector4 HexToVector(PCHAR HexColor, FLOAT Alpha) {
	FLOAT fontColor[3];

	for (INT i = 0; i < 3; i++) {
		INT INTColor = (GetDec(HexColor[0]) * 16) + GetDec(HexColor[1]);

		fontColor[i] = (FLOAT)(INTColor / 255.0);
		HexColor += 2;
	}

	return Vector4(fontColor[0], fontColor[1], fontColor[2], Alpha);
}
float GetTextPos(float PlayerDisctance)
{
	if (PlayerDisctance <= 10)
		return 18;

	else if (PlayerDisctance <= 20)
		return 15;

	else if (PlayerDisctance <= 30)
		return 12;

	else if (PlayerDisctance <= 40)
		return 11;

	else if (PlayerDisctance <= 50)
		return 10;

	else if (PlayerDisctance <= 60)
		return 9;

	else if (PlayerDisctance <= 70)
		return 8;

	else if (PlayerDisctance <= 80)
		return 7;

	else if (PlayerDisctance <= 90)
		return 6;

	else if (PlayerDisctance <= 99.9999)
		return 5;

	else if (PlayerDisctance >= 100)
		return 5;
}
float GetTextPos1(float PlayerDisctance)
{
	if (PlayerDisctance <= 10)
		return 26;

	else if (PlayerDisctance <= 20)
		return 23;

	else if (PlayerDisctance <= 30)
		return 20;

	else if (PlayerDisctance <= 40)
		return 19;

	else if (PlayerDisctance <= 50)
		return 18;

	else if (PlayerDisctance <= 60)
		return 17;

	else if (PlayerDisctance <= 70)
		return 16;

	else if (PlayerDisctance <= 80)
		return 15;

	else if (PlayerDisctance <= 90)
		return 14;

	else if (PlayerDisctance <= 99.9999)
		return 13;

	else if (PlayerDisctance >= 100)
		return 13;
}
float GetBoxWidth() {
	return 17;
}
float GetBoxHeight() {
	return 60;
}
BOOL ProximityWarning(float PlayerDisctance)
{
	if (PlayerDisctance <= 15)
		return true;

	else return false;
}
CONST float *color1;
Vector4 color1BO3;
Vector4 color2BO3;
Vector4 color3BO3;
CONST float *color2;
CONST float *color3;
CONST float *change_color;
CONST float *friendly_color;
CONST float *enemies_color;
CONST float *visible_color;
CONST float *change_shad_color;
CONST float *change_shad_colorInside;
CONST float *change_shad_colorOutside;
CONST float *crosshair_color;
CONST float *shad_e_color;
CONST float *shad_f_color;
CONST float *shad_v_color;
static CONST float L_white[4] = { 1.0f, 1.0f, 1.0f, 0.2f };
static CONST float L_black[4] = { 0.0f, 0.0f, 0.0f, 0.1f };
static CONST float L_black2[4] = { 0.0f, 0.0f, 0.0f, 0.2f };
static CONST float L_grey[4] = { 0.5f, 0.5f, 0.5f, 0.2f };
static CONST float L_red[4] = { 1.0f, 0.0f, 0.0f, 0.2f };
static CONST float L_green[4] = { 0.0f, 1.0f, 0.0f, 0.2f };
static CONST float L_blue[4] = { 0.0f, 0.0f, 1.0f, 0.2f };
static CONST float L_yellow[4] = { 0.9f, 0.9f, 0.0f, 0.2f };
static CONST float L_orange[4] = { 1.f, 0.5, 0.f, 0.2f };
static CONST float L_magenta[4] = { 1.0f, 0.0f, 1.0f, 0.2f };
static CONST float L_purple[4] = { 0.6f, 0.2f, 0.8f, 0.2f };
static CONST float L_pink[4] = { 1.0f, 0.5607843137254902f, 0.8156862745098039f, 0.2f };
static CONST float L_cyan[4] = { 0.0f, 1.0f, 1.0f, 0.2f };
static CONST float white[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
static CONST float black[4] = { 0.0f, 0.0f, 0.0f, 255.0f };
static CONST float smoke[4] = { 0.5f, 0.5f, 0.5f, 0.5f };
static CONST float grey[4] = { 0.5f, 0.5f, 0.5f, 1.0f };
static CONST float red[4] = { 1.0f, 0.0f, 0.0f, 1.0f };
static CONST float green[4] = { 0.0f, 1.0f, 0.0f, 1.0f };
static CONST float yellow[4] = { 0.9f, 0.9f, 0.0f, 1.0 };
static CONST float orange[4] = { 1.f, 0.5, 0.f, 1.f };
static CONST float magenta[4] = { 1.0f, 0.0f, 1.0f, 1.0f };
static CONST float purple[4] = { 0.6f, 0.2f, 0.8f, 1.0f };
static CONST float pink[4] = { 1.0f, 0.5607843137254902f, 0.8156862745098039f, 1.0f };
static CONST float cyan[4] = { 0.0f, 1.0f, 1.0f, 1.0f };

static CONST float c_white[4] = { 0.42f, 0.42f, 0.44f, 1.0f};
static CONST float a_white[4] = { 0.77f, 0.84f, 0.65f, 0.9f };

static Vector4
MenuCycle = Vector4(1, 1, 0, 1),
cyanide = Vector4(0, 1, 1, 1),
xecheats = Vector4(1, 0.549019607843f, 0, 1),
konroi = Vector4(0.19607843137255f, 1, 0.19607843137255f, 1);
Vector4 menu_color;
float title_size = 0.3f;
float menu_pos_x = -400;
float menu_pos_y;
Vector4 fixRGBA(float r, float g, float b, float a)
{
	Vector4 color = Vector4(r / 255, g / 255, b / 255, a / 255);
	return color;
}

VOID cycleColors()
{
	float r = 255, g = 0, b = 0;
	for (;;) {
		if (r > 0 && b == 0) {
			r--;
			g++;
		}
		if (g > 0 && r == 0) {
			g--;
			b++;
		}
		if (b > 0 && g == 0) {
			r++;
			b--;
		}
		menu_color = fixRGBA(r, g, b, 800);
		Sleep(10);
	}
}
float GetDistance(D3DXVECTOR3 me, D3DXVECTOR3 enemi)
{
	float dx = me.x - enemi.x;
	float dy = me.y - enemi.y;
	float dz = me.z - enemi.z;
	return (float)sqrt((dx * dx) + (dy * dy) + (dz * dz))  * 0.03048f;
}
float VectorLength(D3DVECTOR v)
{
	return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

VOID VectorNormalize(D3DVECTOR Vec)
{
	float l = 1 / VectorLength(Vec);
	Vec.x *= l;
	Vec.y *= l;
	Vec.z *= l;
}