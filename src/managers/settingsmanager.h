#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

	#include "keyboardcontrols.h"

	class SettingsManager
	{
		public:
			static bool showFPSCounter;
			static bool enableVSync;
			static int fpsLimit;
			//static KeyboardControls keyboardControls;

		private:
			SettingsManager() {  };

	};

#endif
