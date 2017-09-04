#include "Offsets.h"
namespace MW3{
	namespace Pointers {
		typedef VOID(__cdecl *R_AddCmdDrawText_t)(CONST char *text, INT maxChars, DWORD font, FLOAT x, FLOAT y, FLOAT xScale, FLOAT yScale, FLOAT rotation, CONST FLOAT *color, INT style);
		R_AddCmdDrawText_t R_AddCmdDrawText = (R_AddCmdDrawText_t)Offsets::AddCmdDrawText_t;
		typedef VOID(__cdecl *R_AddCmdDrawStretchPic_t)(FLOAT x, FLOAT y, FLOAT w, FLOAT h, FLOAT s0, FLOAT t0, FLOAT s1, FLOAT t1, CONST FLOAT *color, DWORD material);
		R_AddCmdDrawStretchPic_t R_AddCmdDrawStretchPic = (R_AddCmdDrawStretchPic_t)Offsets::AddCmdDrawStretchPic_t;
		typedef VOID(__cdecl *CG_DrawRotatedPicPhysical)(DWORD ScreenPlacement, FLOAT x, FLOAT y, FLOAT width, FLOAT height, FLOAT angle, CONST FLOAT *color, INT Material);
		CG_DrawRotatedPicPhysical DrawRotated = (CG_DrawRotatedPicPhysical)Offsets::DrawRotatedPicPhysical_t;
		typedef BOOL(*Dvar_GetBool_t)(CONST char *dvarName);
		Dvar_GetBool_t Dvar_GetBool = (Dvar_GetBool_t)Offsets::DvarGetBool;
		typedef BOOL(*CanSeePlayer_)(INT unknown, Structs::cEntity * pEnt, DWORD mask);
		CanSeePlayer_ CanSeePlayer = (CanSeePlayer_)Offsets::CG_CanSeePlayer;
		typedef INT(*Key_IsDown)(INT ClientNum, INT ButtonEnum);
		Key_IsDown Key_Down = (Key_IsDown)Offsets::KeyIsDown;
		typedef INT(*GetTagPos_t)(INT unknown, Structs::cEntity * TheEnt, short tag, FLOAT* out);
		static GetTagPos_t GetTagPos = (GetTagPos_t)Offsets::GetPos;
		typedef INT(*RTGBN) (char* szName);
		RTGBN GetTagByName = (RTGBN)Offsets::RegTag;
		typedef VOID(__cdecl *FireBulletPenetratet)(INT LocalClient, Structs::BulletFireParams* bullet, INT Weapon, INT fuckKnows, Structs::cEntity *cent, INT fuckKnows2, FLOAT* viewOrg, INT fuckKnows3);
		FireBulletPenetratet FireBulletPenetrate = (FireBulletPenetratet)0x8215FB08;
		static VOID(__cdecl*Cbuf_AddText)(INT LocalClient, char* Command) = (VOID(__cdecl*)(INT, char*))0x82287EE0;
	}
}