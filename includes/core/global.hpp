/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** global
*/

#ifndef GLOBAL_HPP_
#define GLOBAL_HPP_

#include <map>
#include "modelInfos.hpp"

extern const std::map<std::string, modelInfos_t> g_modelInfos = {
    {
        "waluigi", // STRING
        { // MODELINFOS_T
            "resources/models/characters/waluigi/waluigi.MD3", // MODEL MD3
            {
                "resources/models/characters/waluigi/Tex_0001_0.png", // TEXTURES
                "resources/models/characters/waluigi/Tex_0002_0.png",
                "resources/models/characters/waluigi/Tex_0003_0.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 353}, // DEAD
            {354, 604}, // VICTORY
            2 // SCALE SIZE
        }
    },
    {
        "dr_peach", // STRING
        { // MODELINFOS_T
            "resources/models/characters/dr_peach/dr_peach.MD3", // MODEL MD3
            {
                "resources/models/characters/dr_peach/dr.peach_crown_dif.png", // TEXTURES
                "resources/models/characters/dr_peach/dr_peach_di.png"
            },
            {0, 120}, // IDLE
            {121, 140}, // RUNNING
            {141, 279}, // DYING
            {280, 356}, // DEAD
            {357, 613}, // VICTORY
            25 // SCALE SIZE
        }
    },
    {
        "koopa", // STRING
        { // MODELINFOS_T
            "resources/models/characters/koopa/koopa.MD3", // MODEL MD3
            {
                "resources/models/characters/koopa/koopaBody.png", // TEXTURES
                "resources/models/characters/koopa/koopaFace.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 376}, // DEAD
            {377, 427}, // VICTORY
            15 // SCALE SIZE
        }
    },
    {
        "lakitu", // STRING
        { // MODELINFOS_T
            "resources/models/characters/lakitu/lakitu.MD3", // MODEL MD3
            {
                "resources/models/characters/lakitu/lakituFace.png", // TEXTURES
                "resources/models/characters/lakitu/lakituBody.png"
            },
            {0, 120}, // IDLE
            {121, 146}, // RUNNING
            {147, 285}, // DYING
            {286, 380}, // DEAD
            {381, 479}, // VICTORY
            15 // SCALE SIZE
        }
    },
    {
        "mario", // STRING
        { // MODELINFOS_T
            "resources/models/characters/mario/mario.MD3", // MODEL MD3
            {
                "resources/models/characters/mario/mario_eye.0.png", // TEXTURES
                "resources/models/characters/mario/mario_all.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 368}, // DEAD
            {369, 423}, // VICTORY
            20 // SCALE SIZE
        }
    },
    {
        "yoshi", // STRING
        { // MODELINFOS_T
            "resources/models/characters/yoshi/yoshi.MD3", // MODEL MD3
            {
                "resources/models/characters/yoshi/yoshi.png", // TEXTURES
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
                "resources/models/characters/yoshi/yoshi.png",
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 342}, // DEAD
            {343, 666}, // VICTORY
            15 // SCALE SIZE
        }
    }
};

#endif /* !GLOBAL_HPP_ */
