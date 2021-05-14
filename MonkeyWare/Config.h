
struct rainbow
{
	float main_red_ = 1.;
	float main_green_ = 0;
	float main_blue_ = 0;
	float main_color_random = 0.0;
	float main_speed = -5.0;
};
rainbow r_c;

namespace initrainbow
{
	void load_rainbow()
	{
		static float c_colr[3];
		struct tick_
		{
			DWORD tick_count = 0;
			DWORD tick_count2 = 0;
		};
		tick_ t_c_;
		ImGui::ColorConvertRGBtoHSV(r_c.main_red_, r_c.main_green_, r_c.main_blue_, c_colr[0], c_colr[1], c_colr[2]);
		if (GetTickCount() - t_c_.tick_count >= 1)
		{
			if (t_c_.tick_count != t_c_.tick_count)
			{
				c_colr[0] += 0.001f * r_c.main_speed;
				t_c_.tick_count2 = t_c_.tick_count;
			}
			t_c_.tick_count = GetTickCount();
		}
		if (c_colr[0] < 0.0f) c_colr[0] += 1.0f;
		ImGui::ColorConvertHSVtoRGB(c_colr[0], c_colr[1], c_colr[2], r_c.main_red_, r_c.main_green_, r_c.main_blue_);
	}
}

struct fontinit
{
	ImFont* Viper;
	ImFont* ElectricPlug;
	ImFont* Tahoma;
};
fontinit g_font;

bool ColorBar(const char* label, const ImVec2& size_arg)
{

}
namespace csgo
{
	struct rainbowbar
	{
		void cs_go_rainbow()
		{
			ColorBar("", ImVec2(200.f, 2.f));
		}
		void cs_go_rainbow_animated()
		{
		}
	};
	rainbowbar r_csgo_;
	rainbowbar* r_csgo = new rainbowbar;

}
namespace Draw
{
	typedef struct
	{
		DWORD R;
		DWORD G;
		DWORD B;
		DWORD A;
	}RGBA;

	class RBGAColr
	{
	public:
		RGBA red = { 255,0,0,255 };
		RGBA Magenta = { 255,0,255,255 };
		RGBA yellow = { 255,255,0,255 };
		RGBA grayblue = { 128,128,255,255 };
		RGBA green = { 128,224,0,255 };
		RGBA darkgreen = { 0,224,128,255 };
		RGBA brown = { 192,96,0,255 };
		RGBA pink = { 255,168,255,255 };
		RGBA DarkYellow = { 216,216,0,255 };
		RGBA SilverWhite = { 236,236,236,255 };
		RGBA purple = { 144,0,255,255 };
		RGBA Navy = { 88,48,224,255 };
		RGBA skyblue = { 0,136,255,255 };
		RGBA graygreen = { 128,160,128,255 };
		RGBA blue = { 0,96,192,255 };
		RGBA orange = { 255,128,0,255 };
		RGBA peachred = { 255,80,128,255 };
		RGBA reds = { 255,128,192,255 };
		RGBA darkgray = { 96,96,96,255 };
		RGBA Navys = { 0,0,128,255 };
		RGBA darkgreens = { 0,128,0,255 };
		RGBA darkblue = { 0,128,128,255 };
		RGBA redbrown = { 128,0,0,255 };
		RGBA purplered = { 128,0,128,255 };
		RGBA greens = { 0,255,0,255 };
		RGBA envy = { 0,255,255,255 };
		RGBA black = { 0,0,0,255 };
		RGBA gray = { 128,128,128,255 };
		RGBA white = { 255,255,255,255 };
		RGBA blues = { 30,144,255,255 };
		RGBA lightblue = { 135,206,250,160 };
		RGBA Scarlet = { 220, 20, 60, 160 };
		RGBA white_ = { 255,255,255,200 };
		RGBA gray_ = { 128,128,128,200 };
		RGBA black_ = { 0,0,0,200 };
		RGBA red_ = { 255,0,0,200 };
		RGBA Magenta_ = { 255,0,255,200 };
		RGBA yellow_ = { 255,255,0,200 };
		RGBA grayblue_ = { 128,128,255,200 };
		RGBA green_ = { 128,224,0,200 };
		RGBA darkgreen_ = { 0,224,128,200 };
		RGBA brown_ = { 192,96,0,200 };
		RGBA pink_ = { 255,168,255,200 };
		RGBA darkyellow_ = { 216,216,0,200 };
		RGBA silverwhite_ = { 236,236,236,200 };
		RGBA purple_ = { 144,0,255,200 };
		RGBA Blue_ = { 88,48,224,200 };
		RGBA skyblue_ = { 0,136,255,200 };
		RGBA graygreen_ = { 128,160,128,200 };
		RGBA blue_ = { 0,96,192,200 };
		RGBA orange_ = { 255,128,0,200 };
		RGBA pinks_ = { 255,80,128,200 };
		RGBA Fuhong_ = { 255,128,192,200 };
		RGBA darkgray_ = { 96,96,96,200 };
		RGBA Navy_ = { 0,0,128,200 };
		RGBA darkgreens_ = { 0,128,0,200 };
		RGBA darkblue_ = { 0,128,128,200 };
		RGBA redbrown_ = { 128,0,0,200 };
		RGBA purplered_ = { 128,0,128,200 };
		RGBA greens_ = { 0,255,0,200 };
		RGBA envy_ = { 0,255,255,200 };
		RGBA glassblack = { 0, 0, 0, 160 };
		RGBA GlassBlue = { 65,105,225,80 };
		RGBA glassyellow = { 255,255,0,160 };
		RGBA glass = { 200,200,200,60 };
		RGBA Plum = { 221,160,221,160 };
		RGBA neongreen = { 0, 255, 229,0 };

	};
	RBGAColr Color;
	void ToggleButtons(const char* str_id, bool* v)
	{
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight();
		float width = height * 1.0f;
		float radius = height * 1.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(0, 100, 255, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
		else
			col_bg = *v ? IM_COL32(0, 100, 255, 255) : IM_COL32(218, 218, 218, 255);

		//draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.7f);
		//draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), 4, IM_COL32(255, 255, 255, 255));
		//draw_list->AddCircle(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), 4, ImColor(0, 0, 0));
		//draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .4 - 1.8), ImColor(0, 0, 0, 200), str_id);
		//draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .5 - 1.5), ImColor(255, 255, 255, 255), str_id);
	}
	std::string string_To_UTF8(const std::string& str)
	{
		int nwLen = ::MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);
		wchar_t* pwBuf = new wchar_t[nwLen + 1];
		ZeroMemory(pwBuf, nwLen * 2 + 2);
		::MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.length(), pwBuf, nwLen);
		int nLen = ::WideCharToMultiByte(CP_UTF8, 0, pwBuf, -1, NULL, NULL, NULL, NULL);
		char* pBuf = new char[nLen + 1];
		ZeroMemory(pBuf, nLen + 1);
		::WideCharToMultiByte(CP_UTF8, 0, pwBuf, nwLen, pBuf, nLen, NULL, NULL);
		std::string retStr(pBuf);
		delete[]pwBuf;
		delete[]pBuf;
		pwBuf = NULL;
		pBuf = NULL;
		return retStr;
	}
	// Drawings for custom menus + Toggle Button's / Checkboxes ETC
	void RegularRGBText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void ShadowRGBText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImColor(0, 0, 0, 240)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void OutlinedRBGText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 30 / 30.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 2), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 30 / 30.0)), utf_8_2.c_str());
		//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), utf_8_2.c_str());
	}
	void RegularText(int x, int y, RGBA* color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), utf_8_2.c_str());
	}
	void NeonRBGText(int x, int y, ImColor color, const char* str)
	{
		ImFont a;
		std::string utf_8_1 = std::string(str);
		std::string utf_8_2 = string_To_UTF8(utf_8_1);
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y - 1), ImColor(64, 255, 0), utf_8_2.c_str());
		ImGui::GetOverlayDrawList()->AddText(ImVec2(x + 1, y + 1), ImColor(64, 255, 0), utf_8_2.c_str());
		//ImGui::GetOverlayDrawList()->AddText(ImVec2(x, y + 1), ImGui::ColorConvertFloat4ToU32(ImVec4(1 / 255.0, 1 / 255.0, 1 / 255.0, 255 / 255.0)), utf_8_2.c_str());
	}
	void BackgroundRBGOutline(int x, int y, int w, int h, ImColor color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0, thickness);
	}
	void BackgroundOutline(int x, int y, int w, int h, RGBA* color, int thickness)
	{
		ImGui::GetOverlayDrawList()->AddRect(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0, thickness);
	}
	void TitleBar(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), 0, 0);
	}
	void TitleBarGraident(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0)), (color->R / 255.0, color->G / 255.0, color->B / 255.0, color->A / 255.0), 0, 0);
	}
	void BackgroundLowOpacity(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.20f)), 0);
	}

	void BackgroundLowRounded(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.20f)), 6);
	}

	void BackgroundRBGGradient(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void BackgroundFilledRBG(int x, int y, int w, int h, ImColor color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color)), 0, 0);
	}

	void SelectedFilled(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 0.40f)), 0, 0);
	}

	void BackgroundFilled(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0);
	}

	void BackgroundFilledRound(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilled(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 6);
	}

	void BackgroundGradient(int x, int y, int w, int h, RGBA* color)
	{
		ImGui::GetOverlayDrawList()->AddRectFilledMultiColor(ImVec2(x, y), ImVec2(x + w, y + h), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), ImGui::ColorConvertFloat4ToU32(ImVec4(color->R / 255.0, color->G / 255.0, color->B / 255.0, 1.00f)), 0, 0);
	}

	// checkbox's / buttons / toggle buttons / sliders

	struct color {
		float a, r, g, b;
		color() = default;
		color(float r, float g, float b, float a = 255) {
			this->r = r;
			this->g = g;
			this->b = b;
			this->a = a;
		}
		color(uint32_t color) {
			this->a = (color >> 24) & 0xff;
			this->r = (color >> 16) & 0xff;
			this->g = (color >> 8) & 0xff;
			this->b = (color & 0xff);
		}
		color from_uint(uint32_t uint) {
			return color(uint);
		}

		static color black(float a = 255) { return { 0, 0, 0, a }; }
		static color white(float a = 255) { return { 255, 255, 255, a }; }
		static color red(float   a = 255) { return { 255, 0, 0, a }; }
		static color green(float a = 255) { return { 0, 255, 0, a }; }
		static color blue(float  a = 255) { return { 0, 0, 255, a }; }
	};

	void ModernToggle(const char* str_id, bool* v)
	{
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = ImGui::GetFrameHeight();
		float width = height * 1.55f;
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(145 + 20, 211, 68 + 20, 255) : IM_COL32(218 - 20, 218 - 20, 218 - 20, 255);
		else
			col_bg = *v ? IM_COL32(145, 211, 68, 255) : IM_COL32(218, 218, 218, 255);

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.10f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius - 1.f, ImColor(255, 255, 255, 255));

	}


	struct colors
	{
		struct red_type
		{
			ImColor main_lightred = { 255, 0, 0 };
			ImColor main_darkred = { 105, 0, 14 };
			ImColor main_velvetred = { 184, 46, 64 };
			ImColor main_cardinalred = { 189, 32, 53 };
			ImColor main_red = { 219, 9, 37 };
		};
		red_type rt_;
		struct grey_type
		{
			ImColor main_grey = { 92, 92, 91 };
			ImColor main_light_grey = { 161, 161, 161 };
			ImColor main_dark_grey = { 44, 45, 46 };
		};
		grey_type gt_;
		struct blue_type
		{
			ImColor main_purple_blue = { 81, 0, 255 };
			ImColor main_blue = { 28, 70, 255 };
		};
		blue_type bt_;
		ImColor main_rainbow = { r_c.main_red_, r_c.main_green_, r_c.main_blue_ };
		struct green_type
		{
			ImColor main_limegreen = { 81, 255, 0 };
			ImColor main_darkgreen = { 2, 133, 0 };
			ImColor main_lightgreen = { 13, 214, 26 };
			ImColor main_yellowgreen = { 145, 255, 0 };
		};
		green_type grt_;
	};
	colors colortype;
	colors ct;
	colors* color_m = new colors;
	colors* col = new colors;

	// how to use.
	// Draw::color_m->rt_.main_red | Draw::col->rt_.main_red | Draw::ct.rt_.main_red | Draw::colortype.rt_.main_red

	namespace easy_colr
	{
		ImColor main_lightred = { 255, 0, 0 };
		ImColor main_darkred = { 105, 0, 14 };
		ImColor main_velvetred = { 184, 46, 64 };
		ImColor main_cardinalred = { 189, 32, 53 };
		ImColor main_red = { 219, 9, 37 };
		ImColor main_grey = { 92, 92, 91 };
		ImColor main_light_grey = { 161, 161, 161 };
		ImColor main_dark_grey = { 44, 45, 46 };
		ImColor main_purple_blue = { 81, 0, 255 };
		ImColor main_blue = { 28, 70, 255 };
		ImColor main_rainbow = { r_c.main_red_, r_c.main_green_, r_c.main_blue_ };
	}

	static ImVec2 padding{ 5, 10 };
	static ImVec2 real_padding{ 12, 17 };
	static int last_widget = -1;

	static color to_color(ImVec4 in)
	{
		return color(in.x * 255, in.y * 255, in.z * 255, in.w * 255);
	}

	static color to_color(float* in)
	{
		return color(in[0], in[1], in[2], in[3]);
	}

	static ImVec4 to_vec(color in)
	{
		return ImVec4(in.r / 255, in.g / 255, in.b / 255, in.a / 255);
	}

	static void to_float(color in, float* out)
	{
		out[0] = in.r;
		out[1] = in.g;
		out[2] = in.b;
		out[3] = in.a;
	}

	static void apply_padding(ImVec2 pad)
	{
		pad.x += ImGui::GetCursorPosX();
		pad.y += ImGui::GetCursorPosY();
		ImGui::SetCursorPos(pad);
	}

	static void change_pos(ImVec2 pos) // resets to top of menu
	{
		ImGui::SetCursorPos(pos);
	}

	static void push_text(ImFont* font, std::string text, color clr = {}, ImVec2 pos = {})
	{
		if (pos.x != 0 && pos.y != 0)
		{
			ImGui::SetCursorPosY(pos.y); // center vertically
			ImGui::SetCursorPosX(pos.x); // positon left
		}

		if (clr.r && clr.g && clr.b)
			ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(clr.r / 255, clr.g / 255, clr.b / 255, 1));

		ImGui::PushFont(font);
		ImGui::Text(text.c_str());
		ImGui::PopFont();

		if (clr.r && clr.g && clr.b)
			ImGui::PopStyleColor();
		last_widget = 0;
	}

	static int page_number = 1;
	static std::vector<bool> toggles = { false, true, false, false, false };
	static void push_button_tab(ImFont* font, std::string text, bool transpearent, ImVec2 pos = {}, ImVec2 size = {}, color clr = {}, color active_clr = {}, int page = -1)
	{
		if (pos.x != 0 && pos.y != 0)
		{
			ImGui::SetCursorPosY(pos.y); // center vertically
			ImGui::SetCursorPosX(pos.x); // positon left
		}

		if (page >= 0 && toggles[page])
			ImGui::PushStyleColor(ImGuiCol_Text, to_vec(active_clr));
		else if (clr.r && clr.g && clr.b)
			ImGui::PushStyleColor(ImGuiCol_Text, to_vec(clr));

		if (transpearent)
		{
			ImGui::PushStyleColor(ImGuiCol_Button, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
			ImGui::PushStyleColor(ImGuiCol_FrameBg, ImVec4(0.0f, 0.0f, 0.0f, 0.00f));
		}

		ImGui::PushFont(font);
		auto temp = ImGui::Button(text.c_str(), size);
		ImGui::PopFont();

		if (temp)
		{
			toggles = { false, false, false, false, false };
			toggles[page] = 1 - toggles[page];
			page_number = page;
		}

		if (transpearent)
			ImGui::PopStyleColor(4);

		if ((clr.r && clr.g && clr.b) || toggles[page])
			ImGui::PopStyleColor();
		last_widget = 1;
	}
	ImFont* InVisible;

	static void ToggleButton(const char* str_id, bool* v, color clr, ImFont* font = InVisible)
	{
		apply_padding(padding);
		ImVec2 p = ImGui::GetCursorScreenPos();
		ImDrawList* draw_list = ImGui::GetWindowDrawList();

		float height = (ImGui::GetFontSize() + ImGui::GetStyle().FramePadding.y * 2) - 7;
		float width = height * 1.55f;
		float radius = height * 0.50f;

		if (ImGui::InvisibleButton(str_id, ImVec2(width, height)))
			*v = !*v;
		ImU32 col_bg;
		if (ImGui::IsItemHovered())
			col_bg = *v ? IM_COL32(clr.r, clr.g - 40, clr.b - 40, clr.a) : IM_COL32(133, 133, 133, 255); // if true/false and hovered
		else
			col_bg = *v ? IM_COL32(clr.r, clr.g, clr.b, clr.a) : IM_COL32(166, 166, 166, 255); // if true/false and not hovered

		draw_list->AddRectFilled(p, ImVec2(p.x + width, p.y + height), col_bg, height * 0.5f);
		draw_list->AddCircleFilled(ImVec2(*v ? (p.x + width - radius) : (p.x + radius), p.y + radius), radius, IM_COL32(255, 255, 255, 255));
		ImGui::PushFont(font);
		draw_list->AddText(ImVec2((p.x + width - radius) + 20, (p.y + radius) - ImGui::CalcTextSize(str_id).y * .5 - 1.5), ImColor(255, 255, 255, 255), str_id);
		ImGui::PopFont();
		last_widget = 2;
	}
}
