namespace MW3{
	namespace Variables{
		INT MainSelected = 0;
		INT AimbotSelected = 0;
		BOOL open = FALSE;
		BOOL *norecoil = FALSE;
		BOOL *advanceduav = FALSE;
		BOOL *nosway = FALSE;
		BOOL *nospread = FALSE;
		BOOL *crosshair = FALSE;
		BOOL *Aimbot = FALSE;
		BOOL *NoSpread = FALSE;
		char AimbotType[5][32] = {
			"Nearest",
			"Visible",
			"Crosshair",
			"Silent",
			"Smooth"
		};
		char AimbotTags[4][32] = {
			"Neck",
			"Head",
			"Helmet",
			"Spine"
		};
		INT current = 0;
		INT NEAREST = 0, VISIBLE = 1, CROSSHAIR = 2, SILENT = 3, LEGIT = 4;
		INT CurrentAimbot = NEAREST;
		INT j_neck1 = 0, j_head1 = 1, j_helmet1 = 2, j_spine41 = 3;
		INT AimbotTag = j_neck1;
	}
	namespace Structs{
		struct BulletFireParams
		{
			INT MaxEntNum;
			INT ignoreEntIndex;
			FLOAT damageMultiplier;
			INT methodOfDeath; //diedfrom
			INT crackCocaine; //lethal
			D3DXVECTOR3 origStart;
			D3DXVECTOR3 start;
			D3DXVECTOR3 end;
			D3DXVECTOR3 dir;
		};
		class cRefdef
		{
		public:
			char _0x0000[8];
			__int32 iWidth;
			__int32 iHeight;
			FLOAT fov_X;
			FLOAT fov_Y;
			D3DXVECTOR3 EyePos;
			D3DXVECTOR3 ViewAxis[3];
			char _0x0030[19276];
			D3DXVECTOR3 vSomeAngle;
			D3DXVECTOR3 refView;
			D3DXVECTOR3 vOrig;
			D3DXVECTOR3 vOrig2;
			D3DXVECTOR3 refView1;
			char _0x4BB8[12];
			D3DXVECTOR3 refView2;
			char _0x4BD0[11376];
		};
		class cEntity
		{
		public:
			char _0x0000[2];
			short Valid; 
			char _0x0004[16];
			D3DXVECTOR3 mPos; 
			D3DXVECTOR3 ViewAngles; 
			char _0x002C[49];
			BYTE Zooming; 
			BYTE iMenu; //ismenu
			BYTE Pose;
			char _0x0060[12];
			D3DXVECTOR3 mPos2; 
			char _0x0078[24];
			D3DXVECTOR3 ViewAngles1;  
			char _0x009C[64];
			D3DXVECTOR3 mPos3; 
			char _0x00E8[24];
			D3DXVECTOR3 ViewAngles2; 
			char _0x010C[131];
			BYTE WeaponID; 
			char _0x0190[55];
			BYTE State; 
			char _0x01C8[632];
		};
		class CGS
		{
		public:
			char _0x0000[8];
			__int32 screenX; 
			__int32 screenY; 
			char _0x0010[20];
			char gametype[4]; 
			char _0x0028[0x1C];
			char hostName[0x14]; 
			char _0x0058[0x100];
			char mapName[20];  
		}; //debug
		class ClientInfo
		{
		public:
			__int32 Valid; 
			char _0x0004[4];
			__int32 mNum; 
			char mName[20]; 
			char _0x0020[12];
			__int32 mTeam;
			char _0x0030[1040];
		}; //players
		class CG_t
		{
		public:
			char _0x0000[336];
			__int32 cNum; 
			char _0x0154[72];
			__int32 Health1; 
			char _0x01A0[4];
			__int32 Health2; 
			char _0x01A8[0x1D4]; 
			FLOAT weaponSpreadScale; 
			char _0x0380[0xC0];
		}; //health & shit
		class UserCmd_t
		{
		public:
			INT ServerTime; 
			INT Button; 
			INT ViewAngle[3];
			INT WeaponID;
			char _0x0018[4];
			INT moveTonpere; 
			char _0x0020[12];
		};//input
		class clientActive
		{
		public:
			char _0x0000[128];
			INT ServerTime; 
			char _0x0084[24];
			D3DXVECTOR3 vOrigin; 
			char _0x00A8[56];
			D3DXVECTOR3 RefAngles; 
			char _0x00EC[13508]; 
			D3DXVECTOR3 ViewAngles; 
			Structs::UserCmd_t cmds[128]; 
			INT CmdNum;

			Structs::UserCmd_t * GetCmd(INT Index)
			{
				return &cmds[(Index & 0x7F)];
			}

		};
	}
	Structs::cEntity * pSavedTarget2;
	Structs::cRefdef *RefDef;
	Structs::cEntity *Entities[18];
	Structs::ClientInfo *Clients[18];
	Structs::CG_t *cg;
	Structs::CGS *CGS;
	Structs::ClientInfo *LocalClient;
}