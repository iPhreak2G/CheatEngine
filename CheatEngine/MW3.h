#include "Menu.h"
#pragma once

XINPUT_STATE XInputState;
short currentButton, previousButton;
#define buttonHit(button) ((currentButton & ~previousButton) & button)

namespace MW3{
	VOID Binds() {
		XInputGetState(0, &XInputState);
		previousButton = currentButton;
		currentButton = ~XInputState.Gamepad.wButtons & 0xFBFF;

		if (buttonHit(XINPUT_GAMEPAD_RIGHT_THUMB) && buttonHit(XINPUT_GAMEPAD_DPAD_LEFT)) {		
			Variables::open = !Variables::open;
		}

		if (Variables::open) {
			if (buttonHit(XINPUT_GAMEPAD_DPAD_LEFT)) {
				if (Variables::current == 0)
				{
					Variables::current = 3;
				}
				else
				{
					if (Variables::current == 1)
					{
						Variables::current = 0;
					}
					else
					{
						if (Variables::current == 2)
						{
							Variables::current = 1;
						}
						else
						{
							if (Variables::current == 3)
							{
								Variables::current = 2;
							}
									
						}
					}
				}
			}

			if (buttonHit(XINPUT_GAMEPAD_DPAD_RIGHT)) {
				if (Variables::current == 0)
				{
					Variables::current = 1;
				}
				else
				{
					if (Variables::current == 1)
					{
						Variables::current = 2;
					}
					else
					{
						if (Variables::current == 2)
						{
							Variables::current = 3;
						}
						else
						{
							if (Variables::current == 3)
							{
								Variables::current = 2;
							}
									
						}
					}
				}
			}

			if (buttonHit(XINPUT_GAMEPAD_DPAD_UP)) {
				if (Variables::current == 0)
				{
					Variables::MainSelected--;
					if (Variables::MainSelected == -1) {
						Variables::MainSelected = 5 - 1;
					}
				}
				else
				{
					if (Variables::current == 1)
					{
						Variables::AimbotSelected--;
						if (Variables::AimbotSelected == -1) {
							Variables::AimbotSelected = 4 - 1;
						}
					}
				}
			}

			if (buttonHit(XINPUT_GAMEPAD_DPAD_DOWN)) {
				if (Variables::current == 0)
				{
					Variables::MainSelected++;
					if (Variables::MainSelected == 5) {
						Variables::MainSelected = 0;
					}
				}
						
			}

			if (buttonHit(XINPUT_GAMEPAD_X)) {
				if (Variables::current == 1)
					{
						if (Variables::AimbotSelected == 1) {
							switch (Variables::CurrentAimbot) {
							case 0:
								Variables::CurrentAimbot = Variables::VISIBLE;
								break;
							case 1:
								Variables::CurrentAimbot = Variables::CROSSHAIR;
								break;
							case 2:
								Variables::CurrentAimbot = Variables::SILENT;
								break;
							case 3:
								Variables::CurrentAimbot = Variables::LEGIT;
								break;
							case 4:
								Variables::CurrentAimbot = Variables::NEAREST;
								break;
							default:
								Variables::CurrentAimbot = Variables::LEGIT;
								break;
							}
						}
						else if (Variables::AimbotSelected == 2) {
							switch (Variables::AimbotTag) {
							case 0:
								Variables::AimbotTag = Offsets::j_head;
								break;
							case 1:
								Variables::AimbotTag = Offsets::j_helmet;
								break;
							case 2:
								Variables::AimbotTag = Offsets::j_spine4;
								break;
							case 3:
								Variables::AimbotTag = Offsets::j_neck;
								break;
							default:
								Variables::AimbotTag = Offsets::j_spine4;
								break;
							}
						}															
					}					
			}
		}
	}
	VOID Toggles()
	{
		if (*Variables::norecoil){
			*(INT*)Offsets::NoRecoil = 0x60000000;
		}else{
			*(INT*)Offsets::NoRecoil = 0x4BFA0395;
		}
		if (*Variables::advanceduav){
			*(INT*)Offsets::Radar = 0x3B800001;
		}else{
			*(INT*)Offsets::Radar = 0x557C87FE;
		}
		if (*Variables::nosway)	{
			*(INT*)Offsets::WeaponSway = 0x60000000;
			*(INT*)Offsets::ZommingSway = 0x60000000;
		}else{
			*(INT*)Offsets::WeaponSway = 0x4BFFEA61;
			*(INT*)Offsets::ZommingSway = 0x4BFFFB9D;
		}
		if (*Variables::nospread){
			*(INT*)Offsets::NoSpread1 = 0x60000000;
			*(INT*)Offsets::NoSpread2 = 0x60000000;
		}else{
			*(INT*)Offsets::NoSpread1 = 0x4BFEAE2D;
			*(INT*)Offsets::NoSpread2 = 0x4BFA1789;
		}
	}
	VOID Menu_Hook()
	{
		Binds();
		Toggles();
		Menu::Engine::EngineExtras();
		if (menu_pos_x > -400){
			Menu::Engine::InitEngine();
			Menu::Engine::addMenu("OFFHOST", 1, Variables::current);
			Menu::Engine::addMenu("AIMBOT", 2, Variables::current);
			Menu::Engine::addMenu("VISUALS", 3, Variables::current);
			Menu::Engine::addMenu("CLIENTS", 4, Variables::current);
			switch(Variables::current){
				case 0:
					Menu::Engine::addBoolOption("No Recoil", 1, Variables::MainSelected, 0, *Variables::norecoil);
					Menu::Engine::addBoolOption("Radar", 2, Variables::MainSelected, 0, *Variables::advanceduav);
					Menu::Engine::addBoolOption("No Sway", 3, Variables::MainSelected, 0, *Variables::nosway);
					Menu::Engine::addBoolOption("No Spread", 4, Variables::MainSelected, 0, *Variables::nospread);
					Menu::Engine::addBoolOption("Draw Crosshair", 5, Variables::MainSelected, 0, *Variables::crosshair);
					break;
				case 1:
					Menu::Engine::addBoolOption("Enabled", 1, Variables::AimbotSelected, 1, *Variables::Aimbot);
					Menu::Engine::addComboOption("Type		->", 2, Variables::AimbotSelected, 1, Variables::AimbotType, Variables::CurrentAimbot);
					Menu::Engine::addComboOption("Target	->", 3, Variables::AimbotSelected, 1, Variables::AimbotTags, Variables::AimbotTag);
					//TODO: finish
					break;
			}
		}

	}
	bool reset = false;
	HRESULT CL_DrawTextHook(CONST char *text, INT maxChars, DWORD font, FLOAT x, FLOAT y, FLOAT xScale, FLOAT yScale, CONST FLOAT *color, INT style)
	{
		INT CenterX = 1280 / 2;
		INT CenterY = 720 / 2;

		FLOAT rotation = 0;
		Pointers::R_AddCmdDrawText(text, maxChars, font, x, y, xScale, yScale, rotation, color, style);

		if (Pointers::Key_Down(0, 0x12))
		{
			
		}
		else
		{
			LastFrameAimKey = false;
		}
		
		
		if (title_size < 1.0f && !reset) {
			title_size += 0.005f;
			if (title_size >= 1.0f) {
				reset = true;
			}
		}
		if (title_size > 0.3f && reset) {
			title_size -= 0.005f;
			if (title_size <= 0.3f) {
				reset = false;
			}
		}


		if (Variables::open) {
			if (menu_pos_x < 640) {
				menu_pos_x += 160;
			}		
		}
		else {
			if (menu_pos_x > 0) {
				menu_pos_x += 160;
			}
		}
		if(menu_pos_x >= 1500){
			menu_pos_x = -400;
		}
		// hooks
		Menu_Hook();
		Functions::Utils::DoAimbot();
		Functions::Utils::Info(Functions::Utils::getOptionInfo(Variables::current, Variables::MainSelected));

		return S_OK;
	}
	DWORD XamInputGetStateHook(DWORD dwUserIndex, DWORD dwFlags, PXINPUT_STATE pState) {
		DWORD r = XInputGetStateEx(dwUserIndex, dwFlags, pState);
		//button functions (autoshoot, auto aim, jitter, tbag, etc)
		return r;
	}
	namespace Hook {
		VOID MW3()
		{			
			PatchInJump((DWORD *)0x82309108, (DWORD)CL_DrawTextHook, false);
			PatchInJump((DWORD*)0x8257FE8C, (DWORD)XamInputGetStateHook, false);
			HookFunctionStart((DWORD *)0x8216D998, (PDWORD)SaveStubPacket, (DWORD)Functions::Utils::CL_WritePackethk);
		}
	}	
}
