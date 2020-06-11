/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** loadCore.cpp
*/

#include "loadCore.hpp"
#include "CoreException.hpp"

void loadSplashBar(Core *core)
{
	core->getSplash()->setBar(new ProgressBar(core->getEnv(), core->getDriver(), irr::core::rect<irr::s32>(300, 800, 1620, 830)));
	core->getSplash()->getBar()->setPosition(irr::core::rect<irr::s32>(30, 700, 600, 600));
	core->getSplash()->getBar()->addBorder(2);
	core->getSplash()->getBar()->setProgress(5);
}

void loadMusic(Core *core)
{
	if (!core->getMusicEngine())
		core->setMusicEngine(new Music());
	core->getSplash()->getBar()->setProgress(7);
}

void loadMap(Core *core)
{
	if (!core->getLoadMap())
		core->setLoadMap(new LoadMap(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(10);
}

void loadIntro(Core *core)
{
	if (!core->getIntro())
		core->setIntro(new Intro(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(20);
}

void loadMenu(Core *core)
{
	if (!core->getMenu())
		core->setMenu(new Menu(core->getEnv(), core->getDriver(), core->getSmgr(), core->getWidth(), core->getHeight()));
	core->getSplash()->getBar()->setProgress(30);
}

void loadSounds(Core *core)
{
	if (!core->getSounds())
		core->setSounds(new Sounds(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(40);
}

void loadGameSettings(Core *core)
{
	if (!core->getGameSettings())
		core->setGameSettings(new GameSettings(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(40);
}

void loadControls(Core *core)
{
	if (!core->getControls())
		core->setControls(new Controls(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(40);
}

void loadSelect(Core *core)
{
	if (!core->getSelect())
		core->setSelect(new Select(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(50);
}

void loadScore(Core *core)
{
	if (!core->getScore() && core->getSelect())
		core->setScore(new Score(core->getEnv(), core->getDriver(), core->getSmgr(), core->getSelect()->getPreviews()));
	core->getSplash()->getBar()->setProgress(50);
}

void loadHelp(Core *core)
{
	if (!core->getHelp())
		core->setHelp(new Help(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(60);
}

void loadCredits(Core *core)
{
	if (!core->getCredits())
		core->setCredits(new Credits(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(60);
}

void loadSave(Core *core)
{
	if (!core->getSave())
		core->setSave(new Save(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(80);
}

void loadInput(Core *core)
{
	if (!core->getInput())
		core->setInput(new Input());
	core->getSplash()->getBar()->setProgress(90);
}

void loadLoad(Core *core)
{
	if (!core->getLoad())
		core->setLoad(new Load(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(90);
}

void loadGameCore(Core *core)
{
	if (!core->getSelect())
		throw CoreException("Select hasn't been initialized, cannot get characters previews");
	if (!core->getGameCore())
		core->setGameCore(new GameCore(core));
	core->getSplash()->getBar()->setProgress(97);
}

void loadPause(Core *core)
{
	if (!core->getPause())
		core->setPause(new Pause(core->getEnv(), core->getDriver(), core->getSmgr(), core));
	core->getSplash()->getBar()->setProgress(100);
}

void loadGameClass(Core *core)
{
	if (!core->getGame() && core->getSelect())
		core->setGame(new Game(core->getEnv(), core->getDriver(), core->getSmgr(), core->getSelect()->getPreviews()));
	core->getSplash()->getBar()->setProgress(100);
}

void loadGameSounds(Core *core)
{
	if (!core->getGameSounds())
		core->setGameSounds(new GameSounds(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(100);
}

void loadGameControls(Core *core)
{
	if (!core->getGameControls())
		core->setGameControls(new GameControls(core->getEnv(), core->getDriver(), core->getSmgr()));
	core->getSplash()->getBar()->setProgress(100);
}
