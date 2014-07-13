#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <string>
#include <GLAux.h>
#pragma comment(lib, "GLAux.lib")

namespace Game
{
	class CTexture
	{
		private:
			bool _bAllowDraw;
			AUX_RGBImageRec* _pTexture;
			unsigned int texture[1];
			float _fTextureMin_x, _fTextureMax_x, _fTextureMin_y, _fTextureMax_y;
		public:
			CTexture();
			~CTexture();
			void Draw(float min_x, float max_x, float min_y, float max_y);
			void LoadTexture(const char* FileName);
			void AllowLoading(bool State);
			float GetWidth(void);
			float GetHeight(void);
			bool isMouseOnTexture(float mouse_x, float mouse_y);
			bool GetState(void);
			void AlphaProcess(void);
	};
};

#endif