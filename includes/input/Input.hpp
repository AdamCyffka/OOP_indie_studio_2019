/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** Event
*/

#ifndef input
#define input

#include <map>
#include "../../victor/irrlicht-1.8.4/include/irrlicht.h"

using namespace irr;                    // NONE A PAS OUBLIER , POUR NON TOUCHE OU TOUCHE NON BIND

enum Key_mouvement
{
    Right = 1 ,
    Left = 2 ,
    Up = 3 ,
    Down = 4,
    Exit = 6
};

class Input : public IEventReceiver
{
    public:
	    virtual bool OnEvent(const SEvent& event);
	    // This is used to check whether a key is being held down
        virtual bool IsKeyDown(EKEY_CODE keyCode) const;
        Key_mouvement keyBoard(Input receiver);
        std::map<int, Key_mouvement> getPlayerInput();
        Key_mouvement getInput(IrrlichtDevice* device, Input receiver);
	    Input();
        ~Input();

    private:
	    // We use this array to store the current state of each key
	    bool KeyIsDown[KEY_KEY_CODES_COUNT];
        std::map<int, Key_mouvement> _playerInput;
};

#endif //input