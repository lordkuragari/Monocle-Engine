#include "../../Monocle.h"
#include "../../Tween.h"
#include "../../Sprite.h"

using namespace Monocle;

namespace Marian
{
	class LevelEditor : public Editor
	{
	public:
		LevelEditor();
		void Update();
		bool isOn;
		Sprite *selectedSprite;
		int selectedSpriteIndex;
	};

	class TitleScene : public Scene
	{
	public:
		void Begin();
		void End();
		void Update();
	};

}