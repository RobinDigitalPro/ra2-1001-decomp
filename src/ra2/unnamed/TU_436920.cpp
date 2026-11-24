// unidentified translation unit (GAMECONST.H initializers at 0x36920) (level-2 reconstruction of GAME.EXE 1.001)
// Bouncing debris physics (provisional class name BounceClass; no RTTI/vtable). Code range
// 0x436af0..0x4375bc. The Vector3 helpers at the end are out-of-line copies of inline methods.
#include "../RECT.H"
static RectangleStruct const ZeroRectA(0, 0, 0, 0);
#include "../GAMECONST.H"
#include "../COORD.H"
#include "../FASTMATH.H"

// ---- local declarations (to be moved to headers by the integrator) ----

// Table based sine/cosine (0x4ba0f0, 0x4ba140; names provisional).
double __cdecl Table_Sin(double angle);         // 0x4ba0f0
double __cdecl Table_Cos(double angle);         // 0x4ba140

class RandomClass {
public:
    int operator()(int minval, int maxval);     // 0x62fe40
};
class ScenarioClass {
public:
    char Unknown0[0x218];
    RandomClass RandomNumber;                   // +0x218
};
extern ScenarioClass * Scen;                    // 0xa255c0

// Three float vector (Westwood 3D math library; inline methods).
class Vector3 {
public:
    Vector3() {}
    Vector3(float x, float y, float z) { X = x; Y = y; Z = z; }        // out of line copy 0x437510
    Vector3 & operator *= (float k) { X *= k; Y *= k; Z *= k; return *this; }   // 0x437530
    Vector3 & operator += (Vector3 const & v) { X += v.X; Y += v.Y; Z += v.Z; return *this; }  // 0x437560
    float Length() const { return Fast_Sqrt(X * X + Y * Y + Z * Z); }  // 0x437590
    float & operator [] (int i) { return (&X)[i]; }                     // 0x619dc0
    float X;
    float Y;
    float Z;
};

class Quaternion {
public:
    Quaternion operator = (Quaternion const & q);   // 0x619de0
    float X;
    float Y;
    float Z;
    float W;
};

class Matrix3D {
public:
    void Make_Identity();                       // 0x58ce60
    float Row[3][4];
};

// The result object is passed first (ecx) and returned by reference.
Quaternion & Build_Quaternion(Quaternion & q, Vector3 const & axis, float angle);  // 0x61a540
Quaternion & Build_Quaternion(Quaternion & q, Matrix3D const & matrix);            // 0x61a7f0
Matrix3D & Build_Matrix3D(Matrix3D & m, Quaternion const & q);                     // 0x61aa40

inline Vector3 operator / (Vector3 const & v, float k)
{
    return Vector3(v.X / k, v.Y / k, v.Z / k);
}

inline Vector3 Normalize(Vector3 const & v)
{
    float len = v.Length();
    if (len != 0.0) {
        return v / len;
    }
    return v;
}

// Vector from three components in units of 1/65535.
inline Vector3 Unit_Vector(int x, int y, int z)
{
    return Vector3(x * (1.0f / 65535.0f), y * (1.0f / 65535.0f), z * (1.0f / 65535.0f));
}

inline double Random_Unit()
{
    return Scen->RandomNumber(0, 0x7FFFFFFE) * (1.0 / 2147483647.0);
}

class BounceClass {
public:
    enum StatusType { BOUNCE_NONE, BOUNCE_BOUNCE, BOUNCE_IMPACT };

    void Init(CoordStruct const & coord, double elasticity, double gravity,
        double min_speed, double max_speed);    // 0x436af0
    void Init(CoordStruct const & coord, double elasticity, double gravity,
        double max_velocity, Vector3 const & velocity, double angular_velocity);  // 0x436c40
    CoordStruct Get_Coord() const;              // 0x436e00
    Matrix3D Get_Matrix() const;                // 0x436e40
    double Impact_Speed() const;                // 0x436e70 (name provisional)

    double Elasticity;                          // +0x00
    double Gravity;                             // +0x08
    double MaxVelocity;                         // +0x10
    Vector3 Coords;                             // +0x18
    Vector3 Velocity;                           // +0x24
    Quaternion CurrentAngle;                    // +0x30
    Quaternion AngularVelocity;                 // +0x40
};

class CellClass {
public:
    char Unknown0[0x140];
    int Flags;                                  // +0x140 (bit 8 = bridge)
};
class MapClass {
public:
    CellClass & operator [] (CoordStruct const & coord);    // 0x545490
    int Get_Cell_Height(CoordStruct const & coord) const;   // 0x557070 (name provisional)
};
class MouseClass : public MapClass {
};
extern MouseClass Map;                          // 0x81a820
extern int BridgeHeight;                        // 0x836fb0 (name provisional)

inline int Distance(int x, int y, int z)
{
    return Fast_Sqrt((double)x * x + (double)y * y + (double)z * z);
}

// ---- end of local declarations ----

// Not yet byte-identical: the original pushes the high half of the 0.0 argument before loading
// the elasticity words (11 bytes of scheduling differ).
void BounceClass::Init(CoordStruct const & coord, double elasticity, double gravity,
    double min_speed, double max_speed)
{
    double speed = (Random_Unit() * (max_speed - min_speed) + min_speed) * 3.0;
    double heading = Random_Unit() * 6.283185307179586;
    double pitch = (Random_Unit() + 1.0) * 0.7853981633974483;
    Vector3 velocity;
    velocity.X = Table_Cos(pitch) * Table_Cos(heading) * speed;
    velocity.Y = Table_Cos(pitch) * Table_Sin(heading) * speed;
    velocity.Z = Table_Sin(pitch) * speed;
    Init(coord, elasticity, 3.0f, 0.0f, velocity, 0.0f);
}

// Not yet byte-identical: the order of the inlined length/normalize code differs.
void BounceClass::Init(CoordStruct const & coord, double elasticity, double gravity,
    double max_velocity, Vector3 const & velocity, double angular_velocity)
{
    Elasticity = elasticity;
    Gravity = gravity;
    MaxVelocity = max_velocity;
    Coords.X = coord.X;
    Coords.Y = coord.Y;
    Coords.Z = coord.Z;
    Velocity = velocity;

    Vector3 axis = Unit_Vector(Scen->RandomNumber(-65535, 65535),
        Scen->RandomNumber(-65535, 65535), Scen->RandomNumber(-65535, 65535));
    Quaternion q;
    AngularVelocity = Build_Quaternion(q, Normalize(axis), angular_velocity);

    Matrix3D matrix;
    matrix.Make_Identity();
    CurrentAngle = Build_Quaternion(q, matrix);
}

CoordStruct BounceClass::Get_Coord() const
{
    return CoordStruct(Coords.X, Coords.Y, Coords.Z);
}



double BounceClass::Impact_Speed() const
{
    CoordStruct coord(Coords.X, Coords.Y, Coords.Z);
    int height = Coords.Z - Map.Get_Cell_Height(coord);
    if ((Map[coord].Flags & 0x100) && height >= BridgeHeight) {
        height -= BridgeHeight;
    }
    CoordStruct velocity(Velocity.X, Velocity.Y, height * Gravity + Velocity.Z);
    // The Y, X, Z argument order reproduces the original load order (the result is symmetric).
    return Distance(velocity.Y, velocity.X, velocity.Z);
}
