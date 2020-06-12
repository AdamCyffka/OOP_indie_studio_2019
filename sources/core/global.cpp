/*
** EPITECH PROJECT, 2020
** OOP_indie_studio_2019
** File description:
** global
*/

#include "global.hpp"
#include "IPowerUps.hpp"

irr::video::ITexture *fireTexture;
std::map<IPowerUps::PowerUpsType, irr::scene::IMesh *> g_meshes;
void setGlobalVariables(irr::video::IVideoDriver *driver, irr::scene::ISceneManager *smgr)
{
    fireTexture = driver->getTexture("resources/images/fx/fire.bmp");
	g_meshes[IPowerUps::PowerUpsType::BombDown] = smgr->getMesh("resources/models/powers/bombs/bombDown.obj");
	g_meshes[IPowerUps::PowerUpsType::BombFull] = smgr->getMesh("resources/models/powers/bombs/bombFull.obj");
	g_meshes[IPowerUps::PowerUpsType::BombPass] = smgr->getMesh("resources/models/powers/bombs/bombPass.obj");
	g_meshes[IPowerUps::PowerUpsType::BombUp] = smgr->getMesh("resources/models/powers/bombs/bombUp.obj");
	g_meshes[IPowerUps::PowerUpsType::FireDown] = smgr->getMesh("resources/models/powers/fires/fireDown.obj");
	g_meshes[IPowerUps::PowerUpsType::FireFull] = smgr->getMesh("resources/models/powers/fires/fireFull.obj");
    g_meshes[IPowerUps::PowerUpsType::FireUp] = smgr->getMesh("resources/models/powers/fires/fireUp.obj");
	g_meshes[IPowerUps::PowerUpsType::SpeedDown] = smgr->getMesh("resources/models/powers/speeds/speedDown.obj");
	g_meshes[IPowerUps::PowerUpsType::SpeedUp] = smgr->getMesh("resources/models/powers/speeds/speedUp.obj");
	g_meshes[IPowerUps::PowerUpsType::WallPass] = smgr->getMesh("resources/models/powers/wallPass/wallPass.obj");
}

const std::map<std::string, modelInfos_t> g_modelInfos = {
    {
        "waluigi", // INDEX
        { // MODELINFOS_T
            "waluigi", // NAME
            "resources/models/characters/waluigi/waluigi.md3", // MODEL MD3
            "resources/sfx/waluigi-hit.wav", // DYING SOUND
            "resources/sfx/waluigi.wav", // VICTORY SOUND
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
            2.0f // SCALE SIZE
        }
    },
    {
        "dr_peach", // INDEX
        { // MODELINFOS_T
            "dr_peach", // NAME
            "resources/models/characters/dr_peach/dr_peach.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/dr_peach/dr.peach_crown_dif.png", // TEXTURES
                "resources/models/characters/dr_peach/dr_peach_di.png"
            },
            {0, 120}, // IDLE
            {121, 140}, // RUNNING
            {141, 279}, // DYING
            {280, 356}, // DEAD
            {357, 613}, // VICTORY
            25.0f // SCALE SIZE
        }
    },
    {
        "koopa", // INDEX
        { // MODELINFOS_T
            "koopa", // NAME
            "resources/models/characters/koopa/koopa.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/koopa/koopaBody.png", // TEXTURES
                "resources/models/characters/koopa/koopaFace.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 376}, // DEAD
            {377, 427}, // VICTORY
            15.0f // SCALE SIZE
        }
    },
    {
        "lakitu", // INDEX
        { // MODELINFOS_T
            "lakitu", // NAME
            "resources/models/characters/lakitu/lakitu.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/lakitu/lakituFace.png", // TEXTURES
                "resources/models/characters/lakitu/lakituBody.png"
            },
            {0, 120}, // IDLE
            {121, 146}, // RUNNING
            {147, 285}, // DYING
            {286, 380}, // DEAD
            {381, 479}, // VICTORY
            15.0f // SCALE SIZE
        }
    },
    {
        "mario", // INDEX
        { // MODELINFOS_T
            "mario", // NAME
            "resources/models/characters/mario/mario.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/mario/mario_eye.0.png", // TEXTURES
                "resources/models/characters/mario/mario_all.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 368}, // DEAD
            {369, 423}, // VICTORY
            20.0f // SCALE SIZE
        }
    },
    {
        "green_toad", // INDEX
        { // MODELINFOS_T
            "green_toad", // NAME
            "resources/models/characters/toad/toad.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/toad/pc09_eye.0.png", // TEXTURES
                "resources/models/characters/toad/pc09G_body_m2.png"
            },
            {0, 120}, // IDLE
            {121, 154}, // RUNNING
            {155, 293}, // DYING
            {294, 376}, // DEAD
            {377, 923}, // VICTORY
            2.5f // SCALE SIZE
        }
    },
    {
        "red_toad", // INDEX
        { // MODELINFOS_T
            "red_toad", // NAME
            "resources/models/characters/toad/toad.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/toad/pc09_eye.1.png", // TEXTURES
                "resources/models/characters/toad/pc09_body_m2.png"
            },
            {0, 120}, // IDLE
            {121, 154}, // RUNNING
            {155, 293}, // DYING
            {294, 376}, // DEAD
            {377, 923}, // VICTORY
            2.5f // SCALE SIZE
        }
    },
    {
        "blue_toad", // INDEX
        { // MODELINFOS_T
            "blue_toad", // NAME
            "resources/models/characters/toad/toad.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/toad/pc09_eye.2.png", // TEXTURES
                "resources/models/characters/toad/pc09B_body_m2.png"
            },
            {0, 120}, // IDLE
            {121, 154}, // RUNNING
            {155, 293}, // DYING
            {294, 376}, // DEAD
            {377, 923}, // VICTORY
            2.5f // SCALE SIZE
        }
    },
    {
        "yellow_toad", // INDEX
        { // MODELINFOS_T
            "yellow_toad", // NAME
            "resources/models/characters/toad/toad.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/toad/pc09_eye.3.png", // TEXTURES
                "resources/models/characters/toad/pc09Y_body_m2.png"
            },
            {0, 120}, // IDLE
            {121, 154}, // RUNNING
            {155, 293}, // DYING
            {294, 376}, // DEAD
            {377, 923}, // VICTORY
            2.5f // SCALE SIZE
        }
    },
    {
        "dry_bones", // INDEX
        { // MODELINFOS_T
            "dry_bones", // NAME
            "resources/models/characters/dry_bones/dry_bones.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/dry_bones/Karon.png", // TEXTURES
                "resources/models/characters/dry_bones/Karon2.png" // TEXTURES
            },
            {0, 120}, // IDLE
            {121, 154}, // RUNNING
            {155, 292}, // DYING
            {293, 373}, // DEAD
            {374, 733}, // VICTORY
            0.13f // SCALE SIZE
        }
    },
    {
        "luigi", // INDEX
        { // MODELINFOS_T
            "luigi", // NAME
            "resources/models/characters/luigi/classic/luigi.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/luigi/classic/player_dw01_MarioHand_dif.png",
                "resources/models/characters/luigi/classic/player_dw01_MarioHand_dif2.png",
                "resources/models/characters/luigi/classic/player_dw01_MarioBody_dif.png", // TEXTURES
                "resources/models/characters/luigi/classic/player_dw01_MarioEye_dif.0.png",
                "resources/models/characters/luigi/classic/player_dw01_MarioHead_dif.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 364}, // DEAD
            {365, 460}, // VICTORY
            0.2f // SCALE SIZE
        }
    },
    {
        "luigi_fire", // INDEX
        { // MODELINFOS_T
            "luigi_fire", // NAME
            "resources/models/characters/luigi/fire/luigi.md3", // MODEL MD3
            "", // DYING SOUND
            "", // VICTORY SOUND
            {
                "resources/models/characters/luigi/fire/player_dw01_MarioHand_dif.png",
                "resources/models/characters/luigi/fire/player_dw01_MarioHand_dif2.png",
                "resources/models/characters/luigi/fire/player_dw01_MarioBody_dif.png", // TEXTURES
                "resources/models/characters/luigi/fire/player_dw01_MarioEye_dif.0.png",
                "resources/models/characters/luigi/fire/player_dw01_MarioHead_dif.png"
            },
            {0, 120}, // IDLE
            {121, 142}, // RUNNING
            {143, 281}, // DYING
            {282, 364}, // DEAD
            {365, 460}, // VICTORY
            0.2f // SCALE SIZE
        }
    }
};