#ifndef DR2TYPES_H
#define DR2TYPES_H

// Platform types
#include "TYPES.H"

// Driver 2 system types
typedef short	SHORTVECTOR4[4];

typedef long	LONGVECTOR3[3];
typedef long	LONGVECTOR4[4];

typedef long	LONGQUATERNION[4];

//---------------------------------------------------------------------------------------
// TODO: math types

struct VECTOR2
{
	int vx;
	int vz;
};

struct USVECTOR_NOPAD
{
	u_short vx;
	u_short vy;
	u_short vz;
};

struct VECTOR_NOPAD
{
	int vx;
	int vy;
	int vz;
};

struct SVECTOR_NOPAD
{
	short vx;
	short vy;
	short vz;
};

struct S_XYZ
{
	short x;
	short y;
	short z;
};

struct BVECTOR
{
	char vx;
	char vy;
	char vz;
	char pad;
};

struct UnpaddedHackVector
{
	int vx;
	int vz;
	short vy;
};

struct UnpaddedCharVector
{
	char vx;
	char vy;
	char vz;
};

struct XYPAIR
{
	int x;
	int y;
};

struct SXYPAIR
{
	short x;
	short y;
};

struct XZPAIR
{
	int x;
	int z;
};

struct XYWH
{
	short x;
	short y;
	short w;
	short h;
};

//---------------------------------------------------------------------------------------
// TODO: image types

struct TIMHDR
{
	int magic;
	int flags;
};

struct TIMIMAGEHDR
{
	int len;
	short origin_x;
	short origin_y;
	short width;
	short height;
};

//---------------------------------------------------------------------------------------
// TODO: DR2TYPES

struct BOX
{
	float xmin;
	float ymin;
	float zmin;
	float xmax;
	float ymax;
	float zmax;
};

struct BSPHERE
{
	VECTOR bounding_sphere_mid;
	float bounding_sphere;
};

struct RGB // almost same as CVECTOR
{
	u_char r;
	u_char g;
	u_char b;
	u_char pad;
};

struct PADRECORD
{
	u_char pad;
	u_char analogue;
	u_char run;
};

struct ARC_ENTRY
{
	short offset;
	short length;
};

//---------------------------------------------------------------------------------------
// TODO: TEXTURES.H

struct UV_INFO
{
	u_char u;
	u_char v;
};

struct UV
{
	u_char u0;
	u_char v0;
	u_char u1;
	u_char v1;
	u_char u2;
	u_char v2;
	u_char u3;
	u_char v3;
};

struct TEXTURE_DETAILS
{
	UV coords;
	u_short tpageid;
	u_short clutid;
	char texture_number;
	char texture_page;
};

struct TP
{
	u_int flags;
	u_int offset;
};

struct TEXINF
{
	u_short id;
	u_short nameoffset;
	u_char x;
	u_char y;
	u_char width;
	u_char height;
};

struct TPAN
{
	u_char texture_page;
	u_char texture_number;
};

//---------------------------------------------------------------------------------------
// TODO: ROADS.H

struct DRIVER2_CURVE
{
	int Midx;
	int Midz;
	short start;
	short end;
	short ConnectIdx[4];
	short gradient;
	short height;
	char NumLanes;
	char LaneDirs;
	char inside;
	char AILanes;
};

struct DRIVER2_STRAIGHT
{
	int Midx;
	int Midz;
	u_short length;
	short bing;
	short angle;
	short ConnectIdx[4];
	char NumLanes;
	char LaneDirs;
	char AILanes;
	char packing;
};

struct OLD_DRIVER2_JUNCTION
{
	int Midx;
	int Midz;
	short length;
	short width;
	short angle;
	short ExitIdx[4];
	u_short flags;
};

struct DRIVER2_JUNCTION
{
	short ExitIdx[4];
	u_int flags;
};

typedef struct _sdPlane
{
	short surface;
	short a;
	short b;
	short c;
	int d;
} sdPlane;

struct sdNodePACKED
{
	int angle : 11;
	int dist : 12;
	int offset : 8;
	int node : 1;
};

typedef union _sdNode
{
	int value;
	sdNodePACKED n;
} sdNode;

// really it's UNUSED in Driver 2 - so it's Driver 1 Only
struct ROUTE_DATA
{
	short type;
	short height;
	short objectAngle;
};

struct AREA_LOAD_INFO
{
	int xoffset;
	int zoffset;
};

struct ROAD_MAP_LUMP_DATA
{
	int width;
	int height;
	int unitXMid;
	int unitZMid;
};

//---------------------------------------------------------------------------------------
// TODO: DR2LEVEL.H

struct CELL_OBJECT
{
	VECTOR_NOPAD pos;
	u_char pad;
	u_char yang;
	u_short type;
};

struct CELL_DATA
{
	u_short num;
};

struct PACKED_CELL_OBJECT
{
	USVECTOR_NOPAD pos;
	u_short value;
};

struct CELL_ITERATOR
{
	CELL_DATA* pcd;
	PACKED_CELL_OBJECT* ppco;
	XZPAIR nearCell;
	int use_computed;
};

struct OUT_CELL_FILE_HEADER
{
	int cells_across;
	int cells_down;
	int cell_size;
	int num_regions;
	int region_size;
	int num_cell_objects;
	int num_cell_data;
	int ambient_light_level;
	VECTOR_NOPAD light_source;
};

//---------------------------------------------------------------------------------------
// TODO: MODELS.H

enum ModelShapeFlags
{
	SHAPE_FLAG_SMASH_QUIET		= 0x8,
	SHAPE_FLAG_NOCOLLIDE		= 0x10,
	SHAPE_FLAG_SUBSURFACE		= 0x80,		// grass, dirt, water
	SHAPE_FLAG_ALLEYWAY			= 0x400,	// alleyway
	SHAPE_FLAG_SMASH_SPRITE		= 0x4000,
};

enum ModelFlags2
{
	MODEL_FLAG_ANIMOBJ			= 0x1,
	MODEL_FLAG_MEDIAN			= 0x20,
	MODEL_FLAG_ALLEY			= 0x80,
	MODEL_FLAG_HASROOF			= 0x100,
	MODEL_FLAG_NOCOL_200		= 0x200,
	MODEL_FLAG_BARRIER			= 0x400,
	MODEL_FLAG_SMASHABLE		= 0x800,
	MODEL_FLAG_LAMP				= 0x1000,
	MODEL_FLAG_TREE				= 0x2000,
	MODEL_FLAG_GRASS			= 0x4000,
	MODEL_FLAG_SIDEWALK			= 0x8000,
};

struct COLLISION_PACKET
{
	short type;
	short xpos;
	short ypos;
	short zpos;
	short flags;
	short yang;
	short empty;
	short xsize;
	short ysize;
	short zsize;
};

struct POLYFT4
{
	u_char id;
	u_char texture_set;
	u_char texture_id;
	u_char spare;
	u_char v0;
	u_char v1;
	u_char v2;
	u_char v3;
	UV_INFO uv0;
	UV_INFO uv1;
	UV_INFO uv2;
	UV_INFO uv3;
	RGB color;
};

struct POLYGT4
{
	u_char id;
	u_char texture_set;
	u_char texture_id;
	u_char spare;
	u_char v0;
	u_char v1;
	u_char v2;
	u_char v3;
	u_char n0;
	u_char n1;
	u_char n2;
	u_char n3;
	UV_INFO uv0;
	UV_INFO uv1;
	UV_INFO uv2;
	UV_INFO uv3;
	RGB color;
};

struct PL_POLYFT4
{
	u_char id;
	u_char texture_set;
	u_char texture_id;
	u_char th;
	u_char v0;
	u_char v1;
	u_char v2;
	u_char v3;
	UV_INFO uv0;
	UV_INFO uv1;
	UV_INFO uv2;
	UV_INFO uv3;
};


struct POLYFT3
{
	u_char id;
	u_char texture_set;
	u_char texture_id;
	u_char spare;
	u_char v0;
	u_char v1;
	u_char v2;
	u_char pad;
	UV_INFO uv0;
	UV_INFO uv1;
	UV_INFO uv2;
	UV_INFO pad2;
	RGB color;
};

struct POLYGT3
{
	u_char id;
	u_char texture_set;
	u_char texture_id;
	u_char spare;
	u_char v0;
	u_char v1;
	u_char v2;
	u_char pad;
	u_char n0;
	u_char n1;
	u_char n2;
	u_char pad2;
	UV_INFO uv0;
	UV_INFO uv1;
	UV_INFO uv2;
	UV_INFO pad3;
	RGB color;
};

struct MODEL
{
	u_short shape_flags;
	u_short flags2;
	short instance_number;
	u_char tri_verts;
	unsigned char zBias;
	short bounding_sphere;
	u_short num_point_normals;
	u_short num_vertices;
	u_short num_polys;
	int vertices;
	int poly_block;
	int normals;
	int point_normals;
	int collision_block;

	SVECTOR* pVertex(int i) const
	{
		return (SVECTOR *)(((u_char *)this) + vertices) + i;
	}

	SVECTOR* pNormal(int i) const
	{
		return (SVECTOR *)(((u_char *)this) + point_normals) + i;
	}

	COLLISION_PACKET* pCollisionPacket(int i) const
	{
		return (COLLISION_PACKET *)(((u_char *)this) + collision_block) + i;
	}

	char* pPolyAt(int ofs) const
	{
		return (char *)(((u_char *)this) + poly_block + ofs);		
	}
};

//---------------------------------------------------------------------------------------
// TODO: DEBRIS.H

struct DAMAGED_LAMP
{
	int index;
	char damage;
};

struct DAMAGED_OBJECT
{
	CELL_OBJECT cop;
	char active;
	char damage;
	int rot_speed;
	SVECTOR velocity;
	int vx;
};

struct ANIMATED_OBJECT
{
	int internal_id;
	int model_num;
	char* name;
	char LitPoly;
};

struct SMASHABLE_OBJECT
{
	int modelIdx;
	char* name;
	int sound;
	int volume;
	int pitch;
};

struct GARAGE_DOOR
{
	CELL_OBJECT* cop;
	VECTOR_NOPAD old_pos;
	VECTOR_NOPAD pos;
	short rotation;
	char yang;
};

struct SMOKE
{
	UnpaddedHackVector position;
	UnpaddedCharVector drift;
	UnpaddedCharVector drift_change;
	UnpaddedHackVector final_tail_pos;
	u_char step;
	u_char pos;
	short start_w;
	short final_w;
	char life;
	char halflife;
	u_short flags;
	u_char num;
	u_char t_step;
	short transparency;
};

struct DEBRIS
{
	VECTOR position;
	SVECTOR direction;
	u_short life;
	u_short flags;
	u_short num;
	u_short pos;
	RGB rgb;
	char step;
	char type;
};

struct LEAF
{
	VECTOR position;
	SVECTOR direction;
	u_short life;
	u_short flags;
	u_short num;
	u_short pos;
	RGB rgb;
	char step;
	char type;
	short sin_index1;
	short sin_index2;
	char sin_addition1;
	char sin_addition2;
};

struct TRI_POINT
{
	BVECTOR v0;
	BVECTOR v1;
	BVECTOR v2;
};

struct TRI_POINT_LONG
{
	VECTOR_NOPAD v0;
	VECTOR_NOPAD v1;
	VECTOR_NOPAD v2;
};

struct RAIN_TYPE
{
	VECTOR_NOPAD position;
	SVECTOR oldposition;
};

struct LAMP_STREAK
{
	SXYPAIR light_trails[4];
	int id;
	short clock;
	char set;
};

//---------------------------------------------------------------------------------------
// TODO: DRIVINGGAMES.H

struct TRAILBLAZER_DATA
{
	int x;
	int z;
	short y;
	short rot;
};

struct SMASHED_CONE
{
	char cone;
	u_char active : 7;
	u_char side : 1;
	short rot_speed;
	VECTOR velocity;
};

//---------------------------------------------------------------------------------------
// TODO: DR2COSMETICS.H

struct CAR_COSMETICS
{
	SVECTOR headLight;
	SVECTOR frontInd;
	SVECTOR backInd;
	SVECTOR brakeLight;
	SVECTOR revLight;
	SVECTOR policeLight;
	SVECTOR exhaust;
	SVECTOR smoke;
	SVECTOR fire;
	SVECTOR wheelDisp[4];
	short extraInfo;
	short powerRatio;
	short cbYoffset;
	short susCoeff;
	short traction;
	short wheelSize;
	SVECTOR cPoints[12];
	SVECTOR colBox;
	SVECTOR cog;
	short twistRateX;
	short twistRateY;
	short twistRateZ;
	short mass;
};

//---------------------------------------------------------------------------------------
// TODO: DR2CARS.H

struct CAR_POLY
{
	int vindices;
	int nindices;
	int clut_uv0;
	int tpage_uv1;
	int uv3_uv2;
	short originalindex;
};

struct CAR_MODEL
{
	int numFT3;
	CAR_POLY* pFT3;
	int numGT3;
	CAR_POLY* pGT3;
	int numB3;
	CAR_POLY* pB3;
	SVECTOR* vlist;
	SVECTOR* nlist;
};

struct plotCarGlobals
{
	u_char* primptr;
	OTTYPE* ot;
	u_int intensity;
	u_short* pciv_clut;
	u_int ShineyTPageASL16;
	u_int ShineyClutASL16;
	u_char* damageLevel;
	u_char* shineyTable;
	int ghost;
};

// UNUSED
struct TEX_INFO
{
	char name[8];
	char tset;
	char u;
	char v;
	char w;
	char h;
};

// UNUSED
struct TEXTURE_LOOKUP
{
	TEX_INFO(*Damage[6]);
};

struct DENTUVS
{
	char u3;
};

struct HUBCAP
{
	int Present[4];
	VECTOR Offset[4];
	MATRIX Orientation;
	MATRIX LocalOrientation;
	VECTOR Position;
	VECTOR Direction;
	float Height;
	int Duration;
};

struct BOUND_BOX
{
	int x0;
	int y0;
	int z0;
	int x1;
	int y1;
	int z1;
};

typedef struct _HANDLING_TYPE
{
	char frictionScaleRatio;
	char aggressiveBraking;
	char fourWheelDrive;
	char autoBrakeOn;
} HANDLING_TYPE;

struct BOXINFO
{
	VECTOR vel;
	VECTOR pos;
	int sf;
	int xs;
	int zs;
	int w;
	int h;
	int zb;
	int ypos;
};

//----------------------------------------

struct WHEEL
{
	char susCompression;
	char locked;
	char onGrass;
	u_char surface;
};

struct OrientedBox
{
	VECTOR_NOPAD location;
	SVECTOR_NOPAD radii[3];
	short length[3];
};

typedef struct _HANDLING_DATA
{
	MATRIX where;
	MATRIX drawCarMat;
	LONGVECTOR4 acc;
	LONGVECTOR4 aacc;
	int wheel_speed;
	int speed;
	int direction;
	char gear;
	char changingGear;
	char mayBeColliding;
	char autoBrake;
	WHEEL wheel[4];
	short revs;
	VECTOR shadowPoints[4];
	int front_vel;
	int rear_vel;
	OrientedBox oBox;
} HANDLING_DATA;

union RigidBodyState
{
	long v[13];
	struct {
		LONGVECTOR3 fposition;
		LONGQUATERNION orientation;
		LONGVECTOR3 linearVelocity;
		LONGVECTOR3 angularVelocity;
	} n;
};

typedef struct _APPEARANCE_DATA
{
	SXYPAIR light_trails[4][4];
	CAR_COSMETICS* carCos;
	short old_clock[4];
	char life;
	char coplife;
	short qy;
	short qw;
	char life2;
	char model;
	char palette;

	char needsDenting : 1;
	char flags : 7;			// [A] new: appearance flags, 1,2,3,4 = wheel hubcaps lost

	short damage[6];
} APPEARANCE_DATA;

struct CIV_ROUTE_ENTRY
{
	short dir;
	u_short pathType;
	int distAlongSegment;
	int x;
	int z;
};

struct CIV_STATE
{
	int currentRoad;
	int currentNode;
	CIV_ROUTE_ENTRY* ctrlNode;
	u_char ctrlState;
	u_char trafficLightPhaseId;
	u_char changeLane;
	u_char turnDir;
	char brakeLight;
	u_char oldLane;
	u_char changeLaneCount;
	u_char pad3;
	int turnNode;
	int changeLaneIndicateCount;
	int carPauseCnt;
	int velRatio;
	CIV_ROUTE_ENTRY targetRoute[13];
	CIV_ROUTE_ENTRY* pnode;
	u_char maxSpeed;
	u_char thrustState;
	u_char carMustDie;
	u_char currentLane;
};

struct COP
{
	VECTOR2 targetHistory[2];
	char routeInMemory;
	char justPinged;
	char close_pursuit;
	char dying;
	u_short DistanceToPlayer;
	short desiredSpeed;
	short recalcTimer;
	short stuckTimer;
	short lastRecoverStrategy;
	short recoveryTimer;
	short hiddenTimer;
	short frontLClear;
	short frontRClear;
	short batterTimer;	// [A] new gameplay feature
};

struct LEAD_CAR
{
	char dstate;
	char ctt;
	short targetDir;
	int targetX;
	int targetZ;
	int currentRoad;
	int lastRoad;
	int nextJunction;
	int nextTurn;
	int nextExit;
	int stuckCount;
	int panicCount;
	int recoverTime;
	int roadPosition;
	int roadForward;
	int boringness;
	int avoid;
	int lastTarget;
	int offRoad;
	int width;
	int d;
	int base_Normal;
	int base_Angle;
	int base_Dir;
	int outsideSpoolRegion;
	int direction;
	int lastDirection;
	char takeDamage;
};

enum ECarControlType
{
	CONTROL_TYPE_NONE = 0,				// car is not in the world
	CONTROL_TYPE_PLAYER = 1,			// controlled by player pads
	CONTROL_TYPE_CIV_AI = 2,			// Civilian car. May be a passive cop car with CONTROL_FLAG_COP flag.
	CONTROL_TYPE_PURSUER_AI = 3,		// Police pursuer car. Always chases player
	CONTROL_TYPE_LEAD_AI = 4,			// FreeRoamer AI

	CONTROL_TYPE_CAMERACOLLIDER = 5,	// Used as a camera collider
	CONTROL_TYPE_TANNERCOLLIDER = 6,	// Used as collision box for tanner
	CONTROL_TYPE_CUTSCENE = 7,			// Pretty same as player car but controllled by cutscene. Can be a chase car.
};

enum ECarControlFlags
{
	CONTROL_FLAG_COP = (1 << 0),				// civ car is a cop car
	CONTROL_FLAG_COP_SLEEPING = (1 << 1),		// passive cop flag (roadblocks). Hitting car with that flag results it's activation
	CONTROL_FLAG_WAS_PARKED = (1 << 2),			// car pinged in as parked. Really nothing to do with it
	CONTROL_FLAG_PLAYER_START_CAR = (1 << 3),	// car owned by player
};

typedef struct _CAR_DATA
{
	HANDLING_DATA hd;
	RigidBodyState st;
	APPEARANCE_DATA ap;
	u_char hndType;
	u_char controlType;
	u_char controlFlags;
	char id;
	union {
		char* padid;
		CIV_STATE c;
		COP p;
		LEAD_CAR l;
	} ai;
	int* inform;
	short thrust;
	short felonyRating;
	char handbrake;
	char wheelspin;
	char wasOnGround;
	char lowDetail;
	short wheel_angle;
	u_short totalDamage;
	int lastPad;
} CAR_DATA;

// UNUSED
typedef struct _COP_DATA
{
	int speed;
	int power;
	int min;
	int max;
} MS_COP_DATA;

struct LEAD_PARAMETERS
{
	int tEnd;
	int tAvelLimit;
	int tDist;
	int tDistMul;
	int tWidth;
	int tWidthMul;
	int tWidth80;
	int tWidth80Mul;
	int hEnd;
	int dEnd;
	int hDist;
	int hDistMul;
	int hWidth;
	int hWidthMul;
	int hWidth80;
	int hWidth80Mul;
};

//---------------------------------------------------------------------------------------
// TODO: DR2EVENTS.H

typedef struct _EVENT EVENT;

struct _EVENT
{
	VECTOR position;
	short rotation;
	short timer;
	int* data;
	int* node;
	short flags;
	short radius;
	int model;
	EVENT* next;
};

struct FixedEvent // same as EVENT but different fields
{
	VECTOR position;
	short rotation;
	short active;
	u_short initialRotation;
	u_short finalRotation;
	u_short minSpeed;
	u_short maxSpeed;
	short flags;
	short radius;
	int model;
	EVENT* next;
	char* modelName;
};

struct EventGlobal
{
	int camera;
	int draw;
	EVENT** track;
	EVENT* cameraEvent;
};

enum SpecialCamera
{
	SPECIAL_CAMERA_SET = 0,
	SPECIAL_CAMERA_SET2 = 1,
	SPECIAL_CAMERA_RESET = 2,
	SPECIAL_CAMERA_WAIT = 3,
};

struct MissionTrain
{
	EVENT* engine;
	int* node;
	int cornerSpeed;
	int initialStraightSpeed;
	int finalStraightSpeed;
	int start;
	int startDir;
};

struct Foam
{
	MODEL* model;
	int rotate;
};

struct EventCarriage
{
	short rotation;
	short vel;
};

struct MultiCar
{
	EVENT* event;
	int count;
};

struct Helicopter
{
	int speed;
	short pitch;
	short dp;
	short roll;
	short dr;
	int lastX;
	int lastZ;
	TEXTURE_DETAILS rotorTexture;
	short rotorrot;
	short rotorvel;
	int cleanModel;
	int deadModel;
};

struct Detonator
{
	int timer;
	int count;
};

struct CameraDelay
{
	int delay;
	int type;
};

enum VisType
{
	VIS_INIT = 0,
	VIS_SORT = 1,
	VIS_ADD = 2,
	VIS_NEXT = 3,
};

struct EventCamera
{
	VECTOR position;
	short yAng;
	MATRIX matrix;
	int rotate;
};

enum Station
{
	EVENT_NO_STATION = 0,
	EVENT_APPROACHING = 1,
	EVENT_LEAVING = 2,
};

//---------------------------------------------------------------------------------------
// TODO: MISSION.H

struct SAVED_PLAYER_POS
{
	u_short type;
	short direction;
	int vx;
	int vy;
	int vz;
	u_int felony;
	u_short totaldamage;
	short damage[6];
};

struct SAVED_CAR_POS
{
	char active;
	u_char model;
	u_char palette;
	u_short totaldamage;
	u_short damage[6];
	short direction;
	int vx;
	int vy;
	int vz;
};

struct MISSION_DATA
{
	SAVED_PLAYER_POS PlayerPos;
	SAVED_CAR_POS CarPos[6];
};

typedef struct _MISSION
{
	int id;
	int size;
	int city;
	int time;
	int weather;
	XYPAIR playerStartPosition;
	int playerStartRotation;
	int type;
	short timer;
	short timerFlags;
	int strings;
	MS_COP_DATA cops;
	int msgCarWrecked;
	int msgOutOfTime;
	int msgComplete;
	int region;
	int route;
	int msgDrowned;
	int playerCarModel;
	int playerCarColour;
	int maxDamage;
	int residentModels[5];
	int nCutscenes;
	int title;
	int msgPoliceCar;
	int msgDoorsLocked;
} MS_MISSION;

typedef struct _ROUTE_INFO
{
	int nJunctions;
	char data[1000][4];
	LEAD_PARAMETERS parameters;
} ROUTE_INFO;

enum TARGET_TYPE
{
	Target_Point = 1,
	Target_Car = 2,
	Target_Event = 3,
	Target_Car2 = 4,
	Target_MultiCar = 5
};

struct MULTICAR_DATA
{
	int x;
	int z;
	u_char palette;
	u_char model;
	short rot;
};

typedef struct _TARGET
{
	int type;			// data 0

	union
	{
		MULTICAR_DATA multiCar[5];

		struct
		{
			int target_flags;	// data 1
			int display_flags;	// data 2

			union
			{
				struct
				{
					int posX;				// data 3
					int posZ;				// data 4
					int radius;				// data 5
					int posY;				// data 6
					int height;				// data 7
					int loseTailMessage;	// data 8
					int actionFlag;			// data 9
					int boatX;				// data 10
					int boatZ;				// data 11
				} point;

				struct
				{
					int posX;			// data 3
					int posZ;			// data 4
					int rotation;		// data 5
					int slot;			// data 6
					int model;			// data 7
					int palette;		// data 8
					int type;			// data 9
					int flags;			// data 10
					int cutscene;		// data 11
					int maxDistance;	// data 12
					union
					{
						struct
						{
							int closeMessages;		// data 13
							int farMessages;		// data 14
						} tail;
						struct
						{
							int maxDamage;			// data 13
							int tooFarMessage;		// data 14
							int gettingFarMessage;	// data 15
						} chasing;
					};
				} car;
				
				struct
				{
					int eventId;			// data 3
					union
					{
						VECTOR* eventPos;	// data 4
						int unused[10];
					};
					int loseMessage;		// data 14
				} event;
			};
		};
	};
} MS_TARGET;

assert_sizeof(MS_TARGET, 64);

//---------------------------------------------------------------------------------------

enum FAIL_REASON
{
	FAILED_OUTOFTIME = 0,
	FAILED_CnR_LOSTHIM = 1,
	FAILED_MESSAGESET = 2,
};

typedef enum PAUSEMODE
{
	PAUSEMODE_PAUSE = 0,
	PAUSEMODE_PAUSEP1 = 1,
	PAUSEMODE_PAUSEP2 = 2,
	PAUSEMODE_GAMEOVER = 3,
	PAUSEMODE_COMPLETE = 4,
	PAUSEMODE_PADERROR = 5,
} PAUSEMODE;

struct MR_TIMER
{
	short x;
	short y;
	u_char flags;
	u_char min;
	u_char sec;
	u_char frac;
	int count;
};

struct MR_MISSION
{
	int active;
	int gameover_delay;
	PAUSEMODE gameover_mode;
	short message_timer[2];
	short message_priority[2];
	char(*message_string[2]);
	MR_TIMER timer[2];
	MS_TARGET* CarTarget;
	MS_TARGET* ChaseTarget;
	int PhantomCarId;
	int ChaseHitDelay;
	char* StealMessage;
};

struct MR_THREAD
{
	u_char active;
	u_char player;
	u_int* initial_sp;
	u_int* pc;
	u_int* sp;
};

//---------------------------------------------------------------------------------------
// TODO: SCORES.H

struct SCORE_ENTRY
{
	int time;
	short items;
	char name[6];
};

struct SCORE_TABLES
{
	SCORE_ENTRY GetawayTable[4][2][5];
	SCORE_ENTRY GateRaceTable[4][2][5];
	SCORE_ENTRY CheckpointTable[4][2][5];
	SCORE_ENTRY TrailblazerTable[4][2][5];
	SCORE_ENTRY SurvivalTable[4][1][5];
};

struct PLAYER_SCORE
{
	int time;
	int P2time;
	short items;
	short P2items;
	char name[6];
};

//---------------------------------------------------------------------------------------
// TODO: FELONY.H

struct FELONY_DELAY
{
	short current;
	short maximum;
};

struct FELONY_VALUE
{
	short placid;
	short angry;
};

struct FELONY_DATA
{
	FELONY_DELAY occurrenceDelay[12];
	FELONY_DELAY reoccurrenceDelay[12];
	FELONY_VALUE value[12];
	int pursuitFelonyScale;
};

//---------------------------------------------------------------------------------------
// TODO: PEDEST.H

enum PED_ACTION_TYPE : char
{
	PED_ACTION_WALK = 0,
	PED_ACTION_RUN = 1,
	PED_ACTION_BACK = 2,
	PED_ACTION_GETINCAR = 3,
	PED_ACTION_GETOUTCAR = 4,
	PED_ACTION_TIME = 5,
	PED_ACTION_PRESSBUTTON = 6,
	PED_ACTION_SIT = 7,
	PED_ACTION_CIVWALK = 8,
	PED_ACTION_CIVRUN = 9,
	PED_ACTION_JUMP = 10,
	PED_ACTION_CIVSIT = 11,
	PED_ACTION_COPSTAND = 12,
	PED_ACTION_COPCROUCH = 13,
	PED_ACTION_TALK = 14,
	PED_ACTION_STOPPING = 15,
};

enum PED_MODEL_TYPES : char
{
	TANNER_MODEL = 0,
	OTHER_MODEL = 1,
	OTHER_SPRITE = 2,
	CIVILIAN = 3,
};

typedef void(*pedFunc)(struct PEDESTRIAN* pPed);

typedef struct PEDESTRIAN
{
	PEDESTRIAN* pNext;
	PEDESTRIAN* pPrev;
	pedFunc fpRestState;
	pedFunc fpAgitatedState;
	char padId;
	PED_MODEL_TYPES pedType;
	VECTOR_NOPAD position;
	SVECTOR dir;
	SVECTOR velocity;
	VECTOR target;
	int flags;
	short head_pos;
	short head_rot;
	short index;
	short last_dir;
	short interest;
	char frame1;
	char* motion;
	char speed;
	char doing_turn;
	char finished_turn;
	char seat_index;
	u_char pallet;
	PED_ACTION_TYPE type;
} *LPPEDESTRIAN;

struct CAR_COLLISION_BOX
{
	int min_x;
	int max_x;
	int min_z;
	int max_z;
};

typedef struct SEATED_PEDESTRIANS
{
	int x;
	int z;
	short rotation;
	char index;
	char pad;
} *SEATEDPTR;

typedef struct PEDESTRIAN_ROADS
{
	short pos;
	short north;
	short south;
	short east;
	short west;
} *LPPEDESTRIAN_ROADS;

//---------------------------------------------------------------------------------------
// TODO: GAMESND.H

typedef struct __envsound
{
	u_char type;
	u_char flags;
	VECTOR pos;
	VECTOR pos2;
	int bank;
	int sample;
	int vol;
} envsound;

typedef struct __envsoundtags
{
	int frame_cnt;
	int func_cnt;
	int num_envsnds;
	int envsnd_cnt;
} envsoundtags;

typedef struct __envsoundinfo
{
	VECTOR eff_pos[4];
	VECTOR cam_pos;
	float g[4];
	int thisS[4];
	int playing_sound[4];
	int chan[4];
	u_int flags;
} envsoundinfo;

struct SPEECH_QUEUE
{
	char allowed;
	char chan;
	char is_playing;
	int count;
	char reverb;
	int slot[7];
};

typedef struct __othercarsound
{
	int car;
	int chan;
	char in_use;
	char stopped;
	char idle;
} othercarsound;

typedef struct __bitfield64
{
	int h;
	int l;
} bitfield64;

typedef struct __skidinfo
{
	char chan;
	char sound;
} skidinfo;

typedef struct __horninfo
{
	char on;
	char time;
	char request;
} horninfo;

//---------------------------------------------------------------------------------------
// TODO: ANIMOBJ.H

struct CYCLE_OBJECT
{
	char* name;
	short vx;
	short vy;
	short start1;
	short stop1;
	short speed1;
	short start2;
	short stop2;
	short speed2;
};

//---------------------------------------------------------------------------------------
// TODO: OVERLAY.H

struct COLOUR_BAND
{
	CVECTOR colour;
	int value;
	int flags;
};

typedef struct _PERCENTAGE_BAR
{
	char* tag;
	short xpos;
	short ypos;
	short width;
	short height;
	u_short position;
	u_short max;
	COLOUR_BAND* pColourBand;
	int flags;
	int active;
} PERCENTAGE_BAR, *LPPERCENTAGE_BAR;

//---------------------------------------------------------------------------------------
// TODO: OVERMAP.H

struct COP_SIGHT_DATA
{
	short surroundViewDistance;
	short frontViewDistance;
	short frontViewAngle;
};

struct MAPTEX
{
	short u;
	short w;
	short v;
	short h;
};

struct OVERMAP
{
	int x_offset;
	int y_offset;
	int width;
	int height;
	u_char toptile;
	u_char dummy;
	int scale;
};

//---------------------------------------------------------------------------------------
// TODO: CHEATS.H

struct ACTIVE_CHEATS
{
	u_char cheat1 : 1;
	u_char cheat2 : 1;
	u_char cheat3 : 1;
	u_char cheat4 : 1;
	u_char cheat5 : 1;
	u_char cheat6 : 1;
	u_char cheat7 : 1;
	u_char cheat8 : 1;
	u_char cheat9 : 1;
	u_char cheat10 : 1;
	u_char cheat11 : 1;
	u_char cheat12 : 1;
	u_char cheat13 : 1;
	u_char cheat14 : 1;
	u_char cheat15 : 1;
	u_char cheat16 : 1;
	u_char reserved1;
	u_char reserved2;
};

// UNUSED - Driver 1 cheats
struct CHEATS
{
	int RearWheelSteer;
	int MiniCars;
	int Stilts;
	int LowGravity;
	int Australia;
	int MagicMirror;
};

//---------------------------------------------------------------------------------------
// TODO: REPLAYS.H

struct REPLAY_PARAMETER_BLOCK
{
	int RecordingEnd;
	VECTOR_NOPAD lead_car_start;
	short Lead_car_dir;
	u_char timeofday;
	u_char weather;
};

struct REPLAY_SAVE_HEADER
{
	u_int magic;
	u_char GameLevel;
	u_char GameType;
	u_char reserved1;
	u_char NumReplayStreams;
	u_char NumPlayers;
	u_char RandomChase;
	u_char CutsceneEvent;
	u_char gCopDifficultyLevel;
	MISSION_DATA SavedData;
	ACTIVE_CHEATS ActiveCheats;
	int wantedCar[2];
	int MissionNumber;
	int HaveStoredData;
	int reserved2[6];
};

struct STREAM_SOURCE
{
	u_char type;
	u_char model;
	u_char palette;
	char controlType;
	u_short flags;
	u_short rotation;
	VECTOR_NOPAD position;
	int totaldamage;
	int damage[6];
};

struct REPLAY_STREAM_HEADER
{
	STREAM_SOURCE SourceType;
	int Size;
	int Length;
};

struct REPLAY_STREAM
{
	STREAM_SOURCE SourceType;
	PADRECORD* InitialPadRecordBuffer;
	PADRECORD* PadRecordBuffer;
	PADRECORD* PadRecordBufferEnd;
	u_char playbackrun;
	int length;
	int padCount;
};

typedef struct _PING_PACKET
{
	u_short frame;
	char carId;
	char cookieCount;
} PING_PACKET;

struct PLAYBACKCAMERA
{
	VECTOR_NOPAD position;
	SVECTOR angle;
	int FrameCnt;
	short CameraPosvy;
	short scr_z;
	short gCameraMaxDistance;
	short gCameraAngle;
	u_char cameraview;
	u_char next;
	u_char prev;
	u_char idx;
};

//---------------------------------------------------------------------------------------
// TODO: CUTSCENE.H

struct CUTSCENE_BUFFER
{
	int numResident;
	u_char residentCutscenes[4];
	char(*residentPointers[4]);
	char* currentPointer;
	int bytesFree;
	char buffer[8192];
};

struct CUTSCENE_INFO
{
	u_short offset;
	u_short size;
};

struct CUTSCENE_HEADER
{
	int maxsize;
	CUTSCENE_INFO data[15];
};

//---------------------------------------------------------------------------------------
// TODO: COP_AI.H

struct STOPCOPS
{
	VECTOR_NOPAD pos;
	int radius;
};

struct GAP_INFO
{
	DVECTOR offset;
	char clear;
};

struct ADJACENT_ROAD_INFO
{
	DVECTOR offset;
	GAP_INFO gap;
};

// only "status" is used
struct ROADBLOCK			// [A] causes undefined behaviour
{
	VECTOR position;
	ADJACENT_ROAD_INFO adjacentRoadInfo;
	short RoadToBlock;
	short AdjacentRoad;
	short RoadblockTimer;
	int copRespawnTime;
	char NumCarsNeededForRoad;
	char NumCarsNeededForAdjacentRoad;
	char NumCarsSavedForBlock;
	char DirectionToRoadblock;
	char status;
	char AI_Slot[13];
};

//---------------------------------------------------------------------------------------
// TODO: OBJCOLL.H

struct tRay
{
	LONGVECTOR4 org;
	LONGVECTOR4 dir;
};

struct tRange
{
	int lower;
	int upper;
};

struct tAABB
{
	tRange slab[3];
};


struct TestResult
{
	int depth;
	VECTOR location;
	VECTOR normal;
};

struct BUILDING_BOX
{
	VECTOR pos;
	int xsize;
	int zsize;
	int theta;
	int height;
	int model;
};

struct CDATA2D
{
	VECTOR x;
	VECTOR axis[2];
	VECTOR vel;
	int theta;
	int length[2];
	int dist[2];
	int limit[2];
	int avel;
	int isCameraOrTanner;
};

struct CRET2D
{
	VECTOR hit;
	VECTOR surfNormal;
	int penetration;
	int neverfree;
};

//---------------------------------------------------------------------------------------
// TODO: TUNNELS.H

typedef struct __tunnelcoords
{
	VECTOR p1;
	VECTOR p2;
} tunnelcoords;

typedef struct __tunnelinfo
{
	char num_tunnels;
	char tunnel_cnt;
	tunnelcoords coords[29];
} tunnelinfo;

//---------------------------------------------------------------------------------------
// TODO: BOMBERMAN.H or JOB_FX.H

enum ExplosionType
{
	BIG_BANG = 0,
	LITTLE_BANG = 1,
	HEY_MOMMA = 666,
	BANG_USED = 999,
};

typedef struct _ExOBJECT
{
	int time;
	int speed;
	int hscale;
	int rscale;
	ExplosionType type;
	VECTOR pos;
} EXOBJECT;

struct BOMB
{
	u_char flags;
	u_char active;
	short rot_speed;
	VECTOR position;
	VECTOR velocity;
};

//---------------------------------------------------------------------------------------
// TODO: PLAYER.H

typedef struct _PLAYER
{
	LONGVECTOR4 pos;
	int dir;
	VECTOR* spoolXZ;
	VECTOR cameraPos;
	int cameraDist;
	int maxCameraDist;
	int cameraAngle;
	int headPos;
	int headTarget;
	int viewChange;
	u_char dying;
	u_char upsideDown;
	char onGrass;
	char targetCarId;
	char cameraView;
	u_char headTimer;
	char playerType;
	char worldCentreCarId;
	char playerCarId;
	char cameraCarId;
	char padid;
	char car_is_sounding;
	LONGVECTOR3 camera_vel;
	int snd_cam_ang;
	skidinfo skidding;
	skidinfo wheelnoise;
	horninfo horn;
	int car_sound_timer;
	short revsvol;
	short idlevol;
	LPPEDESTRIAN pPed;
	int crash_timer;
} PLAYER;

//---------------------------------------------------------------------------------------
// TODO: AI.H

typedef struct _EXTRA_CIV_DATA
{
	int surfInd;
	int distAlongSegment;
	short angle;
	u_short ctrlState;
	int thrustState;
	u_char palette;
	u_char controlFlags;
} EXTRA_CIV_DATA;

struct COP_DATA
{
	int autoMaxPowerScaleLimit;
	int autoDesiredSpeedScaleLimit;
	int autoRespawnScaleLimit;
	int autoBatterPlayerTrigger;
	int immortal;
	int roadblockTrigger;
	int cutOffPowerScale;
	int cutOffDistance;
	short trigger[5];
};

enum AIZone
{
	zoneFrnt = 0,
	zoneBack = 1,
	zoneLeft = 2,
	zoneRght = 3,
};

//---------------------------------------------------------------------------------------
// TODO: DRAW.H

// Primitive plot context used in scratchpad
struct _pct
{
	struct DB* current;
	u_short(*ptexture_pages)[128];
	u_short(*ptexture_cluts)[128][32];
	int f4colourTable[32];
	int* polySizes;
	char* primptr;
	OTTYPE* ot;
	u_int clut;
	u_int tpage;
	u_int colour;
	int flags;
	SVECTOR* verts;
	u_int lastTexInfo;
	int scribble[8];
	int model;
};

struct MATRIX2
{
	short m[3][3];
	short computed;
	char null[12];
};

struct MVERTEX
{
	short vx;
	short vy;
	short vz;
	union {
		short val;
		struct {
			u_char u0;
			u_char v0;
		};
	}uv;
};

struct VERTEX
{
	DVECTOR coord;
	UV_INFO uv_coord;
	u_char pad[2];
};

//---------------------------------------------------------------------------------------
// TODO: SPOOL.H

struct Spool
{
	u_short offset;
	u_char connected_areas[2];
	u_char pvs_size;
	u_char cell_data_size[3];
	u_char super_region;
	u_char num_connected_areas;
	u_char roadm_size;
	u_char roadh_size;
};

struct SPOOLQ
{
	u_char type;
	u_char data;
	u_short nsectors;
	u_int sector;
	char* addr;
	void (*func)();
#ifdef _DEBUG
	const char* requestby;
	int requestbyline;
#endif
};

struct SPL_REGIONINFO
{
	u_short region_to_unpack;
	u_short target_barrel_region;
	int nsectors;
	char* cell_addr;
	char* roadm_addr;
};

struct AreaDataStr
{
	u_short gfx_offset;
	u_short model_offset;
	u_short music_offset;
	u_short ambient_offset;
	u_char model_size;
	u_char pad;
	u_char num_tpages;
	u_char ambient_size;
	u_char music_size;
	u_char music_samples_size;
	u_char music_id;
	u_char ambient_id;
};

//---------------------------------------------------------------------------------------
// TODO: FMV.H

struct RENDER_ARG
{
	u_char render;
	u_char credits;
	u_short recap;
};

struct RENDER_ARGS
{
	u_char nRenders;
	u_char subtitle;
	char screenx;
	char screeny;
	RENDER_ARG Args[4];
};

//---------------------------------------------------------------------------------------
// TODO: GLAUNCH.H

enum GAMETYPE
{
	GAME_MISSION = 0,
	GAME_TAKEADRIVE = 1,
	GAME_IDLEDEMO = 2,
	GAME_PURSUIT = 3,
	GAME_GETAWAY = 4,
	GAME_GATERACE = 5,
	GAME_CHECKPOINT = 6,
	GAME_TRAILBLAZER = 7,
	GAME_SURVIVAL = 8,
	GAME_INVALIDGAME1 = 9,
	GAME_REPLAYMISSION = 10,
	GAME_COPSANDROBBERS = 11,
	GAME_CAPTURETHEFLAG = 12,
	GAME_SECRET = 13,
	GAME_CONTINUEMISSION = 14,
	GAME_LOADEDREPLAY = 15,
};

enum GAMEMODE
{
	GAMEMODE_NORMAL = 0,
	GAMEMODE_QUIT = 1,
	GAMEMODE_RESTART = 2,
	GAMEMODE_REPLAY = 3,
	GAMEMODE_DIRECTOR = 4,
	GAMEMODE_NEXTMISSION = 5,
	GAMEMODE_DEMO = 6,
};

struct MISSION_STEP
{
	u_char flags : 3;
	u_char recap : 5;
	u_char data : 7;
	u_char disc : 1;
};

//---------------------------------------------------------------------------------------
// TODO: LEADAI.H

struct MAP_DATA
{
	CAR_DATA* cp;
	VECTOR* base;
	VECTOR* pos;
	VECTOR* vel;
	VECTOR* size;
	int intention;
	int* map;
	int* local;
};

//---------------------------------------------------------------------------------------
// TODO: PAUSE.H

enum EXIT_VALUE
{
	MENU_QUIT_NONE = 0,
	MENU_QUIT_CONTINUE = 1,
	MENU_QUIT_QUIT = 2,
	MENU_QUIT_RESTART = 3,
	MENU_QUIT_DIRECTOR = 4,
	MENU_QUIT_QUICKREPLAY = 5,
	MENU_QUIT_BACKMENU = 6,
	MENU_QUIT_NEXTMISSION = 7,
};

typedef void(*pauseFunc)(int dir);

struct MENU_ITEM;
struct MENU_HEADER;

struct MENU_ITEM
{
	char* Text;
	u_char Type;
	u_char Justify;
	pauseFunc func;
	EXIT_VALUE ExitValue;
	MENU_HEADER* SubMenu;
};

struct MENU_HEADER
{
	char* Title;
	XYWH Bound;
	u_char NumItems;
	MENU_ITEM* MenuItems;
};

//---------------------------------------------------------------------------------------
// TODO: PRES.H

struct OUT_FONTINFO
{
	u_char x;
	u_char y;
	char offx;
	char offy;
	u_char width;
	u_char height;
	u_short pad;
};

struct FONT_DIGIT
{
	char xOffset;
	char width;
};

struct SHADOWHDR
{
	u_int num_common_verts;
	u_short num_verts_total;
	u_short num_polys_total;
	u_short vert_offsets[4];
	u_short nverts[4];
	u_short npolys[4];
	u_int(*poly_block[4]);
	SVECTOR* vertices;
};

//---------------------------------------------------------------------------------------
// TODO: SHADOW.H

struct TYRE_TRACK
{
	u_char type;
	u_char shade;
	u_char shade_type;
	u_char surface;
	SVECTOR_NOPAD p1;
	SVECTOR_NOPAD p2;
	SVECTOR_NOPAD p3;
	SVECTOR_NOPAD p4;
};

//---------------------------------------------------------------------------------------
// TODO: SOUND.H

struct CHANNEL_DATA
{
	SpuVoiceAttr attr;
	u_char loop;
	u_char locked;
	u_short time;
	int samplerate;
	char player;
	int srcvolume;
	int volumeScale;
	u_short srcpitch;
	u_short dopplerScale;
	int cameradist;
	int lastcameradist;
	VECTOR* srcposition;
	VECTOR position;
	LONGVECTOR3* srcvelocity;
};

struct SAMPLE_DATA
{
	u_int address;
	u_int length;
	u_int loop;
	u_int samplerate;
};

//---------------------------------------------------------------------------------------
// TODO: SYSTEM.H

struct DRAW_MODE
{
	short x1;
	short y1;
	short x2;
	short y2;
	short width;
	short height;
	short framex;
	short framey;
};

enum CDTYPE
{
	CDTYPE_NODISC = 0,
	CDTYPE_SHELLOPEN = 1,
	CDTYPE_DISCERROR = 2,
	CDTYPE_WRONGDISC = 3,
	CDTYPE_CORRECTDISC = 4,
};

enum CITYTYPE
{
	CITYTYPE_DAY = 0,
	CITYTYPE_NIGHT = 1,
	CITYTYPE_MULTI_DAY = 2,
	CITYTYPE_MULTI_NIGHT = 3,
};

//---------------------------------------------------------------------------------------
// TODO: PAD.H

struct DUPLICATION
{
	char* buffer;
	int size;
};

typedef struct MAPPING
{
	u_short button_lookup[16];
	u_short swap_analog;
	u_short reserved1;
} *LPMAPPING;

typedef struct PAD
{
	u_char active;
	u_char type;
	u_char dualshock;
	u_char reserved1;
	u_short direct;
	u_short dirnew;
	char diranalog[4];
	u_short mapped;
	u_short mapnew;
	char mapanalog[4];
	MAPPING mappings;
	u_char alarmShakeCounter;
	u_char asd;
	u_char sdf;
	u_char dfg;
	u_char delay;
	u_char port;
	u_char state;
	u_char dsactive;
	u_char* shakeptr;
	u_char motors[2];
	u_char shake_type;
	u_char vibrate;
} *LPPAD;

//---------------------------------------------------------------------------------------
// TODO: LOADSAVE.H

struct GAME_SAVE_HEADER
{
	u_int magic;
	u_char gMissionLadderPos;
	u_char pad1;
	u_char pad2;
	u_char pad3;
	MISSION_DATA SavedData;
	int reserved[8];
};

struct CONFIG_SAVE_HEADER
{
	u_int magic;
	int gMasterVolume;
	int gMusicVolume;
	int gSoundMode;
	int gVibration;
	int gCopDifficultyLevel;
	int gFurthestMission;
	MAPPING PadMapping[2];
	SCORE_TABLES ScoreTables;
	int PALAdjustX;
	int PALAdjustY;
	int NTSCAdjustX;
	int NTSCAdjustY;
	int gSubtitles;
	ACTIVE_CHEATS AvailableCheats;
	int reserved[6];
};

#endif // DR2TYPES_H