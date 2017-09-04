#include "Pointers.h"
namespace MW3{
	namespace Functions{
		class Utils{
		public:			
			//generic drawing
			static VOID setText(CONST char* text, FLOAT x, FLOAT y, FLOAT xScale, DWORD fontz)
			{
				Pointers::R_AddCmdDrawText(text, 0x7FFFFFFF, fontz, x, y, xScale, xScale, 0, orange, 0);
			}
			static VOID DrawText(CONST char* text, FLOAT x, FLOAT y, FLOAT xScale, CONST FLOAT *color)
			{
				Pointers::R_AddCmdDrawText(text, 0x7FFFFFFF, Offsets::bigFont, x, y, xScale, xScale, 0, color, 0);
			}
			static VOID DrawBox(FLOAT x, FLOAT y, FLOAT Width, FLOAT Height, CONST FLOAT *colorInside, CONST FLOAT *colorOutside)
			{
				DrawRect(x - (Width / 2), y - Height, Width, Height, colorInside);

				DrawRect(x - (Width / 2), y - Height, Width, 2, colorOutside);//*TOP-LINE
				DrawRect(x - (Width / 2), y, Width, 2, colorOutside);//BOTTOM
				DrawRect(x - (Width / 2), y - Height, 2, Height, colorOutside);//LEFT
				DrawRect(x + (Width / 2), y - Height, 2, Height, colorOutside);//RIGHT
			}
			static VOID DrawCornerBox(FLOAT x, FLOAT y, FLOAT Width, FLOAT Height, CONST FLOAT *color)
			{
				INT WidthThird = Width / 4;
				INT HeightThird = WidthThird;

				/* draw eight shadowlines */
				//topleft 
				DrawRect(x - Width / 2 - (1), y - (1), WidthThird + 2, 3, black); //h
				DrawRect(x - Width / 2 - (1), y - (1), 3, HeightThird + 2, black); //v

																				   //topright
				DrawRect((x + Width / 2) - WidthThird - (1), y - (1), WidthThird + 2, 3, black); //h
				DrawRect(x + Width / 2 - (1), y - (1), 3, HeightThird + 2, black); //v

																				   //bottom left
				DrawRect(x - Width / 2 - (1), y + Height - 4, WidthThird + 2, 3, black); //h
				DrawRect(x - Width / 2 - (1), (y + Height) - HeightThird - 4, 3, HeightThird + 2, black);//v

																										 //bottom right
				DrawRect((x + Width / 2) - WidthThird - (1), y + Height - 4, WidthThird + 2, 3, black);//h
				DrawRect(x + Width / 2 - (1), (y + Height) - HeightThird - 4, 3, HeightThird + 3, black); //v

																										  /* draw eight lines */
																										  //topleft 
				DrawRect(x - Width / 2, y, WidthThird, 1, color); //h
				DrawRect(x - Width / 2, y, 1, HeightThird, color); //v

																   //topright
				DrawRect((x + Width / 2) - WidthThird, y, WidthThird, 1, color); //h
				DrawRect(x + Width / 2, y, 1, HeightThird, color); //v

																   //bottom left
				DrawRect(x - Width / 2, y + Height - 3, WidthThird, 1, color); //h
				DrawRect(x - Width / 2, (y + Height) - HeightThird - 3, 1, HeightThird, color);//v

																							   //bottom right
				DrawRect((x + Width / 2) - WidthThird, y + Height - 3, WidthThird, 1, color);//h
				DrawRect(x + Width / 2, (y + Height) - HeightThird - 3, 1, HeightThird + 1, color); //v			
			}
			static VOID DrawBox2(FLOAT x, FLOAT y, FLOAT Width, FLOAT Height, CONST FLOAT *color)
			{
				DrawRect(x, y, Width, Height, color);

				DrawRect(x, y - Height, Width, 1, black);//*TOP-LINE
				DrawRect(x, y, Width, 1, black);//BOTTOM
				DrawRect(x, y, 1, Height, black);//LEFT
				DrawRect(x + Width, y, 1, Height, black);//RIGHT
			}
			static VOID DrawShadowText(CONST char* text, FLOAT x, FLOAT y, FLOAT xScale, CONST FLOAT *color)
			{
				DrawText(text, x - 1, y, xScale, black);
				DrawText(text, x + 1, y, xScale, black);
				DrawText(text, x, y - 1, xScale, black);
				DrawText(text, x, y + 1, xScale, black);

				DrawText(text, x, y, xScale, color);
			}
			static VOID setText2(CONST char* text, FLOAT x, FLOAT y, FLOAT xScale, DWORD fontz)
			{
				Pointers::R_AddCmdDrawText(text, 0x7FFFFFFF, fontz, x, y, xScale, xScale, 0, white, 0);
			}
			static VOID DrawRect(FLOAT x, FLOAT y, FLOAT weight, FLOAT Height, CONST FLOAT *colors)
			{
				Pointers::R_AddCmdDrawStretchPic(x, y, weight, Height, 0, 0, 1, 1, colors, Offsets::White);
			}
			//esp
			static char *getWeaponname(BYTE iD)
			{
				INT ids = (INT)iD;
				switch (ids)
				{
				case 3:
					return "Riot Shield";
				case 4:
					return "Riot Shield Jugg";
				case 5:
					return ".44 Magnum";
				case 6:
					return "USP 45";
				case 7:
					return "USP 45 Jugg";
				case 8:
					return "Desert Eagle";
				case 9:
					return "MP412";
				case 10:
					return "MP412 Jugg";
				case 11:
					return "P99";
				case 12:
					return "Five Seven";
				case 13:
					return "FMG9";
				case 14:
					return "Skorpion";
				case 15:
					return "MP9";
				case 16:
					return "G18";
				case 17:
					return "MP5";
				case 18:
					return "PM-9";
				case 19:
					return "P90";
				case 20:
					return "PP90M1";
				case 21:
					return "UMP45";
				case 22:
					return "MP7";
				case 23:
					return "AK-47";
				case 24:
					return "M16A4";
				case 25:
					return "M4A1";
				case 26:
					return "FAD";
				case 27:
					return "ACR 6.8";
				case 28:
					return "Type 95";
				case 29:
					return "MK14";
				case 30:
					return "SCAR-L";
				case 31:
					return "G36C";
				case 32:
					return "CM-901";
				case 33:
					return "Unknow";
				case 34:
					return "M320 GLM";
				case 35:
					return "RPG-7";
				case 36:
					return "SMAW";
				case 37:
					return "Stinger";
				case 38:
					return "Javelin";
				case 39:
					return "XM25";
				case 40:
					return "Dragunov";
				case 41:
					return "MSR";
				case 42:
					return "Barrett .50";
				case 43:
					return "RSASS";
				case 44:
					return "AS50";
				case 45:
					return "L118A";
				case 46:
					return "KSG 12";
				case 47:
					return "Model 1887";
				case 48:
					return "striker";
				case 49:
					return "AA-12";
				case 50:
					return "USAS 12";
				case 51:
					return "SPAS-12";
				case 52:
					return "M60E4 Jugg";
				case 53:
					return "M60E4";
				case 54:
					return "MK46";
				case 55:
					return "PKP Pecheneg";
				case 56:
					return "L86 LSW";
				case 57:
					return "MG36";
				default:
					return "Unknow";
				}
			}
			static BOOL wS2(FLOAT *flLocation, FLOAT *flOut)
			{

				if (!bInit)
				{
					DWORD LEPD = *(DWORD*)Offsets::refdef_s;
					RefDef = (Structs::cRefdef*)LEPD;

					bInit = true;
				}

				Vector vLocal;

				VectorSubtract(flLocation, RefDef->EyePos, vLocal);
				FLOAT flZ = DotProduct(RefDef->ViewAxis[0], vLocal);
				FLOAT flX = DotProduct(RefDef->ViewAxis[1], vLocal);
				FLOAT flY = DotProduct(RefDef->ViewAxis[2], vLocal);

				if (flZ >= 0.0f)
				{
					FLOAT flTmp = 1.0f / flZ;

					flOut[0] = (1.0f - (flX / RefDef->fov_X * flTmp)) * ((FLOAT)1280 / 2);
					flOut[1] = (1.0f - (flY / RefDef->fov_Y * flTmp)) * ((FLOAT)720 / 2);
					return true;
				}
				return false;
			}
			static INT VectorToScreenDistance(FLOAT *flOrigin1, FLOAT *flOrigin2)
			{
				Vector vScreen1, vScreen2;
				wS2(flOrigin1, vScreen1);
				wS2(flOrigin2, vScreen2);
				return (INT)ScreenDistance(vScreen1, vScreen2);
			}
			static BOOL GetTagPosReg(Structs::cEntity* pEnt, char* szTag, FLOAT* flOut) {
				WORD wTag = Pointers::GetTagByName(szTag);
				if (!wTag)
					return false;

				Pointers::GetTagPos(0, pEnt, wTag, flOut);

				return true;
			}
			static VOID drawMaterial(FLOAT x, FLOAT y, FLOAT width, FLOAT height, FLOAT angle, CONST FLOAT *color) {
				Pointers::DrawRotated(Offsets::DrawRotated_R3, x, y, width, height, angle, color, Offsets::White);
			}
			static VOID drawRectangle(FLOAT x, FLOAT y, FLOAT width, FLOAT height, FLOAT lineWidth, CONST FLOAT *color) {
				drawMaterial(x, y, width, lineWidth, 0.0f, color);
				drawMaterial(x + width, y, lineWidth, height, 0.0f, color);
				drawMaterial(x, y + height - lineWidth, width, lineWidth, 0.0f, color);
				drawMaterial(x, y, lineWidth, height, 0.0f, color);
			}
			//struct utils
			static Structs::ClientInfo *getClientbyIDx(INT id)
			{
				DWORD CclientInfo = ((DWORD)RefDef + 0x924DC);

				return (Structs::ClientInfo*)(CclientInfo + ((INT)0x594 * id));
			}
			static Structs::CGS *getCgs()
			{
				DWORD cgs_ptr = *(DWORD*)Offsets::cgs_t;

				return (Structs::CGS*)cgs_ptr;
			}
			static Structs::CG_t *getCg()
			{
				DWORD cg_ptr = *(DWORD*)Offsets::CG_t;

				return (Structs::CG_t*)cg_ptr;
			}
			static Structs::clientActive *getCA()
			{
				DWORD ca_ptr = *(DWORD*)Offsets::clientActive_t;

				return (Structs::clientActive*)ca_ptr;
			}
			static Structs::cEntity * GetEntitybyIdx(INT x)
			{
				DWORD cent_ptr = *(DWORD*)Offsets::centity_t;

				return (Structs::cEntity*)(cent_ptr + ((INT)0x1EC * x));

			}
			static Structs::cEntity* GetTargetByCrosshair()
			{
				FLOAT ScreenX = (FLOAT)1280 / 2.0f;
				FLOAT ScreenY = (FLOAT)720 / 2.0f;
				FLOAT Nearest = (FLOAT)INT_MAX;
				FLOAT PosX = 0.0f, PosY = 0.0f;

				Structs::cEntity* pRet = NULL;
				getStructs();

				Vector vOut;

				for (INT i = 0; i < 18; i++)
				{
					if (i == cg->cNum)
						continue;

					if ((Entities[i]->Valid) && (Entities[i]->State & 1))
					{
						if (strcmp(CGS->gametype, "dm") == 0)
						{
							if (Functions::Utils::wS2(Entities[i]->mPos2, vOut))
							{
								PosX = vOut.x > ScreenX ? vOut.x - ScreenX : ScreenX - vOut.x;
								PosY = vOut.y > ScreenY ? vOut.y - ScreenY : ScreenY - vOut.y;

								FLOAT Temp = sqrt(PosX*PosX + PosY*PosY);

								if (Temp > Nearest)
									continue;

								pRet = Entities[i];
								Nearest = Temp;
							}
						}
						else
						{
							if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
							{
								if (Functions::Utils::wS2(Entities[i]->mPos2, vOut))
								{
									PosX = vOut.x > ScreenX ? vOut.x - ScreenX : ScreenX - vOut.x;
									PosY = vOut.y > ScreenY ? vOut.y - ScreenY : ScreenY - vOut.y;

									FLOAT Temp = sqrt(PosX*PosX + PosY*PosY);

									if (Temp > Nearest)
										continue;

									pRet = Entities[i];
									Nearest = Temp;
								}
							}
						}
					}
				}
				return pRet;
			}
			static Structs::cEntity* GetVisibleTarget()
			{
				FLOAT ScreenX = (FLOAT)1280 / 2.0f;
				FLOAT ScreenY = (FLOAT)720 / 2.0f;
				FLOAT Nearest = (FLOAT)INT_MAX;
				FLOAT PosX = 0.0f, PosY = 0.0f;

				Structs::cEntity* pRet = NULL;
				getStructs();

				Vector vOut;

				for (INT i = 0; i < 18; i++)
				{
					if (i == cg->cNum)
						continue;

					if ((Entities[i]->Valid) && (Entities[i]->State & 1))
					{
						if (strcmp(CGS->gametype, "dm") == 0)
						{
							if (Pointers::CanSeePlayer(0, Entities[i], 0x280F823))
							{
								PosX = vOut.x > ScreenX ? vOut.x - ScreenX : ScreenX - vOut.x;
								PosY = vOut.y > ScreenY ? vOut.y - ScreenY : ScreenY - vOut.y;

								FLOAT Temp = sqrt(PosX*PosX + PosY*PosY);

								pRet = Entities[i];
								Nearest = Temp;
							}
						}
						else
						{
							if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
							{
								if (Pointers::CanSeePlayer(0, Entities[i], 0x280F823))
								{
									PosX = vOut.x > ScreenX ? vOut.x - ScreenX : ScreenX - vOut.x;
									PosY = vOut.y > ScreenY ? vOut.y - ScreenY : ScreenY - vOut.y;

									FLOAT Temp = sqrt(PosX*PosX + PosY*PosY);

									pRet = Entities[i];
									Nearest = Temp;
								}
							}
						}
					}
				}
				return pRet;
			}
			//cheats
			static VOID justChots()
			{
				*(INT*)Offsets::NoRecoil = 0x60000000;
				*(INT*)Offsets::Radar = 0x3B800001;
				*(INT*)Offsets::WeaponSway = 0x60000000;
				*(INT*)Offsets::ZommingSway = 0x60000000;
			}
			//Variables
			static VOID getStructs()
			{
				DWORD ref_ptr = *(DWORD*)Offsets::refdef_s;
				RefDef = (Structs::cRefdef*)ref_ptr;
				cg = (Structs::CG_t*)Functions::Utils::getCg();
				CGS = (Structs::CGS*)Functions::Utils::getCgs();

				DWORD cent_ptr = *(DWORD*)Offsets::centity_t;

				for (INT i = 0; i < 18; i++)
					Entities[i] = (Structs::cEntity*)(cent_ptr + ((INT)0x1EC * i));

				for (INT i = 0; i < 18; i++)
					Clients[i] = (Structs::ClientInfo*)Functions::Utils::getClientbyIDx(i);

				for (INT i = 0; i < 18; i++)
				{
					if (cg->cNum == i)
					{
						MyTeam = Clients[i]->mTeam;
						break;
					}
				}
			}
			static BOOL CanKillPlayer(INT Player, D3DXVECTOR3 PlayerOrigin)
			{
				Structs::BulletFireParams bp;

				bp.MaxEntNum = 2046;
				bp.ignoreEntIndex = cg->cNum;
				bp.damageMultiplier = 1.0f;
				bp.methodOfDeath = 2;
				bp.origStart = RefDef->EyePos;
				bp.start = RefDef->EyePos;
				bp.end = PlayerOrigin;

				D3DXVECTOR3 dir;
				VectorSubtract(PlayerOrigin, RefDef->EyePos, dir);
				VectorNormalize(dir);
				VectorCopy(dir, bp.dir);

				//AngleVectors(vectoangles(PlayerOrigin - RefDef->EyePos), bp.dir, NULL, NULL);

				Pointers::FireBulletPenetrate(0, &bp, Entities[cg->cNum]->WeaponID, 0, Entities[cg->cNum], 0xFFFFFFFF, RefDef->EyePos, false);

				return (bp.ignoreEntIndex == Player && bp.damageMultiplier > 0.0f);
			}
			static DWORD RandomInt(DWORD Minimum, DWORD Maximum)
			{
				return rand() % (Maximum - Minimum + 1) + Minimum;
			}
			static VOID DoAimbot()
			{
				if (Pointers::Dvar_GetBool("cl_ingame"))
				{
					DWORD pd = *(DWORD*)Offsets::clientActive_t;
					Structs::clientActive *cmdInput = (Structs::clientActive*)pd;
					Structs::UserCmd_t* cmd = cmdInput->GetCmd(cmdInput->CmdNum);
					Structs::clientActive *Ca = Functions::Utils::getCA();

					Structs::UserCmd_t* oldCmd = cmdInput->GetCmd(cmdInput->CmdNum - 1);

					getStructs();
					Structs::cEntity * Target = NULL;
					Structs::clientActive * ca = NULL;
					ca = (Structs::clientActive*)Functions::Utils::getCA();
					Vector vAngles;

					FLOAT objectDistance = 0.f;
					FLOAT flClosestDistance = (FLOAT)INT_MAX;

					D3DXVECTOR3 vHead, vBestHead;
					short mTag = *(short*)Offsets::j_neck;
					if (Variables::AimbotTag == Variables::j_neck1)
					{
						mTag = *(short*)Offsets::j_neck;
					}
					else if (Variables::AimbotTag == 1)
					{
						mTag = *(short*)Offsets::j_head;
					}
					else if (Variables::AimbotTag == 3)
					{
						mTag = Pointers::GetTagByName("j_helmet");
					}
					else if (Variables::AimbotTag == Variables::j_spine41)
					{
						mTag = Pointers::GetTagByName("j_spine4");
					}

					

					if (*Variables::Aimbot)
					{
						if (Variables::CurrentAimbot == Variables::NEAREST)
						{
							for (INT i = 0; i < 18; i++)
							{
								if (i == cg->cNum)
									continue;

								if ((Entities[i]->Valid) && (Entities[i]->State & 1))
								{
									if (strcmp(CGS->gametype, "dm") == 0)
									{
										objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

										Target = Entities[i];
										Pointers::GetTagPos(0, Target, mTag, vHead);

										if (objectDistance < flClosestDistance)
										{
											vBestHead = vHead;
											flClosestDistance = objectDistance;
										}
									}
									else
									{
										if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
										{
											objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

											Target = Entities[i];
											Pointers::GetTagPos(0, Target, mTag, vHead);

											if (objectDistance < flClosestDistance)
											{
												vBestHead = vHead;
												flClosestDistance = objectDistance;
											}
										}
									}
								}
							}
						}
						else if (Variables::CurrentAimbot == Variables::VISIBLE)
						{
							for (INT i = 0; i < 18; i++)
							{
								if (i == cg->cNum)
									continue;

								if ((Entities[i]->Valid) && (Entities[i]->State & 1))
								{
									if (strcmp(CGS->gametype, "dm") == 0)
									{
										if (Pointers::CanSeePlayer(0, Entities[i], 0x280F803))
										{
											objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

											Target = Entities[i];
											Pointers::GetTagPos(0, Target, mTag, vHead);

											if (objectDistance < flClosestDistance)
											{
												vBestHead = vHead;
												flClosestDistance = objectDistance;
											}
										}
									}
									else
									{
										if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
										{
											if (Pointers::CanSeePlayer(0, Entities[i], 0x280F803))
											{
												objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

												Target = Entities[i];
												Pointers::GetTagPos(0, Target, mTag, vHead);

												if (objectDistance < flClosestDistance)
												{
													vBestHead = vHead;
													flClosestDistance = objectDistance;
												}
											}
										}
									}
								}
							}
						}
						else if (Variables::CurrentAimbot == Variables::CROSSHAIR)
						{
							if (LastFrameAimKey && pSavedTarget2)
								Target = pSavedTarget2;
							else
								Target = GetTargetByCrosshair();
						}
						else if (Variables::CurrentAimbot == Variables::SILENT)
						{
							for (INT i = 0; i < 18; i++)
							{
								if (i == cg->cNum)
									continue;

								if ((Entities[i]->Valid) && (Entities[i]->State & 1))
								{
									if (strcmp(CGS->gametype, "dm") == 0)
									{
										if (CanKillPlayer(i, Entities[i]->mPos))//if (Pointers::CanSeePlayer(0, Entities[i], 0x280F803))
										{
											objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

											Target = Entities[i];
											Pointers::GetTagPos(0, Target, mTag, vHead);

											if (objectDistance < flClosestDistance)
											{
												vBestHead = vHead;
												flClosestDistance = objectDistance;
											}
										}
									}
									else
									{
										if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
										{
											if (CanKillPlayer(i, Entities[i]->mPos))
											{
												objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);

												Target = Entities[i];
												Pointers::GetTagPos(0, Target, mTag, vHead);

												if (objectDistance < flClosestDistance)
												{
													vBestHead = vHead;
													flClosestDistance = objectDistance;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
			static VOID CL_WritePackethk(INT a1)
			{
				if (Pointers::Dvar_GetBool("cl_ingame"))
				{
					DWORD pd = *(DWORD*)Offsets::clientActive_t;
					Structs::clientActive *cmdInput = (Structs::clientActive*)pd;
					Structs::UserCmd_t* cmd = cmdInput->GetCmd(cmdInput->CmdNum);
					Structs::clientActive *Ca = Functions::Utils::getCA();

					Structs::UserCmd_t* oldCmd = cmdInput->GetCmd(cmdInput->CmdNum - 1);
					Vector vMyAngles = Ca->ViewAngles;

					*oldCmd = *cmd;
					oldCmd->ServerTime--;

					//spinbot, autoshoot, angle functions, etc
				}

				SaveStubPacket(a1);
			}
			static INT ClosetsClient()
			{
				getStructs();
				FLOAT objectDistance = 0.f;
				FLOAT flClosestDistance = (FLOAT)INT_MAX;
				INT ClosestClient = -1;

				for (INT i = 0; i < 18; i++)
				{
					if (i == cg->cNum)
						continue;

					if ((Entities[i]->Valid) && (Entities[i]->State & 1))
					{
						if (strcmp(CGS->gametype, "dm") == 0)
						{
							objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);
							if (objectDistance < flClosestDistance)
							{
								flClosestDistance = objectDistance;
								ClosestClient = i;
							}
						}
						else
						{
							if (Clients[i]->mTeam != Clients[cg->cNum]->mTeam)
							{
								objectDistance = GetDistance(RefDef->EyePos, Entities[i]->mPos);
								if (objectDistance < flClosestDistance)
								{
									flClosestDistance = objectDistance;
									ClosestClient = i;
								}
							}
						}
					}
				}

				return ClosestClient;
			}
			static char* getOptionInfo(INT menu, INT option){
				char* ret;
				char buffer[3096];
				if(menu == 0){
					switch(option){
						case 1:
							sprintf(buffer, "Remove all recoil from your %s allowing you\nto fire with pen-point accuracy", getWeaponname(Entities[cg->cNum]->WeaponID));
							break;
						case 2:
							sprintf(buffer, "Enable enemy positions to be visible on the\n minimap in the top left corner");
							break;
						case 3:
							sprintf(buffer, "Remove the weapon sway when aiming and\nhip-firing your %s", getWeaponname(Entities[cg->cNum]->WeaponID));
							break;
						case 4:
							sprintf(buffer, "Remove the the bullet spread at long distances\nto increase accuracy", getWeaponname(Entities[cg->cNum]->WeaponID));
							break;
					}
				}
				ret = buffer;
				return ret;
			}
			static VOID Info(char* text)
			{				
				if (menu_pos_x > -400) {
					Functions::Utils::DrawText(text, menu_pos_x-186, 575, 0.5f, white);
				}
					
			}
		};			
	}
}