#ifndef SETTINGSMANAGER_H
#define SETTINGSMANAGER_H

	class SettingsManager
	{
		public:
			static bool showFPSCounter;
			static bool enableVSync;
			static int fpsLimit;

			//static int zoomingSpeed;

		private:
			SettingsManager() {  };

	};

#endif
