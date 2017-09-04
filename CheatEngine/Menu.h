#include "Functions.h"
namespace MW3{
	namespace Menu{
			INT CenterX = 1280 / 2;
			INT CenterY = 720 / 2;
			FLOAT middle = 1065.0f;
			FLOAT center = 100.0f;
			FLOAT bottom = 700.0f;
			FLOAT centerM = 80.0f;
			FLOAT centerM2 = 75.0f;
			FLOAT MenuCenterX = CenterX - (300.0f / 2);
			FLOAT MenuCenterY = CenterY - (300.0f / 2);
		class Engine{
		public:
			static VOID EngineExtras(){
				//toggle text
				Functions::Utils::DrawText("Press \x11 To Toggle Menu", 100, 700, 0.5f, (FLOAT*)&menu_color);
				//doheart
				Functions::Utils::DrawShadowText("CheatEngine", 975, 125, title_size, (FLOAT*)&menu_color);
			}
			static VOID InitEngine(){				
				//menu
				Functions::Utils::drawMaterial(menu_pos_x - 190, center + 5, 100, 245, 0, L_black2);
				Functions::Utils::drawMaterial(menu_pos_x - 200, center, 400, 400, 0, L_black);
				Functions::Utils::drawMaterial(menu_pos_x - 200, center - 25, 400, 25, 0, (FLOAT*)&menu_color);
				Functions::Utils::drawMaterial(menu_pos_x - 200, center + 400, 400, 5, 0, (FLOAT*)&menu_color);
				Functions::Utils::DrawText("CheatEngine | Beta Build", menu_pos_x - 185, center - 2, 0.5f, white);
				//debug/credits
				Functions::Utils::drawMaterial(menu_pos_x - 200, center + 450, 400, 75, 0, L_black);
				Functions::Utils::drawMaterial(menu_pos_x - 200, center + 425, 400, 25, 0, (FLOAT*)&menu_color);
				Functions::Utils::drawMaterial(menu_pos_x - 200, center + 525, 400, 5, 0, (FLOAT*)&menu_color);
				Functions::Utils::DrawText("CheatEngine 5.0 | Build Date: 8/02/2017 | Private Loot", menu_pos_x - 186, center + 450, 0.4f, white);
			}
			static VOID addMenu(char title[32], INT index, INT selected){
				Functions::Utils::DrawText(title, menu_pos_x - 185, center + (35*index), 0.6f, (selected == index ? (FLOAT*)&menu_color : white));
			}
			static VOID addSubMenu(char title[32], INT index, INT selected, INT menu){
				Functions::Utils::DrawText(title, menu_pos_x - 75, 130 + (25 * index), 0.4f, (selected == index ? (FLOAT*)&menu_color : white));
			}
			static VOID addBoolOption(char name[32], INT index, INT selected, INT menu, BOOL enabled){
				Functions::Utils::DrawText(name, menu_pos_x - 75, 130 + (25 * index), 0.4f, (selected == index ? (FLOAT*)&menu_color : white));
				Functions::Utils::DrawText((enabled?"ON":"OFF"), menu_pos_x + 175, 130 + (25 * index), 0.4f, (enabled?green:red));
			}
			static VOID addComboOption(char name[32], INT index, INT selected, INT menu, char options[5][32], INT option){
				Functions::Utils::DrawText(name, menu_pos_x - 75, 130 + (25 * index), 0.4f, (selected == index ? (FLOAT*)&menu_color : white));
				Functions::Utils::DrawText(options[option], menu_pos_x + 150, 130 + (25 * index), 0.4f, white);
			}
		};
	}
}