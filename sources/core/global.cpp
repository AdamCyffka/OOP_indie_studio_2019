/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019 [WSL: Ubuntu]
** File description:
** modelinfo_temporaire
*/

#include <map>
#include "modelInfos.hpp"

std::map<std::string, modelInfos_t> modelInfos = {
    {
        "waluigi", // STRING
        { // MODELINFOS_T
            "resources/models/characters/waluigi/waluigi.MD3", // MODEL MD3
            {
                "resources/models/characters/waluigi/Tex_0001_0.png", // TEXTURES
                "resources/models/characters/waluigi/Tex_0002_0.png",
                "resources/models/characters/waluigi/Tex_0003_0.png",
                "resources/models/characters/waluigi/Tex_0004_1.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // MOVING
            {143, 281}, // DYING
            {282, 353}, // DEAD
            {354, 604}, // VICTORY
            10 // SCALE SIZE
        }
    },
    {
        "dry_bones", // STRING
        { // MODELINFOS_T
            "resources/models/characters/dry_bones/dry_bones.MD3", // MODEL MD3
            {
                "resources/models/characters/dry_bones/Dry_Bones_body.png", // TEXTURES
                "resources/models/characters/dry_bones/Dry_Bones_eye.png",
                "resources/models/characters/dry_bones/Dry_Bones_eye2.png"
            },
            {0, 120}, // IDLE
            {121, 159}, // MOVING
            {160, 298}, // DYING
            {299, 369}, // DEAD
            {370, 620}, // VICTORY
            10 // SCALE SIZE
        }
    }
};