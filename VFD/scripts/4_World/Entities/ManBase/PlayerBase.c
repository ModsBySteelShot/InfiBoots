/*
    Copyright(C) 2019-2020 SteelShot <https://github.com/ModsBySteelShot>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

modded class PlayerBase
{
	private float VFD_SHOES_MOVEMENT_DAMAGE_PER_STEP = 0.035;

    override void Init()
    {
        super.Init();

        VFD_SHOES_MOVEMENT_DAMAGE_PER_STEP = VFD.GetConf().GetSettingValueByKey("SHOES_MOVEMENT_DAMAGE_PER_STEP");
	}

    override void ProcessFeetDamageServer(int pUserInt)
    {
		/* BELOW CODE IS WRITTEN BY BOHEMIA INTERACTIVE, AND SLIGHTLY MODIFIED BY ME TO ALLOW FOR CUSTOM MECHANICS*/
		/* NO LICENSE BELOW */
		EntityAI shoes = GetInventory().FindAttachment(InventorySlots.FEET);

        string surface;
        int liquid;
        GetGame().SurfaceUnderObject(this, surface, liquid);
        float modifier_surface = Surface.GetParamFloat(surface, "footDamage");

        if (VFD_SHOES_MOVEMENT_DAMAGE_PER_STEP != 0)
            if (shoes && shoes.GetHealthLevel() < 4)
            {
                shoes.AddHealth("", "", -1 * modifier_surface * VFD_SHOES_MOVEMENT_DAMAGE_PER_STEP * (float)PlayerConstants.CHECK_EVERY_N_STEP);

                return;
            }

        float chance = GetFeetDamageMoveModifier() * modifier_surface * PlayerConstants.BAREFOOT_MOVEMENT_BLEED_MODIFIER * (float)PlayerConstants.CHECK_EVERY_N_STEP;

        if (Math.RandomFloat01() < chance)
        {
            if (pUserInt % 2 == 0)
            {
                if (GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("RightFoot"))
                {
                    SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
                }
            }
            else
            {
                if (GetBleedingManagerServer().AttemptAddBleedingSourceBySelection("LeftFoot"))
                {
                    SendSoundEvent(EPlayerSoundEventID.INJURED_LIGHT);
                }
            }
        }
		/* END NO LICENSE */
    }
}