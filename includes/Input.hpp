/*
** EPITECH PROJECT, 2020
** Input.hpp
** File description:
** Event
*/

#ifndef input
#define input

enum Key_mouvement
{
    Right = 1 ,
    Left = 2 ,
    Up = 3 ,
    Down = 4
};

class Input : public IEventReceiver
{
    public:
        virtual bool OnEvent(const SEvent& event);
        const SEvent::SJoystickEvent &GetJoystickState(void) const;
        Input();
        ~Input();
    private:
        SEvent::SJoystickEvent JoystickState;
};
#endif /* !input */
