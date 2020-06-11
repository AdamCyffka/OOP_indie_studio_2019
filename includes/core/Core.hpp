/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** Core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#define FULLSCREEN true

#include <irrlicht.h>
#include "CameraTravelManager.hpp"
#include "Menu.hpp"
#include "Score.hpp"
#include "Game.hpp"
#include "Select.hpp"
#include "LoadMap.hpp"
#include "Splash.hpp"
#include "Music.hpp"
#include "GameCore.hpp"
#include "Sounds.hpp"
#include "GameSettings.hpp"
#include "Controls.hpp"
#include "GameControls.hpp"
#include "GameSounds.hpp"
#include "global.hpp"

class Load;
class Save;
class Intro;
class Help;
class Credits;
class Pause;
class MyEventReceiver;
class GameCore;

class Core {
    public:
        Core();
	    ~Core() = default;
	    int run();

        enum layerMenuState {
            menuIntro,
			menuMain,
			menuSounds,
            menuGameSettings,
            menuControls,
			menuSplash,
			menuHelp,
            menuCredits,
			menuSelect,
            menuScore,
            menuSave,
            menuLoad,
		};

        enum layerGameState {
            gamePause,
            gameGame,
            gameSounds,
            gameControls,
            gameSave,
		};

        enum gameState {
        	menu,
        	game
        };

        void pauseCase();
        void gameCase();
        void gameSoundsCase();
        void gameControlsCase();
        void introCase();
        void menuCase();
        void selectCase();
        void scoreCase();
        void soundsCase();
        void controlsCase();
        void gameSettingsCase();
        void helpCase();
        void creditsCase();
        void splashCase();
        void saveCase();
        void loadCase();

        void changeFullscreen();
        void start();
        void restartDevice(bool fullscreen);

        bool getFullscreen() const;
        layerMenuState getLState();
        layerGameState getLGState();
		gameState getGState();
		GameSettings *getGameSettings() const;
		void setGameSettings(GameSettings *gameSettings);
		void setMenu(Menu *);
		Menu *getMenu() const;
		void setSelect(Select *);
        Select *getSelect() const;
        void setControls(Controls *);
        Controls *getControls() const;
		void setHelp(Help *help);
		Help *getHelp() const;
		void setSave(Save *save);
		Save *getSave() const;
		void setLoad(Load *load);
		Load *getLoad() const;
		void setScore(Score *);
        Score *getScore() const;
		void setSounds(Sounds *sounds);
		Sounds *getSounds() const;
		void setGameCore(GameCore *);
		GameCore *getGameCore() const;
		void setGame(Game *);
        Game *getGame() const;
		Credits *getCredits() const;
		void setCredits(Credits *credits);
        void setLoadMap(LoadMap *);
        LoadMap *getLoadMap() const;
		Map *getMap() const;
		void setMusicEngine(Music *);
		Music *getMusicEngine() const;
		Splash *getSplash() const;
		void setIntro(Intro *);
		Intro *getIntro();
		void setInput(Input *);
		Input *getInput();
		GameControls *getGameControls() const;
		void setGameControls(GameControls *gameControls);
		GameSounds *getGameSounds() const;
		void setGameSounds(GameSounds *gameSounds);
		Pause *getPause() const;
		void setPause(Pause *pause);

		CameraTravelManager *getCameraTravelManager();
		irr::gui::IGUIEnvironment *getEnv();
        irr::scene::ISceneManager *getSmgr();
        irr::video::IVideoDriver *getDriver();
        irr::IrrlichtDevice *getWindow();

        void setLState(layerMenuState state);
        void setLGState(layerGameState state);
        void setGState(gameState state);

		int getWidth();
        int getHeight();

        void hideGameLayers();
		void hideMenuLayers();

    private:
		void init();
		template<typename T> void showMenuLayer(T *layer);
        template<typename T> void showGameLayer(T *layer);
		void drawScene();
		void drawMenuLayer();
        void drawGameLayer();
        Intro *_intro;
        Menu *_menu;
        Controls *_controls;
        GameSettings *_gameSettings;
        Sounds *_sounds;
		Splash *_splash;
        LoadMap *_loadmap;
        Select *_select;
        Credits *_credits;
		Help *_help;
        Save *_save;
        Load *_load;
        Music *_music;
        Score *_score;
        Input *_inputs;
        GameCore *_gameCore;
		Pause *_pause;
        Game *_game;
        GameControls *_gameControls;
        GameSounds *_gameSounds;
        layerMenuState _lState;
		layerGameState _lGState;
        gameState _gState;
        MyEventReceiver *_receiver;
        CameraTravelManager *_cameraTravelManager;

        int _height;
        int _width;
        bool _fullscreen;
        bool _isInitialized;
        unsigned int _initStep;

        irr::IrrlichtDevice *_window;
        irr::gui::IGUIEnvironment *_env;
        irr::video::IVideoDriver *_driver;
        irr::scene::ISceneManager *_smgr;
        irr::scene::ICameraSceneNode *_camera;
};

#endif /* !CORE_HPP_ */